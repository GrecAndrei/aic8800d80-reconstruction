// fwstruct annotate: 13a4b0_sub_13A4B0.c
// sub_13A4B0 @ 0x13a4b0, size 36 bytes
_WORD *__fastcall sub_13A4B0(_WORD *result)
{
  _WORD *v1; // r3

  v1 = off_13A4D4;
  if ( !*((_BYTE *)off_13A4D4 + 115) )
  {
    *((_WORD *)off_13A4D4 + 54) = *result;
    v1[55] = result[1];
    v1[56] = result[2];
    v1[57] = 256;
  }
  return result;
}

