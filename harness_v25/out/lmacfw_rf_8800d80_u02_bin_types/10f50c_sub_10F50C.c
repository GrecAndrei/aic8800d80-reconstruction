// sub_10F50C @ 0x10f50c, size 52 bytes
int sub_10F50C()
{
  uint8_t *v0; // r3
  int result; // r0
  void *v2; // r1
  int v3; // r2

  if ( *((uint8_t *)off_10F540 + 362) )
  {
    *(uint8_t *)off_10F544 = 0;
  }
  else
  {
    v0 = off_10F544;
    *(uint32_t *)off_10F544 = dword_10F548;
    v2 = off_10F54C;
    v3 = dword_10F550;
    v0[7] = -62;
    *((uint32_t *)v0 + 2) = 1000;
    *((uint16_t *)v0 + 2) = 1752;
    *((uint32_t *)v0 + 4) = v2;
    *((uint32_t *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}

