1c2045b0  mov ecx, dword ptr [esp + 0xc]
1c2045b4  push esi
1c2045b5  cmp ecx, 0x6e
1c2045b8  jle 0x1c2045d7
1c2045ba  xor eax, eax
1c2045bc  mov esi, dword ptr [esp + 8]
1c2045c0  mov ax, word ptr [esi + 0x60]
1c2045c4  sub ecx, 0x6e
1c2045c7  imul eax, ecx
1c2045ca  cdq 
1c2045cb  mov ecx, 0x64
1c2045d0  idiv ecx
1c2045d2  lea ecx, [eax + 0x6e]
1c2045d5  jmp 0x1c2045db
1c2045d7  mov esi, dword ptr [esp + 8]
1c2045db  xor eax, eax
1c2045dd  mov ax, word ptr [esi + 0x46]
1c2045e1  imul eax, ecx
1c2045e4  cdq 
1c2045e5  mov ecx, 0x6e
1c2045ea  idiv ecx
1c2045ec  xor edx, edx
1c2045ee  mov ecx, dword ptr [esp + 0xc]
1c2045f2  mov dx, word ptr [0x1c250566]
1c2045f9  pop esi
1c2045fa  shl edx, 5
1c2045fd  mov word ptr [edx + ecx - 8], ax
1c204602  ret 
