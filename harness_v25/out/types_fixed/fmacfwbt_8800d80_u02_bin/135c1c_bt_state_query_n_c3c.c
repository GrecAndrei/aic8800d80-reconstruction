// bt_state_query_n_c3c @ 0x135c1c, size 124 bytes
// Doc: bt_state_query_n_c3c [bt]: Query BT state and process result
// bt_state_query_n_c3c [bt]: Query BT state and process result
_DWORD *__fastcall bt_state_query_n_c3c(unsigned __int16 *a1)
{
  unsigned __int16 *v1; // r6
  int v3; // r5
  _DWORD *result; // r0
  int v5; // r3
  int v6; // r3

  v1 = a1 + 6;
  sub_12C964(6154, 6);
  v3 = *(_DWORD *)(v1 + 0x8);
  result = (_DWORD *)feature_guard_sdio(256, dword_135C98, v3);
  if ( v3 )
    return (_DWORD *)sub_135020(v3);
  v5 = *(_DWORD *)(a1 + 0x18);
  if ( !*(_DWORD *)(a1 + 0x18) )
    return fmacfwbt_init_handler();
  if ( v5 != 1 )
  {
    if ( v5 == 2 )
      return (_DWORD *)sub_135B94(*((_BYTE *)a1 + 8), (int)(a1 + 9), (unsigned __int16)(*a1 - 6));
    return result;
  }
  v6 = *(_DWORD *)(v1 + 0x4);
  if ( v6 == 4 )
  {
    mmio_reg_read_1203140(3000);
    return fmacfwbt_init_handler();
  }
  if ( v6 == 2 && *a1 > 0x22u )
    return sub_135384(3, (char *)a1 + 20);
  return result;
}

