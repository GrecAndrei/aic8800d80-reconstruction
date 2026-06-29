// sub_1080F8 @ 0x1080f8, size 56 bytes
int sub_1080F8()
{
  unsigned int *v0; // r5
  int v1; // r6
  __int16 v2; // r4
  int result; // r0
  uint32_t *v4; // r1

  v0 = (unsigned int *)off_108134;
  v1 = *(uint32_t *)off_108134;
  v2 = (unsigned __int16)*(uint32_t *)off_108130 >> 4;
  result = sub_12EB90(1, dword_108138);
  v4 = off_10813C;
  *v0 = (v2 + (uint16_t)v1) & 0xFFF | *v0 & 0xFFFFF000;
  *v4 |= 0x400000u;
  return result;
}

