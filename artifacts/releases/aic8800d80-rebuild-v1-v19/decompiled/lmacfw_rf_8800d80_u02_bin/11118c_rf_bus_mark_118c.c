// rf_bus_mark_118c @ 0x11118c, size 114 bytes
// Doc: rf_bus_reset2_n_150 [rf]: Second-stage RF bus reset using MMIO constants
// rf_bus_reset2_n_150 [rf]: Second-stage RF bus reset using MMIO constants
int rf_bus_mark_118c()
{
  int v0; // r3
  int *v1; // r2
  _DWORD *v2; // r1
  int result; // r0
  int v4; // r3
  int v5; // r1
  char *v6; // r3
  _DWORD *v7; // r4
  int v8; // r6
  __int64 v9; // kr00_8
  __int64 v10; // kr08_8

  v0 = *(_DWORD *)rf_bus_reset2_n_100;
  v1 = (int *)rf_bus_write2_n_31c;
  v2 = rf_bus_reset2_120c;
  *(_DWORD *)(v0 + 4) = *(_DWORD *)rf_bus_reset2_n_104;
  result = *v1;
  v2[709] = v0;
  v4 = *(_DWORD *)ipc_doorbell_handler_n40a;
  *(_BYTE *)(result + 3) |= 0xC0u;
  v5 = v4 + 3200;
  do
  {
    *(_BYTE *)(v4 + 3) |= 0xC0u;
    v4 += 8;
  }
  while ( v4 != v5 );
  v6 = (char *)off_111214;
  v7 = rf_bus_reset2_120c;
  v8 = *((_DWORD *)off_111214 + 2);
  v9 = *(_QWORD *)off_111214;
  *(_BYTE *)(*(_DWORD *)off_111214 + 3) |= 0xC0u;
  *(_BYTE *)(HIDWORD(v9) + 3) |= 0xC0u;
  v10 = *(_QWORD *)(v6 + 12);
  *(_BYTE *)(v8 + 3) |= 0xC0u;
  *(_BYTE *)(v10 + 3) |= 0xC0u;
  *(_BYTE *)(HIDWORD(v10) + 3) |= 0xC0u;
  v7[581] = result;
  return result;
}

