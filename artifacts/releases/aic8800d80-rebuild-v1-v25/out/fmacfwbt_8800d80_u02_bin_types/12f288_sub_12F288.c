// sub_12F288 @ 0x12f288, size 90 bytes
int sub_12F288()
{
  uint8_t *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = off_12F2E4;
  v1 = sub_12C964(1070, 1);
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    j_rf_hw_timer_init();
    rf_level_apply_80c(1070, 1, dword_12F2E8);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      sub_1306CC(v1);
      rf_level_apply_80c(1070, 1, 1000 * *((uint32_t *)off_12F2EC + 91));
      v0[1] = 1;
    }
    return 0;
  }
}

