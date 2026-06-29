// sub_115DBC @ 0x115dbc, size 186 bytes
int sub_115DBC()
{
  int *v0; // r10
  uint8_t *v1; // r5
  uint32_t *v2; // r8
  int v3; // r9
  int v4; // r7
  uint32_t *v5; // r6
  int *v6; // r11
  int i; // r4
  int v8; // r0
  int v9; // r1
  int v10; // r3
  int *v11; // r3
  int v12; // r3
  int v13; // r3
  int v14; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_115E78 = 1;
  }
  v0 = (int *)off_115E88;
  v1 = off_115E7C;
  v2 = off_115E8C;
  v3 = dword_115E90;
  v4 = dword_115E80;
  v5 = off_115E84;
  v6 = (int *)off_115E94;
  ++*(uint32_t *)off_115E88;
  v1[143] = 0;
  for ( i = 4; i != -1; --i )
  {
    if ( *((uint32_t *)v1 + 28) )
    {
      sub_11532C((unsigned __int8)i);
      *(uint32_t *)(v4 + 4 * i) = *v2 + *(uint32_t *)(v3 + 4 * i);
      *v5 = 1 << i;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_115E78 = 1;
      }
      v8 = *v0;
      v9 = *v0 + 1;
      v10 = (1 << i) | *v6;
      *v0 = v9;
      *v6 = v10;
      if ( v9 )
      {
        v11 = (int *)off_115E78;
        *v0 = v8;
        v12 = *v11;
        if ( !v8 )
        {
          if ( v12 )
            __enable_irq();
        }
      }
    }
    v1 -= 28;
  }
  if ( *v0 )
  {
    v13 = *v0 - 1;
    v14 = *(uint32_t *)off_115E78;
    *v0 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return sub_11E5E0(4096);
}

