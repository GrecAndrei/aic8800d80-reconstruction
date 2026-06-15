// v23 annotated: sub_111304 @ 0x111304
// Original: 111304_sub_111304.c
// Primary struct: <unclustered>
//
// sub_111304 @ 0x111304, size 242 bytes
// Doc: rf_bus_write2_176 [rf]: Write 2 words (0x2e, 0x2f) to RF register 0x14b408 via the RF MCU mailbox doorbell.
// rf_bus_write2_176 [rf]: Write 2 words (0x2e, 0x2f) to RF register 0x14b408 via the RF MCU mailbox doorbell.
int sub_111304()
{
  _DWORD *v0; // r2
  _DWORD *v1; // r2
  _DWORD *v2; // r1
  _DWORD *v3; // r2
  _DWORD *v4; // r1
  int v5; // r3
  _DWORD *v6; // r2
  int v7; // r0

  v0 = off_1113F8;
  *((_DWORD *)off_1113F8 + 4) |= 1u;
  while ( (v0[4] & 1) != 0 )
    ;
  v1 = off_1113F8;
  while ( *((int *)off_1113F8 + 4) >= 0 )
    ;
  v2 = off_1113F8;
  *((_DWORD *)off_1113F8 + 3) |= 0x40000007u;
  v1[3] = v1[3] & 0xFFFFC0FF | 0x2700;
  v1[4] |= 1u;
  while ( (v2[4] & 1) != 0 )
    ;
  v3 = off_1113F8;
  while ( *((int *)off_1113F8 + 4) >= 0 )
    ;
  v4 = off_1113F8;
  *((_DWORD *)off_1113F8 + 3) |= 0x40000007u;
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
  v4[6] = dword_1113FC;
  v7 = dword_111400;
  v4[513] &= ~2u;
  v4[513] |= 0x8000u;
  v4[2] = 46;
  v4[2] |= 1u;
  return sub_11F504(v7, v4);
}

