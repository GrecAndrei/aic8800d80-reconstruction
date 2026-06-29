// sub_115D64 @ 0x115d64, size 76 bytes
// Doc: sub_1215D64 [util]: Helper routine with stack frame and shift op
// sub_1215D64 [util]: Helper routine with stack frame and shift op
int sub_115D64()
{
  int *v0; // r6
  uint8_t *v1; // r7
  uint8_t *v2; // r5
  int i; // r4
  int v4; // r3
  int result; // r0
  int v6; // r3
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_115DB0 = 1;
  }
  v0 = (int *)off_115DB4;
  v1 = off_115DB8;
  ++*(uint32_t *)off_115DB4;
  v2 = v1;
  for ( i = 4; i != -1; --i )
  {
    v4 = *((uint32_t *)v2 + 28);
    result = (unsigned __int8)i;
    v2 -= 28;
    if ( v4 )
      result = rf_event_handler_8a4(result);
  }
  v6 = *v0;
  v1[143] = 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    v8 = *(uint32_t *)off_115DB0;
    *v0 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

