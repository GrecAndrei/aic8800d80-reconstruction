// v23 annotated: sub_119D4C @ 0x119d4c
// Original: 119d4c_sub_119D4C.c
// Primary struct: <unclustered>
//
// sub_119D4C @ 0x119d4c, size 264 bytes
int *sub_119D4C()
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

  v0 = off_119E58;
  if ( *(_DWORD *)off_119E58 != *(_DWORD *)off_119E54 )
  {
    v1 = *(_QWORD *)((char *)off_119E54 + 4);
    v2 = *(_QWORD *)((char *)off_119E54 + 12);
    *(_DWORD *)off_119E58 = *(_DWORD *)off_119E54;
    v0[1] = v1;
    v0[2] = HIDWORD(v1);
    v0[3] = v2;
    v0[4] = HIDWORD(v2);
  }
  v3 = (int **)off_119E58;
  v4 = (int *)dword_119E60;
  v5 = dword_119E70;
  v6 = dword_119E5C;
  memset_thunk((int *)dword_119E5C, 0, 0x30u);
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
        v13[18] = dword_119E64;
        v13[43] = dword_119E68;
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
        v13[44] = sub_101AD8() << 14;
        v14 = rf_chan_mask_get();
        v15 = dword_119E6C;
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

