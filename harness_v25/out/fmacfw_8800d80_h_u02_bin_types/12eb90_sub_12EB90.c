// sub_12EB90 @ 0x12eb90, size 36 bytes
int sub_12EB90(int result, int a2, ...)
{
  va_list varg_r2; // [sp+10h] [bp+8h] BYREF

  va_start(varg_r2, a2);
  if ( ((unsigned __int16)result & **(uint16_t **)off_12EBB4) != 0 )
    return sub_10D6C8(a2, (int)varg_r2);
  return result;
}

