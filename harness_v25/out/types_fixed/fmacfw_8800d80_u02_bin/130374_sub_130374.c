// sub_130374 @ 0x130374, size 38 bytes
int sub_130374()
{
  if ( *((_BYTE *)off_13039C + 1) )
    return *((char *)off_13039C + 3);
  rf_cmd_send_1();
  return (int)COERCE_FLOAT(rf_hw_timer_read());
}

