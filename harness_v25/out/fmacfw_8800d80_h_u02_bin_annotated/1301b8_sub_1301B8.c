// fwstruct annotate: 1301b8_sub_1301B8.c
// sub_1301B8 @ 0x1301b8, size 108 bytes
int __fastcall sub_1301B8(int a1)
{
  _BYTE *v1; // r3
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
  v4 = *(_BYTE *)(dword_13022C + v2);
  v5 = *(_BYTE *)(dword_130228 + v2 + 16);
  v6 = *(_BYTE *)(dword_130228 + v2 + 32);
  v7 = *(_BYTE *)(dword_130228 + v3 + 16);
  v8 = dword_13022C + v2;
  LOBYTE(v2) = *(_BYTE *)(dword_130228 + v3) - *(_BYTE *)(dword_130228 + v2);
  v9 = dword_13022C + v3;
  v10 = *(_BYTE *)(dword_130228 + v3 + 32);
  LOBYTE(v3) = *(_BYTE *)(dword_13022C + v3);
  v11 = *(_BYTE *)(v8 + 16);
  v12 = *(_BYTE *)(v9 + 16);
  LOBYTE(v8) = *(_BYTE *)(v8 + 32);
  *((_BYTE *)off_130224 + 8) = v2;
  LOBYTE(v2) = *(_BYTE *)(v9 + 32) - v8;
  v1[9] = v7 - v5;
  v1[10] = v10 - v6;
  v1[11] = v3 - v4;
  v1[12] = v12 - v11;
  v1[13] = v2;
  return sub_102A24();
}

