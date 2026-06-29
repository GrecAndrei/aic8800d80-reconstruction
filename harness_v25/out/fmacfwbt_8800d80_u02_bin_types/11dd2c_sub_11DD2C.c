// sub_11DD2C @ 0x11dd2c, size 162 bytes
int sub_11DD2C()
{
  int *v0; // r5
  int v1; // r4
  int result; // r0
  int *v3; // r8
  int *v4; // r9
  int v5; // r7
  void ( *v6)(uint32_t); // r2
  int v7; // r3
  int v8; // r2
  uint8_t *v9; // r4

  v0 = (int *)off_11DDD0;
  v1 = *(uint32_t *)off_11DDD0;
  result = sub_12D374(0x200000);
  if ( v1 )
  {
    v3 = (int *)off_11DDDC;
    v4 = (int *)off_11DDE0;
    v5 = 0;
    do
    {
      if ( (*(uint8_t *)(v1 + 16) & 1) == 0 )
      {
        if ( v5 )
          break;
        v5 = 1;
      }
      sub_12D4F8(v0);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v3 = 1;
      }
      v6 = *(void ( **)(uint32_t))(v1 + 4);
      ++*v4;
      *(uint8_t *)(v1 + 16) = 0;
      if ( v6 )
        v6(*(uint32_t *)(v1 + 8));
      result = *(uint32_t *)(v1 + 12);
      if ( result )
        result = sub_11E4F4();
      if ( *v4 )
      {
        v7 = *v4 - 1;
        v8 = *v3;
        *v4 = v7;
        if ( !v7 )
        {
          if ( v8 )
            __enable_irq();
        }
      }
      v1 = *v0;
    }
    while ( *v0 );
  }
  v9 = off_11DDD4;
  if ( *((uint8_t *)off_11DDD4 + 69) )
  {
    sub_12D32C(0x80000);
    result = sub_12EEF8(1024, dword_11DDD8);
    v9[69] = 0;
  }
  return result;
}

