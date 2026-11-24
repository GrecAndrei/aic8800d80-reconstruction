// sub_134650 @ 0x134650, size 54 bytes
// Doc: sub_1234650 [util]: Clear/reset state structure fields and zero registers
// sub_1234650 [util]: Clear/reset state structure fields and zero registers
_DWORD *sub_134650()
{
  _DWORD *v0; // r4
  _WORD *v1; // r3
  int v2; // r0

  v0 = off_134688;
  v1 = off_13468C;
  v2 = *((_DWORD *)off_134688 + 4);
  *((_BYTE *)off_13468C + 13) = 0;
  *(_DWORD *)(v1 + 0x1c) = 0;
  *((_BYTE *)v1 + 3) = 0;
  if ( v2 )
  {
    j_buffer_pool_get(v2 - 12);
    j_buffer_pool_get(*(_DWORD *)(v0 + 0x14) - 12);
  }
  memset_thunk((int *)off_134688, 0, 0x2Cu);
  return rf_bus_mark_n_3b7(6u, 0);
}

