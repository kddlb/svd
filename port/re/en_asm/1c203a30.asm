1c203a30  cmp word ptr [0x1c25058c], 0
1c203a38  jle 0x1c203aa6
1c203a3a  cmp word ptr [0x1c25055c], 0
1c203a42  jle 0x1c203aa6
1c203a44  xor ax, ax
1c203a47  xor ecx, ecx
1c203a49  mov cx, word ptr [0x1c250566]
1c203a50  add ecx, ecx
1c203a52  add ecx, dword ptr [0x1c250714]
1c203a58  cmp word ptr [0x1c25058c], ax
1c203a5f  jle 0x1c203a79
1c203a61  mov dx, word ptr [0x1c25055c]
1c203a68  sub ecx, 2
1c203a6b  inc ax
1c203a6d  mov word ptr [ecx], dx
1c203a70  cmp word ptr [0x1c25058c], ax
1c203a77  jg 0x1c203a61
1c203a79  test byte ptr [0x1c250e70], 1
1c203a80  je 0x1c203aa6
1c203a82  sub word ptr [ecx], 8
1c203a86  sub word ptr [ecx + 2], 4
1c203a8b  xor ecx, ecx
1c203a8d  mov eax, dword ptr [0x1c250714]
1c203a92  mov cx, word ptr [0x1c250566]
1c203a99  lea eax, [eax + ecx*2 - 2]
1c203a9d  sub word ptr [eax], 8
1c203aa1  sub word ptr [eax - 2], 4
1c203aa6  ret 
