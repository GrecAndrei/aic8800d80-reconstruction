// message_dispatch_n270 @ 0x134904, size 166 bytes
// Doc: message_dispatch_n270 [ipc]: Message dispatch tick incrementing message counter
// message_dispatch_n270 [ipc]: Message dispatch tick incrementing message counter
uint32_t *message_dispatch_n270()
{
  char *v0; // r5
  uint8_t *v1; // r8
  int v2; // r9
  int *v3; // r10
  int v4; // r4
  uint64_t v5; // r2
  __int16 v6; // lr
  int v7; // r0
  int v8; // r1
  uint64_t v9; // r2
  int v10; // r1
  uint64_t v11; // r2

  v0 = (char *)off_1349AC;
  v1 = off_1349B4;
  v2 = *((unsigned __int8 *)off_1349AC + 12);
  v3 = *((int **)off_1349B4 + 4);
  v4 = rf_bus_setup_n3a8(4098, 4, 6, 0x178u);
  sub_12ECB0(dword_1349B0);
  sub_12C964(6155, 6);
  v5 = *(QWORD *)(v0 + 4);
  v0[14] = 0;
  *(uint32_t *)(v4 + 352) = *(uint32_t *)v5;
  LOWORD(v0) = *(uint16_t *)(v5 + 4);
  *(uint32_t *)v4 = *(uint32_t *)HIDWORD(v5);
  v6 = *(uint16_t *)(HIDWORD(v5) + 4);
  *(uint8_t *)(v4 + 367) = 1;
  v7 = *v3;
  v8 = v3[1];
  v9 = *((QWORD *)v3 + 1);
  *(uint16_t *)(v4 + 356) = (uint16_t)v0;
  *(uint16_t *)(v4 + 4) = v6;
  *(uint32_t *)(v4 + 252) = v7;
  *(uint32_t *)(v4 + 256) = v8;
  *(QWORD *)(v4 + 260) = v9;
  v10 = v3[5];
  v11 = *((QWORD *)v3 + 3);
  *(uint32_t *)(v4 + 268) = v3[4];
  *(uint32_t *)(v4 + 272) = v10;
  *(QWORD *)(v4 + 276) = v11;
  *(uint8_t *)(v4 + 284) = v3[8];
  *(uint8_t *)(v4 + 368) = 1;
  *(uint16_t *)(v4 + 364) = 0;
  *(uint32_t *)(v4 + 360) = 0;
  *(uint8_t *)(v4 + 366) = *((uint8_t *)v3 + 61);
  if ( v2 )
    *(uint8_t *)(v4 + 3) |= 1u;
  v1[32] = v2;
  sub_12CBB4(v4);
  return rf_bus_mark_n_3b7(6u, 2);
}

