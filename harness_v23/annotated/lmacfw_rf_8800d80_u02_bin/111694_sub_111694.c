// v23 annotated: sub_111694 @ 0x111694
// Original: 111694_sub_111694.c
// Primary struct: tx_pkt_buf (cluster 7, 6 funcs)
// Fields: addr=0x0, len=0x4, ctrl=0x8, bssid=0xe, payload_end=0x320
//
// sub_111694 @ 0x111694, size 40 bytes
// Doc: rf_bus_write2_n17b [rf]: RF bus 2-byte write with parameter validation
// rf_bus_write2_n17b [rf]: RF bus 2-byte write with parameter validation
int *__fastcall sub_111694(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)sub_111524(a2, 0x8000000, 0x200000);
  }
  else if ( a2 <= 5 )
  {
    return rf_bus_write_1(a2, 0x8000000, 0x200000);
  }
  return result;
}

