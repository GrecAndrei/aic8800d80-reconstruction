// sub_13A370 @ 0x13a370, size 36 bytes
_WORD *__fastcall sub_13A370(_WORD *result)
{
  _WORD *v1; // r3

  v1 = off_13A394;
  if ( !*((_BYTE *)off_13A394 + 115) )
  {
    *((_WORD *)off_13A394 + 54) = *result;
    *(_DWORD *)(v1 + 0xdc) = *(_DWORD *)(result + 0x4);
    *(_DWORD *)(v1 + 0xe0) = *(_DWORD *)(result + 0x8);
    *(_DWORD *)(v1 + 0xe4) = 256;
  }
  return result;
}

