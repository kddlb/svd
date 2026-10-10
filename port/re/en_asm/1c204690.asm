1c204690  sub esp, 0x48
1c204693  mov dword ptr [esp + 0x44], 0
1c20469b  push ebx
1c20469c  push esi
1c20469d  mov esi, dword ptr [esp + 0x54]
1c2046a1  push edi
1c2046a2  push ebp
1c2046a3  mov eax, dword ptr [esi + 0x28]
1c2046a6  cmp word ptr [eax + 0xc], 0xff
1c2046ac  jne 0x1c2046c2
1c2046ae  xor eax, eax
1c2046b0  pop ebp
1c2046b1  mov dword ptr [0x1c24c154], 1
1c2046bb  pop edi
1c2046bc  pop esi
1c2046bd  pop ebx
1c2046be  add esp, 0x48
1c2046c1  ret 
1c2046c2  mov eax, dword ptr [esi + 0xfa]
1c2046c8  xor ecx, ecx
1c2046ca  mov dword ptr [0x1c250e58], eax
1c2046cf  cmp dword ptr [0x1c24c154], ecx
1c2046d5  je 0x1c2049f6
1c2046db  mov dword ptr [0x1c250e90], 0x1c250690
1c2046e5  mov dword ptr [0x1c250e94], 0x1c2506d0
1c2046ef  mov dword ptr [0x1c250e98], 0x1c250750
1c2046f9  mov dword ptr [0x1c250e9c], 0x1c250790
1c204703  mov dword ptr [0x1c250ea0], 0x1c2505b0
1c20470d  mov dword ptr [0x1c250ea4], 0x1c250600
1c204717  mov dword ptr [0x1c250ea8], 0x1c250640
1c204721  mov dword ptr [0x1c250eac], 0x1c2508b0
1c20472b  mov dword ptr [0x1c250eb0], 0x1c250710
1c204735  mov dword ptr [0x1c250eb4], 0x1c2507d0
1c20473f  mov dword ptr [0x1c250eb8], 0x1c250820
1c204749  mov dword ptr [0x1c250ebc], 0x1c2508f0
1c204753  mov dword ptr [0x1c250ec0], 0x1c250930
1c20475d  mov dword ptr [0x1c250ec4], 0x1c250a10
1c204767  mov dword ptr [0x1c250ec8], 0x1c250870
1c204771  mov dword ptr [0x1c250ecc], 0x1c250970
1c20477b  mov dword ptr [0x1c250ed0], 0x1c2509c0
1c204785  mov eax, 0x1c250ef0
1c20478a  mov dword ptr [0x1c250574], eax
1c20478f  mov dword ptr [0x1c250694], eax
1c204794  mov eax, 0x1c2512f0
1c204799  mov dword ptr [0x1c25057c], eax
1c20479e  mov dword ptr [0x1c2506d4], eax
1c2047a3  mov eax, 0x1c2516f0
1c2047a8  mov dword ptr [0x1c250580], eax
1c2047ad  mov dword ptr [0x1c250754], eax
1c2047b2  mov eax, 0x1c251af0
1c2047b7  mov dword ptr [0x1c250588], eax
1c2047bc  mov dword ptr [0x1c250794], eax
1c2047c1  mov eax, 0x1c251ef0
1c2047c6  mov dword ptr [0x1c250568], eax
1c2047cb  mov dword ptr [0x1c2505b4], eax
1c2047d0  mov eax, 0x1c2522f0
1c2047d5  mov dword ptr [0x1c25056c], eax
1c2047da  mov dword ptr [0x1c250604], eax
1c2047df  mov eax, 0x1c2526f0
1c2047e4  mov dword ptr [0x1c250570], eax
1c2047e9  mov dword ptr [0x1c250644], eax
1c2047ee  mov eax, 0x1c252af0
1c2047f3  mov dword ptr [0x1c250598], eax
1c2047f8  mov dword ptr [0x1c2508b4], eax
1c2047fd  mov eax, 0x1c252ef0
1c204802  mov dword ptr [0x1c250578], eax
1c204807  mov dword ptr [0x1c250714], eax
1c20480c  mov eax, 0x1c2532f0
1c204811  mov dword ptr [0x1c250584], eax
1c204816  mov dword ptr [0x1c2507d4], eax
1c20481b  mov eax, 0x1c2536f0
1c204820  mov dword ptr [0x1c250590], eax
1c204825  mov dword ptr [0x1c250824], eax
1c20482a  mov eax, 0x1c253af0
1c20482f  mov dword ptr [0x1c25059c], eax
1c204834  mov dword ptr [0x1c2508f4], eax
1c204839  mov eax, 0x1c253ef0
1c20483e  mov dword ptr [0x1c2505a0], eax
1c204843  mov dword ptr [0x1c250934], eax
1c204848  mov eax, 0x1c2542f0
1c20484d  mov dword ptr [0x1c250864], eax
1c204852  mov dword ptr [0x1c250a14], eax
1c204857  mov eax, 0x1c2546f0
1c20485c  mov dword ptr [0x1c250594], eax
1c204861  mov dword ptr [0x1c250874], eax
1c204866  mov eax, 0x1c254af0
1c20486b  mov dword ptr [0x1c2505a4], eax
1c204870  mov dword ptr [0x1c250974], eax
1c204875  mov word ptr [0x1c250e50], cx
1c20487c  mov eax, 0x1c254ef0
1c204881  mov word ptr [0x1c250e6a], cx
1c204888  mov dword ptr [0x1c250680], eax
1c20488d  mov dword ptr [0x1c2509c4], eax
1c204892  mov dword ptr [0x1c250148], ecx
1c204898  mov eax, 0x6e
1c20489d  mov dword ptr [0x1c2552f4], ecx
1c2048a3  mov dword ptr [0x1c250e84], eax
1c2048a8  mov dword ptr [0x1c250e80], eax
1c2048ad  mov edx, 0x190
1c2048b2  mov dword ptr [0x1c250a00], eax
1c2048b7  mov eax, 0x64
1c2048bc  mov dword ptr [0x1c250ee0], ecx
1c2048c2  mov dword ptr [0x1c250698], eax
1c2048c7  mov dword ptr [0x1c250878], ecx
1c2048cd  mov dword ptr [0x1c2506d8], edx
1c2048d3  mov dword ptr [0x1c2505b8], eax
1c2048d8  mov dword ptr [0x1c250a18], 0xf
1c2048e2  mov dword ptr [0x1c250758], 0x578
1c2048ec  mov dword ptr [0x1c250608], eax
1c2048f1  mov dword ptr [0x1c250938], edx
1c2048f7  mov dword ptr [0x1c2508b8], ecx
1c2048fd  mov dword ptr [0x1c2507d8], ecx
1c204903  mov dword ptr [0x1c250718], ecx
1c204909  mov dword ptr [0x1c250828], ecx
1c20490f  mov dword ptr [0x1c250978], ecx
1c204915  mov dword ptr [0x1c2509c8], ecx
1c20491b  mov dword ptr [0x1c250798], 0x960
1c204925  mov dword ptr [0x1c250648], 0xc8
1c20492f  mov dword ptr [0x1c2508f8], 0xbb8
1c204939  movsx ebx, word ptr [esi + 0x98]
1c204940  movsx eax, word ptr [esi + 0x9c]
1c204947  mov dword ptr [esp + 0x3c], ebx
1c20494b  mov dword ptr [esp + 0x40], eax
1c20494f  movsx edx, word ptr [esi + 0x9a]
1c204956  mov ax, word ptr [esi + 0x46]
1c20495a  mov dword ptr [esp + 0x44], edx
1c20495e  movsx ebx, word ptr [esi + 0x9e]
1c204965  mov edx, dword ptr [0x1c250e58]
1c20496b  mov dword ptr [esp + 0x48], ebx
1c20496f  mov word ptr [edx + 0x18], ax
1c204973  mov edx, dword ptr [0x1c250e58]
1c204979  mov ax, word ptr [edx + 0x18]
1c20497d  mov di, ax
1c204980  mov word ptr [0x1c250560], ax
1c204986  xor eax, eax
1c204988  mov edx, dword ptr [esi + 0x28]
1c20498b  mov ax, word ptr [edx + 0xe]
1c20498f  add eax, 4
1c204992  cdq 
1c204993  and edx, 7
1c204996  add eax, edx
1c204998  mov edx, dword ptr [0x1c250e58]
1c20499e  sar eax, 3
1c2049a1  shl eax, 5
1c2049a4  mov word ptr [eax + edx + 0x18], di
1c2049a9  movzx eax, cx
1c2049ac  inc cx
1c2049ae  mov edi, dword ptr [eax*4 + 0x1c250e90]
1c2049b5  cmp cx, 0x11
1c2049b9  lea edx, [eax*4]
1c2049c0  mov eax, dword ptr [edi + 8]
1c2049c3  mov dword ptr [edi + 0x14], eax
1c2049c6  mov dword ptr [edi + 0x10], eax
1c2049c9  mov dword ptr [edi + 0xc], eax
1c2049cc  mov eax, dword ptr [edi + 8]
1c2049cf  mov dword ptr [edi + 0x24], eax
1c2049d2  mov dword ptr [edi + 0x20], eax
1c2049d5  mov dword ptr [edi + 0x1c], eax
1c2049d8  mov dword ptr [edi + 0x18], eax
1c2049db  mov edx, dword ptr [edx + 0x1c24c158]
1c2049e1  mov dword ptr [edi], edx
1c2049e3  jb 0x1c2049a9
1c2049e5  mov byte ptr [0x1c250e69], 1
1c2049ec  mov dword ptr [0x1c24c154], 0
1c2049f6  mov ecx, dword ptr [esi + 0x20]
1c2049f9  mov al, byte ptr [ecx + 0xc]
1c2049fc  mov byte ptr [0x1c255301], al
1c204a01  mov edx, dword ptr [ecx + 0x12]
1c204a04  mov dword ptr [0x1c250ed8], edx
1c204a0a  mov eax, dword ptr [ecx + 0x16]
1c204a0d  and al, 0x10
1c204a0f  mov byte ptr [0x1c250edc], al
1c204a14  mov dl, byte ptr [ecx + 0x10]
1c204a17  mov byte ptr [0x1c250550], dl
1c204a1d  mov eax, dword ptr [ecx + 0x16]
1c204a20  mov dword ptr [0x1c2552f8], eax
1c204a25  xor eax, eax
1c204a27  mov ax, word ptr [ecx + 0xe]
1c204a2b  push ecx
1c204a2c  add eax, 4
1c204a2f  cdq 
1c204a30  and edx, 7
1c204a33  add eax, edx
1c204a35  sar eax, 3
1c204a38  mov word ptr [0x1c2509b2], ax
1c204a3e  call 0x1c203010
1c204a43  mov word ptr [0x1c2509b0], ax
1c204a49  add esp, 4
1c204a4c  mov ecx, dword ptr [esi + 0x24]
1c204a4f  mov dl, byte ptr [ecx + 0xc]
1c204a52  mov byte ptr [0x1c255303], dl
1c204a58  mov eax, dword ptr [ecx + 0x12]
1c204a5b  mov dword ptr [0x1c250e64], eax
1c204a60  mov eax, dword ptr [ecx + 0x16]
1c204a63  and al, 0x10
1c204a65  mov byte ptr [0x1c250e68], al
1c204a6a  mov dl, byte ptr [ecx + 0x10]
1c204a6d  mov byte ptr [0x1c255302], dl
1c204a73  mov eax, dword ptr [ecx + 0x16]
1c204a76  mov dword ptr [0x1c2552f0], eax
1c204a7b  xor eax, eax
1c204a7d  mov ax, word ptr [ecx + 0xe]
1c204a81  push ecx
1c204a82  add eax, 4
1c204a85  cdq 
1c204a86  and edx, 7
1c204a89  add eax, edx
1c204a8b  sar eax, 3
1c204a8e  mov word ptr [0x1c250558], ax
1c204a94  call 0x1c203010
1c204a99  mov word ptr [0x1c2505f0], ax
1c204a9f  add esp, 4
1c204aa2  mov edx, dword ptr [esi + 0x28]
1c204aa5  mov dword ptr [esp + 0x20], edx
1c204aa9  mov al, byte ptr [edx + 0xc]
1c204aac  mov byte ptr [0x1c250e7e], al
1c204ab1  mov ecx, dword ptr [edx + 0x12]
1c204ab4  mov dword ptr [0x1c250e70], ecx
1c204aba  mov eax, dword ptr [edx + 0x16]
1c204abd  and al, 0x10
1c204abf  mov byte ptr [0x1c250e74], al
1c204ac4  mov cl, byte ptr [edx + 0x10]
1c204ac7  mov byte ptr [0x1c250ed4], cl
1c204acd  mov eax, dword ptr [edx + 0x16]
1c204ad0  mov dword ptr [0x1c250e78], eax
1c204ad5  xor eax, eax
1c204ad7  mov ax, word ptr [edx + 0xe]
1c204adb  add eax, 4
1c204ade  cdq 
1c204adf  and edx, 7
1c204ae2  add eax, edx
1c204ae4  mov edx, dword ptr [esp + 0x20]
1c204ae8  sar eax, 3
1c204aeb  push edx
1c204aec  mov word ptr [0x1c250566], ax
1c204af2  call 0x1c203010
1c204af7  mov word ptr [0x1c250564], ax
1c204afd  add esp, 4
1c204b00  mov ecx, dword ptr [esi + 0x2c]
1c204b03  mov dl, byte ptr [ecx + 0xc]
1c204b06  mov byte ptr [0x1c250810], dl
1c204b0c  cmp dl, 0xff
1c204b0f  jne 0x1c204b18
1c204b11  mov byte ptr [0x1c250810], 0x1b
1c204b18  mov eax, dword ptr [ecx + 0x12]
1c204b1b  mov dword ptr [0x1c2552fc], eax
1c204b20  mov eax, dword ptr [ecx + 0x16]
1c204b23  and al, 0x10
1c204b25  mov byte ptr [0x1c255300], al
1c204b2a  mov dl, byte ptr [ecx + 0x10]
1c204b2d  mov byte ptr [0x1c25055e], dl
1c204b33  mov eax, dword ptr [ecx + 0x16]
1c204b36  mov dword ptr [0x1c250554], eax
1c204b3b  xor eax, eax
1c204b3d  mov ax, word ptr [ecx + 0xe]
1c204b41  push ecx
1c204b42  add eax, 4
1c204b45  cdq 
1c204b46  and edx, 7
1c204b49  add eax, edx
1c204b4b  sar eax, 3
1c204b4e  mov word ptr [0x1c250e60], ax
1c204b54  call 0x1c203010
1c204b59  mov word ptr [0x1c250e7c], ax
1c204b5f  add esp, 4
1c204b62  mov edx, dword ptr [esi + 0x30]
1c204b65  mov dword ptr [esp + 0x2c], edx
1c204b69  mov al, byte ptr [edx + 0xc]
1c204b6c  mov byte ptr [0x1c2509b4], al
1c204b71  cmp al, 0xff
1c204b73  jne 0x1c204b7c
1c204b75  mov byte ptr [0x1c2509b4], 0x1b
1c204b7c  mov edx, dword ptr [esp + 0x2c]
1c204b80  mov eax, dword ptr [edx + 0x12]
1c204b83  mov dword ptr [0x1c250e5c], eax
1c204b88  mov eax, dword ptr [edx + 0x16]
1c204b8b  and al, 0x10
1c204b8d  mov byte ptr [0x1c250e62], al
1c204b92  mov cl, byte ptr [edx + 0x10]
1c204b95  mov byte ptr [0x1c250e6c], cl
1c204b9b  mov eax, dword ptr [edx + 0x16]
1c204b9e  mov dword ptr [0x1c250e54], eax
1c204ba3  xor eax, eax
1c204ba5  mov ax, word ptr [edx + 0xe]
1c204ba9  add eax, 4
1c204bac  cdq 
1c204bad  and edx, 7
1c204bb0  add eax, edx
1c204bb2  mov edx, dword ptr [esp + 0x2c]
1c204bb6  sar eax, 3
1c204bb9  push edx
1c204bba  xor bp, bp
1c204bbd  mov word ptr [0x1c250146], ax
1c204bc3  call 0x1c203010
1c204bc8  mov word ptr [0x1c250860], ax
1c204bce  add esp, 4
1c204bd1  mov cl, byte ptr [0x1c250e69]
1c204bd7  mov edx, 0x32
1c204bdc  mov edi, 0x19
1c204be1  mov ebx, 0x4b
1c204be6  mov byte ptr [0x1c250e63], cl
1c204bec  mov ecx, 7
1c204bf1  movzx eax, bp
1c204bf4  inc bp
1c204bf6  mov eax, dword ptr [eax*4 + 0x1c250e90]
1c204bfd  cmp bp, 0x11
1c204c01  mov dword ptr [eax + 0x28], edx
1c204c04  mov dword ptr [eax + 0x38], edi
1c204c07  mov dword ptr [eax + 0x3c], ebx
1c204c0a  mov dword ptr [eax + 0x2c], ecx
1c204c0d  mov dword ptr [eax + 0x30], ecx
1c204c10  mov dword ptr [eax + 0x34], 3
1c204c17  jb 0x1c204bf1
1c204c19  mov ax, word ptr [0x1c25058c]
1c204c1f  mov edx, dword ptr [esp + 0x20]
1c204c23  mov word ptr [0x1c250e88], ax
1c204c29  push edx
1c204c2a  call 0x1c201b80
1c204c2f  add esp, 4
1c204c32  push esi
1c204c33  call 0x1c2030b0
1c204c38  mov edx, dword ptr [esp + 0x24]
1c204c3c  add esp, 4
1c204c3f  push edx
1c204c40  call 0x1c249310
1c204c45  mov ax, word ptr [esi + 0x5e]
1c204c49  add esp, 4
1c204c4c  add ax, 3
1c204c50  movsx eax, ax
1c204c53  mov dword ptr [0x1c2507c4], eax
1c204c58  mov dword ptr [0x1c250784], eax
1c204c5d  mov dword ptr [0x1c250704], eax
1c204c62  mov dword ptr [0x1c250674], eax
1c204c67  mov dword ptr [0x1c250634], eax
1c204c6c  mov dword ptr [0x1c2505e4], eax
1c204c71  mov dword ptr [0x1c250964], eax
1c204c76  mov dword ptr [0x1c250924], eax
1c204c7b  movsx eax, word ptr [esi + 0x7e]
1c204c7f  add eax, 3
1c204c82  mov dword ptr [0x1c2508e4], eax
1c204c87  movsx eax, word ptr [esi + 0x80]
1c204c8e  xor di, di
1c204c91  add eax, 3
1c204c94  mov dword ptr [0x1c250804], eax
1c204c99  movsx eax, word ptr [esi + 0x82]
1c204ca0  add eax, 3
1c204ca3  mov dword ptr [0x1c250854], eax
1c204ca8  mov dword ptr [0x1c250744], eax
1c204cad  movzx eax, di
1c204cb0  inc di
1c204cb2  mov ecx, dword ptr [eax*4 + 0x1c250e90]
1c204cb9  push ecx
1c204cba  call 0x1c203870
1c204cbf  add esp, 4
1c204cc2  cmp di, 0x11
1c204cc6  jb 0x1c204cad
1c204cc8  xor dx, dx
1c204ccb  mov edi, dword ptr [0x1c2508b4]
1c204cd1  cmp word ptr [0x1c250566], dx
1c204cd8  mov ecx, dword ptr [0x1c2507d4]
1c204cde  mov ebx, dword ptr [0x1c250714]
1c204ce4  jbe 0x1c204d4a
1c204ce6  mov ax, word ptr [edi]
1c204ce9  test ax, ax
1c204cec  jg 0x1c204cf1
1c204cee  xor ax, ax
1c204cf1  movsx ebp, ax
1c204cf4  movzx ax, byte ptr [ebp + 0x1c20660e]
1c204cfc  mov word ptr [edi], ax
1c204cff  mov ax, word ptr [ecx]
1c204d02  test ax, ax
1c204d05  jg 0x1c204d0a
1c204d07  xor ax, ax
1c204d0a  movsx ebp, ax
1c204d0d  movzx ax, byte ptr [ebp + 0x1c20660e]
1c204d15  sub ax, 0xa
1c204d19  mov word ptr [ecx], ax
1c204d1c  mov ax, word ptr [ebx]
1c204d1f  test ax, ax
1c204d22  jg 0x1c204d27
1c204d24  xor ax, ax
1c204d27  inc dx
1c204d29  add edi, 2
1c204d2c  movsx ebp, ax
1c204d2f  add ecx, 2
1c204d32  add ebx, 2
1c204d35  movzx ax, byte ptr [ebp + 0x1c20660e]
1c204d3d  mov word ptr [ebx - 2], ax
1c204d41  cmp word ptr [0x1c250566], dx
1c204d48  ja 0x1c204ce6
1c204d4a  call 0x1c203a30
1c204d4f  test byte ptr [0x1c250e72], 4
1c204d56  je 0x1c204e13
1c204d5c  mov eax, 0x8000000
1c204d61  test dword ptr [0x1c250e70], eax
1c204d67  je 0x1c204e13
1c204d6d  test dword ptr [0x1c250e64], eax
1c204d73  je 0x1c204d91
1c204d75  test byte ptr [0x1c250e66], 0x80
1c204d7c  je 0x1c204d91
1c204d7e  cmp word ptr [esi + 0x2f2], 2
1c204d86  je 0x1c204d91
1c204d88  mov word ptr [esp + 0x1c], 5
1c204d8f  jmp 0x1c204d98
1c204d91  mov word ptr [esp + 0x1c], 0x3c
1c204d98  mov ebx, dword ptr [0x1c2508b4]
1c204d9e  mov ebp, dword ptr [0x1c2507d4]
1c204da4  mov eax, dword ptr [0x1c2506d4]
1c204da9  mov ecx, dword ptr [0x1c2505b4]
1c204daf  mov word ptr [esp + 0x16], 0
1c204db6  cmp word ptr [0x1c250566], 0
1c204dbe  mov edx, dword ptr [0x1c250604]
1c204dc4  jbe 0x1c204e13
1c204dc6  mov di, word ptr [esp + 0x1c]
1c204dcb  add ebx, 2
1c204dce  sub word ptr [ebx - 2], di
1c204dd2  add ebp, 2
1c204dd5  mov word ptr [ebp - 2], 0
1c204ddb  cmp word ptr [esi + 0x52], 1
1c204de0  jne 0x1c204de9
1c204de2  mov word ptr [eax], 0xfa
1c204de7  jmp 0x1c204dee
1c204de9  mov word ptr [eax], 0x78
1c204dee  add word ptr [ecx], 0x28
1c204df2  add eax, 2
1c204df5  add word ptr [edx], 0xfa
1c204dfa  add ecx, 2
1c204dfd  inc word ptr [esp + 0x16]
1c204e02  add edx, 2
1c204e05  mov di, word ptr [esp + 0x16]
1c204e0a  cmp word ptr [0x1c250566], di
1c204e11  ja 0x1c204dc6
1c204e13  test byte ptr [0x1c250e71], 0x80
1c204e1a  je 0x1c204e2e
1c204e1c  mov dword ptr [esp + 0x4c], 1
1c204e24  mov dword ptr [esp + 0x34], 0x10
1c204e2c  jmp 0x1c204e38
1c204e2e  xor eax, eax
1c204e30  mov dword ptr [esp + 0x4c], eax
1c204e34  mov dword ptr [esp + 0x34], eax
1c204e38  mov eax, dword ptr [0x1c250694]
1c204e3d  mov ecx, dword ptr [0x1c2506d4]
1c204e43  mov edx, dword ptr [0x1c250754]
1c204e49  mov dword ptr [0x1c250574], eax
1c204e4e  mov eax, dword ptr [0x1c250794]
1c204e53  mov dword ptr [0x1c25057c], ecx
1c204e59  mov ecx, dword ptr [0x1c2505b4]
1c204e5f  mov dword ptr [0x1c250580], edx
1c204e65  mov edx, dword ptr [0x1c250604]
1c204e6b  mov dword ptr [0x1c250588], eax
1c204e70  mov eax, dword ptr [0x1c250644]
1c204e75  mov dword ptr [0x1c250568], ecx
1c204e7b  mov ecx, dword ptr [0x1c2508f4]
1c204e81  mov dword ptr [0x1c25056c], edx
1c204e87  mov edx, dword ptr [0x1c250934]
1c204e8d  mov dword ptr [0x1c250570], eax
1c204e92  mov eax, dword ptr [0x1c2508b4]
1c204e97  mov dword ptr [0x1c25059c], ecx
1c204e9d  mov ecx, dword ptr [0x1c2507d4]
1c204ea3  mov dword ptr [0x1c2505a0], edx
1c204ea9  mov edx, dword ptr [0x1c250714]
1c204eaf  mov dword ptr [0x1c250598], eax
1c204eb4  mov eax, dword ptr [0x1c250824]
1c204eb9  mov dword ptr [0x1c250584], ecx
1c204ebf  mov ecx, dword ptr [0x1c250874]
1c204ec5  mov dword ptr [0x1c250578], edx
1c204ecb  mov edx, dword ptr [0x1c250a14]
1c204ed1  mov dword ptr [0x1c250590], eax
1c204ed6  mov eax, dword ptr [0x1c2509c4]
1c204edb  mov dword ptr [0x1c250594], ecx
1c204ee1  mov ecx, dword ptr [0x1c250974]
1c204ee7  mov dword ptr [0x1c250864], edx
1c204eed  mov dword ptr [0x1c250680], eax
1c204ef2  mov dword ptr [0x1c2505a4], ecx
1c204ef8  mov word ptr [esp + 0x16], 0
1c204eff  cmp word ptr [0x1c250566], 0
1c204f07  jbe 0x1c205e64
1c204f0d  mov ecx, dword ptr [esp + 0x1c]
1c204f11  mov ebx, dword ptr [esp + 0x1c]
1c204f15  mov edi, dword ptr [esp + 0x1c]
1c204f19  mov edx, dword ptr [esp + 0x20]
1c204f1d  mov edx, dword ptr [edx]
1c204f1f  test edx, edx
1c204f21  je 0x1c2052f7
1c204f27  cmp word ptr [edx], 0x1e
1c204f2b  je 0x1c2052f7
1c204f31  mov eax, dword ptr [esp + 0x16]
1c204f35  and eax, 0xffff
1c204f3a  mov dword ptr [esp + 0x1c], eax
1c204f3e  movsx eax, word ptr [edx + 4]
1c204f42  cmp eax, dword ptr [esp + 0x1c]
1c204f46  jne 0x1c2052ea
1c204f4c  movsx eax, word ptr [edx]
1c204f4f  cmp eax, 0xbe
1c204f54  jg 0x1c204f6a
1c204f56  je 0x1c2051c8
1c204f5c  cmp eax, 0x32
1c204f5f  je 0x1c20508a
1c204f65  jmp 0x1c2052ea
1c204f6a  cmp eax, 0xdc
1c204f6f  jg 0x1c204f87
1c204f71  je 0x1c2051e2
1c204f77  cmp eax, 0xc8
1c204f7c  je 0x1c2051d5
1c204f82  jmp 0x1c2052ea
1c204f87  cmp eax, 0xf0
1c204f8c  jg 0x1c204fa4
1c204f8e  je 0x1c205202
1c204f94  cmp eax, 0xe6
1c204f99  je 0x1c2051f2
1c204f9f  jmp 0x1c2052ea
1c204fa4  cmp eax, 0x14a
1c204fa9  jg 0x1c204fc1
1c204fab  je 0x1c20521c
1c204fb1  cmp eax, 0x140
1c204fb6  je 0x1c20520f
1c204fbc  jmp 0x1c2052ea
1c204fc1  cmp eax, 0x15e
1c204fc6  jg 0x1c204fde
1c204fc8  je 0x1c205236
1c204fce  cmp eax, 0x154
1c204fd3  je 0x1c205229
1c204fd9  jmp 0x1c2052ea
1c204fde  cmp eax, 0x172
1c204fe3  jg 0x1c204ffb
1c204fe5  je 0x1c205256
1c204feb  cmp eax, 0x168
1c204ff0  je 0x1c205246
1c204ff6  jmp 0x1c2052ea
1c204ffb  cmp eax, 0x186
1c205000  jg 0x1c205018
1c205002  je 0x1c205273
1c205008  cmp eax, 0x17c
1c20500d  je 0x1c205266
1c205013  jmp 0x1c2052ea
1c205018  cmp eax, 0x1fe
1c20501d  jg 0x1c205035
1c20501f  je 0x1c20528d
1c205025  cmp eax, 0x1f4
1c20502a  je 0x1c205280
1c205030  jmp 0x1c2052ea
1c205035  cmp eax, 0x226
1c20503a  jg 0x1c205052
1c20503c  je 0x1c2052a7
1c205042  cmp eax, 0x208
1c205047  je 0x1c20529a
1c20504d  jmp 0x1c2052ea
1c205052  cmp eax, 0x23a
1c205057  jg 0x1c20506f
1c205059  je 0x1c2052c1
1c20505f  cmp eax, 0x230
1c205064  je 0x1c2052b4
1c20506a  jmp 0x1c2052ea
1c20506f  cmp eax, 0x334
1c205074  je 0x1c2052ce
1c20507a  cmp eax, 0x352
1c20507f  je 0x1c2052de
1c205085  jmp 0x1c2052ea
1c20508a  movsx ebp, word ptr [edx + 2]
1c20508e  mov eax, ebp
1c205090  lea ebp, [ebp + ebp*8]
1c205094  cmp word ptr [esi + 0x4c], 3
1c205099  lea ebp, [eax + ebp*4]
1c20509c  lea eax, [ebp*2 + 0x1c24b318]
1c2050a3  je 0x1c2050b5
1c2050a5  mov bp, word ptr [eax + 0x12]
1c2050a9  mov word ptr [esi + 0x4c], bp
1c2050ad  mov bp, word ptr [eax + 8]
1c2050b1  mov word ptr [esi + 0x44], bp
1c2050b5  mov bp, word ptr [eax + 0xa]
1c2050b9  mov word ptr [esi + 0x52], bp
1c2050bd  mov bp, word ptr [eax + 0xe]
1c2050c1  mov word ptr [esi + 0x2f2], bp
1c2050c8  mov bp, word ptr [eax + 4]
1c2050cc  mov word ptr [esi + 0x46], bp
1c2050d0  mov bp, word ptr [eax + 6]
1c2050d4  mov word ptr [esi + 0xac], bp
1c2050db  mov bp, word ptr [eax + 0x14]
1c2050df  mov word ptr [esi + 0x60], bp
1c2050e3  mov bp, word ptr [eax + 0x16]
1c2050e7  mov word ptr [esi + 0x62], bp
1c2050eb  mov bp, word ptr [eax + 0x1a]
1c2050ef  mov word ptr [esi + 0x64], bp
1c2050f3  mov bp, word ptr [eax + 0x1c]
1c2050f7  mov word ptr [esi + 0x66], bp
1c2050fb  mov bp, word ptr [eax + 0x10]
1c2050ff  mov word ptr [esi + 0x8a], bp
1c205106  mov bp, word ptr [eax + 0x42]
1c20510a  mov word ptr [esi + 0x98], bp
1c205111  mov bp, word ptr [eax + 0x44]
1c205115  mov word ptr [esi + 0x9a], bp
1c20511c  mov bp, word ptr [eax + 0x46]
1c205120  mov word ptr [esi + 0x9c], bp
1c205127  mov bp, word ptr [eax + 0x48]
1c20512b  mov word ptr [esi + 0x9e], bp
1c205132  mov bp, word ptr [eax + 0x36]
1c205136  mov word ptr [esi + 0x92], bp
1c20513d  mov bp, word ptr [eax + 0x38]
1c205141  mov word ptr [esi + 0x94], bp
1c205148  mov bp, word ptr [eax + 0x3a]
1c20514c  mov word ptr [esi + 0x96], bp
1c205153  mov bp, word ptr [eax + 0x3c]
1c205157  mov word ptr [esi + 0x8c], bp
1c20515e  mov bp, word ptr [eax + 0x3e]
1c205162  mov word ptr [esi + 0x8e], bp
1c205169  mov bp, word ptr [eax + 0x40]
1c20516d  mov word ptr [esi + 0x90], bp
1c205174  mov bp, word ptr [eax + 0x30]
1c205178  mov word ptr [esi + 0x84], bp
1c20517f  mov bp, word ptr [eax + 0x32]
1c205183  mov word ptr [esi + 0x86], bp
1c20518a  mov bp, word ptr [eax + 0x34]
1c20518e  mov word ptr [esi + 0x88], bp
1c205195  mov bp, word ptr [eax + 0x2a]
1c205199  mov word ptr [esi + 0x7e], bp
1c20519d  mov bp, word ptr [eax + 0x2c]
1c2051a1  mov word ptr [esi + 0x80], bp
1c2051a8  mov bp, word ptr [eax + 0x2e]
1c2051ac  mov word ptr [esi + 0x82], bp
1c2051b3  mov bp, word ptr [eax + 0x26]
1c2051b7  mov word ptr [esi + 0x5c], bp
1c2051bb  mov ax, word ptr [eax + 0x28]
1c2051bf  mov word ptr [esi + 0x5e], ax
1c2051c3  jmp 0x1c2052ea
1c2051c8  mov ax, word ptr [edx + 2]
1c2051cc  mov word ptr [esi + 0x44], ax
1c2051d0  jmp 0x1c2052ea
1c2051d5  mov ax, word ptr [edx + 2]
1c2051d9  mov word ptr [esi + 0x52], ax
1c2051dd  jmp 0x1c2052ea
1c2051e2  mov ax, word ptr [edx + 2]
1c2051e6  mov word ptr [esi + 0x2f2], ax
1c2051ed  jmp 0x1c2052ea
1c2051f2  mov ax, word ptr [edx + 2]
1c2051f6  mov word ptr [esi + 0x8a], ax
1c2051fd  jmp 0x1c2052ea
1c205202  mov ax, word ptr [edx + 2]
1c205206  mov word ptr [esi + 0x4c], ax
1c20520a  jmp 0x1c2052ea
1c20520f  mov ax, word ptr [edx + 2]
1c205213  mov word ptr [esi + 0x5c], ax
1c205217  jmp 0x1c2052ea
1c20521c  mov ax, word ptr [edx + 2]
1c205220  mov word ptr [esi + 0x5e], ax
1c205224  jmp 0x1c2052ea
1c205229  mov ax, word ptr [edx + 2]
1c20522d  mov word ptr [esi + 0x7e], ax
1c205231  jmp 0x1c2052ea
1c205236  mov ax, word ptr [edx + 2]
1c20523a  mov word ptr [esi + 0x80], ax
1c205241  jmp 0x1c2052ea
1c205246  mov ax, word ptr [edx + 2]
1c20524a  mov word ptr [esi + 0x82], ax
1c205251  jmp 0x1c2052ea
1c205256  mov ax, word ptr [edx + 2]
1c20525a  mov word ptr [esi + 0x84], ax
1c205261  jmp 0x1c2052ea
1c205266  mov ax, word ptr [edx + 2]
1c20526a  mov word ptr [esi + 0x86], ax
1c205271  jmp 0x1c2052ea
1c205273  mov ax, word ptr [edx + 2]
1c205277  mov word ptr [esi + 0x88], ax
1c20527e  jmp 0x1c2052ea
1c205280  mov ax, word ptr [edx + 2]
1c205284  mov word ptr [esi + 0x92], ax
1c20528b  jmp 0x1c2052ea
1c20528d  mov ax, word ptr [edx + 2]
1c205291  mov word ptr [esi + 0x94], ax
1c205298  jmp 0x1c2052ea
1c20529a  mov ax, word ptr [edx + 2]
1c20529e  mov word ptr [esi + 0x96], ax
1c2052a5  jmp 0x1c2052ea
1c2052a7  mov ax, word ptr [edx + 2]
1c2052ab  mov word ptr [esi + 0x8c], ax
1c2052b2  jmp 0x1c2052ea
1c2052b4  mov ax, word ptr [edx + 2]
1c2052b8  mov word ptr [esi + 0x8e], ax
1c2052bf  jmp 0x1c2052ea
1c2052c1  mov ax, word ptr [edx + 2]
1c2052c5  mov word ptr [esi + 0x90], ax
1c2052cc  jmp 0x1c2052ea
1c2052ce  mov bp, word ptr [edx + 2]
1c2052d2  or dword ptr [esp + 0x34], 0x20
1c2052d7  mov word ptr [esp + 0x12], bp
1c2052dc  jmp 0x1c2052ea
1c2052de  or dword ptr [esp + 0x34], 8
1c2052e3  mov al, byte ptr [edx + 2]
1c2052e6  mov byte ptr [esp + 0x11], al
1c2052ea  add edx, 6
1c2052ed  cmp word ptr [edx], 0x1e
1c2052f1  jne 0x1c204f3e
1c2052f7  mov eax, dword ptr [0x1c250864]
1c2052fc  mov ax, word ptr [eax]
1c2052ff  sar ax, 8
1c205303  cmp dword ptr [esp + 0x4c], 0
1c205308  mov word ptr [esp + 0x14], ax
1c20530d  je 0x1c20539b
1c205313  xor eax, eax
1c205315  mov al, byte ptr [0x1c250e7e]
1c20531a  sub eax, 0x3c
1c20531d  cmp eax, 0x1c
1c205320  ja 0x1c2053db
1c205326  xor edx, edx
1c205328  mov dl, byte ptr [eax + 0x1c205fd4]
1c20532e  jmp dword ptr [edx*4 + 0x1c205fbc]
1c205335  mov ecx, 0x4a1
1c20533a  mov ebx, 0x898
1c20533f  mov dword ptr [esp + 0x18], 0x14a
1c205347  mov dword ptr [esp + 0x24], 0x3c
1c20534f  mov edi, 0x1f4
1c205354  jmp 0x1c2053db
1c205359  mov ecx, 0x640
1c20535e  mov ebx, 0x8fc
1c205363  mov dword ptr [esp + 0x18], 0x109
1c20536b  mov dword ptr [esp + 0x24], 0x3c
1c205373  mov edi, 0x1f4
1c205378  jmp 0x1c2053db
1c20537a  mov ecx, 0x6d6
1c20537f  mov ebx, 0x8ca
1c205384  mov dword ptr [esp + 0x18], 0xfa
1c20538c  mov dword ptr [esp + 0x24], 0x3c
1c205394  mov edi, 0x1f4
1c205399  jmp 0x1c2053db
1c20539b  mov eax, dword ptr [0x1c25057c]
1c2053a0  mov ebx, dword ptr [0x1c250580]
1c2053a6  movsx edx, word ptr [eax]
1c2053a9  mov eax, dword ptr [0x1c250588]
1c2053ae  mov dword ptr [esp + 0x18], edx
1c2053b2  mov edx, dword ptr [0x1c250568]
1c2053b8  mov ebp, dword ptr [0x1c250570]
1c2053be  movsx ecx, word ptr [ebx]
1c2053c1  movsx ebx, word ptr [eax]
1c2053c4  mov eax, dword ptr [0x1c25056c]
1c2053c9  movsx edi, word ptr [edx]
1c2053cc  movsx edx, word ptr [eax]
1c2053cf  movsx eax, word ptr [ebp]
1c2053d3  mov dword ptr [esp + 0x28], edx
1c2053d7  mov dword ptr [esp + 0x24], eax
1c2053db  mov ax, word ptr [esi + 0x2f2]
1c2053e2  cmp ax, 1
1c2053e6  jne 0x1c205431
1c2053e8  cmp word ptr [esi + 0x52], 0
1c2053ed  jne 0x1c2053f2
1c2053ef  add edi, 0x3c
1c2053f2  mov eax, dword ptr [0x1c250598]
1c2053f7  movsx edx, word ptr [eax]
1c2053fa  sub edx, 7
1c2053fd  mov eax, dword ptr [0x1c250584]
1c205402  movsx eax, word ptr [eax]
1c205405  cmp edx, eax
1c205407  jg 0x1c20540b
1c205409  mov edx, eax
1c20540b  mov eax, dword ptr [0x1c250584]
1c205410  mov word ptr [eax], dx
1c205413  mov edx, dword ptr [0x1c250598]
1c205419  mov ax, word ptr [edx]
1c20541c  cmp ax, 0x14
1c205420  jle 0x1c205429
1c205422  add ax, 4
1c205426  mov word ptr [edx], ax
1c205429  sub word ptr [esp + 0x14], 4
1c20542f  jmp 0x1c20549e
1c205431  cmp ax, 2
1c205435  jne 0x1c20546a
1c205437  mov eax, dword ptr [0x1c250598]
1c20543c  movsx edx, word ptr [eax]
1c20543f  sub edx, 3
1c205442  mov eax, dword ptr [0x1c250584]
1c205447  movsx eax, word ptr [eax]
1c20544a  cmp edx, eax
1c20544c  jg 0x1c205450
1c20544e  mov edx, eax
1c205450  mov eax, dword ptr [0x1c250584]
1c205455  mov edi, 0xc8
1c20545a  mov word ptr [eax], dx
1c20545d  mov edx, dword ptr [0x1c250598]
1c205463  mov word ptr [edx], 0
1c205468  jmp 0x1c20549e
1c20546a  cmp dword ptr [esp + 0x4c], 0
1c20546f  je 0x1c20547d
1c205471  mov eax, dword ptr [0x1c250584]
1c205476  mov word ptr [eax], 0
1c20547b  jmp 0x1c20549e
1c20547d  mov eax, dword ptr [0x1c250598]
1c205482  movsx edx, word ptr [eax]
1c205485  sub edx, 0x14
1c205488  mov eax, dword ptr [0x1c250584]
1c20548d  movsx eax, word ptr [eax]
1c205490  cmp edx, eax
1c205492  jg 0x1c205496
1c205494  mov edx, eax
1c205496  mov eax, dword ptr [0x1c250584]
1c20549b  mov word ptr [eax], dx
1c20549e  test byte ptr [0x1c250e71], 0x80
1c2054a5  je 0x1c2054b0
1c2054a7  mov eax, dword ptr [0x1c250584]
1c2054ac  sub word ptr [eax], 7
1c2054b0  movsx ebp, word ptr [esi + 0x5c]
1c2054b4  mov ax, word ptr [esi + 0x52]
1c2054b8  add ebp, 0xa
1c2054bb  cmp ax, 1
1c2054bf  jne 0x1c2054f4
1c2054c1  mov eax, dword ptr [0x1c250598]
1c2054c6  sub word ptr [esp + 0x14], 5
1c2054cc  sub word ptr [eax], 0xa
1c2054d0  mov edx, dword ptr [0x1c250584]
1c2054d6  sub word ptr [edx], 0x14
1c2054da  mov ebp, dword ptr [0x1c250578]
1c2054e0  sub word ptr [ebp], 6
1c2054e5  mov eax, dword ptr [0x1c25059c]
1c2054ea  add word ptr [eax], 0x96
1c2054ef  jmp 0x1c205783
1c2054f4  cmp ax, 2
1c2054f8  jne 0x1c2055d7
1c2054fe  dec word ptr [esp + 0x14]
1c205503  mov eax, dword ptr [0x1c250598]
1c205508  sub word ptr [eax], 0xd
1c20550c  mov dword ptr [esp + 0x50], ecx
1c205510  mov edx, dword ptr [0x1c250584]
1c205516  add ebx, 0x429
1c20551c  sub word ptr [edx], 0x16
1c205520  mov edx, dword ptr [esp + 0x18]
1c205524  mov eax, dword ptr [0x1c250578]
1c205529  mov dword ptr [esp + 0x30], edx
1c20552d  sub word ptr [eax], 7
1c205531  sub edx, 0x1c2
1c205537  imul edx, ebp
1c20553a  mov dword ptr [esp + 0x1c], 0x3e8
1c205542  mov eax, edx
1c205544  add edx, edx
1c205546  sub ecx, 0x5aa
1c20554c  lea edx, [edx + edx*8]
1c20554f  imul ecx, ebp
1c205552  lea eax, [eax + edx*8]
1c205555  cdq 
1c205556  idiv dword ptr [esp + 0x1c]
1c20555a  add eax, 0x2e4
1c20555f  mov ebp, 0x3e8
1c205564  mov dword ptr [esp + 0x18], eax
1c205568  mov eax, ecx
1c20556a  add ecx, ecx
1c20556c  lea edx, [ecx + ecx*8]
1c20556f  lea eax, [eax + edx*8]
1c205572  cdq 
1c205573  idiv ebp
1c205575  lea ecx, [eax + 0x834]
1c20557b  mov eax, ebx
1c20557d  sub eax, ecx
1c20557f  cmp eax, 0x15e
1c205584  jge 0x1c20558c
1c205586  lea ebx, [ecx + 0x15e]
1c20558c  mov eax, dword ptr [esp + 0x18]
1c205590  imul eax, edi
1c205593  cdq 
1c205594  idiv dword ptr [esp + 0x30]
1c205598  lea edi, [eax + 0x96]
1c20559e  mov eax, ecx
1c2055a0  imul eax, dword ptr [esp + 0x28]
1c2055a5  cdq 
1c2055a6  idiv dword ptr [esp + 0x50]
1c2055aa  add eax, 0x32
1c2055ad  cmp edi, 0x12c
1c2055b3  mov dword ptr [esp + 0x28], eax
1c2055b7  jl 0x1c2055be
1c2055b9  mov edi, 0x12c
1c2055be  cmp edi, 0x64
1c2055c1  jg 0x1c2055c8
1c2055c3  mov edi, 0x64
1c2055c8  mov eax, dword ptr [0x1c25059c]
1c2055cd  add word ptr [eax], 0xfa
1c2055d2  jmp 0x1c205783
1c2055d7  mov edx, dword ptr [esp + 0x18]
1c2055db  mov dword ptr [esp + 0x50], ecx
1c2055df  sub ecx, 0x5aa
1c2055e5  mov dword ptr [esp + 0x30], edx
1c2055e9  mov dword ptr [esp + 0x38], ebx
1c2055ed  sub ebx, 0x9a1
1c2055f3  sub dword ptr [esp + 0x18], 0x1c2
1c2055fb  cmp ax, 3
1c2055ff  mov eax, dword ptr [esp + 0x18]
1c205603  jne 0x1c20568f
1c205609  mov dword ptr [esp + 0x1c], 0x3e8
1c205611  imul eax, ebp
1c205614  mov edx, eax
1c205616  lea eax, [eax + eax*2]
1c205619  shl eax, 3
1c20561c  imul ecx, ebp
1c20561f  sub eax, edx
1c205621  shl eax, 2
1c205624  cdq 
1c205625  idiv dword ptr [esp + 0x1c]
1c205629  add eax, 0x190
1c20562e  mov dword ptr [esp + 0x18], eax
1c205632  mov eax, ecx
1c205634  lea ecx, [ecx + ecx*2]
1c205637  shl ecx, 3
1c20563a  sub ecx, eax
1c20563c  imul ebx, ebp
1c20563f  lea eax, [ecx*4]
1c205646  mov ecx, 0x3e8
1c20564b  cdq 
1c20564c  idiv ecx
1c20564e  mov ebp, 0x3e8
1c205653  lea ecx, [eax + 0x564]
1c205659  mov eax, ebx
1c20565b  lea ebx, [ebx + ebx*2]
1c20565e  shl ebx, 3
1c205661  sub ebx, eax
1c205663  lea eax, [ebx*4]
1c20566a  cdq 
1c20566b  idiv ebp
1c20566d  lea ebx, [eax + 0x92e]
1c205673  mov eax, ebx
1c205675  sub eax, ecx
1c205677  cmp eax, 0xfa
1c20567c  jge 0x1c205684
1c20567e  lea ebx, [ecx + 0xfa]
1c205684  mov eax, dword ptr [0x1c25059c]
1c205689  sub word ptr [eax], 0x64
1c20568d  jmp 0x1c2056e5
1c20568f  imul eax, ebp
1c205692  shl eax, 2
1c205695  imul ecx, ebp
1c205698  shl ecx, 2
1c20569b  lea edx, [eax + eax*4]
1c20569e  mov dword ptr [esp + 0x1c], 0x3e8
1c2056a6  lea eax, [edx + edx*4]
1c2056a9  cdq 
1c2056aa  idiv dword ptr [esp + 0x1c]
1c2056ae  add eax, 0x1c2
1c2056b3  lea edx, [ecx + ecx*4]
1c2056b6  mov ecx, 0x3e8
1c2056bb  mov dword ptr [esp + 0x18], eax
1c2056bf  imul ebx, ebp
1c2056c2  shl ebx, 2
1c2056c5  lea eax, [edx + edx*4]
1c2056c8  cdq 
1c2056c9  idiv ecx
1c2056cb  lea edx, [ebx + ebx*4]
1c2056ce  mov ebp, 0x3e8
1c2056d3  lea ecx, [eax + 0x5aa]
1c2056d9  lea eax, [edx + edx*4]
1c2056dc  cdq 
1c2056dd  idiv ebp
1c2056df  lea ebx, [eax + 0x9a1]
1c2056e5  mov eax, dword ptr [esp + 0x18]
1c2056e9  imul eax, edi
1c2056ec  cdq 
1c2056ed  idiv dword ptr [esp + 0x30]
1c2056f1  mov edi, eax
1c2056f3  mov eax, ecx
1c2056f5  imul eax, dword ptr [esp + 0x28]
1c2056fa  cdq 
1c2056fb  idiv dword ptr [esp + 0x50]
1c2056ff  mov dword ptr [esp + 0x28], eax
1c205703  mov eax, ebx
1c205705  imul eax, dword ptr [esp + 0x24]
1c20570a  cdq 
1c20570b  idiv dword ptr [esp + 0x38]
1c20570f  mov dword ptr [esp + 0x24], eax
1c205713  cmp edi, 0x12c
1c205719  jl 0x1c205720
1c20571b  mov edi, 0x12c
1c205720  cmp edi, 0x28
1c205723  jg 0x1c20572a
1c205725  mov edi, 0x28
1c20572a  movsx eax, word ptr [esi + 0x46]
1c20572e  sub eax, 0x6e
1c205731  test eax, eax
1c205733  jg 0x1c205737
1c205735  xor eax, eax
1c205737  cdq 
1c205738  mov ebp, 0xe
1c20573d  idiv ebp
1c20573f  cmp eax, 0x14
1c205742  jl 0x1c205749
1c205744  mov eax, 0x14
1c205749  mov edx, dword ptr [0x1c250598]
1c20574f  sub word ptr [edx], ax
1c205752  mov eax, dword ptr [0x1c250584]
1c205757  sub word ptr [eax], 0xd
1c20575b  mov edx, dword ptr [esp + 0x18]
1c20575f  shl edx, 5
1c205762  mov ebp, dword ptr [0x1c250578]
1c205768  sub word ptr [ebp], 2
1c20576d  add edx, dword ptr [esp + 0x18]
1c205771  mov ebp, 0x21
1c205776  mov eax, dword ptr [esp + 0x18]
1c20577a  add eax, edx
1c20577c  cdq 
1c20577d  idiv ebp
1c20577f  mov dword ptr [esp + 0x18], eax
1c205783  mov ax, word ptr [esi + 0x84]
1c20578a  mov edx, dword ptr [0x1c250598]
1c205790  add word ptr [edx], ax
1c205793  mov eax, dword ptr [0x1c250584]
1c205798  mov bp, word ptr [esi + 0x86]
1c20579f  add word ptr [eax], bp
1c2057a2  mov bp, word ptr [esi + 0x88]
1c2057a9  mov edx, dword ptr [0x1c250578]
1c2057af  add word ptr [edx], bp
1c2057b2  mov ebp, 0x64
1c2057b7  movsx eax, word ptr [esi + 0x92]
1c2057be  imul eax, dword ptr [esp + 0x18]
1c2057c3  cdq 
1c2057c4  idiv ebp
1c2057c6  mov ebp, eax
1c2057c8  movsx eax, word ptr [esi + 0x94]
1c2057cf  imul eax, ecx
1c2057d2  cdq 
1c2057d3  mov ecx, 0x64
1c2057d8  idiv ecx
1c2057da  mov ecx, eax
1c2057dc  movsx eax, word ptr [esi + 0x96]
1c2057e3  imul eax, ebx
1c2057e6  cdq 
1c2057e7  mov ebx, 0x64
1c2057ec  idiv ebx
1c2057ee  mov ebx, eax
1c2057f0  cmp ebp, 0xff0
1c2057f6  jl 0x1c2057fd
1c2057f8  mov ebp, 0xff0
1c2057fd  cmp ebp, 0x64
1c205800  jg 0x1c205807
1c205802  mov ebp, 0x64
1c205807  mov dword ptr [esp + 0x18], ebp
1c20580b  cmp ecx, 0xff0
1c205811  jl 0x1c205818
1c205813  mov ecx, 0xff0
1c205818  cmp ecx, 0x64
1c20581b  jg 0x1c205822
1c20581d  mov ecx, 0x64
1c205822  cmp ebx, 0xff0
1c205828  jl 0x1c20582f
1c20582a  mov ebx, 0xff0
1c20582f  cmp ebx, 0x64
1c205832  jg 0x1c205839
1c205834  mov ebx, 0x64
1c205839  movsx eax, word ptr [esi + 0x8c]
1c205840  imul eax, edi
1c205843  mov edi, 0x64
1c205848  mov ebp, 0x64
1c20584d  cdq 
1c20584e  idiv edi
1c205850  mov edi, eax
1c205852  movsx eax, word ptr [esi + 0x8e]
1c205859  imul eax, dword ptr [esp + 0x28]
1c20585e  cdq 
1c20585f  idiv ebp
1c205861  mov dword ptr [esp + 0x1c], 0x64
1c205869  mov ebp, eax
1c20586b  movsx eax, word ptr [esi + 0x90]
1c205872  imul eax, dword ptr [esp + 0x24]
1c205877  cdq 
1c205878  idiv dword ptr [esp + 0x1c]
1c20587c  cmp edi, 0x1f4
1c205882  jl 0x1c205889
1c205884  mov edi, 0x1f4
1c205889  cmp edi, 0x28
1c20588c  jg 0x1c205893
1c20588e  mov edi, 0x28
1c205893  cmp ebp, 0x1f4
1c205899  jl 0x1c2058a0
1c20589b  mov ebp, 0x1f4
1c2058a0  cmp ebp, 0x28
1c2058a3  jg 0x1c2058aa
1c2058a5  mov ebp, 0x28
1c2058aa  mov dword ptr [esp + 0x28], ebp
1c2058ae  cmp eax, 0x1f4
1c2058b3  jl 0x1c2058ba
1c2058b5  mov eax, 0x1f4
1c2058ba  cmp eax, 0x28
1c2058bd  jg 0x1c2058c4
1c2058bf  mov eax, 0x28
1c2058c4  mov dword ptr [esp + 0x24], eax
1c2058c8  movsx eax, word ptr [esi + 0x98]
1c2058cf  sub eax, dword ptr [esp + 0x3c]
1c2058d3  lea edx, [eax + eax*4]
1c2058d6  lea ebp, [edx + edx*4]
1c2058d9  lea eax, [ebp + ebp*4]
1c2058dd  lea edx, [eax + eax*4]
1c2058e0  lea eax, [edx*8]
1c2058e7  sar eax, 0x10
1c2058ea  add dword ptr [esp + 0x3c], eax
1c2058ee  movsx eax, word ptr [esi + 0x9c]
1c2058f5  sub eax, dword ptr [esp + 0x40]
1c2058f9  lea edx, [eax + eax*4]
1c2058fc  lea ebp, [edx + edx*4]
1c2058ff  lea eax, [ebp + ebp*4]
1c205903  lea edx, [eax + eax*4]
1c205906  lea eax, [edx*8]
1c20590d  sar eax, 0x10
1c205910  add dword ptr [esp + 0x40], eax
1c205914  movsx eax, word ptr [esi + 0x9a]
1c20591b  sub eax, dword ptr [esp + 0x44]
1c20591f  lea edx, [eax + eax*4]
1c205922  lea ebp, [edx + edx*4]
1c205925  lea eax, [ebp + ebp*4]
1c205929  lea edx, [eax + eax*4]
1c20592c  lea eax, [edx*8]
1c205933  sar eax, 0x10
1c205936  add dword ptr [esp + 0x44], eax
1c20593a  movsx eax, word ptr [esi + 0x9e]
1c205941  sub eax, dword ptr [esp + 0x48]
1c205945  lea edx, [eax + eax*4]
1c205948  lea ebp, [edx + edx*4]
1c20594b  lea eax, [ebp + ebp*4]
1c20594f  lea edx, [eax + eax*4]
1c205952  lea eax, [edx*8]
1c205959  sar eax, 0x10
1c20595c  mov dx, word ptr [esi + 0x8a]
1c205963  add dword ptr [esp + 0x48], eax
1c205967  add word ptr [esp + 0x14], dx
1c20596c  mov ax, word ptr [esp + 0x14]
1c205971  cmp ax, 0xf
1c205975  jl 0x1c20597b
1c205977  mov ax, 0xf
1c20597b  test ax, ax
1c20597e  jg 0x1c205983
1c205980  xor ax, ax
1c205983  mov word ptr [esp + 0x14], ax
1c205988  mov ebp, dword ptr [0x1c2505a0]
1c20598e  mov eax, dword ptr [0x1c25059c]
1c205993  cmp word ptr [esi + 0x48], 0x1f40
1c205999  movsx edx, word ptr [eax]
1c20599c  movsx eax, word ptr [ebp]
1c2059a0  mov dword ptr [esp + 0x38], edx
1c2059a4  mov dword ptr [esp + 0x30], eax
1c2059a8  jne 0x1c205a70
1c2059ae  mov edx, dword ptr [esp + 0x18]
1c2059b2  lea eax, [edx + edx*4]
1c2059b5  lea eax, [edx + eax*2]
1c2059b8  lea edx, [edi + edi*4]
1c2059bb  sar eax, 3
1c2059be  mov dword ptr [esp + 0x18], eax
1c2059c2  lea eax, [edi + edx*2]
1c2059c5  sar eax, 3
1c2059c8  lea edx, [ecx + ecx*4]
1c2059cb  mov edi, eax
1c2059cd  mov ebp, dword ptr [esp + 0x28]
1c2059d1  lea eax, [ecx + edx*2]
1c2059d4  lea edx, [ebp + ebp*4]
1c2059d8  sar eax, 3
1c2059db  lea edx, [ebp + edx*2]
1c2059df  sar edx, 3
1c2059e2  mov ecx, eax
1c2059e4  lea eax, [ebx + ebx*4]
1c2059e7  mov ebp, dword ptr [esp + 0x24]
1c2059eb  mov dword ptr [esp + 0x28], edx
1c2059ef  lea eax, [ebx + eax*2]
1c2059f2  sar eax, 3
1c2059f5  lea edx, [ebp + ebp*4]
1c2059f9  mov ebx, eax
1c2059fb  lea edx, [ebp + edx*2]
1c2059ff  sar edx, 3
1c205a02  mov ebp, dword ptr [esp + 0x3c]
1c205a06  mov dword ptr [esp + 0x24], edx
1c205a0a  lea eax, [ebp + ebp*4]
1c205a0e  mov edx, dword ptr [esp + 0x44]
1c205a12  lea eax, [ebp + eax*2]
1c205a16  sar eax, 3
1c205a19  lea ebp, [edx + edx*4]
1c205a1c  mov dword ptr [esp + 0x3c], eax
1c205a20  lea eax, [edx + ebp*2]
1c205a23  sar eax, 3
1c205a26  mov edx, dword ptr [esp + 0x40]
1c205a2a  mov dword ptr [esp + 0x44], eax
1c205a2e  lea ebp, [edx + edx*4]
1c205a31  lea eax, [edx + ebp*2]
1c205a34  mov edx, dword ptr [esp + 0x48]
1c205a38  sar eax, 3
1c205a3b  lea ebp, [edx + edx*4]
1c205a3e  mov dword ptr [esp + 0x40], eax
1c205a42  lea eax, [edx + ebp*2]
1c205a45  sar eax, 3
1c205a48  mov ebp, dword ptr [esp + 0x38]
1c205a4c  mov dword ptr [esp + 0x48], eax
1c205a50  lea edx, [ebp + ebp*4]
1c205a54  mov eax, dword ptr [esp + 0x30]
1c205a58  lea edx, [ebp + edx*2]
1c205a5c  sar edx, 3
1c205a5f  lea ebp, [eax + eax*4]
1c205a62  mov dword ptr [esp + 0x38], edx
1c205a66  lea edx, [eax + ebp*2]
1c205a69  sar edx, 3
1c205a6c  mov dword ptr [esp + 0x30], edx
1c205a70  test dword ptr [0x1c250e70], 0xc0100000
1c205a7a  je 0x1c205aac
1c205a7c  mov ax, word ptr [0x1c250566]
1c205a82  shr ax, 1
1c205a86  cmp ax, word ptr [esp + 0x16]
1c205a8b  jae 0x1c205aac
1c205a8d  xor eax, eax
1c205a8f  mov al, byte ptr [0x1c250e7e]
1c205a94  mov edx, eax
1c205a96  lea ebp, [eax + eax*4]
1c205a99  lea eax, [ebp + ebp*4]
1c205a9d  add eax, edx
1c205a9f  mov edx, dword ptr [esp + 0x2c]
1c205aa3  mov ebp, dword ptr [edx + 4]
1c205aa6  mov al, byte ptr [eax + ebp + 0x31]
1c205aaa  jmp 0x1c205ac9
1c205aac  xor eax, eax
1c205aae  mov al, byte ptr [0x1c250e7e]
1c205ab3  mov edx, eax
1c205ab5  lea ebp, [eax + eax*4]
1c205ab8  lea eax, [ebp + ebp*4]
1c205abc  add eax, edx
1c205abe  mov edx, dword ptr [esp + 0x2c]
1c205ac2  mov ebp, dword ptr [edx + 4]
1c205ac5  mov al, byte ptr [eax + ebp + 0x17]
1c205ac9  mov byte ptr [0x1c250e69], al
1c205ace  cmp byte ptr [0x1c250e69], 0
1c205ad5  jne 0x1c205ae1
1c205ad7  mov al, byte ptr [0x1c250e63]
1c205adc  mov byte ptr [0x1c250e69], al
1c205ae1  mov al, byte ptr [0x1c250e69]
1c205ae6  mov edx, dword ptr [0x1c250e58]
1c205aec  mov byte ptr [edx + 0x1a], al
1c205aef  mov eax, dword ptr [esp + 0x18]
1c205af3  add eax, 8
1c205af6  cdq 
1c205af7  and edx, 0xf
1c205afa  add eax, edx
1c205afc  xor edx, edx
1c205afe  sar eax, 4
1c205b01  mov dl, al
1c205b03  mov al, byte ptr [edx + 0x1c205ff4]
1c205b09  mov edx, dword ptr [0x1c250e58]
1c205b0f  mov byte ptr [edx], al
1c205b11  lea eax, [ecx + 8]
1c205b14  cdq 
1c205b15  and edx, 0xf
1c205b18  add eax, edx
1c205b1a  xor edx, edx
1c205b1c  sar eax, 4
1c205b1f  mov dl, al
1c205b21  mov al, byte ptr [edx + 0x1c205ff4]
1c205b27  mov edx, dword ptr [0x1c250e58]
1c205b2d  mov byte ptr [edx + 1], al
1c205b30  lea eax, [ebx + 8]
1c205b33  cdq 
1c205b34  and edx, 0xf
1c205b37  add eax, edx
1c205b39  xor edx, edx
1c205b3b  sar eax, 4
1c205b3e  mov dl, al
1c205b40  mov al, byte ptr [edx + 0x1c205ff4]
1c205b46  mov edx, dword ptr [0x1c250e58]
1c205b4c  mov byte ptr [edx + 2], al
1c205b4f  mov eax, dword ptr [esp + 0x3c]
1c205b53  add eax, 0x10
1c205b56  cdq 
1c205b57  and edx, 0x1f
1c205b5a  add eax, edx
1c205b5c  xor edx, edx
1c205b5e  sar eax, 5
1c205b61  mov dl, al
1c205b63  mov al, byte ptr [edx + 0x1c2060f4]
1c205b69  mov edx, dword ptr [0x1c250e58]
1c205b6f  mov byte ptr [edx + 3], al
1c205b72  mov eax, dword ptr [esp + 0x40]
1c205b76  add eax, 0x10
1c205b79  cdq 
1c205b7a  and edx, 0x1f
1c205b7d  add eax, edx
1c205b7f  xor edx, edx
1c205b81  sar eax, 5
1c205b84  mov dl, al
1c205b86  mov al, byte ptr [edx + 0x1c2060f4]
1c205b8c  mov edx, dword ptr [0x1c250e58]
1c205b92  mov byte ptr [edx + 4], al
1c205b95  mov edx, dword ptr [0x1c250e58]
1c205b9b  lea eax, [edi + 4]
1c205b9e  mov byte ptr [edx + 5], 0
1c205ba2  cdq 
1c205ba3  and edx, 7
1c205ba6  add eax, edx
1c205ba8  xor edx, edx
1c205baa  sar eax, 3
1c205bad  mov dl, al
1c205baf  mov al, byte ptr [edx + 0x1c2061f4]
1c205bb5  mov byte ptr [esp + 0x1c], al
1c205bb9  mov eax, dword ptr [esp + 0x28]
1c205bbd  shl byte ptr [esp + 0x1c], 4
1c205bc2  add eax, 4
1c205bc5  cdq 
1c205bc6  and edx, 7
1c205bc9  add eax, edx
1c205bcb  xor edx, edx
1c205bcd  sar eax, 3
1c205bd0  mov dl, al
1c205bd2  mov al, byte ptr [edx + 0x1c2061f4]
1c205bd8  mov edx, dword ptr [0x1c250e58]
1c205bde  add byte ptr [esp + 0x1c], al
1c205be2  mov al, byte ptr [esp + 0x1c]
1c205be6  mov byte ptr [edx + 6], al
1c205be9  mov eax, dword ptr [esp + 0x24]
1c205bed  add eax, 4
1c205bf0  cdq 
1c205bf1  and edx, 7
1c205bf4  add eax, edx
1c205bf6  xor edx, edx
1c205bf8  sar eax, 3
1c205bfb  mov dl, al
1c205bfd  mov al, byte ptr [edx + 0x1c2061f4]
1c205c03  mov edx, dword ptr [0x1c250e58]
1c205c09  shl al, 4
1c205c0c  add al, byte ptr [esp + 0x14]
1c205c10  mov byte ptr [edx + 7], al
1c205c13  mov eax, dword ptr [esp + 0x44]
1c205c17  add eax, 4
1c205c1a  cdq 
1c205c1b  and edx, 7
1c205c1e  add eax, edx
1c205c20  xor edx, edx
1c205c22  sar eax, 3
1c205c25  mov dl, al
1c205c27  mov al, byte ptr [edx + 0x1c2062f4]
1c205c2d  mov byte ptr [esp + 0x1c], al
1c205c31  mov eax, dword ptr [esp + 0x48]
1c205c35  shl byte ptr [esp + 0x1c], 4
1c205c3a  add eax, 4
1c205c3d  cdq 
1c205c3e  and edx, 7
1c205c41  add eax, edx
1c205c43  xor edx, edx
1c205c45  sar eax, 3
1c205c48  mov dl, al
1c205c4a  mov al, byte ptr [edx + 0x1c2062f4]
1c205c50  mov edx, dword ptr [0x1c250e58]
1c205c56  add byte ptr [esp + 0x1c], al
1c205c5a  mov al, byte ptr [esp + 0x1c]
1c205c5e  mov byte ptr [edx + 8], al
1c205c61  mov eax, dword ptr [esp + 0x38]
1c205c65  add eax, 0x10
1c205c68  cdq 
1c205c69  and edx, 0x1f
1c205c6c  add eax, edx
1c205c6e  xor edx, edx
1c205c70  sar eax, 5
1c205c73  mov dl, al
1c205c75  mov al, byte ptr [edx + 0x1c2060f4]
1c205c7b  mov edx, dword ptr [0x1c250e58]
1c205c81  mov byte ptr [edx + 9], al
1c205c84  mov al, byte ptr [0x1c250e7e]
1c205c89  mov edx, dword ptr [0x1c250e58]
1c205c8f  mov byte ptr [edx + 0xb], al
1c205c92  mov ax, word ptr [esi + 0x44]
1c205c96  shr ax, 1
1c205c9a  cmp ax, 1
1c205c9e  ja 0x1c205ca4
1c205ca0  mov ax, 1
1c205ca4  mov edx, dword ptr [0x1c250e58]
1c205caa  mov byte ptr [edx + 0xa], al
1c205cad  mov eax, dword ptr [0x1c250598]
1c205cb2  movsx eax, word ptr [eax]
1c205cb5  add eax, eax
1c205cb7  cmp eax, 0x80
1c205cbc  jl 0x1c205cc3
1c205cbe  mov eax, 0x80
1c205cc3  test eax, eax
1c205cc5  jg 0x1c205cc9
1c205cc7  xor eax, eax
1c205cc9  mov edx, dword ptr [0x1c250e58]
1c205ccf  mov byte ptr [edx + 0x10], al
1c205cd2  mov eax, dword ptr [0x1c250584]
1c205cd7  movsx eax, word ptr [eax]
1c205cda  add eax, eax
1c205cdc  cmp eax, 0x80
1c205ce1  jl 0x1c205ce8
1c205ce3  mov eax, 0x80
1c205ce8  test eax, eax
1c205cea  jg 0x1c205cee
1c205cec  xor eax, eax
1c205cee  mov edx, dword ptr [0x1c250e58]
1c205cf4  mov byte ptr [edx + 0x11], al
1c205cf7  mov eax, dword ptr [0x1c250578]
1c205cfc  movsx eax, word ptr [eax]
1c205cff  add eax, eax
1c205d01  cmp eax, 0x80
1c205d06  jl 0x1c205d0d
1c205d08  mov eax, 0x80
1c205d0d  test eax, eax
1c205d0f  jg 0x1c205d13
1c205d11  xor eax, eax
1c205d13  mov edx, dword ptr [0x1c250e58]
1c205d19  mov byte ptr [edx + 0x12], al
1c205d1c  mov eax, dword ptr [0x1c250590]
1c205d21  movsx ebp, word ptr [eax]
1c205d24  lea eax, [ebp*2 + 0x5c]
1c205d2b  test eax, eax
1c205d2d  jg 0x1c205d31
1c205d2f  xor eax, eax
1c205d31  mov edx, dword ptr [0x1c250e58]
1c205d37  mov byte ptr [edx + 0x13], al
1c205d3a  mov eax, dword ptr [esp + 0x30]
1c205d3e  add eax, 4
1c205d41  cdq 
1c205d42  and edx, 7
1c205d45  add eax, edx
1c205d47  xor edx, edx
1c205d49  sar eax, 3
1c205d4c  mov dl, al
1c205d4e  mov al, byte ptr [edx + 0x1c2062f4]
1c205d54  mov edx, dword ptr [0x1c250e58]
1c205d5a  shl al, 4
1c205d5d  mov bp, word ptr [esp + 0x12]
1c205d62  mov byte ptr [edx + 0x14], al
1c205d65  mov edx, dword ptr [0x1c250e58]
1c205d6b  mov al, byte ptr [esp + 0x11]
1c205d6f  mov byte ptr [edx + 0x1b], al
1c205d72  mov edx, dword ptr [0x1c250e58]
1c205d78  mov word ptr [edx + 0x1c], bp
1c205d7c  mov al, byte ptr [esp + 0x34]
1c205d80  mov edx, dword ptr [0x1c250e58]
1c205d86  mov byte ptr [edx + 0x17], al
1c205d89  mov edx, dword ptr [0x1c250e58]
1c205d8f  mov al, byte ptr [esp + 0x54]
1c205d93  mov byte ptr [edx + 0x1f], al
1c205d96  inc dword ptr [esp + 0x54]
1c205d9a  xor eax, eax
1c205d9c  mov ax, word ptr [esi + 0x4c]
1c205da0  cmp eax, 2
1c205da3  je 0x1c205db7
1c205da5  cmp eax, 4
1c205da8  je 0x1c205dc5
1c205daa  mov eax, dword ptr [0x1c250e58]
1c205daf  mov word ptr [eax + 0x18], 0
1c205db5  jmp 0x1c205dc5
1c205db7  mov ax, word ptr [esi + 0x46]
1c205dbb  mov edx, dword ptr [0x1c250e58]
1c205dc1  mov word ptr [edx + 0x18], ax
1c205dc5  add dword ptr [0x1c250e58], 0x20
1c205dcc  test byte ptr [esp + 0x34], 8
1c205dd1  je 0x1c205dd8
1c205dd3  xor dword ptr [esp + 0x34], 8
1c205dd8  test byte ptr [esp + 0x34], 0x20
1c205ddd  je 0x1c205de4
1c205ddf  xor dword ptr [esp + 0x34], 0x20
1c205de4  add dword ptr [0x1c25057c], 2
1c205deb  add dword ptr [0x1c250580], 2
1c205df2  add dword ptr [0x1c250588], 2
1c205df9  add dword ptr [0x1c250568], 2
1c205e00  add dword ptr [0x1c25056c], 2
1c205e07  add dword ptr [0x1c250570], 2
1c205e0e  add dword ptr [0x1c25059c], 2
1c205e15  add dword ptr [0x1c2505a0], 2
1c205e1c  add dword ptr [0x1c250864], 2
1c205e23  add dword ptr [0x1c250594], 2
1c205e2a  add dword ptr [0x1c250598], 2
1c205e31  inc word ptr [esp + 0x16]
1c205e36  mov ax, word ptr [esp + 0x16]
1c205e3b  add dword ptr [0x1c250584], 2
1c205e42  add dword ptr [0x1c250578], 2
1c205e49  add dword ptr [0x1c250590], 2
1c205e50  add dword ptr [0x1c250574], 2
1c205e57  cmp word ptr [0x1c250566], ax
1c205e5e  ja 0x1c204f19
1c205e64  mov ax, word ptr [esi + 0x46]
1c205e68  mov ecx, dword ptr [esi + 0xf6]
1c205e6e  mov word ptr [ecx + 0x18], ax
1c205e72  mov edx, dword ptr [esp + 0x20]
1c205e76  push edx
1c205e77  mov eax, dword ptr [0x1c250e58]
1c205e7c  xor ecx, ecx
1c205e7e  mov cx, word ptr [0x1c250566]
1c205e85  shl ecx, 5
1c205e88  sub eax, ecx
1c205e8a  push eax
1c205e8b  push esi
1c205e8c  call 0x1c203ab0
1c205e91  add esp, 0xc
1c205e94  xor eax, eax
1c205e96  mov ax, word ptr [esi + 0x4c]
1c205e9a  cmp eax, 3
1c205e9d  je 0x1c205ea6
1c205e9f  cmp eax, 4
1c205ea2  je 0x1c205ec7
1c205ea4  jmp 0x1c205edb
1c205ea6  mov edx, dword ptr [esp + 0x20]
1c205eaa  mov eax, dword ptr [0x1c250e58]
1c205eaf  push edx
1c205eb0  xor ecx, ecx
1c205eb2  mov cx, word ptr [0x1c250566]
1c205eb9  shl ecx, 5
1c205ebc  sub eax, ecx
1c205ebe  push eax
1c205ebf  push esi
1c205ec0  call 0x1c2042c0
1c205ec5  jmp 0x1c205ed8
1c205ec7  mov edx, dword ptr [esp + 0x20]
1c205ecb  mov eax, dword ptr [0x1c250e58]
1c205ed0  push edx
1c205ed1  push eax
1c205ed2  push esi
1c205ed3  call 0x1c204030
1c205ed8  add esp, 0xc
1c205edb  mov ecx, 1
1c205ee0  mov edx, dword ptr [esp + 0x20]
1c205ee4  mov eax, dword ptr [edx + 0x16]
1c205ee7  test ah, 1
1c205eea  je 0x1c205ef1
1c205eec  mov ecx, 3
1c205ef1  test al, 0x80
1c205ef3  je 0x1c205ef8
1c205ef5  or ecx, 4
1c205ef8  mov eax, dword ptr [0x1c250e58]
1c205efd  xor edx, edx
1c205eff  mov dx, word ptr [0x1c250566]
1c205f06  shl edx, 5
1c205f09  sub eax, edx
1c205f0b  or byte ptr [eax + 0x17], cl
1c205f0e  mov eax, dword ptr [0x1c250e58]
1c205f13  mov dword ptr [esi + 0xfa], eax
1c205f19  xor ecx, ecx
1c205f1b  movsx eax, word ptr [esi + 0x98]
1c205f22  add eax, 0x10
1c205f25  cdq 
1c205f26  and edx, 0x1f
1c205f29  add eax, edx
1c205f2b  sar eax, 5
1c205f2e  mov cl, al
1c205f30  movzx ax, byte ptr [ecx + 0x1c2060f4]
1c205f38  mov word ptr [esi + 0xa0], ax
1c205f3f  xor ecx, ecx
1c205f41  movsx eax, word ptr [esi + 0x9c]
1c205f48  add eax, 0x10
1c205f4b  cdq 
1c205f4c  and edx, 0x1f
1c205f4f  add eax, edx
1c205f51  sar eax, 5
1c205f54  mov cl, al
1c205f56  movzx ax, byte ptr [ecx + 0x1c2060f4]
1c205f5e  mov word ptr [esi + 0xa4], ax
1c205f65  xor ecx, ecx
1c205f67  movsx eax, word ptr [esi + 0x9a]
1c205f6e  add eax, 4
1c205f71  cdq 
1c205f72  and edx, 7
1c205f75  add eax, edx
1c205f77  sar eax, 3
1c205f7a  mov cl, al
1c205f7c  movzx ax, byte ptr [ecx + 0x1c2062f4]
1c205f84  mov word ptr [esi + 0xa2], ax
1c205f8b  xor ecx, ecx
1c205f8d  movsx eax, word ptr [esi + 0x9e]
1c205f94  add eax, 4
1c205f97  cdq 
1c205f98  and edx, 7
1c205f9b  pop ebp
1c205f9c  add eax, edx
1c205f9e  pop edi
1c205f9f  sar eax, 3
1c205fa2  mov cl, al
1c205fa4  movzx ax, byte ptr [ecx + 0x1c2062f4]
1c205fac  mov word ptr [esi + 0xa6], ax
1c205fb3  pop esi
1c205fb4  pop ebx
1c205fb5  add esp, 0x48
1c205fb8  ret 
