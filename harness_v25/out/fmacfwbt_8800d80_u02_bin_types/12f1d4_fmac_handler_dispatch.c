// fmac_handler_dispatch @ 0x12f1d4, size 42 bytes
// Doc: fmac_handler_dispatch [ipc]: Dispatch into fmac handler with arg save, resolves handler via table
// fmac_handler_dispatch [ipc]: Dispatch into fmac handler with arg save, resolves handler via table
int  fmac_handler_dispatch(int a1, uint32_t *a2, __int16 a3, __int16 a4)
{
  sub_12ECB0(dword_12F200, *a2);
  *(uint32_t *)off_12F204 = *a2;
  message_dispatch_n84(1029, a4, a3);
  return 0;
}

