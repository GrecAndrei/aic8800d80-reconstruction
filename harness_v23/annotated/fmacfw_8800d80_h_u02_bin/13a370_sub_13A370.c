// v23 annotated: sub_13A370 @ 0x13a370
// Original: 13a370_sub_13A370.c
// Primary struct: <unclustered>
//
// sub_13A370 @ 0x13a370, size 36 bytes
_WORD *__fastcall sub_13A370(_WORD *result)
{
  _WORD *v1; // r3

  v1 = off_13A394;
  if ( !*((_BYTE *)off_13A394 + 115) )
  {
    *((_WORD *)off_13A394 + 54) = *result;
    v1[55] = result[1];
    v1[56] = result[2];
    v1[57] = 256;
  }
  return result;
}

