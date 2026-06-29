// sub_13B82C @ 0x13b82c, size 146 bytes
uint32_t *sub_13B82C()
{
  uint32_t *v0; // r9
  int v1; // r5
  int v2; // r8
  unsigned int i; // r4
  uint32_t *result; // r0

  v0 = (uint32_t *)dword_13B8C0;
  sub_12D100((uint32_t *)dword_13B8C0);
  sub_12D100(v0 + 2);
  sub_12D100(v0 + 4);
  sub_12D100(v0 + 6);
  sub_12D100(v0 + 8);
  sub_12D100(v0 + 10);
  v1 = dword_13B8C4;
  v2 = dword_13B8C8;
  for ( i = 0; ; ++i )
  {
    *(uint8_t *)(v1 + 16) = -1;
    *(uint8_t *)(v1 + 26) = i;
    if ( i > 0xF )
      break;
    sub_12D108((int)v0, (uint32_t *)v1);
    sub_12CBF4((i << 8) & 0xFF00 | 8, 0);
LABEL_3:
    v1 += 32;
  }
  *(uint32_t *)(v1 + 28) = v2 + 268 * i;
  sub_12D108((int)(v0 + 6), (uint32_t *)v1);
  result = sub_12CBF4((i << 8) & 0xFF00 | 8, 0);
  if ( i != 31 )
    goto LABEL_3;
  return result;
}

