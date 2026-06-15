// v23 annotated: sub_111C04 @ 0x111c04
// Original: 111c04_sub_111C04.c
// Primary struct: tx_pkt_buf (cluster 8, 6 funcs)
// Fields: addr=0x0, len=0x4, ctrl=0x8, bssid=0xe, payload_end=0x320
//
// sub_111C04 @ 0x111c04, size 36 bytes
int *__fastcall sub_111C04(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)sub_111ADC(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return sub_111A24(a2, 0x8000000, 0);
  }
  return result;
}

