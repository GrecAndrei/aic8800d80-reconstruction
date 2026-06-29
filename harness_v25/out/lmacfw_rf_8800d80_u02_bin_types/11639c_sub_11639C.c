// sub_11639C @ 0x11639c, size 252 bytes
int  sub_11639C(int a1)
{
  int v2; // r5
  uint32_t *v3; // r4
  uint32_t *v4; // r11
  int v5; // r7
  int v6; // r10
  int v7; // r9
  int v8; // r8
  uint32_t *v9; // r6
  int v10; // r8
  int v11; // r0
  int *v12; // r5
  int v13; // r7
  int result; // r0
  int v15; // r3
  int v16; // r2
  uint32_t *v17; // r1
  int v18; // r0

  v2 = dword_11649C;
  v3 = (uint32_t *)dword_1164A0;
  v4 = (uint32_t *)dword_1164B8;
  v5 = dword_1164A4;
  v6 = dword_1164BC;
  v7 = dword_1164C0;
  v8 = dword_116498;
  sub_11E71C(dword_116498);
  sub_11E71C(v8 + 8);
  do
  {
    if ( !a1 || !*(uint8_t *)(v2 + 53) )
    {
      sub_100200((int *)v2, 0, 0x38u);
      v15 = 0;
      *(uint32_t *)(v2 + 28) = v3;
      *(uint32_t *)(v2 + 32) = v4;
      v4[12] = 0;
      v4[13] = 0;
      v3[24] = 0;
      v3[25] = 0;
      v16 = dword_1164B4;
      v4[6] = v3 + 26;
      v4[2] = v6;
      v3[11] = v7;
      *(uint8_t *)(v2 + 52) = 0;
      v4[9] = 0;
      v4[14] = 0;
      v17 = v3 + 25;
      do
      {
        v18 = v16 | v15++;
        v17[1] = v18;
        ++v17;
        v16 -= 0x10000;
      }
      while ( v15 != 1024 );
      sub_11E724(v8);
    }
    v3 += 1050;
    v2 += 56;
    v4 += 19;
  }
  while ( v3 != (uint32_t *)v5 );
  v9 = off_1164A8;
  v10 = dword_1164C0;
  *(uint32_t *)off_1164A8 = dword_1164C0;
  v9[1] = sub_101A9C() << 14;
  v11 = sub_1029BC();
  v12 = (int *)off_1164AC;
  v13 = dword_1164B0;
  v9[2] = v11;
  v9[5] = 1024;
  v9[6] = 0;
  v9[7] = 0;
  v9[10] = 0;
  v9[11] = 0;
  *v12 = v10;
  v9[3] = 0;
  v9[8] = 0;
  v9[12] = 0;
  v9[4] = v13;
  v12[1] = sub_101A9C() << 14;
  result = sub_1029BC();
  v12[2] = result;
  v12[3] = 0;
  v12[6] = 0;
  v12[7] = 0;
  v12[10] = 0;
  v12[11] = 0;
  v12[4] = v13;
  v12[8] = 0;
  v12[12] = 0;
  v12[5] = 4;
  return result;
}

