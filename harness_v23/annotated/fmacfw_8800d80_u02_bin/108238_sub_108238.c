// v23 annotated: sub_108238 @ 0x108238
// Original: 108238_sub_108238.c
// Primary struct: <unclustered>
//
// sub_108238 @ 0x108238, size 56 bytes
int sub_108238()
{
  unsigned int *v0; // r5
  int v1; // r6
  __int16 v2; // r4
  int result; // r0
  _DWORD *v4; // r1

  v0 = (unsigned int *)off_108274;
  v1 = *(_DWORD *)off_108274;
  v2 = (unsigned __int16)*(_DWORD *)off_108270 >> 4;
  result = feature_guard_check(1, dword_108278);
  v4 = off_10827C;
  *v0 = (v2 + (_WORD)v1) & 0xFFF | *v0 & 0xFFFFF000;
  *v4 |= 0x400000u;
  return result;
}

