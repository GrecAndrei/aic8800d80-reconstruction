// v23 annotated: sub_12EC60 @ 0x12ec60
// Original: 12ec60_sub_12EC60.c
// Primary struct: delay_timer (cluster 0, 25 funcs)
// Fields: us=0x0, ticks=0x4
//
// sub_12EC60 @ 0x12ec60, size 6 bytes
int __fastcall sub_12EC60(int result)
{
  *((_DWORD *)off_12EC68 + 1) = result;
  return result;
}

