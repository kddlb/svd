1c204550  mov ecx, dword ptr [esp + 0xc]
1c204554  push esi
1c204555  cmp ecx, 0x6e
1c204558  jle 0x1c204577
1c20455a  xor eax, eax
1c20455c  mov esi, dword ptr [esp + 8]
1c204560  mov ax, word ptr [esi + 0x60]
1c204564  sub ecx, 0x6e
1c204567  imul eax, ecx
1c20456a  cdq 
1c20456b  mov ecx, 0x64
1c204570  idiv ecx
1c204572  lea ecx, [eax + 0x6e]
1c204575  jmp 0x1c20457b
1c204577  mov esi, dword ptr [esp + 8]
1c20457b  xor eax, eax
1c20457d  mov ax, word ptr [esi + 0x46]
1c204581  imul eax, ecx
1c204584  cdq 
1c204585  mov ecx, 0x6e
1c20458a  idiv ecx
1c20458c  xor edx, edx
1c20458e  mov ecx, dword ptr [esp + 0xc]
1c204592  mov dx, word ptr [0x1c250566]
1c204599  pop esi
1c20459a  and edx, 0xfffffffe
1c20459d  shl edx, 4
1c2045a0  mov word ptr [edx + ecx + 0x18], ax
1c2045a5  ret 
