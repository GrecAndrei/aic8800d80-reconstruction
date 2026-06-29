// fwstruct annotate: 11c4e4_sub_11C4E4.c
// sub_11C4E4 @ 0x11c4e4, size 16 bytes
_BYTE *__fastcall sub_11C4E4(_BYTE *result)
{
  _BYTE *v1; // r3

  v1 = off_11C4F4;
  *((_BYTE *)off_11C4F4 + 164) = *result;
  v1[165] = result[1];
  return result;
}

