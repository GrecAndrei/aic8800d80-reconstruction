// feature_guard_sdio @ 0x12eef8, size 36 bytes
// Doc: feature_guard_sdio [mac]: Check SDIO feature enable flag from shared state
// feature_guard_sdio [mac]: Check SDIO feature enable flag from shared state
int feature_guard_sdio(int result, int a2, ...)
{
  va_list varg_r2; // [sp+10h] [bp+8h] BYREF

  va_start(varg_r2, a2);
  if ( ((unsigned __int16)result & **(_WORD **)off_12EF1C) != 0 )
    return sdio_transfer(a2, (int)varg_r2);
  return result;
}

