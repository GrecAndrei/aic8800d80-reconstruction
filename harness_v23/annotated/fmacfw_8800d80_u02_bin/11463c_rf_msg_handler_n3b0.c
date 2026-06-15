// v23 annotated: rf_msg_handler_n3b0 @ 0x11463c
// Original: 11463c_rf_msg_handler_n3b0.c
// Primary struct: <unclustered>
//
// rf_msg_handler_n3b0 @ 0x11463c, size 94 bytes
// Doc: rf_fault_dump_n_d8 [rf]: Dumps RF fault state to memory
// rf_fault_dump_n_d8 [rf]: Dumps RF fault state to memory
int __fastcall rf_msg_handler_n3b0(int a1)
{
  int *v1; // r3
  int v2; // r2
  int v3; // r4
  int v4; // r1
  int v5; // r0
  _BYTE *v6; // r1
  _DWORD *v8; // r1

  if ( *(_DWORD *)off_11469C )
  {
    v8 = rf_fault_dump_46b0;
    v1 = (int *)rf_fault_dump_n_94;
    *(_DWORD *)off_1146A0 = rf_fault_dump_n_94;
    v8[19] = 1;
    v3 = 2048;
    v4 = 1;
    v2 = 75;
  }
  else
  {
    v1 = *(int **)off_1146A0;
    v2 = 76;
    v3 = 4096;
    v4 = 2;
  }
  v5 = a1 << 15;
  if ( *(_BYTE *)(*(_DWORD *)rf_mem_read_n456 + 6) == 1 )
    *((_DWORD *)off_1146A8 + 83) |= v4;
  v6 = rf_bus_reset2_n142;
  *v1 = v5;
  v1[3] = 1;
  v1[2] = 3;
  v6[v2 + 768] = -20;
  *((_DWORD *)v6 + 2) = v3;
  return 236;
}

