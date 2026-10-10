1c00402c  push ebp
1c00402d  mov ebp, esp
1c00402f  push eax
1c004030  push ecx
1c004031  push edx
1c004032  push ebx
1c004033  push ebp
1c004034  push esi
1c004035  push edi
1c004036  pushfd 
1c004037  cld 
1c004038  mov ebx, dword ptr [ebp + 8]
1c00403b  mov ax, word ptr [ebp + 0xc]
1c00403f  mov word ptr [ebx + 0x2f4], ax
1c004046  mov edi, dword ptr [ebx + 0x15e]
1c00404c  mov ax, word ptr [ebx + 0x30e]
1c004053  cmp ax, 0
1c004057  je 0x1c0044a0
1c00405d  mov word ptr [ebx + 0x30e], 0
1c004066  xor eax, eax
1c004068  mov dword ptr [ebx + 0x1b2], eax
1c00406e  mov dword ptr [ebx + 0x1c6], eax
1c004074  mov dword ptr [ebx + 0x1da], eax
1c00407a  mov dword ptr [ebx + 0x1ee], eax
1c004080  mov dword ptr [ebx + 0x202], eax
1c004086  mov dword ptr [ebx + 0x216], eax
1c00408c  mov dword ptr [ebx + 0x22a], eax
1c004092  mov dword ptr [ebx + 0x23e], eax
1c004098  mov dword ptr [ebx + 0x252], eax
1c00409e  mov dword ptr [ebx + 0x28a], eax
1c0040a4  mov dword ptr [ebx + 0x282], eax
1c0040aa  mov dword ptr [ebx + 0x292], eax
1c0040b0  mov dword ptr [ebx + 0x2aa], eax
1c0040b6  mov dword ptr [ebx + 0x2fc], eax
1c0040bc  mov word ptr [ebx + 0x2ee], 0x3ff
1c0040c5  mov dword ptr [ebx + 0x300], 0x20000
1c0040cf  mov edx, dword ptr [ebx + 0x300]
1c0040d5  mov eax, dword ptr [ebx + 0xf6]
1c0040db  add eax, 0x80
1c0040e0  mov dword ptr [ebx + 0xfa], eax
1c0040e6  jmp 0x1c0040f9
1c0040e8  mov dword ptr [ebx + 0xfa], eax
1c0040ee  add eax, 0x20
1c0040f1  mov esi, eax
1c0040f3  test byte ptr [esi + 0x17], 2
1c0040f7  je 0x1c0040e8
1c0040f9  mov dword ptr [ebx + 0xfe], 0x40
1c004103  lea esi, [0x1c001570]
1c004109  mov dword ptr [ebx + 0x2e4], esi
1c00410f  mov esi, dword ptr [ebx + 0x2c0]
1c004115  mov dword ptr [ebx + 0x2e8], esi
1c00411b  jmp 0x1c0044cb
1c004120  mov edx, dword ptr [ebx + 0x2fc]
1c004126  add edx, dword ptr [ebx + 0x300]
1c00412c  and edx, 0x3ffffff
1c004132  mov dword ptr [ebx + 0x2fc], edx
1c004138  mov ax, dx
1c00413b  shr edx, 0x10
1c00413e  shl edx, 1
1c004140  mov esi, dword ptr [ebx + 0x2d8]
1c004146  add esi, edx
1c004148  mov ax, word ptr [esi]
1c00414b  imul word ptr [ebx + 0x268]
1c004152  shld dx, ax, 1
1c004157  mov cx, dx
1c00415a  push cx
1c00415c  mov edx, dword ptr [ebx + 0x2fc]
1c004162  mov ax, dx
1c004165  shr edx, 0x10
1c004168  shl edx, 1
1c00416a  mov esi, dword ptr [ebx + 0x2dc]
1c004170  add esi, edx
1c004172  mov ax, word ptr [esi]
1c004175  imul word ptr [ebx + 0x270]
1c00417c  shld dx, ax, 1
1c004181  pop ax
1c004183  add ax, dx
1c004186  imul word ptr [ebx + 0x278]
1c00418d  shld dx, ax, 1
1c004192  mov eax, dword ptr [ebx + 0x27a]
1c004198  add dword ptr [ebx + 0x276], eax
1c00419e  cmp dx, 0
1c0041a2  jge 0x1c0041b4
1c0041a4  mov ax, word ptr [ebx + 0x298]
1c0041ab  mov cx, word ptr [ebx + 0x2a0]
1c0041b2  jmp 0x1c0041c2
1c0041b4  mov ax, word ptr [ebx + 0x29c]
1c0041bb  mov cx, word ptr [ebx + 0x2a4]
1c0041c2  mov word ptr [ebx + 0x280], ax
1c0041c9  mov word ptr [ebx + 0x288], cx
1c0041d0  ror edx, 0x10
1c0041d3  xor dx, dx
1c0041d6  mov ecx, edx
1c0041d8  xchg dword ptr [ebx + 0x2aa], edx
1c0041de  sub ecx, edx
1c0041e0  shl ecx, 1
1c0041e2  ror ecx, 0x10
1c0041e5  mov eax, dword ptr [ebx + 0x23e]
1c0041eb  mov word ptr [ebx + 0x240], ax
1c0041f2  sub ax, cx
1c0041f5  imul word ptr [ebx + 0x244]
1c0041fc  shld dx, ax, 2
1c004201  ror eax, 0x10
1c004204  ror edx, 0x10
1c004207  sub ax, cx
1c00420a  imul word ptr [ebx + 0x24c]
1c004211  shld dx, ax, 1
1c004216  sub cx, dx
1c004219  ror edx, 0x10
1c00421c  add cx, dx
1c00421f  mov word ptr [ebx + 0x23e], cx
1c004226  mov eax, dword ptr [ebx + 0x246]
1c00422c  add dword ptr [ebx + 0x242], eax
1c004232  mov eax, dword ptr [ebx + 0x24e]
1c004238  add dword ptr [ebx + 0x24a], eax
1c00423e  mov esi, dword ptr [ebx + 0x2e4]
1c004244  lodsw ax, word ptr [esi]
1c004246  imul word ptr [ebx + 0x280]
1c00424d  shld dx, ax, 1
1c004252  add cx, dx
1c004255  mov eax, dword ptr [ebx + 0x202]
1c00425b  mov word ptr [ebx + 0x204], ax
1c004262  sub ax, cx
1c004265  imul word ptr [ebx + 0x208]
1c00426c  shld dx, ax, 2
1c004271  ror eax, 0x10
1c004274  ror edx, 0x10
1c004277  sub ax, cx
1c00427a  imul word ptr [ebx + 0x210]
1c004281  shld dx, ax, 1
1c004286  sub cx, dx
1c004289  ror edx, 0x10
1c00428c  add cx, dx
1c00428f  mov word ptr [ebx + 0x202], cx
1c004296  mov eax, dword ptr [ebx + 0x1b2]
1c00429c  mov word ptr [ebx + 0x1b4], ax
1c0042a3  sub ax, cx
1c0042a6  imul word ptr [ebx + 0x1b8]
1c0042ad  shld dx, ax, 2
1c0042b2  ror eax, 0x10
1c0042b5  ror edx, 0x10
1c0042b8  sub ax, cx
1c0042bb  imul word ptr [ebx + 0x1c0]
1c0042c2  shld dx, ax, 1
1c0042c7  sub cx, dx
1c0042ca  ror edx, 0x10
1c0042cd  add cx, dx
1c0042d0  mov word ptr [ebx + 0x1b2], cx
1c0042d7  mov eax, dword ptr [ebx + 0x1ba]
1c0042dd  add dword ptr [ebx + 0x1b6], eax
1c0042e3  mov eax, dword ptr [ebx + 0x1c2]
1c0042e9  add dword ptr [ebx + 0x1be], eax
1c0042ef  mov eax, dword ptr [ebx + 0x1da]
1c0042f5  mov word ptr [ebx + 0x1dc], ax
1c0042fc  sub ax, cx
1c0042ff  imul word ptr [ebx + 0x1e0]
1c004306  shld dx, ax, 2
1c00430b  ror eax, 0x10
1c00430e  ror edx, 0x10
1c004311  sub ax, cx
1c004314  imul word ptr [ebx + 0x1e8]
1c00431b  shld dx, ax, 1
1c004320  sub cx, dx
1c004323  ror edx, 0x10
1c004326  add cx, dx
1c004329  mov word ptr [ebx + 0x1da], cx
1c004330  mov eax, dword ptr [ebx + 0x1e2]
1c004336  add dword ptr [ebx + 0x1de], eax
1c00433c  mov eax, dword ptr [ebx + 0x1ea]
1c004342  add dword ptr [ebx + 0x1e6], eax
1c004348  mov eax, dword ptr [ebx + 0x1ee]
1c00434e  mov word ptr [ebx + 0x1f0], ax
1c004355  sub ax, cx
1c004358  imul word ptr [ebx + 0x1f4]
1c00435f  shld dx, ax, 2
1c004364  ror eax, 0x10
1c004367  ror edx, 0x10
1c00436a  sub ax, cx
1c00436d  imul word ptr [ebx + 0x1fc]
1c004374  shld dx, ax, 1
1c004379  sub cx, dx
1c00437c  ror edx, 0x10
1c00437f  add cx, dx
1c004382  mov word ptr [ebx + 0x1ee], cx
1c004389  mov eax, dword ptr [ebx + 0x1c6]
1c00438f  mov word ptr [ebx + 0x1c8], ax
1c004396  sub ax, cx
1c004399  imul word ptr [ebx + 0x1cc]
1c0043a0  shld dx, ax, 2
1c0043a5  ror eax, 0x10
1c0043a8  ror edx, 0x10
1c0043ab  sub ax, cx
1c0043ae  imul word ptr [ebx + 0x1d4]
1c0043b5  shld dx, ax, 1
1c0043ba  sub cx, dx
1c0043bd  ror edx, 0x10
1c0043c0  add cx, dx
1c0043c3  mov word ptr [ebx + 0x1c6], cx
1c0043ca  mov eax, dword ptr [ebx + 0x1ce]
1c0043d0  add dword ptr [ebx + 0x1ca], eax
1c0043d6  mov eax, dword ptr [ebx + 0x1d6]
1c0043dc  add dword ptr [ebx + 0x1d2], eax
1c0043e2  push cx
1c0043e4  lodsw ax, word ptr [esi]
1c0043e6  mov dword ptr [ebx + 0x2e4], esi
1c0043ec  sar ax, 2
1c0043f0  push ax
1c0043f2  mov cx, ax
1c0043f5  mov eax, dword ptr [ebx + 0x216]
1c0043fb  mov word ptr [ebx + 0x218], ax
1c004402  sub ax, cx
1c004405  imul word ptr [ebx + 0x21c]
1c00440c  shld dx, ax, 2
1c004411  ror eax, 0x10
1c004414  ror edx, 0x10
1c004417  sub ax, cx
1c00441a  imul word ptr [ebx + 0x224]
1c004421  shld dx, ax, 1
1c004426  sub cx, dx
1c004429  ror edx, 0x10
1c00442c  add cx, dx
1c00442f  mov word ptr [ebx + 0x216], cx
1c004436  mov ax, cx
1c004439  imul word ptr [ebx + 0x290]
1c004440  shld dx, ax, 1
1c004445  pop ax
1c004447  sar ax, 5
1c00444b  xchg dx, ax
1c00444d  sub ax, dx
1c004450  imul word ptr [ebx + 0x288]
1c004457  shld dx, ax, 1
1c00445c  shld dx, ax, 3
1c004461  pop ax
1c004463  add ax, dx
1c004466  sar ax, 5
1c00446a  cmp ax, 0xff38
1c00446e  jg 0x1c004476
1c004470  mov ax, 0xff38
1c004474  jmp 0x1c004480
1c004476  cmp ax, 0xc8
1c00447a  jl 0x1c004480
1c00447c  mov ax, 0xc8
1c004480  mov ecx, esi
1c004482  movsx esi, ax
1c004485  mov ax, word ptr [esi + 0x1c0011c6]
1c00448c  mov esi, ecx
1c00448e  add ax, 0x80
1c004492  stosb byte ptr es:[edi], al
1c004493  dec word ptr [ebx + 0x2f4]
1c00449a  je 0x1c004985
1c0044a0  dec word ptr [ebx + 0x2ee]
1c0044a7  jne 0x1c0044be
1c0044a9  mov word ptr [ebx + 0x2ee], 0x3ff
1c0044b2  lea esi, [0x1c001570]
1c0044b8  mov dword ptr [ebx + 0x2e4], esi
1c0044be  dec word ptr [ebx + 0x30c]
1c0044c5  jne 0x1c004120
1c0044cb  push edi
1c0044cc  mov esi, dword ptr [ebx + 0xfa]
1c0044d2  add esi, 0x20
1c0044d5  cmp byte ptr [esi], 0xff
1c0044d8  je 0x1c00496e
1c0044de  cmp byte ptr [esi - 0x35], 1
1c0044e2  je 0x1c00496e
1c0044e8  cmp byte ptr [esi - 0x35], 2
1c0044ec  je 0x1c00496e
1c0044f2  mov dword ptr [ebx + 0xfa], esi
1c0044f8  mov eax, dword ptr [ebx + 0x48]
1c0044fb  mul word ptr [0x1c0120e8]
1c004502  div word ptr [0x1c0120ea]
1c004509  xor dx, dx
1c00450c  movzx cx, byte ptr [esi + 0xa]
1c004511  shl cx, 1
1c004514  div cx
1c004517  shr ax, 1
1c00451a  mov word ptr [ebx + 0x2bc], ax
1c004521  mov dx, 1
1c004525  xor ax, ax
1c004528  idiv word ptr [ebx + 0x2bc]
1c00452f  mov word ptr [ebx + 0x2fa], ax
1c004536  test dword ptr [ebx + 0x4e], 0x40
1c00453d  jne 0x1c004608
1c004543  xor ecx, ecx
1c004545  test dword ptr [ebx + 0x4e], 8
1c00454c  je 0x1c004571
1c00454e  movzx cx, byte ptr [esi + 0x1a]
1c004553  cmp cl, byte ptr [ebx + 0x312]
1c004559  je 0x1c004571
1c00455b  mov byte ptr [ebx + 0x312], cl
1c004561  push ecx
1c004562  push cx
1c004564  push 0x3f0
1c004569  call 0x1c00498f
1c00456e  add esp, 0xa
1c004571  test dword ptr [ebx + 0x4e], 4
1c004578  je 0x1c004595
1c00457a  test byte ptr [esi + 0x17], 1
1c00457e  je 0x1c004595
1c004580  movzx cx, byte ptr [esi + 0xb]
1c004585  push ecx
1c004586  push cx
1c004588  push 0x3ee
1c00458d  call 0x1c00498f
1c004592  add esp, 0xa
1c004595  test dword ptr [ebx + 0x4e], 2
1c00459c  je 0x1c0045b4
1c00459e  test byte ptr [esi + 0x17], 4
1c0045a2  je 0x1c0045b4
1c0045a4  push ecx
1c0045a5  push cx
1c0045a7  push 0x3ed
1c0045ac  call 0x1c00498f
1c0045b1  add esp, 0xa
1c0045b4  test dword ptr [ebx + 0x4e], 1
1c0045bb  je 0x1c0045d3
1c0045bd  test byte ptr [esi + 0x17], 2
1c0045c1  je 0x1c0045d3
1c0045c3  push ecx
1c0045c4  push cx
1c0045c6  push 0x3ec
1c0045cb  call 0x1c00498f
1c0045d0  add esp, 0xa
1c0045d3  test byte ptr [esi + 0x17], 8
1c0045d7  je 0x1c0045ee
1c0045d9  movzx cx, byte ptr [esi + 0x1b]
1c0045de  push ecx
1c0045df  push cx
1c0045e1  push 0x3ef
1c0045e6  call 0x1c00498f
1c0045eb  add esp, 0xa
1c0045ee  test byte ptr [esi + 0x17], 0x20
1c0045f2  je 0x1c004608
1c0045f4  mov cx, word ptr [esi + 0x1c]
1c0045f8  push ecx
1c0045f9  push cx
1c0045fb  push 0x3eb
1c004600  call 0x1c00498f
1c004605  add esp, 0xa
1c004608  nop 
1c004609  mov ax, 0xfa00
1c00460d  mul word ptr [ebx + 0x2bc]
1c004614  div word ptr [ebx + 0x48]
1c004618  cwde 
1c004619  mov edx, dword ptr [ebx + 0xfe]
1c00461f  add edx, eax
1c004621  mov dword ptr [ebx + 0xfe], edx
1c004627  movzx edi, byte ptr [esi + 7]
1c00462b  and edi, 0xf
1c00462e  shl edi, 1
1c004630  mov ax, word ptr [edi + 0x1c0036b0]
1c004637  sub ax, word ptr [ebx + 0x244]
1c00463e  imul word ptr [ebx + 0x2fa]
1c004645  mov word ptr [ebx + 0x246], ax
1c00464c  mov word ptr [ebx + 0x248], dx
1c004653  mov ax, word ptr [edi + 0x1c0036d0]
1c00465a  sub ax, word ptr [ebx + 0x24c]
1c004661  imul word ptr [ebx + 0x2fa]
1c004668  mov word ptr [ebx + 0x24e], ax
1c00466f  mov word ptr [ebx + 0x250], dx
1c004676  movzx eax, word ptr [esi + 0x18]
1c00467a  ror eax, 0x10
1c00467d  shr eax, 7
1c004680  mov dword ptr [ebx + 0x300], eax
1c004686  movzx ecx, byte ptr [esi + 6]
1c00468a  mov edi, ecx
1c00468c  shr edi, 4
1c00468f  shl edi, 1
1c004691  mov ax, word ptr [edi + 0x1c003070]
1c004698  sub ax, word ptr [ebx + 0x1c0]
1c00469f  imul word ptr [ebx + 0x2fa]
1c0046a6  mov word ptr [ebx + 0x1c2], ax
1c0046ad  mov word ptr [ebx + 0x1c4], dx
1c0046b4  movzx ax, byte ptr [esi]
1c0046b8  shl ax, 5
1c0046bc  or di, ax
1c0046bf  mov ax, word ptr [edi + 0x1c002570]
1c0046c6  sub ax, word ptr [ebx + 0x1b8]
1c0046cd  imul word ptr [ebx + 0x2fa]
1c0046d4  mov word ptr [ebx + 0x1ba], ax
1c0046db  mov word ptr [ebx + 0x1bc], dx
1c0046e2  mov edi, ecx
1c0046e4  and edi, 0xf
1c0046e7  shl edi, 1
1c0046e9  mov ax, word ptr [edi + 0x1c003070]
1c0046f0  sub ax, word ptr [ebx + 0x1d4]
1c0046f7  imul word ptr [ebx + 0x2fa]
1c0046fe  mov word ptr [ebx + 0x1d6], ax
1c004705  mov word ptr [ebx + 0x1d8], dx
1c00470c  movzx ax, byte ptr [esi + 1]
1c004711  shl ax, 5
1c004715  or di, ax
1c004718  mov ax, word ptr [edi + 0x1c002570]
1c00471f  sub ax, word ptr [ebx + 0x1cc]
1c004726  imul word ptr [ebx + 0x2fa]
1c00472d  mov word ptr [ebx + 0x1ce], ax
1c004734  mov word ptr [ebx + 0x1d0], dx
1c00473b  movzx ecx, byte ptr [esi + 7]
1c00473f  mov edi, ecx
1c004741  shr edi, 4
1c004744  shl edi, 1
1c004746  mov ax, word ptr [edi + 0x1c003070]
1c00474d  sub ax, word ptr [ebx + 0x1e8]
1c004754  imul word ptr [ebx + 0x2fa]
1c00475b  mov word ptr [ebx + 0x1ea], ax
1c004762  mov word ptr [ebx + 0x1ec], dx
1c004769  movzx ax, byte ptr [esi + 2]
1c00476e  shl ax, 5
1c004772  or di, ax
1c004775  mov ax, word ptr [edi + 0x1c002570]
1c00477c  sub ax, word ptr [ebx + 0x1e0]
1c004783  imul word ptr [ebx + 0x2fa]
1c00478a  mov word ptr [ebx + 0x1e2], ax
1c004791  mov word ptr [ebx + 0x1e4], dx
1c004798  movzx ecx, byte ptr [esi + 8]
1c00479c  mov edi, ecx
1c00479e  shr edi, 4
1c0047a1  shl edi, 1
1c0047a3  movzx eax, word ptr [edi + 0x1c003690]
1c0047aa  ror eax, 0x10
1c0047ad  mov dword ptr [ebx + 0x1fa], eax
1c0047b3  movzx ax, byte ptr [esi + 3]
1c0047b8  shl ax, 5
1c0047bc  or di, ax
1c0047bf  movzx eax, word ptr [edi + 0x1c003090]
1c0047c6  ror eax, 0x10
1c0047c9  mov dword ptr [ebx + 0x1f2], eax
1c0047cf  mov edi, ecx
1c0047d1  and edi, 0xf
1c0047d4  shl edi, 1
1c0047d6  movzx eax, word ptr [edi + 0x1c003690]
1c0047dd  ror eax, 0x10
1c0047e0  mov dword ptr [ebx + 0x20e], eax
1c0047e6  movzx ax, byte ptr [esi + 4]
1c0047eb  shl ax, 5
1c0047ef  or di, ax
1c0047f2  movzx eax, word ptr [edi + 0x1c003090]
1c0047f9  ror eax, 0x10
1c0047fc  mov dword ptr [ebx + 0x206], eax
1c004802  movzx ecx, byte ptr [esi + 0x14]
1c004806  mov edi, ecx
1c004808  shr edi, 4
1c00480b  shl edi, 1
1c00480d  movzx eax, word ptr [edi + 0x1c003690]
1c004814  ror eax, 0x10
1c004817  mov dword ptr [ebx + 0x222], eax
1c00481d  movzx ax, byte ptr [esi + 9]
1c004822  shl ax, 5
1c004826  or di, ax
1c004829  movzx eax, word ptr [edi + 0x1c003090]
1c004830  ror eax, 0x10
1c004833  mov dword ptr [ebx + 0x21a], eax
1c004839  movzx di, byte ptr [esi + 0xf]
1c00483e  shl di, 7
1c004842  mov word ptr [ebx + 0x268], di
1c004849  mov ax, 0x7f80
1c00484d  sub ax, di
1c004850  mov word ptr [ebx + 0x270], ax
1c004857  movzx edi, byte ptr [esi + 0x10]
1c00485b  mov ax, word ptr [edi + 0x1c001308]
1c004862  sub ax, word ptr [ebx + 0x278]
1c004869  imul word ptr [ebx + 0x2fa]
1c004870  mov word ptr [ebx + 0x27a], ax
1c004877  mov word ptr [ebx + 0x27c], dx
1c00487e  movzx edi, byte ptr [esi + 0x11]
1c004882  movzx eax, word ptr [edi + 0x1c001308]
1c004889  ror eax, 0x10
1c00488c  mov dword ptr [ebx + 0x27e], eax
1c004892  mov dword ptr [ebx + 0x296], eax
1c004898  mov dword ptr [ebx + 0x29a], eax
1c00489e  movzx edi, byte ptr [esi + 0x12]
1c0048a2  movzx eax, word ptr [edi + 0x1c001308]
1c0048a9  ror eax, 0x10
1c0048ac  mov dword ptr [ebx + 0x286], eax
1c0048b2  mov dword ptr [ebx + 0x29e], eax
1c0048b8  mov dword ptr [ebx + 0x2a2], eax
1c0048be  movzx edi, byte ptr [esi + 0x13]
1c0048c2  xor eax, eax
1c0048c4  sub ax, word ptr [edi + 0x1c001308]
1c0048cb  add ax, 0x101d
1c0048cf  ror eax, 0x10
1c0048d2  mov dword ptr [ebx + 0x28e], eax
1c0048d8  cmp byte ptr [esi + 0x10], 0x3c
1c0048dc  jb 0x1c0048fc
1c0048de  mov eax, dword ptr [ebx + 0x296]
1c0048e4  shr eax, 3
1c0048e7  mov dword ptr [ebx + 0x29a], eax
1c0048ed  mov eax, dword ptr [ebx + 0x29e]
1c0048f3  shr eax, 4
1c0048f6  mov dword ptr [ebx + 0x2a2], eax
1c0048fc  cmp byte ptr [esi + 0x10], 0xe
1c004900  ja 0x1c004934
1c004902  cmp byte ptr [esi + 0x11], 0xe
1c004906  ja 0x1c004934
1c004908  cmp byte ptr [esi - 0x10], 0xe
1c00490c  ja 0x1c004934
1c00490e  cmp byte ptr [esi - 0xf], 0xe
1c004912  ja 0x1c004934
1c004914  xor eax, eax
1c004916  mov dword ptr [ebx + 0x1b2], eax
1c00491c  mov dword ptr [ebx + 0x1c6], eax
1c004922  mov dword ptr [ebx + 0x1da], eax
1c004928  mov dword ptr [ebx + 0x1ee], eax
1c00492e  mov dword ptr [ebx + 0x23e], eax
1c004934  movzx edi, byte ptr [esi + 0xd]
1c004938  shl edi, 2
1c00493b  mov eax, dword ptr [edi + 0x1c013bd0]
1c004941  mov dword ptr [ebx + 0x2d8], eax
1c004947  movzx edi, byte ptr [esi + 0xe]
1c00494b  shl edi, 2
1c00494e  mov eax, dword ptr [edi + 0x1c013bd0]
1c004954  mov dword ptr [ebx + 0x2dc], eax
1c00495a  pop edi
1c00495b  mov ax, word ptr [ebx + 0x2bc]
1c004962  mov word ptr [ebx + 0x30c], ax
1c004969  jmp 0x1c004120
1c00496e  pop edi
1c00496f  xor ecx, ecx
1c004971  mov cx, word ptr [ebx + 0x2f4]
1c004978  mov al, 0x80
1c00497a  rep stosb byte ptr es:[edi], al
1c00497c  mov word ptr [ebx + 0x314], 0
1c004985  popfd 
1c004986  pop edi
1c004987  pop esi
1c004988  pop ebp
1c004989  pop ebx
1c00498a  pop edx
1c00498b  pop ecx
1c00498c  pop eax
1c00498d  leave 
1c00498e  ret 
1c00498f  push ebp
1c004990  mov ebp, esp
1c004992  push esi
1c004993  push edi
1c004994  mov edi, dword ptr [ebx]
1c004996  mov esi, dword ptr [edi + 0xa4]
1c00499c  movzx eax, word ptr [esi]
1c00499f  inc word ptr [esi]
1c0049a2  cmp eax, 0x63
1c0049a7  jb 0x1c0049ae
1c0049a9  mov word ptr [esi], 0
1c0049ae  add esi, 0xc84
1c0049b4  add esi, eax
1c0049b6  mov byte ptr [esi], 1
1c0049b9  sub esi, eax
1c0049bb  sub esi, 0xc84
1c0049c1  mov dx, 0x20
1c0049c5  mul dx
1c0049c8  movzx eax, ax
1c0049cb  add esi, 4
1c0049ce  add esi, eax
1c0049d0  mov dword ptr [esi], edi
1c0049d2  mov ax, word ptr [ebp + 8]
1c0049d6  mov word ptr [esi + 8], ax
1c0049da  mov edx, dword ptr [ebx + 0xfe]
1c0049e0  shr edx, 6
1c0049e3  mov dword ptr [esi + 4], edx
1c0049e6  mov ax, word ptr [ebp + 0xc]
1c0049ea  mov word ptr [esi + 0xa], ax
1c0049ee  mov eax, dword ptr [ebp + 0xe]
1c0049f1  mov dword ptr [esi + 0xc], eax
1c0049f4  mov eax, dword ptr [ebx + 8]
1c0049f7  mov dword ptr [esi + 0x14], eax
1c0049fa  mov eax, dword ptr [edi + 0xc8]
1c004a00  mov dword ptr [esi + 0x10], eax
1c004a03  pop edi
1c004a04  pop esi
1c004a05  leave 
1c004a06  ret 
1c004a07  int3 
1c004a08  int3 
1c004a09  int3 
1c004a0a  int3 
1c004a0b  int3 
1c004a0c  int3 
1c004a0d  int3 
1c004a0e  int3 
1c004a0f  int3 