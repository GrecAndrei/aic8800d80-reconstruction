// sub_11C3A4 @ 0x11c3a4, size 16 bytes
_BYTE *__fastcall sub_11C3A4(_BYTE *result)
{
  _BYTE *v1; // r3

  v1 = off_11C3B4;
  *((_BYTE *)off_11C3B4 + 164) = *result;
  *(_DWORD *)(v1 + 0x294) = *(_DWORD *)(result + 0x4);
  return result;
}

