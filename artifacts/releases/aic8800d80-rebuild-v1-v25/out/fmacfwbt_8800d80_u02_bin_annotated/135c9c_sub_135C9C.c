// fwstruct annotate: 135c9c_sub_135C9C.c
// sub_135C9C @ 0x135c9c, size 44 bytes
_DWORD *__fastcall sub_135C9C(int a1)
{
  _DWORD *v1; // r5

  v1 = off_135CC8;
  sub_12C964(6154, 6);
  sub_14380C(a1, v1[4], 54);
  j_buffer_pool_get(v1[4] - 12);
  v1[4] = a1;
  return fmacfwbt_init_handler();
}

