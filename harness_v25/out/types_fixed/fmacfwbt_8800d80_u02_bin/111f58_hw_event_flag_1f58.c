// hw_event_flag_1f58 @ 0x111f58, size 32 bytes
// Doc: hw_event_flag_1f58 [mmio]: Check hardware event flag status from MMIO register
// hw_event_flag_1f58 [mmio]: Check hardware event flag status from MMIO register
int __fastcall hw_event_flag_1f58(int a1)
{
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(_DWORD *)(result + 2816);
  if ( v2 < 0 )
    *(_DWORD *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}

