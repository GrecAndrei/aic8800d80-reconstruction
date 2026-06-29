// sub_13BA0C @ 0x13ba0c, size 22 bytes
// Doc: sub_123BA0C [patch]: Stub/trampoline: nop + load pointer (patch hook)
// sub_123BA0C [patch]: Stub/trampoline: nop + load pointer (patch hook)
int  sub_13BA0C(__int16 a1)
{
  return timer_set_relative(8194, (unsigned __int16)(a1 << 8) | 8, 0x1F4000u);
}

