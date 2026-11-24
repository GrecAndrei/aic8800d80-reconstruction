// sub_118A78 @ 0x118a78, size 126 bytes
int __fastcall sub_118A78(int a1, int a2, int a3)
{
  __int64 v3; // kr00_8
  int v5; // r1
  int v6; // r7
  int result; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r2

  v3 = *(_QWORD *)(a1 + 72);
  *(_DWORD *)(HIDWORD(v3) + 32) = *(_DWORD *)(HIDWORD(v3) + 28) + a3 - 1;
  *(_DWORD *)(HIDWORD(v3) + 36) = a3 + 4;
  *(_DWORD *)(HIDWORD(v3) + 24) = 0;
  if ( a2 )
  {
    if ( a2 == 1 )
      v5 = dword_118B00;
    else
      v5 = v3 + 44;
    v6 = v3 + 44;
  }
  else
  {
    v5 = dword_118AFC;
    v6 = v3 + 44;
  }
  result = sub_143630(v6, v5, 52);
  v8 = *(_DWORD *)off_118AF8;
  if ( *(_DWORD *)(v3 + 64) & 0x7C | (*(_DWORD *)(v3 + 64) >> 11) & 6 )
    v9 = (unsigned __int16)((unsigned __int16)*(_DWORD *)off_118AF8 << 8) | (unsigned __int8)v8;
  else
    v9 = *(_DWORD *)off_118AF8 & 0xFF00 | BYTE1(v8);
  v10 = *(_DWORD *)(a1 + 72);
  *(_DWORD *)(v3 + 80) = v9;
  *(_DWORD *)(HIDWORD(v3) + 44) = 0;
  *(_DWORD *)(HIDWORD(v3) + 48) = v6;
  *(_DWORD *)(HIDWORD(v3) + 68) = 0;
  *(_DWORD *)(a1 + 88) = 0;
  *(_DWORD *)(a1 + 92) = 0;
  *(_DWORD *)(v10 + 40) = 0;
  *(_WORD *)(a1 + 82) = 0;
  return result;
}

