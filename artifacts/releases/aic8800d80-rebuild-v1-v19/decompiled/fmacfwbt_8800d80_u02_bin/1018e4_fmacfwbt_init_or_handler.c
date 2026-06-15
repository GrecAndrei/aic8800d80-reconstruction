// fmacfwbt_init_or_handler @ 0x1018e4, size 28 bytes
// Doc: fmacfwbt_init_or_handler [unknown]: FMAC BT firmware init/handler stub
// fmacfwbt_init_or_handler [unknown]: FMAC BT firmware init/handler stub
_DWORD *__fastcall fmacfwbt_init_or_handler(_DWORD *result, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = off_101900;
  *(_DWORD *)off_101900 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}

