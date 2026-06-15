// v23 annotated: sub_123AB4 @ 0x123ab4
// Original: 123ab4_sub_123AB4.c
// Primary struct: <unclustered>
//
// sub_123AB4 @ 0x123ab4, size 130 bytes
int __fastcall sub_123AB4(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v7; // r2
  _WORD *v8; // r5
  int result; // r0

  if ( sub_12CD48(a3) == 3 || sub_12CD48(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = off_123B38;
  *((_BYTE *)off_123B38 + 31) = v7;
  if ( !v7 )
  {
    if ( sub_12CD48(a3) != 2 )
    {
      sub_120FA4();
LABEL_6:
      sub_12C8D0(35, a4, a3);
      return 0;
    }
    return 2;
  }
  result = sub_12CD48(a3);
  if ( !result )
  {
    if ( **(__int16 **)off_123B3C < 0 )
    {
      if ( *(_DWORD *)off_123B40 << 28 )
        sub_12F32C(dword_123B48, dword_123B44, 1522);
    }
    v8[9] = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    sub_12B6C4(result);
    sub_12CBF4(a3);
    return 2;
  }
  return result;
}

