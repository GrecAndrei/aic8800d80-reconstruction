// v23 annotated: sub_12F630 @ 0x12f630
// Original: 12f630_sub_12F630.c
// Primary struct: <unclustered>
//
// sub_12F630 @ 0x12f630, size 82 bytes
// Doc: sub_122F630 [bt]: BT/LMAC helper: branches on shifted flag and dispatches
// sub_122F630 [bt]: BT/LMAC helper: branches on shifted flag and dispatches
int __fastcall sub_12F630(int a1, int a2, int a3)
{
  int *v4; // r4
  int v5; // r0
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12F684 = 1;
  }
  v4 = (int *)off_12F688;
  v5 = dword_12F68C;
  ++*(_DWORD *)off_12F688;
  result = sub_12ECB0(v5, a1, a2, a3 & 0xFFFFF);
  if ( *(int *)off_12F690 >= 0 )
  {
    sub_12BD48();
    result = irq_nesting_or(0x80000000);
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(_DWORD *)off_12F684;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

