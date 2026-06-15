// v23 annotated: sub_11164C @ 0x11164c
// Original: 11164c_sub_11164C.c
// Primary struct: tx_pkt_buf (cluster 7, 6 funcs)
// Fields: addr=0x0, len=0x4, ctrl=0x8, bssid=0xe, payload_end=0x320
//
// sub_11164C @ 0x11164c, size 36 bytes
// Doc: rf_bus_mark_n4c8 [rf]: Marks RF bus state for n4c8 access pattern
// rf_bus_mark_n4c8 [rf]: Marks RF bus state for n4c8 access pattern
int *__fastcall sub_11164C(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)sub_111524(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_bus_write_1(a2, 0x8000000, 0);
  }
  return result;
}

