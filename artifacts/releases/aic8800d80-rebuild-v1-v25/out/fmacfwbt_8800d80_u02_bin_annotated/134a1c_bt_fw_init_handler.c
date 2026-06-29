// fwstruct annotate: 134a1c_bt_fw_init_handler.c
// bt_fw_init_handler @ 0x134a1c, size 256 bytes
// Doc: bt_fw_init_handler [bt]: Bluetooth firmware initialization entry; sets up stack and calls sub-routine
// bt_fw_init_handler [bt]: Bluetooth firmware initialization entry; sets up stack and calls sub-routine
int __fastcall bt_fw_init_handler(int a1)
{
  int v1; // lr
  int v3; // r7
  _BYTE *v4; // r6
  int v5; // r0
  unsigned int *v6; // r3
  _BYTE *v7; // r5
  int v8; // r0
  _BYTE *v9; // r0
  _BYTE *v10; // r0
  int v12; // r0

  v3 = v1;
  v4 = (_BYTE *)rf_bus_setup_n3a8(5145, 5, 6, 2u);
  v5 = rf_bus_setup_n3a8(5143, 5, 6, 2u);
  v6 = (unsigned int *)off_134B1C;
  v7 = (_BYTE *)v5;
  if ( (*(_DWORD *)off_134B1C & 0x4000000) != 0 )
  {
    *(_DWORD *)off_134B1C &= ~0x4000000u;
    *v6 = *v6 & 0xFF3FFFFF | 0x800000;
  }
  v8 = dword_134B28;
  *((_BYTE *)off_134B24 + 73) = *(_BYTE *)off_134B20;
  sub_12ECB0(v8, v3);
  sub_134608();
  sub_117974(a1);
  sub_13BEB0(*(unsigned __int8 *)(a1 + 116));
  *v4 = 0;
  v4[1] = *(_BYTE *)(a1 + 107);
  list_push_tail(dword_134B2C, (_DWORD *)v4 - 3);
  if ( *(_BYTE *)(a1 + 108) )
  {
    v12 = rf_bus_setup_n3a8(30, 0, 6, 4u);
    *(_BYTE *)(v12 + 2) = 0;
    *(_BYTE *)(v12 + 3) = *(_BYTE *)(a1 + 107);
    list_push_tail(dword_134B2C, (_DWORD *)(v12 - 12));
  }
  if ( *(unsigned __int8 *)(a1 + 116) != 255 )
  {
    v9 = (_BYTE *)rf_bus_setup_n3a8(12, 0, 6, 1u);
    *v9 = *(_BYTE *)(a1 + 116);
    list_push_tail(dword_134B2C, (_DWORD *)v9 - 3);
  }
  if ( *(_DWORD *)(a1 + 72) )
  {
    v10 = (_BYTE *)rf_bus_setup_n3a8(57, 0, 6, 1u);
    *v10 = *(_BYTE *)(a1 + 107);
    list_push_tail(dword_134B2C, (_DWORD *)v10 - 3);
  }
  *v7 = 0;
  v7[1] = *(_BYTE *)(a1 + 107);
  list_push_tail(dword_134B2C, (_DWORD *)v7 - 3);
  return sub_1349D8();
}

