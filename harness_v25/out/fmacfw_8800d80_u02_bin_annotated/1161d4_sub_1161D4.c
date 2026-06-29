// fwstruct annotate: 1161d4_sub_1161D4.c
// sub_1161D4 @ 0x1161d4, size 210 bytes
int sub_1161D4()
{
  int *v0; // r4
  int v1; // r8
  int v2; // r7
  _WORD *v3; // r5
  int v4; // r6
  int v5; // r0
  int v6; // r3
  int *v7; // r4
  int v8; // r7
  int v9; // r6
  int *v10; // r8
  int v11; // r5
  int result; // r0
  int v13; // r2
  int v14; // r1

  v0 = (int *)dword_1162A8;
  v1 = dword_1162B8;
  v2 = dword_1162AC;
  v3 = off_1162B0;
  v4 = dword_1162A8 + 2048;
  do
  {
    *v0 = v1;
    v0[1] = sub_101AD8() << 14;
    v5 = rf_chan_mask_get();
    v0[3] = 0;
    v0[4] = v2;
    v0[5] = 0;
    v0[6] = 0;
    v0[7] = 0;
    v0[8] = 0;
    v0[2] = v5;
    v0[9] = (unsigned __int16)(*v3 << 8) | (unsigned __int8)*(_DWORD *)v3;
    v0[10] = (unsigned __int16)(*v3 << 8) | (unsigned __int8)*(_DWORD *)v3;
    v0[11] = (unsigned __int16)(*v3 << 8) | (unsigned __int8)*(_DWORD *)v3;
    v6 = (unsigned __int16)(*v3 << 8) | (unsigned __int8)*(_DWORD *)v3;
    v0[14] = 4128768;
    v0[12] = v6;
    v0[13] = 8704;
    v0 += 16;
  }
  while ( v0 != (int *)v4 );
  v7 = (int *)dword_1162B4;
  v8 = dword_1162B8;
  v9 = dword_1162AC;
  v10 = (int *)off_1162B0;
  v11 = dword_1162B4 + 256;
  do
  {
    *v7 = v8;
    v7[1] = sub_101AD8() << 14;
    result = rf_chan_mask_get();
    v7[3] = 0;
    v7[4] = v9;
    v7[5] = 0;
    v7[6] = 0;
    v7[7] = 0;
    v7[8] = 0;
    v7[2] = result;
    v13 = *v10;
    v14 = *v10;
    v7[10] = 0;
    v7[9] = (unsigned __int16)((_WORD)v13 << 8) | (unsigned __int8)v14;
    v7[11] = 0;
    v7[12] = 0;
    v7[13] = 0;
    v7[14] = 4128768;
    v7 += 16;
  }
  while ( v7 != (int *)v11 );
  return result;
}

