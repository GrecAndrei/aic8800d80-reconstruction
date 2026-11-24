// sub_13A54C @ 0x13a54c, size 36 bytes
_WORD *__fastcall sub_13A54C(_WORD *result)
{
  _WORD *v1; // r3

  v1 = off_13A570;
  if ( !*((_BYTE *)off_13A570 + 115) )
  {
    *((_WORD *)off_13A570 + 54) = *result;
    *(_DWORD *)(v1 + 0xdc) = *(_DWORD *)(result + 0x4);
    *(_DWORD *)(v1 + 0xe0) = *(_DWORD *)(result + 0x8);
    *(_DWORD *)(v1 + 0xe4) = 256;
  }
  return result;
}

