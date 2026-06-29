// fwstruct annotate: 11c924_sub_11C924.c
// sub_11C924 @ 0x11c924, size 16 bytes
_BYTE *__fastcall sub_11C924(_BYTE *result)
{
  _BYTE *v1; // r3

  v1 = off_11C934;
  *((_BYTE *)off_11C934 + 164) = *result;
  v1[165] = result[1];
  return result;
}

