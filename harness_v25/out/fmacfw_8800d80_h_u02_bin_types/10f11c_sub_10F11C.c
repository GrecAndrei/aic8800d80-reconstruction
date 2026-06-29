// sub_10F11C @ 0x10f11c, size 52 bytes
int sub_10F11C()
{
  uint8_t *v0; // r3
  int result; // r0
  int v2; // r1
  void *v3; // r2

  if ( *((uint8_t *)off_10F150 + 362) )
  {
    *(uint8_t *)off_10F154 = 0;
  }
  else
  {
    v0 = off_10F154;
    *(uint32_t *)off_10F154 = dword_10F158;
    v2 = dword_10F15C;
    v3 = off_10F160;
    v0[7] = -62;
    *((uint32_t *)v0 + 2) = 1000;
    *((uint16_t *)v0 + 2) = 1752;
    *((uint32_t *)v0 + 4) = v2;
    *((uint32_t *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}

