// v23 annotated: irq_prio_set @ 0x10dafc
// Original: 10dafc_irq_prio_set.c
// Primary struct: <unclustered>
//
// irq_prio_set @ 0x10dafc, size 42 bytes
// Doc: irq_prio_set [util]: Set NVIC interrupt priority with bounds check
// irq_prio_set [util]: Set NVIC interrupt priority with bounds check
int __fastcall irq_prio_set(int result)
{
  _DWORD *v1; // r1

  if ( result <= 7 )
  {
    v1 = off_10DB28;
    dword_40504080[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}

