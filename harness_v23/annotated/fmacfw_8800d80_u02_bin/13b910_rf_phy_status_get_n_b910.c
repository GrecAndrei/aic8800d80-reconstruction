// v23 annotated: rf_phy_status_get_n_b910 @ 0x13b910
// Original: 13b910_rf_phy_status_get_n_b910.c
// Primary struct: <unclustered>
//
// rf_phy_status_get_n_b910 @ 0x13b910, size 68 bytes
// Doc: rf_phy_status_get_n_b910 [rf]: Read PHY state byte at offset 0x106 and check mode 2
// rf_phy_status_get_n_b910 [rf]: Read PHY state byte at offset 0x106 and check mode 2
int __fastcall rf_phy_status_get_n_b910(int a1)
{
  int v1; // r3
  int v2; // r6
  int (__fastcall *v4)(int, int); // r2
  unsigned __int8 v5; // r0

  v1 = *(unsigned __int8 *)(a1 + 262) + a1;
  if ( *(_BYTE *)(v1 + 6) != 2 )
    return 0;
  LOBYTE(v2) = 0;
  do
  {
    *(_BYTE *)(v1 + 6) = 0;
    v4 = *(int (__fastcall **)(int, int))a1;
    *(_WORD *)(a1 + 4) = (*(_WORD *)(a1 + 4) + 1) & 0xFFF;
    v5 = v4(a1, 1);
    v1 = a1 + v5;
    *(_BYTE *)(a1 + 262) = v5;
    v2 = (char)(v2 + 1);
  }
  while ( *(_BYTE *)(v1 + 6) == 2 );
  return v2;
}

