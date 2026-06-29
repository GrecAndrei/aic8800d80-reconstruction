// sub_1264DC @ 0x1264dc, size 70 bytes
int  sub_1264DC(int a1)
{
  uint32_t *v1; // r3
  int *v2; // r4
  int v3; // r1
  int v4; // r2
  int result; // r0
  bool v6; // nf
  uint32_t *v7; // r2

  *(uint32_t *)off_126524 = a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_126528 = 1;
  }
  v1 = off_12652C;
  v2 = (int *)off_126530;
  v3 = *(uint32_t *)off_12652C;
  v4 = *(uint32_t *)off_126530;
  result = *(uint32_t *)off_12652C + 1;
  v6 = (*(uint32_t *)off_126530 & 0x400) != 0;
  *(uint32_t *)off_12652C = result;
  if ( !v6 )
  {
    *(uint32_t *)off_126534 = 1024;
    *v2 = v4 | 0x400;
  }
  if ( result )
  {
    v7 = off_126528;
    *v1 = v3;
    if ( !v3 )
    {
      if ( *v7 )
        __enable_irq();
    }
  }
  return result;
}

