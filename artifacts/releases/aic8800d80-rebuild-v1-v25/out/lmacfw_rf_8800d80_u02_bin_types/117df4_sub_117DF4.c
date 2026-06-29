// sub_117DF4 @ 0x117df4, size 90 bytes
int sub_117DF4()
{
  uint8_t *v0; // r8
  int v1; // r4
  int v2; // r7
  int v3; // r6
  int result; // r0

  v0 = off_117E50;
  sub_100200((int *)off_117E50, 0, 0x14u);
  sub_11E71C(v0);
  v1 = dword_117E54;
  v2 = dword_117E58;
  sub_11E71C(v0 + 8);
  v3 = v1 + 896;
  do
  {
    sub_100200((int *)v1, 0, 0xE0u);
    *(uint8_t *)(v1 + 94) = 5;
    *(uint8_t *)(v1 + 97) = 127;
    *(uint32_t *)(v1 + 52) = v2;
    *(uint32_t *)(v1 + 56) = v1;
    v1 += 224;
    result = list_push_tail(v0);
  }
  while ( v1 != v3 );
  v0[16] = -1;
  return result;
}

