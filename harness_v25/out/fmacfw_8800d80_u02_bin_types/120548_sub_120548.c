// sub_120548 @ 0x120548, size 82 bytes
int sub_120548()
{
  uint8_t *v0; // r4
  int v1; // r3
  __int16 *v2; // r1
  int v3; // r1
  int result; // r0

  v0 = off_12059C;
  memset_thunk((int *)off_12059C, 0, 0x34u);
  v1 = dword_1205A4;
  v2 = *(__int16 **)off_1205A0;
  *(uint32_t *)v0 = dword_1205A4;
  v0[31] = 1;
  *((uint16_t *)v0 + 9) = 0;
  v3 = *v2;
  *((uint32_t *)v0 + 1) = 0;
  if ( v3 < 0 && *(uint32_t *)off_1205B0 << 28 )
  {
    sub_12F49C(dword_1205B8, dword_1205B4, 472);
    v1 = *(uint32_t *)v0 | *((uint32_t *)v0 + 1);
  }
  *(uint32_t *)off_1205A8 = v1;
  result = fmac_main_loop();
  *((uint32_t *)v0 + 9) = dword_1205AC;
  return result;
}

