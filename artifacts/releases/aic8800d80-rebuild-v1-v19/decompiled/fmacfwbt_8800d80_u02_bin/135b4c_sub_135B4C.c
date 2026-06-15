// sub_135B4C @ 0x135b4c, size 46 bytes
_DWORD *__fastcall sub_135B4C(int a1)
{
  sub_12C964(6154, 6);
  if ( !a1 )
    return fmacfwbt_init_handler();
  feature_guard_sdio(256, dword_135B7C, a1);
  return (_DWORD *)sub_135020(a1);
}

