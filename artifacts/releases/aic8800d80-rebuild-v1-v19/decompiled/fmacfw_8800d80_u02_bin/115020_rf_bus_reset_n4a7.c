// rf_bus_reset_n4a7 @ 0x115020, size 230 bytes
// Doc: patch_apply_n1a2 [patch]: Apply patch writing MMIO reg at +0x104 and toggling bits
// patch_apply_n1a2 [patch]: Apply patch writing MMIO reg at +0x104 and toggling bits
int rf_bus_reset_n4a7()
{
  int v0; // r4
  _DWORD *v1; // r3
  _DWORD *v2; // r2
  _DWORD *v3; // r3
  _DWORD *v4; // r3
  int v6; // r1
  int v7; // r1
  _DWORD *v8; // r2

  if ( **(_BYTE **)rf_cmd_send_n238_5108 == 2 )
  {
    if ( rf_cmd_send_n_374() )
      v0 = *((_DWORD *)patch_apply_n27c + 87);
    else
      v0 = 16;
    sub_1129E8();
    *((_DWORD *)off_115114 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    msg_parse(patch_apply_n270, v6, 1);
    v8 = off_115120;
    *((_DWORD *)off_115120 + 513) |= 2u;
    v8[4] |= 1u;
    while ( (v8[4] & 1) != 0 )
      ;
    msg_parse(patch_apply_n278, v7, v8);
  }
  else
  {
    v0 = 16;
  }
  v1 = patch_apply_n260;
  if ( (*((_DWORD *)patch_apply_n260 + 74) & 0x80) != 0 )
  {
    v2 = patch_apply_n264;
    *((_DWORD *)patch_apply_n260 + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = patch_apply_n264;
  if ( (*((_DWORD *)patch_apply_n264 + 2) & 0x20000) != 0 )
  {
    *((_DWORD *)patch_apply_n260 + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = off_115114;
  *((_DWORD *)off_115114 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  v4[34] = 1;
  __dsb(0xFu);
  __isb(0xFu);
  sub_10D784();
  if ( *(_BYTE *)(*(_DWORD *)off_115118 + 3) )
    rf_msg_handler();
  __disable_irq();
  return v0;
}

