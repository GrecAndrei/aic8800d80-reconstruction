// v23 annotated: irq_prio_set_db48 @ 0x10db48
// Original: 10db48_irq_prio_set_db48.c
// Primary struct: <unclustered>
//
// irq_prio_set_db48 @ 0x10db48, size 42 bytes
// Doc: irq_prio_set_db48 [util]: Set interrupt priority (validate irq < 8)
// irq_prio_set_db48 [util]: Set interrupt priority (validate irq < 8)
int __fastcall irq_prio_set_db48(int result)
{
  _DWORD *v1; // r1

  if ( result <= 7 )
  {
    v1 = off_10DB74;
    dword_40504080[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}

