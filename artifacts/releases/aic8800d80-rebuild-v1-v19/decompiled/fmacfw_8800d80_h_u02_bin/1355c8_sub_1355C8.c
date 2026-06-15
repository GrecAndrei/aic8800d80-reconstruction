// sub_1355C8 @ 0x1355c8, size 316 bytes
int __fastcall sub_1355C8(int result)
{
  int v1; // r4
  int v2; // r2
  int v3; // r3
  int v4; // r5
  int v5; // r2
  int v6; // r6
  __int16 v7; // r8
  int v8; // r7
  __int16 v9; // r3
  _WORD *v10; // r12
  int v11; // r3
  __int16 v12; // r1
  int v13; // r2
  int v14; // r0
  __int16 v15; // r6
  int v16; // r4
  int v17; // r4
  int v18; // r3
  int v19; // r2
  int v20; // r1
  __int64 v21; // r2
  int v22; // [sp+4h] [bp-10h] BYREF
  int v23; // [sp+8h] [bp-Ch]
  __int16 v24; // [sp+Ch] [bp-8h]

  v1 = dword_135704 + 1320 * *(unsigned __int8 *)(result + 8);
  v2 = *(unsigned __int8 *)(v1 + 108);
  v22 = 0;
  v23 = 0;
  v24 = 0;
  if ( v2 )
  {
    if ( !*(_BYTE *)(v1 + 106) )
    {
      v3 = *(unsigned __int8 *)(result + 7);
      v4 = result;
      if ( v3 != 255 )
      {
        v5 = *(unsigned __int8 *)(v1 + 116);
        if ( v5 == v3 )
        {
          v6 = dword_135708 + 696 * v5;
          if ( *(_BYTE *)(v6 + 52) == 2 && !*(_BYTE *)(result + 13) )
          {
            v7 = *(_WORD *)(result + 14);
            result = sub_118B04(*(unsigned __int8 *)(result + 6) != 0, 512);
            v8 = result;
            if ( result )
            {
              v9 = *(_WORD *)(v4 + 4);
              LOBYTE(v22) = *(_BYTE *)(v4 + 6);
              LOWORD(v23) = v9;
              HIWORD(v22) = v9;
              sub_12C3F8(v1, result, (unsigned __int8 *)&v22);
              v10 = off_13570C;
              v11 = *(_DWORD *)(v8 + 72);
              v12 = *((_WORD *)off_13570C + 254);
              v13 = v6 + 38;
              *(_DWORD *)(v11 + 112) = *(_DWORD *)(v6 + 38);
              *(_BYTE *)(v11 + 108) = -48;
              *(_WORD *)(v11 + 116) = *(_WORD *)(v6 + 42);
              ++v12;
              v14 = *(_DWORD *)(v1 + 100);
              v15 = *(_WORD *)(v1 + 104);
              v16 = *(_DWORD *)v13;
              *(_DWORD *)(v11 + 118) = v14;
              LOWORD(v14) = *(_WORD *)(v13 + 4);
              *(_BYTE *)(v11 + 109) = 0;
              *(_BYTE *)(v11 + 110) = 0;
              *(_BYTE *)(v11 + 111) = 0;
              *(_WORD *)(v11 + 122) = v15;
              *(_DWORD *)(v11 + 124) = v16;
              *(_WORD *)(v11 + 128) = v14;
              v10[254] = v12;
              *(_WORD *)(v11 + 130) = 16 * v12;
              *(_BYTE *)(v8 + 28) = *(_BYTE *)(v4 + 8);
              *(_BYTE *)(v8 + 29) = *(_BYTE *)(v4 + 7);
              v17 = v11 + 108;
              *(_BYTE *)(v8 + 51) = 0;
              *(_BYTE *)(v8 + 53) = 0;
              sub_13C558(v8, 208, 8);
              sub_13AF60(v8, v17, 24);
              v18 = *(unsigned __int8 *)(v8 + 51) + 24;
              v19 = v18 + v17;
              *(_BYTE *)(v18 + v17) = 8;
              *(_BYTE *)(v19 + 1) = 1;
              v20 = *(_DWORD *)(v8 + 76);
              *(_WORD *)(v19 + 2) = v7;
              HIDWORD(v21) = v18 + *(unsigned __int8 *)(v8 + 53) + 4;
              LODWORD(v21) = *(_DWORD *)(v20 + 28) - 1 + HIDWORD(v21);
              HIDWORD(v21) += 4;
              *(_QWORD *)(v20 + 32) = v21;
              return sub_118B34(v8, 5);
            }
          }
        }
      }
    }
  }
  return result;
}

