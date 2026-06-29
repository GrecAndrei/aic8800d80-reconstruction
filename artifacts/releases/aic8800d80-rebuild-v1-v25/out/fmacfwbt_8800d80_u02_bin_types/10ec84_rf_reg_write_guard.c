// rf_reg_write_guard @ 0x10ec84, size 70 bytes
// Doc: rf_reg_write_guard [rf]: Guard wrapper validating/serializing RF register writes
// rf_reg_write_guard [rf]: Guard wrapper validating/serializing RF register writes
int  rf_reg_write_guard(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  uint32_t *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10ECCC = 1;
  }
  v4 = (int *)off_10ECD0;
  ++*(uint32_t *)off_10ECD0;
  if ( a4 )
  {
    v5 = off_10ECD4;
    while ( !*(uint32_t *)off_10ECD4 )
      ;
    result = sub_10EBD4();
    *v5 = 1;
  }
  else
  {
    result = sub_10EBD4();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(uint32_t *)off_10ECCC;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

