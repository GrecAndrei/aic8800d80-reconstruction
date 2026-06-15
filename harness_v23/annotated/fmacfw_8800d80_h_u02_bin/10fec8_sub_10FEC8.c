// v23 annotated: sub_10FEC8 @ 0x10fec8
// Original: 10fec8_sub_10FEC8.c
// Primary struct: <unclustered>
//
// sub_10FEC8 @ 0x10fec8, size 218 bytes
int __fastcall sub_10FEC8(_DWORD *a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = sub_10FDF4((unsigned int)a1);
  if ( !result )
  {
    result = sub_10DAE4(dword_10FFAC, a1);
    v5 = **(unsigned __int8 **)off_10FFA4;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return sub_113908(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !sub_10FDF4((unsigned int)a1) )
          sub_10DAE4(dword_10FFBC, a1);
        return sub_10FBA0(dword_10FFB0, a1);
      }
      if ( **(__int16 **)off_10FFA8 < 0 )
        return sub_12F32C(dword_10FFB8, dword_10FFB4, 204);
      return result;
    }
    return sub_110380(a1);
  }
  v3 = *((unsigned __int8 *)a1 - 4);
  v4 = **(unsigned __int8 **)off_10FFA4;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return sub_110250(a1);
    if ( v3 == 2 )
      return sub_1102F0(a1);
    if ( *((_BYTE *)a1 - 4) )
      return result;
    return sub_110380(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(__int16 **)off_10FFA8 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return sub_11414C(a1);
      }
      if ( v3 == 3 )
        return sub_11414C(a1);
      return sub_12F32C(dword_10FFB8, dword_10FFB4, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return sub_1137C4(a1);
  if ( !*((_BYTE *)a1 - 4) )
    return sub_113908(a1);
  return result;
}

