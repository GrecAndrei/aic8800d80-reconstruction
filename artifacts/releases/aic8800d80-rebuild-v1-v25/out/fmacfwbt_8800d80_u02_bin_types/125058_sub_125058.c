// sub_125058 @ 0x125058, size 96 bytes
int  sub_125058(int a1)
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
    *(uint32_t *)off_1250B8 = 1;
  }
  v1 = (int *)off_1250BC;
  v2 = off_1250C0;
  v3 = *(uint32_t *)off_1250C0 == a1;
  ++*(uint32_t *)off_1250BC;
  if ( v3 )
  {
    result = sub_12D4F8(v2);
    v7 = off_1250C4;
    if ( *(uint32_t *)v2 )
    {
      v8 = *(uint32_t *)(*(uint32_t *)v2 + 12);
      result = 0x40000;
      *((uint32_t *)off_1250C4 + 2) = 0x40000;
      v7[12] = v8;
      v7[2] = 4;
    }
    else
    {
      *((uint32_t *)off_1250C4 + 2) = 1024;
    }
  }
  else
  {
    result = sub_12D510(v2, a1);
  }
  if ( *v1 )
  {
    v5 = *v1 - 1;
    v6 = *(uint32_t *)off_1250B8;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

