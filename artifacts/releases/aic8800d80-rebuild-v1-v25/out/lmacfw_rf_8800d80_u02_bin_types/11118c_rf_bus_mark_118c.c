// rf_bus_mark_118c @ 0x11118c, size 114 bytes
// Doc: rf_bus_reset2_n_150 [rf]: Second-stage RF bus reset using MMIO constants
// rf_bus_reset2_n_150 [rf]: Second-stage RF bus reset using MMIO constants
int rf_bus_mark_118c()
{
  int v0; // r3
  int *v1; // r2
  uint32_t *v2; // r1
  int result; // r0
  int v4; // r3
  int v5; // r1
  char *v6; // r3
  uint32_t *v7; // r4
  int v8; // r6
  uint64_t v9; // kr00_8
  uint64_t v10; // kr08_8

  v0 = *(uint32_t *)rf_bus_reset2_n_100;
  v1 = (int *)rf_bus_write2_n_31c;
  v2 = rf_bus_reset2_120c;
  *(uint32_t *)(v0 + 4) = *(uint32_t *)rf_bus_reset2_n_104;
  result = *v1;
  v2[709] = v0;
  v4 = *(uint32_t *)ipc_doorbell_handler_n40a;
  *(uint8_t *)(result + 3) |= 0xC0u;
  v5 = v4 + 3200;
  do
  {
    *(uint8_t *)(v4 + 3) |= 0xC0u;
    v4 += 8;
  }
  while ( v4 != v5 );
  v6 = (char *)off_111214;
  v7 = rf_bus_reset2_120c;
  v8 = *((uint32_t *)off_111214 + 2);
  v9 = *(QWORD *)off_111214;
  *(uint8_t *)(*(uint32_t *)off_111214 + 3) |= 0xC0u;
  *(uint8_t *)(HIDWORD(v9) + 3) |= 0xC0u;
  v10 = *(QWORD *)(v6 + 12);
  *(uint8_t *)(v8 + 3) |= 0xC0u;
  *(uint8_t *)(v10 + 3) |= 0xC0u;
  *(uint8_t *)(HIDWORD(v10) + 3) |= 0xC0u;
  v7[581] = result;
  return result;
}

