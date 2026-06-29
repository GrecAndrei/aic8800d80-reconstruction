// fwstruct annotate: 10da6c_sub_10DA6C.c
// sub_10DA6C @ 0x10da6c, size 28 bytes
int sub_10DA6C(int a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, a1);
  return message_dispatch_n286(a1, (int)varg_r1);
}

