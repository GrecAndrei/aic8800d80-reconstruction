// v23 annotated: mmio_syscfg_init_n4 @ 0x124914
// Original: 124914_mmio_syscfg_init_n4.c
// Primary struct: <unclustered>
//
// mmio_syscfg_init_n4 @ 0x124914, size 32 bytes
// Doc: mmio_syscfg_init_n4 [mmio]: Initialize SYSCFG/clock MMIO registers
// mmio_syscfg_init_n4 [mmio]: Initialize SYSCFG/clock MMIO registers
int mmio_syscfg_init_n4()
{
  int *v0; // r1
  int v1; // r0

  v0 = (int *)off_124938;
  v1 = dword_12493C;
  *(_DWORD *)off_124934 |= 0x10u;
  *v0 = v1;
  mmio_init_clock_gate_n121();
  msg_parse(dword_124940);
  return 0;
}

