// sub_141DE8 @ 0x141de8, size 66 bytes
int  sub_141DE8(int a1, int a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r2

  v3 = *(uint32_t *)(a1 + 24)
     - 400
     - *(uint32_t *)(a1 + 48) * a2
     - *(uint32_t *)(dword_141E2C + 1320 * *(unsigned __int8 *)(a1 + 47) + 40);
  v4 = sub_12C068();
  v5 = *((uint32_t *)off_141E30 + 4);
  *(uint32_t *)(a1 + 56) = dword_141E34;
  return timestamp_update_4f60(a1 + 52, v5 + v3 - v4);
}

