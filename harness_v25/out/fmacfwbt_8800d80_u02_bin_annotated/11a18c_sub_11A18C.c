// fwstruct annotate: 11a18c_sub_11A18C.c
// sub_11A18C @ 0x11a18c, size 264 bytes
int *sub_11A18C()
{
  _DWORD *v0; // r3
  __int64 v1; // kr00_8
  __int64 v2; // kr08_8
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

  v0 = off_11A298;
  if ( *(_DWORD *)off_11A298 != *(_DWORD *)off_11A294 )
  {
    v1 = *(_QWORD *)((char *)off_11A294 + 4);
    v2 = *(_QWORD *)((char *)off_11A294 + 12);
    *(_DWORD *)off_11A298 = *(_DWORD *)off_11A294;
    v0[1] = v1;
    v0[2] = HIDWORD(v1);
    v0[3] = v2;
    v0[4] = HIDWORD(v2);
  }
  v3 = (int **)off_11A298;
  v4 = (int *)dword_11A2A0;
  v5 = dword_11A2B0;
  v6 = dword_11A29C;
  memset_thunk((int *)dword_11A29C, 0, 0x30u);
  v7 = v3 + 6;
  do
  {
    v8 = *v3++;
    result = memset_thunk(v8, 0, 360 * *v4);
    v10 = *v4++;
    if ( v10 > 0 )
    {
      v11 = 0;
      v12 = 0;
      do
      {
        v13 = &(*(v3 - 1))[v11];
        v13[18] = dword_11A2A4;
        v13[43] = dword_11A2A8;
        *((_BYTE *)v13 + 155) = 5;
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
        *((_BYTE *)v13 + 152) = -124;
        *((_BYTE *)v13 + 153) = 0;
        *((_BYTE *)v13 + 154) = 0;
        v13[11] = 0;
        v13[16] = 0;
        v13[28] = 0;
        v13[33] = 0;
        v13[29] = 0;
        v13[85] = v6;
        v13[4] = v5;
        v13[21] = v5;
        v13[44] = sub_101954() << 14;
        v14 = sdio_buffer_prepare_n_32a();
        v15 = dword_11A2AC;
        v13[45] = v14;
        v13[46] = 0;
        v13[47] = v15;
        result = (int *)list_push_tail(v6);
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

