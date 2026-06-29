// sub_11A72C @ 0x11a72c, size 132 bytes
int  sub_11A72C(unsigned __int16 *a1)
{
  int v1; // r3
  int *v2; // r2
  int v4; // r0
  int *v5; // r5
  int *v6; // r7
  int v7; // r6
  int v8; // r1
  int v9; // r5
  int *v10; // r0

  v1 = dword_11A7B4;
  v2 = *(int **)off_11A7B0;
  v4 = *a1;
  v5 = (int *)off_11A7B8;
  v6 = (int *)off_11A7BC;
  v7 = a1[2];
  *v2 = **(uint32_t **)off_11A7B0 & dword_11A7B4 | (v4 << 12);
  *v5 = *v5 & v1 | (v4 << 12);
  v8 = a1[1];
  v2[1] = v2[1] & v1 | (v8 << 12);
  v9 = a1[3];
  *v6 = *v6 & v1 | (v8 << 12);
  v2[2] = v2[2] & v1 | (v7 << 12);
  v10 = (int *)off_11A7C0;
  v6[1] = v6[1] & v1 | (v7 << 12);
  v2[3] = v2[3] & v1 | (v9 << 12);
  *v10 = v1 & *v10 | (v9 << 12);
  sub_1183A0();
  sub_11F504(dword_11A7C4, *a1);
  return 0;
}

