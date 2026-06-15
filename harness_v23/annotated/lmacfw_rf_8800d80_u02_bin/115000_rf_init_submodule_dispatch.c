// v23 annotated: rf_init_submodule_dispatch @ 0x115000
// Original: 115000_rf_init_submodule_dispatch.c
// Primary struct: <unclustered>
//
// rf_init_submodule_dispatch @ 0x115000, size 22 bytes
// Doc: rf_init_submodule_dispatch [rf]: Dispatches initialization calls to RF subsystem submodules
// rf_init_submodule_dispatch [rf]: Dispatches initialization calls to RF subsystem submodules
int rf_init_submodule_dispatch()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0

  v0 = nullsub_5();
  v1 = lmac_rf_state_check(v0);
  v2 = sdio_buffer_prepare_6ec(v1);
  return rf_cmd_dispatch_n_500(v2);
}

