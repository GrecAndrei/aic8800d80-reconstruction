// sub_100E24 @ 0x100e24, size 174 bytes
int  sub_100E24(int result)
{
  unsigned int *v1; // r3
  uint32_t *v2; // r1
  unsigned int v3; // r5
  uint32_t *v4; // r4
  uint32_t *v5; // r3

  v1 = (unsigned int *)off_100ED8;
  v2 = off_100EDC;
  v3 = *(uint32_t *)off_100ED8;
  v4 = off_100EE0;
  *(uint32_t *)off_100EDC = (*(unsigned __int8 *)off_100ED4 << 10) & 0x1FC00 | *(uint32_t *)off_100EDC & 0xFFFE03FF;
  *v1 |= 0x18u;
  *v1 = *v1 & 0xFFFFFFF8 | 3;
  *v2 |= 0x80000u;
  *v2 |= 0x40000u;
  *v1 = *v1 & 0xFFFFFC1F | 0xE0;
  *v4 &= ~2u;
  *v4 |= 1u;
  if ( !result && ((v3 >> 5) & 0x1F) != 7 )
  {
    v5 = off_100EE4;
    *(uint32_t *)off_100EE4 |= 0x80u;
    *v5 &= ~0x40u;
    *v5 |= 0x40u;
    *v5 &= ~0x80u;
  }
  return result;
}

