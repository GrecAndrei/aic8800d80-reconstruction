// log_pool_alloc_b @ 0x1102a0, size 62 bytes
// Doc: log_pool_alloc_b [util]: Allocate a buffer from log pool variant B
// log_pool_alloc_b [util]: Allocate a buffer from log pool variant B
int log_pool_alloc_b()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1102E0 = 1;
  }
  v0 = (int *)off_1102E4;
  v1 = dword_1102E8;
  ++*(uint32_t *)off_1102E4;
  result = sub_12D190(v1);
  if ( result )
    --*(uint32_t *)off_1102EC;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_1102E0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

