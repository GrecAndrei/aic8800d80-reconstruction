// sub_1018E4 @ 0x1018e4, size 28 bytes
_DWORD *__fastcall sub_1018E4(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = off_101900;
  *(_DWORD *)off_101900 = *result;
  *(_DWORD *)(v2 + 0x4) = *(_DWORD *)(result + 0x4);
  *(_DWORD *)(v2 + 0x8) = *a2;
  *(_DWORD *)(v2 + 0xc) = *(_DWORD *)(a2 + 0x4);
  *(_DWORD *)(v2 + 0x10) = *(_DWORD *)(a2 + 0x8);
  *(_DWORD *)(v2 + 0x14) = *(_DWORD *)(a2 + 0xc);
  return result;
}

