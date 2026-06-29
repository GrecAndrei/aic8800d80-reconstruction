// sub_11908C @ 0x11908c, size 36 bytes
int  sub_11908C(int a1, int a2, int a3)
{
  if ( (*(uint32_t *)(dword_1190B0 + 696 * a1 + 4) & 0x20) != 0 )
    return rf_chan_table_lookup_8f48(a1, 7, a2, a3);
  else
    return sub_118DC4(a1, a2, a3);
}

