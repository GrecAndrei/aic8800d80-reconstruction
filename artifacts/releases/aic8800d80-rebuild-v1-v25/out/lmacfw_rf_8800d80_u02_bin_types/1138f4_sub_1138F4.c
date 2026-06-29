// sub_1138F4 @ 0x1138f4, size 68 bytes
int sub_1138F4()
{
  int v0; // r2
  int v1; // r1
  uint32_t *v2; // r3

  if ( *(uint32_t *)off_11393C )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(uint32_t *)off_11393C )
    v1 = 1;
  else
    v1 = 2;
  if ( *(uint8_t *)(*(uint32_t *)off_113938 + 6) == 1 )
    *((uint32_t *)off_113940 + 83) &= ~v1;
  v2 = off_113948;
  *(uint32_t *)(*(uint32_t *)off_113944 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}

