// v23 annotated: sub_13A54C @ 0x13a54c
// Original: 13a54c_sub_13A54C.c
// Primary struct: <unclustered>
//
// sub_13A54C @ 0x13a54c, size 36 bytes
_WORD *__fastcall sub_13A54C(_WORD *result)
{
  _WORD *v1; // r3

  v1 = off_13A570;
  if ( !*((_BYTE *)off_13A570 + 115) )
  {
    *((_WORD *)off_13A570 + 54) = *result;
    v1[55] = result[1];
    v1[56] = result[2];
    v1[57] = 256;
  }
  return result;
}

