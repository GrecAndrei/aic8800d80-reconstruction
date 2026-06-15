// v23 annotated: sub_136C94 @ 0x136c94
// Original: 136c94_sub_136C94.c
// Primary struct: <unclustered>
//
// sub_136C94 @ 0x136c94, size 100 bytes
// Doc: bt_fmac_handler_n136 [bt]: BT FMAC handler checking flag bitmask against per-channel mask
// bt_fmac_handler_n136 [bt]: BT FMAC handler checking flag bitmask against per-channel mask
int __fastcall sub_136C94(int result, int a2)
{
  int v3; // r3
  int v4; // r0

  if ( (*(_WORD *)(result + 30) & 0x1000) != 0 )
  {
    v3 = *(unsigned __int8 *)(a2 + 310);
    if ( ((unsigned __int8)v3 & *(_BYTE *)(dword_136CF8 + *(unsigned __int8 *)(result + 27))) != 0 )
    {
      if ( (*(_BYTE *)(a2 + 53) & 8) == 0 )
      {
        *(_BYTE *)(a2 + 53) |= 8u;
        if ( v3 == 15 )
          goto LABEL_5;
      }
    }
    else if ( (*(_BYTE *)(a2 + 53) & 2) == 0 )
    {
      *(_BYTE *)(a2 + 53) |= 2u;
LABEL_5:
      v4 = rf_bus_setup_n3a8(65, 0, 5, 4u);
      *(_WORD *)v4 = *(_WORD *)(a2 + 32);
      *(_BYTE *)(v4 + 3) = *(_BYTE *)(a2 + 34);
      *(_BYTE *)(v4 + 2) = 1;
      return sub_12CBB4(v4);
    }
  }
  return result;
}

