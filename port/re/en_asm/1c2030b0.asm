1c2030b0  push ebx
1c2030b1  push esi
1c2030b2  push edi
1c2030b3  push 0x1c2508b0
1c2030b8  call 0x1c202fe0
1c2030bd  add esp, 4
1c2030c0  push 0x1c2507d0
1c2030c5  call 0x1c202fe0
1c2030ca  add esp, 4
1c2030cd  xor edx, edx
1c2030cf  mov dx, word ptr [0x1c250564]
1c2030d6  xor eax, eax
1c2030d8  mov ax, word ptr [0x1c250e7c]
1c2030de  lea ecx, [edx + edx*4]
1c2030e1  lea ebx, [eax + ecx*2]
1c2030e4  lea eax, [ebx + ebx*4]
1c2030e7  lea ecx, [eax*2]
1c2030ee  xor eax, eax
1c2030f0  mov al, byte ptr [ecx + 0x1c24c460]
1c2030f6  mov dword ptr [0x1c2508d8], eax
1c2030fb  xor eax, eax
1c2030fd  mov ax, word ptr [0x1c2505f0]
1c203103  lea ebx, [eax + eax*4]
1c203106  lea edx, [edx + ebx*2]
1c203109  lea eax, [edx + edx*4]
1c20310c  lea edx, [eax*2]
1c203113  xor eax, eax
1c203115  mov al, byte ptr [edx + 0x1c24c463]
1c20311b  mov dword ptr [0x1c2508dc], eax
1c203120  xor eax, eax
1c203122  cmp byte ptr [0x1c255303], 0x3f
1c203129  mov al, byte ptr [ecx + 0x1c24c466]
1c20312f  mov dword ptr [0x1c2508e0], eax
1c203134  jne 0x1c203140
1c203136  mov dword ptr [0x1c2508dc], 1
1c203140  cmp byte ptr [0x1c250e7e], 0x3f
1c203147  jne 0x1c203158
1c203149  mov eax, 1
1c20314e  mov dword ptr [0x1c2508e0], eax
1c203153  mov dword ptr [0x1c2508dc], eax
1c203158  cmp byte ptr [0x1c250810], 0x3f
1c20315f  jne 0x1c20316b
1c203161  mov dword ptr [0x1c2508e0], 1
1c20316b  mov dword ptr [0x1c2508e8], 0
1c203175  mov dword ptr [0x1c2508ec], 0x4b
1c20317f  xor eax, eax
1c203181  mov al, byte ptr [ecx + 0x1c24c461]
1c203187  mov dword ptr [0x1c2507f8], eax
1c20318c  xor eax, eax
1c20318e  mov al, byte ptr [edx + 0x1c24c464]
1c203194  mov edx, dword ptr [esp + 0x10]
1c203198  mov dword ptr [0x1c2507fc], eax
1c20319d  xor eax, eax
1c20319f  mov al, byte ptr [ecx + 0x1c24c467]
1c2031a5  xor ecx, ecx
1c2031a7  mov cl, byte ptr [0x1c250810]
1c2031ad  mov dword ptr [0x1c250800], eax
1c2031b2  mov eax, dword ptr [edx + 0x2c]
1c2031b5  xor ebx, ebx
1c2031b7  lea esi, [ecx + ecx*4]
1c2031ba  mov edi, dword ptr [eax + 4]
1c2031bd  lea esi, [esi + esi*4]
1c2031c0  add esi, ecx
1c2031c2  cmp cl, 0x1c
1c2031c5  mov bl, byte ptr [edi + esi + 0x16]
1c2031c9  mov dword ptr [0x1c2508c8], ebx
1c2031cf  je 0x1c2031d6
1c2031d1  cmp cl, 0x1b
1c2031d4  jne 0x1c2031e9
1c2031d6  test byte ptr [0x1c250e73], 8
1c2031dd  jne 0x1c2031e9
1c2031df  mov dword ptr [0x1c2508c8], 0
1c2031e9  mov edi, dword ptr [0x1c250e70]
1c2031ef  and edi, 0x10000000
1c2031f5  je 0x1c203219
1c2031f7  test byte ptr [0x1c2552ff], 8
1c2031fe  je 0x1c203219
1c203200  test byte ptr [0x1c2552fc], 0x40
1c203207  je 0x1c203219
1c203209  test byte ptr [0x1c250e5f], 0x10
1c203210  je 0x1c203219
1c203212  add dword ptr [0x1c2508c8], 6
1c203219  mov eax, dword ptr [0x1c2508c8]
1c20321e  mov dword ptr [0x1c2508cc], eax
1c203223  mov eax, 0x8000000
1c203228  test dword ptr [0x1c2552fc], eax
1c20322e  je 0x1c203245
1c203230  test dword ptr [0x1c250e5c], eax
1c203236  jne 0x1c203245
1c203238  mov eax, dword ptr [0x1c2508c8]
1c20323d  sub eax, 3
1c203240  mov dword ptr [0x1c2508cc], eax
1c203245  mov esi, dword ptr [0x1c2508c8]
1c20324b  xor eax, eax
1c20324d  mov dword ptr [0x1c2507e8], 0
1c203257  mov al, byte ptr [esi + 0x1c2065be]
1c20325d  mov esi, dword ptr [0x1c2508cc]
1c203263  mov dword ptr [0x1c2508c8], eax
1c203268  xor eax, eax
1c20326a  test byte ptr [0x1c2552fc], 0x44
1c203271  mov al, byte ptr [esi + 0x1c2065be]
1c203277  mov dword ptr [0x1c2508cc], eax
1c20327c  je 0x1c2032db
1c20327e  sub ecx, 0x35
1c203281  cmp ecx, 0x17
1c203284  ja 0x1c2032db
1c203286  xor eax, eax
1c203288  mov al, byte ptr [ecx + 0x1c203750]
1c20328e  jmp dword ptr [eax*4 + 0x1c203730]
1c203295  mov dword ptr [0x1c2507e8], 0x2f
1c20329f  jmp 0x1c2032db
1c2032a1  mov dword ptr [0x1c2507e8], 0x21
1c2032ab  jmp 0x1c2032db
1c2032ad  mov dword ptr [0x1c2507e8], 0x20
1c2032b7  jmp 0x1c2032db
1c2032b9  mov dword ptr [0x1c2507e8], 0x24
1c2032c3  jmp 0x1c2032db
1c2032c5  mov dword ptr [0x1c2507e8], 0x21
1c2032cf  jmp 0x1c2032db
1c2032d1  mov dword ptr [0x1c2507e8], 0x2b
1c2032db  mov eax, dword ptr [0x1c2507e8]
1c2032e0  xor ecx, ecx
1c2032e2  test byte ptr [0x1c250e67], 8
1c2032e9  mov cl, byte ptr [eax + 0x1c2065c8]
1c2032ef  mov dword ptr [0x1c2507e8], ecx
1c2032f5  mov dword ptr [0x1c2507ec], ecx
1c2032fb  jne 0x1c2035ac
1c203301  test dword ptr [0x1c250e64], 0x40040
1c20330b  je 0x1c2035ac
1c203311  mov ebx, dword ptr [0x1c250e70]
1c203317  and ebx, 0x10002000
1c20331d  jne 0x1c20332c
1c20331f  cmp byte ptr [0x1c250e7e], 0x1c
1c203326  jne 0x1c2035ac
1c20332c  mov word ptr [0x1c250e6e], 5
1c203335  cmp byte ptr [0x1c250e68], 0
1c20333c  mov word ptr [0x1c250e52], 0x2e
1c203345  jne 0x1c203359
1c203347  mov word ptr [0x1c250e6e], 2
1c203350  mov word ptr [0x1c250e52], 0x28
1c203359  test edi, edi
1c20335b  jne 0x1c203383
1c20335d  test byte ptr [0x1c250e71], 8
1c203364  jne 0x1c20337a
1c203366  test byte ptr [0x1c250e65], 4
1c20336d  jne 0x1c20337a
1c20336f  mov word ptr [0x1c250e6e], 7
1c203378  jmp 0x1c203383
1c20337a  mov word ptr [0x1c250e6e], 6
1c203383  test byte ptr [0x1c250edb], 8
1c20338a  je 0x1c20339c
1c20338c  cmp byte ptr [0x1c250e74], 0
1c203393  jne 0x1c20339c
1c203395  dec word ptr [0x1c250e6e]
1c20339c  test byte ptr [0x1c250e64], 1
1c2033a3  je 0x1c2033ad
1c2033a5  sub word ptr [0x1c250e6e], 3
1c2033ad  cmp byte ptr [0x1c250e7e], 0x1c
1c2033b4  je 0x1c2033bf
1c2033b6  cmp byte ptr [0x1c250e7e], 0x1b
1c2033bd  jne 0x1c2033d0
1c2033bf  mov word ptr [0x1c250e6e], 8
1c2033c8  sub word ptr [0x1c250e52], 3
1c2033d0  mov esi, dword ptr [0x1c250e64]
1c2033d6  and esi, 0x40000
1c2033dc  je 0x1c2033fb
1c2033de  cmp byte ptr [0x1c255301], 0x41
1c2033e5  jne 0x1c2033fb
1c2033e7  test byte ptr [0x1c2552f0], 0x80
1c2033ee  jne 0x1c2033fb
1c2033f0  mov word ptr [0x1c250e6e], 0
1c2033f9  jmp 0x1c203423
1c2033fb  test byte ptr [0x1c250e64], 0x40
1c203402  je 0x1c203423
1c203404  test edi, edi
1c203406  je 0x1c203413
1c203408  mov word ptr [0x1c250e6e], 1
1c203411  jmp 0x1c203423
1c203413  mov ax, word ptr [0x1c250566]
1c203419  shr ax, 1
1c20341d  mov word ptr [0x1c250e6e], ax
1c203423  mov cx, word ptr [0x1c250566]
1c20342a  mov ax, cx
1c20342d  mov di, word ptr [0x1c250e6e]
1c203434  cmp ax, di
1c203437  jl 0x1c20343c
1c203439  mov ax, di
1c20343c  test byte ptr [0x1c250e72], 8
1c203443  mov word ptr [0x1c250e6e], ax
1c203449  je 0x1c20346e
1c20344b  test byte ptr [0x1c250e64], 2
1c203452  je 0x1c20346e
1c203454  cmp byte ptr [0x1c250e7e], 0x36
1c20345b  jne 0x1c203467
1c20345d  add word ptr [0x1c250e52], 6
1c203465  jmp 0x1c20346e
1c203467  inc word ptr [0x1c250e52]
1c20346e  mov ax, word ptr [edx + 0x52]
1c203472  test ax, ax
1c203475  je 0x1c20347d
1c203477  cmp ax, 3
1c20347b  jne 0x1c2034ac
1c20347d  test byte ptr [0x1c250e65], 4
1c203484  jne 0x1c2034ac
1c203486  test ebx, ebx
1c203488  je 0x1c2034ac
1c20348a  add word ptr [0x1c250e6e], 2
1c203492  cmp byte ptr [0x1c250e74], 0
1c203499  jne 0x1c2034a4
1c20349b  test byte ptr [0x1c250e78], 4
1c2034a2  je 0x1c2034ac
1c2034a4  add word ptr [0x1c250e6e], 2
1c2034ac  cmp word ptr [edx + 0x4c], 3
1c2034b1  jne 0x1c2034bb
1c2034b3  sar word ptr [0x1c250e6e], 1
1c2034bb  cmp word ptr [0x1c250e6e], 0
1c2034c3  jle 0x1c2035ac
1c2034c9  movsx eax, word ptr [0x1c250e52]
1c2034d0  xor edx, edx
1c2034d2  test byte ptr [0x1c250e64], 0x40
1c2034d9  mov dl, byte ptr [eax + 0x1c2065c8]
1c2034df  mov dword ptr [0x1c2507d8], edx
1c2034e5  je 0x1c2034f1
1c2034e7  mov eax, dword ptr [0x1c2507e4]
1c2034ec  mov dword ptr [0x1c2507d8], eax
1c2034f1  mov dword ptr [0x1c2507fc], 2
1c2034fb  xor eax, eax
1c2034fd  xor edi, edi
1c2034ff  mov di, word ptr [0x1c250566]
1c203506  mov dword ptr [0x1c2507dc], eax
1c20350b  mov dword ptr [0x1c250808], eax
1c203510  movsx eax, word ptr [0x1c250e6e]
1c203517  shl eax, 2
1c20351a  lea edx, [eax + eax*4]
1c20351d  lea eax, [edx + edx*4 + 0x32]
1c203521  sub edx, edx
1c203523  div edi
1c203525  cmp eax, 0x64
1c203528  jb 0x1c20352f
1c20352a  mov eax, 0x64
1c20352f  add dword ptr [0x1c250608], 0x64
1c203536  mov dword ptr [0x1c25080c], eax
1c20353b  test esi, esi
1c20353d  je 0x1c2035ac
1c20353f  test byte ptr [0x1c250e67], 4
1c203546  je 0x1c203552
1c203548  add dword ptr [0x1c250660], 0x96
1c203552  movsx ecx, cx
1c203555  xor eax, eax
1c203557  mov dword ptr [0x1c2507fc], eax
1c20355c  mov dword ptr [0x1c2508b8], eax
1c203561  mov dword ptr [0x1c25062c], eax
1c203566  mov dword ptr [0x1c2505dc], eax
1c20356b  mov dword ptr [0x1c2508dc], eax
1c203570  mov eax, 0xfffffe70
1c203575  cdq 
1c203576  idiv ecx
1c203578  mov ecx, dword ptr [0x1c25080c]
1c20357e  add ecx, eax
1c203580  test ecx, ecx
1c203582  jg 0x1c203586
1c203584  xor ecx, ecx
1c203586  mov eax, dword ptr [0x1c25080c]
1c20358b  mov dword ptr [0x1c250638], ecx
1c203591  mov dword ptr [0x1c2505e8], ecx
1c203597  mov dword ptr [0x1c2508e8], ecx
1c20359d  mov dword ptr [0x1c25063c], eax
1c2035a2  mov dword ptr [0x1c2505ec], eax
1c2035a7  mov dword ptr [0x1c2508ec], eax
1c2035ac  mov eax, dword ptr [0x1c2508c8]
1c2035b1  mov ecx, 0x64
1c2035b6  sub eax, dword ptr [0x1c2508bc]
1c2035bc  imul eax, dword ptr [0x1c2508d8]
1c2035c3  cdq 
1c2035c4  idiv ecx
1c2035c6  mov ecx, dword ptr [0x1c2508bc]
1c2035cc  add ecx, eax
1c2035ce  mov eax, dword ptr [0x1c2507e8]
1c2035d3  sub eax, dword ptr [0x1c2507dc]
1c2035d9  mov dword ptr [0x1c2508d4], ecx
1c2035df  imul eax, dword ptr [0x1c2507f8]
1c2035e6  cdq 
1c2035e7  mov ecx, 0x64
1c2035ec  idiv ecx
1c2035ee  mov ecx, dword ptr [0x1c2507dc]
1c2035f4  add ecx, eax
1c2035f6  mov eax, dword ptr [0x1c2508c8]
1c2035fb  mov dword ptr [0x1c2507f4], ecx
1c203601  test eax, eax
1c203603  jg 0x1c203607
1c203605  xor eax, eax
1c203607  mov dword ptr [0x1c2508c8], eax
1c20360c  mov eax, dword ptr [0x1c2508cc]
1c203611  test eax, eax
1c203613  jg 0x1c203617
1c203615  xor eax, eax
1c203617  mov dword ptr [0x1c2508cc], eax
1c20361c  mov eax, dword ptr [0x1c2508d4]
1c203621  test eax, eax
1c203623  jg 0x1c203627
1c203625  xor eax, eax
1c203627  push 0x1c250870
1c20362c  mov dword ptr [0x1c2508d4], eax
1c203631  call 0x1c202fe0
1c203636  add esp, 4
1c203639  push 0x1c250a10
1c20363e  call 0x1c202fe0
1c203643  mov dword ptr [0x1c250a28], 0xc
1c20364d  add esp, 4
1c203650  test byte ptr [0x1c2552ff], 8
1c203657  jne 0x1c203663
1c203659  mov dword ptr [0x1c250a28], 8
1c203663  cmp byte ptr [0x1c255300], 0
1c20366a  je 0x1c203673
1c20366c  add dword ptr [0x1c250a28], 2
1c203673  test byte ptr [0x1c250554], 4
1c20367a  je 0x1c20368c
1c20367c  cmp byte ptr [0x1c255300], 0
1c203683  jne 0x1c20368c
1c203685  sub dword ptr [0x1c250a28], 2
1c20368c  test byte ptr [0x1c2552ff], 1
1c203693  je 0x1c20369c
1c203695  sub dword ptr [0x1c250a28], 5
1c20369c  cmp byte ptr [0x1c250810], 1
1c2036a3  jne 0x1c2036ac
1c2036a5  add dword ptr [0x1c2505bc], 0x32
1c2036ac  mov eax, 3
1c2036b1  mov esi, dword ptr [0x1c250a28]
1c2036b7  shl esi, 8
1c2036ba  mov dword ptr [0x1c250a40], eax
1c2036bf  mov dword ptr [0x1c250a3c], eax
1c2036c4  mov dword ptr [0x1c250a28], esi
1c2036ca  mov eax, dword ptr [0x1c250888]
1c2036cf  mov ecx, 0x64
1c2036d4  sub eax, dword ptr [0x1c25087c]
1c2036da  mov dword ptr [0x1c250a2c], esi
1c2036e0  imul eax, dword ptr [0x1c250898]
1c2036e7  cdq 
1c2036e8  idiv ecx
1c2036ea  mov ecx, dword ptr [0x1c25087c]
1c2036f0  sub esi, dword ptr [0x1c250a1c]
1c2036f6  add ecx, eax
1c2036f8  mov ebx, 0x64
1c2036fd  lea eax, [esi + esi*4]
1c203700  mov dword ptr [0x1c250894], ecx
1c203706  mov dword ptr [0x1c250a38], 0x32
1c203710  lea ecx, [eax + eax*4]
1c203713  pop edi
1c203714  pop esi
1c203715  lea eax, [ecx*2]
1c20371c  cdq 
1c20371d  idiv ebx
1c20371f  mov ecx, dword ptr [0x1c250a1c]
1c203725  pop ebx
1c203726  add ecx, eax
1c203728  mov dword ptr [0x1c250a34], ecx
1c20372e  ret 
