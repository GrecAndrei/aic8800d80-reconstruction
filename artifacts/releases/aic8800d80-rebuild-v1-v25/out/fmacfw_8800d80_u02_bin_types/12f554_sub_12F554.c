// sub_12F554 @ 0x12f554, size 48 bytes
// Doc: sub_122F554 [unknown]: Save callee-saved regs and dereference first argument pointer
// sub_122F554 [unknown]: Save callee-saved regs and dereference first argument pointer
uint32_t ** sub_12F554(uint32_t **result)
{
  uint32_t *v1; // r4
  int v2; // r6
  uint32_t *v3; // r5
  int v4; // r2

  v1 = *result;
  if ( *result )
  {
    v2 = dword_12F584;
    v3 = result;
    do
    {
      while ( 1 )
      {
        rf_bus_mark_n100_d2d0((int)v3);
        result = (uint32_t **)v2;
        if ( !v1[3] )
          break;
        result = (uint32_t **)list_push_tail(v2, v1);
        v1 = (uint32_t *)*v3;
        if ( !*v3 )
          return result;
      }
      v4 = v1[2];
      v1 = (uint32_t *)*v3;
      *(uint16_t *)(v4 + 8) = 0;
    }
    while ( v1 );
  }
  return result;
}

