// v23 annotated: bt_msg_handler_n54c @ 0x13a54c
// Original: 13a54c_bt_msg_handler_n54c.c
// Primary struct: rf_param_tbl (cluster 14, 4 funcs)
// Fields: field1=0x26, field2=0x2c, field3=0x4c
//
// bt_msg_handler_n54c @ 0x13a54c, size 36 bytes
// Doc: bt_msg_handler_n54c [bt]: Handles incoming Bluetooth message
// bt_msg_handler_n54c [bt]: Handles incoming Bluetooth message
_WORD *__fastcall bt_msg_handler_n54c(_WORD *result)
{
  _WORD *v1; // r3

  v1 = off_13A570;
  if ( !*((_BYTE *)off_13A570 + 115) )
  {
    *((_WORD *)off_13A570 + 54) = *result;
    v1[55] = result[1];
    v1[56] = result[2];
    v1[57] = 256;
  }
  return result;
}

