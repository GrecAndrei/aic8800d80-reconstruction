// v23 annotated: sub_126538 @ 0x126538
// Original: 126538_sub_126538.c
// Primary struct: <unclustered>
//
// sub_126538 @ 0x126538, size 64 bytes
// Doc: sub_1226538 [unknown]: Unknown helper function in lmacfw_rf image
// sub_1226538 [unknown]: Unknown helper function in lmacfw_rf image
int sub_126538()
{
  _DWORD *v0; // r2
  unsigned int *v1; // r4
  int v2; // r1
  int result; // r0
  unsigned int v4; // r3
  int *v5; // r3
  int v6; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_126578 = 1;
  }
  v0 = off_12657C;
  v1 = (unsigned int *)off_126580;
  v2 = *(_DWORD *)off_12657C;
  result = *(_DWORD *)off_12657C + 1;
  v4 = *(_DWORD *)off_126580 & 0xFFFFFBFF;
  *(_DWORD *)off_12657C = result;
  *v1 = v4;
  if ( result )
  {
    v5 = (int *)off_126578;
    *v0 = v2;
    v6 = *v5;
    if ( !v2 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  *(_DWORD *)off_126584 = 1024;
  return result;
}

