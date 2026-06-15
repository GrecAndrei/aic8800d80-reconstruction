// sub_11C3A4 @ 0x11c3a4, size 16 bytes
_BYTE *__fastcall sub_11C3A4(_BYTE *result)
{
  _BYTE *v1; // r3

  v1 = off_11C3B4;
  *((_BYTE *)off_11C3B4 + 164) = *result;
  v1[165] = result[1];
  return result;
}

