// sub_11A7E8 @ 0x11a7e8, size 68 bytes
// Doc: sub_121A7E8 [unknown]: Unknown stub function with invalid instruction
// sub_121A7E8 [unknown]: Unknown stub function with invalid instruction
int  sub_11A7E8(int result)
{
  int *v1; // r4
  int v2; // r2
  int v3; // r1
  int v4; // r3
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11A82C = 1;
  }
  v1 = (int *)off_11A834;
  v2 = dword_11A830 + 84 * result;
  v3 = *(unsigned __int8 *)(v2 + 80);
  v4 = *(uint32_t *)off_11A834 + 1;
  *(uint32_t *)off_11A834 = v4;
  if ( !v3 && *(uint32_t *)(v2 + 44) )
  {
    result = sub_119EC8(result);
    v4 = *v1;
  }
  if ( v4 )
  {
    v5 = v4 - 1;
    v6 = *(uint32_t *)off_11A82C;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

