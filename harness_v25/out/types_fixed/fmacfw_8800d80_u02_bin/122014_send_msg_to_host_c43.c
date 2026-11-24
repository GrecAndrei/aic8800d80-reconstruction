// send_msg_to_host_c43 @ 0x122014, size 30 bytes
// Doc: send_msg_to_host_c43 [ipc]: Send message id 0x43 to host with arg 6 and flag=1
// send_msg_to_host_c43 [ipc]: Send message id 0x43 to host with arg 6 and flag=1
int __fastcall send_msg_to_host_c43(int a1)
{
  _BYTE *v2; // r0

  v2 = (_BYTE *)sub_12C92C(67, 6, 0, 1);
  *v2 = *(_BYTE *)(a1 + 107);
  return sdio_buffer_prepare_n_4e8(v2);
}

