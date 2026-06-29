// sub_1301B8 @ 0x1301b8, size 108 bytes
int  sub_1301B8(int a1)
{
  uint8_t *v1; // r3
  int v2; // r2
  int v3; // r0
  char v4; // lr
  char v5; // r9
  char v6; // r8
  char v7; // r5
  int v8; // r7
  int v9; // r6
  char v10; // r4
  char v11; // r12
  char v12; // r1

  v1 = off_130224;
  v2 = *((char *)off_130224 + 2) + 7;
  v3 = a1 + 7;
  v4 = *(uint8_t *)(dword_13022C + v2);
  v5 = *(uint8_t *)(dword_130228 + v2 + 16);
  v6 = *(uint8_t *)(dword_130228 + v2 + 32);
  v7 = *(uint8_t *)(dword_130228 + v3 + 16);
  v8 = dword_13022C + v2;
  LOBYTE(v2) = *(uint8_t *)(dword_130228 + v3) - *(uint8_t *)(dword_130228 + v2);
  v9 = dword_13022C + v3;
  v10 = *(uint8_t *)(dword_130228 + v3 + 32);
  LOBYTE(v3) = *(uint8_t *)(dword_13022C + v3);
  v11 = *(uint8_t *)(v8 + 16);
  v12 = *(uint8_t *)(v9 + 16);
  LOBYTE(v8) = *(uint8_t *)(v8 + 32);
  *((uint8_t *)off_130224 + 8) = v2;
  LOBYTE(v2) = *(uint8_t *)(v9 + 32) - v8;
  v1[9] = v7 - v5;
  v1[10] = v10 - v6;
  v1[11] = v3 - v4;
  v1[12] = v12 - v11;
  v1[13] = v2;
  return sub_102A24();
}

