// fwstruct annotate: 1323e4_sub_1323E4.c
// sub_1323E4 @ 0x1323e4, size 46 bytes
int sub_1323E4()
{
  _DWORD *v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0
  int inited; // r0

  memset_thunk((int *)dword_132414, 0, 0x17Cu);
  v0 = rf_bus_mark_n_3b7(5u, 0);
  v1 = sub_1376D4(v0);
  v2 = sub_136870(v1);
  v3 = sub_134650(v2);
  inited = ipc_queues_init_n(v3);
  return bt_init_subsystem_1240E38(inited);
}

