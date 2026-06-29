// sub_10F204 @ 0x10f204, size 74 bytes
void __noreturn sub_10F204()
{
  int v0; // r2
  uint64_t v1; // kr00_8
  char *v2; // r3
  uint64_t v3; // r0
  int v4; // r4
  int v5; // r2
  uint64_t v6; // kr10_8

  v0 = *(uint32_t *)off_10F250;
  v1 = *(QWORD *)(*(uint32_t *)off_10F250 + 24);
  v2 = (char *)off_10F254;
  LODWORD(v3) = *(uint32_t *)(*(uint32_t *)off_10F250 + 36);
  v4 = *(uint32_t *)(*(uint32_t *)off_10F250 + 32);
  *(uint32_t *)off_10F254 = v1;
  v6 = *(QWORD *)(v0 + 40);
  v5 = *(uint32_t *)(v0 + 44);
  HIDWORD(v3) = v6;
  *((uint32_t *)v2 + 1) = HIDWORD(v1);
  *((uint32_t *)v2 + 2) = v4;
  *(QWORD *)(v2 + 12) = v3;
  *((uint32_t *)v2 + 5) = v5;
  phy_rf_init();
}

