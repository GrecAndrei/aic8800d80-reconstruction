// sub_12B2A4 @ 0x12b2a4, size 124 bytes
// Doc: sub_122B2A4 [ipc]: Sends command 0x801 to IPC handler and stores result
// sub_122B2A4 [ipc]: Sends command 0x801 to IPC handler and stores result
int  sub_12B2A4(int a1, int a2, int a3, int a4)
{
  __int16 v4; // r6
  uint8_t *v6; // r4
  uint8_t *v7; // r2

  v4 = a4;
  v6 = (uint8_t *)rf_bus_setup_n3a8(2049, a4, a3, 1);
  msg_get_value(2);
  feature_guard_sdio(4, dword_12B324);
  if ( msg_get_value(2) )
  {
    *v6 = 8;
    sub_12CBB4(v6);
    return 0;
  }
  else
  {
    if ( **(__int16 **)off_12B328 < 0 && !*(uint8_t *)(a2 + 367) )
      sub_12F694(dword_12B334, dword_12B330, 73);
    v7 = off_12B32C;
    *v6 = 0;
    *(uint32_t *)v7 = a2;
    v7[10] = 0;
    *((uint16_t *)v7 + 4) = v4;
    sub_12B49C(a2);
    sub_12CBB4(v6);
    return 1;
  }
}

