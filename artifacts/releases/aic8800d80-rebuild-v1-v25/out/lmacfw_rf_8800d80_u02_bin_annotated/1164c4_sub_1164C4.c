// fwstruct annotate: 1164c4_sub_1164C4.c
// sub_1164C4 @ 0x1164c4, size 168 bytes
int __fastcall sub_1164C4(int a1, int a2, int a3)
{
  __int64 v3; // kr00_8
  int v6; // r1
  int v7; // r7
  int result; // r0
  int v9; // r2
  int v10; // r3
  int v11; // r2
  unsigned __int64 v12; // kr08_8

  v3 = *(_QWORD *)(a1 + 28);
  if ( a3 > 4096 )
  {
    v12 = (unsigned int)dword_11657C * (unsigned __int64)(unsigned int)(v3 - dword_116578);
    *(_DWORD *)(HIDWORD(v3) + 28) = *(_DWORD *)(HIDWORD(v3) + 24) + 4095;
    *(_DWORD *)(HIDWORD(v3) + 32) = sub_123B30(HIDWORD(v3) + 8, a3, HIDWORD(v12) >> 12) + 4;
  }
  else
  {
    *(_DWORD *)(HIDWORD(v3) + 28) = *(_DWORD *)(HIDWORD(v3) + 24) + a3 - 1;
    *(_DWORD *)(HIDWORD(v3) + 32) = a3 + 4;
    *(_DWORD *)(HIDWORD(v3) + 20) = 0;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
      v6 = dword_116574;
    else
      v6 = v3 + 44;
    v7 = v3 + 44;
  }
  else
  {
    v6 = dword_116570;
    v7 = v3 + 44;
  }
  result = sub_1282E8(v7, v6, 52);
  v9 = *(_DWORD *)off_11656C;
  if ( *(_DWORD *)(v3 + 64) & 0x7C | (*(_DWORD *)(v3 + 64) >> 11) & 6 )
    v10 = (unsigned __int16)((unsigned __int16)*(_DWORD *)off_11656C << 8) | (unsigned __int8)v9;
  else
    v10 = *(_DWORD *)off_11656C & 0xFF00 | BYTE1(v9);
  v11 = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(v3 + 80) = v10;
  *(_DWORD *)(HIDWORD(v3) + 40) = 0;
  *(_DWORD *)(HIDWORD(v3) + 44) = v7;
  *(_DWORD *)(HIDWORD(v3) + 64) = 0;
  *(_DWORD *)(a1 + 44) = 0;
  *(_DWORD *)(a1 + 48) = 0;
  *(_DWORD *)(v11 + 40) = 0;
  *(_WORD *)(a1 + 38) = 0;
  return result;
}

