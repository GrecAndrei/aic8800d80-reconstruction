// scan_chan_entry_alloc_n_54 @ 0x11b5e8, size 72 bytes
// Doc: scan_chan_entry_alloc_n_54 [scan]: Allocate a 0x54-byte scan channel entry from pool
// scan_chan_entry_alloc_n_54 [scan]: Allocate a 0x54-byte scan channel entry from pool
int __fastcall scan_chan_entry_alloc_n_54(int a1, int a2)
{
  int v4; // r5
  int v5; // r8
  int v6; // r2

  v4 = dword_11B630 + 84 * a2;
  v5 = *(_DWORD *)(a1 + 76);
  sub_12D4F8(84 * (__int16)a2 + 12 + dword_11B630);
  v6 = *(unsigned __int16 *)(a1 + 4);
  --*(_BYTE *)(v4 + 80);
  if ( v6 )
    return sub_118358(a1, *(_DWORD *)(v5 + 72), a2);
  else
    return sub_119120();
}

