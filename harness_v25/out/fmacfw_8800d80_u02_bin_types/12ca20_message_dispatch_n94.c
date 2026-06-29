// message_dispatch_n94 @ 0x12ca20, size 22 bytes
// Doc: message_dispatch_na8 [ipc]: Dispatch incoming message using conditional IT/ITETE
// message_dispatch_na8 [ipc]: Dispatch incoming message using conditional IT/ITETE
int  message_dispatch_n94(int a1, __int16 a2, __int16 a3, __int16 a4)
{
  *(uint16_t *)(a1 - 8) = a2;
  *(uint16_t *)(a1 - 6) = a3;
  *(uint16_t *)(a1 - 4) = a4;
  return sdio_buffer_prepare_n_4e8(a1);
}

