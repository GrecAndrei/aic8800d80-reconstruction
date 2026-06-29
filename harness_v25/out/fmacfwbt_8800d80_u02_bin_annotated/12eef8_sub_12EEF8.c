// fwstruct annotate: 12eef8_sub_12EEF8.c
// sub_12EEF8 @ 0x12eef8, size 36 bytes
int sub_12EEF8(int result, int a2, ...)
{
  va_list varg_r2; // [sp+10h] [bp+8h] BYREF

  va_start(varg_r2, a2);
  if ( ((unsigned __int16)result & **(_WORD **)off_12EF1C) != 0 )
    return sub_10D660(a2, (int)varg_r2);
  return result;
}

