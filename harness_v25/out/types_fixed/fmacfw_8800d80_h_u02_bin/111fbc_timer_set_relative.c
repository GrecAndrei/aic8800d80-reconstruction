// timer_set_relative @ 0x111fbc, size 32 bytes
// Doc: timer_set_relative [util]: Program a timer with a relative deadline
// timer_set_relative [util]: Program a timer with a relative deadline
int __fastcall timer_set_relative(int a1)
{
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(_DWORD *)(result + 2816);
  if ( v2 < 0 )
    *(_DWORD *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}

