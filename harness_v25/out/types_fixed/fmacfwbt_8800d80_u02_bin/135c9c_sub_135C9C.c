// sub_135C9C @ 0x135c9c, size 44 bytes
_DWORD *__fastcall sub_135C9C(int a1)
{
  _DWORD *v1; // r5

  v1 = off_135CC8;
  sub_12C964(6154, 6);
  sub_14380C(a1, *(_DWORD *)(v1 + 0x10), 54);
  j_buffer_pool_get(*(_DWORD *)(v1 + 0x10) - 12);
  *(_DWORD *)(v1 + 0x10) = a1;
  return fmacfwbt_init_handler();
}

