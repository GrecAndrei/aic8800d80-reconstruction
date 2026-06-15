// v23 annotated: sub_14175C @ 0x14175c
// Original: 14175c_sub_14175C.c
// Primary struct: <unclustered>
//
// sub_14175C @ 0x14175c, size 106 bytes
_DWORD *__fastcall sub_14175C(int a1, int a2)
{
  int v2; // r4
  int v4; // r6
  _DWORD *result; // r0

  if ( a2 )
  {
    v2 = dword_1417C8;
    v4 = *(_DWORD *)(dword_1417C8 + 6480);
    if ( sub_1405AC() )
    {
      if ( msg_get_value(0xBu) == 3 )
        return (_DWORD *)sub_141688();
      else
        return sub_141520();
    }
    else
    {
      *(_BYTE *)(a1 + 98) = 1;
      sub_1405DC(a1, 0, 0, v2 + 136 * v4 + 6336);
      return (_DWORD *)sub_1190B4(a1, 3);
    }
  }
  else
  {
    result = rf_bus_mark_n_3b7(0xBu, 0);
    *(_DWORD *)(dword_1417C8 + 6480) = -1;
  }
  return result;
}

