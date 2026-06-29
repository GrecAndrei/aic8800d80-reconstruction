// fwstruct annotate: 11d0b8_mmio_init_40328050.c
// mmio_init_40328050 @ 0x11d0b8, size 502 bytes
// Doc: mmio_init_40328050 [mmio]: Initialize MMIO register block at 0x40328050 with value 1
// mmio_init_40328050 [mmio]: Initialize MMIO register block at 0x40328050 with value 1
int mmio_init_40328050()
{
  _DWORD *v0; // r2
  unsigned int v1; // r0
  _DWORD *v2; // r3
  _DWORD *v3; // r2
  __int16 **v4; // r1
  char *v5; // r0
  int *v6; // r3
  _DWORD *v7; // r1
  int v8; // r2
  int *v9; // r4
  int v10; // r5
  _BYTE *v11; // r1
  int *v12; // r3
  _DWORD *v13; // r3
  _DWORD *v14; // r4
  unsigned int *v15; // r6
  _DWORD *v16; // r2
  _DWORD *v17; // r5
  int result; // r0
  _DWORD *v19; // r1
  _BYTE **v20; // r2
  _DWORD *v21; // r4
  _DWORD *v22; // r6
  int v23; // r0
  unsigned int *v24; // r5
  unsigned __int8 v25; // [sp+6h] [bp-2h] BYREF
  unsigned __int8 v26; // [sp+7h] [bp-1h] BYREF

  v0 = off_11D2B0;
  *(_DWORD *)off_11D2B0 = 1;
  while ( (unsigned __int8)*v0 )
    ;
  v1 = sub_1005E8();
  sub_11CDB8(v1);
  v2 = off_11D2B8;
  *(_DWORD *)off_11D2B4 = dword_11D2BC;
  v3 = off_11D2C0;
  *v2 = 0x80000000;
  v4 = (__int16 **)off_11D2C4;
  *v3 &= ~0x800u;
  if ( **v4 < 0 && *(_DWORD *)off_11D2C8 < 0x13000000u )
    rf_cmd_send_n264(dword_11D314, dword_11D310, 284);
  v5 = (char *)off_11D2C8;
  v6 = (int *)off_11D2CC;
  v7 = off_11D2C0;
  v8 = dword_11D2D4;
  *(_DWORD *)off_11D2C8 = dword_11D2D0;
  *v6 = v8;
  v9 = (int *)off_11D2D8;
  v10 = dword_11D2DC;
  *v7 |= 0x40007C0u;
  *v7 &= ~0x4000000u;
  v11 = off_11D2E0;
  v12 = v6 - 8199;
  *(_DWORD *)&v5[-132] |= 0x10000u;
  *v9 = v10;
  *v12 |= 0xFF000000;
  *v12 |= 0x800000u;
  *v12 = *v12 & 0xFF80FFFF | 0x100000;
  if ( !v11[2] )
    *v12 = (HIWORD(*v12) << 16) | 0x64;
  v13 = off_11D2E4;
  v14 = off_11D2C0;
  v15 = (unsigned int *)off_11D2EC;
  *(_DWORD *)off_11D2E8 = 12288;
  *v13 = 0;
  sub_1029A8(&v26, &v25);
  v16 = off_11D2F4;
  *(_DWORD *)off_11D2F0 = (v26 << 8) | (v25 << 16) | v26;
  v17 = off_11D2F8;
  *v14 |= 0x1000u;
  *v14 |= 0x2000u;
  *v16 |= 0x80000u;
  *v16 &= ~0x80u;
  result = lmac_rf_unk_1a9c();
  v19 = off_11D2FC;
  *v15 = ((result + 1) << 26) & 0x1C000000 | *v15 & 0xE3FFFFFF;
  v20 = (_BYTE **)off_11D300;
  *v14 |= 0x20u;
  *v17 &= ~1u;
  *v19 |= 2u;
  if ( **v20 == 1 )
    *(_DWORD *)off_11D304 &= 0x80FFFFFF;
  v21 = off_11D2C0;
  v22 = off_11D308;
  *(_DWORD *)off_11D2C0 |= 0x2000000u;
  if ( (*v22 & 0x20000) != 0 )
  {
    result = phy_get_link_status();
    if ( result )
    {
      v23 = chip_revision_get();
      v24 = (unsigned int *)off_11D318;
      result = v23 << 8;
      *(_DWORD *)off_11D318 = result & 0x700 | *(_DWORD *)off_11D318 & 0xFFFFF8FF;
      *v24 = *v24 & 0xFFFFFF1F | 0x60;
      *v24 |= 4u;
      *v24 |= 1u;
      if ( (*v22 & 0x8000) != 0 )
      {
        result = sub_101A2C();
        if ( result )
        {
          *v21 |= 0x80000u;
          *v24 = *v24 & 0xF1FFFFFF | 0x4000000;
        }
      }
      if ( (*(_DWORD *)off_11D308 & 0x20000) != 0 )
      {
        result = mmio_get_bit_30();
        if ( result )
          *(_DWORD *)off_11D318 |= 2u;
      }
    }
  }
  *(_DWORD *)off_11D30C |= 1u;
  return result;
}

