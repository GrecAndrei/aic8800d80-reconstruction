// sdio_buffer_prepare_n_2fa @ 0x12391c, size 142 bytes
// Doc: sdio_buffer_prepare_n_2fa [util]: Prepare SDIO buffer for transfer
// sdio_buffer_prepare_n_2fa [util]: Prepare SDIO buffer for transfer
int __fastcall sdio_buffer_prepare_n_2fa(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  int v7; // r1
  BOOL v9; // r0
  int v10; // r2
  char v11; // r6
  _BYTE *v12; // r0
  BOOL n1c0; // r0
  int v15; // r3
  int v16; // r1

  v5 = *a2;
  v6 = a2[1];
  v7 = a2[2];
  if ( v5 )
  {
    n1c0 = rf_channel_status_get_n1c0(v6, v7);
    v10 = a3;
    if ( n1c0 )
    {
      rf_param_lookup_n_1fc(dword_1239AC + 696 * a2[1], a2[2], a3);
      v11 = 2;
      v10 = a3;
      goto LABEL_4;
    }
  }
  else
  {
    v9 = bt_indexed_tbl_lookup_n_21b(v6, v7);
    v10 = a3;
    if ( v9 )
    {
      v15 = 696 * a2[1];
      v16 = dword_1239B0 + 32 * *(unsigned __int8 *)(v15 + 12 * a2[2] + dword_1239AC + 453);
      *(_WORD *)(v15 + 6 * a2[2] + dword_1239AC + 354) = 0;
      *(_WORD *)(v16 + 12) = 0;
      v11 = 2;
      goto LABEL_4;
    }
  }
  v11 = 3;
LABEL_4:
  v12 = (_BYTE *)rf_bus_setup_n3a8(43, a4, v10, 3);
  *v12 = a2[1];
  v12[1] = a2[2];
  v12[2] = v11;
  sub_12CBB4(v12);
  return 0;
}

