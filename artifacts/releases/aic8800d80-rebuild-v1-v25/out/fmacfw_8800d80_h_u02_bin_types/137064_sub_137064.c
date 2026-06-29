// sub_137064 @ 0x137064, size 48 bytes
int sub_137064()
{
  uint8_t *v0; // r2
  char v1; // r3
  unsigned int v2; // r1

  v0 = off_137094;
  v1 = *((uint8_t *)off_137094 + 3851);
  if ( !v1 )
  {
    v2 = *((unsigned __int16 *)off_137094 + 2);
    if ( v2 >= 7 )
      v2 = 7;
    *(uint32_t *)off_137098 = *(uint32_t *)off_137098 & 0xFFFFFE3F | (v2 << 6);
  }
  v0[3851] = v1 + 1;
  sub_13819C();
  return 0;
}

