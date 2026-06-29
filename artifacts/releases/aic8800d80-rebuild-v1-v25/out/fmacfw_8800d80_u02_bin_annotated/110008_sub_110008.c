// fwstruct annotate: 110008_sub_110008.c
// sub_110008 @ 0x110008, size 218 bytes
int __fastcall sub_110008(_DWORD *a1)
{
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = sub_10FF34((unsigned int)a1);
  if ( !result )
  {
    result = sub_10DC24(dword_1100EC, a1);
    v5 = **(unsigned __int8 **)off_1100E4;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return sub_113A48(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !sub_10FF34((unsigned int)a1) )
          sub_10DC24(dword_1100FC, a1);
        return sub_10FCE0(dword_1100F0, a1);
      }
      if ( **(__int16 **)off_1100E8 < 0 )
        return sub_12F46C(dword_1100F8, dword_1100F4, 204);
      return result;
    }
    return sub_1104C0(a1);
  }
  v3 = *((unsigned __int8 *)a1 - 4);
  v4 = **(unsigned __int8 **)off_1100E4;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return sub_110390(a1);
    if ( v3 == 2 )
      return sub_110430(a1);
    if ( *((_BYTE *)a1 - 4) )
      return result;
    return sub_1104C0(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(__int16 **)off_1100E8 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return sub_11428C(a1);
      }
      if ( v3 == 3 )
        return sub_11428C(a1);
      return sub_12F46C(dword_1100F8, dword_1100F4, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return sub_113904(a1);
  if ( !*((_BYTE *)a1 - 4) )
    return sub_113A48(a1);
  return result;
}

