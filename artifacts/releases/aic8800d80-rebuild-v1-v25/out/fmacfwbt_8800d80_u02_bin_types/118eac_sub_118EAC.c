// sub_118EAC @ 0x118eac, size 58 bytes
int  sub_118EAC(int a1, int a2, uint32_t *a3, int *a4)
{
  int v8; // r1
  int v9; // r2

  memset_thunk((int *)a1, 0, 0x64u);
  *(uint8_t *)(a1 + 96) = 1;
  v8 = dword_118EE8;
  v9 = dword_118EEC;
  *(uint32_t *)(a1 + 72) = a2;
  *(uint32_t *)(a1 + 44) = a4;
  *(uint32_t *)(a1 + 76) = a3;
  a3[13] = 0;
  a3[14] = 0;
  a3[7] = a2 + 108;
  a3[3] = v8;
  a3[10] = 0;
  a3[15] = 0;
  *a4 = v9;
  return a2 + 108;
}

