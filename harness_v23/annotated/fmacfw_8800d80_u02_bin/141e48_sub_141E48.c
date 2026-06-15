// v23 annotated: sub_141E48 @ 0x141e48
// Original: 141e48_sub_141E48.c
// Primary struct: <unclustered>
//
// sub_141E48 @ 0x141e48, size 130 bytes
_BYTE *__fastcall sub_141E48(int a1)
{
  int v2; // r5
  __int16 v3; // r3
  int v4; // r2
  _BYTE *result; // r0
  int v6; // r5
  __int64 v7; // r2
  int i; // r8
  unsigned __int64 v9; // r6
  unsigned __int64 v10; // r0

  v2 = *(unsigned __int8 *)(a1 + 47);
  sub_124E34(a1 + 52);
  v3 = *(_WORD *)a1;
  v4 = dword_141ECC;
  result = off_141ED0;
  *(_WORD *)a1 &= ~8u;
  v6 = v4 + 1320 * v2;
  LOBYTE(v4) = result[1] - 1;
  *(_DWORD *)(v6 + 4) &= ~0x100u;
  result[1] = v4;
  if ( (v3 & 0x60) == 0x20 )
  {
    v7 = *(_QWORD *)(a1 + 24);
    for ( i = 1; ; i = (unsigned __int8)(i + 1) )
    {
      v9 = v7 - *(_QWORD *)(v6 + 40);
      LODWORD(v10) = sub_12BE40();
      if ( v9 >= v10 )
        break;
      v7 = *(_QWORD *)(a1 + 24) + *(unsigned int *)(a1 + 16);
      *(_QWORD *)(a1 + 24) = v7;
    }
    return (_BYTE *)sub_141D4C(a1, i);
  }
  return result;
}

