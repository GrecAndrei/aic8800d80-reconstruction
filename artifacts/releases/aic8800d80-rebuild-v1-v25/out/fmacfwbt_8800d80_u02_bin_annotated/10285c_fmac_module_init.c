// fwstruct annotate: 10285c_fmac_module_init.c
// fmac_module_init @ 0x10285c, size 52 bytes
// Doc: fmac_module_init [mac]: Initialize fmac module and dispatch to sub-init routine
// fmac_module_init [mac]: Initialize fmac module and dispatch to sub-init routine
void __noreturn fmac_module_init()
{
  sub_100AA8();
  sub_1009A0(0, 0x96Cu);
  rf_bus_write2_n_3aa();
}

