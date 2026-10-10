1c204030  mov eax, dword ptr [esp + 0xc]
1c204034  push ebx
1c204035  push esi
1c204036  push edi
1c204037  push ebp
1c204038  mov ebx, dword ptr [eax]
1c20403a  test ebx, ebx
1c20403c  je 0x1c20415d
1c204042  cmp word ptr [ebx], 0x1e
1c204046  mov edi, dword ptr [esp + 0x14]
1c20404a  mov esi, dword ptr [esp + 0x18]
1c20404e  je 0x1c204165
1c204054  movsx ecx, word ptr [ebx]
1c204057  sub ecx, 0x32
1c20405a  cmp ecx, 0xc8
1c204060  ja 0x1c20414e
1c204066  xor eax, eax
1c204068  mov al, byte ptr [ecx + 0x1c2041ec]
1c20406e  jmp dword ptr [eax*4 + 0x1c2041d4]
1c204075  movsx eax, word ptr [ebx + 2]
1c204079  push eax
1c20407a  push edi
1c20407b  call 0x1c204680
1c204080  add esp, 8
1c204083  jmp 0x1c20414e
1c204088  mov ax, word ptr [ebx + 2]
1c20408c  mov word ptr [edi + 0xae], ax
1c204093  jmp 0x1c20414e
1c204098  mov ax, word ptr [ebx + 2]
1c20409c  test ax, ax
1c20409f  jg 0x1c2040fc
1c2040a1  mov cx, word ptr [edi + 0xac]
1c2040a8  imul cx, cx, 0xc
1c2040ac  add cx, word ptr [edi + 0xae]
1c2040b3  sub cx, ax
1c2040b6  cmp cx, 0x55
1c2040ba  jl 0x1c2040d0
1c2040bc  mov bp, 0xc
1c2040c0  lea eax, [ecx - 0x49]
1c2040c3  sub dx, dx
1c2040c6  div bp
1c2040c9  imul ax, bp
1c2040cd  sub cx, ax
1c2040d0  test cx, cx
1c2040d3  jge 0x1c2040ed
1c2040d5  mov ax, 0xb
1c2040d9  sub ax, cx
1c2040dc  mov bp, 0xc
1c2040e0  sub dx, dx
1c2040e3  div bp
1c2040e6  imul ax, bp
1c2040ea  add cx, ax
1c2040ed  movsx eax, cx
1c2040f0  xor ecx, ecx
1c2040f2  mov cx, word ptr [eax*2 + 0x1c24c028]
1c2040fa  jmp 0x1c204113
1c2040fc  cmp ax, 0x7d0
1c204100  jl 0x1c204106
1c204102  mov ax, 0x7d0
1c204106  cmp ax, 0xa
1c20410a  jg 0x1c204110
1c20410c  mov ax, 0xa
1c204110  movsx ecx, ax
1c204113  mov dx, word ptr [ebx + 4]
1c204117  movsx eax, dx
1c20411a  shl eax, 5
1c20411d  add eax, esi
1c20411f  cmp word ptr [0x1c250566], dx
1c204126  jbe 0x1c20414e
1c204128  mov word ptr [eax + 0x18], cx
1c20412c  add eax, 0x20
1c20412f  inc dx
1c204131  cmp word ptr [0x1c250566], dx
1c204138  ja 0x1c204128
1c20413a  jmp 0x1c20414e
1c20413c  mov ax, word ptr [ebx + 2]
1c204140  mov word ptr [edi + 0x4c], ax
1c204144  jmp 0x1c20414e
1c204146  mov ax, word ptr [ebx + 2]
1c20414a  mov word ptr [edi + 0x60], ax
1c20414e  add ebx, 6
1c204151  cmp word ptr [ebx], 0x1e
1c204155  jne 0x1c204054
1c20415b  jmp 0x1c204165
1c20415d  mov edi, dword ptr [esp + 0x14]
1c204161  mov esi, dword ptr [esp + 0x18]
1c204165  test byte ptr [0x1c250e78], 0x80
1c20416c  jne 0x1c204177
1c20416e  test byte ptr [0x1c250e73], 0x20
1c204175  je 0x1c2041cd
1c204177  test byte ptr [0x1c250e73], 0x20
1c20417e  jne 0x1c2041b0
1c204180  cmp byte ptr [0x1c250e7e], 0x1c
1c204187  je 0x1c2041b0
1c204189  xor ecx, ecx
1c20418b  xor eax, eax
1c20418d  mov cx, word ptr [edi + 0x46]
1c204191  mov al, byte ptr [0x1c250e7e]
1c204196  add eax, ecx
1c204198  and eax, 7
1c20419b  movsx eax, word ptr [eax*2 + 0x1c24c1a0]
1c2041a3  imul eax, ecx
1c2041a6  cdq 
1c2041a7  mov ecx, 0x6e
1c2041ac  idiv ecx
1c2041ae  jmp 0x1c2041b8
1c2041b0  xor eax, eax
1c2041b2  mov ax, word ptr [0x1c250560]
1c2041b8  mov cx, word ptr [0x1c250560]
1c2041bf  mov word ptr [esi - 8], cx
1c2041c3  mov word ptr [esi + 0x18], ax
1c2041c7  mov word ptr [0x1c250560], ax
1c2041cd  pop ebp
1c2041ce  pop edi
1c2041cf  pop esi
1c2041d0  pop ebx
1c2041d1  ret 
