import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
public class DisRange extends GhidraScript {
  public void run() throws Exception {
    String[] a = getScriptArgs();
    Address s = toAddr(a[1]), e = toAddr(a[2]);
    PrintWriter pw = new PrintWriter(new FileWriter(a[0]));
    for (int i = 3; i < a.length; i++) disassemble(toAddr(a[i]));
    Address cur = s;
    while (cur.compareTo(e) < 0) {
      Instruction ins = getInstructionAt(cur);
      if (ins == null) { Data d = getDataAt(cur); pw.println(cur + "  ?? " + (d==null?"":d)); cur = cur.add(1); continue; }
      String c = ""; for (var r : ins.getReferencesFrom()) { var sym = getSymbolAt(r.getToAddress()); if (sym!=null) c += " ; "+sym.getName(); }
      pw.println(cur + "  " + ins + c);
      cur = ins.getMaxAddress().add(1);
    }
    pw.close();
  }
}
