// sub_100A14 @ 0x100a14, size 90 bytes
int sub_100A14()
{
  _DWORD *v0; // r2
  int *v1; // r3
  int v2; // r4
  int result; // r0
  int v4; // r1
  _DWORD *v5; // r2
  _DWORD *v6; // r3

  v0 = off_100A70;
  *(_DWORD *)off_100A70 |= 0x1000u;
  v0[4896] |= 0x20000000u;
  v1 = (int *)dword_100A74;
  v2 = dword_100A74 + 2048;
  result = dword_100A78 - dword_100A74;
  do
  {
    v4 = *v1;
    v5 = (int *)((char *)v1++ + result);
    *v5 = v4;
  }
  while ( v1 != (int *)v2 );
  v6 = off_100A70;
  *(_DWORD *)off_100A70 |= 0x80000u;
  *v6 &= ~0x1000u;
  *(_DWORD *)off_100A7C &= ~0x20000000u;
  return result;
}

