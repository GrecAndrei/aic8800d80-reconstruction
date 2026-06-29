// sub_119C0C @ 0x119c0c, size 264 bytes
int *sub_119C0C()
{
  uint32_t *v0; // r3
  uint64_t v1; // kr00_8
  uint64_t v2; // kr08_8
  int **v3; // r5
  int *v4; // r7
  int v5; // r8
  int v6; // r6
  int **v7; // r9
  int *v8; // t1
  int *result; // r0
  int v10; // t1
  int v11; // r11
  int v12; // r10
  int *v13; // r4
  int v14; // r0
  int v15; // r3

  v0 = off_119D18;
  if ( *(uint32_t *)off_119D18 != *(uint32_t *)off_119D14 )
  {
    v1 = *(QWORD *)((char *)off_119D14 + 4);
    v2 = *(QWORD *)((char *)off_119D14 + 12);
    *(uint32_t *)off_119D18 = *(uint32_t *)off_119D14;
    v0[1] = v1;
    v0[2] = HIDWORD(v1);
    v0[3] = v2;
    v0[4] = HIDWORD(v2);
  }
  v3 = (int **)off_119D18;
  v4 = (int *)dword_119D20;
  v5 = dword_119D30;
  v6 = dword_119D1C;
  sub_100200((int *)dword_119D1C, 0, 0x30u);
  v7 = v3 + 6;
  do
  {
    v8 = *v3++;
    result = sub_100200(v8, 0, 360 * *v4);
    v10 = *v4++;
    if ( v10 > 0 )
    {
      v11 = 0;
      v12 = 0;
      do
      {
        v13 = &(*(v3 - 1))[v11];
        v13[18] = dword_119D24;
        v13[43] = dword_119D28;
        *((uint8_t *)v13 + 155) = 5;
        v13[30] = (int)(v13 + 43);
        v13[25] = (int)(v13 + 38);
        v13[26] = (int)v13 + 175;
        v13[27] = 24;
        v13[34] = 1536;
        v13[35] = 323;
        v13[14] = 0;
        v13[15] = 0;
        v13[23] = 0;
        v13[24] = 0;
        v13[31] = 0;
        v13[32] = 0;
        *((uint8_t *)v13 + 152) = -124;
        *((uint8_t *)v13 + 153) = 0;
        *((uint8_t *)v13 + 154) = 0;
        v13[11] = 0;
        v13[16] = 0;
        v13[28] = 0;
        v13[33] = 0;
        v13[29] = 0;
        v13[85] = v6;
        v13[4] = v5;
        v13[21] = v5;
        v13[44] = sub_101A2C() << 14;
        v14 = sub_102AB0();
        v15 = dword_119D2C;
        v13[45] = v14;
        v13[46] = 0;
        v13[47] = v15;
        result = (int *)sub_12D108(v6);
        ++v12;
        v11 += 90;
      }
      while ( v12 < *(v4 - 1) );
    }
    v6 += 8;
  }
  while ( v3 != v7 );
  return result;
}

