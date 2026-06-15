// v23 annotated: sub_10FEAC @ 0x10feac
// Original: 10feac_sub_10FEAC.c
// Primary struct: <unclustered>
//
// sub_10FEAC @ 0x10feac, size 62 bytes
_DWORD *__fastcall sub_10FEAC(char a1)
{
  _DWORD *v2; // r4

  if ( **(_BYTE **)off_10FEEC == 1 )
    v2 = (_DWORD *)sub_110370();
  else
    v2 = log_pool_alloc2_a18(dword_10FEF0, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( log_ptr_in_range((unsigned int)v2) )
  {
    *((_BYTE *)v2 - 1) = a1;
    return v2;
  }
  sub_10DA6C(dword_10FEF4, v2);
  return v2;
}

