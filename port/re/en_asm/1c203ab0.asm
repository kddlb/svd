1c203ab0  mov eax, dword ptr [esp + 0xc]
1c203ab4  push ebx
1c203ab5  push esi
1c203ab6  push edi
1c203ab7  push ebp
1c203ab8  mov edi, dword ptr [eax]
1c203aba  test edi, edi
1c203abc  je 0x1c203b82
1c203ac2  cmp word ptr [edi], 0x1e
1c203ac6  mov esi, dword ptr [esp + 0x14]
1c203aca  je 0x1c203b86
1c203ad0  movsx eax, word ptr [edi]
1c203ad3  sub eax, 0x32
1c203ad6  cmp eax, 0xc8
1c203adb  ja 0x1c203b73
1c203ae1  xor ecx, ecx
1c203ae3  mov cl, byte ptr [eax + 0x1c203f5c]
1c203ae9  jmp dword ptr [ecx*4 + 0x1c203f44]
1c203af0  movsx eax, word ptr [edi + 2]
1c203af4  push eax
1c203af5  push esi
1c203af6  call 0x1c204680
1c203afb  add esp, 8
1c203afe  jmp 0x1c203b73
1c203b00  mov ax, word ptr [edi + 2]
1c203b04  mov word ptr [esi + 0xae], ax
1c203b0b  jmp 0x1c203b73
1c203b0d  mov ax, word ptr [edi + 2]
1c203b11  test ax, ax
1c203b14  jg 0x1c203b47
1c203b16  mov bx, word ptr [esi + 0xac]
1c203b1d  imul bx, bx, 0xc
1c203b21  add bx, word ptr [esi + 0xae]
1c203b28  sub bx, ax
1c203b2b  cmp bx, 0x55
1c203b2f  jl 0x1c203b73
1c203b31  mov cx, 0xc
1c203b35  lea eax, [ebx - 0x49]
1c203b38  sub dx, dx
1c203b3b  div cx
1c203b3e  imul ax, cx
1c203b42  sub bx, ax
1c203b45  jmp 0x1c203b73
1c203b47  cmp ax, 0x7d0
1c203b4b  jl 0x1c203b51
1c203b4d  mov ax, 0x7d0
1c203b51  cmp ax, 0xa
1c203b55  jg 0x1c203b5b
1c203b57  mov ax, 0xa
1c203b5b  mov word ptr [esi + 0x46], ax
1c203b5f  jmp 0x1c203b73
1c203b61  mov ax, word ptr [edi + 2]
1c203b65  mov word ptr [esi + 0x4c], ax
1c203b69  jmp 0x1c203b73
1c203b6b  mov ax, word ptr [edi + 2]
1c203b6f  mov word ptr [esi + 0x60], ax
1c203b73  add edi, 6
1c203b76  cmp word ptr [edi], 0x1e
1c203b7a  jne 0x1c203ad0
1c203b80  jmp 0x1c203b86
1c203b82  mov esi, dword ptr [esp + 0x14]
1c203b86  mov ebx, dword ptr [0x1c250e78]
1c203b8c  and ebx, 4
1c203b8f  shr ebx, 2
1c203b92  test byte ptr [0x1c2552ff], 0x20
1c203b99  jne 0x1c203bba
1c203b9b  test byte ptr [0x1c2552ff], 8
1c203ba2  je 0x1c203bba
1c203ba4  test byte ptr [0x1c2552ff], 1
1c203bab  je 0x1c203bb6
1c203bad  test byte ptr [0x1c2552fd], 0x80
1c203bb4  je 0x1c203bba
1c203bb6  xor ebp, ebp
1c203bb8  jmp 0x1c203bbf
1c203bba  mov ebp, 1
1c203bbf  test byte ptr [0x1c250e78], 0x80
1c203bc6  je 0x1c203cd0
1c203bcc  test byte ptr [0x1c250e65], 1
1c203bd3  je 0x1c203bea
1c203bd5  test byte ptr [0x1c250e73], 8
1c203bdc  je 0x1c203bea
1c203bde  mov dword ptr [0x1c250a00], 0x64
1c203be8  jmp 0x1c203bfb
1c203bea  mov ecx, dword ptr [esi + 0xc4]
1c203bf0  xor eax, eax
1c203bf2  mov al, byte ptr [ecx]
1c203bf4  add eax, eax
1c203bf6  mov dword ptr [0x1c250a00], eax
1c203bfb  mov ecx, dword ptr [esi + 0xc8]
1c203c01  xor eax, eax
1c203c03  inc dword ptr [esi + 0xc4]
1c203c09  mov al, byte ptr [ecx]
1c203c0b  add eax, eax
1c203c0d  mov dword ptr [0x1c250e80], eax
1c203c12  xor eax, eax
1c203c14  mov ecx, dword ptr [esi + 0xcc]
1c203c1a  inc dword ptr [esi + 0xc8]
1c203c20  mov al, byte ptr [ecx]
1c203c22  add eax, eax
1c203c24  mov dword ptr [0x1c250e84], eax
1c203c29  mov ecx, dword ptr [esi + 0xd8]
1c203c2f  inc dword ptr [esi + 0xcc]
1c203c35  mov al, byte ptr [ecx]
1c203c37  and al, 0x70
1c203c39  shr al, 1
1c203c3c  movzx ax, al
1c203c40  mov word ptr [0x1c250e6a], ax
1c203c46  inc dword ptr [esi + 0xd8]
1c203c4c  mov dword ptr [0x1c250148], 1
1c203c56  mov dword ptr [0x1c2552f4], 0
1c203c60  test byte ptr [0x1c250e73], 2
1c203c67  je 0x1c203c70
1c203c69  mov eax, dword ptr [0x1c250e70]
1c203c6e  jmp 0x1c203c93
1c203c70  test byte ptr [0x1c2552ff], 2
1c203c77  je 0x1c203c80
1c203c79  mov eax, dword ptr [0x1c2552fc]
1c203c7e  jmp 0x1c203c93
1c203c80  test byte ptr [0x1c250e5f], 2
1c203c87  mov eax, 0
1c203c8c  je 0x1c203c93
1c203c8e  mov eax, dword ptr [0x1c250e5c]
1c203c93  test eax, 0x400000
1c203c98  jne 0x1c203cd0
1c203c9a  test ah, 2
1c203c9d  je 0x1c203cb6
1c203c9f  add dword ptr [0x1c250a00], 4
1c203ca6  add dword ptr [0x1c250e80], 7
1c203cad  add dword ptr [0x1c250e84], 4
1c203cb4  jmp 0x1c203cd0
1c203cb6  test ah, 0x40
1c203cb9  je 0x1c203cd0
1c203cbb  sub dword ptr [0x1c250a00], 4
1c203cc2  sub dword ptr [0x1c250e80], 7
1c203cc9  sub dword ptr [0x1c250e84], 4
1c203cd0  cmp word ptr [esi + 0x4c], 0
1c203cd5  jne 0x1c203f3e
1c203cdb  test byte ptr [0x1c250e71], 0x20
1c203ce2  je 0x1c203d18
1c203ce4  test byte ptr [0x1c250e66], 0x80
1c203ceb  je 0x1c203d18
1c203ced  test byte ptr [0x1c2552ff], 0x10
1c203cf4  je 0x1c203d18
1c203cf6  cmp byte ptr [0x1c255300], 0
1c203cfd  je 0x1c203d18
1c203cff  mov eax, dword ptr [0x1c250a00]
1c203d04  mov edi, dword ptr [esp + 0x18]
1c203d08  sub eax, 0xa
1c203d0b  push eax
1c203d0c  push edi
1c203d0d  push esi
1c203d0e  call 0x1c204550
1c203d13  add esp, 0xc
1c203d16  jmp 0x1c203d1c
1c203d18  mov edi, dword ptr [esp + 0x18]
1c203d1c  cmp dword ptr [0x1c2552f4], 0
1c203d23  je 0x1c203d61
1c203d25  cmp word ptr [0x1c250e6a], 0
1c203d2d  je 0x1c203d4c
1c203d2f  movsx eax, word ptr [0x1c250e6a]
1c203d36  add eax, dword ptr [0x1c250e84]
1c203d3c  push eax
1c203d3d  push edi
1c203d3e  push esi
1c203d3f  call 0x1c2045b0
1c203d44  add esp, 0xc
1c203d47  pop ebp
1c203d48  pop edi
1c203d49  pop esi
1c203d4a  pop ebx
1c203d4b  ret 
1c203d4c  mov eax, dword ptr [0x1c250e84]
1c203d51  push eax
1c203d52  push edi
1c203d53  push esi
1c203d54  call 0x1c2045b0
1c203d59  add esp, 0xc
1c203d5c  pop ebp
1c203d5d  pop edi
1c203d5e  pop esi
1c203d5f  pop ebx
1c203d60  ret 
1c203d61  xor eax, eax
1c203d63  cmp dword ptr [0x1c250148], eax
1c203d69  je 0x1c203df7
1c203d6f  test byte ptr [0x1c250e73], 8
1c203d76  mov dword ptr [0x1c2552f4], eax
1c203d7b  je 0x1c203df7
1c203d7d  test byte ptr [0x1c250e73], 2
1c203d84  mov dword ptr [0x1c250148], eax
1c203d89  je 0x1c203d9a
1c203d8b  mov eax, dword ptr [0x1c250a00]
1c203d90  push eax
1c203d91  push edi
1c203d92  push esi
1c203d93  call 0x1c204500
1c203d98  jmp 0x1c203df4
1c203d9a  test byte ptr [0x1c250e65], 1
1c203da1  je 0x1c203dcb
1c203da3  mov eax, dword ptr [0x1c250a00]
1c203da8  push eax
1c203da9  push edi
1c203daa  push esi
1c203dab  call 0x1c204500
1c203db0  add esp, 0xc
1c203db3  mov eax, dword ptr [0x1c250e80]
1c203db8  add eax, dword ptr [0x1c250a00]
1c203dbe  sar eax, 1
1c203dc1  push eax
1c203dc2  push edi
1c203dc3  push esi
1c203dc4  call 0x1c204550
1c203dc9  jmp 0x1c203df4
1c203dcb  test ebx, ebx
1c203dcd  je 0x1c203de7
1c203dcf  test byte ptr [0x1c2552ff], 2
1c203dd6  je 0x1c203de7
1c203dd8  mov eax, dword ptr [0x1c250a00]
1c203ddd  push eax
1c203dde  push edi
1c203ddf  push esi
1c203de0  call 0x1c204550
1c203de5  jmp 0x1c203df4
1c203de7  mov eax, dword ptr [0x1c250a00]
1c203dec  push eax
1c203ded  push edi
1c203dee  push esi
1c203def  call 0x1c2045b0
1c203df4  add esp, 0xc
1c203df7  test byte ptr [0x1c250e73], 2
1c203dfe  je 0x1c203ec0
1c203e04  test byte ptr [0x1c250e66], 4
1c203e0b  je 0x1c203e28
1c203e0d  test byte ptr [0x1c250e67], 8
1c203e14  jne 0x1c203e28
1c203e16  mov eax, dword ptr [0x1c250e80]
1c203e1b  add eax, 8
1c203e1e  push eax
1c203e1f  push edi
1c203e20  push esi
1c203e21  call 0x1c204500
1c203e26  jmp 0x1c203e8f
1c203e28  cmp byte ptr [0x1c250e74], 0
1c203e2f  je 0x1c203e6f
1c203e31  test ebx, ebx
1c203e33  je 0x1c203e44
1c203e35  mov eax, dword ptr [0x1c250e80]
1c203e3a  push eax
1c203e3b  push edi
1c203e3c  push esi
1c203e3d  call 0x1c204500
1c203e42  jmp 0x1c203e8f
1c203e44  test byte ptr [0x1c250554], 0x80
1c203e4b  jne 0x1c203e82
1c203e4d  test dword ptr [0x1c2552fc], 0x10002000
1c203e57  mov eax, dword ptr [0x1c250e80]
1c203e5c  push eax
1c203e5d  push edi
1c203e5e  push esi
1c203e5f  je 0x1c203e68
1c203e61  call 0x1c204610
1c203e66  jmp 0x1c203e8f
1c203e68  call 0x1c2045b0
1c203e6d  jmp 0x1c203e8f
1c203e6f  test ebx, ebx
1c203e71  je 0x1c203e82
1c203e73  mov eax, dword ptr [0x1c250e80]
1c203e78  push eax
1c203e79  push edi
1c203e7a  push esi
1c203e7b  call 0x1c204500
1c203e80  jmp 0x1c203e8f
1c203e82  mov eax, dword ptr [0x1c250e80]
1c203e87  push eax
1c203e88  push edi
1c203e89  push esi
1c203e8a  call 0x1c204550
1c203e8f  add esp, 0xc
1c203e92  test ebx, ebx
1c203e94  jne 0x1c203ec4
1c203e96  cmp word ptr [0x1c250e6a], 0
1c203e9e  jne 0x1c203ec0
1c203ea0  test byte ptr [0x1c250554], 0x80
1c203ea7  mov eax, dword ptr [0x1c250e84]
1c203eac  push eax
1c203ead  push edi
1c203eae  push esi
1c203eaf  je 0x1c203eb8
1c203eb1  call 0x1c2045b0
1c203eb6  jmp 0x1c203ebd
1c203eb8  call 0x1c204610
1c203ebd  add esp, 0xc
1c203ec0  test ebx, ebx
1c203ec2  je 0x1c203f3e
1c203ec4  test ebp, ebp
1c203ec6  je 0x1c203ef1
1c203ec8  cmp word ptr [0x1c250e6a], 0
1c203ed0  jne 0x1c203ef1
1c203ed2  mov eax, dword ptr [0x1c250e84]
1c203ed7  push eax
1c203ed8  push edi
1c203ed9  push esi
1c203eda  call 0x1c2045b0
1c203edf  add esp, 0xc
1c203ee2  mov dword ptr [0x1c2552f4], 1
1c203eec  pop ebp
1c203eed  pop edi
1c203eee  pop esi
1c203eef  pop ebx
1c203ef0  ret 
1c203ef1  test ebx, ebx
1c203ef3  je 0x1c203f3e
1c203ef5  cmp word ptr [0x1c250e6a], 0
1c203efd  je 0x1c203f3e
1c203eff  test byte ptr [0x1c250e73], 2
1c203f06  je 0x1c203f18
1c203f08  mov eax, dword ptr [0x1c250e84]
1c203f0d  push eax
1c203f0e  push edi
1c203f0f  push esi
1c203f10  call 0x1c204550
1c203f15  add esp, 0xc
1c203f18  test ebp, ebp
1c203f1a  je 0x1c203f3e
1c203f1c  movsx eax, word ptr [0x1c250e6a]
1c203f23  add eax, dword ptr [0x1c250e84]
1c203f29  push eax
1c203f2a  push edi
1c203f2b  push esi
1c203f2c  call 0x1c2045b0
1c203f31  mov dword ptr [0x1c2552f4], 1
1c203f3b  add esp, 0xc
1c203f3e  pop ebp
1c203f3f  pop edi
1c203f40  pop esi
1c203f41  pop ebx
1c203f42  ret 
