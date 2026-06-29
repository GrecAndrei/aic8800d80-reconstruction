// sub_12B400 @ 0x12b400, size 72 bytes
int sub_12B400()
{
  uint32_t *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(__int16 **)off_12B448 < 0 && *(uint32_t *)off_12B454 << 28 )
    return sub_12F2C8(dword_12B45C, dword_12B458, 105, *(uint32_t *)off_12B454);
  if ( (*(uint32_t *)off_12B44C & 0x80) != 0 )
  {
    v0 = off_12B450;
    v1 = *((uint32_t *)off_12B450 + 1) & 0xFFFFFFFB;
    *(uint32_t *)off_12B44C &= ~0x80u;
    v0[1] = v1;
    return sub_12CFC4(0x2000000);
  }
  return result;
}

