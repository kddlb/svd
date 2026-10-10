1c4019c0  sub esp, 4
1c4019c3  test dword ptr [0x1c412ac0], 0x10002000
1c4019cd  push ebx
1c4019ce  push esi
1c4019cf  push edi
1c4019d0  push ebp
1c4019d1  je 0x1c401a1f
1c4019d3  test byte ptr [0x1c412ac0], 0x10
1c4019da  jne 0x1c401a1f
1c4019dc  xor eax, eax
1c4019de  mov dword ptr [0x1c412238], eax
1c4019e3  mov dword ptr [0x1c412358], eax
1c4019e8  mov dword ptr [0x1c412288], eax
1c4019ed  mov dword ptr [0x1c4123d8], eax
1c4019f2  mov dword ptr [0x1c4122c8], eax
1c4019f7  mov dword ptr [0x1c412418], eax
1c4019fc  mov eax, 0x64
1c401a01  mov dword ptr [0x1c41223c], eax
1c401a06  mov dword ptr [0x1c41235c], eax
1c401a0b  mov dword ptr [0x1c41228c], eax
1c401a10  mov dword ptr [0x1c4123dc], eax
1c401a15  mov dword ptr [0x1c4122cc], eax
1c401a1a  mov dword ptr [0x1c41241c], eax
1c401a1f  push 0x1c412320
1c401a24  call 0x1c402c30
1c401a29  add esp, 4
1c401a2c  push 0x1c412200
1c401a31  call 0x1c402c30
1c401a36  add esp, 4
1c401a39  push 0x1c4123a0
1c401a3e  call 0x1c402c30
1c401a43  add esp, 4
1c401a46  push 0x1c412250
1c401a4b  call 0x1c402c30
1c401a50  add esp, 4
1c401a53  push 0x1c4123e0
1c401a58  call 0x1c402c30
1c401a5d  add esp, 4
1c401a60  push 0x1c412290
1c401a65  call 0x1c402c30
1c401a6a  add esp, 4
1c401a6d  cmp byte ptr [0x1c412460], 0x4b
1c401a74  je 0x1c401a89
1c401a76  cmp byte ptr [0x1c412460], 0x4c
1c401a7d  je 0x1c401a89
1c401a7f  movzx ax, byte ptr [0x1c412460]
1c401a87  jmp 0x1c401a91
1c401a89  movzx ax, byte ptr [0x1c412604]
1c401a91  movsx edx, ax
1c401a94  lea ebx, [edx + edx*4]
1c401a97  mov ecx, dword ptr [esp + 0x18]
1c401a9b  mov eax, edx
1c401a9d  lea edx, [ebx + ebx*4]
1c401aa0  add edx, eax
1c401aa2  add edx, dword ptr [ecx + 4]
1c401aa5  movsx eax, word ptr [edx + 6]
1c401aa9  mov dword ptr [0x1c412338], eax
1c401aae  movsx ebx, word ptr [edx + 0xc]
1c401ab2  mov dword ptr [0x1c412218], ebx
1c401ab8  movsx ebp, word ptr [edx + 8]
1c401abc  mov dword ptr [0x1c4123b8], ebp
1c401ac2  movsx eax, word ptr [edx + 0xe]
1c401ac6  mov dword ptr [0x1c412268], eax
1c401acb  test byte ptr [0x1c416f4c], 0x10
1c401ad2  movsx ebx, word ptr [edx + 0xa]
1c401ad6  mov dword ptr [0x1c4123f8], ebx
1c401adc  movsx ebp, word ptr [edx + 0x10]
1c401ae0  mov dword ptr [0x1c4122a8], ebp
1c401ae6  je 0x1c401b2a
1c401ae8  movsx eax, word ptr [edx + 0x20]
1c401aec  add edx, 0x1a
1c401aef  mov dword ptr [0x1c41233c], eax
1c401af4  movsx ebx, word ptr [edx + 0xc]
1c401af8  mov dword ptr [0x1c41221c], ebx
1c401afe  movsx ebp, word ptr [edx + 8]
1c401b02  mov dword ptr [0x1c4123bc], ebp
1c401b08  sub edx, 0x1a
1c401b0b  movsx eax, word ptr [edx + 0x28]
1c401b0f  mov dword ptr [0x1c41226c], eax
1c401b14  movsx ebx, word ptr [edx + 0x24]
1c401b18  mov dword ptr [0x1c4123fc], ebx
1c401b1e  movsx ebp, word ptr [edx + 0x2a]
1c401b22  mov dword ptr [0x1c4122ac], ebp
1c401b28  jmp 0x1c401b6e
1c401b2a  mov eax, dword ptr [0x1c412338]
1c401b2f  mov ebx, dword ptr [0x1c412218]
1c401b35  mov ebp, dword ptr [0x1c4123b8]
1c401b3b  mov dword ptr [0x1c41233c], eax
1c401b40  mov eax, dword ptr [0x1c412268]
1c401b45  mov dword ptr [0x1c41221c], ebx
1c401b4b  mov ebx, dword ptr [0x1c4123f8]
1c401b51  mov dword ptr [0x1c4123bc], ebp
1c401b57  mov ebp, dword ptr [0x1c4122a8]
1c401b5d  mov dword ptr [0x1c41226c], eax
1c401b62  mov dword ptr [0x1c4123fc], ebx
1c401b68  mov dword ptr [0x1c4122ac], ebp
1c401b6e  cmp byte ptr [0x1c412460], 0x4b
1c401b75  je 0x1c401b84
1c401b77  cmp byte ptr [0x1c412460], 0x4c
1c401b7e  jne 0x1c401c13
1c401b84  movsx eax, word ptr [edx + 0xc]
1c401b88  add eax, 0xc8
1c401b8d  mov dword ptr [0x1c41221c], eax
1c401b92  mov dword ptr [0x1c412218], eax
1c401b97  movsx eax, word ptr [edx + 0xe]
1c401b9b  add eax, 0x28
1c401b9e  cmp eax, 0xc8
1c401ba3  jg 0x1c401baa
1c401ba5  mov eax, 0xc8
1c401baa  mov dword ptr [0x1c41226c], eax
1c401baf  mov dword ptr [0x1c412268], eax
1c401bb4  movsx eax, word ptr [edx + 0x10]
1c401bb8  add eax, 0x3c
1c401bbb  cmp eax, 0x12c
1c401bc0  jg 0x1c401bc7
1c401bc2  mov eax, 0x12c
1c401bc7  mov dword ptr [0x1c4122ac], eax
1c401bcc  mov dword ptr [0x1c4122a8], eax
1c401bd1  test byte ptr [0x1c412ac3], 0x20
1c401bd8  jne 0x1c401c13
1c401bda  mov eax, dword ptr [0x1c41233c]
1c401bdf  add eax, dword ptr [0x1c41232c]
1c401be5  sar eax, 1
1c401be8  mov dword ptr [0x1c412338], eax
1c401bed  mov eax, dword ptr [0x1c4123ac]
1c401bf2  add eax, dword ptr [0x1c4123bc]
1c401bf8  sar eax, 1
1c401bfb  mov dword ptr [0x1c4123b8], eax
1c401c00  mov eax, dword ptr [0x1c4123fc]
1c401c05  add eax, dword ptr [0x1c4123ec]
1c401c0b  sar eax, 1
1c401c0e  mov dword ptr [0x1c4123f8], eax
1c401c13  test byte ptr [0x1c416f4f], 0x20
1c401c1a  je 0x1c401c60
1c401c1c  mov eax, dword ptr [0x1c41232c]
1c401c21  mov edx, dword ptr [0x1c41220c]
1c401c27  mov ebx, dword ptr [0x1c4123ac]
1c401c2d  mov dword ptr [0x1c412338], eax
1c401c32  mov eax, dword ptr [0x1c41225c]
1c401c37  mov dword ptr [0x1c412218], edx
1c401c3d  mov edx, dword ptr [0x1c4123ec]
1c401c43  mov dword ptr [0x1c4123b8], ebx
1c401c49  mov ebx, dword ptr [0x1c41229c]
1c401c4f  mov dword ptr [0x1c412268], eax
1c401c54  mov dword ptr [0x1c4123f8], edx
1c401c5a  mov dword ptr [0x1c4122a8], ebx
1c401c60  test byte ptr [0x1c412ac3], 0x20
1c401c67  je 0x1c401cad
1c401c69  mov eax, dword ptr [0x1c412338]
1c401c6e  mov edx, dword ptr [0x1c41221c]
1c401c74  mov ebx, dword ptr [0x1c4123b8]
1c401c7a  mov dword ptr [0x1c41232c], eax
1c401c7f  mov eax, dword ptr [0x1c41226c]
1c401c84  mov dword ptr [0x1c41220c], edx
1c401c8a  mov edx, dword ptr [0x1c4123f8]
1c401c90  mov dword ptr [0x1c4123ac], ebx
1c401c96  mov ebx, dword ptr [0x1c4122ac]
1c401c9c  mov dword ptr [0x1c41225c], eax
1c401ca1  mov dword ptr [0x1c4123ec], edx
1c401ca7  mov dword ptr [0x1c41229c], ebx
1c401cad  test byte ptr [0x1c416f4f], 0x10
1c401cb4  je 0x1c401da1
1c401cba  test byte ptr [0x1c416f4c], 0x80
1c401cc1  je 0x1c401cdf
1c401cc3  test byte ptr [0x1c416f4d], 0x10
1c401cca  je 0x1c401cdf
1c401ccc  test byte ptr [0x1c412aaf], 4
1c401cd3  je 0x1c401cdf
1c401cd5  mov eax, dword ptr [0x1c4123b8]
1c401cda  mov dword ptr [0x1c4123bc], eax
1c401cdf  test dword ptr [0x1c416f4c], 0x40000080
1c401ce9  je 0x1c401cfe
1c401ceb  test byte ptr [0x1c412aad], 8
1c401cf2  je 0x1c401cfe
1c401cf4  sub dword ptr [0x1c4123bc], 0x12c
1c401cfe  test byte ptr [0x1c416f4f], 0x40
1c401d05  je 0x1c401d1a
1c401d07  test byte ptr [0x1c412aac], 2
1c401d0e  je 0x1c401d1a
1c401d10  sub dword ptr [0x1c4123bc], 0x96
1c401d1a  cmp byte ptr [0x1c412ace], 0x36
1c401d21  je 0x1c401d2c
1c401d23  cmp byte ptr [0x1c412ace], 0x6c
1c401d2a  jne 0x1c401d5c
1c401d2c  test byte ptr [0x1c412ac2], 0x20
1c401d33  mov eax, dword ptr [ecx + 4]
1c401d36  je 0x1c401d47
1c401d38  movsx edx, word ptr [eax + 0x586]
1c401d3f  mov dword ptr [0x1c4123f8], edx
1c401d45  jmp 0x1c401d5c
1c401d47  movsx eax, word ptr [eax + 0x586]
1c401d4e  add eax, dword ptr [0x1c4123f8]
1c401d54  sar eax, 1
1c401d57  mov dword ptr [0x1c4123f8], eax
1c401d5c  cmp byte ptr [0x1c412460], 0x11
1c401d63  jne 0x1c401dec
1c401d69  cmp byte ptr [0x1c416f50], 0
1c401d70  jne 0x1c401dec
1c401d72  mov eax, 0x294
1c401d77  mov dword ptr [0x1c412338], eax
1c401d7c  mov dword ptr [0x1c41233c], eax
1c401d81  mov eax, 0x514
1c401d86  mov dword ptr [0x1c4123b8], eax
1c401d8b  mov dword ptr [0x1c4123bc], eax
1c401d90  mov eax, 0x960
1c401d95  mov dword ptr [0x1c4123f8], eax
1c401d9a  mov dword ptr [0x1c4123fc], eax
1c401d9f  jmp 0x1c401dec
1c401da1  test byte ptr [0x1c416f4c], 0x40
1c401da8  je 0x1c401dec
1c401daa  test byte ptr [0x1c416f4e], 1
1c401db1  je 0x1c401dec
1c401db3  test byte ptr [0x1c412aaf], 0x10
1c401dba  je 0x1c401dec
1c401dbc  test byte ptr [0x1c412aae], 0x20
1c401dc3  je 0x1c401dec
1c401dc5  sub dword ptr [0x1c4123b8], 0x32
1c401dcc  sub dword ptr [0x1c4123f8], 0xc8
1c401dd6  mov eax, dword ptr [0x1c4123b8]
1c401ddb  mov edx, dword ptr [0x1c4123f8]
1c401de1  mov dword ptr [0x1c4123bc], eax
1c401de6  mov dword ptr [0x1c4123fc], edx
1c401dec  test byte ptr [0x1c416f4c], 2
1c401df3  je 0x1c401e1c
1c401df5  test byte ptr [0x1c412ac2], 0x18
1c401dfc  je 0x1c401e1c
1c401dfe  mov eax, 0x73a
1c401e03  mov dword ptr [0x1c4123bc], eax
1c401e08  mov dword ptr [0x1c4123b8], eax
1c401e0d  mov eax, 0x898
1c401e12  mov dword ptr [0x1c4123fc], eax
1c401e17  mov dword ptr [0x1c4123f8], eax
1c401e1c  mov edx, dword ptr [0x1c416f4c]
1c401e22  and edx, 0x4000000
1c401e28  je 0x1c401e51
1c401e2a  test byte ptr [0x1c412ac2], 0x18
1c401e31  je 0x1c401e51
1c401e33  mov eax, 0x6a4
1c401e38  mov dword ptr [0x1c4123bc], eax
1c401e3d  mov dword ptr [0x1c4123b8], eax
1c401e42  mov eax, 0x76c
1c401e47  mov dword ptr [0x1c4123fc], eax
1c401e4c  mov dword ptr [0x1c4123f8], eax
1c401e51  test edx, edx
1c401e53  je 0x1c401e7c
1c401e55  test byte ptr [0x1c412ac3], 0x80
1c401e5c  je 0x1c401e7c
1c401e5e  mov eax, 0x384
1c401e63  mov dword ptr [0x1c4123bc], eax
1c401e68  mov dword ptr [0x1c4123b8], eax
1c401e6d  mov eax, 0x9c4
1c401e72  mov dword ptr [0x1c4123fc], eax
1c401e77  mov dword ptr [0x1c4123f8], eax
1c401e7c  cmp byte ptr [0x1c412460], 0x37
1c401e83  jne 0x1c401f0b
1c401e89  test byte ptr [0x1c412aae], 0x80
1c401e90  je 0x1c401ed2
1c401e92  test byte ptr [0x1c412aad], 0x80
1c401e99  jne 0x1c401ed2
1c401e9b  xor edx, edx
1c401e9d  mov dl, byte ptr [0x1c412604]
1c401ea3  mov eax, edx
1c401ea5  lea ebx, [edx + edx*4]
1c401ea8  mov esi, 0xa
1c401ead  lea edx, [ebx + ebx*4]
1c401eb0  add edx, eax
1c401eb2  mov eax, dword ptr [ecx + 4]
1c401eb5  movsx eax, word ptr [edx + eax + 8]
1c401eba  mov edx, dword ptr [0x1c4123b8]
1c401ec0  lea ebx, [edx + edx*8]
1c401ec3  add eax, ebx
1c401ec5  cdq 
1c401ec6  idiv esi
1c401ec8  mov dword ptr [0x1c4123bc], eax
1c401ecd  mov dword ptr [0x1c4123b8], eax
1c401ed2  cmp byte ptr [0x1c412460], 0x37
1c401ed9  jne 0x1c401f2b
1c401edb  test byte ptr [0x1c412aae], 0x80
1c401ee2  je 0x1c401eed
1c401ee4  test byte ptr [0x1c412aad], 0x80
1c401eeb  je 0x1c401f0b
1c401eed  mov eax, dword ptr [0x1c4123b8]
1c401ef2  mov esi, 0xa
1c401ef7  lea eax, [eax + eax*8 + 0x91]
1c401efe  cdq 
1c401eff  idiv esi
1c401f01  mov dword ptr [0x1c4123bc], eax
1c401f06  mov dword ptr [0x1c4123b8], eax
1c401f0b  cmp byte ptr [0x1c412460], 0x37
1c401f12  jne 0x1c401f2b
1c401f14  test byte ptr [0x1c412aae], 0x20
1c401f1b  je 0x1c401f2b
1c401f1d  sub dword ptr [0x1c41233c], 0x64
1c401f24  sub dword ptr [0x1c4123bc], 0x64
1c401f2b  cmp byte ptr [0x1c412460], 0x36
1c401f32  je 0x1c401f3d
1c401f34  cmp byte ptr [0x1c412460], 0x6c
1c401f3b  jne 0x1c401f79
1c401f3d  test byte ptr [0x1c412ac2], 0x20
1c401f44  jne 0x1c401f50
1c401f46  mov eax, dword ptr [0x1c4123e8]
1c401f4b  mov dword ptr [0x1c4123f8], eax
1c401f50  test byte ptr [0x1c412aae], 0x20
1c401f57  jne 0x1c401f79
1c401f59  xor edx, edx
1c401f5b  mov dl, byte ptr [0x1c412604]
1c401f61  mov eax, edx
1c401f63  lea ebx, [edx + edx*4]
1c401f66  lea edx, [ebx + ebx*4]
1c401f69  add edx, eax
1c401f6b  mov eax, dword ptr [ecx + 4]
1c401f6e  movsx ebx, word ptr [edx + eax + 0xa]
1c401f73  mov dword ptr [0x1c4123fc], ebx
1c401f79  cmp byte ptr [0x1c412460], 0x40
1c401f80  jne 0x1c401fe5
1c401f82  xor edx, edx
1c401f84  mov dl, byte ptr [0x1c412604]
1c401f8a  mov eax, edx
1c401f8c  lea ebx, [edx + edx*4]
1c401f8f  lea edx, [ebx + ebx*4]
1c401f92  add edx, eax
1c401f94  mov eax, dword ptr [ecx + 4]
1c401f97  movsx eax, word ptr [eax + edx + 6]
1c401f9c  add eax, dword ptr [0x1c41232c]
1c401fa2  sar eax, 1
1c401fa5  mov dword ptr [0x1c41233c], eax
1c401faa  mov dword ptr [0x1c412338], eax
1c401faf  mov ebx, dword ptr [ecx + 4]
1c401fb2  movsx eax, word ptr [ebx + edx + 8]
1c401fb7  add eax, dword ptr [0x1c4123ac]
1c401fbd  sar eax, 1
1c401fc0  mov dword ptr [0x1c4123bc], eax
1c401fc5  mov dword ptr [0x1c4123b8], eax
1c401fca  mov ebx, dword ptr [ecx + 4]
1c401fcd  movsx eax, word ptr [ebx + edx + 0xa]
1c401fd2  add eax, dword ptr [0x1c4123ec]
1c401fd8  sar eax, 1
1c401fdb  mov dword ptr [0x1c4123fc], eax
1c401fe0  mov dword ptr [0x1c4123f8], eax
1c401fe5  cmp byte ptr [0x1c412460], 0x3e
1c401fec  jne 0x1c402023
1c401fee  test dword ptr [0x1c412ac0], 0x40000080
1c401ff8  je 0x1c402023
1c401ffa  mov ecx, dword ptr [0x1c4123b8]
1c402000  mov edx, dword ptr [0x1c4123f8]
1c402006  mov dword ptr [0x1c4123bc], ecx
1c40200c  mov dword ptr [0x1c4123fc], edx
1c402012  sub dword ptr [0x1c412338], 0x64
1c402019  mov eax, dword ptr [0x1c412338]
1c40201e  mov dword ptr [0x1c41233c], eax
1c402023  mov eax, dword ptr [0x1c4123f8]
1c402028  sub eax, dword ptr [0x1c4123b8]
1c40202e  cmp eax, 0xfa
1c402033  jge 0x1c402044
1c402035  mov eax, dword ptr [0x1c4123f8]
1c40203a  sub eax, 0xfa
1c40203f  mov dword ptr [0x1c4123b8], eax
1c402044  mov eax, dword ptr [0x1c4123fc]
1c402049  sub eax, dword ptr [0x1c4123bc]
1c40204f  cmp eax, 0xfa
1c402054  jge 0x1c402065
1c402056  mov eax, dword ptr [0x1c4123fc]
1c40205b  sub eax, 0xfa
1c402060  mov dword ptr [0x1c4123bc], eax
1c402065  mov eax, dword ptr [0x1c4123b8]
1c40206a  sub eax, dword ptr [0x1c412338]
1c402070  cmp eax, 0xc8
1c402075  jge 0x1c402086
1c402077  mov eax, dword ptr [0x1c4123b8]
1c40207c  sub eax, 0xc8
1c402081  mov dword ptr [0x1c412338], eax
1c402086  mov eax, dword ptr [0x1c4123bc]
1c40208b  sub eax, dword ptr [0x1c41233c]
1c402091  cmp eax, 0xc8
1c402096  jge 0x1c4020a7
1c402098  mov eax, dword ptr [0x1c4123bc]
1c40209d  sub eax, 0xc8
1c4020a2  mov dword ptr [0x1c41233c], eax
1c4020a7  call 0x1c403100
1c4020ac  mov eax, dword ptr [0x1c416f4c]
1c4020b1  and eax, 0x10002000
1c4020b6  mov dword ptr [esp + 0x10], eax
1c4020ba  je 0x1c40211c
1c4020bc  test byte ptr [0x1c412aad], 0x80
1c4020c3  je 0x1c4020ec
1c4020c5  add dword ptr [0x1c41221c], 0x64
1c4020cc  add dword ptr [0x1c41226c], 0x32
1c4020d3  add dword ptr [0x1c4122ac], 0x32
1c4020da  mov eax, dword ptr [0x1c41233c]
1c4020df  add eax, 0x1f4
1c4020e4  sar eax, 1
1c4020e7  mov dword ptr [0x1c41233c], eax
1c4020ec  test byte ptr [0x1c412ac1], 0x80
1c4020f3  je 0x1c40211c
1c4020f5  add dword ptr [0x1c412218], 0x64
1c4020fc  add dword ptr [0x1c412268], 0x32
1c402103  add dword ptr [0x1c4122a8], 0x32
1c40210a  mov eax, dword ptr [0x1c412338]
1c40210f  add eax, 0x1f4
1c402114  sar eax, 1
1c402117  mov dword ptr [0x1c412338], eax
1c40211c  mov ax, word ptr [0x1c4121aa]
1c402122  mov ebx, dword ptr [0x1c416f4c]
1c402128  mov word ptr [0x1c4121b2], ax
1c40212e  and ebx, 0x10000000
1c402134  je 0x1c402141
1c402136  mov word ptr [0x1c4121aa], 0
1c40213f  jmp 0x1c402170
1c402141  test byte ptr [0x1c416f4f], 1
1c402148  je 0x1c402155
1c40214a  mov word ptr [0x1c4121aa], 1
1c402153  jmp 0x1c402170
1c402155  test byte ptr [0x1c416f4c], 0x40
1c40215c  mov word ptr [0x1c4121aa], 2
1c402165  jne 0x1c402170
1c402167  mov word ptr [0x1c4121aa], 3
1c402170  movsx eax, word ptr [0x1c4121b2]
1c402177  movsx ecx, word ptr [0x1c4121aa]
1c40217e  xor edx, edx
1c402180  mov dl, byte ptr [ecx + eax*4 + 0x1c40dee8]
1c402187  mov dword ptr [0x1c412408], edx
1c40218d  mov dword ptr [0x1c4123c8], edx
1c402193  mov dword ptr [0x1c412348], edx
1c402199  mov dword ptr [0x1c4122b8], edx
1c40219f  mov dword ptr [0x1c412278], edx
1c4021a5  mov dword ptr [0x1c412228], edx
1c4021ab  cmp byte ptr [0x1c412ace], 0x37
1c4021b2  jne 0x1c4021d7
1c4021b4  mov eax, 0x14
1c4021b9  mov dword ptr [0x1c412228], eax
1c4021be  mov dword ptr [0x1c412348], eax
1c4021c3  mov dword ptr [0x1c412278], eax
1c4021c8  mov dword ptr [0x1c4123c8], eax
1c4021cd  mov dword ptr [0x1c4122b8], eax
1c4021d2  mov dword ptr [0x1c412408], eax
1c4021d7  mov edi, dword ptr [0x1c412ac0]
1c4021dd  and edi, 0x10000000
1c4021e3  je 0x1c402211
1c4021e5  test byte ptr [0x1c416f4d], 8
1c4021ec  je 0x1c402211
1c4021ee  mov eax, 0x14
1c4021f3  mov dword ptr [0x1c412228], eax
1c4021f8  mov dword ptr [0x1c412348], eax
1c4021fd  mov dword ptr [0x1c412278], eax
1c402202  mov dword ptr [0x1c4123c8], eax
1c402207  mov dword ptr [0x1c4122b8], eax
1c40220c  mov dword ptr [0x1c412408], eax
1c402211  test edi, edi
1c402213  je 0x1c4022a5
1c402219  test byte ptr [0x1c416f4f], 1
1c402220  je 0x1c40224a
1c402222  mov eax, 0x41
1c402227  mov dword ptr [0x1c412228], eax
1c40222c  mov dword ptr [0x1c412348], eax
1c402231  mov eax, 0x32
1c402236  mov dword ptr [0x1c412278], eax
1c40223b  mov dword ptr [0x1c4123c8], eax
1c402240  mov dword ptr [0x1c4122b8], eax
1c402245  mov dword ptr [0x1c412408], eax
1c40224a  test edi, edi
1c40224c  je 0x1c4022a5
1c40224e  cmp byte ptr [0x1c412460], 0x36
1c402255  je 0x1c402260
1c402257  cmp byte ptr [0x1c412460], 0x6c
1c40225e  jne 0x1c4022a5
1c402260  test byte ptr [0x1c412ac0], 0x80
1c402267  mov dword ptr [0x1c412348], 0x64
1c402271  jne 0x1c40227d
1c402273  mov dword ptr [0x1c412348], 0x1e
1c40227d  mov dword ptr [0x1c4123c8], 0x50
1c402287  mov dword ptr [0x1c412408], 0x32
1c402291  mov eax, 0x14
1c402296  mov dword ptr [0x1c4122b8], eax
1c40229b  mov dword ptr [0x1c412278], eax
1c4022a0  mov dword ptr [0x1c412228], eax
1c4022a5  cmp byte ptr [0x1c412ace], 0x36
1c4022ac  je 0x1c4022b7
1c4022ae  cmp byte ptr [0x1c412ace], 0x6c
1c4022b5  jne 0x1c4022f7
1c4022b7  test byte ptr [0x1c412ab4], 0x80
1c4022be  mov dword ptr [0x1c412348], 0
1c4022c8  jne 0x1c4022d4
1c4022ca  mov dword ptr [0x1c412348], 0x46
1c4022d4  mov dword ptr [0x1c412408], 0x32
1c4022de  mov eax, 0x14
1c4022e3  mov dword ptr [0x1c4123c8], eax
1c4022e8  mov dword ptr [0x1c4122b8], eax
1c4022ed  mov dword ptr [0x1c412278], eax
1c4022f2  mov dword ptr [0x1c412228], eax
1c4022f7  mov ecx, dword ptr [0x1c412ac0]
1c4022fd  and ecx, 0x800000
1c402303  je 0x1c402315
1c402305  test byte ptr [0x1c416f4c], 0x40
1c40230c  je 0x1c402315
1c40230e  mov eax, 0x5a
1c402313  jmp 0x1c40232c
1c402315  test byte ptr [0x1c412ac0], 0x40
1c40231c  je 0x1c402336
1c40231e  test byte ptr [0x1c416f4e], 0x80
1c402325  je 0x1c402336
1c402327  mov eax, 0xa
1c40232c  mov dword ptr [0x1c412228], eax
1c402331  mov dword ptr [0x1c412348], eax
1c402336  test byte ptr [0x1c416f4f], 0x20
1c40233d  je 0x1c402364
1c40233f  xor eax, eax
1c402341  mov dword ptr [0x1c412408], eax
1c402346  mov dword ptr [0x1c4123c8], eax
1c40234b  mov dword ptr [0x1c412348], eax
1c402350  mov eax, 0x32
1c402355  mov dword ptr [0x1c4122b8], eax
1c40235a  mov dword ptr [0x1c412278], eax
1c40235f  mov dword ptr [0x1c412228], eax
1c402364  test byte ptr [0x1c412ac3], 0x20
1c40236b  je 0x1c402381
1c40236d  mov eax, 0x64
1c402372  mov dword ptr [0x1c412408], eax
1c402377  mov dword ptr [0x1c4123c8], eax
1c40237c  mov dword ptr [0x1c412348], eax
1c402381  test edi, edi
1c402383  je 0x1c40239a
1c402385  test byte ptr [0x1c416f4f], 4
1c40238c  je 0x1c40239a
1c40238e  mov dword ptr [0x1c4123c8], 0x50
1c402398  jmp 0x1c4023b1
1c40239a  test byte ptr [0x1c412ac3], 4
1c4023a1  je 0x1c4023b1
1c4023a3  test ebx, ebx
1c4023a5  je 0x1c4023b1
1c4023a7  mov dword ptr [0x1c4123c8], 0x1e
1c4023b1  test ecx, ecx
1c4023b3  je 0x1c4023e1
1c4023b5  cmp byte ptr [0x1c412460], 0x1e
1c4023bc  jne 0x1c4023e1
1c4023be  mov eax, 0x5a
1c4023c3  mov dword ptr [0x1c412228], eax
1c4023c8  mov dword ptr [0x1c412348], eax
1c4023cd  mov dword ptr [0x1c412278], eax
1c4023d2  mov dword ptr [0x1c4123c8], eax
1c4023d7  mov dword ptr [0x1c4122b8], eax
1c4023dc  mov dword ptr [0x1c412408], eax
1c4023e1  mov esi, dword ptr [0x1c412ac0]
1c4023e7  and esi, 0x80000
1c4023ed  je 0x1c4023ff
1c4023ef  test byte ptr [0x1c416f4d], 0x80
1c4023f6  je 0x1c4023ff
1c4023f8  mov eax, 0xa
1c4023fd  jmp 0x1c402416
1c4023ff  test byte ptr [0x1c412ac1], 0x80
1c402406  je 0x1c40242a
1c402408  test byte ptr [0x1c416f4e], 8
1c40240f  je 0x1c40242a
1c402411  mov eax, 0x5a
1c402416  mov dword ptr [0x1c412408], eax
1c40241b  mov dword ptr [0x1c4123c8], eax
1c402420  mov dword ptr [0x1c4122b8], eax
1c402425  mov dword ptr [0x1c412278], eax
1c40242a  test dword ptr [0x1c412ac0], 0xc0100000
1c402434  je 0x1c402462
1c402436  test byte ptr [0x1c416f4d], 0x20
1c40243d  je 0x1c402462
1c40243f  mov eax, 0x14
1c402444  mov dword ptr [0x1c412228], eax
1c402449  mov dword ptr [0x1c412348], eax
1c40244e  mov dword ptr [0x1c412278], eax
1c402453  mov dword ptr [0x1c4123c8], eax
1c402458  mov dword ptr [0x1c4122b8], eax
1c40245d  mov dword ptr [0x1c412408], eax
1c402462  mov eax, dword ptr [0x1c412338]
1c402467  mov ebp, 0x64
1c40246c  sub eax, dword ptr [0x1c41232c]
1c402472  imul eax, dword ptr [0x1c412348]
1c402479  cdq 
1c40247a  idiv ebp
1c40247c  mov edx, dword ptr [0x1c41232c]
1c402482  add edx, eax
1c402484  mov eax, dword ptr [0x1c4123b8]
1c402489  sub eax, dword ptr [0x1c4123ac]
1c40248f  mov dword ptr [0x1c412344], edx
1c402495  imul eax, dword ptr [0x1c4123c8]
1c40249c  cdq 
1c40249d  idiv ebp
1c40249f  mov edx, dword ptr [0x1c4123ac]
1c4024a5  add edx, eax
1c4024a7  mov eax, dword ptr [0x1c4123f8]
1c4024ac  sub eax, dword ptr [0x1c4123ec]
1c4024b2  mov dword ptr [0x1c4123c4], edx
1c4024b8  imul eax, dword ptr [0x1c412408]
1c4024bf  cdq 
1c4024c0  idiv ebp
1c4024c2  mov edx, dword ptr [0x1c4123ec]
1c4024c8  add edx, eax
1c4024ca  mov eax, dword ptr [0x1c412218]
1c4024cf  sub eax, dword ptr [0x1c41220c]
1c4024d5  mov dword ptr [0x1c412404], edx
1c4024db  imul eax, dword ptr [0x1c412228]
1c4024e2  cdq 
1c4024e3  idiv ebp
1c4024e5  mov edx, dword ptr [0x1c41220c]
1c4024eb  add edx, eax
1c4024ed  mov eax, dword ptr [0x1c412268]
1c4024f2  sub eax, dword ptr [0x1c41225c]
1c4024f8  mov dword ptr [0x1c412224], edx
1c4024fe  imul eax, dword ptr [0x1c412278]
1c402505  cdq 
1c402506  idiv ebp
1c402508  mov edx, dword ptr [0x1c41225c]
1c40250e  add edx, eax
1c402510  mov eax, dword ptr [0x1c4122a8]
1c402515  sub eax, dword ptr [0x1c41229c]
1c40251b  mov dword ptr [0x1c412274], edx
1c402521  imul eax, dword ptr [0x1c4122b8]
1c402528  cdq 
1c402529  idiv ebp
1c40252b  mov edx, dword ptr [0x1c41229c]
1c402531  add edx, eax
1c402533  test byte ptr [0x1c412ab4], 2
1c40253a  mov dword ptr [0x1c4122b4], edx
1c402540  je 0x1c402568
1c402542  test ecx, ecx
1c402544  je 0x1c402568
1c402546  mov dword ptr [0x1c4123c0], 0x640
1c402550  mov dword ptr [0x1c412400], 0x8fc
1c40255a  test esi, esi
1c40255c  jne 0x1c402568
1c40255e  mov dword ptr [0x1c412400], 0xa28
1c402568  test byte ptr [0x1c412ac0], 2
1c40256f  je 0x1c402597
1c402571  test byte ptr [0x1c416f4e], 0x80
1c402578  je 0x1c402597
1c40257a  test byte ptr [0x1c416f4e], 8
1c402581  mov dword ptr [0x1c412404], 0x8fc
1c40258b  jne 0x1c402597
1c40258d  mov dword ptr [0x1c412404], 0xa3c
1c402597  mov esi, dword ptr [0x1c412ac0]
1c40259d  and esi, 0x10002000
1c4025a3  je 0x1c4025d8
1c4025a5  test byte ptr [0x1c416f4f], 4
1c4025ac  je 0x1c4025d8
1c4025ae  mov eax, dword ptr [0x1c4123ec]
1c4025b3  mov ebp, 3
1c4025b8  add dword ptr [0x1c412224], 0x64
1c4025bf  add eax, dword ptr [0x1c4123b8]
1c4025c5  add eax, dword ptr [0x1c4123ac]
1c4025cb  cdq 
1c4025cc  idiv ebp
1c4025ce  sub eax, 0x190
1c4025d3  mov dword ptr [0x1c4123c4], eax
1c4025d8  mov eax, dword ptr [0x1c416f4c]
1c4025dd  and eax, 0x4000000
1c4025e2  je 0x1c4025f7
1c4025e4  test dword ptr [0x1c412ac0], 0x40000080
1c4025ee  je 0x1c4025f7
1c4025f0  add dword ptr [0x1c4123c4], 0x64
1c4025f7  mov edx, dword ptr [0x1c412ac0]
1c4025fd  and edx, 0x4000000
1c402603  je 0x1c402618
1c402605  test dword ptr [0x1c416f4c], 0x40000080
1c40260f  je 0x1c402618
1c402611  add dword ptr [0x1c4123c4], 0x64
1c402618  test edx, edx
1c40261a  je 0x1c40263f
1c40261c  test byte ptr [0x1c416f4d], 4
1c402623  mov ebp, dword ptr [0x1c4123c4]
1c402629  je 0x1c402633
1c40262b  add ebp, 0x320
1c402631  jmp 0x1c402639
1c402633  add ebp, 0x190
1c402639  mov dword ptr [0x1c412404], ebp
1c40263f  test eax, eax
1c402641  je 0x1c402662
1c402643  test byte ptr [0x1c412ac1], 4
1c40264a  mov eax, dword ptr [0x1c4123c4]
1c40264f  je 0x1c402658
1c402651  add eax, 0x320
1c402656  jmp 0x1c40265d
1c402658  add eax, 0x258
1c40265d  mov dword ptr [0x1c412404], eax
1c402662  test byte ptr [0x1c412ac1], 8
1c402669  je 0x1c40267f
1c40266b  test ebx, ebx
1c40266d  je 0x1c40267f
1c40266f  sub dword ptr [0x1c412344], 0x3c
1c402676  sub dword ptr [0x1c4123c4], 0x32
1c40267d  jmp 0x1c40269a
1c40267f  test edi, edi
1c402681  je 0x1c40269a
1c402683  test byte ptr [0x1c412ab5], 8
1c40268a  je 0x1c40269a
1c40268c  add dword ptr [0x1c412340], 0x64
1c402693  add dword ptr [0x1c4123c0], 0x64
1c40269a  test dword ptr [0x1c412ac0], 0x20000100
1c4026a4  je 0x1c4026d1
1c4026a6  cmp byte ptr [0x1c412ace], 0x40
1c4026ad  je 0x1c4026d1
1c4026af  mov eax, dword ptr [0x1c412328]
1c4026b4  mov ebx, dword ptr [0x1c4123a8]
1c4026ba  mov ebp, dword ptr [0x1c4123e8]
1c4026c0  mov dword ptr [0x1c412340], eax
1c4026c5  mov dword ptr [0x1c4123c0], ebx
1c4026cb  mov dword ptr [0x1c412400], ebp
1c4026d1  test edx, edx
1c4026d3  je 0x1c4027ec
1c4026d9  cmp dword ptr [esp + 0x10], 0
1c4026de  je 0x1c4027ec
1c4026e4  xor eax, eax
1c4026e6  mov al, byte ptr [0x1c412460]
1c4026eb  sub eax, 9
1c4026ee  cmp eax, 0x63
1c4026f1  ja 0x1c4027ec
1c4026f7  xor edx, edx
1c4026f9  mov dl, byte ptr [eax + 0x1c402bc0]
1c4026ff  jmp dword ptr [edx*4 + 0x1c402b88]
1c402706  mov dword ptr [0x1c4123c4], 0x8de
1c402710  mov dword ptr [0x1c412404], 0xc1c
1c40271a  jmp 0x1c4027ec
1c40271f  mov dword ptr [0x1c4123c4], 0x834
1c402729  mov dword ptr [0x1c412404], 0xa14
1c402733  jmp 0x1c4027ec
1c402738  mov dword ptr [0x1c4123c4], 0x76c
1c402742  mov dword ptr [0x1c412404], 0x97e
1c40274c  jmp 0x1c4027ec
1c402751  mov dword ptr [0x1c4123c4], 0x866
1c40275b  mov dword ptr [0x1c412404], 0xa41
1c402765  jmp 0x1c4027ec
1c40276a  mov dword ptr [0x1c4123c4], 0x7e4
1c402774  mov dword ptr [0x1c412404], 0x92e
1c40277e  jmp 0x1c4027ec
1c402780  mov dword ptr [0x1c4123c4], 0x4b0
1c40278a  mov dword ptr [0x1c412404], 0x960
1c402794  jmp 0x1c4027ec
1c402796  mov dword ptr [0x1c4123c4], 0x3e8
1c4027a0  mov dword ptr [0x1c412404], 0x9f6
1c4027aa  jmp 0x1c4027ec
1c4027ac  mov dword ptr [0x1c4123c4], 0x5dc
1c4027b6  mov dword ptr [0x1c412404], 0x76c
1c4027c0  jmp 0x1c4027ec
1c4027c2  mov dword ptr [0x1c4123c4], 0x78a
1c4027cc  mov dword ptr [0x1c412404], 0x9a6
1c4027d6  jmp 0x1c4027ec
1c4027d8  mov dword ptr [0x1c4123c4], 0x410
1c4027e2  mov dword ptr [0x1c412404], 0x8ca
1c4027ec  mov eax, 0xa
1c4027f1  mov dword ptr [0x1c41222c], eax
1c4027f6  mov dword ptr [0x1c41234c], eax
1c4027fb  mov dword ptr [0x1c41227c], eax
1c402800  mov dword ptr [0x1c4123cc], eax
1c402805  mov dword ptr [0x1c4122bc], eax
1c40280a  mov dword ptr [0x1c41240c], eax
1c40280f  mov eax, 0xc
1c402814  mov dword ptr [0x1c412230], eax
1c402819  mov dword ptr [0x1c412350], eax
1c40281e  mov dword ptr [0x1c412280], eax
1c402823  mov dword ptr [0x1c4123d0], eax
1c402828  mov dword ptr [0x1c4122c0], eax
1c40282d  mov dword ptr [0x1c412410], eax
1c402832  test byte ptr [0x1c412ac3], 1
1c402839  je 0x1c40285e
1c40283b  mov eax, 5
1c402840  mov dword ptr [0x1c412230], eax
1c402845  mov dword ptr [0x1c412350], eax
1c40284a  mov dword ptr [0x1c412280], eax
1c40284f  mov dword ptr [0x1c4123d0], eax
1c402854  mov dword ptr [0x1c4122c0], eax
1c402859  mov dword ptr [0x1c412410], eax
1c40285e  test ecx, ecx
1c402860  je 0x1c402893
1c402862  test byte ptr [0x1c416f4f], 1
1c402869  je 0x1c402893
1c40286b  mov eax, 6
1c402870  mov dword ptr [0x1c412230], eax
1c402875  mov dword ptr [0x1c412350], eax
1c40287a  mov eax, 8
1c40287f  mov dword ptr [0x1c412280], eax
1c402884  mov dword ptr [0x1c4123d0], eax
1c402889  mov dword ptr [0x1c4122c0], eax
1c40288e  mov dword ptr [0x1c412410], eax
1c402893  cmp byte ptr [0x1c412ace], 0x39
1c40289a  jne 0x1c4028c5
1c40289c  mov eax, dword ptr [0x1c416f4c]
1c4028a1  and eax, 0x1000000
1c4028a6  cmp eax, 1
1c4028a9  sbb eax, eax
1c4028ab  and eax, 2
1c4028ae  add eax, 3
1c4028b1  mov dword ptr [0x1c412280], eax
1c4028b6  mov dword ptr [0x1c4123d0], eax
1c4028bb  mov dword ptr [0x1c4122c0], eax
1c4028c0  mov dword ptr [0x1c412410], eax
1c4028c5  cmp byte ptr [0x1c412ace], 0x36
1c4028cc  je 0x1c4028d7
1c4028ce  cmp byte ptr [0x1c412ace], 0x6c
1c4028d5  jne 0x1c402922
1c4028d7  mov eax, 4
1c4028dc  mov dword ptr [0x1c412350], eax
1c4028e1  mov dword ptr [0x1c41234c], eax
1c4028e6  mov dword ptr [0x1c4123d0], eax
1c4028eb  mov dword ptr [0x1c4123cc], eax
1c4028f0  mov eax, 5
1c4028f5  mov dword ptr [0x1c412410], eax
1c4028fa  mov dword ptr [0x1c41240c], eax
1c4028ff  mov eax, 2
1c402904  mov dword ptr [0x1c412230], eax
1c402909  mov dword ptr [0x1c41222c], eax
1c40290e  mov dword ptr [0x1c412280], eax
1c402913  mov dword ptr [0x1c41227c], eax
1c402918  mov dword ptr [0x1c4122c0], eax
1c40291d  mov dword ptr [0x1c4122bc], eax
1c402922  mov eax, dword ptr [0x1c412ab4]
1c402927  and eax, 0x2000
1c40292c  je 0x1c402964
1c40292e  cmp byte ptr [0x1c416f53], 0x36
1c402935  je 0x1c402964
1c402937  test edi, edi
1c402939  je 0x1c4029aa
1c40293b  mov edx, 7
1c402940  mov dword ptr [0x1c41222c], edx
1c402946  mov dword ptr [0x1c41234c], edx
1c40294c  mov dword ptr [0x1c41227c], edx
1c402952  mov dword ptr [0x1c4123cc], edx
1c402958  mov dword ptr [0x1c4122bc], edx
1c40295e  mov dword ptr [0x1c41240c], edx
1c402964  test edi, edi
1c402966  je 0x1c4029aa
1c402968  cmp byte ptr [0x1c412ac4], 0
1c40296f  je 0x1c4029aa
1c402971  cmp byte ptr [0x1c412b30], 0
1c402978  je 0x1c4029aa
1c40297a  test eax, eax
1c40297c  je 0x1c4029aa
1c40297e  test byte ptr [0x1c412b2e], 4
1c402985  je 0x1c4029aa
1c402987  mov eax, 5
1c40298c  mov dword ptr [0x1c41222c], eax
1c402991  mov dword ptr [0x1c41234c], eax
1c402996  mov dword ptr [0x1c41227c], eax
1c40299b  mov dword ptr [0x1c4123cc], eax
1c4029a0  mov dword ptr [0x1c4122bc], eax
1c4029a5  mov dword ptr [0x1c41240c], eax
1c4029aa  cmp word ptr [0x1c412240], 3
1c4029b2  jne 0x1c4029e0
1c4029b4  test ecx, ecx
1c4029b6  je 0x1c402a18
1c4029b8  mov eax, 5
1c4029bd  mov dword ptr [0x1c41222c], eax
1c4029c2  mov dword ptr [0x1c41234c], eax
1c4029c7  mov eax, 7
1c4029cc  mov dword ptr [0x1c41227c], eax
1c4029d1  mov dword ptr [0x1c4123cc], eax
1c4029d6  mov dword ptr [0x1c4122bc], eax
1c4029db  jmp 0x1c402a66
1c4029e0  test ecx, ecx
1c4029e2  je 0x1c402a18
1c4029e4  cmp word ptr [0x1c412acc], 3
1c4029ec  jne 0x1c402a18
1c4029ee  mov eax, 5
1c4029f3  mov dword ptr [0x1c412230], eax
1c4029f8  mov dword ptr [0x1c412350], eax
1c4029fd  mov eax, 7
1c402a02  mov dword ptr [0x1c412280], eax
1c402a07  mov dword ptr [0x1c4123d0], eax
1c402a0c  mov dword ptr [0x1c4122c0], eax
1c402a11  mov dword ptr [0x1c412410], eax
1c402a16  jmp 0x1c402a6b
1c402a18  mov eax, 3
1c402a1d  cmp word ptr [0x1c4121b4], ax
1c402a24  jne 0x1c402a6b
1c402a26  mov ecx, 2
1c402a2b  mov dword ptr [0x1c412280], eax
1c402a30  mov dword ptr [0x1c412230], ecx
1c402a36  mov dword ptr [0x1c41222c], ecx
1c402a3c  mov dword ptr [0x1c412350], ecx
1c402a42  mov dword ptr [0x1c41234c], ecx
1c402a48  mov dword ptr [0x1c41227c], eax
1c402a4d  mov dword ptr [0x1c4123d0], eax
1c402a52  mov dword ptr [0x1c4123cc], eax
1c402a57  mov dword ptr [0x1c4122c0], eax
1c402a5c  mov dword ptr [0x1c4122bc], eax
1c402a61  mov dword ptr [0x1c412410], eax
1c402a66  mov dword ptr [0x1c41240c], eax
1c402a6b  cmp byte ptr [0x1c412ace], 0x37
1c402a72  jne 0x1c402a97
1c402a74  mov eax, 3
1c402a79  mov dword ptr [0x1c412230], eax
1c402a7e  mov dword ptr [0x1c412350], eax
1c402a83  mov dword ptr [0x1c412280], eax
1c402a88  mov dword ptr [0x1c4123d0], eax
1c402a8d  mov dword ptr [0x1c4122c0], eax
1c402a92  mov dword ptr [0x1c412410], eax
1c402a97  test edi, edi
1c402a99  je 0x1c402ac7
1c402a9b  test byte ptr [0x1c416f4d], 8
1c402aa2  je 0x1c402ac7
1c402aa4  mov eax, 5
1c402aa9  mov dword ptr [0x1c412230], eax
1c402aae  mov dword ptr [0x1c412350], eax
1c402ab3  mov dword ptr [0x1c412280], eax
1c402ab8  mov dword ptr [0x1c4123d0], eax
1c402abd  mov dword ptr [0x1c4122c0], eax
1c402ac2  mov dword ptr [0x1c412410], eax
1c402ac7  test esi, esi
1c402ac9  je 0x1c402b0b
1c402acb  test dword ptr [0x1c412ab4], 0x1000040
1c402ad5  je 0x1c402aeb
1c402ad7  mov eax, 5
1c402adc  mov dword ptr [0x1c4122bc], eax
1c402ae1  mov dword ptr [0x1c41227c], eax
1c402ae6  mov dword ptr [0x1c41222c], eax
1c402aeb  test dword ptr [0x1c416f4c], 0x1000040
1c402af5  je 0x1c402b0b
1c402af7  mov eax, 5
1c402afc  mov dword ptr [0x1c4122c0], eax
1c402b01  mov dword ptr [0x1c412280], eax
1c402b06  mov dword ptr [0x1c412230], eax
1c402b0b  cmp byte ptr [0x1c412ace], 0x36
1c402b12  je 0x1c402b29
1c402b14  cmp byte ptr [0x1c412ace], 0x6c
1c402b1b  je 0x1c402b29
1c402b1d  mov dword ptr [0x1c412b28], 0
1c402b27  jmp 0x1c402b33
1c402b29  mov dword ptr [0x1c412b28], 1
1c402b33  cmp byte ptr [0x1c412460], 0x36
1c402b3a  je 0x1c402b45
1c402b3c  cmp byte ptr [0x1c412460], 0x6c
1c402b43  jne 0x1c402b59
1c402b45  mov dword ptr [0x1c412274], 0xfa
1c402b4f  mov dword ptr [0x1c412280], 2
1c402b59  cmp byte ptr [0x1c416f53], 0x36
1c402b60  je 0x1c402b6b
1c402b62  cmp byte ptr [0x1c416f53], 0x6c
1c402b69  jne 0x1c402b7f
1c402b6b  mov dword ptr [0x1c412270], 0xfa
1c402b75  mov dword ptr [0x1c41227c], 2
1c402b7f  pop ebp
1c402b80  pop edi
1c402b81  pop esi
1c402b82  pop ebx
1c402b83  add esp, 4
1c402b86  ret 
1c402b87  nop 
1c402b88  push es
1c402b89  daa 
1c402b8a  inc eax
1c402b8b  sbb al, 0x1f
1c402b8d  daa 
1c402b8e  inc eax
1c402b8f  sbb al, 0x38
1c402b91  daa 
1c402b92  inc eax
1c402b93  sbb al, 0x51
1c402b95  daa 
1c402b96  inc eax
1c402b97  sbb al, 0x6a
1c402b99  daa 
1c402b9a  inc eax
1c402b9b  sbb al, 0x80
1c402b9d  daa 
1c402b9e  inc eax
1c402b9f  sbb al, 0x96
1c402ba1  daa 
1c402ba2  inc eax
1c402ba3  sbb al, 0xac
1c402ba5  daa 
1c402ba6  inc eax
1c402ba7  sbb al, 0xc2
1c402ba9  daa 
1c402baa  inc eax
1c402bab  sbb al, 0xd8
1c402bad  daa 
1c402bae  inc eax
1c402baf  sbb al, 0xac
1c402bb1  daa 
1c402bb2  inc eax
1c402bb3  sbb al, 0x96
1c402bb5  daa 
1c402bb6  inc eax
1c402bb7  sbb al, 0xc2
1c402bb9  daa 
1c402bba  inc eax
1c402bbb  sbb al, 0xec
1c402bbd  daa 
1c402bbe  inc eax
1c402bbf  sbb al, 0
1c402bc1  or eax, 0xd010d0d
1c402bc6  or eax, 0xd0d020d
1c402bcb  or eax, 0xd0d0d0d
1c402bd0  or eax, 0xd0d0d0d
1c402bd5  or eax, 0xd040d03
1c402bda  add eax, 0x60d0d0d
1c402bdf  or eax, 0xd0d0d07
1c402be4  or eax, 0xd0d0d0d
1c402be9  or eax, 0x80d0d0d
1c402bee  or dword ptr [edx], ecx
1c402bf0  or eax, 0xd0d0d0d
1c402bf5  or eax, 0xd0d0d0d
1c402bfa  or eax, 0xd0d0d0d
1c402bff  or eax, 0xd0d0d0d
1c402c04  or eax, 0xd0d0d0d
1c402c09  or eax, 0xd0d0d0d
1c402c0e  or eax, 0xd0d0d0d
1c402c13  or ecx, dword ptr [0xd0d0d0d]
1c402c19  or eax, 0xd0d0d0d
1c402c1e  or eax, 0xd0d0d0d
1c402c23  or al, 0xcc
1c402c25  int3 
1c402c26  int3 
1c402c27  int3 
1c402c28  int3 
1c402c29  int3 
1c402c2a  int3 
1c402c2b  int3 
1c402c2c  int3 
1c402c2d  int3 
1c402c2e  int3 
1c402c2f  int3 
1c402c30  mov ecx, dword ptr [esp + 4]
1c402c34  mov eax, dword ptr [ecx + 8]
1c402c37  mov edx, dword ptr [ecx + 0x18]
1c402c3a  mov dword ptr [ecx + 0x10], eax
1c402c3d  mov dword ptr [ecx + 8], edx
1c402c40  mov eax, dword ptr [ecx + 0xc]
1c402c43  mov edx, dword ptr [ecx + 0x1c]
1c402c46  mov dword ptr [ecx + 0x14], eax
1c402c49  mov dword ptr [ecx + 0xc], edx
1c402c4c  mov eax, dword ptr [ecx + 0x24]
1c402c4f  mov dword ptr [ecx + 0x20], eax
1c402c52  ret 
1c402c53  int3 
1c402c54  int3 
1c402c55  int3 
1c402c56  int3 
1c402c57  int3 
1c402c58  int3 
1c402c59  int3 
1c402c5a  int3 
1c402c5b  int3 
1c402c5c  int3 
1c402c5d  int3 
1c402c5e  int3 
1c402c5f  int3 
1c402c60  mov ecx, dword ptr [esp + 4]
1c402c64  mov ax, word ptr [ecx + 0xc]
1c402c68  cmp ax, 0xff
1c402c6c  jne 0x1c402c73
1c402c6e  mov ax, 9
1c402c72  ret 
1c402c73  movzx edx, ax
1c402c76  mov eax, edx
1c402c78  lea edx, [edx + edx*4]
1c402c7b  lea edx, [edx + edx*4]
1c402c7e  add edx, eax
1c402c80  mov eax, dword ptr [ecx + 4]
1c402c83  mov eax, dword ptr [edx + eax + 2]
1c402c87  test eax, 0x10000000
1c402c8c  je 0x1c402c92
1c402c8e  xor ax, ax
1c402c91  ret 
1c402c92  test ah, 0x20
1c402c95  je 0x1c402c9c
1c402c97  mov ax, 1
1c402c9b  ret 
1c402c9c  test ah, 0x80
1c402c9f  je 0x1c402ca6
1c402ca1  mov ax, 2
1c402ca5  ret 
1c402ca6  test al, 0x40
1c402ca8  je 0x1c402cbc
1c402caa  and eax, 0x8000000
1c402caf  cmp eax, 1
1c402cb2  sbb eax, eax
1c402cb4  and eax, 2
1c402cb7  add ax, 3
1c402cbb  ret 
1c402cbc  test eax, 0x40000
1c402cc1  je 0x1c402cd5
1c402cc3  and eax, 0x8000000
1c402cc8  cmp eax, 1
1c402ccb  sbb eax, eax
1c402ccd  and eax, 2
1c402cd0  add ax, 4
1c402cd4  ret 
1c402cd5  test al, 4
1c402cd7  je 0x1c402cde
1c402cd9  mov ax, 7
1c402cdd  ret 
1c402cde  test eax, 0x20000000
1c402ce3  je 0x1c402cea
1c402ce5  mov ax, 9
1c402ce9  ret 
1c402cea  and eax, 0x100
1c402cef  cmp eax, 1
1c402cf2  mov eax, 9
1c402cf7  adc eax, -1
1c402cfa  ret 
1c402cfb  int3 
1c402cfc  int3 
1c402cfd  int3 
1c402cfe  int3 
1c402cff  int3 
1c402d00  push ebx
1c402d01  push esi
1c402d02  push 0x1c412500
1c402d07  call 0x1c402c30
1c402d0c  add esp, 4
1c402d0f  push 0x1c412420
1c402d14  call 0x1c402c30
1c402d19  add esp, 4
1c402d1c  xor edx, edx
1c402d1e  mov dx, word ptr [0x1c4121b4]
1c402d25  xor eax, eax
1c402d27  mov ax, word ptr [0x1c412acc]
1c402d2d  lea ecx, [edx + edx*4]
1c402d30  lea ebx, [eax + ecx*2]
1c402d33  lea eax, [ebx + ebx*4]
1c402d36  lea esi, [eax*2]
1c402d3d  xor eax, eax
1c402d3f  mov al, byte ptr [esi + 0x1c40df58]
1c402d45  mov dword ptr [0x1c412528], eax
1c402d4a  xor eax, eax
1c402d4c  mov ax, word ptr [0x1c412240]
1c402d52  lea ecx, [eax + eax*4]
1c402d55  lea edx, [edx + ecx*2]
1c402d58  xor ecx, ecx
1c402d5a  lea eax, [edx + edx*4]
1c402d5d  mov dword ptr [0x1c412538], 0
1c402d67  add eax, eax
1c402d69  mov dword ptr [0x1c41253c], 0x4b
1c402d73  mov cl, byte ptr [eax + 0x1c40df5b]
1c402d79  mov dword ptr [0x1c41252c], ecx
1c402d7f  xor ecx, ecx
1c402d81  mov cl, byte ptr [esi + 0x1c40df5e]
1c402d87  mov dword ptr [0x1c412530], ecx
1c402d8d  xor ecx, ecx
1c402d8f  mov cl, byte ptr [esi + 0x1c40df59]
1c402d95  mov dword ptr [0x1c412448], ecx
1c402d9b  xor ecx, ecx
1c402d9d  mov cl, byte ptr [eax + 0x1c40df5c]
1c402da3  xor eax, eax
1c402da5  mov al, byte ptr [esi + 0x1c40df5f]
1c402dab  mov dword ptr [0x1c41244c], ecx
1c402db1  cmp byte ptr [0x1c412ace], 0x36
1c402db8  mov dword ptr [0x1c412450], eax
1c402dbd  je 0x1c402dc8
1c402dbf  cmp byte ptr [0x1c412ace], 0x6c
1c402dc6  jne 0x1c402dd7
1c402dc8  mov eax, 1
1c402dcd  mov dword ptr [0x1c412530], eax
1c402dd2  mov dword ptr [0x1c41252c], eax
1c402dd7  test byte ptr [0x1c412ac2], 0x80
1c402dde  je 0x1c402e18
1c402de0  cmp byte ptr [0x1c412460], 0x36
1c402de7  je 0x1c402df2
1c402de9  cmp byte ptr [0x1c412460], 0x6c
1c402df0  jne 0x1c402dfc
1c402df2  mov dword ptr [0x1c412528], 0
1c402dfc  cmp byte ptr [0x1c416f53], 0x36
1c402e03  je 0x1c402e0e
1c402e05  cmp byte ptr [0x1c416f53], 0x6c
1c402e0c  jne 0x1c402e18
1c402e0e  mov eax, dword ptr [0x1c412508]
1c402e13  mov dword ptr [0x1c412520], eax
1c402e18  xor ecx, ecx
1c402e1a  mov eax, dword ptr [esp + 0xc]
1c402e1e  mov cl, byte ptr [0x1c412460]
1c402e24  xor ebx, ebx
1c402e26  mov edx, dword ptr [eax + 0x2c]
1c402e29  lea eax, [ecx + ecx*4]
1c402e2c  mov esi, dword ptr [edx + 4]
1c402e2f  lea edx, [eax + eax*4]
1c402e32  add edx, ecx
1c402e34  test byte ptr [0x1c416f4f], 0x20
1c402e3b  mov bl, byte ptr [esi + edx + 0x16]
1c402e3f  mov dword ptr [0x1c412518], ebx
1c402e45  je 0x1c402e5a
1c402e47  test byte ptr [0x1c412ac3], 8
1c402e4e  jne 0x1c402e5a
1c402e50  mov dword ptr [0x1c412518], 0
1c402e5a  mov eax, 0x10000000
1c402e5f  test dword ptr [0x1c412ac0], eax
1c402e65  je 0x1c402e88
1c402e67  test byte ptr [0x1c416f4f], 8
1c402e6e  je 0x1c402e88
1c402e70  test byte ptr [0x1c416f4c], 0x40
1c402e77  je 0x1c402e88
1c402e79  test dword ptr [0x1c412aac], eax
1c402e7f  je 0x1c402e88
1c402e81  add dword ptr [0x1c412518], 6
1c402e88  mov eax, dword ptr [0x1c412518]
1c402e8d  mov dword ptr [0x1c41251c], eax
1c402e92  mov eax, 0x8000000
1c402e97  test dword ptr [0x1c416f4c], eax
1c402e9d  je 0x1c402eb4
1c402e9f  test dword ptr [0x1c412aac], eax
1c402ea5  jne 0x1c402eb4
1c402ea7  mov eax, dword ptr [0x1c412518]
1c402eac  sub eax, 3
1c402eaf  mov dword ptr [0x1c41251c], eax
1c402eb4  mov eax, dword ptr [0x1c412518]
1c402eb9  xor edx, edx
1c402ebb  mov dword ptr [0x1c412438], 0
1c402ec5  mov dl, byte ptr [eax + 0x1c40604e]
1c402ecb  mov eax, dword ptr [0x1c41251c]
1c402ed0  mov dword ptr [0x1c412518], edx
1c402ed6  xor edx, edx
1c402ed8  test byte ptr [0x1c416f4c], 0x44
1c402edf  mov dl, byte ptr [eax + 0x1c40604e]
1c402ee5  mov dword ptr [0x1c41251c], edx
1c402eeb  je 0x1c402f3e
1c402eed  sub ecx, 0x41
1c402ef0  cmp ecx, 0xa
1c402ef3  ja 0x1c402f3e
1c402ef5  xor eax, eax
1c402ef7  mov al, byte ptr [ecx + 0x1c4030f4]
1c402efd  jmp dword ptr [eax*4 + 0x1c4030dc]
1c402f04  mov dword ptr [0x1c412438], 0x20
1c402f0e  jmp 0x1c402f3e
1c402f10  mov dword ptr [0x1c412438], 0x20
1c402f1a  jmp 0x1c402f3e
1c402f1c  mov dword ptr [0x1c412438], 0x24
1c402f26  jmp 0x1c402f3e
1c402f28  mov dword ptr [0x1c412438], 0x21
1c402f32  jmp 0x1c402f3e
1c402f34  mov dword ptr [0x1c412438], 0x28
1c402f3e  mov eax, dword ptr [0x1c412438]
1c402f43  xor ecx, ecx
1c402f45  mov cl, byte ptr [eax + 0x1c406058]
1c402f4b  mov eax, dword ptr [0x1c412518]
1c402f50  sub eax, dword ptr [0x1c41250c]
1c402f56  mov dword ptr [0x1c412438], ecx
1c402f5c  imul eax, dword ptr [0x1c412528]
1c402f63  cdq 
1c402f64  mov dword ptr [0x1c41243c], ecx
1c402f6a  mov ecx, 0x64
1c402f6f  idiv ecx
1c402f71  mov ecx, dword ptr [0x1c41250c]
1c402f77  add ecx, eax
1c402f79  mov eax, dword ptr [0x1c412438]
1c402f7e  sub eax, dword ptr [0x1c41242c]
1c402f84  mov dword ptr [0x1c412524], ecx
1c402f8a  imul eax, dword ptr [0x1c412448]
1c402f91  cdq 
1c402f92  mov ecx, 0x64
1c402f97  idiv ecx
1c402f99  mov ecx, dword ptr [0x1c41242c]
1c402f9f  add ecx, eax
1c402fa1  mov eax, dword ptr [0x1c412518]
1c402fa6  mov dword ptr [0x1c412444], ecx
1c402fac  test eax, eax
1c402fae  jg 0x1c402fb2
1c402fb0  xor eax, eax
1c402fb2  mov dword ptr [0x1c412518], eax
1c402fb7  mov eax, dword ptr [0x1c41251c]
1c402fbc  test eax, eax
1c402fbe  jg 0x1c402fc2
1c402fc0  xor eax, eax
1c402fc2  mov dword ptr [0x1c41251c], eax
1c402fc7  mov eax, dword ptr [0x1c412524]
1c402fcc  test eax, eax
1c402fce  jg 0x1c402fd2
1c402fd0  xor eax, eax
1c402fd2  push 0x1c4124c0
1c402fd7  mov dword ptr [0x1c412524], eax
1c402fdc  call 0x1c402c30
1c402fe1  add esp, 4
1c402fe4  push 0x1c412660
1c402fe9  call 0x1c402c30
1c402fee  mov dword ptr [0x1c412678], 0xc
1c402ff8  add esp, 4
1c402ffb  test byte ptr [0x1c416f4f], 8
1c403002  jne 0x1c40300e
1c403004  mov dword ptr [0x1c412678], 8
1c40300e  cmp byte ptr [0x1c416f50], 0
1c403015  je 0x1c40301e
1c403017  add dword ptr [0x1c412678], 2
1c40301e  test byte ptr [0x1c4121a4], 4
1c403025  je 0x1c403037
1c403027  cmp byte ptr [0x1c416f50], 0
1c40302e  jne 0x1c403037
1c403030  sub dword ptr [0x1c412678], 2
1c403037  test byte ptr [0x1c416f4f], 1
1c40303e  je 0x1c403047
1c403040  sub dword ptr [0x1c412678], 5
1c403047  cmp byte ptr [0x1c412460], 1
1c40304e  jne 0x1c403057
1c403050  add dword ptr [0x1c41220c], 0x32
1c403057  mov eax, 3
1c40305c  mov esi, dword ptr [0x1c412678]
1c403062  shl esi, 8
1c403065  mov dword ptr [0x1c412690], eax
1c40306a  mov dword ptr [0x1c41268c], eax
1c40306f  mov dword ptr [0x1c412678], esi
1c403075  mov eax, dword ptr [0x1c4124d8]
1c40307a  mov ecx, 0x64
1c40307f  sub eax, dword ptr [0x1c4124cc]
1c403085  mov dword ptr [0x1c41267c], esi
1c40308b  imul eax, dword ptr [0x1c4124e8]
1c403092  cdq 
1c403093  idiv ecx
1c403095  mov ecx, dword ptr [0x1c4124cc]
1c40309b  sub esi, dword ptr [0x1c41266c]
1c4030a1  add ecx, eax
1c4030a3  mov ebx, 0x64
1c4030a8  lea eax, [esi + esi*4]
1c4030ab  mov dword ptr [0x1c4124e4], ecx
1c4030b1  lea ecx, [eax + eax*4]
1c4030b4  pop esi
1c4030b5  mov dword ptr [0x1c412688], 0x32
1c4030bf  lea eax, [ecx*2]
1c4030c6  mov ecx, dword ptr [0x1c41266c]
1c4030cc  cdq 
1c4030cd  idiv ebx
1c4030cf  add ecx, eax
1c4030d1  pop ebx
1c4030d2  mov dword ptr [0x1c412684], ecx
1c4030d8  ret 
1c4030d9  lea ecx, [ecx]
1c4030dc  add al, 0x2f
1c4030de  inc eax
1c4030df  sbb al, 0x10
1c4030e1  das 
1c4030e2  inc eax
1c4030e3  sbb al, 0x1c
1c4030e5  das 
1c4030e6  inc eax
1c4030e7  sbb al, 0x28
1c4030e9  das 
1c4030ea  inc eax
1c4030eb  sbb al, 0x34
1c4030ed  das 
1c4030ee  inc eax
1c4030ef  sbb al, 0x3e
1c4030f1  das 
1c4030f2  inc eax
1c4030f3  sbb al, 0
1c4030f5  add dword ptr [edx], eax
1c4030f7  add eax, dword ptr [0x5050505]
1c4030fd  add eax, 0x5756cc04
1c403102  mov esi, dword ptr [0x1c412ac0]
1c403108  test esi, 0x10
1c40310e  je 0x1c4031f3
1c403114  xor ax, ax
1c403117  mov cl, byte ptr [0x1c412ace]
1c40311d  movsx edx, ax
1c403120  cmp byte ptr [edx + edx*2 + 0x1c40df18], cl
1c403127  je 0x1c403131
1c403129  inc ax
1c40312b  cmp ax, 0x15
1c40312f  jl 0x1c40311d
1c403131  movsx eax, ax
1c403134  test esi, 0xc0000000
1c40313a  movzx dx, byte ptr [eax + eax*2 + 0x1c40df19]
1c403143  movzx di, byte ptr [eax + eax*2 + 0x1c40df1a]
1c40314c  lea eax, [eax + eax*2]
1c40314f  je 0x1c403162
1c403151  test byte ptr [0x1c416f4d], 0x20
1c403158  je 0x1c403162
1c40315a  sub dx, 0xa
1c40315e  sub di, 0xf
1c403162  cmp dx, 0x5f
1c403166  jl 0x1c40316c
1c403168  mov dx, 0x5f
1c40316c  test dx, dx
1c40316f  jg 0x1c403174
1c403171  xor dx, dx
1c403174  movsx eax, dx
1c403177  cmp di, 0x64
1c40317b  jl 0x1c403181
1c40317d  mov di, 0x64
1c403181  movsx edx, di
1c403184  lea esi, [eax + 5]
1c403187  cmp edx, esi
1c403189  jg 0x1c40318d
1c40318b  mov edx, esi
1c40318d  mov dword ptr [0x1c412238], eax
1c403192  mov dword ptr [0x1c412358], eax
1c403197  mov dword ptr [0x1c412288], eax
1c40319c  mov dword ptr [0x1c4123d8], eax
1c4031a1  mov dword ptr [0x1c4122c8], eax
1c4031a6  mov dword ptr [0x1c412418], eax
1c4031ab  movsx eax, dx
1c4031ae  mov dword ptr [0x1c41223c], eax
1c4031b3  mov dword ptr [0x1c41235c], eax
1c4031b8  mov dword ptr [0x1c41228c], eax
1c4031bd  mov dword ptr [0x1c4123dc], eax
1c4031c2  mov dword ptr [0x1c4122cc], eax
1c4031c7  mov dword ptr [0x1c41241c], eax
1c4031cc  xor eax, eax
1c4031ce  mov al, cl
1c4031d0  cmp eax, 0x23
1c4031d3  jne 0x1c4031f3
1c4031d5  mov eax, 0x32
1c4031da  mov dword ptr [0x1c412238], eax
1c4031df  mov dword ptr [0x1c412358], eax
1c4031e4  mov eax, 0x5f
1c4031e9  mov dword ptr [0x1c41223c], eax
1c4031ee  mov dword ptr [0x1c41235c], eax
1c4031f3  pop edi
1c4031f4  pop esi
1c4031f5  ret 
1c4031f6  int3 
1c4031f7  int3 
1c4031f8  int3 
1c4031f9  int3 
1c4031fa  int3 
1c4031fb  int3 
1c4031fc  int3 
1c4031fd  int3 
1c4031fe  int3 
1c4031ff  int3 
1c403200  sub esp, 8
1c403203  push ebx
1c403204  push esi
1c403205  mov esi, dword ptr [esp + 0x14]
1c403209  push edi
1c40320a  push ebp
1c40320b  mov ecx, 0x64
1c403210  xor ebp, ebp
1c403212  mov eax, dword ptr [esi + 0x38]
1c403215  mov bp, word ptr [0x1c4121b6]
1c40321c  mov edi, 0x8000
1c403221  imul eax, ebp
1c403224  cdq 
1c403225  idiv ecx
1c403227  lea ebx, [eax + 1]
1c40322a  mov eax, dword ptr [esi + 0x3c]
1c40322d  imul eax, ebp
1c403230  add eax, 0x32
1c403233  cdq 
1c403234  idiv ecx
1c403236  mov ecx, eax
1c403238  sub ecx, ebx
1c40323a  cmp ecx, 1
1c40323d  jg 0x1c403244
1c40323f  mov ecx, 1
1c403244  mov eax, edi
1c403246  mov ebp, 0x8000
1c40324b  cdq 
1c40324c  idiv ecx
1c40324e  sub ebp, eax
1c403250  mov edx, eax
1c403252  mov ecx, 0x1c4126a0
1c403257  test ebx, ebx
1c403259  jle 0x1c403275
1c40325b  mov edi, ecx
1c40325d  mov eax, 0x1000100
1c403262  mov ecx, ebx
1c403264  shr ecx, 1
1c403267  rep stosd dword ptr es:[edi], eax
1c403269  adc ecx, ecx
1c40326b  rep stosw word ptr es:[edi], ax
1c40326e  lea ecx, [ebx*2 + 0x1c4126a0]
1c403275  xor eax, eax
1c403277  mov ax, word ptr [0x1c4121b6]
1c40327d  cmp eax, ebx
1c40327f  jle 0x1c4032a2
1c403281  test ebp, ebp
1c403283  jge 0x1c403287
1c403285  xor ebp, ebp
1c403287  mov eax, ebp
1c403289  add ecx, 2
1c40328c  sar eax, 7
1c40328f  sub ebp, edx
1c403291  mov word ptr [ecx - 2], ax
1c403295  inc ebx
1c403296  xor eax, eax
1c403298  mov ax, word ptr [0x1c4121b6]
1c40329e  cmp eax, ebx
1c4032a0  jg 0x1c403281
1c4032a2  xor eax, eax
1c4032a4  mov ax, word ptr [0x1c4121b6]
1c4032aa  mov word ptr [eax*2 + 0x1c41269e], 0
1c4032b4  mov ecx, dword ptr [esi + 0x34]
1c4032b7  cmp ecx, 8
1c4032ba  jl 0x1c4032c1
1c4032bc  mov ecx, 8
1c4032c1  test ecx, ecx
1c4032c3  jg 0x1c4032c7
1c4032c5  xor ecx, ecx
1c4032c7  shl ecx, 4
1c4032ca  mov edx, dword ptr [esi + 0x20]
1c4032cd  mov eax, dword ptr [esi + 0x2c]
1c4032d0  mov ebp, dword ptr [esi + 8]
1c4032d3  add eax, ecx
1c4032d5  mov edi, 0x1c411da0
1c4032da  mov dword ptr [esp + 0x10], ebp
1c4032de  mov ebx, dword ptr [eax*4 + 0x1c40dca8]
1c4032e5  xor eax, eax
1c4032e7  mov dword ptr [esp + 0x14], ebx
1c4032eb  cmp word ptr [0x1c4121b6], ax
1c4032f2  mov ebx, 0x1c4126a0
1c4032f7  jbe 0x1c40332b
1c4032f9  mov ebp, dword ptr [esp + 0x10]
1c4032fd  add ebx, 2
1c403300  sub ebp, edx
1c403302  add edi, 2
1c403305  imul ebp, dword ptr [esp + 0x14]
1c40330a  sar ebp, 8
1c40330d  inc eax
1c40330e  add edx, ebp
1c403310  movsx ebp, word ptr [ebx - 2]
1c403314  imul ebp, edx
1c403317  sar ebp, 8
1c40331a  mov word ptr [edi - 2], bp
1c40331e  xor ebp, ebp
1c403320  mov bp, word ptr [0x1c4121b6]
1c403327  cmp ebp, eax
1c403329  jg 0x1c4032f9
1c40332b  xor eax, eax
1c40332d  mov edx, dword ptr [esi + 4]
1c403330  mov ax, word ptr [0x1c4121b6]
1c403336  lea edi, [eax*2 + 0x1c411d9e]
1c40333d  lea ebx, [eax*2 - 2]
1c403344  add edx, ebx
1c403346  mov eax, dword ptr [esi + 0xc]
1c403349  add ebx, 0x1c4126a0
1c40334f  mov dword ptr [esp + 0x10], eax
1c403353  mov eax, dword ptr [esi + 0x30]
1c403356  mov esi, dword ptr [esi + 0x24]
1c403359  add eax, ecx
1c40335b  mov ecx, dword ptr [eax*4 + 0x1c40dca8]
1c403362  mov dword ptr [esp + 0x14], ecx
1c403366  xor ecx, ecx
1c403368  cmp word ptr [0x1c4121b6], cx
1c40336f  jbe 0x1c4033b0
1c403371  mov eax, 0x100
1c403376  sub ebx, 2
1c403379  sub edi, 2
1c40337c  sub edx, 2
1c40337f  movsx ebp, word ptr [ebx + 2]
1c403383  sub eax, ebp
1c403385  inc ecx
1c403386  imul eax, esi
1c403389  sar eax, 8
1c40338c  add ax, word ptr [edi + 2]
1c403390  mov word ptr [edx + 2], ax
1c403394  mov eax, dword ptr [esp + 0x10]
1c403398  sub eax, esi
1c40339a  imul eax, dword ptr [esp + 0x14]
1c40339f  sar eax, 8
1c4033a2  add esi, eax
1c4033a4  xor eax, eax
1c4033a6  mov ax, word ptr [0x1c4121b6]
1c4033ac  cmp eax, ecx
1c4033ae  jg 0x1c403371
1c4033b0  pop ebp
1c4033b1  pop edi
1c4033b2  pop esi
1c4033b3  pop ebx
1c4033b4  add esp, 8
1c4033b7  ret 
1c4033b8  int3 
1c4033b9  int3 
1c4033ba  int3 
1c4033bb  int3 
1c4033bc  int3 
1c4033bd  int3 
1c4033be  int3 
1c4033bf  int3 
1c4033c0  cmp word ptr [0x1c4121dc], 0
1c4033c8  jle 0x1c403436
1c4033ca  cmp word ptr [0x1c4121ac], 0
1c4033d2  jle 0x1c403436
1c4033d4  xor ax, ax
1c4033d7  xor ecx, ecx
1c4033d9  mov cx, word ptr [0x1c4121b6]
1c4033e0  add ecx, ecx
1c4033e2  add ecx, dword ptr [0x1c412364]
1c4033e8  cmp word ptr [0x1c4121dc], ax
1c4033ef  jle 0x1c403409
1c4033f1  mov dx, word ptr [0x1c4121ac]
1c4033f8  sub ecx, 2
1c4033fb  inc ax
1c4033fd  mov word ptr [ecx], dx
1c403400  cmp word ptr [0x1c4121dc], ax
1c403407  jg 0x1c4033f1
1c403409  test byte ptr [0x1c412ac0], 1
1c403410  je 0x1c403436
1c403412  sub word ptr [ecx], 8
1c403416  sub word ptr [ecx + 2], 4
1c40341b  xor ecx, ecx
1c40341d  mov eax, dword ptr [0x1c412364]
1c403422  mov cx, word ptr [0x1c4121b6]
1c403429  lea eax, [eax + ecx*2 - 2]
1c40342d  sub word ptr [eax], 8
1c403431  sub word ptr [eax - 2], 4
1c403436  ret 
1c403437  int3 
1c403438  int3 
1c403439  int3 
1c40343a  int3 
1c40343b  int3 
1c40343c  int3 
1c40343d  int3 
1c40343e  int3 
1c40343f  int3 
1c403440  mov eax, dword ptr [esp + 0xc]
1c403444  push ebx
1c403445  push esi
1c403446  push edi
1c403447  push ebp
1c403448  mov edi, dword ptr [eax]
1c40344a  test edi, edi
1c40344c  je 0x1c403512
1c403452  cmp word ptr [edi], 0x1e
1c403456  mov esi, dword ptr [esp + 0x14]
1c40345a  je 0x1c403516
1c403460  movsx eax, word ptr [edi]
1c403463  sub eax, 0x32
1c403466  cmp eax, 0xc8
1c40346b  ja 0x1c403503
1c403471  xor ecx, ecx
1c403473  mov cl, byte ptr [eax + 0x1c4038ec]
1c403479  jmp dword ptr [ecx*4 + 0x1c4038d4]
1c403480  movsx eax, word ptr [edi + 2]
1c403484  push eax
1c403485  push esi
1c403486  call 0x1c404010
1c40348b  add esp, 8
1c40348e  jmp 0x1c403503
1c403490  mov ax, word ptr [edi + 2]
1c403494  mov word ptr [esi + 0xae], ax
1c40349b  jmp 0x1c403503
1c40349d  mov ax, word ptr [edi + 2]
1c4034a1  test ax, ax
1c4034a4  jg 0x1c4034d7
1c4034a6  mov bx, word ptr [esi + 0xac]
1c4034ad  imul bx, bx, 0xc
1c4034b1  add bx, word ptr [esi + 0xae]
1c4034b8  sub bx, ax
1c4034bb  cmp bx, 0x55
1c4034bf  jl 0x1c403503
1c4034c1  mov cx, 0xc
1c4034c5  lea eax, [ebx - 0x49]
1c4034c8  sub dx, dx
1c4034cb  div cx
1c4034ce  imul ax, cx
1c4034d2  sub bx, ax
1c4034d5  jmp 0x1c403503
1c4034d7  cmp ax, 0x7d0
1c4034db  jl 0x1c4034e1
1c4034dd  mov ax, 0x7d0
1c4034e1  cmp ax, 0xa
1c4034e5  jg 0x1c4034eb
1c4034e7  mov ax, 0xa
1c4034eb  mov word ptr [esi + 0x46], ax
1c4034ef  jmp 0x1c403503
1c4034f1  mov ax, word ptr [edi + 2]
1c4034f5  mov word ptr [esi + 0x4c], ax
1c4034f9  jmp 0x1c403503
1c4034fb  mov ax, word ptr [edi + 2]
1c4034ff  mov word ptr [esi + 0x60], ax
1c403503  add edi, 6
1c403506  cmp word ptr [edi], 0x1e
1c40350a  jne 0x1c403460
1c403510  jmp 0x1c403516
1c403512  mov esi, dword ptr [esp + 0x14]
1c403516  mov ebx, dword ptr [0x1c412ac8]
1c40351c  and ebx, 4
1c40351f  shr ebx, 2
1c403522  test byte ptr [0x1c416f4f], 0x20
1c403529  jne 0x1c40354a
1c40352b  test byte ptr [0x1c416f4f], 8
1c403532  je 0x1c40354a
1c403534  test byte ptr [0x1c416f4f], 1
1c40353b  je 0x1c403546
1c40353d  test byte ptr [0x1c416f4d], 0x80
1c403544  je 0x1c40354a
1c403546  xor ebp, ebp
1c403548  jmp 0x1c40354f
1c40354a  mov ebp, 1
1c40354f  test byte ptr [0x1c412ac8], 0x80
1c403556  je 0x1c403660
1c40355c  test byte ptr [0x1c412ab5], 1
1c403563  je 0x1c40357a
1c403565  test byte ptr [0x1c412ac3], 8
1c40356c  je 0x1c40357a
1c40356e  mov dword ptr [0x1c412650], 0x64
1c403578  jmp 0x1c40358b
1c40357a  mov ecx, dword ptr [esi + 0xc4]
1c403580  xor eax, eax
1c403582  mov al, byte ptr [ecx]
1c403584  add eax, eax
1c403586  mov dword ptr [0x1c412650], eax
1c40358b  mov ecx, dword ptr [esi + 0xc8]
1c403591  xor eax, eax
1c403593  inc dword ptr [esi + 0xc4]
1c403599  mov al, byte ptr [ecx]
1c40359b  add eax, eax
1c40359d  mov dword ptr [0x1c412ad0], eax
1c4035a2  xor eax, eax
1c4035a4  mov ecx, dword ptr [esi + 0xcc]
1c4035aa  inc dword ptr [esi + 0xc8]
1c4035b0  mov al, byte ptr [ecx]
1c4035b2  add eax, eax
1c4035b4  mov dword ptr [0x1c412ad4], eax
1c4035b9  mov ecx, dword ptr [esi + 0xd8]
1c4035bf  inc dword ptr [esi + 0xcc]
1c4035c5  mov al, byte ptr [ecx]
1c4035c7  and al, 0x70
1c4035c9  shr al, 1
1c4035cc  movzx ax, al
1c4035d0  mov word ptr [0x1c412aba], ax
1c4035d6  inc dword ptr [esi + 0xd8]
1c4035dc  mov dword ptr [0x1c411d98], 1
1c4035e6  mov dword ptr [0x1c416f44], 0
1c4035f0  test byte ptr [0x1c412ac3], 2
1c4035f7  je 0x1c403600
1c4035f9  mov eax, dword ptr [0x1c412ac0]
1c4035fe  jmp 0x1c403623
1c403600  test byte ptr [0x1c416f4f], 2
1c403607  je 0x1c403610
1c403609  mov eax, dword ptr [0x1c416f4c]
1c40360e  jmp 0x1c403623
1c403610  test byte ptr [0x1c412aaf], 2
1c403617  mov eax, 0
1c40361c  je 0x1c403623
1c40361e  mov eax, dword ptr [0x1c412aac]
1c403623  test eax, 0x400000
1c403628  jne 0x1c403660
1c40362a  test ah, 2
1c40362d  je 0x1c403646
1c40362f  add dword ptr [0x1c412650], 4
1c403636  add dword ptr [0x1c412ad0], 7
1c40363d  add dword ptr [0x1c412ad4], 4
1c403644  jmp 0x1c403660
1c403646  test ah, 0x40
1c403649  je 0x1c403660
1c40364b  sub dword ptr [0x1c412650], 4
1c403652  sub dword ptr [0x1c412ad0], 7
1c403659  sub dword ptr [0x1c412ad4], 4
1c403660  cmp word ptr [esi + 0x4c], 0
1c403665  jne 0x1c4038ce
1c40366b  test byte ptr [0x1c412ac1], 0x20
1c403672  je 0x1c4036a8
1c403674  test byte ptr [0x1c412ab6], 0x80
1c40367b  je 0x1c4036a8
1c40367d  test byte ptr [0x1c416f4f], 0x10
1c403684  je 0x1c4036a8
1c403686  cmp byte ptr [0x1c416f50], 0
1c40368d  je 0x1c4036a8
1c40368f  mov eax, dword ptr [0x1c412650]
1c403694  mov edi, dword ptr [esp + 0x18]
1c403698  sub eax, 0xa
1c40369b  push eax
1c40369c  push edi
1c40369d  push esi
1c40369e  call 0x1c403ee0
1c4036a3  add esp, 0xc
1c4036a6  jmp 0x1c4036ac
1c4036a8  mov edi, dword ptr [esp + 0x18]
1c4036ac  cmp dword ptr [0x1c416f44], 0
1c4036b3  je 0x1c4036f1
1c4036b5  cmp word ptr [0x1c412aba], 0
1c4036bd  je 0x1c4036dc
1c4036bf  movsx eax, word ptr [0x1c412aba]
1c4036c6  add eax, dword ptr [0x1c412ad4]
1c4036cc  push eax
1c4036cd  push edi
1c4036ce  push esi
1c4036cf  call 0x1c403f40
1c4036d4  add esp, 0xc
1c4036d7  pop ebp
1c4036d8  pop edi
1c4036d9  pop esi
1c4036da  pop ebx
1c4036db  ret 
1c4036dc  mov eax, dword ptr [0x1c412ad4]
1c4036e1  push eax
1c4036e2  push edi
1c4036e3  push esi
1c4036e4  call 0x1c403f40
1c4036e9  add esp, 0xc
1c4036ec  pop ebp
1c4036ed  pop edi
1c4036ee  pop esi
1c4036ef  pop ebx
1c4036f0  ret 
1c4036f1  xor eax, eax
1c4036f3  cmp dword ptr [0x1c411d98], eax
1c4036f9  je 0x1c403787
1c4036ff  test byte ptr [0x1c412ac3], 8
1c403706  mov dword ptr [0x1c416f44], eax
1c40370b  je 0x1c403787
1c40370d  test byte ptr [0x1c412ac3], 2
1c403714  mov dword ptr [0x1c411d98], eax
1c403719  je 0x1c40372a
1c40371b  mov eax, dword ptr [0x1c412650]
1c403720  push eax
1c403721  push edi
1c403722  push esi
1c403723  call 0x1c403e90
1c403728  jmp 0x1c403784
1c40372a  test byte ptr [0x1c412ab5], 1
1c403731  je 0x1c40375b
1c403733  mov eax, dword ptr [0x1c412650]
1c403738  push eax
1c403739  push edi
1c40373a  push esi
1c40373b  call 0x1c403e90
1c403740  add esp, 0xc
1c403743  mov eax, dword ptr [0x1c412ad0]
1c403748  add eax, dword ptr [0x1c412650]
1c40374e  sar eax, 1
1c403751  push eax
1c403752  push edi
1c403753  push esi
1c403754  call 0x1c403ee0
1c403759  jmp 0x1c403784
1c40375b  test ebx, ebx
1c40375d  je 0x1c403777
1c40375f  test byte ptr [0x1c416f4f], 2
1c403766  je 0x1c403777
1c403768  mov eax, dword ptr [0x1c412650]
1c40376d  push eax
1c40376e  push edi
1c40376f  push esi
1c403770  call 0x1c403ee0
1c403775  jmp 0x1c403784
1c403777  mov eax, dword ptr [0x1c412650]
1c40377c  push eax
1c40377d  push edi
1c40377e  push esi
1c40377f  call 0x1c403f40
1c403784  add esp, 0xc
1c403787  test byte ptr [0x1c412ac3], 2
1c40378e  je 0x1c403850
1c403794  test byte ptr [0x1c412ab6], 4
1c40379b  je 0x1c4037b8
1c40379d  test byte ptr [0x1c412ab7], 8
1c4037a4  jne 0x1c4037b8
1c4037a6  mov eax, dword ptr [0x1c412ad0]
1c4037ab  add eax, 8
1c4037ae  push eax
1c4037af  push edi
1c4037b0  push esi
1c4037b1  call 0x1c403e90
1c4037b6  jmp 0x1c40381f
1c4037b8  cmp byte ptr [0x1c412ac4], 0
1c4037bf  je 0x1c4037ff
1c4037c1  test ebx, ebx
1c4037c3  je 0x1c4037d4
1c4037c5  mov eax, dword ptr [0x1c412ad0]
1c4037ca  push eax
1c4037cb  push edi
1c4037cc  push esi
1c4037cd  call 0x1c403e90
1c4037d2  jmp 0x1c40381f
1c4037d4  test byte ptr [0x1c4121a4], 0x80
1c4037db  jne 0x1c403812
1c4037dd  test dword ptr [0x1c416f4c], 0x10002000
1c4037e7  mov eax, dword ptr [0x1c412ad0]
1c4037ec  push eax
1c4037ed  push edi
1c4037ee  push esi
1c4037ef  je 0x1c4037f8
1c4037f1  call 0x1c403fa0
1c4037f6  jmp 0x1c40381f
1c4037f8  call 0x1c403f40
1c4037fd  jmp 0x1c40381f
1c4037ff  test ebx, ebx
1c403801  je 0x1c403812
1c403803  mov eax, dword ptr [0x1c412ad0]
1c403808  push eax
1c403809  push edi
1c40380a  push esi
1c40380b  call 0x1c403e90
1c403810  jmp 0x1c40381f
1c403812  mov eax, dword ptr [0x1c412ad0]
1c403817  push eax
1c403818  push edi
1c403819  push esi
1c40381a  call 0x1c403ee0
1c40381f  add esp, 0xc
1c403822  test ebx, ebx
1c403824  jne 0x1c403854
1c403826  cmp word ptr [0x1c412aba], 0
1c40382e  jne 0x1c403850
1c403830  test byte ptr [0x1c4121a4], 0x80
1c403837  mov eax, dword ptr [0x1c412ad4]
1c40383c  push eax
1c40383d  push edi
1c40383e  push esi
1c40383f  je 0x1c403848
1c403841  call 0x1c403f40
1c403846  jmp 0x1c40384d
1c403848  call 0x1c403fa0
1c40384d  add esp, 0xc
1c403850  test ebx, ebx
1c403852  je 0x1c4038ce
1c403854  test ebp, ebp
1c403856  je 0x1c403881
1c403858  cmp word ptr [0x1c412aba], 0
1c403860  jne 0x1c403881
1c403862  mov eax, dword ptr [0x1c412ad4]
1c403867  push eax
1c403868  push edi
1c403869  push esi
1c40386a  call 0x1c403f40
1c40386f  add esp, 0xc
1c403872  mov dword ptr [0x1c416f44], 1
1c40387c  pop ebp
1c40387d  pop edi
1c40387e  pop esi
1c40387f  pop ebx
1c403880  ret 
1c403881  test ebx, ebx
1c403883  je 0x1c4038ce
1c403885  cmp word ptr [0x1c412aba], 0
1c40388d  je 0x1c4038ce
1c40388f  test byte ptr [0x1c412ac3], 2
1c403896  je 0x1c4038a8
1c403898  mov eax, dword ptr [0x1c412ad4]
1c40389d  push eax
1c40389e  push edi
1c40389f  push esi
1c4038a0  call 0x1c403ee0
1c4038a5  add esp, 0xc
1c4038a8  test ebp, ebp
1c4038aa  je 0x1c4038ce
1c4038ac  movsx eax, word ptr [0x1c412aba]
1c4038b3  add eax, dword ptr [0x1c412ad4]
1c4038b9  push eax
1c4038ba  push edi
1c4038bb  push esi
1c4038bc  call 0x1c403f40
1c4038c1  mov dword ptr [0x1c416f44], 1
1c4038cb  add esp, 0xc
1c4038ce  pop ebp
1c4038cf  pop edi
1c4038d0  pop esi
1c4038d1  pop ebx
1c4038d2  ret 
1c4038d3  nop 
1c4038d4  xor byte ptr [eax + eax*2], 0x1c
1c4038d8  nop 
1c4038d9  xor al, 0x40
1c4038db  sbb al, 0x9d
1c4038dd  xor al, 0x40
1c4038df  sbb al, 0xf1
1c4038e1  xor al, 0x40
1c4038e3  sbb al, 0xfb
1c4038e5  xor al, 0x40
1c4038e7  sbb al, 3
1c4038e9  xor eax, 0x5001c40
1c4038ee  add eax, 0x5050505
1c4038f3  add eax, 0x5050505
1c4038f8  add eax, 0x5050505
1c4038fd  add eax, 0x5050505
1c403902  add eax, 0x5050505
1c403907  add eax, 0x5050505
1c40390c  add eax, 0x5050505
1c403911  add eax, 0x5050505
1c403916  add eax, 0x5050505
1c40391b  add eax, 0x5050505
1c403920  add eax, 0x5050505
1c403925  add eax, 0x5050505
1c40392a  add eax, 0x5050505
1c40392f  add eax, 0x5050505
1c403934  add eax, 0x5050505
1c403939  add eax, 0x5050505
1c40393e  add eax, 0x5050505
1c403943  add eax, 0x5010505
1c403948  add eax, 0x5050505
1c40394d  add eax, 0x5050505
1c403952  add eax, 0x5050505
1c403957  add eax, 0x5050505
1c40395c  add eax, 0x5050505
1c403961  add eax, 0x5050505
1c403966  add eax, 0x5050505
1c40396b  add eax, 0x5020505
1c403970  add eax, 0x5050505
1c403975  add eax, 0x5050505
1c40397a  add eax, 0x5050505
1c40397f  add eax, 0x5050505
1c403984  add eax, 0x5050505
1c403989  add eax, 0x5050505
1c40398e  add eax, 0x5050505
1c403993  add eax, 0x5050505
1c403998  add eax, 0x5050505
1c40399d  add eax, 0x5050505
1c4039a2  add eax, 0x5050505
1c4039a7  add eax, 0x5030505
1c4039ac  add eax, 0x5050505
1c4039b1  add eax, 0xcc040505
1c4039b6  int3 
1c4039b7  int3 
1c4039b8  int3 
1c4039b9  int3 
1c4039ba  int3 
1c4039bb  int3 
1c4039bc  int3 
1c4039bd  int3 
1c4039be  int3 
1c4039bf  int3 
1c4039c0  mov eax, dword ptr [esp + 0xc]
1c4039c4  push ebx
1c4039c5  push esi
1c4039c6  push edi
1c4039c7  push ebp
1c4039c8  mov ebx, dword ptr [eax]
1c4039ca  test ebx, ebx
1c4039cc  je 0x1c403aed
1c4039d2  cmp word ptr [ebx], 0x1e
1c4039d6  mov edi, dword ptr [esp + 0x14]
1c4039da  mov esi, dword ptr [esp + 0x18]
1c4039de  je 0x1c403af5
1c4039e4  movsx ecx, word ptr [ebx]
1c4039e7  sub ecx, 0x32
1c4039ea  cmp ecx, 0xc8
1c4039f0  ja 0x1c403ade
1c4039f6  xor eax, eax
1c4039f8  mov al, byte ptr [ecx + 0x1c403b7c]
1c4039fe  jmp dword ptr [eax*4 + 0x1c403b64]
1c403a05  movsx eax, word ptr [ebx + 2]
1c403a09  push eax
1c403a0a  push edi
1c403a0b  call 0x1c404010
1c403a10  add esp, 8
1c403a13  jmp 0x1c403ade
1c403a18  mov ax, word ptr [ebx + 2]
1c403a1c  mov word ptr [edi + 0xae], ax
1c403a23  jmp 0x1c403ade
1c403a28  mov ax, word ptr [ebx + 2]
1c403a2c  test ax, ax
1c403a2f  jg 0x1c403a8c
1c403a31  mov cx, word ptr [edi + 0xac]
1c403a38  imul cx, cx, 0xc
1c403a3c  add cx, word ptr [edi + 0xae]
1c403a43  sub cx, ax
1c403a46  cmp cx, 0x55
1c403a4a  jl 0x1c403a60
1c403a4c  mov bp, 0xc
1c403a50  lea eax, [ecx - 0x49]
1c403a53  sub dx, dx
1c403a56  div bp
1c403a59  imul ax, bp
1c403a5d  sub cx, ax
1c403a60  test cx, cx
1c403a63  jge 0x1c403a7d
1c403a65  mov ax, 0xb
1c403a69  sub ax, cx
1c403a6c  mov bp, 0xc
1c403a70  sub dx, dx
1c403a73  div bp
1c403a76  imul ax, bp
1c403a7a  add cx, ax
1c403a7d  movsx eax, cx
1c403a80  xor ecx, ecx
1c403a82  mov cx, word ptr [eax*2 + 0x1c40db20]
1c403a8a  jmp 0x1c403aa3
1c403a8c  cmp ax, 0x7d0
1c403a90  jl 0x1c403a96
1c403a92  mov ax, 0x7d0
1c403a96  cmp ax, 0xa
1c403a9a  jg 0x1c403aa0
1c403a9c  mov ax, 0xa
1c403aa0  movsx ecx, ax
1c403aa3  mov dx, word ptr [ebx + 4]
1c403aa7  movsx eax, dx
1c403aaa  shl eax, 5
1c403aad  add eax, esi
1c403aaf  cmp word ptr [0x1c4121b6], dx
1c403ab6  jbe 0x1c403ade
1c403ab8  mov word ptr [eax + 0x18], cx
1c403abc  add eax, 0x20
1c403abf  inc dx
1c403ac1  cmp word ptr [0x1c4121b6], dx
1c403ac8  ja 0x1c403ab8
1c403aca  jmp 0x1c403ade
1c403acc  mov ax, word ptr [ebx + 2]
1c403ad0  mov word ptr [edi + 0x4c], ax
1c403ad4  jmp 0x1c403ade
1c403ad6  mov ax, word ptr [ebx + 2]
1c403ada  mov word ptr [edi + 0x60], ax
1c403ade  add ebx, 6
1c403ae1  cmp word ptr [ebx], 0x1e
1c403ae5  jne 0x1c4039e4
1c403aeb  jmp 0x1c403af5
1c403aed  mov edi, dword ptr [esp + 0x14]
1c403af1  mov esi, dword ptr [esp + 0x18]
1c403af5  test byte ptr [0x1c412ac8], 0x80
1c403afc  jne 0x1c403b07
1c403afe  test byte ptr [0x1c412ac3], 0x20
1c403b05  je 0x1c403b5d
1c403b07  test byte ptr [0x1c412ac3], 0x20
1c403b0e  jne 0x1c403b40
1c403b10  cmp byte ptr [0x1c412ace], 0x1c
1c403b17  je 0x1c403b40
1c403b19  xor ecx, ecx
1c403b1b  xor eax, eax
1c403b1d  mov cx, word ptr [edi + 0x46]
1c403b21  mov al, byte ptr [0x1c412ace]
1c403b26  add eax, ecx
1c403b28  and eax, 7
1c403b2b  movsx eax, word ptr [eax*2 + 0x1c40dc98]
1c403b33  imul eax, ecx
1c403b36  cdq 
1c403b37  mov ecx, 0x6e
1c403b3c  idiv ecx
1c403b3e  jmp 0x1c403b48
1c403b40  xor eax, eax
1c403b42  mov ax, word ptr [0x1c4121b0]
1c403b48  mov word ptr [esi + 0x18], ax
1c403b4c  mov cx, word ptr [0x1c4121b0]
1c403b53  mov word ptr [esi - 8], cx
1c403b57  mov word ptr [0x1c4121b0], ax
1c403b5d  pop ebp
1c403b5e  pop edi
1c403b5f  pop esi
1c403b60  pop ebx
1c403b61  ret 
1c403b62  mov edi, edi
1c403b64  add eax, 0x181c403a
1c403b69  cmp al, byte ptr [eax + 0x1c]
1c403b6c  sub byte ptr [edx], bh
1c403b6e  inc eax
1c403b6f  sbb al, 0xcc
1c403b71  cmp al, byte ptr [eax + 0x1c]
1c403b74  salc 
1c403b75  cmp al, byte ptr [eax + 0x1c]
1c403b78  fidivr word ptr [edx]
1c403b7a  inc eax
1c403b7b  sbb al, 0
1c403b7d  add eax, 0x5050505
1c403b82  add eax, 0x5050505
1c403b87  add eax, 0x5050505
1c403b8c  add eax, 0x5050505
1c403b91  add eax, 0x5050505
1c403b96  add eax, 0x5050505
1c403b9b  add eax, 0x5050505
1c403ba0  add eax, 0x5050505
1c403ba5  add eax, 0x5050505
1c403baa  add eax, 0x5050505
1c403baf  add eax, 0x5050505
1c403bb4  add eax, 0x5050505
1c403bb9  add eax, 0x5050505
1c403bbe  add eax, 0x5050505
1c403bc3  add eax, 0x5050505
1c403bc8  add eax, 0x5050505
1c403bcd  add eax, 0x5050505
1c403bd2  add eax, 0x1050505
1c403bd7  add eax, 0x5050505
1c403bdc  add eax, 0x5050505
1c403be1  add eax, 0x5050505
1c403be6  add eax, 0x5050505
1c403beb  add eax, 0x5050505
1c403bf0  add eax, 0x5050505
1c403bf5  add eax, 0x5050505
1c403bfa  add eax, 0x2050505
1c403bff  add eax, 0x5050505
1c403c04  add eax, 0x5050505
1c403c09  add eax, 0x5050505
1c403c0e  add eax, 0x5050505
1c403c13  add eax, 0x5050505
1c403c18  add eax, 0x5050505
1c403c1d  add eax, 0x5050505
1c403c22  add eax, 0x5050505
1c403c27  add eax, 0x5050505
1c403c2c  add eax, 0x5050505
1c403c31  add eax, 0x5050505
1c403c36  add eax, 0x3050505
1c403c3b  add eax, 0x5050505
1c403c40  add eax, 0x4050505
1c403c45  int3 
1c403c46  int3 
1c403c47  int3 
1c403c48  int3 
1c403c49  int3 
1c403c4a  int3 
1c403c4b  int3 
1c403c4c  int3 
1c403c4d  int3 
1c403c4e  int3 
1c403c4f  int3 
1c403c50  mov cx, word ptr [0x1c4121b0]
1c403c57  push ebx
1c403c58  xor dx, dx
1c403c5b  push esi
1c403c5c  cmp word ptr [0x1c4121b6], dx
1c403c63  push edi
1c403c64  mov esi, dword ptr [esp + 0x14]
1c403c68  push ebp
1c403c69  mov eax, esi
1c403c6b  jbe 0x1c403c7f
1c403c6d  mov word ptr [eax + 0x18], cx
1c403c71  add eax, 0x20
1c403c74  inc dx
1c403c76  cmp dx, word ptr [0x1c4121b6]
1c403c7d  jb 0x1c403c6d
1c403c7f  mov eax, dword ptr [esp + 0x1c]
1c403c83  mov ebx, dword ptr [eax]
1c403c85  test ebx, ebx
1c403c87  je 0x1c403da5
1c403c8d  cmp word ptr [ebx], 0x1e
1c403c91  je 0x1c403da5
1c403c97  mov edi, dword ptr [esp + 0x14]
1c403c9b  movsx ecx, word ptr [ebx]
1c403c9e  sub ecx, 0x32
1c403ca1  cmp ecx, 0xc8
1c403ca7  ja 0x1c403d98
1c403cad  xor eax, eax
1c403caf  mov al, byte ptr [ecx + 0x1c403dc4]
1c403cb5  jmp dword ptr [eax*4 + 0x1c403dac]
1c403cbc  movsx eax, word ptr [ebx + 2]
1c403cc0  push eax
1c403cc1  push edi
1c403cc2  call 0x1c404010
1c403cc7  add esp, 8
1c403cca  jmp 0x1c403d98
1c403ccf  mov ax, word ptr [ebx + 2]
1c403cd3  mov word ptr [edi + 0xae], ax
1c403cda  jmp 0x1c403d98
1c403cdf  mov cx, word ptr [ebx + 2]
1c403ce3  test cx, cx
1c403ce6  jg 0x1c403d41
1c403ce8  mov bp, word ptr [edi + 0xac]
1c403cef  imul bp, bp, 0xc
1c403cf3  add bp, word ptr [edi + 0xae]
1c403cfa  sub bp, cx
1c403cfd  cmp bp, 0x55
1c403d01  jl 0x1c403d17
1c403d03  mov cx, 0xc
1c403d07  lea eax, [ebp - 0x49]
1c403d0a  sub dx, dx
1c403d0d  div cx
1c403d10  imul ax, cx
1c403d14  sub bp, ax
1c403d17  test bp, bp
1c403d1a  jge 0x1c403d34
1c403d1c  mov ax, 0xb
1c403d20  sub ax, bp
1c403d23  mov cx, 0xc
1c403d27  sub dx, dx
1c403d2a  div cx
1c403d2d  imul ax, cx
1c403d31  add bp, ax
1c403d34  movsx eax, bp
1c403d37  mov cx, word ptr [eax*2 + 0x1c40db20]
1c403d3f  jmp 0x1c403d56
1c403d41  cmp cx, 0x7d0
1c403d46  jl 0x1c403d4c
1c403d48  mov cx, 0x7d0
1c403d4c  cmp cx, 0xa
1c403d50  jg 0x1c403d56
1c403d52  mov cx, 0xa
1c403d56  mov dx, word ptr [ebx + 4]
1c403d5a  movsx eax, dx
1c403d5d  shl eax, 5
1c403d60  add eax, esi
1c403d62  cmp dx, word ptr [0x1c4121b6]
1c403d69  jae 0x1c403d7d
1c403d6b  mov word ptr [eax + 0x18], cx
1c403d6f  add eax, 0x20
1c403d72  inc dx
1c403d74  cmp dx, word ptr [0x1c4121b6]
1c403d7b  jb 0x1c403d6b
1c403d7d  mov word ptr [0x1c4121b0], cx
1c403d84  jmp 0x1c403d98
1c403d86  mov ax, word ptr [ebx + 2]
1c403d8a  mov word ptr [edi + 0x4c], ax
1c403d8e  jmp 0x1c403d98
1c403d90  mov ax, word ptr [ebx + 2]
1c403d94  mov word ptr [edi + 0x60], ax
1c403d98  add ebx, 6
1c403d9b  cmp word ptr [ebx], 0x1e
1c403d9f  jne 0x1c403c9b
1c403da5  pop ebp
1c403da6  pop edi
1c403da7  pop esi
1c403da8  pop ebx
1c403da9  ret 
1c403daa  mov edi, edi
1c403dac  mov esp, 0xcf1c403c
1c403db1  cmp al, 0x40
1c403db3  sbb al, 0xdf
1c403db5  cmp al, 0x40
1c403db7  sbb al, 0x86
1c403db9  cmp eax, 0x3d901c40
1c403dbe  inc eax
1c403dbf  sbb al, 0x98
1c403dc1  cmp eax, 0x5001c40
1c403dc6  add eax, 0x5050505
1c403dcb  add eax, 0x5050505
1c403dd0  add eax, 0x5050505
1c403dd5  add eax, 0x5050505
1c403dda  add eax, 0x5050505
1c403ddf  add eax, 0x5050505
1c403de4  add eax, 0x5050505
1c403de9  add eax, 0x5050505
1c403dee  add eax, 0x5050505
1c403df3  add eax, 0x5050505
1c403df8  add eax, 0x5050505
1c403dfd  add eax, 0x5050505
1c403e02  add eax, 0x5050505
1c403e07  add eax, 0x5050505
1c403e0c  add eax, 0x5050505
1c403e11  add eax, 0x5050505
1c403e16  add eax, 0x5050505
1c403e1b  add eax, 0x5010505
1c403e20  add eax, 0x5050505
1c403e25  add eax, 0x5050505
1c403e2a  add eax, 0x5050505
1c403e2f  add eax, 0x5050505
1c403e34  add eax, 0x5050505
1c403e39  add eax, 0x5050505
1c403e3e  add eax, 0x5050505
1c403e43  add eax, 0x5020505
1c403e48  add eax, 0x5050505
1c403e4d  add eax, 0x5050505
1c403e52  add eax, 0x5050505
1c403e57  add eax, 0x5050505
1c403e5c  add eax, 0x5050505
1c403e61  add eax, 0x5050505
1c403e66  add eax, 0x5050505
1c403e6b  add eax, 0x5050505
1c403e70  add eax, 0x5050505
1c403e75  add eax, 0x5050505
1c403e7a  add eax, 0x5050505
1c403e7f  add eax, 0x5030505
1c403e84  add eax, 0x5050505
1c403e89  add eax, 0xcc040505
1c403e8e  int3 
1c403e8f  int3 
1c403e90  mov ecx, dword ptr [esp + 0xc]
1c403e94  push esi
1c403e95  cmp ecx, 0x6e
1c403e98  jle 0x1c403eb7
1c403e9a  xor eax, eax
1c403e9c  mov esi, dword ptr [esp + 8]
1c403ea0  mov ax, word ptr [esi + 0x60]
1c403ea4  sub ecx, 0x6e
1c403ea7  imul eax, ecx
1c403eaa  cdq 
1c403eab  mov ecx, 0x64
1c403eb0  idiv ecx
1c403eb2  lea ecx, [eax + 0x6e]
1c403eb5  jmp 0x1c403ebb
1c403eb7  mov esi, dword ptr [esp + 8]
1c403ebb  xor eax, eax
1c403ebd  mov ax, word ptr [esi + 0x46]
1c403ec1  imul eax, ecx
1c403ec4  cdq 
1c403ec5  mov ecx, 0x6e
1c403eca  idiv ecx
1c403ecc  mov edx, dword ptr [esp + 0xc]
1c403ed0  pop esi
1c403ed1  mov word ptr [edx + 0x18], ax
1c403ed5  ret 
1c403ed6  int3 
1c403ed7  int3 
1c403ed8  int3 
1c403ed9  int3 
1c403eda  int3 
1c403edb  int3 
1c403edc  int3 
1c403edd  int3 
1c403ede  int3 
1c403edf  int3 
1c403ee0  mov ecx, dword ptr [esp + 0xc]
1c403ee4  push esi
1c403ee5  cmp ecx, 0x6e
1c403ee8  jle 0x1c403f07
1c403eea  xor eax, eax
1c403eec  mov esi, dword ptr [esp + 8]
1c403ef0  mov ax, word ptr [esi + 0x60]
1c403ef4  sub ecx, 0x6e
1c403ef7  imul eax, ecx
1c403efa  cdq 
1c403efb  mov ecx, 0x64
1c403f00  idiv ecx
1c403f02  lea ecx, [eax + 0x6e]
1c403f05  jmp 0x1c403f0b
1c403f07  mov esi, dword ptr [esp + 8]
1c403f0b  xor eax, eax
1c403f0d  mov ax, word ptr [esi + 0x46]
1c403f11  imul eax, ecx
1c403f14  cdq 
1c403f15  mov ecx, 0x6e
1c403f1a  idiv ecx
1c403f1c  xor edx, edx
1c403f1e  mov ecx, dword ptr [esp + 0xc]
1c403f22  mov dx, word ptr [0x1c4121b6]
1c403f29  pop esi
1c403f2a  and edx, 0xfffffffe
1c403f2d  shl edx, 4
1c403f30  mov word ptr [edx + ecx + 0x18], ax
1c403f35  ret 
1c403f36  int3 
1c403f37  int3 
1c403f38  int3 
1c403f39  int3 
1c403f3a  int3 
1c403f3b  int3 
1c403f3c  int3 
1c403f3d  int3 
1c403f3e  int3 
1c403f3f  int3 
1c403f40  mov ecx, dword ptr [esp + 0xc]
1c403f44  push esi
1c403f45  cmp ecx, 0x6e
1c403f48  jle 0x1c403f67
1c403f4a  xor eax, eax
1c403f4c  mov esi, dword ptr [esp + 8]
1c403f50  mov ax, word ptr [esi + 0x60]
1c403f54  sub ecx, 0x6e
1c403f57  imul eax, ecx
1c403f5a  cdq 
1c403f5b  mov ecx, 0x64
1c403f60  idiv ecx
1c403f62  lea ecx, [eax + 0x6e]
1c403f65  jmp 0x1c403f6b
1c403f67  mov esi, dword ptr [esp + 8]
1c403f6b  xor eax, eax
1c403f6d  mov ax, word ptr [esi + 0x46]
1c403f71  imul eax, ecx
1c403f74  cdq 
1c403f75  mov ecx, 0x6e
1c403f7a  idiv ecx
1c403f7c  xor edx, edx
1c403f7e  mov ecx, dword ptr [esp + 0xc]
1c403f82  mov dx, word ptr [0x1c4121b6]
1c403f89  pop esi
1c403f8a  shl edx, 5
1c403f8d  mov word ptr [edx + ecx - 8], ax
1c403f92  ret 
1c403f93  int3 
1c403f94  int3 
1c403f95  int3 
1c403f96  int3 
1c403f97  int3 
1c403f98  int3 
1c403f99  int3 
1c403f9a  int3 
1c403f9b  int3 
1c403f9c  int3 
1c403f9d  int3 
1c403f9e  int3 
1c403f9f  int3 
1c403fa0  mov ecx, dword ptr [esp + 0xc]
1c403fa4  push esi
1c403fa5  cmp ecx, 0x6e
1c403fa8  jle 0x1c403fc7
1c403faa  xor eax, eax
1c403fac  mov esi, dword ptr [esp + 8]
1c403fb0  mov ax, word ptr [esi + 0x60]
1c403fb4  sub ecx, 0x6e
1c403fb7  imul eax, ecx
1c403fba  cdq 
1c403fbb  mov ecx, 0x64
1c403fc0  idiv ecx
1c403fc2  lea ecx, [eax + 0x6e]
1c403fc5  jmp 0x1c403fcb
1c403fc7  mov esi, dword ptr [esp + 8]
1c403fcb  xor eax, eax
1c403fcd  mov ax, word ptr [esi + 0x46]
1c403fd1  imul eax, ecx
1c403fd4  cdq 
1c403fd5  mov ecx, 0x6e
1c403fda  idiv ecx
1c403fdc  xor edx, edx
1c403fde  xor ecx, ecx
1c403fe0  mov dx, word ptr [0x1c412ab0]
1c403fe7  mov esi, dword ptr [esp + 0xc]
1c403feb  mov cx, word ptr [0x1c4121b6]
1c403ff2  and edx, 0xfffffffe
1c403ff5  shl edx, 4
1c403ff8  shl ecx, 5
1c403ffb  add edx, ecx
1c403ffd  mov word ptr [edx + esi + 0x18], ax
1c404002  pop esi
1c404003  ret 
1c404004  int3 
1c404005  int3 
1c404006  int3 
1c404007  int3 
1c404008  int3 
1c404009  int3 
1c40400a  int3 
1c40400b  int3 
1c40400c  int3 
1c40400d  int3 
1c40400e  int3 
1c40400f  int3 
1c404010  ret 
1c404011  int3 
1c404012  int3 
1c404013  int3 
1c404014  int3 
1c404015  int3 
1c404016  int3 
1c404017  int3 
1c404018  int3 
1c404019  int3 
1c40401a  int3 
1c40401b  int3 
1c40401c  int3 
1c40401d  int3 
1c40401e  int3 
1c40401f  int3 
1c404020  sub esp, 0x48
1c404023  mov dword ptr [esp + 0x3c], 0
1c40402b  push ebx
1c40402c  push esi
1c40402d  mov esi, dword ptr [esp + 0x54]
1c404031  push edi
1c404032  push ebp
1c404033  mov eax, dword ptr [esi + 0x28]
1c404036  cmp word ptr [eax + 0xc], 0xff
1c40403c  jne 0x1c404052
1c40403e  xor eax, eax
1c404040  pop ebp
1c404041  mov dword ptr [0x1c40dc4c], 1
1c40404b  pop edi
1c40404c  pop esi
1c40404d  pop ebx
1c40404e  add esp, 0x48
1c404051  ret 
1c404052  mov eax, dword ptr [esi + 0xfa]
1c404058  xor ecx, ecx
1c40405a  mov dword ptr [0x1c412aa8], eax
1c40405f  cmp dword ptr [0x1c40dc4c], ecx
1c404065  je 0x1c404386
1c40406b  mov dword ptr [0x1c412ae0], 0x1c4122e0
1c404075  mov dword ptr [0x1c412ae4], 0x1c412320
1c40407f  mov dword ptr [0x1c412ae8], 0x1c4123a0
1c404089  mov dword ptr [0x1c412aec], 0x1c4123e0
1c404093  mov dword ptr [0x1c412af0], 0x1c412200
1c40409d  mov dword ptr [0x1c412af4], 0x1c412250
1c4040a7  mov dword ptr [0x1c412af8], 0x1c412290
1c4040b1  mov dword ptr [0x1c412afc], 0x1c412500
1c4040bb  mov dword ptr [0x1c412b00], 0x1c412360
1c4040c5  mov dword ptr [0x1c412b04], 0x1c412420
1c4040cf  mov dword ptr [0x1c412b08], 0x1c412470
1c4040d9  mov dword ptr [0x1c412b0c], 0x1c412540
1c4040e3  mov dword ptr [0x1c412b10], 0x1c412580
1c4040ed  mov dword ptr [0x1c412b14], 0x1c412660
1c4040f7  mov dword ptr [0x1c412b18], 0x1c4124c0
1c404101  mov dword ptr [0x1c412b1c], 0x1c4125c0
1c40410b  mov dword ptr [0x1c412b20], 0x1c412610
1c404115  mov eax, 0x1c412b40
1c40411a  mov dword ptr [0x1c4121c4], eax
1c40411f  mov dword ptr [0x1c4122e4], eax
1c404124  mov eax, 0x1c412f40
1c404129  mov dword ptr [0x1c4121cc], eax
1c40412e  mov dword ptr [0x1c412324], eax
1c404133  mov eax, 0x1c413340
1c404138  mov dword ptr [0x1c4121d0], eax
1c40413d  mov dword ptr [0x1c4123a4], eax
1c404142  mov eax, 0x1c413740
1c404147  mov dword ptr [0x1c4121d8], eax
1c40414c  mov dword ptr [0x1c4123e4], eax
1c404151  mov eax, 0x1c413b40
1c404156  mov dword ptr [0x1c4121b8], eax
1c40415b  mov dword ptr [0x1c412204], eax
1c404160  mov eax, 0x1c413f40
1c404165  mov dword ptr [0x1c4121bc], eax
1c40416a  mov dword ptr [0x1c412254], eax
1c40416f  mov eax, 0x1c414340
1c404174  mov dword ptr [0x1c4121c0], eax
1c404179  mov dword ptr [0x1c412294], eax
1c40417e  mov eax, 0x1c414740
1c404183  mov dword ptr [0x1c4121e8], eax
1c404188  mov dword ptr [0x1c412504], eax
1c40418d  mov eax, 0x1c414b40
1c404192  mov dword ptr [0x1c4121c8], eax
1c404197  mov dword ptr [0x1c412364], eax
1c40419c  mov eax, 0x1c414f40
1c4041a1  mov dword ptr [0x1c4121d4], eax
1c4041a6  mov dword ptr [0x1c412424], eax
1c4041ab  mov eax, 0x1c415340
1c4041b0  mov dword ptr [0x1c4121e0], eax
1c4041b5  mov dword ptr [0x1c412474], eax
1c4041ba  mov eax, 0x1c415740
1c4041bf  mov dword ptr [0x1c4121ec], eax
1c4041c4  mov dword ptr [0x1c412544], eax
1c4041c9  mov eax, 0x1c415b40
1c4041ce  mov dword ptr [0x1c4121f0], eax
1c4041d3  mov dword ptr [0x1c412584], eax
1c4041d8  mov eax, 0x1c415f40
1c4041dd  mov dword ptr [0x1c4124b4], eax
1c4041e2  mov dword ptr [0x1c412664], eax
1c4041e7  mov eax, 0x1c416340
1c4041ec  mov dword ptr [0x1c4121e4], eax
1c4041f1  mov dword ptr [0x1c4124c4], eax
1c4041f6  mov eax, 0x1c416740
1c4041fb  mov dword ptr [0x1c4121f4], eax
1c404200  mov dword ptr [0x1c4125c4], eax
1c404205  mov word ptr [0x1c412aa0], cx
1c40420c  mov eax, 0x1c416b40
1c404211  mov word ptr [0x1c412aba], cx
1c404218  mov dword ptr [0x1c4122d0], eax
1c40421d  mov dword ptr [0x1c412614], eax
1c404222  mov dword ptr [0x1c411d98], ecx
1c404228  mov eax, 0x6e
1c40422d  mov dword ptr [0x1c416f44], ecx
1c404233  mov dword ptr [0x1c412ad4], eax
1c404238  mov dword ptr [0x1c412ad0], eax
1c40423d  mov edx, 0x190
1c404242  mov dword ptr [0x1c412650], eax
1c404247  mov eax, 0x64
1c40424c  mov dword ptr [0x1c412b34], ecx
1c404252  mov dword ptr [0x1c4122e8], eax
1c404257  mov dword ptr [0x1c4124c8], ecx
1c40425d  mov dword ptr [0x1c412328], edx
1c404263  mov dword ptr [0x1c412208], eax
1c404268  mov dword ptr [0x1c412668], 0xf
1c404272  mov dword ptr [0x1c4123a8], 0x578
1c40427c  mov dword ptr [0x1c412258], eax
1c404281  mov dword ptr [0x1c412588], edx
1c404287  mov dword ptr [0x1c412508], ecx
1c40428d  mov dword ptr [0x1c412428], ecx
1c404293  mov dword ptr [0x1c412368], ecx
1c404299  mov dword ptr [0x1c412478], ecx
1c40429f  mov dword ptr [0x1c4125c8], ecx
1c4042a5  mov dword ptr [0x1c412618], ecx
1c4042ab  mov dword ptr [0x1c4123e8], 0x960
1c4042b5  mov dword ptr [0x1c412298], 0xc8
1c4042bf  mov dword ptr [0x1c412548], 0xbb8
1c4042c9  movsx ebx, word ptr [esi + 0x98]
1c4042d0  movsx eax, word ptr [esi + 0x9c]
1c4042d7  mov dword ptr [esp + 0x38], ebx
1c4042db  mov dword ptr [esp + 0x3c], eax
1c4042df  movsx edx, word ptr [esi + 0x9a]
1c4042e6  mov ax, word ptr [esi + 0x46]
1c4042ea  mov dword ptr [esp + 0x40], edx
1c4042ee  movsx ebx, word ptr [esi + 0x9e]
1c4042f5  mov edx, dword ptr [0x1c412aa8]
1c4042fb  mov dword ptr [esp + 0x44], ebx
1c4042ff  mov word ptr [edx + 0x18], ax
1c404303  mov edx, dword ptr [0x1c412aa8]
1c404309  mov ax, word ptr [edx + 0x18]
1c40430d  mov di, ax
1c404310  mov word ptr [0x1c4121b0], ax
1c404316  xor eax, eax
1c404318  mov edx, dword ptr [esi + 0x28]
1c40431b  mov ax, word ptr [edx + 0xe]
1c40431f  add eax, 4
1c404322  cdq 
1c404323  and edx, 7
1c404326  add eax, edx
1c404328  mov edx, dword ptr [0x1c412aa8]
1c40432e  sar eax, 3
1c404331  shl eax, 5
1c404334  mov word ptr [eax + edx + 0x18], di
1c404339  movzx eax, cx
1c40433c  inc cx
1c40433e  mov edi, dword ptr [eax*4 + 0x1c412ae0]
1c404345  cmp cx, 0x11
1c404349  lea edx, [eax*4]
1c404350  mov eax, dword ptr [edi + 8]
1c404353  mov dword ptr [edi + 0x14], eax
1c404356  mov dword ptr [edi + 0x10], eax
1c404359  mov dword ptr [edi + 0xc], eax
1c40435c  mov eax, dword ptr [edi + 8]
1c40435f  mov dword ptr [edi + 0x24], eax
1c404362  mov dword ptr [edi + 0x20], eax
1c404365  mov dword ptr [edi + 0x1c], eax
1c404368  mov dword ptr [edi + 0x18], eax
1c40436b  mov edx, dword ptr [edx + 0x1c40dc50]
1c404371  mov dword ptr [edi], edx
1c404373  jb 0x1c404339
1c404375  mov byte ptr [0x1c412ab9], 1
1c40437c  mov dword ptr [0x1c40dc4c], 0
1c404386  mov ecx, dword ptr [esi + 0x20]
1c404389  mov al, byte ptr [ecx + 0xc]
1c40438c  mov byte ptr [0x1c416f51], al
1c404391  mov edx, dword ptr [ecx + 0x12]
1c404394  mov dword ptr [0x1c412b2c], edx
1c40439a  mov eax, dword ptr [ecx + 0x16]
1c40439d  and al, 0x10
1c40439f  mov byte ptr [0x1c412b30], al
1c4043a4  mov dl, byte ptr [ecx + 0x10]
1c4043a7  mov byte ptr [0x1c4121a0], dl
1c4043ad  mov eax, dword ptr [ecx + 0x16]
1c4043b0  mov dword ptr [0x1c416f48], eax
1c4043b5  xor eax, eax
1c4043b7  mov ax, word ptr [ecx + 0xe]
1c4043bb  push ecx
1c4043bc  add eax, 4
1c4043bf  cdq 
1c4043c0  and edx, 7
1c4043c3  add eax, edx
1c4043c5  sar eax, 3
1c4043c8  mov word ptr [0x1c412602], ax
1c4043ce  call 0x1c402c60
1c4043d3  mov word ptr [0x1c412600], ax
1c4043d9  add esp, 4
1c4043dc  mov ecx, dword ptr [esi + 0x24]
1c4043df  mov dl, byte ptr [ecx + 0xc]
1c4043e2  mov byte ptr [0x1c416f53], dl
1c4043e8  mov eax, dword ptr [ecx + 0x12]
1c4043eb  mov dword ptr [0x1c412ab4], eax
1c4043f0  mov eax, dword ptr [ecx + 0x16]
1c4043f3  and al, 0x10
1c4043f5  mov byte ptr [0x1c412ab8], al
1c4043fa  mov dl, byte ptr [ecx + 0x10]
1c4043fd  mov byte ptr [0x1c416f52], dl
1c404403  mov eax, dword ptr [ecx + 0x16]
1c404406  mov dword ptr [0x1c416f40], eax
1c40440b  xor eax, eax
1c40440d  mov ax, word ptr [ecx + 0xe]
1c404411  push ecx
1c404412  add eax, 4
1c404415  cdq 
1c404416  and edx, 7
1c404419  add eax, edx
1c40441b  sar eax, 3
1c40441e  mov word ptr [0x1c4121a8], ax
1c404424  call 0x1c402c60
1c404429  mov word ptr [0x1c412240], ax
1c40442f  add esp, 4
1c404432  mov edx, dword ptr [esi + 0x28]
1c404435  mov dword ptr [esp + 0x28], edx
1c404439  mov al, byte ptr [edx + 0xc]
1c40443c  mov byte ptr [0x1c412ace], al
1c404441  mov ecx, dword ptr [edx + 0x12]
1c404444  mov dword ptr [0x1c412ac0], ecx
1c40444a  mov eax, dword ptr [edx + 0x16]
1c40444d  and al, 0x10
1c40444f  mov byte ptr [0x1c412ac4], al
1c404454  mov cl, byte ptr [edx + 0x10]
1c404457  mov byte ptr [0x1c412b24], cl
1c40445d  mov eax, dword ptr [edx + 0x16]
1c404460  mov dword ptr [0x1c412ac8], eax
1c404465  xor eax, eax
1c404467  mov ax, word ptr [edx + 0xe]
1c40446b  add eax, 4
1c40446e  cdq 
1c40446f  and edx, 7
1c404472  add eax, edx
1c404474  mov edx, dword ptr [esp + 0x28]
1c404478  sar eax, 3
1c40447b  push edx
1c40447c  mov word ptr [0x1c4121b6], ax
1c404482  call 0x1c402c60
1c404487  mov word ptr [0x1c4121b4], ax
1c40448d  add esp, 4
1c404490  mov ecx, dword ptr [esi + 0x2c]
1c404493  mov dl, byte ptr [ecx + 0xc]
1c404496  mov byte ptr [0x1c412460], dl
1c40449c  cmp dl, 0xff
1c40449f  jne 0x1c4044a8
1c4044a1  mov byte ptr [0x1c412460], 0x1b
1c4044a8  mov eax, dword ptr [ecx + 0x12]
1c4044ab  mov dword ptr [0x1c416f4c], eax
1c4044b0  mov eax, dword ptr [ecx + 0x16]
1c4044b3  and al, 0x10
1c4044b5  mov byte ptr [0x1c416f50], al
1c4044ba  mov dl, byte ptr [ecx + 0x10]
1c4044bd  mov byte ptr [0x1c4121ae], dl
1c4044c3  mov eax, dword ptr [ecx + 0x16]
1c4044c6  mov dword ptr [0x1c4121a4], eax
1c4044cb  xor eax, eax
1c4044cd  mov ax, word ptr [ecx + 0xe]
1c4044d1  push ecx
1c4044d2  add eax, 4
1c4044d5  cdq 
1c4044d6  and edx, 7
1c4044d9  add eax, edx
1c4044db  sar eax, 3
1c4044de  mov word ptr [0x1c412ab0], ax
1c4044e4  call 0x1c402c60
1c4044e9  mov word ptr [0x1c412acc], ax
1c4044ef  add esp, 4
1c4044f2  mov ecx, dword ptr [esi + 0x30]
1c4044f5  mov dword ptr [esp + 0x30], ecx
1c4044f9  mov al, byte ptr [ecx + 0xc]
1c4044fc  mov byte ptr [0x1c412604], al
1c404501  cmp al, 0xff
1c404503  jne 0x1c40450c
1c404505  mov byte ptr [0x1c412604], 0x1b
1c40450c  mov ecx, dword ptr [esp + 0x30]
1c404510  mov eax, dword ptr [ecx + 0x12]
1c404513  mov dword ptr [0x1c412aac], eax
1c404518  mov eax, dword ptr [ecx + 0x16]
1c40451b  and al, 0x10
1c40451d  mov byte ptr [0x1c412ab2], al
1c404522  mov dl, byte ptr [ecx + 0x10]
1c404525  mov byte ptr [0x1c412abc], dl
1c40452b  mov eax, dword ptr [ecx + 0x16]
1c40452e  mov dword ptr [0x1c412aa4], eax
1c404533  xor eax, eax
1c404535  mov ax, word ptr [ecx + 0xe]
1c404539  push ecx
1c40453a  add eax, 4
1c40453d  cdq 
1c40453e  and edx, 7
1c404541  add eax, edx
1c404543  sar eax, 3
1c404546  mov word ptr [0x1c411d96], ax
1c40454c  call 0x1c402c60
1c404551  mov word ptr [0x1c4124b0], ax
1c404557  add esp, 4
1c40455a  mov cl, byte ptr [0x1c412ab9]
1c404560  mov edx, 7
1c404565  mov edi, 0x32
1c40456a  mov ebx, 0x19
1c40456f  mov ebp, 0x4b
1c404574  mov byte ptr [0x1c412ab3], cl
1c40457a  xor cx, cx
1c40457d  movzx eax, cx
1c404580  inc cx
1c404582  mov eax, dword ptr [eax*4 + 0x1c412ae0]
1c404589  cmp cx, 0x11
1c40458d  mov dword ptr [eax + 0x28], edi
1c404590  mov dword ptr [eax + 0x38], ebx
1c404593  mov dword ptr [eax + 0x3c], ebp
1c404596  mov dword ptr [eax + 0x2c], edx
1c404599  mov dword ptr [eax + 0x30], edx
1c40459c  mov dword ptr [eax + 0x34], 3
1c4045a3  jb 0x1c40457d
1c4045a5  mov ax, word ptr [0x1c4121dc]
1c4045ab  mov edx, dword ptr [esp + 0x28]
1c4045af  mov word ptr [0x1c412ad8], ax
1c4045b5  push edx
1c4045b6  call 0x1c4019c0
1c4045bb  add esp, 4
1c4045be  push esi
1c4045bf  call 0x1c402d00
1c4045c4  mov edx, dword ptr [esp + 0x2c]
1c4045c8  add esp, 4
1c4045cb  push edx
1c4045cc  call 0x1c40a9e0
1c4045d1  mov cx, word ptr [esi + 0x5e]
1c4045d5  add esp, 4
1c4045d8  add cx, 3
1c4045dc  mov eax, 5
1c4045e1  mov dword ptr [0x1c412414], eax
1c4045e6  mov dword ptr [0x1c4123d4], eax
1c4045eb  mov dword ptr [0x1c412354], eax
1c4045f0  mov dword ptr [0x1c4122c4], eax
1c4045f5  mov dword ptr [0x1c412284], eax
1c4045fa  mov dword ptr [0x1c412234], eax
1c4045ff  movsx edx, cx
1c404602  mov dword ptr [0x1c4125b4], edx
1c404608  mov dword ptr [0x1c412574], edx
1c40460e  movsx eax, word ptr [esi + 0x7e]
1c404612  add eax, 3
1c404615  mov dword ptr [0x1c412534], eax
1c40461a  movsx eax, word ptr [esi + 0x80]
1c404621  xor di, di
1c404624  add eax, 3
1c404627  mov dword ptr [0x1c412454], eax
1c40462c  movsx eax, word ptr [esi + 0x82]
1c404633  add eax, 3
1c404636  mov dword ptr [0x1c4124a4], eax
1c40463b  mov dword ptr [0x1c412394], eax
1c404640  movzx eax, di
1c404643  inc di
1c404645  mov ecx, dword ptr [eax*4 + 0x1c412ae0]
1c40464c  push ecx
1c40464d  call 0x1c403200
1c404652  add esp, 4
1c404655  cmp di, 0x11
1c404659  jb 0x1c404640
1c40465b  xor dx, dx
1c40465e  mov edi, dword ptr [0x1c412504]
1c404664  cmp word ptr [0x1c4121b6], dx
1c40466b  mov ecx, dword ptr [0x1c412424]
1c404671  mov ebx, dword ptr [0x1c412364]
1c404677  jbe 0x1c4046dd
1c404679  mov ax, word ptr [edi]
1c40467c  test ax, ax
1c40467f  jg 0x1c404684
1c404681  xor ax, ax
1c404684  movsx ebp, ax
1c404687  movzx ax, byte ptr [ebp + 0x1c40609e]
1c40468f  mov word ptr [edi], ax
1c404692  mov ax, word ptr [ecx]
1c404695  test ax, ax
1c404698  jg 0x1c40469d
1c40469a  xor ax, ax
1c40469d  movsx ebp, ax
1c4046a0  movzx ax, byte ptr [ebp + 0x1c40609e]
1c4046a8  sub ax, 0xa
1c4046ac  mov word ptr [ecx], ax
1c4046af  mov ax, word ptr [ebx]
1c4046b2  test ax, ax
1c4046b5  jg 0x1c4046ba
1c4046b7  xor ax, ax
1c4046ba  inc dx
1c4046bc  add edi, 2
1c4046bf  movsx ebp, ax
1c4046c2  add ecx, 2
1c4046c5  add ebx, 2
1c4046c8  movzx ax, byte ptr [ebp + 0x1c40609e]
1c4046d0  mov word ptr [ebx - 2], ax
1c4046d4  cmp word ptr [0x1c4121b6], dx
1c4046db  ja 0x1c404679
1c4046dd  call 0x1c4033c0
1c4046e2  test byte ptr [0x1c412ac2], 4
1c4046e9  je 0x1c4047cf
1c4046ef  test byte ptr [0x1c412ac3], 8
1c4046f6  je 0x1c4047cf
1c4046fc  cmp byte ptr [0x1c412ac4], 0
1c404703  je 0x1c4047cf
1c404709  test byte ptr [0x1c412ab7], 0x20
1c404710  jne 0x1c404728
1c404712  test byte ptr [0x1c416f40], 8
1c404719  jne 0x1c404728
1c40471b  cmp byte ptr [0x1c412ace], 0x4f
1c404722  jne 0x1c4047cf
1c404728  test byte ptr [0x1c412ab7], 8
1c40472f  je 0x1c40474d
1c404731  test byte ptr [0x1c412ab6], 0x80
1c404738  je 0x1c40474d
1c40473a  cmp word ptr [esi + 0x2f2], 2
1c404742  je 0x1c40474d
1c404744  mov word ptr [esp + 0x1c], 5
1c40474b  jmp 0x1c404754
1c40474d  mov word ptr [esp + 0x1c], 0x3c
1c404754  mov ebp, dword ptr [0x1c412504]
1c40475a  mov eax, dword ptr [0x1c412424]
1c40475f  mov ecx, dword ptr [0x1c412324]
1c404765  mov edx, dword ptr [0x1c412204]
1c40476b  mov word ptr [esp + 0x16], 0
1c404772  cmp word ptr [0x1c4121b6], 0
1c40477a  mov edi, dword ptr [0x1c412254]
1c404780  jbe 0x1c4047cf
1c404782  mov bx, word ptr [esp + 0x1c]
1c404787  add ebp, 2
1c40478a  sub word ptr [ebp - 2], bx
1c40478e  add eax, 2
1c404791  mov word ptr [eax - 2], 0
1c404797  cmp word ptr [esi + 0x52], 1
1c40479c  jne 0x1c4047a5
1c40479e  mov word ptr [ecx], 0xfa
1c4047a3  jmp 0x1c4047aa
1c4047a5  mov word ptr [ecx], 0x78
1c4047aa  add word ptr [edx], 0x28
1c4047ae  add ecx, 2
1c4047b1  add word ptr [edi], 0xfa
1c4047b6  add edx, 2
1c4047b9  inc word ptr [esp + 0x16]
1c4047be  add edi, 2
1c4047c1  mov bx, word ptr [esp + 0x16]
1c4047c6  cmp word ptr [0x1c4121b6], bx
1c4047cd  ja 0x1c404782
1c4047cf  test byte ptr [0x1c412ac1], 0x80
1c4047d6  je 0x1c4047ea
1c4047d8  mov dword ptr [esp + 0x48], 1
1c4047e0  mov dword ptr [esp + 0x34], 0x10
1c4047e8  jmp 0x1c4047f4
1c4047ea  xor eax, eax
1c4047ec  mov dword ptr [esp + 0x48], eax
1c4047f0  mov dword ptr [esp + 0x34], eax
1c4047f4  mov eax, dword ptr [0x1c4122e4]
1c4047f9  mov ecx, dword ptr [0x1c412324]
1c4047ff  mov edx, dword ptr [0x1c4123a4]
1c404805  mov dword ptr [0x1c4121c4], eax
1c40480a  mov eax, dword ptr [0x1c4123e4]
1c40480f  mov dword ptr [0x1c4121cc], ecx
1c404815  mov ecx, dword ptr [0x1c412204]
1c40481b  mov dword ptr [0x1c4121d0], edx
1c404821  mov edx, dword ptr [0x1c412254]
1c404827  mov dword ptr [0x1c4121d8], eax
1c40482c  mov eax, dword ptr [0x1c412294]
1c404831  mov dword ptr [0x1c4121b8], ecx
1c404837  mov ecx, dword ptr [0x1c412544]
1c40483d  mov dword ptr [0x1c4121bc], edx
1c404843  mov edx, dword ptr [0x1c412584]
1c404849  mov dword ptr [0x1c4121c0], eax
1c40484e  mov eax, dword ptr [0x1c412504]
1c404853  mov dword ptr [0x1c4121ec], ecx
1c404859  mov ecx, dword ptr [0x1c412424]
1c40485f  mov dword ptr [0x1c4121f0], edx
1c404865  mov edx, dword ptr [0x1c412364]
1c40486b  mov dword ptr [0x1c4121e8], eax
1c404870  mov eax, dword ptr [0x1c412474]
1c404875  mov dword ptr [0x1c4121d4], ecx
1c40487b  mov ecx, dword ptr [0x1c4124c4]
1c404881  mov dword ptr [0x1c4121c8], edx
1c404887  mov edx, dword ptr [0x1c412664]
1c40488d  mov dword ptr [0x1c4121e0], eax
1c404892  mov eax, dword ptr [0x1c412614]
1c404897  mov dword ptr [0x1c4121e4], ecx
1c40489d  mov ecx, dword ptr [0x1c4125c4]
1c4048a3  mov dword ptr [0x1c4124b4], edx
1c4048a9  mov dword ptr [0x1c4122d0], eax
1c4048ae  mov dword ptr [0x1c4121f4], ecx
1c4048b4  mov word ptr [esp + 0x16], 0
1c4048bb  cmp word ptr [0x1c4121b6], 0
1c4048c3  jbe 0x1c4058f4
1c4048c9  mov ebx, dword ptr [esp + 0x1c]
1c4048cd  mov edi, dword ptr [esp + 0x1c]
1c4048d1  mov edx, dword ptr [esp + 0x28]
1c4048d5  mov edx, dword ptr [edx]
1c4048d7  test edx, edx
1c4048d9  je 0x1c404caa
1c4048df  cmp word ptr [edx], 0x1e
1c4048e3  je 0x1c404caa
1c4048e9  mov ecx, dword ptr [esp + 0x16]
1c4048ed  and ecx, 0xffff
1c4048f3  movsx eax, word ptr [edx + 4]
1c4048f7  cmp eax, ecx
1c4048f9  jne 0x1c404c9d
1c4048ff  movsx eax, word ptr [edx]
1c404902  cmp eax, 0xbe
1c404907  jg 0x1c40491d
1c404909  je 0x1c404b7b
1c40490f  cmp eax, 0x32
1c404912  je 0x1c404a3d
1c404918  jmp 0x1c404c9d
1c40491d  cmp eax, 0xdc
1c404922  jg 0x1c40493a
1c404924  je 0x1c404b95
1c40492a  cmp eax, 0xc8
1c40492f  je 0x1c404b88
1c404935  jmp 0x1c404c9d
1c40493a  cmp eax, 0xf0
1c40493f  jg 0x1c404957
1c404941  je 0x1c404bb5
1c404947  cmp eax, 0xe6
1c40494c  je 0x1c404ba5
1c404952  jmp 0x1c404c9d
1c404957  cmp eax, 0x14a
1c40495c  jg 0x1c404974
1c40495e  je 0x1c404bcf
1c404964  cmp eax, 0x140
1c404969  je 0x1c404bc2
1c40496f  jmp 0x1c404c9d
1c404974  cmp eax, 0x15e
1c404979  jg 0x1c404991
1c40497b  je 0x1c404be9
1c404981  cmp eax, 0x154
1c404986  je 0x1c404bdc
1c40498c  jmp 0x1c404c9d
1c404991  cmp eax, 0x172
1c404996  jg 0x1c4049ae
1c404998  je 0x1c404c09
1c40499e  cmp eax, 0x168
1c4049a3  je 0x1c404bf9
1c4049a9  jmp 0x1c404c9d
1c4049ae  cmp eax, 0x186
1c4049b3  jg 0x1c4049cb
1c4049b5  je 0x1c404c26
1c4049bb  cmp eax, 0x17c
1c4049c0  je 0x1c404c19
1c4049c6  jmp 0x1c404c9d
1c4049cb  cmp eax, 0x1fe
1c4049d0  jg 0x1c4049e8
1c4049d2  je 0x1c404c40
1c4049d8  cmp eax, 0x1f4
1c4049dd  je 0x1c404c33
1c4049e3  jmp 0x1c404c9d
1c4049e8  cmp eax, 0x226
1c4049ed  jg 0x1c404a05
1c4049ef  je 0x1c404c5a
1c4049f5  cmp eax, 0x208
1c4049fa  je 0x1c404c4d
1c404a00  jmp 0x1c404c9d
1c404a05  cmp eax, 0x23a
1c404a0a  jg 0x1c404a22
1c404a0c  je 0x1c404c74
1c404a12  cmp eax, 0x230
1c404a17  je 0x1c404c67
1c404a1d  jmp 0x1c404c9d
1c404a22  cmp eax, 0x334
1c404a27  je 0x1c404c81
1c404a2d  cmp eax, 0x352
1c404a32  je 0x1c404c91
1c404a38  jmp 0x1c404c9d
1c404a3d  movsx eax, word ptr [edx + 2]
1c404a41  mov ebp, eax
1c404a43  lea eax, [eax + eax*8]
1c404a46  cmp word ptr [esi + 0x4c], 3
1c404a4b  lea ebp, [ebp + eax*4]
1c404a4f  lea eax, [ebp*2 + 0x1c40d318]
1c404a56  je 0x1c404a68
1c404a58  mov bp, word ptr [eax + 0x12]
1c404a5c  mov word ptr [esi + 0x4c], bp
1c404a60  mov bp, word ptr [eax + 8]
1c404a64  mov word ptr [esi + 0x44], bp
1c404a68  mov bp, word ptr [eax + 0xa]
1c404a6c  mov word ptr [esi + 0x52], bp
1c404a70  mov bp, word ptr [eax + 0xe]
1c404a74  mov word ptr [esi + 0x2f2], bp
1c404a7b  mov bp, word ptr [eax + 4]
1c404a7f  mov word ptr [esi + 0x46], bp
1c404a83  mov bp, word ptr [eax + 6]
1c404a87  mov word ptr [esi + 0xac], bp
1c404a8e  mov bp, word ptr [eax + 0x14]
1c404a92  mov word ptr [esi + 0x60], bp
1c404a96  mov bp, word ptr [eax + 0x16]
1c404a9a  mov word ptr [esi + 0x62], bp
1c404a9e  mov bp, word ptr [eax + 0x1a]
1c404aa2  mov word ptr [esi + 0x64], bp
1c404aa6  mov bp, word ptr [eax + 0x1c]
1c404aaa  mov word ptr [esi + 0x66], bp
1c404aae  mov bp, word ptr [eax + 0x10]
1c404ab2  mov word ptr [esi + 0x8a], bp
1c404ab9  mov bp, word ptr [eax + 0x42]
1c404abd  mov word ptr [esi + 0x98], bp
1c404ac4  mov bp, word ptr [eax + 0x44]
1c404ac8  mov word ptr [esi + 0x9a], bp
1c404acf  mov bp, word ptr [eax + 0x46]
1c404ad3  mov word ptr [esi + 0x9c], bp
1c404ada  mov bp, word ptr [eax + 0x48]
1c404ade  mov word ptr [esi + 0x9e], bp
1c404ae5  mov bp, word ptr [eax + 0x36]
1c404ae9  mov word ptr [esi + 0x92], bp
1c404af0  mov bp, word ptr [eax + 0x38]
1c404af4  mov word ptr [esi + 0x94], bp
1c404afb  mov bp, word ptr [eax + 0x3a]
1c404aff  mov word ptr [esi + 0x96], bp
1c404b06  mov bp, word ptr [eax + 0x3c]
1c404b0a  mov word ptr [esi + 0x8c], bp
1c404b11  mov bp, word ptr [eax + 0x3e]
1c404b15  mov word ptr [esi + 0x8e], bp
1c404b1c  mov bp, word ptr [eax + 0x40]
1c404b20  mov word ptr [esi + 0x90], bp
1c404b27  mov bp, word ptr [eax + 0x30]
1c404b2b  mov word ptr [esi + 0x84], bp
1c404b32  mov bp, word ptr [eax + 0x32]
1c404b36  mov word ptr [esi + 0x86], bp
1c404b3d  mov bp, word ptr [eax + 0x34]
1c404b41  mov word ptr [esi + 0x88], bp
1c404b48  mov bp, word ptr [eax + 0x2a]
1c404b4c  mov word ptr [esi + 0x7e], bp
1c404b50  mov bp, word ptr [eax + 0x2c]
1c404b54  mov word ptr [esi + 0x80], bp
1c404b5b  mov bp, word ptr [eax + 0x2e]
1c404b5f  mov word ptr [esi + 0x82], bp
1c404b66  mov bp, word ptr [eax + 0x26]
1c404b6a  mov word ptr [esi + 0x5c], bp
1c404b6e  mov ax, word ptr [eax + 0x28]
1c404b72  mov word ptr [esi + 0x5e], ax
1c404b76  jmp 0x1c404c9d
1c404b7b  mov ax, word ptr [edx + 2]
1c404b7f  mov word ptr [esi + 0x44], ax
1c404b83  jmp 0x1c404c9d
1c404b88  mov ax, word ptr [edx + 2]
1c404b8c  mov word ptr [esi + 0x52], ax
1c404b90  jmp 0x1c404c9d
1c404b95  mov ax, word ptr [edx + 2]
1c404b99  mov word ptr [esi + 0x2f2], ax
1c404ba0  jmp 0x1c404c9d
1c404ba5  mov ax, word ptr [edx + 2]
1c404ba9  mov word ptr [esi + 0x8a], ax
1c404bb0  jmp 0x1c404c9d
1c404bb5  mov ax, word ptr [edx + 2]
1c404bb9  mov word ptr [esi + 0x4c], ax
1c404bbd  jmp 0x1c404c9d
1c404bc2  mov ax, word ptr [edx + 2]
1c404bc6  mov word ptr [esi + 0x5c], ax
1c404bca  jmp 0x1c404c9d
1c404bcf  mov ax, word ptr [edx + 2]
1c404bd3  mov word ptr [esi + 0x5e], ax
1c404bd7  jmp 0x1c404c9d
1c404bdc  mov ax, word ptr [edx + 2]
1c404be0  mov word ptr [esi + 0x7e], ax
1c404be4  jmp 0x1c404c9d
1c404be9  mov ax, word ptr [edx + 2]
1c404bed  mov word ptr [esi + 0x80], ax
1c404bf4  jmp 0x1c404c9d
1c404bf9  mov ax, word ptr [edx + 2]
1c404bfd  mov word ptr [esi + 0x82], ax
1c404c04  jmp 0x1c404c9d
1c404c09  mov ax, word ptr [edx + 2]
1c404c0d  mov word ptr [esi + 0x84], ax
1c404c14  jmp 0x1c404c9d
1c404c19  mov ax, word ptr [edx + 2]
1c404c1d  mov word ptr [esi + 0x86], ax
1c404c24  jmp 0x1c404c9d
1c404c26  mov ax, word ptr [edx + 2]
1c404c2a  mov word ptr [esi + 0x88], ax
1c404c31  jmp 0x1c404c9d
1c404c33  mov ax, word ptr [edx + 2]
1c404c37  mov word ptr [esi + 0x92], ax
1c404c3e  jmp 0x1c404c9d
1c404c40  mov ax, word ptr [edx + 2]
1c404c44  mov word ptr [esi + 0x94], ax
1c404c4b  jmp 0x1c404c9d
1c404c4d  mov ax, word ptr [edx + 2]
1c404c51  mov word ptr [esi + 0x96], ax
1c404c58  jmp 0x1c404c9d
1c404c5a  mov ax, word ptr [edx + 2]
1c404c5e  mov word ptr [esi + 0x8c], ax
1c404c65  jmp 0x1c404c9d
1c404c67  mov ax, word ptr [edx + 2]
1c404c6b  mov word ptr [esi + 0x8e], ax
1c404c72  jmp 0x1c404c9d
1c404c74  mov ax, word ptr [edx + 2]
1c404c78  mov word ptr [esi + 0x90], ax
1c404c7f  jmp 0x1c404c9d
1c404c81  mov bp, word ptr [edx + 2]
1c404c85  or dword ptr [esp + 0x34], 0x20
1c404c8a  mov word ptr [esp + 0x12], bp
1c404c8f  jmp 0x1c404c9d
1c404c91  or dword ptr [esp + 0x34], 8
1c404c96  mov al, byte ptr [edx + 2]
1c404c99  mov byte ptr [esp + 0x11], al
1c404c9d  add edx, 6
1c404ca0  cmp word ptr [edx], 0x1e
1c404ca4  jne 0x1c4048f3
1c404caa  mov eax, dword ptr [0x1c4124b4]
1c404caf  mov ax, word ptr [eax]
1c404cb2  sar ax, 8
1c404cb6  cmp dword ptr [esp + 0x48], 0
1c404cbb  mov word ptr [esp + 0x14], ax
1c404cc0  je 0x1c404d57
1c404cc6  xor eax, eax
1c404cc8  mov al, byte ptr [0x1c412ace]
1c404ccd  sub eax, 0x3c
1c404cd0  cmp eax, 0x1c
1c404cd3  ja 0x1c404d9a
1c404cd9  xor ecx, ecx
1c404cdb  mov cl, byte ptr [eax + 0x1c405a64]
1c404ce1  jmp dword ptr [ecx*4 + 0x1c405a4c]
1c404ce8  mov ebx, 0x14a
1c404ced  mov edi, 0x4a1
1c404cf2  mov dword ptr [esp + 0x18], 0x898
1c404cfa  mov dword ptr [esp + 0x20], 0x1f4
1c404d02  mov dword ptr [esp + 0x2c], 0x3c
1c404d0a  jmp 0x1c404d9a
1c404d0f  mov ebx, 0x109
1c404d14  mov edi, 0x640
1c404d19  mov dword ptr [esp + 0x18], 0x8fc
1c404d21  mov dword ptr [esp + 0x20], 0x1f4
1c404d29  mov dword ptr [esp + 0x2c], 0x3c
1c404d31  jmp 0x1c404d9a
1c404d33  mov ebx, 0xfa
1c404d38  mov edi, 0x6d6
1c404d3d  mov dword ptr [esp + 0x18], 0x8ca
1c404d45  mov dword ptr [esp + 0x20], 0x1f4
1c404d4d  mov dword ptr [esp + 0x2c], 0x3c
1c404d55  jmp 0x1c404d9a
1c404d57  mov eax, dword ptr [0x1c4121cc]
1c404d5c  mov ecx, dword ptr [0x1c4121d0]
1c404d62  movsx ebx, word ptr [eax]
1c404d65  mov eax, dword ptr [0x1c4121d8]
1c404d6a  mov edx, dword ptr [0x1c4121b8]
1c404d70  movsx edi, word ptr [ecx]
1c404d73  movsx ecx, word ptr [eax]
1c404d76  movsx eax, word ptr [edx]
1c404d79  mov dword ptr [esp + 0x18], ecx
1c404d7d  mov dword ptr [esp + 0x20], eax
1c404d81  mov ecx, dword ptr [0x1c4121bc]
1c404d87  mov eax, dword ptr [0x1c4121c0]
1c404d8c  movsx edx, word ptr [ecx]
1c404d8f  movsx ecx, word ptr [eax]
1c404d92  mov dword ptr [esp + 0x24], edx
1c404d96  mov dword ptr [esp + 0x2c], ecx
1c404d9a  mov ax, word ptr [esi + 0x2f2]
1c404da1  cmp ax, 1
1c404da5  jne 0x1c404df2
1c404da7  cmp word ptr [esi + 0x52], 0
1c404dac  jne 0x1c404db3
1c404dae  add dword ptr [esp + 0x20], 0x3c
1c404db3  mov eax, dword ptr [0x1c4121e8]
1c404db8  movsx ecx, word ptr [eax]
1c404dbb  sub ecx, 7
1c404dbe  mov eax, dword ptr [0x1c4121d4]
1c404dc3  movsx eax, word ptr [eax]
1c404dc6  cmp ecx, eax
1c404dc8  jg 0x1c404dcc
1c404dca  mov ecx, eax
1c404dcc  mov eax, dword ptr [0x1c4121d4]
1c404dd1  mov word ptr [eax], cx
1c404dd4  mov ecx, dword ptr [0x1c4121e8]
1c404dda  mov ax, word ptr [ecx]
1c404ddd  cmp ax, 0x14
1c404de1  jle 0x1c404dea
1c404de3  add ax, 4
1c404de7  mov word ptr [ecx], ax
1c404dea  sub word ptr [esp + 0x14], 4
1c404df0  jmp 0x1c404e62
1c404df2  cmp ax, 2
1c404df6  jne 0x1c404e2e
1c404df8  mov eax, dword ptr [0x1c4121e8]
1c404dfd  movsx ecx, word ptr [eax]
1c404e00  sub ecx, 3
1c404e03  mov eax, dword ptr [0x1c4121d4]
1c404e08  movsx eax, word ptr [eax]
1c404e0b  cmp ecx, eax
1c404e0d  jg 0x1c404e11
1c404e0f  mov ecx, eax
1c404e11  mov dword ptr [esp + 0x20], 0xc8
1c404e19  mov eax, dword ptr [0x1c4121d4]
1c404e1e  mov word ptr [eax], cx
1c404e21  mov ecx, dword ptr [0x1c4121e8]
1c404e27  mov word ptr [ecx], 0
1c404e2c  jmp 0x1c404e62
1c404e2e  cmp dword ptr [esp + 0x48], 0
1c404e33  je 0x1c404e41
1c404e35  mov eax, dword ptr [0x1c4121d4]
1c404e3a  mov word ptr [eax], 0
1c404e3f  jmp 0x1c404e62
1c404e41  mov eax, dword ptr [0x1c4121e8]
1c404e46  movsx ecx, word ptr [eax]
1c404e49  sub ecx, 0x14
1c404e4c  mov eax, dword ptr [0x1c4121d4]
1c404e51  movsx eax, word ptr [eax]
1c404e54  cmp ecx, eax
1c404e56  jg 0x1c404e5a
1c404e58  mov ecx, eax
1c404e5a  mov eax, dword ptr [0x1c4121d4]
1c404e5f  mov word ptr [eax], cx
1c404e62  test byte ptr [0x1c412ac1], 0x80
1c404e69  je 0x1c404e74
1c404e6b  mov eax, dword ptr [0x1c4121d4]
1c404e70  sub word ptr [eax], 7
1c404e74  cmp dword ptr [0x1c412b28], 0
1c404e7b  je 0x1c404efb
1c404e7d  xor eax, eax
1c404e7f  mov ax, word ptr [esp + 0x16]
1c404e84  and eax, 3
1c404e87  je 0x1c404e93
1c404e89  cmp eax, 1
1c404e8c  je 0x1c404ed1
1c404e8e  cmp eax, 2
1c404e91  jne 0x1c404efb
1c404e93  sub ebx, 0x32
1c404e96  lea edi, [edi + edi*2 + 0x4b0]
1c404e9d  sar edi, 2
1c404ea0  mov eax, dword ptr [esp + 0x24]
1c404ea4  add eax, 0xc8
1c404ea9  mov ecx, dword ptr [0x1c4121e8]
1c404eaf  sar eax, 1
1c404eb2  add dword ptr [esp + 0x20], 0x28
1c404eb7  sub word ptr [ecx], 3
1c404ebb  mov dword ptr [esp + 0x24], eax
1c404ebf  mov eax, dword ptr [esp + 0x18]
1c404ec3  add eax, 0x7d0
1c404ec8  sar eax, 1
1c404ecb  mov dword ptr [esp + 0x18], eax
1c404ecf  jmp 0x1c404efb
1c404ed1  sub ebx, 0x64
1c404ed4  add edi, 0x4b0
1c404eda  sar edi, 1
1c404edd  mov eax, dword ptr [0x1c4121e8]
1c404ee2  add dword ptr [esp + 0x20], 0x50
1c404ee7  sub word ptr [eax], 6
1c404eeb  mov dword ptr [esp + 0x24], 0xc8
1c404ef3  mov dword ptr [esp + 0x18], 0x7d0
1c404efb  movsx ecx, word ptr [esi + 0x5c]
1c404eff  mov dx, word ptr [esi + 0x52]
1c404f03  add ecx, 0xa
1c404f06  cmp dx, 1
1c404f0a  jne 0x1c404fd8
1c404f10  mov eax, dword ptr [0x1c4121e8]
1c404f15  add dword ptr [esp + 0x18], 0x1d1
1c404f1d  sub word ptr [eax], 0xa
1c404f21  mov edx, dword ptr [0x1c4121d4]
1c404f27  sub word ptr [esp + 0x14], 5
1c404f2d  sub word ptr [edx], 0x14
1c404f31  lea edx, [ebx - 0x1c2]
1c404f37  imul edx, ecx
1c404f3a  mov ebp, dword ptr [0x1c4121c8]
1c404f40  mov eax, edx
1c404f42  sub word ptr [ebp], 6
1c404f47  lea edx, [edx + edx*2]
1c404f4a  shl edx, 3
1c404f4d  mov ebp, 0x3e8
1c404f52  sub edx, eax
1c404f54  lea eax, [edx + edx*4]
1c404f57  cdq 
1c404f58  idiv ebp
1c404f5a  add eax, 0x24a
1c404f5f  mov dword ptr [esp + 0x1c], eax
1c404f63  lea eax, [edi - 0x5aa]
1c404f69  imul eax, ecx
1c404f6c  lea ecx, [eax + eax*8]
1c404f6f  lea edx, [ecx + ecx*2]
1c404f72  lea eax, [edx + edx*4]
1c404f75  cdq 
1c404f76  idiv ebp
1c404f78  lea ebp, [eax + 0x6de]
1c404f7e  mov eax, dword ptr [esp + 0x18]
1c404f82  sub eax, ebp
1c404f84  cmp eax, 0x12c
1c404f89  jge 0x1c404f95
1c404f8b  lea eax, [ebp + 0x12c]
1c404f91  mov dword ptr [esp + 0x18], eax
1c404f95  mov eax, dword ptr [esp + 0x1c]
1c404f99  imul eax, dword ptr [esp + 0x20]
1c404f9e  cdq 
1c404f9f  idiv ebx
1c404fa1  lea ecx, [eax + 0x32]
1c404fa4  mov eax, ebp
1c404fa6  imul eax, dword ptr [esp + 0x24]
1c404fab  cdq 
1c404fac  idiv edi
1c404fae  mov dword ptr [esp + 0x24], eax
1c404fb2  cmp ecx, 0x15e
1c404fb8  jl 0x1c404fbf
1c404fba  mov ecx, 0x15e
1c404fbf  cmp ecx, 0x46
1c404fc2  jg 0x1c404fc9
1c404fc4  mov ecx, 0x46
1c404fc9  mov eax, dword ptr [0x1c4121ec]
1c404fce  add word ptr [eax], 0x96
1c404fd3  jmp 0x1c405244
1c404fd8  cmp dx, 2
1c404fdc  jne 0x1c4050ad
1c404fe2  dec word ptr [esp + 0x14]
1c404fe7  mov eax, dword ptr [0x1c4121e8]
1c404fec  sub word ptr [eax], 0xd
1c404ff0  lea eax, [ebx - 0x1c2]
1c404ff6  mov edx, dword ptr [0x1c4121d4]
1c404ffc  imul eax, ecx
1c404fff  sub word ptr [edx], 0x16
1c405003  mov edx, eax
1c405005  mov ebp, dword ptr [0x1c4121c8]
1c40500b  add eax, eax
1c40500d  add dword ptr [esp + 0x18], 0x429
1c405015  sub word ptr [ebp], 7
1c40501a  lea ebp, [eax + eax*8]
1c40501d  lea eax, [edx + ebp*8]
1c405020  mov ebp, 0x3e8
1c405025  cdq 
1c405026  idiv ebp
1c405028  add eax, 0x2e4
1c40502d  lea edx, [edi - 0x5aa]
1c405033  imul edx, ecx
1c405036  mov dword ptr [esp + 0x1c], eax
1c40503a  mov eax, edx
1c40503c  add edx, edx
1c40503e  lea ecx, [edx + edx*8]
1c405041  lea eax, [eax + ecx*8]
1c405044  cdq 
1c405045  idiv ebp
1c405047  lea ebp, [eax + 0x834]
1c40504d  mov eax, dword ptr [esp + 0x18]
1c405051  sub eax, ebp
1c405053  cmp eax, 0x15e
1c405058  jge 0x1c405064
1c40505a  lea eax, [ebp + 0x15e]
1c405060  mov dword ptr [esp + 0x18], eax
1c405064  mov eax, dword ptr [esp + 0x1c]
1c405068  imul eax, dword ptr [esp + 0x20]
1c40506d  cdq 
1c40506e  idiv ebx
1c405070  lea ecx, [eax + 0x96]
1c405076  mov eax, ebp
1c405078  imul eax, dword ptr [esp + 0x24]
1c40507d  cdq 
1c40507e  idiv edi
1c405080  add eax, 0x32
1c405083  cmp ecx, 0x12c
1c405089  mov dword ptr [esp + 0x24], eax
1c40508d  jl 0x1c405094
1c40508f  mov ecx, 0x12c
1c405094  cmp ecx, 0x64
1c405097  jg 0x1c40509e
1c405099  mov ecx, 0x64
1c40509e  mov eax, dword ptr [0x1c4121ec]
1c4050a3  add word ptr [eax], 0xfa
1c4050a8  jmp 0x1c405244
1c4050ad  mov eax, dword ptr [esp + 0x18]
1c4050b1  mov dword ptr [esp + 0x1c], ebx
1c4050b5  sub ebx, 0x1c2
1c4050bb  mov dword ptr [esp + 0x50], edi
1c4050bf  sub edi, 0x5aa
1c4050c5  mov dword ptr [esp + 0x54], eax
1c4050c9  sub dword ptr [esp + 0x18], 0x9a1
1c4050d1  cmp dx, 3
1c4050d5  jne 0x1c40515f
1c4050db  imul ebx, ecx
1c4050de  mov eax, ebx
1c4050e0  mov ebp, 0x3e8
1c4050e5  lea ebx, [ebx + ebx*2]
1c4050e8  shl ebx, 3
1c4050eb  sub ebx, eax
1c4050ed  imul edi, ecx
1c4050f0  lea eax, [ebx*4]
1c4050f7  cdq 
1c4050f8  idiv ebp
1c4050fa  lea ebx, [eax + 0x190]
1c405100  mov eax, edi
1c405102  lea edi, [edi + edi*2]
1c405105  shl edi, 3
1c405108  sub edi, eax
1c40510a  imul ecx, dword ptr [esp + 0x18]
1c40510f  lea eax, [edi*4]
1c405116  cdq 
1c405117  idiv ebp
1c405119  mov edi, 0x3e8
1c40511e  lea ebp, [eax + 0x564]
1c405124  mov eax, ecx
1c405126  lea ecx, [ecx + ecx*2]
1c405129  shl ecx, 3
1c40512c  sub ecx, eax
1c40512e  lea eax, [ecx*4]
1c405135  cdq 
1c405136  idiv edi
1c405138  add eax, 0x92e
1c40513d  mov dword ptr [esp + 0x18], eax
1c405141  sub eax, ebp
1c405143  cmp eax, 0xfa
1c405148  jge 0x1c405154
1c40514a  lea eax, [ebp + 0xfa]
1c405150  mov dword ptr [esp + 0x18], eax
1c405154  mov eax, dword ptr [0x1c4121ec]
1c405159  sub word ptr [eax], 0x64
1c40515d  jmp 0x1c4051ad
1c40515f  imul ebx, ecx
1c405162  shl ebx, 2
1c405165  mov ebp, 0x3e8
1c40516a  imul edi, ecx
1c40516d  shl edi, 2
1c405170  lea edx, [ebx + ebx*4]
1c405173  lea eax, [edx + edx*4]
1c405176  cdq 
1c405177  idiv ebp
1c405179  imul ecx, dword ptr [esp + 0x18]
1c40517e  lea edx, [edi + edi*4]
1c405181  mov edi, 0x3e8
1c405186  shl ecx, 2
1c405189  lea ebx, [eax + 0x1c2]
1c40518f  lea eax, [edx + edx*4]
1c405192  cdq 
1c405193  idiv ebp
1c405195  lea edx, [ecx + ecx*4]
1c405198  lea ebp, [eax + 0x5aa]
1c40519e  lea eax, [edx + edx*4]
1c4051a1  cdq 
1c4051a2  idiv edi
1c4051a4  add eax, 0x9a1
1c4051a9  mov dword ptr [esp + 0x18], eax
1c4051ad  mov eax, ebx
1c4051af  imul eax, dword ptr [esp + 0x20]
1c4051b4  cdq 
1c4051b5  idiv dword ptr [esp + 0x1c]
1c4051b9  mov ecx, eax
1c4051bb  mov eax, ebp
1c4051bd  imul eax, dword ptr [esp + 0x24]
1c4051c2  cdq 
1c4051c3  idiv dword ptr [esp + 0x50]
1c4051c7  mov dword ptr [esp + 0x24], eax
1c4051cb  mov eax, dword ptr [esp + 0x2c]
1c4051cf  imul eax, dword ptr [esp + 0x18]
1c4051d4  cdq 
1c4051d5  idiv dword ptr [esp + 0x54]
1c4051d9  mov dword ptr [esp + 0x2c], eax
1c4051dd  cmp ecx, 0x12c
1c4051e3  jl 0x1c4051ea
1c4051e5  mov ecx, 0x12c
1c4051ea  cmp ecx, 0x28
1c4051ed  jg 0x1c4051f4
1c4051ef  mov ecx, 0x28
1c4051f4  movsx eax, word ptr [esi + 0x46]
1c4051f8  sub eax, 0x6e
1c4051fb  test eax, eax
1c4051fd  jg 0x1c405201
1c4051ff  xor eax, eax
1c405201  cdq 
1c405202  mov edi, 0xe
1c405207  idiv edi
1c405209  cmp eax, 0x14
1c40520c  jl 0x1c405213
1c40520e  mov eax, 0x14
1c405213  mov edx, dword ptr [0x1c4121e8]
1c405219  sub word ptr [edx], ax
1c40521c  mov eax, dword ptr [0x1c4121d4]
1c405221  sub word ptr [eax], 0xd
1c405225  mov eax, ebx
1c405227  shl eax, 5
1c40522a  mov edi, dword ptr [0x1c4121c8]
1c405230  sub word ptr [edi], 2
1c405234  add eax, ebx
1c405236  mov edi, 0x21
1c40523b  add eax, ebx
1c40523d  cdq 
1c40523e  idiv edi
1c405240  mov dword ptr [esp + 0x1c], eax
1c405244  mov ax, word ptr [esi + 0x84]
1c40524b  mov edx, dword ptr [0x1c4121e8]
1c405251  add word ptr [edx], ax
1c405254  mov eax, dword ptr [0x1c4121d4]
1c405259  mov bx, word ptr [esi + 0x86]
1c405260  add word ptr [eax], bx
1c405263  mov di, word ptr [esi + 0x88]
1c40526a  mov edx, dword ptr [0x1c4121c8]
1c405270  add word ptr [edx], di
1c405273  mov edi, 0x64
1c405278  movsx eax, word ptr [esi + 0x92]
1c40527f  imul eax, dword ptr [esp + 0x1c]
1c405284  cdq 
1c405285  idiv edi
1c405287  mov ebx, eax
1c405289  movsx eax, word ptr [esi + 0x94]
1c405290  imul eax, ebp
1c405293  cdq 
1c405294  idiv edi
1c405296  mov edi, eax
1c405298  mov ebp, 0x64
1c40529d  movsx eax, word ptr [esi + 0x96]
1c4052a4  imul eax, dword ptr [esp + 0x18]
1c4052a9  cdq 
1c4052aa  idiv ebp
1c4052ac  cmp ebx, 0xff0
1c4052b2  jl 0x1c4052b9
1c4052b4  mov ebx, 0xff0
1c4052b9  cmp ebx, 0x64
1c4052bc  jg 0x1c4052c3
1c4052be  mov ebx, 0x64
1c4052c3  cmp edi, 0xff0
1c4052c9  jl 0x1c4052d0
1c4052cb  mov edi, 0xff0
1c4052d0  cmp edi, 0x64
1c4052d3  jg 0x1c4052da
1c4052d5  mov edi, 0x64
1c4052da  cmp eax, 0xff0
1c4052df  jl 0x1c4052e6
1c4052e1  mov eax, 0xff0
1c4052e6  cmp eax, 0x64
1c4052e9  jg 0x1c4052f0
1c4052eb  mov eax, 0x64
1c4052f0  mov dword ptr [esp + 0x18], eax
1c4052f4  movsx eax, word ptr [esi + 0x8c]
1c4052fb  imul eax, ecx
1c4052fe  mov ecx, 0x64
1c405303  mov ebp, 0x64
1c405308  cdq 
1c405309  idiv ecx
1c40530b  mov ecx, eax
1c40530d  movsx eax, word ptr [esi + 0x8e]
1c405314  imul eax, dword ptr [esp + 0x24]
1c405319  cdq 
1c40531a  idiv ebp
1c40531c  mov dword ptr [esp + 0x1c], 0x64
1c405324  mov ebp, eax
1c405326  movsx eax, word ptr [esi + 0x90]
1c40532d  imul eax, dword ptr [esp + 0x2c]
1c405332  cdq 
1c405333  idiv dword ptr [esp + 0x1c]
1c405337  cmp ecx, 0x1f4
1c40533d  jl 0x1c405344
1c40533f  mov ecx, 0x1f4
1c405344  cmp ecx, 0x28
1c405347  jg 0x1c40534e
1c405349  mov ecx, 0x28
1c40534e  mov dword ptr [esp + 0x20], ecx
1c405352  cmp ebp, 0x1f4
1c405358  jl 0x1c40535f
1c40535a  mov ebp, 0x1f4
1c40535f  cmp ebp, 0x28
1c405362  jg 0x1c405369
1c405364  mov ebp, 0x28
1c405369  mov dword ptr [esp + 0x24], ebp
1c40536d  cmp eax, 0x1f4
1c405372  jl 0x1c405379
1c405374  mov eax, 0x1f4
1c405379  cmp eax, 0x28
1c40537c  jg 0x1c405383
1c40537e  mov eax, 0x28
1c405383  mov dword ptr [esp + 0x2c], eax
1c405387  movsx eax, word ptr [esi + 0x98]
1c40538e  sub eax, dword ptr [esp + 0x38]
1c405392  lea ecx, [eax + eax*4]
1c405395  lea edx, [ecx + ecx*4]
1c405398  lea eax, [edx + edx*4]
1c40539b  lea ecx, [eax + eax*4]
1c40539e  lea eax, [ecx*8]
1c4053a5  sar eax, 0x10
1c4053a8  add dword ptr [esp + 0x38], eax
1c4053ac  movsx eax, word ptr [esi + 0x9c]
1c4053b3  sub eax, dword ptr [esp + 0x3c]
1c4053b7  lea ecx, [eax + eax*4]
1c4053ba  lea edx, [ecx + ecx*4]
1c4053bd  lea eax, [edx + edx*4]
1c4053c0  lea ecx, [eax + eax*4]
1c4053c3  lea eax, [ecx*8]
1c4053ca  sar eax, 0x10
1c4053cd  add dword ptr [esp + 0x3c], eax
1c4053d1  movsx eax, word ptr [esi + 0x9a]
1c4053d8  sub eax, dword ptr [esp + 0x40]
1c4053dc  lea ecx, [eax + eax*4]
1c4053df  lea edx, [ecx + ecx*4]
1c4053e2  lea eax, [edx + edx*4]
1c4053e5  lea ecx, [eax + eax*4]
1c4053e8  lea eax, [ecx*8]
1c4053ef  sar eax, 0x10
1c4053f2  add dword ptr [esp + 0x40], eax
1c4053f6  movsx eax, word ptr [esi + 0x9e]
1c4053fd  sub eax, dword ptr [esp + 0x44]
1c405401  lea ecx, [eax + eax*4]
1c405404  lea edx, [ecx + ecx*4]
1c405407  lea eax, [edx + edx*4]
1c40540a  lea ecx, [eax + eax*4]
1c40540d  lea eax, [ecx*8]
1c405414  sar eax, 0x10
1c405417  mov cx, word ptr [esi + 0x8a]
1c40541e  add dword ptr [esp + 0x44], eax
1c405422  add word ptr [esp + 0x14], cx
1c405427  mov ax, word ptr [esp + 0x14]
1c40542c  cmp ax, 0xf
1c405430  jl 0x1c405436
1c405432  mov ax, 0xf
1c405436  test ax, ax
1c405439  jg 0x1c40543e
1c40543b  xor ax, ax
1c40543e  mov word ptr [esp + 0x14], ax
1c405443  mov ecx, dword ptr [0x1c4121f0]
1c405449  mov eax, dword ptr [0x1c4121ec]
1c40544e  cmp word ptr [esi + 0x48], 0x1f40
1c405454  movsx ebp, word ptr [eax]
1c405457  movsx eax, word ptr [ecx]
1c40545a  mov dword ptr [esp + 0x1c], eax
1c40545e  jne 0x1c405520
1c405464  lea eax, [ebx + ebx*4]
1c405467  mov edx, dword ptr [esp + 0x20]
1c40546b  lea eax, [ebx + eax*2]
1c40546e  lea ecx, [edx + edx*4]
1c405471  sar eax, 3
1c405474  lea ecx, [edx + ecx*2]
1c405477  sar ecx, 3
1c40547a  mov ebx, eax
1c40547c  lea eax, [edi + edi*4]
1c40547f  mov edx, dword ptr [esp + 0x24]
1c405483  mov dword ptr [esp + 0x20], ecx
1c405487  lea eax, [edi + eax*2]
1c40548a  sar eax, 3
1c40548d  lea ecx, [edx + edx*4]
1c405490  mov edi, eax
1c405492  lea ecx, [edx + ecx*2]
1c405495  sar ecx, 3
1c405498  mov eax, dword ptr [esp + 0x18]
1c40549c  mov dword ptr [esp + 0x24], ecx
1c4054a0  lea edx, [eax + eax*4]
1c4054a3  lea ecx, [eax + edx*2]
1c4054a6  mov eax, dword ptr [esp + 0x2c]
1c4054aa  sar ecx, 3
1c4054ad  lea edx, [eax + eax*4]
1c4054b0  mov dword ptr [esp + 0x18], ecx
1c4054b4  lea ecx, [eax + edx*2]
1c4054b7  sar ecx, 3
1c4054ba  mov edx, dword ptr [esp + 0x38]
1c4054be  mov dword ptr [esp + 0x2c], ecx
1c4054c2  lea eax, [edx + edx*4]
1c4054c5  lea eax, [edx + eax*2]
1c4054c8  mov edx, dword ptr [esp + 0x40]
1c4054cc  sar eax, 3
1c4054cf  lea ecx, [edx + edx*4]
1c4054d2  mov dword ptr [esp + 0x38], eax
1c4054d6  lea eax, [edx + ecx*2]
1c4054d9  sar eax, 3
1c4054dc  mov edx, dword ptr [esp + 0x3c]
1c4054e0  mov dword ptr [esp + 0x40], eax
1c4054e4  lea ecx, [edx + edx*4]
1c4054e7  lea eax, [edx + ecx*2]
1c4054ea  mov edx, dword ptr [esp + 0x44]
1c4054ee  sar eax, 3
1c4054f1  lea ecx, [edx + edx*4]
1c4054f4  mov dword ptr [esp + 0x3c], eax
1c4054f8  lea eax, [edx + ecx*2]
1c4054fb  sar eax, 3
1c4054fe  lea ecx, [ebp + ebp*4]
1c405502  mov edx, dword ptr [esp + 0x1c]
1c405506  mov dword ptr [esp + 0x44], eax
1c40550a  lea eax, [ebp + ecx*2]
1c40550e  lea ecx, [edx + edx*4]
1c405511  sar eax, 3
1c405514  lea ecx, [edx + ecx*2]
1c405517  sar ecx, 3
1c40551a  mov ebp, eax
1c40551c  mov dword ptr [esp + 0x1c], ecx
1c405520  test dword ptr [0x1c412ac0], 0xc0100000
1c40552a  je 0x1c40555b
1c40552c  mov ax, word ptr [0x1c4121b6]
1c405532  shr ax, 1
1c405536  cmp ax, word ptr [esp + 0x16]
1c40553b  jae 0x1c40555b
1c40553d  xor eax, eax
1c40553f  mov al, byte ptr [0x1c412ace]
1c405544  mov ecx, eax
1c405546  lea edx, [eax + eax*4]
1c405549  lea eax, [edx + edx*4]
1c40554c  add eax, ecx
1c40554e  mov ecx, dword ptr [esp + 0x30]
1c405552  mov edx, dword ptr [ecx + 4]
1c405555  mov al, byte ptr [eax + edx + 0x31]
1c405559  jmp 0x1c405577
1c40555b  xor eax, eax
1c40555d  mov al, byte ptr [0x1c412ace]
1c405562  mov ecx, eax
1c405564  lea edx, [eax + eax*4]
1c405567  lea eax, [edx + edx*4]
1c40556a  add eax, ecx
1c40556c  mov ecx, dword ptr [esp + 0x30]
1c405570  mov edx, dword ptr [ecx + 4]
1c405573  mov al, byte ptr [eax + edx + 0x17]
1c405577  mov byte ptr [0x1c412ab9], al
1c40557c  cmp byte ptr [0x1c412ab9], 0
1c405583  jne 0x1c40558f
1c405585  mov al, byte ptr [0x1c412ab3]
1c40558a  mov byte ptr [0x1c412ab9], al
1c40558f  mov al, byte ptr [0x1c412ab9]
1c405594  mov ecx, dword ptr [0x1c412aa8]
1c40559a  mov byte ptr [ecx + 0x1a], al
1c40559d  lea eax, [ebx + 8]
1c4055a0  cdq 
1c4055a1  and edx, 0xf
1c4055a4  xor ecx, ecx
1c4055a6  add eax, edx
1c4055a8  sar eax, 4
1c4055ab  mov cl, al
1c4055ad  mov al, byte ptr [ecx + 0x1c405a84]
1c4055b3  mov ecx, dword ptr [0x1c412aa8]
1c4055b9  mov byte ptr [ecx], al
1c4055bb  lea eax, [edi + 8]
1c4055be  cdq 
1c4055bf  and edx, 0xf
1c4055c2  xor ecx, ecx
1c4055c4  add eax, edx
1c4055c6  sar eax, 4
1c4055c9  mov cl, al
1c4055cb  mov al, byte ptr [ecx + 0x1c405a84]
1c4055d1  mov ecx, dword ptr [0x1c412aa8]
1c4055d7  mov byte ptr [ecx + 1], al
1c4055da  mov eax, dword ptr [esp + 0x18]
1c4055de  add eax, 8
1c4055e1  xor ecx, ecx
1c4055e3  cdq 
1c4055e4  and edx, 0xf
1c4055e7  add eax, edx
1c4055e9  sar eax, 4
1c4055ec  mov cl, al
1c4055ee  mov al, byte ptr [ecx + 0x1c405a84]
1c4055f4  mov ecx, dword ptr [0x1c412aa8]
1c4055fa  mov byte ptr [ecx + 2], al
1c4055fd  mov eax, dword ptr [esp + 0x38]
1c405601  add eax, 0x10
1c405604  xor ecx, ecx
1c405606  cdq 
1c405607  and edx, 0x1f
1c40560a  add eax, edx
1c40560c  sar eax, 5
1c40560f  mov cl, al
1c405611  mov al, byte ptr [ecx + 0x1c405b84]
1c405617  mov ecx, dword ptr [0x1c412aa8]
1c40561d  mov byte ptr [ecx + 3], al
1c405620  mov eax, dword ptr [esp + 0x3c]
1c405624  add eax, 0x10
1c405627  xor ecx, ecx
1c405629  cdq 
1c40562a  and edx, 0x1f
1c40562d  add eax, edx
1c40562f  sar eax, 5
1c405632  mov cl, al
1c405634  mov al, byte ptr [ecx + 0x1c405b84]
1c40563a  mov ecx, dword ptr [0x1c412aa8]
1c405640  mov byte ptr [ecx + 4], al
1c405643  mov ecx, dword ptr [0x1c412aa8]
1c405649  mov eax, dword ptr [esp + 0x20]
1c40564d  mov byte ptr [ecx + 5], 0
1c405651  add eax, 4
1c405654  cdq 
1c405655  and edx, 7
1c405658  xor ecx, ecx
1c40565a  add eax, edx
1c40565c  sar eax, 3
1c40565f  mov cl, al
1c405661  mov eax, dword ptr [esp + 0x24]
1c405665  add eax, 4
1c405668  mov cl, byte ptr [ecx + 0x1c405c84]
1c40566e  cdq 
1c40566f  shl cl, 4
1c405672  and edx, 7
1c405675  add eax, edx
1c405677  xor edx, edx
1c405679  sar eax, 3
1c40567c  mov dl, al
1c40567e  mov eax, dword ptr [0x1c412aa8]
1c405683  add cl, byte ptr [edx + 0x1c405c84]
1c405689  mov byte ptr [eax + 6], cl
1c40568c  mov eax, dword ptr [esp + 0x2c]
1c405690  add eax, 4
1c405693  xor ecx, ecx
1c405695  cdq 
1c405696  and edx, 7
1c405699  add eax, edx
1c40569b  sar eax, 3
1c40569e  mov cl, al
1c4056a0  mov al, byte ptr [ecx + 0x1c405c84]
1c4056a6  mov ecx, dword ptr [0x1c412aa8]
1c4056ac  shl al, 4
1c4056af  add al, byte ptr [esp + 0x14]
1c4056b3  mov byte ptr [ecx + 7], al
1c4056b6  mov eax, dword ptr [esp + 0x40]
1c4056ba  add eax, 4
1c4056bd  xor ecx, ecx
1c4056bf  cdq 
1c4056c0  and edx, 7
1c4056c3  add eax, edx
1c4056c5  sar eax, 3
1c4056c8  mov cl, al
1c4056ca  mov eax, dword ptr [esp + 0x44]
1c4056ce  add eax, 4
1c4056d1  mov cl, byte ptr [ecx + 0x1c405d84]
1c4056d7  cdq 
1c4056d8  shl cl, 4
1c4056db  and edx, 7
1c4056de  add eax, edx
1c4056e0  xor edx, edx
1c4056e2  sar eax, 3
1c4056e5  mov dl, al
1c4056e7  mov eax, dword ptr [0x1c412aa8]
1c4056ec  add cl, byte ptr [edx + 0x1c405d84]
1c4056f2  mov byte ptr [eax + 8], cl
1c4056f5  lea eax, [ebp + 0x10]
1c4056f8  cdq 
1c4056f9  and edx, 0x1f
1c4056fc  xor ecx, ecx
1c4056fe  add eax, edx
1c405700  sar eax, 5
1c405703  mov cl, al
1c405705  mov al, byte ptr [ecx + 0x1c405b84]
1c40570b  mov edx, dword ptr [0x1c412aa8]
1c405711  mov byte ptr [edx + 9], al
1c405714  mov al, byte ptr [0x1c412ace]
1c405719  mov edx, dword ptr [0x1c412aa8]
1c40571f  mov byte ptr [edx + 0xb], al
1c405722  mov ax, word ptr [esi + 0x44]
1c405726  shr ax, 1
1c40572a  cmp ax, 1
1c40572e  ja 0x1c405734
1c405730  mov ax, 1
1c405734  mov edx, dword ptr [0x1c412aa8]
1c40573a  mov byte ptr [edx + 0xa], al
1c40573d  mov eax, dword ptr [0x1c4121e8]
1c405742  movsx eax, word ptr [eax]
1c405745  add eax, eax
1c405747  cmp eax, 0x80
1c40574c  jl 0x1c405753
1c40574e  mov eax, 0x80
1c405753  test eax, eax
1c405755  jg 0x1c405759
1c405757  xor eax, eax
1c405759  mov edx, dword ptr [0x1c412aa8]
1c40575f  mov byte ptr [edx + 0x10], al
1c405762  mov eax, dword ptr [0x1c4121d4]
1c405767  movsx eax, word ptr [eax]
1c40576a  add eax, eax
1c40576c  cmp eax, 0x80
1c405771  jl 0x1c405778
1c405773  mov eax, 0x80
1c405778  test eax, eax
1c40577a  jg 0x1c40577e
1c40577c  xor eax, eax
1c40577e  mov edx, dword ptr [0x1c412aa8]
1c405784  mov byte ptr [edx + 0x11], al
1c405787  mov eax, dword ptr [0x1c4121c8]
1c40578c  movsx eax, word ptr [eax]
1c40578f  add eax, eax
1c405791  cmp eax, 0x80
1c405796  jl 0x1c40579d
1c405798  mov eax, 0x80
1c40579d  test eax, eax
1c40579f  jg 0x1c4057a3
1c4057a1  xor eax, eax
1c4057a3  mov edx, dword ptr [0x1c412aa8]
1c4057a9  mov byte ptr [edx + 0x12], al
1c4057ac  mov eax, dword ptr [0x1c4121e0]
1c4057b1  movsx ecx, word ptr [eax]
1c4057b4  lea eax, [ecx*2 + 0x5c]
1c4057bb  test eax, eax
1c4057bd  jg 0x1c4057c1
1c4057bf  xor eax, eax
1c4057c1  mov edx, dword ptr [0x1c412aa8]
1c4057c7  mov byte ptr [edx + 0x13], al
1c4057ca  mov eax, dword ptr [esp + 0x1c]
1c4057ce  add eax, 4
1c4057d1  xor ecx, ecx
1c4057d3  cdq 
1c4057d4  and edx, 7
1c4057d7  add eax, edx
1c4057d9  mov edx, dword ptr [0x1c412aa8]
1c4057df  sar eax, 3
1c4057e2  mov cl, al
1c4057e4  mov al, byte ptr [ecx + 0x1c405d84]
1c4057ea  shl al, 4
1c4057ed  mov bp, word ptr [esp + 0x12]
1c4057f2  mov byte ptr [edx + 0x14], al
1c4057f5  mov edx, dword ptr [0x1c412aa8]
1c4057fb  mov al, byte ptr [esp + 0x11]
1c4057ff  mov byte ptr [edx + 0x1b], al
1c405802  mov edx, dword ptr [0x1c412aa8]
1c405808  mov word ptr [edx + 0x1c], bp
1c40580c  mov al, byte ptr [esp + 0x34]
1c405810  mov edx, dword ptr [0x1c412aa8]
1c405816  mov cl, byte ptr [esp + 0x4c]
1c40581a  inc dword ptr [esp + 0x4c]
1c40581e  mov byte ptr [edx + 0x17], al
1c405821  mov edx, dword ptr [0x1c412aa8]
1c405827  xor eax, eax
1c405829  mov byte ptr [edx + 0x1f], cl
1c40582c  mov ax, word ptr [esi + 0x4c]
1c405830  cmp eax, 2
1c405833  je 0x1c405847
1c405835  cmp eax, 4
1c405838  je 0x1c405855
1c40583a  mov eax, dword ptr [0x1c412aa8]
1c40583f  mov word ptr [eax + 0x18], 0
1c405845  jmp 0x1c405855
1c405847  mov ax, word ptr [esi + 0x46]
1c40584b  mov ecx, dword ptr [0x1c412aa8]
1c405851  mov word ptr [ecx + 0x18], ax
1c405855  add dword ptr [0x1c412aa8], 0x20
1c40585c  test byte ptr [esp + 0x34], 8
1c405861  je 0x1c405868
1c405863  xor dword ptr [esp + 0x34], 8
1c405868  test byte ptr [esp + 0x34], 0x20
1c40586d  je 0x1c405874
1c40586f  xor dword ptr [esp + 0x34], 0x20
1c405874  add dword ptr [0x1c4121cc], 2
1c40587b  add dword ptr [0x1c4121d0], 2
1c405882  add dword ptr [0x1c4121d8], 2
1c405889  add dword ptr [0x1c4121b8], 2
1c405890  add dword ptr [0x1c4121bc], 2
1c405897  add dword ptr [0x1c4121c0], 2
1c40589e  add dword ptr [0x1c4121ec], 2
1c4058a5  add dword ptr [0x1c4121f0], 2
1c4058ac  add dword ptr [0x1c4124b4], 2
1c4058b3  add dword ptr [0x1c4121e4], 2
1c4058ba  add dword ptr [0x1c4121e8], 2
1c4058c1  inc word ptr [esp + 0x16]
1c4058c6  mov ax, word ptr [esp + 0x16]
1c4058cb  add dword ptr [0x1c4121d4], 2
1c4058d2  add dword ptr [0x1c4121c8], 2
1c4058d9  add dword ptr [0x1c4121e0], 2
1c4058e0  add dword ptr [0x1c4121c4], 2
1c4058e7  cmp word ptr [0x1c4121b6], ax
1c4058ee  ja 0x1c4048d1
1c4058f4  mov ax, word ptr [esi + 0x46]
1c4058f8  mov ecx, dword ptr [esi + 0xf6]
1c4058fe  mov word ptr [ecx + 0x18], ax
1c405902  mov edx, dword ptr [esp + 0x28]
1c405906  push edx
1c405907  mov eax, dword ptr [0x1c412aa8]
1c40590c  xor ecx, ecx
1c40590e  mov cx, word ptr [0x1c4121b6]
1c405915  shl ecx, 5
1c405918  sub eax, ecx
1c40591a  push eax
1c40591b  push esi
1c40591c  call 0x1c403440
1c405921  add esp, 0xc
1c405924  xor eax, eax
1c405926  mov ax, word ptr [esi + 0x4c]
1c40592a  cmp eax, 3
1c40592d  je 0x1c405936
1c40592f  cmp eax, 4
1c405932  je 0x1c405957
1c405934  jmp 0x1c40596b
1c405936  mov edx, dword ptr [esp + 0x28]
1c40593a  mov eax, dword ptr [0x1c412aa8]
1c40593f  push edx
1c405940  xor ecx, ecx
1c405942  mov cx, word ptr [0x1c4121b6]
1c405949  shl ecx, 5
1c40594c  sub eax, ecx
1c40594e  push eax
1c40594f  push esi
1c405950  call 0x1c403c50
1c405955  jmp 0x1c405968
1c405957  mov edx, dword ptr [esp + 0x28]
1c40595b  mov eax, dword ptr [0x1c412aa8]
1c405960  push edx
1c405961  push eax
1c405962  push esi
1c405963  call 0x1c4039c0
1c405968  add esp, 0xc
1c40596b  mov ecx, 1
1c405970  mov edx, dword ptr [esp + 0x28]
1c405974  mov eax, dword ptr [edx + 0x16]
1c405977  test ah, 1
1c40597a  je 0x1c405981
1c40597c  mov ecx, 3
1c405981  test al, 0x80
1c405983  je 0x1c405988
1c405985  or ecx, 4
1c405988  mov eax, dword ptr [0x1c412aa8]
1c40598d  xor edx, edx
1c40598f  mov dx, word ptr [0x1c4121b6]
1c405996  shl edx, 5
1c405999  sub eax, edx
1c40599b  or byte ptr [eax + 0x17], cl
1c40599e  mov eax, dword ptr [0x1c412aa8]
1c4059a3  mov dword ptr [esi + 0xfa], eax
1c4059a9  xor ecx, ecx
1c4059ab  movsx eax, word ptr [esi + 0x98]
1c4059b2  add eax, 0x10
1c4059b5  cdq 
1c4059b6  and edx, 0x1f
1c4059b9  add eax, edx
1c4059bb  sar eax, 5
1c4059be  mov cl, al
1c4059c0  movzx ax, byte ptr [ecx + 0x1c405b84]
1c4059c8  mov word ptr [esi + 0xa0], ax
1c4059cf  xor ecx, ecx
1c4059d1  movsx eax, word ptr [esi + 0x9c]
1c4059d8  add eax, 0x10
1c4059db  cdq 
1c4059dc  and edx, 0x1f
1c4059df  add eax, edx
1c4059e1  sar eax, 5
1c4059e4  mov cl, al
1c4059e6  movzx ax, byte ptr [ecx + 0x1c405b84]
1c4059ee  mov word ptr [esi + 0xa4], ax
1c4059f5  xor ecx, ecx
1c4059f7  movsx eax, word ptr [esi + 0x9a]
1c4059fe  add eax, 4
1c405a01  cdq 
1c405a02  and edx, 7
1c405a05  add eax, edx
1c405a07  sar eax, 3
1c405a0a  mov cl, al
1c405a0c  movzx ax, byte ptr [ecx + 0x1c405d84]
1c405a14  mov word ptr [esi + 0xa2], ax
1c405a1b  xor ecx, ecx
1c405a1d  movsx eax, word ptr [esi + 0x9e]
1c405a24  add eax, 4
1c405a27  cdq 
1c405a28  and edx, 7
1c405a2b  pop ebp
1c405a2c  add eax, edx
1c405a2e  pop edi
1c405a2f  sar eax, 3
1c405a32  mov cl, al
1c405a34  movzx ax, byte ptr [ecx + 0x1c405d84]
1c405a3c  mov word ptr [esi + 0xa6], ax
1c405a43  pop esi
1c405a44  pop ebx
1c405a45  add esp, 0x48
1c405a48  ret 
1c405a49  lea ecx, [ecx]
1c405a4c  call 0x2b5c9a9d
1c405a51  dec ebp
1c405a52  inc eax
1c405a53  sbb al, 0x33
1c405a55  dec ebp
1c405a56  inc eax
1c405a57  sbb al, 0xe8
1c405a59  dec esp
1c405a5a  inc eax
1c405a5b  sbb al, 0xf
1c405a5d  dec ebp
1c405a5e  inc eax
1c405a5f  sbb al, 0x9a
1c405a61  dec ebp
1c405a62  inc eax
1c405a63  sbb al, 0
1c405a65  add dword ptr [edx], eax
1c405a67  add eax, 0x5050505
1c405a6c  add eax, 0x5050505
1c405a71  add eax, 0x5050505
1c405a76  add eax, 0x5050505
1c405a7b  add eax, 0x3050505
1c405a80  add al, 0xcc
1c405a82  int3 
1c405a83  int3 
----
1c40a9e0  sub esp, 4
1c40a9e3  push ebx
1c40a9e4  push esi
1c40a9e5  push edi
1c40a9e6  push ebp
1c40a9e7  push 0x1c412540
1c40a9ec  call 0x1c402c30
1c40a9f1  add esp, 4
1c40a9f4  push 0x1c412580
1c40a9f9  call 0x1c402c30
1c40a9fe  add esp, 4
1c40aa01  push 0x1c412360
1c40aa06  call 0x1c402c30
1c40aa0b  add esp, 4
1c40aa0e  push 0x1c412470
1c40aa13  call 0x1c402c30
1c40aa18  add esp, 4
1c40aa1b  xor eax, eax
1c40aa1d  mov ecx, dword ptr [0x1c416f4c]
1c40aa23  mov dword ptr [0x1c41237c], eax
1c40aa28  and ecx, 0x40
1c40aa2b  mov dword ptr [0x1c412378], eax
1c40aa30  je 0x1c40aaf7
1c40aa36  mov al, byte ptr [0x1c412460]
1c40aa3b  sub eax, 0x41
1c40aa3e  cmp eax, 7
1c40aa41  ja 0x1c40aa4a
1c40aa43  jmp dword ptr [eax*4 + 0x1c40b30c]
1c40aa4a  mov dword ptr [0x1c412378], 0
1c40aa54  jmp 0x1c40aab4
1c40aa56  mov dword ptr [0x1c412378], 0x2f
1c40aa60  jmp 0x1c40aab4
1c40aa62  mov dword ptr [0x1c412378], 0x3d
1c40aa6c  jmp 0x1c40aab4
1c40aa6e  mov dword ptr [0x1c412378], 0x37
1c40aa78  jmp 0x1c40aab4
1c40aa7a  mov dword ptr [0x1c412378], 0x31
1c40aa84  jmp 0x1c40aab4
1c40aa86  mov dword ptr [0x1c412378], 0x2e
1c40aa90  jmp 0x1c40aab4
1c40aa92  mov dword ptr [0x1c412378], 0x3c
1c40aa9c  jmp 0x1c40aab4
1c40aa9e  mov dword ptr [0x1c412378], 0x38
1c40aaa8  jmp 0x1c40aab4
1c40aaaa  mov dword ptr [0x1c412378], 0x35
1c40aab4  test byte ptr [0x1c412ac2], 1
1c40aabb  je 0x1c40aacd
1c40aabd  test byte ptr [0x1c416f4c], 0x80
1c40aac4  jne 0x1c40aacd
1c40aac6  add dword ptr [0x1c412378], 3
1c40aacd  cmp byte ptr [0x1c416f50], 0
1c40aad4  jne 0x1c40aaed
1c40aad6  sub dword ptr [0x1c412378], 2
1c40aadd  test byte ptr [0x1c416f4c], 2
1c40aae4  je 0x1c40aaed
1c40aae6  sub dword ptr [0x1c412378], 2
1c40aaed  mov eax, dword ptr [0x1c412378]
1c40aaf2  mov dword ptr [0x1c41237c], eax
1c40aaf7  xor edx, edx
1c40aaf9  mov eax, dword ptr [0x1c412378]
1c40aafe  xor ebx, ebx
1c40ab00  mov dword ptr [0x1c412398], edx
1c40ab06  mov dword ptr [0x1c41239c], 0x4b
1c40ab10  mov dword ptr [0x1c412488], 0xfffffff6
1c40ab1a  mov dword ptr [0x1c412558], 0xbb8
1c40ab24  mov dword ptr [0x1c412598], 0x190
1c40ab2e  mov bl, byte ptr [eax + 0x1c40604e]
1c40ab34  mov eax, dword ptr [0x1c41237c]
1c40ab39  mov dword ptr [0x1c412378], ebx
1c40ab3f  xor ebx, ebx
1c40ab41  mov bl, byte ptr [eax + 0x1c40604e]
1c40ab47  mov dword ptr [0x1c41237c], ebx
1c40ab4d  mov ebx, dword ptr [0x1c416f4c]
1c40ab53  and ebx, 0x40040
1c40ab59  je 0x1c40ad4d
1c40ab5f  cmp byte ptr [0x1c412604], 0x29
1c40ab66  je 0x1c40ab71
1c40ab68  cmp byte ptr [0x1c412604], 0x38
1c40ab6f  jne 0x1c40ab76
1c40ab71  mov edx, 1
1c40ab76  mov esi, dword ptr [0x1c416f4c]
1c40ab7c  and esi, 2
1c40ab7f  je 0x1c40abbe
1c40ab81  test byte ptr [0x1c416f4e], 4
1c40ab88  je 0x1c40abad
1c40ab8a  cmp byte ptr [0x1c412604], 0x36
1c40ab91  je 0x1c40ab9c
1c40ab93  cmp byte ptr [0x1c412604], 0x6c
1c40ab9a  jne 0x1c40abad
1c40ab9c  mov bp, 0xdac
1c40aba0  mov ax, 0x1c2
1c40aba4  mov di, 0xffee
1c40aba8  jmp 0x1c40ac7a
1c40abad  mov bp, 0xfa0
1c40abb1  mov ax, 0x1f4
1c40abb5  mov di, 0xffee
1c40abb9  jmp 0x1c40ac7a
1c40abbe  test byte ptr [0x1c416f4e], 1
1c40abc5  je 0x1c40abed
1c40abc7  test edx, edx
1c40abc9  je 0x1c40abdc
1c40abcb  mov bp, 0x8fc
1c40abcf  mov ax, 0x12c
1c40abd3  mov di, 0xffee
1c40abd7  jmp 0x1c40ac7a
1c40abdc  mov bp, 0x9c4
1c40abe0  mov ax, 0x12c
1c40abe4  mov di, 0xffee
1c40abe8  jmp 0x1c40ac7a
1c40abed  test byte ptr [0x1c416f4f], 4
1c40abf4  je 0x1c40ac3d
1c40abf6  test byte ptr [0x1c412aae], 0x80
1c40abfd  je 0x1c40ac2f
1c40abff  xor eax, eax
1c40ac01  mov al, byte ptr [0x1c412604]
1c40ac06  mov edi, eax
1c40ac08  lea ebp, [eax + eax*4]
1c40ac0b  lea eax, [ebp + ebp*4]
1c40ac0f  add eax, edi
1c40ac11  mov edi, dword ptr [esp + 0x18]
1c40ac15  add eax, dword ptr [edi + 4]
1c40ac18  movsx ebp, word ptr [eax + 8]
1c40ac1c  movsx edi, word ptr [eax + 0xa]
1c40ac20  mov ax, 0xfa
1c40ac24  add ebp, edi
1c40ac26  sar ebp, 1
1c40ac29  mov di, 0xffee
1c40ac2d  jmp 0x1c40ac7a
1c40ac2f  mov bp, 0x834
1c40ac33  mov ax, 0xdc
1c40ac37  mov di, 0xffee
1c40ac3b  jmp 0x1c40ac7a
1c40ac3d  test byte ptr [0x1c416f4c], 8
1c40ac44  je 0x1c40ac54
1c40ac46  mov bp, 0xe10
1c40ac4a  mov ax, 0x3e8
1c40ac4e  mov di, 0xfffa
1c40ac52  jmp 0x1c40ac7a
1c40ac54  test byte ptr [0x1c416f4d], 4
1c40ac5b  je 0x1c40ac6b
1c40ac5d  mov bp, 0xe10
1c40ac61  mov ax, 0x3e8
1c40ac65  mov di, 0xfffd
1c40ac69  jmp 0x1c40ac7a
1c40ac6b  mov ax, word ptr [esp + 0x10]
1c40ac70  mov di, word ptr [esp + 0x10]
1c40ac75  mov bp, word ptr [esp + 0x10]
1c40ac7a  movsx ebp, bp
1c40ac7d  movsx eax, ax
1c40ac80  mov dword ptr [0x1c41255c], ebp
1c40ac86  mov dword ptr [0x1c412558], ebp
1c40ac8c  mov dword ptr [0x1c41259c], eax
1c40ac91  mov dword ptr [0x1c412598], eax
1c40ac96  movsx ebp, di
1c40ac99  mov dword ptr [0x1c41248c], ebp
1c40ac9f  mov dword ptr [0x1c412488], ebp
1c40aca5  test esi, esi
1c40aca7  je 0x1c40acca
1c40aca9  test edx, edx
1c40acab  je 0x1c40acb7
1c40acad  sub dword ptr [0x1c41255c], 0x12c
1c40acb7  test byte ptr [0x1c412ac2], 0x20
1c40acbe  je 0x1c40acca
1c40acc0  sub dword ptr [0x1c412558], 0x12c
1c40acca  test byte ptr [0x1c416f4e], 1
1c40acd1  je 0x1c40ad4d
1c40acd3  test dword ptr [0x1c412ac0], 0x10002000
1c40acdd  je 0x1c40ad02
1c40acdf  mov eax, dword ptr [0x1c4123ec]
1c40ace4  mov esi, 6
1c40ace9  add eax, dword ptr [0x1c4123ac]
1c40acef  sar eax, 1
1c40acf2  add eax, 0x64
1c40acf5  cdq 
1c40acf6  mov dword ptr [0x1c412558], eax
1c40acfb  idiv esi
1c40acfd  mov dword ptr [0x1c412598], eax
1c40ad02  test dword ptr [0x1c412aac], 0x10002000
1c40ad0c  je 0x1c40ad4d
1c40ad0e  xor edx, edx
1c40ad10  mov edi, dword ptr [esp + 0x18]
1c40ad14  mov dl, byte ptr [0x1c412604]
1c40ad1a  mov eax, edx
1c40ad1c  lea ebp, [edx + edx*4]
1c40ad1f  lea edx, [ebp + ebp*4]
1c40ad23  add edx, eax
1c40ad25  add edx, dword ptr [edi + 4]
1c40ad28  mov ebp, 6
1c40ad2d  movsx esi, word ptr [edx + 8]
1c40ad31  movsx eax, word ptr [edx + 0xa]
1c40ad35  add esi, eax
1c40ad37  sar esi, 1
1c40ad3a  add esi, 0x64
1c40ad3d  mov eax, esi
1c40ad3f  mov dword ptr [0x1c41255c], esi
1c40ad45  cdq 
1c40ad46  idiv ebp
1c40ad48  mov dword ptr [0x1c41259c], eax
1c40ad4d  test ecx, ecx
1c40ad4f  jne 0x1c40ad7c
1c40ad51  test byte ptr [0x1c412ac0], 0x40
1c40ad58  je 0x1c40ad7c
1c40ad5a  mov eax, dword ptr [0x1c41254c]
1c40ad5f  mov edx, dword ptr [0x1c41258c]
1c40ad65  mov ebp, dword ptr [0x1c41247c]
1c40ad6b  mov dword ptr [0x1c412558], eax
1c40ad70  mov dword ptr [0x1c412598], edx
1c40ad76  mov dword ptr [0x1c412488], ebp
1c40ad7c  mov edi, dword ptr [0x1c412ac0]
1c40ad82  and edi, 0x40
1c40ad85  jne 0x1c40ade1
1c40ad87  test byte ptr [0x1c412ac2], 4
1c40ad8e  jne 0x1c40ade1
1c40ad90  test byte ptr [0x1c412ab4], 0x40
1c40ad97  je 0x1c40adbb
1c40ad99  mov eax, dword ptr [0x1c412554]
1c40ad9e  mov edx, dword ptr [0x1c412594]
1c40ada4  mov ebp, dword ptr [0x1c412484]
1c40adaa  mov dword ptr [0x1c412548], eax
1c40adaf  mov dword ptr [0x1c412588], edx
1c40adb5  mov dword ptr [0x1c412478], ebp
1c40adbb  test ecx, ecx
1c40adbd  je 0x1c40ade1
1c40adbf  mov eax, dword ptr [0x1c412558]
1c40adc4  mov edx, dword ptr [0x1c412598]
1c40adca  mov ebp, dword ptr [0x1c412488]
1c40add0  mov dword ptr [0x1c41254c], eax
1c40add5  mov dword ptr [0x1c41258c], edx
1c40addb  mov dword ptr [0x1c41247c], ebp
1c40ade1  mov esi, dword ptr [0x1c412ac0]
1c40ade7  and esi, 0x4000000
1c40aded  je 0x1c40ae0a
1c40adef  test dword ptr [0x1c416f4c], 0x10002000
1c40adf9  je 0x1c40ae0a
1c40adfb  mov eax, dword ptr [0x1c4123c4]
1c40ae00  add eax, 0x82
1c40ae05  mov dword ptr [0x1c41254c], eax
1c40ae0a  xor ebp, ebp
1c40ae0c  xor eax, eax
1c40ae0e  mov bp, word ptr [0x1c4121b4]
1c40ae15  mov ax, word ptr [0x1c412acc]
1c40ae1b  lea edx, [ebp + ebp*4]
1c40ae1f  lea eax, [eax + edx*2]
1c40ae22  xor edx, edx
1c40ae24  lea eax, [eax + eax*4]
1c40ae27  add eax, eax
1c40ae29  mov dl, byte ptr [eax + 0x1c40df5a]
1c40ae2f  mov dword ptr [0x1c412388], edx
1c40ae35  mov edx, 0x32
1c40ae3a  mov dword ptr [0x1c412568], edx
1c40ae40  mov dword ptr [0x1c4125a8], edx
1c40ae46  mov dword ptr [0x1c412498], edx
1c40ae4c  xor edx, edx
1c40ae4e  mov dx, word ptr [0x1c412240]
1c40ae55  mov dword ptr [esp + 0x10], 0
1c40ae5d  lea edx, [edx + edx*4]
1c40ae60  lea ebp, [ebp + edx*2]
1c40ae64  lea edx, [ebp + ebp*4]
1c40ae68  mov dl, byte ptr [edx*2 + 0x1c40df5d]
1c40ae6f  mov byte ptr [esp + 0x10], dl
1c40ae73  mov edx, dword ptr [esp + 0x10]
1c40ae77  mov dword ptr [0x1c41238c], edx
1c40ae7d  xor edx, edx
1c40ae7f  test byte ptr [0x1c412ab4], 0x40
1c40ae86  mov dl, byte ptr [eax + 0x1c40df60]
1c40ae8c  mov dword ptr [0x1c412390], edx
1c40ae92  je 0x1c40ae9b
1c40ae94  mov eax, 2
1c40ae99  jmp 0x1c40aea0
1c40ae9b  mov eax, 5
1c40aea0  mov dword ptr [0x1c41249c], eax
1c40aea5  mov dword ptr [0x1c4125ac], eax
1c40aeaa  mov dword ptr [0x1c41256c], eax
1c40aeaf  test ecx, ecx
1c40aeb1  je 0x1c40aeba
1c40aeb3  mov eax, 2
1c40aeb8  jmp 0x1c40aebf
1c40aeba  mov eax, 5
1c40aebf  mov ecx, dword ptr [0x1c412ac0]
1c40aec5  mov dword ptr [0x1c4124a0], eax
1c40aeca  and ecx, 0x40000
1c40aed0  mov dword ptr [0x1c4125b0], eax
1c40aed5  mov dword ptr [0x1c412570], eax
1c40aeda  mov eax, 0
1c40aedf  je 0x1c40aeff
1c40aee1  mov dword ptr [0x1c412498], eax
1c40aee6  mov dword ptr [0x1c4125a8], eax
1c40aeeb  mov dword ptr [0x1c412568], eax
1c40aef0  mov dword ptr [0x1c4124a0], eax
1c40aef5  mov dword ptr [0x1c4125b0], eax
1c40aefa  mov dword ptr [0x1c412570], eax
1c40aeff  xor eax, eax
1c40af01  test edi, edi
1c40af03  je 0x1c40af1d
1c40af05  test byte ptr [0x1c412ab6], 4
1c40af0c  je 0x1c40af1d
1c40af0e  mov dword ptr [0x1c41249c], eax
1c40af13  mov dword ptr [0x1c4125ac], eax
1c40af18  mov dword ptr [0x1c41256c], eax
1c40af1d  mov eax, dword ptr [0x1c412378]
1c40af22  mov edi, 0x64
1c40af27  sub eax, dword ptr [0x1c41236c]
1c40af2d  imul eax, dword ptr [0x1c412388]
1c40af34  cdq 
1c40af35  idiv edi
1c40af37  mov edx, dword ptr [0x1c41236c]
1c40af3d  add edx, eax
1c40af3f  mov eax, dword ptr [0x1c412558]
1c40af44  sub eax, dword ptr [0x1c41254c]
1c40af4a  mov dword ptr [0x1c412384], edx
1c40af50  imul eax, dword ptr [0x1c412568]
1c40af57  cdq 
1c40af58  idiv edi
1c40af5a  mov edx, dword ptr [0x1c41254c]
1c40af60  add edx, eax
1c40af62  mov eax, dword ptr [0x1c412598]
1c40af67  sub eax, dword ptr [0x1c41258c]
1c40af6d  mov dword ptr [0x1c412564], edx
1c40af73  imul eax, dword ptr [0x1c4125a8]
1c40af7a  cdq 
1c40af7b  idiv edi
1c40af7d  mov edx, dword ptr [0x1c41258c]
1c40af83  add edx, eax
1c40af85  mov eax, dword ptr [0x1c412488]
1c40af8a  sub eax, dword ptr [0x1c41247c]
1c40af90  mov dword ptr [0x1c4125a4], edx
1c40af96  imul eax, dword ptr [0x1c412498]
1c40af9d  cdq 
1c40af9e  idiv edi
1c40afa0  mov edx, dword ptr [0x1c41247c]
1c40afa6  add edx, eax
1c40afa8  xor eax, eax
1c40afaa  mov word ptr [0x1c4121dc], ax
1c40afb0  mov dword ptr [0x1c412494], edx
1c40afb6  mov word ptr [0x1c4121ac], ax
1c40afbc  mov edx, dword ptr [0x1c412ac0]
1c40afc2  and edx, 1
1c40afc5  jne 0x1c40afe5
1c40afc7  test ecx, ecx
1c40afc9  je 0x1c40b302
1c40afcf  test byte ptr [0x1c416f4f], 0x20
1c40afd6  je 0x1c40afe5
1c40afd8  test byte ptr [0x1c416f4d], 0x80
1c40afdf  je 0x1c40b302
1c40afe5  xor di, di
1c40afe8  movsx ebp, di
1c40afeb  mov al, byte ptr [0x1c412ace]
1c40aff0  cmp byte ptr [ebp*2 + 0x1c40def8], al
1c40aff7  je 0x1c40b001
1c40aff9  inc di
1c40affb  cmp di, 0xf
1c40afff  jl 0x1c40afe8
1c40b001  movsx ebp, di
1c40b004  cmp byte ptr [0x1c416f53], 0x41
1c40b00b  movzx ax, byte ptr [ebp*2 + 0x1c40def9]
1c40b014  mov word ptr [0x1c4121dc], ax
1c40b01a  je 0x1c40b03f
1c40b01c  cmp byte ptr [0x1c412ace], 0x52
1c40b023  jne 0x1c40b03f
1c40b025  cmp byte ptr [0x1c412460], 0x6c
1c40b02c  je 0x1c40b037
1c40b02e  cmp byte ptr [0x1c412460], 0x36
1c40b035  jne 0x1c40b03f
1c40b037  add word ptr [0x1c4121dc], 3
1c40b03f  test edx, edx
1c40b041  je 0x1c40b05d
1c40b043  cmp byte ptr [0x1c412ac4], 0
1c40b04a  je 0x1c40b05d
1c40b04c  cmp byte ptr [0x1c412460], 0x6c
1c40b053  je 0x1c40b05d
1c40b055  add word ptr [0x1c4121dc], 2
1c40b05d  cmp byte ptr [0x1c416f53], 0x41
1c40b064  jne 0x1c40b078
1c40b066  test byte ptr [0x1c416f40], 0x80
1c40b06d  je 0x1c40b078
1c40b06f  mov word ptr [0x1c4121dc], 2
1c40b078  mov ax, word ptr [0x1c4121dc]
1c40b07e  mov di, word ptr [0x1c4121b6]
1c40b085  cmp ax, di
1c40b088  jl 0x1c40b08d
1c40b08a  mov ax, di
1c40b08d  mov word ptr [0x1c4121dc], ax
1c40b093  test ecx, ecx
1c40b095  je 0x1c40b12d
1c40b09b  xor eax, eax
1c40b09d  mov al, byte ptr [0x1c412ace]
1c40b0a2  sub eax, 0x49
1c40b0a5  cmp eax, 0xb
1c40b0a8  ja 0x1c40b0b1
1c40b0aa  jmp dword ptr [eax*4 + 0x1c40b32c]
1c40b0b1  mov word ptr [0x1c4121ac], 0
1c40b0ba  jmp 0x1c40b12d
1c40b0bc  mov word ptr [0x1c4121ac], 0x3b
1c40b0c5  jmp 0x1c40b12d
1c40b0c7  mov word ptr [0x1c4121ac], 0x3e
1c40b0d0  jmp 0x1c40b12d
1c40b0d2  mov word ptr [0x1c4121ac], 0
1c40b0db  jmp 0x1c40b12d
1c40b0dd  mov word ptr [0x1c4121ac], 0
1c40b0e6  jmp 0x1c40b12d
1c40b0e8  mov word ptr [0x1c4121ac], 0
1c40b0f1  jmp 0x1c40b12d
1c40b0f3  mov word ptr [0x1c4121ac], 0x32
1c40b0fc  jmp 0x1c40b12d
1c40b0fe  cmp byte ptr [0x1c416f53], 0x41
1c40b105  mov word ptr [0x1c4121ac], 0x25
1c40b10e  je 0x1c40b12d
1c40b110  cmp byte ptr [0x1c412460], 0x6c
1c40b117  jne 0x1c40b12d
1c40b119  mov word ptr [0x1c4121ac], 0x2b
1c40b122  jmp 0x1c40b12d
1c40b124  mov word ptr [0x1c4121ac], 0x3a
1c40b12d  mov ecx, dword ptr [0x1c412ac0]
1c40b133  and ecx, 0x10000
1c40b139  je 0x1c40b14c
1c40b13b  test byte ptr [0x1c416f4c], 0x80
1c40b142  jne 0x1c40b14c
1c40b144  add word ptr [0x1c4121ac], 4
1c40b14c  mov eax, dword ptr [0x1c412ab4]
1c40b151  and eax, 0x8000
1c40b156  je 0x1c40b16b
1c40b158  cmp byte ptr [0x1c412ac4], 0
1c40b15f  jne 0x1c40b16b
1c40b161  sub word ptr [0x1c4121ac], 6
1c40b169  jmp 0x1c40b180
1c40b16b  test eax, eax
1c40b16d  jne 0x1c40b180
1c40b16f  cmp byte ptr [0x1c412ac4], 0
1c40b176  jne 0x1c40b180
1c40b178  sub word ptr [0x1c4121ac], 3
1c40b180  test ebx, ebx
1c40b182  je 0x1c40b18c
1c40b184  sub word ptr [0x1c4121ac], 3
1c40b18c  cmp byte ptr [0x1c416f53], 0x41
1c40b193  jne 0x1c40b1a6
1c40b195  test byte ptr [0x1c416f40], 0x80
1c40b19c  je 0x1c40b1a6
1c40b19e  sub word ptr [0x1c4121ac], 3
1c40b1a6  test edx, edx
1c40b1a8  jne 0x1c40b302
1c40b1ae  cmp byte ptr [0x1c412460], 0x40
1c40b1b5  jne 0x1c40b1c0
1c40b1b7  mov word ptr [0x1c4121ac], 0
1c40b1c0  test edx, edx
1c40b1c2  jne 0x1c40b302
1c40b1c8  test byte ptr [0x1c416f4c], 1
1c40b1cf  jne 0x1c40b302
1c40b1d5  test byte ptr [0x1c416f4e], 4
1c40b1dc  je 0x1c40b26f
1c40b1e2  mov eax, 0x400
1c40b1e7  test dword ptr [0x1c412ac0], eax
1c40b1ed  je 0x1c40b208
1c40b1ef  test dword ptr [0x1c416f4c], eax
1c40b1f5  je 0x1c40b208
1c40b1f7  mov word ptr [0x1c4121ac], 0
1c40b200  pop ebp
1c40b201  pop edi
1c40b202  pop esi
1c40b203  pop ebx
1c40b204  add esp, 4
1c40b207  ret 
1c40b208  test byte ptr [0x1c412ac0], 2
1c40b20f  je 0x1c40b22b
1c40b211  test byte ptr [0x1c416f4c], 2
1c40b218  je 0x1c40b22b
1c40b21a  mov word ptr [0x1c4121ac], 0
1c40b223  pop ebp
1c40b224  pop edi
1c40b225  pop esi
1c40b226  pop ebx
1c40b227  add esp, 4
1c40b22a  ret 
1c40b22b  test esi, esi
1c40b22d  je 0x1c40b249
1c40b22f  test byte ptr [0x1c416f4f], 4
1c40b236  je 0x1c40b249
1c40b238  mov word ptr [0x1c4121ac], 0
1c40b241  pop ebp
1c40b242  pop edi
1c40b243  pop esi
1c40b244  pop ebx
1c40b245  add esp, 4
1c40b248  ret 
1c40b249  test ecx, ecx
1c40b24b  je 0x1c40b302
1c40b251  test byte ptr [0x1c416f4e], 1
1c40b258  je 0x1c40b302
1c40b25e  mov word ptr [0x1c4121ac], 0
1c40b267  pop ebp
1c40b268  pop edi
1c40b269  pop esi
1c40b26a  pop ebx
1c40b26b  add esp, 4
1c40b26e  ret 
1c40b26f  cmp byte ptr [0x1c412460], 0x40
1c40b276  jne 0x1c40b302
1c40b27c  test byte ptr [0x1c412aae], 4
1c40b283  je 0x1c40b302
1c40b285  mov eax, 0x400
1c40b28a  test dword ptr [0x1c412ac0], eax
1c40b290  je 0x1c40b2ab
1c40b292  test dword ptr [0x1c412aac], eax
1c40b298  je 0x1c40b2ab
1c40b29a  mov word ptr [0x1c4121ac], 0
1c40b2a3  pop ebp
1c40b2a4  pop edi
1c40b2a5  pop esi
1c40b2a6  pop ebx
1c40b2a7  add esp, 4
1c40b2aa  ret 
1c40b2ab  test byte ptr [0x1c412ac0], 2
1c40b2b2  je 0x1c40b2ce
1c40b2b4  test byte ptr [0x1c412aac], 2
1c40b2bb  je 0x1c40b2ce
1c40b2bd  mov word ptr [0x1c4121ac], 0
1c40b2c6  pop ebp
1c40b2c7  pop edi
1c40b2c8  pop esi
1c40b2c9  pop ebx
1c40b2ca  add esp, 4
1c40b2cd  ret 
1c40b2ce  test esi, esi
1c40b2d0  je 0x1c40b2ec
1c40b2d2  test byte ptr [0x1c412aaf], 4
1c40b2d9  je 0x1c40b2ec
1c40b2db  mov word ptr [0x1c4121ac], 0
1c40b2e4  pop ebp
1c40b2e5  pop edi
1c40b2e6  pop esi
1c40b2e7  pop ebx
1c40b2e8  add esp, 4
1c40b2eb  ret 
1c40b2ec  test ecx, ecx
1c40b2ee  je 0x1c40b302
1c40b2f0  test byte ptr [0x1c412aae], 1
1c40b2f7  je 0x1c40b302
1c40b2f9  mov word ptr [0x1c4121ac], 0
1c40b302  pop ebp
1c40b303  pop edi
1c40b304  pop esi
1c40b305  pop ebx
1c40b306  add esp, 4
1c40b309  ret 
