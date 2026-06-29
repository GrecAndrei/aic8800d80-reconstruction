// sub_1143D0 @ 0x1143d0, size 40 bytes
int  sub_1143D0(int a1, int a2, int a3)
{
  int result; // r0
  uint8_t *v4; // r3
  uint32_t *v5; // r1

  result = sub_12ECB0(dword_1143F8, a2, a3);
  v4 = off_1143FC;
  if ( *((uint8_t *)off_1143FC + 3) )
  {
    v5 = off_114404;
    *(uint32_t *)off_114400 &= ~8u;
    *v5 &= 0xFFFFFFF0;
    v4[3] = 0;
    return 0;
  }
  return result;
}

