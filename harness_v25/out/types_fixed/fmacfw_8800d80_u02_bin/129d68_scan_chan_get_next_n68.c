// scan_chan_get_next_n68 @ 0x129d68, size 32 bytes
// Doc: scan_chan_get_next_n68 [scan]: Acquire next scan channel context
// scan_chan_get_next_n68 [scan]: Acquire next scan channel context
int __fastcall scan_chan_get_next_n68(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r0
  unsigned __int8 v6; // r4

  v5 = ipc_array_lookup_n_4c0(a1, a2, a3, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  timestamp_update(a1, v5);
  *(_BYTE *)(a1 + 16) = 1;
  return v6;
}

