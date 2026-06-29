// rf_bus_setup_n3a8 @ 0x12cb54, size 82 bytes
// Doc: message_dispatch_n_1c [ipc]: Dispatches messages comparing slot 0x24
// message_dispatch_n_1c [ipc]: Dispatches messages comparing slot 0x24
int  rf_bus_setup_n3a8(__int16 a1, __int16 a2, __int16 a3, unsigned int a4)
{
  int v8; // r0
  int v9; // r4

  v8 = message_dispatch_n158(a4 + 12);
  v9 = v8;
  if ( **(__int16 **)off_12CBA8 < 0 && !v8 )
    sub_12F694(message_dispatch_n_4, message_dispatch_2, 145);
  *(uint16_t *)(v9 + 4) = a1;
  *(uint16_t *)(v9 + 6) = a2;
  *(uint16_t *)(v9 + 8) = a3;
  *(uint16_t *)(v9 + 10) = a4;
  *(uint32_t *)v9 = 0;
  memset_thunk((int *)(v9 + 12), 0, a4);
  return v9 + 12;
}

