1c204610  mov ecx, dword ptr [esp + 0xc]
1c204614  push esi
1c204615  cmp ecx, 0x6e
1c204618  jle 0x1c204637
1c20461a  xor eax, eax
1c20461c  mov esi, dword ptr [esp + 8]
1c204620  mov ax, word ptr [esi + 0x60]
1c204624  sub ecx, 0x6e
1c204627  imul eax, ecx
1c20462a  cdq 
1c20462b  mov ecx, 0x64
1c204630  idiv ecx
1c204632  lea ecx, [eax + 0x6e]
1c204635  jmp 0x1c20463b
1c204637  mov esi, dword ptr [esp + 8]
1c20463b  xor eax, eax
1c20463d  mov ax, word ptr [esi + 0x46]
1c204641  imul eax, ecx
1c204644  cdq 
1c204645  mov ecx, 0x6e
1c20464a  idiv ecx
1c20464c  xor edx, edx
1c20464e  xor ecx, ecx
1c204650  mov dx, word ptr [0x1c250e60]
1c204657  mov esi, dword ptr [esp + 0xc]
1c20465b  mov cx, word ptr [0x1c250566]
1c204662  and edx, 0xfffffffe
1c204665  shl edx, 4
1c204668  shl ecx, 5
1c20466b  add edx, ecx
1c20466d  mov word ptr [edx + esi + 0x18], ax
1c204672  pop esi
1c204673  ret 
