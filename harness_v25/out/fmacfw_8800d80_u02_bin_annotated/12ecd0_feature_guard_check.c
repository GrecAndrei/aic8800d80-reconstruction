// fwstruct annotate: 12ecd0_feature_guard_check.c
// feature_guard_check @ 0x12ecd0, size 36 bytes
// Doc: feature_guard_check [util]: SDIO feature availability guard testing a bitmask against feature word
// feature_guard_check [util]: SDIO feature availability guard testing a bitmask against feature word
int feature_guard_check(int result, int a2, ...)
{
  va_list varg_r2; // [sp+10h] [bp+8h] BYREF

  va_start(varg_r2, a2);
  if ( ((unsigned __int16)result & **(_WORD **)off_12ECF4) != 0 )
    return sdio_transfer_808(a2, (int)varg_r2);
  return result;
}

