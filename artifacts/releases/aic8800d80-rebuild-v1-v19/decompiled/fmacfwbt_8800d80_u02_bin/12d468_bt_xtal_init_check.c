// bt_xtal_init_check @ 0x12d468, size 8 bytes
// Doc: bt_xtal_init_check [bt]: Initialize structure to zero then check XTAL status flag
// bt_xtal_init_check [bt]: Initialize structure to zero then check XTAL status flag
_DWORD *__fastcall bt_xtal_init_check(_DWORD *result)
{
  *result = 0;
  result[1] = 0;
  return result;
}

