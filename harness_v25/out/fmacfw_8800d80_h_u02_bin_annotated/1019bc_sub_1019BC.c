// fwstruct annotate: 1019bc_sub_1019BC.c
// sub_1019BC @ 0x1019bc, size 28 bytes
_DWORD *__fastcall sub_1019BC(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = off_1019D8;
  *(_DWORD *)off_1019D8 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}

