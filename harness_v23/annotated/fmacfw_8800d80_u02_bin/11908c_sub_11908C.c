// v23 annotated: sub_11908C @ 0x11908c
// Original: 11908c_sub_11908C.c
// Primary struct: <unclustered>
//
// sub_11908C @ 0x11908c, size 36 bytes
int __fastcall sub_11908C(int a1, int a2, int a3)
{
  if ( (*(_DWORD *)(dword_1190B0 + 696 * a1 + 4) & 0x20) != 0 )
    return rf_chan_table_lookup_8f48(a1, 7, a2, a3);
  else
    return sub_118DC4(a1, a2, a3);
}

