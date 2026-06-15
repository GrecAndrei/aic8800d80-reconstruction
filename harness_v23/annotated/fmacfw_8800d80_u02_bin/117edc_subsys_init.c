// v23 annotated: subsys_init @ 0x117edc
// Original: 117edc_subsys_init.c
// Primary struct: <unclustered>
//
// subsys_init @ 0x117edc, size 56 bytes
// Doc: subsys_init [util]: Initializes subsystem via callback registration
// subsys_init [util]: Initializes subsystem via callback registration
int subsys_init()
{
  int v0; // r4

  v0 = dword_117F14;
  memset_thunk((int *)dword_117F14, 0, 0x28u);
  sub_12D240(v0);
  sub_12D240(v0 + 8);
  sub_12D240(v0 + 16);
  sub_12D240(v0 + 24);
  return sub_12D240(v0 + 32);
}

