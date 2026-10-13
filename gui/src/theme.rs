//! The LoSnoCo design language for egui: colors, type and motion.
//!
//! Colors are the LoSnoCo tokens (`tokens.json` in the design skill); keep
//! them in sync with it rather than inventing new values.  Fonts (Inter
//! LoSnoCo, Iosevka LoSnoCo) are fetched from assets.losno.co at startup; until
//! they arrive, or if the fetch fails, egui's built-in fonts stand in.  Code
//! surfaces (phonemes, the sync log) stay dark in both themes.

use eframe::egui::{self, Color32, CornerRadius, FontFamily, FontId, RichText, Shadow, Stroke, TextStyle, Theme, Vec2, Visuals};

const fn hex(rgb: u32) -> Color32 {
    Color32::from_rgb((rgb >> 16) as u8, (rgb >> 8) as u8, rgb as u8)
}

// ---- Tokens -----------------------------------------------------------------

pub const ORANGE: Color32 = hex(0xF25E0D);
const TEAL: Color32 = hex(0x0DF2C9);
const TEAL_LIGHT: Color32 = hex(0x00967F);
const ERROR: Color32 = hex(0xC0392B);

pub const CODE_BG: Color32 = hex(0x111C1A);
pub const CODE_BORDER: Color32 = hex(0x2F524B);
pub const CODE_TEXT: Color32 = hex(0xE5EFED);
const CODE_INLINE_BG: Color32 = hex(0x182926);

/// The neutral ramp of one theme.
struct Surfaces {
    bg: Color32,
    surface: Color32,
    surface2: Color32,
    surface3: Color32,
    border: Color32,
    border_strong: Color32,
    muted: Color32,
    text: Color32,
    /// Links, focus rings and selection: teal-light on light, teal on dark.
    accent: Color32,
    /// Text drawn on `accent`.
    on_accent: Color32,
}

const LIGHT: Surfaces = Surfaces {
    bg: hex(0xF4F3F0),
    surface: hex(0xECEAE5),
    surface2: hex(0xE4E2DC),
    surface3: hex(0xD8D5CE),
    border: hex(0xD8D5CE),
    border_strong: hex(0xB8B5AE),
    muted: hex(0x888880),
    text: hex(0x1A1917),
    accent: TEAL_LIGHT,
    on_accent: Color32::WHITE,
};

const DARK: Surfaces = Surfaces {
    bg: hex(0x111C1A),
    surface: hex(0x182926),
    surface2: hex(0x1E332F),
    surface3: hex(0x243D38),
    border: hex(0x243D38),
    border_strong: hex(0x2F524B),
    muted: hex(0x7A9E98),
    text: hex(0xE5EFED),
    accent: TEAL,
    on_accent: hex(0x111C1A),
};

/// --dur-quick, for interactive state.
const DUR_QUICK: f32 = 0.160;
/// --dur-slow, for entrances.
const DUR_SLOW: f64 = 0.420;

// ---- Type -------------------------------------------------------------------

const FONT_URL: &str = "https://assets.losno.co/fonts-flat/";
/// Inter LoSnoCo at weight 600 (buttons) and 700 (section labels).
const SEMIBOLD: &str = "Inter LoSnoCo 600";
const BOLD: &str = "Inter LoSnoCo 700";

fn family(name: &str) -> FontFamily {
    FontFamily::Name(name.into())
}

// ---- Setup ------------------------------------------------------------------

/// Entrance animation state; see `App::ui`.
pub struct Motion {
    reduce: bool,
    start: Option<f64>,
}

impl Motion {
    /// Opacity for the entrance fade (--dur-slow, --ease-out).
    pub fn entrance(&mut self, ctx: &egui::Context) -> f32 {
        if self.reduce {
            return 1.0;
        }
        let now = ctx.input(|i| i.time);
        let t = ((now - *self.start.get_or_insert(now)) / DUR_SLOW).min(1.0) as f32;
        if t < 1.0 {
            ctx.request_repaint();
        }
        ease_out(t)
    }
}

/// Apply the theme to both light and dark mode (egui follows the system
/// setting) and start fetching the fonts.
pub fn install(ctx: &egui::Context) -> Motion {
    let reduce = reduce_motion();
    ctx.set_visuals_of(Theme::Light, visuals(&LIGHT, false));
    ctx.set_visuals_of(Theme::Dark, visuals(&DARK, true));
    ctx.all_styles_mut(|s| {
        s.text_styles = [
            (TextStyle::Small, FontId::proportional(11.0)),
            (TextStyle::Body, FontId::proportional(15.0)),
            (TextStyle::Button, FontId::new(15.0, family(SEMIBOLD))),
            (TextStyle::Heading, FontId::new(17.0, family(SEMIBOLD))),
            (TextStyle::Monospace, FontId::monospace(13.4)),
        ]
        .into();
        s.spacing.item_spacing = Vec2::new(8.0, 6.0);
        s.spacing.button_padding = Vec2::new(12.0, 5.0);
        s.spacing.interact_size.y = 24.0;
        s.animation_time = if reduce { 0.0 } else { DUR_QUICK };
    });
    load_fonts(ctx);
    Motion { reduce, start: None }
}

fn visuals(p: &Surfaces, dark: bool) -> Visuals {
    let mut v = if dark { Visuals::dark() } else { Visuals::light() };
    let radius = CornerRadius::same(6); // --radius-btn, --radius-input
    let shadow = Shadow { offset: [0, 4], blur: 16, spread: 0, color: Color32::from_black_alpha(26) };

    v.panel_fill = p.bg;
    v.window_fill = p.bg;
    v.faint_bg_color = p.surface;
    v.extreme_bg_color = p.surface;
    v.text_edit_bg_color = Some(p.surface);
    v.code_bg_color = CODE_INLINE_BG;
    v.weak_text_color = Some(p.muted);
    v.hyperlink_color = p.accent;
    v.warn_fg_color = ORANGE;
    v.error_fg_color = ERROR;
    v.selection.bg_fill = p.accent;
    v.selection.stroke = Stroke::new(1.0, p.on_accent);
    v.text_cursor.stroke = Stroke::new(2.0, p.accent);
    v.window_corner_radius = CornerRadius::same(8);
    v.menu_corner_radius = CornerRadius::same(8);
    v.window_stroke = Stroke::new(1.0, p.border);
    v.window_shadow = shadow;
    v.popup_shadow = shadow;
    v.slider_trailing_fill = true;

    let w = &mut v.widgets;
    for (wv, fill, stroke) in [
        (&mut w.noninteractive, p.bg, p.border),
        (&mut w.inactive, p.surface, p.border),
        (&mut w.hovered, p.surface2, p.border_strong),
        (&mut w.active, p.surface3, p.accent),
        (&mut w.open, p.surface2, p.border_strong),
    ] {
        wv.bg_fill = fill;
        wv.weak_bg_fill = fill;
        wv.bg_stroke = Stroke::new(1.0, stroke);
        wv.fg_stroke = Stroke::new(1.0, p.text);
        wv.corner_radius = radius;
        wv.expansion = 0.0;
    }
    v
}

/// Register the font families (egui panics on unknown ones) with the
/// built-in fonts, then swap the LoSnoCo faces in as they arrive.
fn load_fonts(ctx: &egui::Context) {
    let mut defs = egui::FontDefinitions::default();
    let sans = defs.families[&FontFamily::Proportional].clone();
    for name in [SEMIBOLD, BOLD] {
        defs.families.insert(family(name), sans.clone());
    }
    ctx.set_fonts(defs);

    fetch_font(ctx, "InterVariableLoSnoCo.woff2", |ctx, ttf| {
        for (name, fam, wght) in [("Inter LoSnoCo", FontFamily::Proportional, 400.0), (SEMIBOLD, family(SEMIBOLD), 600.0), (BOLD, family(BOLD), 700.0)] {
            let mut data = egui::FontData::from_static(ttf);
            data.tweak.coords = egui::epaint::text::VariationCoords::new([(b"wght", wght), (b"opsz", 14.0)]);
            add_font(ctx, name, data, fam);
        }
    });
    fetch_font(ctx, "IosevkaLoSnoCo-Regular.woff2", |ctx, ttf| {
        add_font(ctx, "Iosevka LoSnoCo", egui::FontData::from_static(ttf), FontFamily::Monospace);
    });
}

fn add_font(ctx: &egui::Context, name: &str, data: egui::FontData, fam: FontFamily) {
    ctx.add_font(egui::epaint::text::FontInsert::new(
        name,
        data,
        vec![egui::epaint::text::InsertFontFamily { family: fam, priority: egui::epaint::text::FontPriority::Highest }],
    ));
}

/// Download a woff2 face and hand its TTF data to `then`.  The data lives
/// as long as the app, so it is leaked rather than copied per family.
fn fetch_font(ctx: &egui::Context, file: &'static str, then: impl FnOnce(&egui::Context, &'static [u8]) + Send + 'static) {
    let ctx = ctx.clone();
    ehttp::fetch(ehttp::Request::get(format!("{FONT_URL}{file}")), move |r| {
        let ttf = r
            .and_then(|r| if r.ok { Ok(r.bytes) } else { Err(format!("HTTP {} {}", r.status, r.status_text)) })
            .and_then(|woff2| wuff::decompress_woff2(&woff2).map_err(|e| format!("{e:?}")));
        match ttf {
            Ok(ttf) => {
                then(&ctx, ttf.leak());
                ctx.request_repaint();
            }
            Err(e) => log(&format!("{file}: {e}; using the built-in font")),
        }
    });
}

#[cfg(target_arch = "wasm32")]
fn log(msg: &str) {
    web_sys::console::warn_1(&msg.into());
}

#[cfg(not(target_arch = "wasm32"))]
fn log(msg: &str) {
    eprintln!("{msg}");
}

// ---- Motion -----------------------------------------------------------------

/// cubic-bezier(0.2, 0.8, 0.2, 1), the --ease-out token.
fn ease_out(x: f32) -> f32 {
    let curve = |a: f32, b: f32, s: f32| 3.0 * (1.0 - s) * (1.0 - s) * s * a + 3.0 * (1.0 - s) * s * s * b + s * s * s;
    let (mut lo, mut hi) = (0.0, 1.0);
    for _ in 0..20 {
        let mid = (lo + hi) / 2.0;
        if curve(0.2, 0.2, mid) < x { lo = mid } else { hi = mid }
    }
    curve(0.8, 1.0, (lo + hi) / 2.0)
}

/// prefers-reduced-motion, or the platform's equivalent.
#[cfg(target_arch = "wasm32")]
fn reduce_motion() -> bool {
    web_sys::window()
        .and_then(|w| w.match_media("(prefers-reduced-motion: reduce)").ok().flatten())
        .is_some_and(|m| m.matches())
}

/// Windows: "Show animations in Windows" (SPI_GETCLIENTAREAANIMATION).
#[cfg(windows)]
fn reduce_motion() -> bool {
    use windows_sys::Win32::UI::WindowsAndMessaging::{SPI_GETCLIENTAREAANIMATION, SystemParametersInfoW};
    let mut on: i32 = 1;
    let ok = unsafe { SystemParametersInfoW(SPI_GETCLIENTAREAANIMATION, 0, (&raw mut on).cast(), 0) };
    ok != 0 && on == 0
}

#[cfg(not(any(windows, target_arch = "wasm32")))]
fn reduce_motion() -> bool {
    false
}

// ---- Components -------------------------------------------------------------

/// A section label: uppercase, 11 px, weight 700, +0.2em tracking, orange.
pub fn section(ui: &mut egui::Ui, text: &str) {
    ui.label(RichText::new(text.to_uppercase()).font(FontId::new(11.0, family(BOLD))).extra_letter_spacing(2.2).color(ORANGE));
    ui.add_space(2.0);
}

/// The view's one primary (orange) action.
pub fn primary_button(text: &str) -> egui::Button<'static> {
    egui::Button::new(RichText::new(text).color(Color32::WHITE)).fill(ORANGE).stroke(Stroke::NONE)
}

/// A dark code surface, the same in both themes.
pub fn code_frame() -> egui::Frame {
    egui::Frame::new().fill(CODE_BG).stroke(Stroke::new(2.0, CODE_BORDER)).corner_radius(8).inner_margin(10)
}

#[cfg(test)]
mod tests {
    #[test]
    fn ease_out_endpoints() {
        assert!(super::ease_out(0.0).abs() < 1e-3);
        assert!((super::ease_out(1.0) - 1.0).abs() < 1e-3);
        assert!(super::ease_out(0.5) > 0.5);
    }
}
