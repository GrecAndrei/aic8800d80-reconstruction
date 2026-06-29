// sub_113300 @ 0x113300, size 54 bytes
// Doc: sub_1213300 [unknown]: Stub function with invalid instruction (corpus artifact)
// sub_1213300 [unknown]: Stub function with invalid instruction (corpus artifact)
int sub_113300()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_113338 = 1;
  }
  v0 = (int *)off_11333C;
  v1 = dword_113340;
  ++*(uint32_t *)off_11333C;
  result = list_push_tail(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_113338;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

