// rf_msg_handler_n41e @ 0x12efac, size 42 bytes
// Doc: rf_msg_handler_n41e [rf]: RF message handler initializing with status code 0x9e
// rf_msg_handler_n41e [rf]: RF message handler initializing with status code 0x9e
int  rf_msg_handler_n41e(int a1, uint32_t *a2, __int16 a3, __int16 a4)
{
  msg_parse(dword_12EFD8, *a2);
  *(uint32_t *)off_12EFDC = *a2;
  sub_12CA10(1029, a4, a3);
  return 0;
}

