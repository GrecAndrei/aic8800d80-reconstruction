// fwstruct annotate: 1029e4_fmac_init_step.c
// fmac_init_step @ 0x1029e4, size 52 bytes
// Doc: fmac_init_step [util]: FMAC firmware init step
// fmac_init_step [util]: FMAC firmware init step
void __noreturn fmac_init_step()
{
  mmio_set_clock_gate_bit();
  sub_1009A0(0, 0x96Cu);
  sub_102960();
}

