// init_1990b0_buffers @ 0x1420a0, size 38 bytes
int *init_1990b0_buffers()
{
  int *v0; // r4
  int *v1; // r5
  int *result; // r0

  v0 = (int *)dword_1420CC;
  memset((int *)dword_1420C8, 0, 3u);
  v1 = v0 + 144;
  do
  {
    result = memset(v0, 0, 0x48u);
    v0[15] = (int)v0;
    v0 += 18;
  }
  while ( v0 != v1 );
  return result;
}

