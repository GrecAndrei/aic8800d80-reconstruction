// mmio_copy_4words @ 0x101a68, size 28 bytes
// Doc: mmio_copy_4words [mmio]: Copy 4 words from src pair to MMIO 0x403308a8
// mmio_copy_4words [mmio]: Copy 4 words from src pair to MMIO 0x403308a8
_DWORD *__fastcall mmio_copy_4words(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = off_101A84;
  *(_DWORD *)off_101A84 = *result;
  *(_DWORD *)(v2 + 0x4) = *(_DWORD *)(result + 0x4);
  *(_DWORD *)(v2 + 0x8) = *a2;
  *(_DWORD *)(v2 + 0xc) = *(_DWORD *)(a2 + 0x4);
  *(_DWORD *)(v2 + 0x10) = *(_DWORD *)(a2 + 0x8);
  *(_DWORD *)(v2 + 0x14) = *(_DWORD *)(a2 + 0xc);
  return result;
}

