// sub_10DA7C @ 0x10da7c, size 28 bytes
int sub_10DA7C(int a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, a1);
  return sub_10D660(a1, (int)varg_r1);
}

