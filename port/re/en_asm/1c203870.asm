1c203870  sub esp, 8
1c203873  push ebx
1c203874  push esi
1c203875  mov esi, dword ptr [esp + 0x14]
1c203879  push edi
1c20387a  push ebp
1c20387b  mov ecx, 0x64
1c203880  xor ebp, ebp
1c203882  mov eax, dword ptr [esi + 0x38]
1c203885  mov bp, word ptr [0x1c250566]
1c20388c  mov edi, 0x8000
1c203891  imul eax, ebp
1c203894  cdq 
1c203895  idiv ecx
1c203897  lea ebx, [eax + 1]
1c20389a  mov eax, dword ptr [esi + 0x3c]
1c20389d  imul eax, ebp
1c2038a0  add eax, 0x32
1c2038a3  cdq 
1c2038a4  idiv ecx
1c2038a6  mov ecx, eax
1c2038a8  sub ecx, ebx
1c2038aa  cmp ecx, 1
1c2038ad  jg 0x1c2038b4
1c2038af  mov ecx, 1
1c2038b4  mov eax, edi
1c2038b6  mov ebp, 0x8000
1c2038bb  cdq 
1c2038bc  idiv ecx
1c2038be  sub ebp, eax
1c2038c0  mov edx, eax
1c2038c2  mov ecx, 0x1c250a50
1c2038c7  test ebx, ebx
1c2038c9  jle 0x1c2038e5
1c2038cb  mov edi, ecx
1c2038cd  mov eax, 0x1000100
1c2038d2  mov ecx, ebx
1c2038d4  shr ecx, 1
1c2038d7  rep stosd dword ptr es:[edi], eax
1c2038d9  adc ecx, ecx
1c2038db  rep stosw word ptr es:[edi], ax
1c2038de  lea ecx, [ebx*2 + 0x1c250a50]
1c2038e5  xor eax, eax
1c2038e7  mov ax, word ptr [0x1c250566]
1c2038ed  cmp eax, ebx
1c2038ef  jle 0x1c203912
1c2038f1  test ebp, ebp
1c2038f3  jge 0x1c2038f7
1c2038f5  xor ebp, ebp
1c2038f7  mov eax, ebp
1c2038f9  add ecx, 2
1c2038fc  sar eax, 7
1c2038ff  sub ebp, edx
1c203901  mov word ptr [ecx - 2], ax
1c203905  inc ebx
1c203906  xor eax, eax
1c203908  mov ax, word ptr [0x1c250566]
1c20390e  cmp eax, ebx
1c203910  jg 0x1c2038f1
1c203912  xor eax, eax
1c203914  mov ax, word ptr [0x1c250566]
1c20391a  mov word ptr [eax*2 + 0x1c250a4e], 0
1c203924  mov ecx, dword ptr [esi + 0x34]
1c203927  cmp ecx, 8
1c20392a  jl 0x1c203931
1c20392c  mov ecx, 8
1c203931  test ecx, ecx
1c203933  jg 0x1c203937
1c203935  xor ecx, ecx
1c203937  shl ecx, 4
1c20393a  mov edx, dword ptr [esi + 0x20]
1c20393d  mov eax, dword ptr [esi + 0x2c]
1c203940  mov ebp, dword ptr [esi + 8]
1c203943  add eax, ecx
1c203945  mov edi, 0x1c250150
1c20394a  mov dword ptr [esp + 0x10], ebp
1c20394e  mov ebx, dword ptr [eax*4 + 0x1c24c1b0]
1c203955  xor eax, eax
1c203957  mov dword ptr [esp + 0x14], ebx
1c20395b  cmp word ptr [0x1c250566], ax
1c203962  mov ebx, 0x1c250a50
1c203967  jbe 0x1c20399b
1c203969  mov ebp, dword ptr [esp + 0x10]
1c20396d  add ebx, 2
1c203970  sub ebp, edx
1c203972  add edi, 2
1c203975  imul ebp, dword ptr [esp + 0x14]
1c20397a  sar ebp, 8
1c20397d  inc eax
1c20397e  add edx, ebp
1c203980  movsx ebp, word ptr [ebx - 2]
1c203984  imul ebp, edx
1c203987  sar ebp, 8
1c20398a  mov word ptr [edi - 2], bp
1c20398e  xor ebp, ebp
1c203990  mov bp, word ptr [0x1c250566]
1c203997  cmp ebp, eax
1c203999  jg 0x1c203969
1c20399b  xor eax, eax
1c20399d  mov edx, dword ptr [esi + 4]
1c2039a0  mov ax, word ptr [0x1c250566]
1c2039a6  lea edi, [eax*2 + 0x1c25014e]
1c2039ad  lea ebx, [eax*2 - 2]
1c2039b4  add edx, ebx
1c2039b6  mov eax, dword ptr [esi + 0xc]
1c2039b9  add ebx, 0x1c250a50
1c2039bf  mov dword ptr [esp + 0x10], eax
1c2039c3  mov eax, dword ptr [esi + 0x30]
1c2039c6  mov esi, dword ptr [esi + 0x24]
1c2039c9  add eax, ecx
1c2039cb  mov ecx, dword ptr [eax*4 + 0x1c24c1b0]
1c2039d2  mov dword ptr [esp + 0x14], ecx
1c2039d6  xor ecx, ecx
1c2039d8  cmp word ptr [0x1c250566], cx
1c2039df  jbe 0x1c203a20
1c2039e1  mov eax, 0x100
1c2039e6  sub ebx, 2
1c2039e9  sub edi, 2
1c2039ec  sub edx, 2
1c2039ef  movsx ebp, word ptr [ebx + 2]
1c2039f3  sub eax, ebp
1c2039f5  inc ecx
1c2039f6  imul eax, esi
1c2039f9  sar eax, 8
1c2039fc  add ax, word ptr [edi + 2]
1c203a00  mov word ptr [edx + 2], ax
1c203a04  mov eax, dword ptr [esp + 0x10]
1c203a08  sub eax, esi
1c203a0a  imul eax, dword ptr [esp + 0x14]
1c203a0f  sar eax, 8
1c203a12  add esi, eax
1c203a14  xor eax, eax
1c203a16  mov ax, word ptr [0x1c250566]
1c203a1c  cmp eax, ecx
1c203a1e  jg 0x1c2039e1
1c203a20  pop ebp
1c203a21  pop edi
1c203a22  pop esi
1c203a23  pop ebx
1c203a24  add esp, 8
1c203a27  ret 
