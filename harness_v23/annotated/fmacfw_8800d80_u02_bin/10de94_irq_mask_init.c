// v23 annotated: irq_mask_init @ 0x10de94
// Original: 10de94_irq_mask_init.c
// Primary struct: <unclustered>
//
// irq_mask_init @ 0x10de94, size 94 bytes
// Doc: irq_mask_init [util]: Initialize IRQ masks via enable/disable
// irq_mask_init [util]: Initialize IRQ masks via enable/disable
int irq_mask_init()
{
  _DWORD *v0; // r1
  _DWORD *v1; // r3
  int result; // r0

  irq_prio_set_dca4(1);
  sub_10DCEC(1);
  irq_prio_set_dca4(2);
  sub_10DCEC(2);
  if ( *((_BYTE *)off_10DEF4 + 369) )
  {
    rf_mem_read_n47e(1);
    rf_mem_read_n47e(2);
  }
  else
  {
    sub_10DD14(1);
    sub_10DD14(2);
  }
  mmio_bit_clear_n0e0(3);
  sub_10DD44(3, 2, dword_10DEF8);
  v0 = off_10DEFC;
  v1 = off_10DF04;
  result = dword_10DF08;
  *((_DWORD *)off_10DEFC + 1) = off_10DF00;
  v1[1] = result;
  v1[2] = 0;
  v0[2] = 0;
  return result;
}

