1c203770  push esi
1c203771  push edi
1c203772  mov esi, dword ptr [0x1c250e70]
1c203778  test esi, 0x10
1c20377e  je 0x1c203863
1c203784  xor ax, ax
1c203787  mov cl, byte ptr [0x1c250e7e]
1c20378d  movsx edx, ax
1c203790  cmp byte ptr [edx + edx*2 + 0x1c24c420], cl
1c203797  je 0x1c2037a1
1c203799  inc ax
1c20379b  cmp ax, 0x15
1c20379f  jl 0x1c20378d
1c2037a1  movsx eax, ax
1c2037a4  test esi, 0xc0000000
1c2037aa  movzx dx, byte ptr [eax + eax*2 + 0x1c24c421]
1c2037b3  movzx di, byte ptr [eax + eax*2 + 0x1c24c422]
1c2037bc  lea eax, [eax + eax*2]
1c2037bf  je 0x1c2037d2
1c2037c1  test byte ptr [0x1c2552fd], 0x20
1c2037c8  je 0x1c2037d2
1c2037ca  sub dx, 0xa
1c2037ce  sub di, 0xf
1c2037d2  cmp dx, 0x5f
1c2037d6  jl 0x1c2037dc
1c2037d8  mov dx, 0x5f
1c2037dc  test dx, dx
1c2037df  jg 0x1c2037e4
1c2037e1  xor dx, dx
1c2037e4  movsx eax, dx
1c2037e7  cmp di, 0x64
1c2037eb  jl 0x1c2037f1
1c2037ed  mov di, 0x64
1c2037f1  movsx edx, di
1c2037f4  lea esi, [eax + 5]
1c2037f7  cmp edx, esi
1c2037f9  jg 0x1c2037fd
1c2037fb  mov edx, esi
1c2037fd  mov dword ptr [0x1c2505e8], eax
1c203802  mov dword ptr [0x1c250708], eax
1c203807  mov dword ptr [0x1c250638], eax
1c20380c  mov dword ptr [0x1c250788], eax
1c203811  mov dword ptr [0x1c250678], eax
1c203816  mov dword ptr [0x1c2507c8], eax
1c20381b  movsx eax, dx
1c20381e  mov dword ptr [0x1c2505ec], eax
1c203823  mov dword ptr [0x1c25070c], eax
1c203828  mov dword ptr [0x1c25063c], eax
1c20382d  mov dword ptr [0x1c25078c], eax
1c203832  mov dword ptr [0x1c25067c], eax
1c203837  mov dword ptr [0x1c2507cc], eax
1c20383c  xor eax, eax
1c20383e  mov al, cl
1c203840  cmp eax, 0x23
1c203843  jne 0x1c203863
1c203845  mov eax, 0x32
1c20384a  mov dword ptr [0x1c2505e8], eax
1c20384f  mov dword ptr [0x1c250708], eax
1c203854  mov eax, 0x5f
1c203859  mov dword ptr [0x1c2505ec], eax
1c20385e  mov dword ptr [0x1c25070c], eax
1c203863  pop edi
1c203864  pop esi
1c203865  ret 
