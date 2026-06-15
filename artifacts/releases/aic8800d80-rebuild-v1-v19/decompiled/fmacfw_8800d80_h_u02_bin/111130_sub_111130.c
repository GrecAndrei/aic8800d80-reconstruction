// sub_111130 @ 0x111130, size 118 bytes
int __fastcall sub_111130(char a1, int a2, int a3)
{
  _DWORD *v6; // r0
  _DWORD *v7; // r4
  _DWORD *v8; // r6
  int v9; // r2
  int v10; // r3

  v6 = sub_10FE7C(4);
  if ( !v6 )
    return sub_10DAE4(dword_1111B0);
  v7 = v6;
  v8 = (_DWORD *)sub_11017C();
  if ( v8 )
  {
    *(_BYTE *)v7 = a3;
    *((_BYTE *)v7 + 1) = BYTE1(a3) & 0xF;
    *((_BYTE *)v7 + 2) = a1;
    *((_BYTE *)v7 + 3) = 0;
    sub_143630(v7 + 1, a2, a3);
    v9 = v8[2];
    v10 = dword_1111A8;
    v8[1] = 0;
    *v8 = v7;
    v8[2] = (unsigned __int16)(a3 + 4) | v10 & v9 | 0x80000000;
    return sub_11101C((int)v8);
  }
  else
  {
    sub_10DAE4(dword_1111AC);
    return sub_10FEC8(v7);
  }
}

