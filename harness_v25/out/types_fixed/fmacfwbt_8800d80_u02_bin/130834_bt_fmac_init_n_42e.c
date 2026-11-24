// bt_fmac_init_n_42e @ 0x130834, size 36 bytes
// Doc: bt_fmac_init_n_42e [bt]: Triggers BT-related FMAC initialization for opcode 0x42e
// bt_fmac_init_n_42e [bt]: Triggers BT-related FMAC initialization for opcode 0x42e
int bt_fmac_init_n_42e()
{
  int result; // r0

  *((_BYTE *)off_130858 + 1) = 0;
  result = message_dispatch_n_d8(1070, 1);
  if ( result )
    return sub_12C964(1070, 1);
  return result;
}

