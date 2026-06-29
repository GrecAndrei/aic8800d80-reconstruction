// sub_121774 @ 0x121774, size 90 bytes
unsigned int sub_121774()
{
  __int16 **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  uint32_t *v5; // r2

  v0 = (__int16 **)off_1217D4;
  v1 = dword_1217D8;
  *(uint32_t *)off_1217D0 &= ~2u;
  v2 = (int *)off_1217DC;
  v3 = **v0;
  *(uint32_t *)off_1217DC = v1;
  if ( v3 < 0 && *(uint32_t *)off_1217F0 << 28 )
  {
    sub_12F35C(dword_1217F8, dword_1217F4, 472);
    v1 = *v2;
  }
  *(uint32_t *)off_1217E0 = v1 | v2[1];
  result = sub_11DF40(0);
  v5 = off_1217E8;
  *(uint32_t *)off_1217E4 = dword_1217EC;
  *v5 &= 0xFFFBFFFE;
  return result;
}

