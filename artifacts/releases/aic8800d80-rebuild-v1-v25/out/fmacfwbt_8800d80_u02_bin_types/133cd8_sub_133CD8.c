// sub_133CD8 @ 0x133cd8, size 266 bytes
// Doc: sub_1233CD8 [unknown]: Unknown helper in fmacfwbt image (reconstructed flow)
// sub_1233CD8 [unknown]: Unknown helper in fmacfwbt image (reconstructed flow)
int sub_133CD8()
{
  int v0; // r2
  unsigned int v1; // r3
  uint8_t *v2; // r3
  uint8_t *v4; // r4
  int v5; // r3
  int v6; // r1
  int v7; // [sp+0h] [bp-Ch] BYREF
  int v8; // [sp+4h] [bp-8h] BYREF

  if ( **(__int16 **)off_133DE4 < 0 && msg_get_value(6u) != 4 && msg_get_value(6u) != 10 )
    sub_12F694(dword_133DFC, dword_133DF8, 697);
  if ( msg_get_value(6u) == 10 )
  {
    v4 = off_133DE8;
    v5 = *((unsigned __int8 *)off_133DE8 + 4);
    *(uint32_t *)(*((uint32_t *)off_133DE8 + 2) + 472) = 0;
    if ( v5 )
    {
      message_dispatch_n84(6148, 13, 6);
      v4[4] = 0;
    }
    sub_12CBB4(*(uint32_t *)v4 + 12);
    v6 = (unsigned __int8)v4[33];
    *(uint32_t *)v4 = 0;
    if ( v6 )
    {
      v7 = 0;
      v8 = 0;
      sub_134690(&v7, &v8);
      sub_1347DC(v7, v8, 0);
    }
    else
    {
      rf_bus_mark_n_3b7(6u, 0);
    }
    return 0;
  }
  else
  {
    v0 = *((uint32_t *)off_133DE8 + 4);
    v1 = *(unsigned __int8 *)(v0 + 59);
    if ( v1 == 2 )
    {
      if ( (*(uint32_t *)(v0 + 48) & 0x40) != 0 )
      {
        fmacfwbt_init_handler();
        v2 = off_133DEC;
        if ( *((uint8_t *)off_133DEC + 13) )
        {
LABEL_6:
          if ( (v2[15] & 1) != 0 )
          {
            rf_level_apply_80c(6155, 6, dword_133DF0);
            mmio_reg_init_n0d08c();
          }
        }
        return 0;
      }
LABEL_5:
      sub_135384(1, 0);
      v2 = off_133DEC;
      if ( *((uint8_t *)off_133DEC + 13) )
        goto LABEL_6;
      return 0;
    }
    if ( v1 <= 2 )
      goto LABEL_5;
    if ( v1 == 3 )
    {
      sub_135A6C(dword_133DF4);
      if ( *((uint8_t *)off_133DEC + 13) )
        *((uint8_t *)off_133DEC + 15) |= 2u;
      return 0;
    }
    sub_135020(1);
    return 0;
  }
}

