// sub_114574 @ 0x114574, size 40 bytes
int  sub_114574(int a1, int a2, int a3)
{
  int result; // r0
  uint8_t *v4; // r3
  uint32_t *v5; // r1

  result = sub_12EA88(dword_11459C, a2, a3);
  v4 = off_1145A0;
  if ( *((uint8_t *)off_1145A0 + 3) )
  {
    v5 = off_1145A8;
    *(uint32_t *)off_1145A4 &= ~8u;
    *v5 &= 0xFFFFFFF0;
    v4[3] = 0;
    return 0;
  }
  return result;
}

