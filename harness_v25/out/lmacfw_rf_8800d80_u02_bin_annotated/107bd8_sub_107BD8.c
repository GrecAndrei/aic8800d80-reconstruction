// fwstruct annotate: 107bd8_sub_107BD8.c
// sub_107BD8 @ 0x107bd8, size 60 bytes
int sub_107BD8()
{
  unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  _DWORD *v4; // r2

  v0 = (unsigned int *)off_107C18;
  v1 = *(_DWORD *)off_107C18;
  v2 = *(_DWORD *)off_107C14 >> 20;
  result = sub_11F74C(1, dword_107C1C, v2, off_107C14);
  v4 = off_107C24;
  *v0 = dword_107C20 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}

