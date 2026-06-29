// fwstruct annotate: 12ff98_log_list_init.c
// log_list_init @ 0x12ff98, size 94 bytes
// Doc: log_list_init [util]: Initialize logging list structure
// log_list_init [util]: Initialize logging list structure
int log_list_init()
{
  int *v0; // r4
  _DWORD *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  log_hw_init_if_d774();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12FFF8 = 1;
  }
  v0 = (int *)off_12FFFC;
  v1 = (_DWORD *)dword_130000;
  ++*(_DWORD *)off_12FFFC;
  sub_12D240(v1);
  sub_12D240((_DWORD *)dword_130004);
  list_push_tail(dword_130000, (_DWORD *)dword_130008);
  list_push_tail(dword_130000, (_DWORD *)dword_13000C);
  list_push_tail(dword_130000, (_DWORD *)dword_130010);
  result = list_push_tail(dword_130000, (_DWORD *)dword_130014);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_12FFF8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

