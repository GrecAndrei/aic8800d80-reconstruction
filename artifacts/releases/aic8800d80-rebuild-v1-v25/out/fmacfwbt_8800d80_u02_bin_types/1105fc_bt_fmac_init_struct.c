// bt_fmac_init_struct @ 0x1105fc, size 52 bytes
// Doc: bt_fmac_init_struct [bt]: Initialize FMAC/BT linked-list struct to zero
// bt_fmac_init_struct [bt]: Initialize FMAC/BT linked-list struct to zero
int  bt_fmac_init_struct(int a1)
{
  uint32_t *v1; // r2
  uint32_t *v2; // r1

  v1 = off_110630;
  v2 = off_110634;
  *(uint32_t *)off_110630 = 0;
  v1[1] = 0;
  v1[2] = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v2 = 0;
  v2[1] = 0;
  v2[4] = 0;
  v2[5] = 0;
  *((uint16_t *)v2 + 6) = 0;
  v2[2] = 0;
  *((uint8_t *)v2 + 14) = 0;
  *((uint16_t *)v2 + 14) = 0;
  v2[6] = 0;
  *((uint8_t *)v2 + 30) = 0;
  fmac_main_task((int)v1, (int)v2);
  return 1;
}

