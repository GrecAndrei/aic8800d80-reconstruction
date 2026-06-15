// v23 annotated: sub_10DA6C @ 0x10da6c
// Original: 10da6c_sub_10DA6C.c
// Primary struct: bitmask_state (cluster 5, 7 funcs)
// Fields: prev_base=0x-c, mask0=0x0, mask1=0x4, mask2=0x8
//
// sub_10DA6C @ 0x10da6c, size 28 bytes
int sub_10DA6C(int a1, ...)
{
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, a1);
  return message_dispatch_n286(a1, (int)varg_r1);
}

