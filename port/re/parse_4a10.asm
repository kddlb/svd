1c004a10  sub esp, 0x24
1c004a13  push ebx
1c004a14  push esi
1c004a15  push edi
1c004a16  push ebp
1c004a17  mov ebp, dword ptr [esp + 0x38]
1c004a1b  mov edx, 0xa
1c004a20  mov edi, dword ptr [ebp + 8]
1c004a23  mov esi, dword ptr [ebp + 0x1c]
1c004a26  mov eax, dword ptr [ebp + 0x38]
1c004a29  mov dword ptr [esp + 0x18], edi
1c004a2d  mov dword ptr [0x1c014598], eax
1c004a32  lea eax, [edi + 1]
1c004a35  mov cl, byte ptr [edi]
1c004a37  mov byte ptr [esp + 0x13], cl
1c004a3b  mov dword ptr [esp + 0x18], eax
1c004a3f  test cl, cl
1c004a41  je 0x1c004a99
1c004a43  mov eax, 0x2a
1c004a48  mov ebx, 0x3b
1c004a4d  cmp byte ptr [esp + 0x13], bl
1c004a51  jne 0x1c004a54
1c004a53  inc edx
1c004a54  cmp byte ptr [esp + 0x13], 0x7d
1c004a59  jne 0x1c004a5e
1c004a5b  add edx, 2
1c004a5e  cmp byte ptr [esp + 0x13], al
1c004a62  jne 0x1c004a7d
1c004a64  add edx, 2
1c004a67  mov ecx, dword ptr [esp + 0x18]
1c004a6b  mov cl, byte ptr [ecx]
1c004a6d  mov byte ptr [esp + 0x13], cl
1c004a71  inc dword ptr [esp + 0x18]
1c004a75  cmp cl, al
1c004a77  je 0x1c004a67
1c004a79  dec dword ptr [esp + 0x18]
1c004a7d  cmp byte ptr [esp + 0x13], 0x40
1c004a82  jne 0x1c004a87
1c004a84  add edx, 2
1c004a87  mov ecx, dword ptr [esp + 0x18]
1c004a8b  mov cl, byte ptr [ecx]
1c004a8d  mov byte ptr [esp + 0x13], cl
1c004a91  inc dword ptr [esp + 0x18]
1c004a95  test cl, cl
1c004a97  jne 0x1c004a4d
1c004a99  lea eax, [edx + edx*2]
1c004a9c  mov dword ptr [esp + 0x18], edi
1c004aa0  add eax, eax
1c004aa2  push eax
1c004aa3  push 0x40
1c004aa5  call dword ptr [0x1c015168]
1c004aab  mov dword ptr [ebp + 0x34], eax
1c004aae  mov edi, eax
1c004ab0  test edi, edi
1c004ab2  jne 0x1c004ac1
1c004ab4  mov eax, 0x1b5a
1c004ab9  pop ebp
1c004aba  pop edi
1c004abb  pop esi
1c004abc  pop ebx
1c004abd  add esp, 0x24
1c004ac0  ret 
1c004ac1  xor ebx, ebx
1c004ac3  mov word ptr [esi + 0xc], bx
1c004ac7  mov eax, dword ptr [ebp + 0x40]
1c004aca  add esi, 0x1a
1c004acd  mov ecx, dword ptr [eax + 2]
1c004ad0  mov dword ptr [esi - 8], ecx
1c004ad3  mov edx, dword ptr [0x1c014598]
1c004ad9  mov dword ptr [esi - 0x12], edx
1c004adc  mov eax, dword ptr [ebp + 0x40]
1c004adf  mov dword ptr [esi - 0x16], eax
1c004ae2  mov word ptr [esi + 0xc], bx
1c004ae6  mov eax, dword ptr [ebp + 0x40]
1c004ae9  add esi, 0x1a
1c004aec  mov ecx, dword ptr [eax + 2]
1c004aef  mov dword ptr [esi - 8], ecx
1c004af2  mov edx, dword ptr [0x1c014598]
1c004af8  mov dword ptr [esi - 0x12], edx
1c004afb  mov edx, 0x1b
1c004b00  mov eax, dword ptr [ebp + 0x40]
1c004b03  mov dword ptr [esi - 0x16], eax
1c004b06  mov word ptr [esi + 0xc], dx
1c004b0a  mov eax, dword ptr [ebp + 0x40]
1c004b0d  mov ecx, dword ptr [eax + 0x2c0]
1c004b13  mov dword ptr [esi + 0x12], ecx
1c004b16  mov ecx, 0x50
1c004b1b  mov word ptr [esi + 0xe], cx
1c004b1f  add esi, 0x1a
1c004b22  mov eax, dword ptr [0x1c014598]
1c004b27  mov dword ptr [esi - 0x12], eax
1c004b2a  mov eax, dword ptr [ebp + 0x40]
1c004b2d  mov dword ptr [esi - 0x16], eax
1c004b30  mov word ptr [esi + 0xc], dx
1c004b34  mov eax, dword ptr [ebp + 0x40]
1c004b37  mov edx, dword ptr [eax + 0x2c0]
1c004b3d  mov dword ptr [esi + 0x12], edx
1c004b40  add esi, 0x1a
1c004b43  mov word ptr [esi - 0xc], cx
1c004b47  mov ecx, dword ptr [0x1c014598]
1c004b4d  mov dword ptr [esi - 0x12], ecx
1c004b50  mov eax, dword ptr [ebp + 0x40]
1c004b53  mov dword ptr [esi - 0x16], eax
1c004b56  mov word ptr [esi + 0xc], bx
1c004b5a  mov eax, dword ptr [ebp + 0x40]
1c004b5d  add esi, 0x1a
1c004b60  mov ecx, dword ptr [eax + 2]
1c004b63  mov dword ptr [esp + 0x24], ebx
1c004b67  push 0x1c014594
1c004b6c  mov dword ptr [esi - 8], ecx
1c004b6f  mov edx, dword ptr [0x1c014598]
1c004b75  mov dword ptr [esi - 0x12], edx
1c004b78  mov eax, dword ptr [ebp + 0x40]
1c004b7b  mov dword ptr [esi - 0x16], eax
1c004b7e  mov word ptr [ebp + 0xe], 5
1c004b84  call dword ptr [0x1c01519c]
1c004b8a  add esp, 4
1c004b8d  push 0x1c014594
1c004b92  call dword ptr [0x1c0151a0]
1c004b98  add esp, 4
1c004b9b  mov dword ptr [0x1c01459c], eax
1c004ba0  mov eax, dword ptr [esp + 0x18]
1c004ba4  mov al, byte ptr [eax]
1c004ba6  mov word ptr [esp + 0x16], bx
1c004bab  mov byte ptr [esp + 0x13], al
1c004baf  mov ecx, dword ptr [0x1c01459c]
1c004bb5  inc dword ptr [esp + 0x18]
1c004bb9  mov dword ptr [esp + 0x1c], ebx
1c004bbd  mov dword ptr [esp + 0x30], ebx
1c004bc1  mov eax, dword ptr [ecx + 0x14]
1c004bc4  mov dword ptr [esp + 0x2c], ebx
1c004bc8  shl eax, 0x10
1c004bcb  or eax, dword ptr [ecx + 0x10]
1c004bce  cmp eax, 0x270f000c
1c004bd3  jbe 0x1c004bdd
1c004bd5  mov dword ptr [esp + 0x30], 1
1c004bdd  mov eax, dword ptr [ebp + 0x14]
1c004be0  mov ebx, dword ptr [esp + 0x28]
1c004be4  mov dword ptr [esp + 0x20], eax
1c004be8  test eax, eax
1c004bea  jle 0x1c00504a
1c004bf0  cmp byte ptr [esp + 0x13], 0x7b
1c004bf5  jne 0x1c004c85
1c004bfb  test byte ptr [ebp + 0x4e], 0x80
1c004bff  je 0x1c004c4d
1c004c01  dec dword ptr [esp + 0x20]
1c004c05  cmp byte ptr [esp + 0x13], 0
1c004c0a  je 0x1c004c2f
1c004c0c  mov ecx, 0x7d
1c004c11  xor edx, edx
1c004c13  cmp byte ptr [esp + 0x13], cl
1c004c17  je 0x1c004c2f
1c004c19  mov eax, dword ptr [esp + 0x18]
1c004c1d  mov al, byte ptr [eax]
1c004c1f  mov byte ptr [esp + 0x13], al
1c004c23  inc dword ptr [esp + 0x18]
1c004c27  dec dword ptr [esp + 0x20]
1c004c2b  cmp al, dl
1c004c2d  jne 0x1c004c13
1c004c2f  cmp dword ptr [esp + 0x20], 0
1c004c34  jle 0x1c00504a
1c004c3a  mov eax, dword ptr [esp + 0x18]
1c004c3e  mov al, byte ptr [eax]
1c004c40  mov byte ptr [esp + 0x13], al
1c004c44  inc dword ptr [esp + 0x18]
1c004c48  jmp 0x1c00502b
1c004c4d  cmp dword ptr [esp + 0x1c], 0
1c004c52  jne 0x1c004c58
1c004c54  mov dword ptr [esp + 0x1c], edi
1c004c58  lea eax, [esp + 0x20]
1c004c5c  lea ecx, [esp + 0x13]
1c004c60  lea edx, [esp + 0x18]
1c004c64  push eax
1c004c65  push ecx
1c004c66  push edi
1c004c67  push edx
1c004c68  call 0x1c005180
1c004c6d  add esp, 0x10
1c004c70  mov edi, eax
1c004c72  test edi, edi
1c004c74  je 0x1c005038
1c004c7a  cmp dword ptr [esp + 0x20], 0
1c004c7f  je 0x1c00504a
1c004c85  movsx eax, byte ptr [esp + 0x13]
1c004c8a  sub eax, 0x20
1c004c8d  js 0x1c004c94
1c004c8f  cmp eax, 0x3b
1c004c92  jbe 0x1c004c99
1c004c94  mov eax, 1
1c004c99  mov edx, dword ptr [eax*4 + 0x1c012a68]
1c004ca0  mov eax, dword ptr [esp + 0x18]
1c004ca4  mov al, byte ptr [eax]
1c004ca6  mov byte ptr [esp + 0x28], al
1c004caa  cmp al, 0x48
1c004cac  je 0x1c004cb5
1c004cae  mov eax, 1
1c004cb3  jmp 0x1c004cd2
1c004cb5  xor eax, eax
1c004cb7  mov ebx, dword ptr [esp + 0x18]
1c004cbb  inc ebx
1c004cbc  cmp byte ptr [esp + 0x28], 0x48
1c004cc1  jne 0x1c004cd2
1c004cc3  mov ecx, ebx
1c004cc5  cmp eax, 1
1c004cc8  sbb eax, eax
1c004cca  inc ebx
1c004ccb  neg eax
1c004ccd  cmp byte ptr [ecx], 0x48
1c004cd0  je 0x1c004cc3
1c004cd2  mov cl, 0
1c004cd4  cmp eax, 1
1c004cd7  adc cl, 0xff
1c004cda  mov al, byte ptr [edx]
1c004cdc  and cl, byte ptr [esp + 0x28]
1c004ce0  cmp cl, al
1c004ce2  je 0x1c004cf0
1c004ce4  cmp byte ptr [edx], 0
1c004ce7  je 0x1c004cf0
1c004ce9  add edx, 2
1c004cec  cmp byte ptr [edx], cl
1c004cee  jne 0x1c004ce4
1c004cf0  xor ebx, ebx
1c004cf2  mov bl, byte ptr [edx + 1]
1c004cf5  cmp ebx, 0xff
1c004cfb  jne 0x1c004d1c
1c004cfd  test al, al
1c004cff  je 0x1c004d05
1c004d01  inc dword ptr [esp + 0x18]
1c004d05  mov dword ptr [esp + 0x24], 0x1b59
1c004d0d  mov dword ptr [esp + 0x20], 0
1c004d15  mov ebx, 8
1c004d1a  jmp 0x1c004d3b
1c004d1c  cmp byte ptr [edx], 0
1c004d1f  je 0x1c004d29
1c004d21  inc dword ptr [esp + 0x18]
1c004d25  dec dword ptr [esp + 0x20]
1c004d29  mov eax, dword ptr [esp + 0x18]
1c004d2d  mov al, byte ptr [eax]
1c004d2f  mov byte ptr [esp + 0x13], al
1c004d33  inc dword ptr [esp + 0x18]
1c004d37  dec dword ptr [esp + 0x20]
1c004d3b  mov ecx, 1
1c004d40  mov eax, dword ptr [0x1c014598]
1c004d45  mov edx, dword ptr [eax + 0x1c]
1c004d48  mov eax, dword ptr [edx + ebx*4]
1c004d4b  test eax, 0x40000200
1c004d50  je 0x1c004dab
1c004d52  mov eax, dword ptr [esi - 0x12]
1c004d55  movsx ecx, word ptr [esi - 0xe]
1c004d59  mov edx, dword ptr [eax + 0x1c]
1c004d5c  test byte ptr [edx + ecx*4 + 3], 0x10
1c004d61  je 0x1c004d99
1c004d63  cmp ebx, 0x68
1c004d66  jne 0x1c004d72
1c004d68  lea ecx, [esi - 0xa]
1c004d6b  mov word ptr [ecx], 5
1c004d70  jmp 0x1c004d8b
1c004d72  lea ecx, [esi - 0xa]
1c004d75  cmp ebx, 0x69
1c004d78  jne 0x1c004d81
1c004d7a  mov word ptr [ecx], 2
1c004d7f  jmp 0x1c004d8b
1c004d81  lea eax, [ebx - 0x5e]
1c004d84  movzx ax, al
1c004d88  mov word ptr [ecx], ax
1c004d8b  cmp word ptr [ecx], 0
1c004d8f  je 0x1c004d95
1c004d91  or dword ptr [esi - 4], 0x30
1c004d95  xor ecx, ecx
1c004d97  jmp 0x1c004dab
1c004d99  xor ecx, ecx
1c004d9b  dec dword ptr [esp + 0x18]
1c004d9f  mov dword ptr [esp + 0x24], 0x1b59
1c004da7  mov byte ptr [esp + 0x13], cl
1c004dab  cmp ebx, 0x6a
1c004dae  jne 0x1c004dbd
1c004db0  test byte ptr [ebp + 0x4e], 0x80
1c004db4  jne 0x1c004dbb
1c004db6  inc word ptr [esp + 0x16]
1c004dbb  xor ecx, ecx
1c004dbd  cmp ebx, 0x6b
1c004dc0  jne 0x1c004e47
1c004dc6  mov eax, dword ptr [esp + 0x18]
1c004dca  dec eax
1c004dcb  push eax
1c004dcc  call 0x1c0056e0
1c004dd1  mov word ptr [esp + 0x18], ax
1c004dd6  mov eax, dword ptr [esp + 0x18]
1c004dda  add esp, 4
1c004ddd  and eax, 0xffff
1c004de2  cmp eax, 0xffff8000
1c004de7  je 0x1c005042
1c004ded  mov eax, dword ptr [esp + 0x18]
1c004df1  mov al, byte ptr [eax]
1c004df3  mov byte ptr [esp + 0x13], al
1c004df7  inc dword ptr [esp + 0x18]
1c004dfb  test al, al
1c004dfd  je 0x1c004e3d
1c004dff  dec dword ptr [esp + 0x20]
1c004e03  call dword ptr [0x1c0151a4]
1c004e09  cmp dword ptr [eax], 1
1c004e0c  jle 0x1c004e22
1c004e0e  push 4
1c004e10  xor eax, eax
1c004e12  mov al, byte ptr [esp + 0x17]
1c004e16  push eax
1c004e17  call dword ptr [0x1c0151ac]
1c004e1d  add esp, 8
1c004e20  jmp 0x1c004e39
1c004e22  call dword ptr [0x1c0151a8]
1c004e28  mov edx, dword ptr [eax]
1c004e2a  xor ecx, ecx
1c004e2c  mov cl, byte ptr [esp + 0x13]
1c004e30  xor eax, eax
1c004e32  mov ax, word ptr [edx + ecx*2]
1c004e36  and eax, 4
1c004e39  test eax, eax
1c004e3b  jne 0x1c004ded
1c004e3d  mov dword ptr [esp + 0x2c], 1
1c004e45  xor ecx, ecx
1c004e47  mov eax, dword ptr [0x1c014598]
1c004e4c  mov edx, dword ptr [eax + 0x1c]
1c004e4f  test byte ptr [edx + ebx*4 + 3], 4
1c004e54  je 0x1c004e82
1c004e56  cmp word ptr [ebp + 0xe], 4
1c004e5b  je 0x1c004e80
1c004e5d  mov edx, dword ptr [esi - 0x12]
1c004e60  movsx eax, word ptr [esi - 0xe]
1c004e64  mov edx, dword ptr [edx + 0x1c]
1c004e67  test byte ptr [edx + eax*4 + 3], 4
1c004e6c  je 0x1c004e82
1c004e6e  test ebx, ebx
1c004e70  je 0x1c004e80
1c004e72  dec word ptr [ebp + 0xe]
1c004e76  sub esi, 0x1a
1c004e79  mov ecx, 1
1c004e7e  jmp 0x1c004e82
1c004e80  xor ecx, ecx
1c004e82  cmp ebx, 5
1c004e85  je 0x1c004e8e
1c004e87  cmp ebx, 6
1c004e8a  je 0x1c004e97
1c004e8c  jmp 0x1c004ec2
1c004e8e  or dword ptr [esi + 0x16], 0x800
1c004e95  jmp 0x1c004ec0
1c004e97  mov cx, word ptr [esi - 0xe]
1c004e9b  mov eax, dword ptr [esi - 0x12]
1c004e9e  mov eax, dword ptr [eax + 0x1c]
1c004ea1  movsx edx, cx
1c004ea4  test byte ptr [eax + edx*4 + 3], 4
1c004ea9  je 0x1c004eb9
1c004eab  test cx, cx
1c004eae  jne 0x1c004ec0
1c004eb0  or dword ptr [esi - 0x1e], 0x1000
1c004eb7  jmp 0x1c004ec0
1c004eb9  or dword ptr [esi - 4], 0x1000
1c004ec0  xor ecx, ecx
1c004ec2  mov eax, dword ptr [0x1c014598]
1c004ec7  cmp dword ptr [eax + 0x10], 1
1c004ecb  jne 0x1c004f3e
1c004ecd  cmp ebx, 0x36
1c004ed0  jne 0x1c004f3e
1c004ed2  cmp dword ptr [esp + 0x1c], 0
1c004ed7  jne 0x1c004f3e
1c004ed9  cmp word ptr [esp + 0x16], 0
1c004edf  jne 0x1c004f3e
1c004ee1  movsx edx, word ptr [esi - 0xe]
1c004ee5  sub edx, 9
1c004ee8  mov dword ptr [esp + 0x28], ebx
1c004eec  cmp edx, 0x20
1c004eef  ja 0x1c004f21
1c004ef1  xor eax, eax
1c004ef3  mov al, byte ptr [edx + 0x1c005154]
1c004ef9  jmp dword ptr [eax*4 + 0x1c00513c]
1c004f00  mov ebx, 0x2b
1c004f05  jmp 0x1c004f21
1c004f07  mov ebx, 0x2d
1c004f0c  jmp 0x1c004f21
1c004f0e  mov ebx, 0x2f
1c004f13  jmp 0x1c004f21
1c004f15  mov ebx, 0x31
1c004f1a  jmp 0x1c004f21
1c004f1c  mov ebx, 0x33
1c004f21  cmp dword ptr [esp + 0x28], ebx
1c004f25  je 0x1c004f48
1c004f27  dec word ptr [ebp + 0xe]
1c004f2b  mov eax, dword ptr [esi - 0x1a]
1c004f2e  sub esi, 0x1a
1c004f31  test eax, eax
1c004f33  je 0x1c004f48
1c004f35  sub edi, 6
1c004f38  mov dword ptr [esp + 0x1c], eax
1c004f3c  jmp 0x1c004f48
1c004f3e  cmp ebx, 0x5c
1c004f41  jne 0x1c004f48
1c004f43  mov ebx, 0x27
1c004f48  cmp dword ptr [esp + 0x30], 0
1c004f4d  je 0x1c004f51
1c004f4f  xor ecx, ecx
1c004f51  test ecx, ecx
1c004f53  je 0x1c00502b
1c004f59  inc word ptr [ebp + 0xe]
1c004f5d  lea ecx, [ebx + ebx*4]
1c004f60  mov word ptr [esi + 0xc], bx
1c004f64  lea ecx, [ecx + ecx*4]
1c004f67  add ecx, ebx
1c004f69  mov eax, dword ptr [ebp + 0x40]
1c004f6c  test ebx, ebx
1c004f6e  mov edx, dword ptr [ecx + eax + 2]
1c004f72  mov dword ptr [esi + 0x12], edx
1c004f75  mov ecx, dword ptr [0x1c014598]
1c004f7b  mov dword ptr [esi + 8], ecx
1c004f7e  mov eax, dword ptr [ebp + 0x40]
1c004f81  mov dword ptr [esi + 4], eax
1c004f84  je 0x1c005028
1c004f8a  cmp word ptr [esp + 0x16], 0
1c004f90  je 0x1c004fc6
1c004f92  cmp dword ptr [esp + 0x1c], 0
1c004f97  jne 0x1c004f9d
1c004f99  mov dword ptr [esp + 0x1c], edi
1c004f9d  test edi, edi
1c004f9f  je 0x1c004fb8
1c004fa1  mov word ptr [edi], 0x2bc
1c004fa6  add edi, 6
1c004fa9  mov ax, word ptr [esp + 0x16]
1c004fae  mov word ptr [edi - 4], ax
1c004fb2  mov word ptr [edi - 2], 0
1c004fb8  or dword ptr [esi + 0x16], 0x400
1c004fbf  mov word ptr [esp + 0x16], 0
1c004fc6  cmp dword ptr [esp + 0x2c], 0
1c004fcb  je 0x1c004ffb
1c004fcd  cmp dword ptr [esp + 0x1c], 0
1c004fd2  jne 0x1c004fd8
1c004fd4  mov dword ptr [esp + 0x1c], edi
1c004fd8  test edi, edi
1c004fda  je 0x1c004ff3
1c004fdc  mov word ptr [edi], 0x334
1c004fe1  add edi, 6
1c004fe4  mov ax, word ptr [esp + 0x14]
1c004fe9  mov word ptr [edi - 4], ax
1c004fed  mov word ptr [edi - 2], 0
1c004ff3  mov dword ptr [esp + 0x2c], 0
1c004ffb  cmp dword ptr [esp + 0x1c], 0
1c005000  je 0x1c00501a
1c005002  test edi, edi
1c005004  je 0x1c00501a
1c005006  mov word ptr [edi], 0x1e
1c00500b  add edi, 6
1c00500e  mov word ptr [edi - 4], 0
1c005014  mov word ptr [edi - 2], 0
1c00501a  mov eax, dword ptr [esp + 0x1c]
1c00501e  mov dword ptr [esp + 0x1c], 0
1c005026  mov dword ptr [esi], eax
1c005028  add esi, 0x1a
1c00502b  cmp dword ptr [esp + 0x20], 0
1c005030  jg 0x1c004bf0
1c005036  jmp 0x1c00504a
1c005038  mov dword ptr [esp + 0x24], 0x1b67
1c005040  jmp 0x1c00504a
1c005042  mov dword ptr [esp + 0x24], 0x1b67
1c00504a  mov eax, dword ptr [esp + 0x18]
1c00504e  dec eax
1c00504f  cmp dword ptr [esp + 0x24], 0
1c005054  mov dword ptr [ebp + 0x10], eax
1c005057  jne 0x1c00510c
1c00505d  cmp word ptr [ebp + 0xe], 4
1c005062  jbe 0x1c005111
1c005068  mov ax, word ptr [esi - 0xe]
1c00506c  test ax, ax
1c00506f  jne 0x1c005079
1c005071  mov word ptr [esi - 0xe], 4
1c005077  jmp 0x1c0050a4
1c005079  mov ecx, dword ptr [esi - 0x12]
1c00507c  movsx eax, ax
1c00507f  mov edx, dword ptr [ecx + 0x1c]
1c005082  test byte ptr [edx + eax*4 + 3], 2
1c005087  je 0x1c00508e
1c005089  cmp ebx, 0x1b
1c00508c  jne 0x1c0050a4
1c00508e  mov word ptr [esi + 0xc], 4
1c005094  mov eax, dword ptr [ebp + 0x40]
1c005097  add esi, 0x1a
1c00509a  mov ecx, dword ptr [eax + 0x6a]
1c00509d  mov dword ptr [esi - 8], ecx
1c0050a0  inc word ptr [ebp + 0xe]
1c0050a4  xor eax, eax
1c0050a6  cmp dword ptr [esp + 0x1c], eax
1c0050aa  je 0x1c0050c4
1c0050ac  test edi, edi
1c0050ae  je 0x1c0050bd
1c0050b0  mov word ptr [edi], 0x1e
1c0050b5  mov word ptr [edi + 2], ax
1c0050b9  mov word ptr [edi + 4], ax
1c0050bd  mov eax, dword ptr [esp + 0x1c]
1c0050c1  mov dword ptr [esi - 0x1a], eax
1c0050c4  mov ecx, 0x1b
1c0050c9  add esi, 0x1a
1c0050cc  mov word ptr [esi - 0xe], cx
1c0050d0  mov eax, dword ptr [ebp + 0x40]
1c0050d3  add esi, 0x1a
1c0050d6  mov edx, dword ptr [eax + 0x2c0]
1c0050dc  mov dword ptr [esi - 0x22], edx
1c0050df  mov word ptr [esi - 0xe], cx
1c0050e3  mov eax, dword ptr [ebp + 0x40]
1c0050e6  mov edx, dword ptr [eax + 0x2c0]
1c0050ec  mov eax, 0xff
1c0050f1  mov dword ptr [esi - 8], edx
1c0050f4  mov word ptr [esi + 0xc], ax
1c0050f8  mov word ptr [esi + 0x10], ax
1c0050fc  mov word ptr [esi + 0xe], ax
1c005100  mov dword ptr [esi + 0x12], 0
1c005107  add word ptr [ebp + 0xe], 3
1c00510c  cmp word ptr [ebp + 0xe], 4
1c005111  jne 0x1c005121
1c005113  mov dword ptr [esp + 0x24], 0x3e8
1c00511b  mov word ptr [ebp + 0xe], 0
1c005121  cmp dword ptr [esp + 0x30], 0
1c005126  je 0x1c005130
1c005128  mov dword ptr [esp + 0x24], 0x1b6d
1c005130  mov eax, dword ptr [esp + 0x24]
1c005134  pop ebp
1c005135  pop edi
1c005136  pop esi
1c005137  pop ebx
1c005138  add esp, 0x24
1c00513b  ret 