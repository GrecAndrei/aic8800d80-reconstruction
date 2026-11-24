// sub_118AB0 @ 0x118ab0, size 228 bytes
int __fastcall sub_118AB0(int a1)
{
  int v2; // r4
  _DWORD *v3; // r6
  _DWORD *v4; // r5
  int v5; // r11
  int v6; // r10
  int v7; // r9
  int v8; // r8
  _DWORD *v9; // r6
  int v10; // r8
  int v11; // r0
  int *v12; // r5
  int v13; // r7
  int result; // r0

  v2 = dword_118B98;
  v3 = (_DWORD *)dword_118B9C;
  v4 = (_DWORD *)dword_118BA0;
  v5 = dword_118BB0;
  v6 = dword_118BB4;
  v7 = dword_118B94;
  sub_12D240(dword_118B94);
  sub_12D240(v7 + 8);
  v8 = v2 + 400;
  do
  {
    if ( !a1 || !*(_BYTE *)(v2 + 97) )
    {
      sub_100200((int *)v2, 0, 0x64u);
      *(_DWORD *)(v2 + 44) = v3 + 11;
      *(_DWORD *)(v2 + 72) = v3;
      *(_DWORD *)(v2 + 76) = v4;
      *(_DWORD *)(v4 + 0x34) = 0;
      *(_DWORD *)(v4 + 0x38) = 0;
      *(_DWORD *)(v3 + 0x60) = 0;
      *(_DWORD *)(v3 + 0x64) = 0;
      *(_DWORD *)(v4 + 0xc) = v5;
      *(_DWORD *)(v3 + 0x2c) = v6;
      *(_BYTE *)(v2 + 96) = 0;
      *(_DWORD *)(v4 + 0x28) = 0;
      *(_DWORD *)(v4 + 0x3c) = 0;
      *(_DWORD *)(v4 + 0x1c) = v3 + 27;
      sub_12D248(v7);
    }
    v2 += 100;
    v3 += 155;
    v4 += 20;
  }
  while ( v2 != v8 );
  v9 = off_118BA4;
  v10 = dword_118BB4;
  *(_DWORD *)off_118BA4 = dword_118BB4;
  *(_DWORD *)(v9 + 0x34) = 0;
  *(_DWORD *)(v9 + 0x38) = 0;
  *(_DWORD *)(v9 + 0x3c) = 0;
  *(_DWORD *)(v9 + 0x4) = sub_101AD8() << 14;
  v11 = sub_102B60();
  v12 = (int *)off_118BA8;
  v13 = dword_118BAC;
  *(_DWORD *)(v9 + 0x8) = v11;
  *(_DWORD *)(v9 + 0x10) = v13;
  *(_DWORD *)(v9 + 0x14) = 1024;
  *(_DWORD *)(v9 + 0x18) = 0;
  *(_DWORD *)(v9 + 0x1c) = 0;
  *(_DWORD *)(v9 + 0xc) = 0;
  *(_DWORD *)(v9 + 0x20) = 0;
  *v12 = v10;
  *(_DWORD *)(v9 + 0x28) = 0;
  *(_DWORD *)(v9 + 0x2c) = 0;
  *(_DWORD *)(v12 + 0x34) = 0;
  *(_DWORD *)(v12 + 0x38) = 0;
  *(_DWORD *)(v9 + 0x30) = 0;
  *(_DWORD *)(v12 + 0x3c) = 0;
  *(_DWORD *)(v12 + 0x4) = sub_101AD8() << 14;
  result = sub_102B60();
  *(_DWORD *)(v12 + 0x8) = result;
  *(_DWORD *)(v12 + 0xc) = 0;
  *(_DWORD *)(v12 + 0x18) = 0;
  *(_DWORD *)(v12 + 0x1c) = 0;
  *(_DWORD *)(v12 + 0x28) = 0;
  *(_DWORD *)(v12 + 0x2c) = 0;
  *(_DWORD *)(v12 + 0x10) = v13;
  *(_DWORD *)(v12 + 0x20) = 0;
  *(_DWORD *)(v12 + 0x30) = 0;
  *(_DWORD *)(v12 + 0x14) = 4;
  return result;
}

