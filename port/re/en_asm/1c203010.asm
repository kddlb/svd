1c203010  mov ecx, dword ptr [esp + 4]
1c203014  mov ax, word ptr [ecx + 0xc]
1c203018  cmp ax, 0xff
1c20301c  jne 0x1c203023
1c20301e  mov ax, 9
1c203022  ret 
1c203023  movzx edx, ax
1c203026  mov eax, edx
1c203028  lea edx, [edx + edx*4]
1c20302b  lea edx, [edx + edx*4]
1c20302e  add edx, eax
1c203030  mov eax, dword ptr [ecx + 4]
1c203033  mov eax, dword ptr [edx + eax + 2]
1c203037  test eax, 0x10000000
1c20303c  je 0x1c203042
1c20303e  xor ax, ax
1c203041  ret 
1c203042  test ah, 0x20
1c203045  je 0x1c20304c
1c203047  mov ax, 1
1c20304b  ret 
1c20304c  test ah, 0x80
1c20304f  je 0x1c203056
1c203051  mov ax, 2
1c203055  ret 
1c203056  test al, 0x40
1c203058  je 0x1c20306c
1c20305a  and eax, 0x8000000
1c20305f  cmp eax, 1
1c203062  sbb eax, eax
1c203064  and eax, 2
1c203067  add ax, 3
1c20306b  ret 
1c20306c  test eax, 0x40000
1c203071  je 0x1c203085
1c203073  and eax, 0x8000000
1c203078  cmp eax, 1
1c20307b  sbb eax, eax
1c20307d  and eax, 2
1c203080  add ax, 4
1c203084  ret 
1c203085  test al, 4
1c203087  je 0x1c20308e
1c203089  mov ax, 7
1c20308d  ret 
1c20308e  test eax, 0x20000000
1c203093  je 0x1c20309a
1c203095  mov ax, 9
1c203099  ret 
1c20309a  and eax, 0x100
1c20309f  cmp eax, 1
1c2030a2  mov eax, 9
1c2030a7  adc eax, -1
1c2030aa  ret 
