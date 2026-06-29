// sub_11F5B0 @ 0x11f5b0, size 44 bytes
void sub_11F5B0()
{
  uint8_t *v0; // r3
  unsigned int v1; // r2

  v0 = *((uint8_t **)off_11F5DC + 2);
  if ( !v0[106] && v0[108] && v0[117] )
  {
    v1 = (unsigned __int8)v0[118];
    if ( v1 <= 8 )
      *(uint32_t *)off_11F5E0 = ((1 << v1) - 1) << 8;
  }
}

