// fwstruct annotate: 101a68_mmio_copy_4words.c
// mmio_copy_4words @ 0x101a68, size 28 bytes
// Doc: mmio_copy_4words [mmio]: Copy 4 words from src pair to MMIO 0x403308a8
// mmio_copy_4words [mmio]: Copy 4 words from src pair to MMIO 0x403308a8
_DWORD *__fastcall mmio_copy_4words(_DWORD *result, _DWORD *a2)
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

