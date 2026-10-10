1c2042c0  mov cx, word ptr [0x1c250560]
1c2042c7  push ebx
1c2042c8  xor dx, dx
1c2042cb  push esi
1c2042cc  cmp word ptr [0x1c250566], dx
1c2042d3  push edi
1c2042d4  mov esi, dword ptr [esp + 0x14]
1c2042d8  push ebp
1c2042d9  mov eax, esi
1c2042db  jbe 0x1c2042ef
1c2042dd  mov word ptr [eax + 0x18], cx
1c2042e1  add eax, 0x20
1c2042e4  inc dx
1c2042e6  cmp dx, word ptr [0x1c250566]
1c2042ed  jb 0x1c2042dd
1c2042ef  mov eax, dword ptr [esp + 0x1c]
1c2042f3  mov ebx, dword ptr [eax]
1c2042f5  test ebx, ebx
1c2042f7  je 0x1c204415
1c2042fd  cmp word ptr [ebx], 0x1e
1c204301  je 0x1c204415
1c204307  mov edi, dword ptr [esp + 0x14]
1c20430b  movsx ecx, word ptr [ebx]
1c20430e  sub ecx, 0x32
1c204311  cmp ecx, 0xc8
1c204317  ja 0x1c204408
1c20431d  xor eax, eax
1c20431f  mov al, byte ptr [ecx + 0x1c204434]
1c204325  jmp dword ptr [eax*4 + 0x1c20441c]
1c20432c  movsx eax, word ptr [ebx + 2]
1c204330  push eax
1c204331  push edi
1c204332  call 0x1c204680
1c204337  add esp, 8
1c20433a  jmp 0x1c204408
1c20433f  mov ax, word ptr [ebx + 2]
1c204343  mov word ptr [edi + 0xae], ax
1c20434a  jmp 0x1c204408
1c20434f  mov cx, word ptr [ebx + 2]
1c204353  test cx, cx
1c204356  jg 0x1c2043b1
1c204358  mov bp, word ptr [edi + 0xac]
1c20435f  imul bp, bp, 0xc
1c204363  add bp, word ptr [edi + 0xae]
1c20436a  sub bp, cx
1c20436d  cmp bp, 0x55
1c204371  jl 0x1c204387
1c204373  mov cx, 0xc
1c204377  lea eax, [ebp - 0x49]
1c20437a  sub dx, dx
1c20437d  div cx
1c204380  imul ax, cx
1c204384  sub bp, ax
1c204387  test bp, bp
1c20438a  jge 0x1c2043a4
1c20438c  mov ax, 0xb
1c204390  sub ax, bp
1c204393  mov cx, 0xc
1c204397  sub dx, dx
1c20439a  div cx
1c20439d  imul ax, cx
1c2043a1  add bp, ax
1c2043a4  movsx eax, bp
1c2043a7  mov cx, word ptr [eax*2 + 0x1c24c028]
1c2043af  jmp 0x1c2043c6
1c2043b1  cmp cx, 0x7d0
1c2043b6  jl 0x1c2043bc
1c2043b8  mov cx, 0x7d0
1c2043bc  cmp cx, 0xa
1c2043c0  jg 0x1c2043c6
1c2043c2  mov cx, 0xa
1c2043c6  mov dx, word ptr [ebx + 4]
1c2043ca  movsx eax, dx
1c2043cd  shl eax, 5
1c2043d0  add eax, esi
1c2043d2  cmp dx, word ptr [0x1c250566]
1c2043d9  jae 0x1c2043ed
1c2043db  mov word ptr [eax + 0x18], cx
1c2043df  add eax, 0x20
1c2043e2  inc dx
1c2043e4  cmp dx, word ptr [0x1c250566]
1c2043eb  jb 0x1c2043db
1c2043ed  mov word ptr [0x1c250560], cx
1c2043f4  jmp 0x1c204408
1c2043f6  mov ax, word ptr [ebx + 2]
1c2043fa  mov word ptr [edi + 0x4c], ax
1c2043fe  jmp 0x1c204408
1c204400  mov ax, word ptr [ebx + 2]
1c204404  mov word ptr [edi + 0x60], ax
1c204408  add ebx, 6
1c20440b  cmp word ptr [ebx], 0x1e
1c20440f  jne 0x1c20430b
1c204415  pop ebp
1c204416  pop edi
1c204417  pop esi
1c204418  pop ebx
1c204419  ret 
