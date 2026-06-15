// v23 annotated: sub_1301B4 @ 0x1301b4
// Original: 1301b4_sub_1301B4.c
// Primary struct: <unclustered>
//
// sub_1301B4 @ 0x1301b4, size 94 bytes
int sub_1301B4()
{
  int *v0; // r4
  _DWORD *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  log_hw_init_if();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_130214 = 1;
  }
  v0 = (int *)off_130218;
  v1 = (_DWORD *)dword_13021C;
  ++*(_DWORD *)off_130218;
  bt_xtal_init_check(v1);
  bt_xtal_init_check((_DWORD *)dword_130220);
  list_push_tail(dword_13021C, (_DWORD *)dword_130224);
  list_push_tail(dword_13021C, (_DWORD *)dword_130228);
  list_push_tail(dword_13021C, (_DWORD *)dword_13022C);
  result = list_push_tail(dword_13021C, (_DWORD *)dword_130230);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_130214;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

