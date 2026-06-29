// sub_111884 @ 0x111884, size 114 bytes
// Doc: rf_bus_mark_owner_n62 [rf]: Mark RF bus n62 as owned: set request+grant bits (0xc0) in bus state and record owner id.
// rf_bus_mark_owner_n62 [rf]: Mark RF bus n62 as owned: set request+grant bits (0xc0) in bus state and record owner id.
int sub_111884()
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

  v0 = *(uint32_t *)off_1118FC;
  v1 = (int *)off_111900;
  v2 = off_111904;
  *(uint32_t *)(v0 + 4) = *(uint32_t *)off_1118F8;
  result = *v1;
  v2[709] = v0;
  v4 = *(uint32_t *)off_111908;
  *(uint8_t *)(result + 3) |= 0xC0u;
  v5 = v4 + 3200;
  do
  {
    *(uint8_t *)(v4 + 3) |= 0xC0u;
    v4 += 8;
  }
  while ( v4 != v5 );
  v6 = (char *)off_11190C;
  v7 = off_111904;
  v8 = *((uint32_t *)off_11190C + 2);
  v9 = *(QWORD *)off_11190C;
  *(uint8_t *)(*(uint32_t *)off_11190C + 3) |= 0xC0u;
  *(uint8_t *)(HIDWORD(v9) + 3) |= 0xC0u;
  v10 = *(QWORD *)(v6 + 12);
  *(uint8_t *)(v8 + 3) |= 0xC0u;
  *(uint8_t *)(v10 + 3) |= 0xC0u;
  *(uint8_t *)(HIDWORD(v10) + 3) |= 0xC0u;
  v7[581] = result;
  return result;
}

