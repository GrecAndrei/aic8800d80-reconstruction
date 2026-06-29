// sub_10189C @ 0x10189c, size 20 bytes
unsigned int  sub_10189C(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(uint32_t *)off_1018B0 & 0xFFFFFFF7;
  *(uint32_t *)off_1018B0 = result;
  return result;
}

