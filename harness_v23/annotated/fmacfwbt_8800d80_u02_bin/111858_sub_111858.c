// v23 annotated: sub_111858 @ 0x111858
// Original: 111858_sub_111858.c
// Primary struct: <unclustered>
//
// sub_111858 @ 0x111858, size 242 bytes
// Doc: rf_bus_write2_n_1bc_18bc [rf]: Configure RF bus register with mask flags
// rf_bus_write2_n_1bc_18bc [rf]: Configure RF bus register with mask flags
int sub_111858()
{
  _DWORD *v0; // r2
  _DWORD *v1; // r2
  _DWORD *v2; // r1
  _DWORD *v3; // r2
  _DWORD *v4; // r1
  int v5; // r3
  _DWORD *v6; // r2
  int v7; // r0

  v0 = rf_bus_reset2_nf4_194c;
  *((_DWORD *)rf_bus_reset2_nf4_194c + 4) |= 1u;
  while ( (v0[4] & 1) != 0 )
    ;
  v1 = rf_bus_reset2_nf4_194c;
  while ( *((int *)rf_bus_reset2_nf4_194c + 4) >= 0 )
    ;
  v2 = rf_bus_reset2_nf4_194c;
  *((_DWORD *)rf_bus_reset2_nf4_194c + 3) |= 0x40000007u;
  v1[3] = v1[3] & 0xFFFFC0FF | 0x2700;
  v1[4] |= 1u;
  while ( (v2[4] & 1) != 0 )
    ;
  v3 = rf_bus_reset2_nf4_194c;
  while ( *((int *)rf_bus_reset2_nf4_194c + 4) >= 0 )
    ;
  v4 = rf_bus_reset2_nf4_194c;
  *((_DWORD *)rf_bus_reset2_nf4_194c + 3) |= 0x40000007u;
  v3[3] = v3[3] & 0xFFFFC0FF | 0x2700;
  v3[512] &= 0xFFFFE7FC;
  v3[512] |= 0x800004u;
  v3[6] = 0;
  v5 = 1;
  v3[5] = -1;
  v3[519] = 0;
  v3[517] = 0;
  v3[516] = 0;
  while ( 1 )
  {
    v6 = &v4[8 * v5 - 16];
    if ( v5 != 1 )
      break;
    v4[706] = -1;
    v4[578] = -1;
LABEL_11:
    ++v5;
  }
  v6[714] = -1;
  v6[586] = -1;
  if ( v5 != 6 )
    goto LABEL_11;
  v4[6] = rf_bus_setup_n_408_1950;
  v7 = rf_bus_mark;
  v4[513] &= ~2u;
  v4[513] |= 0x8000u;
  v4[2] = 46;
  v4[2] |= 1u;
  return sub_12ECB0(v7, v4, 46);
}

