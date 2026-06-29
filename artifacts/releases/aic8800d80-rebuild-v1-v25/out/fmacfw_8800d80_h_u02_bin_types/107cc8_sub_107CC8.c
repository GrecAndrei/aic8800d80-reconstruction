// sub_107CC8 @ 0x107cc8, size 92 bytes
int sub_107CC8()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r3
  int result; // r0
  uint32_t *v3; // r2
  int v4; // r3

  v0 = off_107D24;
  sub_1073D8();
  *v0 &= ~1u;
  sub_100644(1);
  v1 = off_107D28;
  *(uint32_t *)off_107D28 &= 0xCFFFFFFF;
  *v1 |= 0x40000000u;
  result = sub_100644(1);
  v3 = off_107D2C;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (unsigned __int16)(v4 - 1);
    while ( v4 );
  }
  *(uint32_t *)off_107D24 &= ~1u;
  return result;
}

