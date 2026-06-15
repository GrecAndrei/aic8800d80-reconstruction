// v23 annotated: mmio_init_block_clear @ 0x111c14
// Original: 111c14_mmio_init_block_clear.c
// Primary struct: <unclustered>
//
// mmio_init_block_clear @ 0x111c14, size 262 bytes
// Doc: rf_bus_write_n288 [rf]: Write a value to the RF control bus register
// rf_bus_write_n288 [rf]: Write a value to the RF control bus register
int __fastcall mmio_init_block_clear(_DWORD *a1, int a2)
{
  _BYTE *v4; // r6
  _DWORD *v5; // r7
  void *v6; // r0
  int v7; // r2
  int v8; // r1
  _DWORD *v9; // r4
  int v10; // r1
  void (__fastcall *v11)(int); // r2
  int v12; // r1
  _DWORD *v13; // r3
  _BYTE *v15; // r7
  int v16; // r0
  int v17; // r1
  _DWORD *v18; // r3

  sub_12ECB0(log_free_dispatch_d1c, 0, a2);
  if ( !a1 )
    return 1;
  if ( !*a1 || !a1[1] || !a1[2] || !a1[5] )
    return 2;
  v4 = rf_state_check_n_310;
  if ( *(_BYTE *)rf_state_check_n_310 )
    return 3;
  v5 = rf_bus_write2_n2ac;
  v6 = off_111D28;
  *(_BYTE *)rf_state_check_n_310 = 1;
  sub_14380C(v6, a1, 80);
  v8 = v5[97];
  if ( v8 )
  {
    sub_12ECB0(rf_state_check_n_2dc, v8, v7);
    delay_us(v5[97]);
  }
  v9 = off_111D2C;
  if ( (*((_DWORD *)off_111D2C + 512) & 0x7F0) != 0 )
  {
    v15 = rf_state_check_n_2ec;
    *((_DWORD *)rf_state_check_n_2ec + 1) = 0;
    *((_DWORD *)v15 + 2) = 0;
    *v15 = 0;
    *v4 = 4;
    v16 = rf_bus_reset2_n_177();
    v17 = *(_DWORD *)rf_bus_write_n388;
    v18 = *(_DWORD **)off_111D4C;
    *v18 = rf_bus_setup_n_8;
    v18[1] = v17;
    v9[709] = v18;
    v9[706] = v9[706];
    v11 = *((void (__fastcall **)(int))off_111D28 + 19);
    v10 = 1;
    v9[704] |= 0x84000000;
    *v15 = 1;
    if ( v11 )
      v11(v16);
  }
  else
  {
    if ( (*((_DWORD *)off_111D2C + 2) & 1) != 0 )
    {
      *((_DWORD *)off_111D2C + 2) &= ~1u;
      v9[513] |= 2u;
    }
    sub_111858();
  }
  sub_12ECB0(rf_bus_write2_n2b8, v10, v11);
  v12 = rf_bus_write2_n2c0;
  v13 = message_dispatch_d3c;
  *(_DWORD *)(*((_DWORD *)off_111D34 + 2) + 320) = rf_bus_write2_n2c0;
  v13[2] = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  sub_12ECB0(rf_bus_setup_n_18, v12, 1);
  return 0;
}

