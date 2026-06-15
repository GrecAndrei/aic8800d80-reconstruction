// sub_10DB9C @ 0x10db9c, size 174 bytes
int __fastcall sub_10DB9C(int result, int a2, int a3)
{
  int v3; // r4
  _DWORD *v4; // r6
  _DWORD *v5; // r3
  int v6; // r6
  _DWORD *v7; // r3
  _BYTE *v8; // r5
  bool v9; // nf

  v3 = 1 << result;
  if ( result <= 7 )
  {
    v4 = off_10DC4C;
    dword_40504080[result] &= 0xFFFFFFF0;
    v4[1] |= v3;
  }
  v5 = off_10DC4C;
  *((_DWORD *)off_10DC4C + 2) &= ~v3;
  v5[10] |= v3;
  v5[3] &= ~v3;
  v6 = ~v3;
  if ( a2 == 2 )
  {
    v5[4] |= v3;
  }
  else
  {
    v5[4] &= v6;
    if ( a2 )
      v5[5] &= v6;
    else
      v5[5] |= v3;
  }
  v7 = off_10DC4C;
  v8 = off_10DC50;
  *((_DWORD *)off_10DC4C + 9) = v3;
  v7[6] |= v3;
  v7[11] |= 7 << (result & 0xFC);
  v9 = (*(_DWORD *)v8 & 0x800000) != 0;
  *(_DWORD *)(dword_10DC54 + 4 * result) = a3;
  if ( !v9 )
  {
    result = dword_10DC5C;
    *(_DWORD *)(*((_DWORD *)off_10DC58 + 2) + 156) = dword_10DC5C;
    v8[791] = -4;
    *(_DWORD *)v8 = 0x800000;
  }
  return result;
}

