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
    *(_DWORD *)(v0 + 0x4) = sub_101AD8() << 14;
    v5 = rf_chan_mask_get();
    *(_DWORD *)(v0 + 0xc) = 0;
    *(_DWORD *)(v0 + 0x10) = v2;
    *(_DWORD *)(v0 + 0x14) = 0;
    *(_DWORD *)(v0 + 0x18) = 0;
    *(_DWORD *)(v0 + 0x1c) = 0;
    *(_DWORD *)(v0 + 0x20) = 0;
    *(_DWORD *)(v0 + 0x8) = v5;
    *(_DWORD *)(v0 + 0x24) = (unsigned __int16)(*v3 << 8) | (unsigned __int8)*(_DWORD *)v3;
    *(_DWORD *)(v0 + 0x28) = (unsigned __int16)(*v3 << 8) | (unsigned __int8)*(_DWORD *)v3;
    *(_DWORD *)(v0 + 0x2c) = (unsigned __int16)(*v3 << 8) | (unsigned __int8)*(_DWORD *)v3;
    v6 = (unsigned __int16)(*v3 << 8) | (unsigned __int8)*(_DWORD *)v3;
    *(_DWORD *)(v0 + 0x38) = 4128768;
    *(_DWORD *)(v0 + 0x30) = v6;
    *(_DWORD *)(v0 + 0x34) = 8704;
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
    *(_DWORD *)(v7 + 0x4) = sub_101AD8() << 14;
    result = rf_chan_mask_get();
    *(_DWORD *)(v7 + 0xc) = 0;
    *(_DWORD *)(v7 + 0x10) = v9;
    *(_DWORD *)(v7 + 0x14) = 0;
    *(_DWORD *)(v7 + 0x18) = 0;
    *(_DWORD *)(v7 + 0x1c) = 0;
    *(_DWORD *)(v7 + 0x20) = 0;
    *(_DWORD *)(v7 + 0x8) = result;
    v13 = *v10;
    v14 = *v10;
    *(_DWORD *)(v7 + 0x28) = 0;
    *(_DWORD *)(v7 + 0x24) = (unsigned __int16)((_WORD)v13 << 8) | (unsigned __int8)v14;
    *(_DWORD *)(v7 + 0x2c) = 0;
    *(_DWORD *)(v7 + 0x30) = 0;
    *(_DWORD *)(v7 + 0x34) = 0;
    *(_DWORD *)(v7 + 0x38) = 4128768;
    v7 += 16;
  }
  while ( v7 != (int *)v11 );
  return result;
}

