// sub_103D84 @ 0x103d84, size 86 bytes
int sub_103D84()
{
  int v0; // r2
  int *v1; // r4
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int *v5; // r3
  int v6; // r1
  uint32_t *v7; // r2
  int v8; // r0

  v0 = 777;
  v1 = (int *)off_103DE0;
  *(uint32_t *)off_103DDC = 777;
  while ( *v1 < 0 )
    delay_us(1);
  sub_12ECB0(dword_103DE4, *(uint32_t *)off_103DE0, v0);
  v2 = dword_103DE8;
  *(uint32_t *)off_103DDC = 0;
  sub_12ECB0(v2, v3, v4);
  v5 = (int *)off_103DF0;
  v6 = dword_103DF4;
  v7 = off_103DF8;
  *(uint32_t *)off_103DEC = 0;
  *v5 = v6;
  v8 = dword_103DFC;
  *v7 &= 0xFF00FFFF;
  return sub_12ECB0(v8, 0x4000, v7);
}

