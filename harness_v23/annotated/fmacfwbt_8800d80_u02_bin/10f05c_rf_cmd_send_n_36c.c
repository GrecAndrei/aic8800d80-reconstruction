// v23 annotated: rf_cmd_send_n_36c @ 0x10f05c
// Original: 10f05c_rf_cmd_send_n_36c.c
// Primary struct: log_state (cluster 11, 4 funcs)
// Fields: enable=0x0, state=0x0, level=0x4, flag=0x7, count=0x8, tick=0xa, buf=0x14, status=0x16a
//
// rf_cmd_send_n_36c @ 0x10f05c, size 74 bytes
// Doc: rf_cmd_send_n_36c [mac]: Send RF command 0x22 reading window length from MMIO
// rf_cmd_send_n_36c [mac]: Send RF command 0x22 reading window length from MMIO
void __noreturn rf_cmd_send_n_36c()
{
  int v0; // r2
  __int64 v1; // kr00_8
  char *v2; // r3
  __int64 v3; // r0
  int v4; // r4
  int v5; // r2
  __int64 v6; // kr10_8

  v0 = *(_DWORD *)off_10F0A8;
  v1 = *(_QWORD *)(*(_DWORD *)off_10F0A8 + 24);
  v2 = (char *)off_10F0AC;
  LODWORD(v3) = *(_DWORD *)(*(_DWORD *)off_10F0A8 + 36);
  v4 = *(_DWORD *)(*(_DWORD *)off_10F0A8 + 32);
  *(_DWORD *)off_10F0AC = v1;
  v6 = *(_QWORD *)(v0 + 40);
  v5 = *(_DWORD *)(v0 + 44);
  HIDWORD(v3) = v6;
  *((_DWORD *)v2 + 1) = HIDWORD(v1);
  *((_DWORD *)v2 + 2) = v4;
  *(_QWORD *)(v2 + 12) = v3;
  *((_DWORD *)v2 + 5) = v5;
  phy_rf_init_2d0();
}

