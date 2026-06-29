// sub_11843C @ 0x11843c, size 86 bytes
int sub_11843C()
{
  uint16_t *v0; // r4
  int v1; // r3
  __int16 *v2; // r1
  int v3; // r1

  v0 = off_118494;
  sub_100200((int *)off_118494, 0, 0x20u);
  v1 = dword_11849C;
  v2 = *(__int16 **)off_118498;
  *(uint32_t *)v0 = dword_11849C;
  v0[8] = 0;
  v3 = *v2;
  *((uint32_t *)v0 + 1) = 0;
  if ( v3 < 0 && *(uint32_t *)off_1184A4 << 28 )
  {
    sub_1219F4(dword_1184AC, dword_1184A8, 472);
    *(uint32_t *)off_1184A0 = *(uint32_t *)v0 | *((uint32_t *)v0 + 1);
  }
  else
  {
    *(uint32_t *)off_1184A0 = v1;
  }
  return sub_1183A0();
}

