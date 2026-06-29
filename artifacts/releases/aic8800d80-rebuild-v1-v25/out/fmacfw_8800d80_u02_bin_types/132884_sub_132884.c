// sub_132884 @ 0x132884, size 22 bytes
int  sub_132884(int a1)
{
  unsigned int v1; // r3
  int v2; // r0

  v1 = *(uint32_t *)(a1 + 220);
  v2 = HIBYTE(v1) & 0x3F;
  if ( (v1 & 0x40000000) != 0 )
    return v2 | 0x300;
  else
    return v2 | 0x100;
}

