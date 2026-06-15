// irq_prio_set_dca4 @ 0x10dca4, size 42 bytes
// Doc: irq_prio_set_dca4 [util]: Sets interrupt priority (bounds check vs 7)
// irq_prio_set_dca4 [util]: Sets interrupt priority (bounds check vs 7)
int __fastcall irq_prio_set_dca4(int result)
{
  _DWORD *v1; // r1

  if ( result <= 7 )
  {
    v1 = off_10DCD0;
    dword_40504080[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}

