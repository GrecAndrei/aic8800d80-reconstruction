// phy_chan_table_lookup @ 0x136b08, size 88 bytes
// Doc: phy_chan_table_lookup [mac]: Look up PHY channel entry in indexed table (stride 0x528)
// phy_chan_table_lookup [mac]: Look up PHY channel entry in indexed table (stride 0x528)
int __fastcall phy_chan_table_lookup(int a1)
{
  unsigned int v1; // r3
  int v2; // r2
  int v3; // r3

  if ( *(_BYTE *)(dword_136B60 + 1320 * *(unsigned __int8 *)(a1 + 28) + 106) != 2 )
    return 1;
  v1 = *(unsigned __int8 *)(a1 + 29);
  if ( v1 > 0x23 || !*(_WORD *)(a1 + 4) && *(_WORD *)(*(_DWORD *)(a1 + 72) + 108) == 584 )
    return 1;
  v2 = dword_136B64 + 696 * v1;
  v3 = *(unsigned __int8 *)(v2 + 36);
  if ( v3 != 1 )
    return 1;
  if ( (*(_BYTE *)(v2 + 54) & 3) == 0 )
  {
    v3 = 0;
    *(_WORD *)(a1 + 30) |= 0x1000u;
  }
  return v3;
}

