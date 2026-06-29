// init_alloc_0x200000 @ 0x11dde4, size 180 bytes
// Doc: init_alloc_0x200000 [util]: Allocate 0x200000-byte buffer and initialize related state
// init_alloc_0x200000 [util]: Allocate 0x200000-byte buffer and initialize related state
int init_alloc_0x200000()
{
  int *v0; // r6
  int v1; // r4
  int result; // r0
  uint16_t *v3; // r5
  int *v4; // r8
  int *v5; // r9
  char v6; // r2
  void ( *v7)(uint32_t); // r3
  int v8; // r3
  int v9; // r2
  uint8_t *v10; // r4

  v0 = (int *)off_11DE98;
  v1 = *(uint32_t *)off_11DE98;
  result = sub_12D374(0x200000);
  if ( v1 )
  {
    v3 = off_11DE9C;
    if ( *(uint16_t *)off_11DE9C )
    {
      v4 = (int *)off_11DEA8;
      v5 = (int *)off_11DEAC;
      do
      {
        if ( (*(uint8_t *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        sub_12D4F8(v0);
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *v4 = 1;
        }
        v6 = *(uint8_t *)(v1 + 16);
        ++*v5;
        if ( (v6 & 1) == 0 )
          --*v3;
        v7 = *(void ( **)(uint32_t))(v1 + 4);
        *(uint8_t *)(v1 + 16) = 0;
        if ( v7 )
          v7(*(uint32_t *)(v1 + 8));
        result = *(uint32_t *)(v1 + 12);
        if ( result )
          result = rx_desc_status_get();
        if ( *v5 )
        {
          v8 = *v5 - 1;
          v9 = *v4;
          *v5 = v8;
          if ( !v8 )
          {
            if ( v9 )
              __enable_irq();
          }
        }
        v1 = *v0;
      }
      while ( *v0 );
      v10 = off_11DEA0;
      if ( *((uint8_t *)off_11DEA0 + 69) )
      {
        irq_nesting_or(0x80000);
        result = feature_guard_sdio(1024, dword_11DEA4);
        v10[69] = 0;
      }
    }
  }
  return result;
}

