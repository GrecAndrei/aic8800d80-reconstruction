// timestamp_remove @ 0x124e34, size 96 bytes
// Doc: timestamp_remove [util]: Remove/clear timestamp from data structure
// timestamp_remove [util]: Remove/clear timestamp from data structure
int  timestamp_remove(int a1)
{
  int *v1; // r4
  void *v2; // r5
  bool v3; // zf
  int result; // r0
  int v5; // r3
  int v6; // r2
  uint32_t *v7; // r3
  int v8; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_124E94 = 1;
  }
  v1 = (int *)off_124E98;
  v2 = off_124E9C;
  v3 = *(uint32_t *)off_124E9C == a1;
  ++*(uint32_t *)off_124E98;
  if ( v3 )
  {
    result = rf_bus_mark_n100_d2d0(v2);
    v7 = off_124EA0;
    if ( *(uint32_t *)v2 )
    {
      v8 = *(uint32_t *)(*(uint32_t *)v2 + 12);
      result = 0x40000;
      *((uint32_t *)off_124EA0 + 2) = 0x40000;
      v7[12] = v8;
      v7[2] = 4;
    }
    else
    {
      *((uint32_t *)off_124EA0 + 2) = 1024;
    }
  }
  else
  {
    result = sub_12D2E8(v2, a1);
  }
  if ( *v1 )
  {
    v5 = *v1 - 1;
    v6 = *(uint32_t *)off_124E94;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

