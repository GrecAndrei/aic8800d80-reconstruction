// v23 annotated: sub_1416C0 @ 0x1416c0
// Original: 1416c0_sub_1416C0.c
// Primary struct: <unclustered>
//
// sub_1416C0 @ 0x1416c0, size 106 bytes
_DWORD *__fastcall sub_1416C0(int a1, int a2)
{
  int v2; // r4
  int v4; // r6
  _DWORD *result; // r0

  if ( a2 )
  {
    v2 = dword_14172C;
    v4 = *(_DWORD *)(dword_14172C + 6480);
    if ( mmio_read_status() )
    {
      if ( msg_get_value(0xBu) == 3 )
        return (_DWORD *)sub_1415EC();
      else
        return sub_141484();
    }
    else
    {
      *(_BYTE *)(a1 + 98) = 1;
      sub_140540(a1, 0, 0, v2 + 136 * v4 + 6336);
      return (_DWORD *)rf_param_get_status(a1, 3);
    }
  }
  else
  {
    result = sub_12CD34(0xBu, 0);
    *(_DWORD *)(dword_14172C + 6480) = -1;
  }
  return result;
}

