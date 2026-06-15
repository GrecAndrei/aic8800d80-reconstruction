// v23 annotated: sub_10DCEC @ 0x10dcec
// Original: 10dcec_sub_10DCEC.c
// Primary struct: <unclustered>
//
// sub_10DCEC @ 0x10dcec, size 94 bytes
int sub_10DCEC()
{
  _DWORD *v0; // r1
  _DWORD *v1; // r3
  int result; // r0

  irq_prio_set(1);
  irq_prio_set2(1);
  irq_prio_set(2);
  irq_prio_set2(2);
  if ( *((_BYTE *)off_10DD4C + 369) )
  {
    irq_enable(1);
    irq_enable(2);
  }
  else
  {
    sub_10DB6C(1);
    sub_10DB6C(2);
  }
  mmio_reg_bit_clear(3);
  irq_config(3, 2, dword_10DD50);
  v0 = off_10DD54;
  v1 = off_10DD5C;
  result = dword_10DD60;
  *((_DWORD *)off_10DD54 + 1) = off_10DD58;
  v1[1] = result;
  v1[2] = 0;
  v0[2] = 0;
  return result;
}

