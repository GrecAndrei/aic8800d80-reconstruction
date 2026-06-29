// fwstruct annotate: 12ca10_sub_12CA10.c
// sub_12CA10 @ 0x12ca10, size 16 bytes
// Doc: message_dispatch_n86 [ipc]: Dispatch message with two short fields stored to message header
// message_dispatch_n86 [ipc]: Dispatch message with two short fields stored to message header
int __fastcall sub_12CA10(__int16 a1, __int16 a2, __int16 a3)
{
  int v3; // r0

  v3 = sub_12C92C(a1, a2, a3, 0);
  return sdio_buffer_prepare_n_4e8(v3);
}

