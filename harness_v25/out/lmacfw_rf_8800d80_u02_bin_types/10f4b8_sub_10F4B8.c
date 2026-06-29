// sub_10F4B8 @ 0x10f4b8, size 70 bytes
void __noreturn sub_10F4B8()
{
  uint64_t v0; // r0
  uint64_t v1; // kr00_8
  QWORD *v2; // r3

  v0 = *(QWORD *)(*(uint32_t *)off_10F500 + 32);
  v1 = *(QWORD *)(*(uint32_t *)off_10F500 + 24);
  v2 = off_10F504;
  *((uint32_t *)off_10F504 + 4) = *(uint32_t *)(*(uint32_t *)off_10F500 + 44);
  *v2 = v1;
  v2[1] = v0;
  sub_10C2E4();
}

