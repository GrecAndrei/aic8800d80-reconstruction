// sub_12A818 @ 0x12a818, size 264 bytes
// Doc: sub_122A818 [mac]: Indexed table lookup on 0x190d48 struct by id at offset 0x4c9
// sub_122A818 [mac]: Indexed table lookup on 0x190d48 struct by id at offset 0x4c9
int __fastcall sub_12A818(int a1, int a2, char a3, char a4, unsigned int a5, int a6, int a7)
{
  int v7; // r6
  int v8; // r7
  unsigned __int8 *v9; // r4
  int v10; // r9
  unsigned __int8 *v11; // r5
  int v13; // r0
  int v14; // r10
  int v15; // lr
  bool v16; // zf
  int v17; // r1
  char v18; // r11
  char v19; // r11
  char v20; // r4
  int v21; // r7

  v7 = dword_12A920;
  v8 = *(unsigned __int8 *)(a1 + 1225);
  v9 = (unsigned __int8 *)(dword_12A920 + 140 * v8);
  if ( v9[112] != 1 )
    return 255;
  v10 = v9[16];
  v11 = (unsigned __int8 *)(dword_12A920 + 140 * v8);
  if ( v9[16] )
  {
    if ( v9[64] )
      return 255;
    v10 = 1;
    v13 = 140 * v8 + 48 + dword_12A920;
    v14 = 1;
  }
  else
  {
    v13 = dword_12A920 + 140 * v8;
    v14 = v9[16];
  }
  v15 = dword_12A920 + 140 * v8;
  v16 = a2 == 0;
  v17 = dword_12A920 + 140 * v8 + 48 * v14;
  v18 = *(_BYTE *)(v15 + 121);
  *(_BYTE *)(v17 + 19) = a4;
  *(_BYTE *)(v17 + 20) = a4;
  *(_DWORD *)(v17 + 28) = a5;
  v19 = v18 + 1;
  *(_DWORD *)(v17 + 24) = a6;
  v20 = v16;
  *(_DWORD *)(v17 + 36) = a7;
  *(_BYTE *)(v17 + 33) = a3;
  *(_BYTE *)(v17 + 32) = v20;
  *(_BYTE *)(v15 + 121) = v19;
  if ( !v16 )
    ++*(_BYTE *)(v15 + 122);
  if ( a5 )
    *(_DWORD *)(140 * v8 + 48 * v14 + v7 + 40) = 0x80000000 / a5 - 1;
  timestamp_update_4f60(v13, a7);
  v21 = 140 * v8;
  *(_BYTE *)(v7 + v21 + 48 * v14 + 16) = 1;
  sub_125EFC(*(unsigned __int8 *)(v21 + v7 + 113), 3);
  sub_129768((int)v11, v10);
  sub_1297BC((int)v11);
  sub_129A28(v11);
  return v10;
}

