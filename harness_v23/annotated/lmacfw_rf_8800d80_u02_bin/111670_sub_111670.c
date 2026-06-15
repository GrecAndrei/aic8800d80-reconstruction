// v23 annotated: sub_111670 @ 0x111670
// Original: 111670_sub_111670.c
// Primary struct: tx_pkt_buf (cluster 7, 6 funcs)
// Fields: addr=0x0, len=0x4, ctrl=0x8, bssid=0xe, payload_end=0x320
//
// sub_111670 @ 0x111670, size 36 bytes
// Doc: unknown_func_0 [unknown]: firmware function (unlabeled)
// unknown_func_0 [unknown]: firmware function (unlabeled)
int *__fastcall sub_111670(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)sub_111524(a2, 0x200000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_bus_write_1(a2, 0x200000, 0);
  }
  return result;
}

