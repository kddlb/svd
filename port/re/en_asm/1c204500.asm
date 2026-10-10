1c204500  mov ecx, dword ptr [esp + 0xc]
1c204504  push esi
1c204505  cmp ecx, 0x6e
1c204508  jle 0x1c204527
1c20450a  xor eax, eax
1c20450c  mov esi, dword ptr [esp + 8]
1c204510  mov ax, word ptr [esi + 0x60]
1c204514  sub ecx, 0x6e
1c204517  imul eax, ecx
1c20451a  cdq 
1c20451b  mov ecx, 0x64
1c204520  idiv ecx
1c204522  lea ecx, [eax + 0x6e]
1c204525  jmp 0x1c20452b
1c204527  mov esi, dword ptr [esp + 8]
1c20452b  xor eax, eax
1c20452d  mov ax, word ptr [esi + 0x46]
1c204531  imul eax, ecx
1c204534  cdq 
1c204535  mov ecx, 0x6e
1c20453a  idiv ecx
1c20453c  mov edx, dword ptr [esp + 0xc]
1c204540  pop esi
1c204541  mov word ptr [edx + 0x18], ax
1c204545  ret 
