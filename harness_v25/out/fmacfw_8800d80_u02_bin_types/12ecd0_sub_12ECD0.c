// sub_12ECD0 @ 0x12ecd0, size 36 bytes
int sub_12ECD0(int result, int a2, ...)
{
  va_list varg_r2; // [sp+10h] [bp+8h] BYREF

  va_start(varg_r2, a2);
  if ( ((unsigned __int16)result & **(uint16_t **)off_12ECF4) != 0 )
    return sub_10D808(a2, (int)varg_r2);
  return result;
}

