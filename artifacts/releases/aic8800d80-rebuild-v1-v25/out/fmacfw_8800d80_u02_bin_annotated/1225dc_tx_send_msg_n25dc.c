// fwstruct annotate: 1225dc_tx_send_msg_n25dc.c
// tx_send_msg_n25dc @ 0x1225dc, size 30 bytes
// Doc: tx_send_msg_n25dc [tx]: Send TX/datapath message (id 0x59, param 0xd) via IPC
// tx_send_msg_n25dc [tx]: Send TX/datapath message (id 0x59, param 0xd) via IPC
int __fastcall tx_send_msg_n25dc(char a1, char a2)
{
  _BYTE *v4; // r0

  v4 = (_BYTE *)sub_12C92C(89, 13, 0, 2);
  *v4 = a1;
  v4[1] = a2;
  return sdio_buffer_prepare_n_4e8(v4);
}

