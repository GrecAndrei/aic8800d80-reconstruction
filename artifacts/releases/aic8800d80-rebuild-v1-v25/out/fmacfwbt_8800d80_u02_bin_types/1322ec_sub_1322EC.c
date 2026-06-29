// sub_1322EC @ 0x1322ec, size 96 bytes
int  sub_1322EC(int a1, char *a2, __int16 a3, __int16 a4)
{
  uint16_t *v7; // r4
  char v8; // r3
  int v9; // r1
  uint8_t *v10; // r0
  int v11; // r3

  if ( msg_get_value(5u) == 1 )
    return 2;
  v7 = off_13234C;
  v8 = *a2;
  v9 = *((uint32_t *)off_13234C + 1);
  if ( *a2 )
    v8 = 1;
  *((uint8_t *)off_13234C + 375) = v8;
  if ( !v9 )
  {
    v10 = (uint8_t *)rf_bus_setup_n3a8(49, 0, 5, 1u);
    v11 = *((unsigned __int8 *)v7 + 375);
    v7[4] = 255;
    if ( v11 )
      LOBYTE(v11) = *((uint8_t *)v7 + 376);
    *v10 = v11;
    sub_12CBB4((int)v10);
    rf_bus_mark_n_3b7(5u, 1);
  }
  message_dispatch_n84(5140, a4, a3);
  return 0;
}

