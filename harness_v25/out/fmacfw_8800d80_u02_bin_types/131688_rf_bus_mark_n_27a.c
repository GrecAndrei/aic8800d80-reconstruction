// rf_bus_mark_n_27a @ 0x131688, size 226 bytes
// Doc: rf_bus_mark_n_27a [rf]: Marks RF bus entry with byte/halfword writes and calls update routine
// rf_bus_mark_n_27a [rf]: Marks RF bus entry with byte/halfword writes and calls update routine
int  rf_bus_mark_n_27a(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v7; // r5
  int v8; // r4
  int v9; // r7
  int v10; // r4
  int v11; // r0
  int v12; // r1
  unsigned __int8 *v14; // r7
  int v15; // r0
  __int16 v16; // r1
  int v17; // r4
  int v18; // r1
  int v19; // r2

  if ( msg_get_value(5u) == 1 )
    return 2;
  v7 = sub_12C92C(5138, a4, a3, 0xCu);
  if ( **(__int16 **)off_13176C < 0 )
  {
    v14 = (unsigned __int8 *)off_131770;
    v8 = *((unsigned __int8 *)off_131770 + 16);
    if ( v8 == 255 )
    {
      sub_12F46C(dword_13177C, dword_131778, 1092);
      v8 = v14[16];
    }
  }
  else
  {
    v8 = *((unsigned __int8 *)off_131770 + 16);
  }
  if ( chip_info_is_fpga_or_emu() )
    mmio_bit_modify(*((unsigned __int8 *)a2 + 11));
  v9 = dword_131774 + 1320 * v8;
  v10 = *(uint32_t *)(v9 + 72);
  if ( v10 )
  {
    *(uint8_t *)v7 = *(uint8_t *)(v10 + 24);
    if ( *((uint8_t *)a2 + 10) )
    {
      if ( list_count((uint32_t **)dword_131780) == 1 )
      {
        v15 = sub_12C92C(59, 0, 5, 0xCu);
        *(uint8_t *)v15 = *(uint8_t *)(*(uint32_t *)(v9 + 72) + 24);
        v16 = *((uint16_t *)a2 + 4);
        v17 = a2[1];
        *(uint32_t *)(v15 + 2) = *a2;
        *(uint16_t *)(v15 + 10) = v16;
        *(uint32_t *)(v15 + 6) = v17;
        sdio_buffer_prepare_n_4e8(v15);
        v18 = *a2;
        v19 = a2[1];
        *(uint16_t *)(v7 + 10) = *((uint16_t *)a2 + 4);
        *(uint32_t *)(v7 + 2) = v18;
        *(uint32_t *)(v7 + 6) = v19;
        goto LABEL_9;
      }
      v10 = *(uint32_t *)(v9 + 72);
    }
    v11 = *(uint32_t *)(v10 + 4);
    v12 = *(uint32_t *)(v10 + 8);
    *(uint16_t *)(v7 + 10) = *(uint16_t *)(v10 + 12);
    *(uint32_t *)(v7 + 2) = v11;
    *(uint32_t *)(v7 + 6) = v12;
LABEL_9:
    sdio_buffer_prepare_n_4e8(v7);
    return 0;
  }
  *(uint8_t *)v7 = -1;
  sdio_buffer_prepare_n_4e8(v7);
  return 0;
}

