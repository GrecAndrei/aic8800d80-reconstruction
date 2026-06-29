// sub_123068 @ 0x123068, size 94 bytes
int sub_123068()
{
  int *v0; // r4
  uint32_t *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  sub_10D614();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1230C8 = 1;
  }
  v0 = (int *)off_1230CC;
  v1 = (uint32_t *)dword_1230D0;
  ++*(uint32_t *)off_1230CC;
  sub_11E71C(v1);
  sub_11E71C((uint32_t *)dword_1230D4);
  list_push_tail(dword_1230D0, (uint32_t *)dword_1230D8);
  list_push_tail(dword_1230D0, (uint32_t *)dword_1230DC);
  list_push_tail(dword_1230D0, (uint32_t *)dword_1230E0);
  result = list_push_tail(dword_1230D0, (uint32_t *)dword_1230E4);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_1230C8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

