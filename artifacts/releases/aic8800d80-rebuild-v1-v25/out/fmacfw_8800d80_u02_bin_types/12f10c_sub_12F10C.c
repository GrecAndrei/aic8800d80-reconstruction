// sub_12F10C @ 0x12f10c, size 116 bytes
int  sub_12F10C(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  int v6; // r3
  uint32_t *v7; // r4
  int v9; // r5

  v5 = sub_12C92C(1038, a4, a3, 4u);
  v6 = a2[1];
  v7 = (uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      msg_parse(loc_12F18C, *(uint32_t *)(*a2 + 4));
      break;
    case 2:
      msg_parse(loc_12F190, *a2);
      break;
    case 3:
      v9 = *a2;
      msg_parse(loc_12F188, v9);
      if ( !v9 )
        sub_12F0C8();
      timer_set_relative(1068, 1, v9 << 10);
      break;
    default:
      msg_parse(sub_12F180);
      break;
  }
  *v7 = (unsigned __int8)sub_114840();
  msg_parse(loc_12F184);
  sdio_buffer_prepare_n_4e8((int)v7);
  return 0;
}

