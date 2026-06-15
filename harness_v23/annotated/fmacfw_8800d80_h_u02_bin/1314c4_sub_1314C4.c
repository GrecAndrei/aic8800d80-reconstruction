// v23 annotated: sub_1314C4 @ 0x1314c4
// Original: 1314c4_sub_1314C4.c
// Primary struct: <unclustered>
//
// sub_1314C4 @ 0x1314c4, size 118 bytes
int __fastcall sub_1314C4(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v4; // r0
  int v7; // r4
  int v8; // r1
  int v9; // r7
  _BYTE *v10; // r0

  v4 = *a2;
  if ( a2[1] )
  {
    v7 = dword_13153C + 696 * v4;
    v8 = *(unsigned __int8 *)(v7 + 34);
    v9 = *(unsigned __int8 *)(dword_131540 + 1320 * v8 + 106);
    *(_BYTE *)(v7 + 52) = 2;
    if ( !v9 && ((*((_DWORD *)off_131544 + 1) >> v8) & 1) != 0 )
    {
      v10 = (_BYTE *)sub_12C7EC(5145, 5, 6, 2u);
      *v10 = 0;
      v10[1] = *(_BYTE *)(v7 + 34);
      sub_12C84C((int)v10);
    }
  }
  else
  {
    *(_BYTE *)(dword_13153C + 696 * v4 + 52) = 1;
  }
  sub_12C8D0(5125, a4, a3);
  return 0;
}

