// rf_cmd_send_n4d0 @ 0x1239c4, size 192 bytes
// Doc: rf_cmd_send_n4d0 [rf]: Sends an RF command, sets ready flag and patches command byte bits
// rf_cmd_send_n4d0 [rf]: Sends an RF command, sets ready flag and patches command byte bits
int  rf_cmd_send_n4d0(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  uint32_t *v5; // r5
  uint32_t *v6; // r3
  int v7; // r4
  BOOL is_fpga_or_emu; // r0
  int v9; // r3

  v4 = sub_12C92C(5, a4, a3, 28);
  v5 = off_123A84;
  *(uint32_t *)v4 = dword_123A88;
  v6 = off_123A8C;
  *(uint32_t *)(v4 + 4) = *v5;
  *(uint32_t *)(v4 + 8) = *v6;
  *(uint8_t *)(v4 + 26) = 4;
  *(uint16_t *)(v4 + 24) = 32;
  v7 = v4;
  sub_101984((uint32_t *)(v4 + 12), (uint32_t *)(v4 + 16));
  *(uint32_t *)(v7 + 20) = dword_123A90;
  if ( (*v5 & 0x20000) != 0 && sub_101A48() )
  {
    *(uint32_t *)(v7 + 20) |= 0x400u;
    if ( (*(uint32_t *)off_123A84 & 0x20000) == 0 )
      goto LABEL_3;
  }
  else if ( (*(uint32_t *)off_123A84 & 0x20000) == 0 )
  {
    goto LABEL_3;
  }
  if ( sub_101A58() )
    *(uint32_t *)(v7 + 20) |= 0x4000u;
LABEL_3:
  if ( (*(uint32_t *)off_123A84 & 0x2000) != 0 )
    *(uint32_t *)(v7 + 20) |= 0x1000u;
  if ( sub_1019F8() )
    *(uint32_t *)(v7 + 20) |= 0x200u;
  if ( (*(uint32_t *)off_123A84 & 0x8000) != 0 && sub_1019FC() )
    *(uint32_t *)(v7 + 20) |= 0x800000u;
  is_fpga_or_emu = chip_info_is_fpga_or_emu();
  v9 = *(uint32_t *)(v7 + 20);
  if ( is_fpga_or_emu )
    v9 |= 0x80000u;
  *(uint32_t *)(v7 + 20) = v9 | 0x600000;
  sdio_buffer_prepare_n_4e8(v7);
  return 0;
}

