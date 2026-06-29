// fwstruct annotate: 117954_rf_table_lookup_handler.c
// rf_table_lookup_handler @ 0x117954, size 50 bytes
// Doc: rf_table_lookup_handler [rf]: Look up handler from RF table and invoke callback
// rf_table_lookup_handler [rf]: Look up handler from RF table and invoke callback
int __fastcall rf_table_lookup_handler(int a1)
{
  void *v2; // r0

  scan_channel_done_n_180(a1, *(_DWORD *)(a1 + 28));
  v2 = off_117988;
  if ( !*(_DWORD *)off_117988 )
    return sub_1174EC(a1);
  *(_BYTE *)(a1 + 16) |= 1u;
  *(_DWORD *)(a1 + 4) = 0;
  return list_push_tail(v2);
}

