// sub_12F46C @ 0x12f46c, size 36 bytes
int  sub_12F46C(int a1, int a2, int a3)
{
  int v4; // r0
  int result; // r0

  __disable_irq();
  v4 = dword_12F494;
  *(uint32_t *)off_12F490 = 0;
  result = msg_parse(v4, a1, a2, a3 & 0xFFFFF);
  while ( *(uint32_t *)off_12F498 )
    ;
  return result;
}

