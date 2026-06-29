// log_list_init @ 0x12ff98, size 94 bytes
// Doc: log_list_init [util]: Initialize logging list structure
// log_list_init [util]: Initialize logging list structure
int log_list_init()
{
  int *v0; // r4
  uint32_t *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  log_hw_init_if_d774();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12FFF8 = 1;
  }
  v0 = (int *)off_12FFFC;
  v1 = (uint32_t *)dword_130000;
  ++*(uint32_t *)off_12FFFC;
  sub_12D240(v1);
  sub_12D240((uint32_t *)dword_130004);
  list_push_tail(dword_130000, (uint32_t *)dword_130008);
  list_push_tail(dword_130000, (uint32_t *)dword_13000C);
  list_push_tail(dword_130000, (uint32_t *)dword_130010);
  result = list_push_tail(dword_130000, (uint32_t *)dword_130014);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_12FFF8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

