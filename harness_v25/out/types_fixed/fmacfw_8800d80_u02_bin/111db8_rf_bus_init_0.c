// rf_bus_init_0 @ 0x111db8, size 262 bytes
// Doc: rf_bus_init_nfc [rf]: Initialize RF bus for NFC mode
// rf_bus_init_nfc [rf]: Initialize RF bus for NFC mode
int __fastcall rf_bus_init_0(_DWORD *a1, int a2)
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

  msg_parse(rf_bus_setup_n_3c_1ec0, 0, a2);
  if ( !a1 )
    return 1;
  if ( !*a1 || !*(_DWORD *)(a1 + 0x4) || !*(_DWORD *)(a1 + 0x8) || !*(_DWORD *)(a1 + 0x14) )
    return 2;
  v4 = rf_bus_reset2_n4c8;
  if ( *(_BYTE *)rf_bus_reset2_n4c8 )
    return 3;
  v5 = off_111EC8;
  v6 = rf_state_check_n_308;
  *(_BYTE *)rf_bus_reset2_n4c8 = 1;
  sub_143770(v6, a1, 80);
  v8 = *(_DWORD *)(v5 + 0x184);
  if ( v8 )
  {
    msg_parse(dword_111EF8, v8, v7);
    delay_us_0644(*(_DWORD *)(v5 + 0x184));
  }
  v9 = rf_bus_write2_n2b4;
  if ( (*((_DWORD *)rf_bus_write2_n2b4 + 512) & 0x7F0) != 0 )
  {
    v15 = rf_state_check_n_2ec_1ee8;
    *((_DWORD *)rf_state_check_n_2ec_1ee8 + 1) = 0;
    *((_DWORD *)v15 + 2) = 0;
    *v15 = 0;
    *v4 = 4;
    v16 = rf_bus_mark_n1();
    v17 = *(_DWORD *)rf_bus_write_n388_1eec;
    v18 = *(_DWORD **)rf_bus_write2_n2d4;
    *v18 = dword_111EF4;
    *(_DWORD *)(v18 + 0x4) = v17;
    *(_DWORD *)(v9 + 0xb14) = v18;
    *(_DWORD *)(v9 + 0xb08) = *(_DWORD *)(v9 + 0xb08);
    v11 = *((void (__fastcall **)(int))rf_state_check_n_308 + 19);
    v10 = 1;
    *(_DWORD *)(v9 + 0xb00) |= 0x84000000;
    *v15 = 1;
    if ( v11 )
      v11(v16);
  }
  else
  {
    if ( (*((_DWORD *)rf_bus_write2_n2b4 + 2) & 1) != 0 )
    {
      *((_DWORD *)rf_bus_write2_n2b4 + 2) &= ~1u;
      *(_DWORD *)(v9 + 0x804) |= 2u;
    }
    sub_1119FC();
  }
  msg_parse(dword_111ED4, v10, v11);
  v12 = dword_111EDC;
  v13 = off_111EE0;
  *(_DWORD *)(*((_DWORD *)off_111ED8 + 2) + 320) = dword_111EDC;
  *(_DWORD *)(v13 + 0x8) = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  msg_parse(rf_bus_setup_n_18_1ee4, v12, 1);
  return 0;
}

