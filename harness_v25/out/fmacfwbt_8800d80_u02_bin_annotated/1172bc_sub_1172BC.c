// fwstruct annotate: 1172bc_sub_1172BC.c
// sub_1172BC @ 0x1172bc, size 124 bytes
int sub_1172BC()
{
  int v0; // r0
  int inited; // r0
  char *v2; // r5
  char *v3; // r6
  char *v4; // r0
  _DWORD *v5; // r5
  int result; // r0

  sub_11A18C();
  ipc_msg_handler_init();
  v0 = lmac_rf_helper_121BF38();
  sub_11831C(v0);
  inited = bt_subsystem_init_n_ef0(0);
  sub_11C1C8(inited);
  v2 = (char *)off_117338 + 12;
  memset_thunk((int *)off_117338, 0, 0x204u);
  v3 = v2 + 420;
  do
  {
    bt_xtal_init_check(v2);
    *((_DWORD *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((_DWORD *)v2 + 6) = 0;
    *((_DWORD *)v2 + 7) = 0;
    v4 = v2 + 16;
    v2 += 84;
    bt_xtal_init_check(v4);
  }
  while ( v2 != v3 );
  v5 = off_117338;
  bt_xtal_init_check((char *)off_117338 + 432);
  v5[114] = 0;
  v5[115] = 0;
  v5[105] = 0;
  *((_BYTE *)v5 + 446) = 0;
  *((_BYTE *)v5 + 500) = 0;
  result = bt_xtal_init_check(v5 + 112);
  *((_WORD *)v5 + 254) = 0;
  return result;
}

