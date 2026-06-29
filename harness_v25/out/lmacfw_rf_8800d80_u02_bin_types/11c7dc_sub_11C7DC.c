// sub_11C7DC @ 0x11c7dc, size 48 bytes
int * sub_11C7DC(int a1)
{
  int v1; // r4
  int v2; // r6
  char v3; // r5
  int v4; // r7
  int v5; // r4
  int *result; // r0
  int v7; // r3

  v1 = dword_11C80C;
  v2 = dword_11C80C + 32 * a1;
  v3 = a1;
  v4 = 32 * a1;
  if ( *(uint8_t *)(v2 + 30) )
    timestamp_remove(dword_11C80C + 32 * a1);
  v5 = v1 + v4;
  result = sub_100200((int *)v2, 0, 0x20u);
  v7 = dword_11C810;
  *(uint32_t *)(v5 + 8) = v2;
  *(uint8_t *)(v5 + 28) = v3;
  *(uint32_t *)(v5 + 4) = v7;
  return result;
}

