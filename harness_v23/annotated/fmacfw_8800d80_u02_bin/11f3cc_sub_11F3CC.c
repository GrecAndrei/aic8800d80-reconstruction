// v23 annotated: sub_11F3CC @ 0x11f3cc
// Original: 11f3cc_sub_11F3CC.c
// Primary struct: <unclustered>
//
// sub_11F3CC @ 0x11f3cc, size 122 bytes
int __fastcall sub_11F3CC(int a1, int a2, int a3)
{
  int v3; // r10
  int v4; // r4
  int v8; // r9
  int v9; // r1
  int v10; // r0
  int v12; // [sp+4h] [bp-4h] BYREF

  v3 = *(_DWORD *)(a2 + 572);
  if ( !v3 )
    return 0;
  v4 = 0;
  v8 = a2 + 572;
  do
  {
    v12 = 0;
    if ( !scan_chan_setup_n134(a1) )
      break;
    if ( !phy_chan_table_lookup(v3) )
      break;
    v10 = sub_136BD0(a1, a2, &v12);
    if ( v12 )
      break;
    if ( !v10 )
      v10 = rf_bus_mark_n100_d2d0(v8);
    v9 = *(unsigned __int8 *)(v10 + 27);
    *(_BYTE *)(v10 + 97) = 0;
    ++v4;
    sub_1176A0(v10, v9);
    if ( a3 )
    {
      if ( v4 == a3 )
        break;
    }
    v3 = *(_DWORD *)(a2 + 572);
  }
  while ( v3 );
  return v4;
}

