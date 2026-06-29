// sub_13C2E4 @ 0x13c2e4, size 70 bytes
int  sub_13C2E4(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r4

  result = 696 * a1 + 12 * a2 + dword_13C330;
  v3 = *(unsigned __int8 *)(result + 452);
  if ( **(__int16 **)off_13C32C < 0 && v3 > 0x20 )
    result = sub_12F32C(dword_13C340, dword_13C33C, 1152);
  *(uint32_t *)(dword_13C334 + 32 * v3 + 8) = *((uint32_t *)off_13C338 + 4);
  return result;
}

