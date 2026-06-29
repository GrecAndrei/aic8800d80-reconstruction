// sub_116654 @ 0x116654, size 102 bytes
uint32_t *sub_116654()
{
  int *v0; // r5
  int *v1; // r7
  int v2; // r6
  uint32_t *result; // r0
  uint32_t *v4; // r4
  int v5; // r2
  int v6; // r3
  void ( *v7)(uint32_t, uint32_t); // r3

  sub_11E628(0x200000);
  v0 = (int *)off_1166BC;
  v1 = (int *)off_1166C0;
  v2 = dword_1166C4;
  while ( 1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v1 = 1;
    }
    ++*v0;
    result = (uint32_t *)sub_11E7AC(v2);
    v4 = result;
    v5 = *v0 - 1;
    if ( *v0 )
    {
      v6 = *v1;
      *v0 = v5;
      if ( !v5 )
      {
        if ( v6 )
          __enable_irq();
      }
    }
    if ( !result )
      break;
    v7 = (void ( *)(uint32_t, uint32_t))result[11];
    if ( v7 )
      v7(result[12], *(uint32_t *)(result[8] + 68));
    if ( !*((uint8_t *)v4 + 52) )
      list_push_tail(dword_1166C8);
  }
  return result;
}

