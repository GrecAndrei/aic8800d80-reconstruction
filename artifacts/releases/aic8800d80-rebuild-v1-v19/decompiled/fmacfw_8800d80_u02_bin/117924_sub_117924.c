// sub_117924 @ 0x117924, size 168 bytes
// Doc: sub_1217924 [mmio]: Misc register poke helper with shift mask
// sub_1217924 [mmio]: Misc register poke helper with shift mask
int __fastcall sub_117924(int result)
{
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r3
  unsigned int v4; // r4

  v1 = *(_DWORD *)off_1179CC;
  if ( (*(_DWORD *)off_1179CC & 0x1000) != 0 )
  {
    result = log_free_pool_dispatch2_c8e4(result, *(_DWORD *)off_1179CC << 19);
    *(_DWORD *)off_1179E0 = 4096;
  }
  v2 = dword_1179D0;
  if ( (v1 & dword_1179D0) != 0 )
  {
    result = rf_stream_start2_n418();
    *(_DWORD *)off_1179E0 = v2;
  }
  if ( (dword_1179D4 & v1) != 0 && (*(_DWORD *)off_1179D8 & 0x300000) == 0 )
  {
    *(_DWORD *)off_1179E8 |= 0x200u;
    v3 = dword_1179DC & v1;
    if ( (dword_1179DC & v1) == 0 )
      return result;
  }
  else
  {
    v3 = dword_1179DC & v1;
    if ( (dword_1179DC & v1) == 0 )
      return result;
  }
  if ( (v1 & 0x80000) != 0 )
  {
LABEL_9:
    *(_DWORD *)off_1179E0 = 0x80000;
    return tx_queue_dispatch(5);
  }
  v4 = (unsigned __int8)(25 - __clz(v3));
  if ( **(__int16 **)off_1179E4 >= 0 || v4 <= 6 )
  {
    if ( v4 == 5 )
      goto LABEL_9;
  }
  else
  {
    sub_12F46C(dword_1179F0, dword_1179EC, 2883);
  }
  *(_DWORD *)off_1179E0 = 1 << (v4 + 6);
  return tx_queue_dispatch(v4);
}

