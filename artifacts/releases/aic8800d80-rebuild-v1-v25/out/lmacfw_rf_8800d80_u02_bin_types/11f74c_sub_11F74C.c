// sub_11F74C @ 0x11f74c, size 36 bytes
// Doc: rf_mem_read_n1c8 [rf]: Read from RF shared memory via helper
// rf_mem_read_n1c8 [rf]: Read from RF shared memory via helper
int  sub_11F74C(int result, int a2, int a3, int a4)
{
  uint32_t varg_r2[2]; // [sp+10h] [bp+8h] BYREF

  varg_r2[0] = a3;
  varg_r2[1] = a4;
  if ( ((unsigned __int16)result & **(uint16_t **)rf_mem_read_n1dc) != 0 )
    return message_dispatch_n286(a2, (int)varg_r2);
  return result;
}

