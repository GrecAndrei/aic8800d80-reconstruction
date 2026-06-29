// fwstruct annotate: 101a68_sub_101A68.c
// sub_101A68 @ 0x101a68, size 28 bytes
_DWORD *__fastcall sub_101A68(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = off_101A84;
  *(_DWORD *)off_101A84 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}

