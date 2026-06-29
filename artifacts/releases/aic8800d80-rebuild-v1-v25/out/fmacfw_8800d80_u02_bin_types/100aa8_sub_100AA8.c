// sub_100AA8 @ 0x100aa8, size 90 bytes
int sub_100AA8()
{
  uint32_t *v0; // r2
  int *v1; // r3
  int v2; // r4
  int result; // r0
  int v4; // r1
  uint32_t *v5; // r2
  uint32_t *v6; // r3

  v0 = off_100B04;
  *(uint32_t *)off_100B04 |= 0x1000u;
  v0[4896] |= 0x20000000u;
  v1 = (int *)dword_100B08;
  v2 = dword_100B08 + 2048;
  result = dword_100B0C - dword_100B08;
  do
  {
    v4 = *v1;
    v5 = (int *)((char *)v1++ + result);
    *v5 = v4;
  }
  while ( v1 != (int *)v2 );
  v6 = off_100B04;
  *(uint32_t *)off_100B04 |= 0x80000u;
  *v6 &= ~0x1000u;
  *(uint32_t *)off_100B10 &= ~0x20000000u;
  return result;
}

