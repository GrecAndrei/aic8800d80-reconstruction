// sub_117DC0 @ 0x117dc0, size 44 bytes
void sub_117DC0()
{
  uint8_t *v0; // r3
  unsigned int v1; // r2

  v0 = *((uint8_t **)off_117DEC + 2);
  if ( !v0[94] && v0[96] && v0[103] )
  {
    v1 = (unsigned __int8)v0[104];
    if ( v1 <= 8 )
      *(uint32_t *)off_117DF0 = ((1 << v1) - 1) << 8;
  }
}

