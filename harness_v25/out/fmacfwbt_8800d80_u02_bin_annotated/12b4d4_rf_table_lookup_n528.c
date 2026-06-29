// fwstruct annotate: 12b4d4_rf_table_lookup_n528.c
// rf_table_lookup_n528 @ 0x12b4d4, size 218 bytes
// Doc: rf_table_lookup_n528 [rf]: Index into RF parameter table (0x528 stride) by entry id
// rf_table_lookup_n528 [rf]: Index into RF parameter table (0x528 stride) by entry id
int __fastcall rf_table_lookup_n528(int a1, int a2, int a3)
{
  int v3; // r9
  int v4; // r3
  int v6; // r5
  int v9; // r3
  int v10; // r0
  int result; // r0
  int v12; // r4
  _WORD *v13; // lr
  int v14; // r1
  __int64 v15; // kr00_8
  __int16 v16; // r5
  int v17; // r9
  int v18; // r0
  int v19; // r9

  v3 = dword_12B5B4;
  v4 = dword_12B5B4 + 1320 * a1;
  v6 = *(unsigned __int8 *)(v4 + 116);
  if ( *(_BYTE *)(v4 + 1224) )
  {
    result = sub_119084(1, 26);
    v12 = result;
    if ( result )
    {
LABEL_5:
      v13 = off_12B5B8;
      v14 = dword_12B5B0 + 696 * v6;
      v15 = *(_QWORD *)(result + 72);
      v16 = *((_WORD *)off_12B5B8 + 254);
      *(_DWORD *)(v15 + 112) = *(_DWORD *)(v14 + 38);
      v17 = v3 + 1320 * a1;
      *(_BYTE *)(v15 + 108) = 64;
      *(_WORD *)(v15 + 116) = *(_WORD *)(v14 + 42);
      v18 = *(_DWORD *)(v17 + 100);
      LOWORD(v17) = *(_WORD *)(v17 + 104);
      *(_DWORD *)(v15 + 118) = v18;
      LOWORD(v18) = *(_WORD *)(v14 + 42);
      *(_WORD *)(v15 + 122) = v17;
      ++v16;
      v19 = *(_DWORD *)(v14 + 38);
      *(_WORD *)(v15 + 128) = v18;
      *(_BYTE *)(v15 + 109) = 0;
      *(_BYTE *)(v15 + 110) = 0;
      *(_BYTE *)(v15 + 111) = 0;
      *(_DWORD *)(v15 + 124) = v19;
      v13[254] = v16;
      *(_BYTE *)(v15 + 132) = 0;
      *(_BYTE *)(v15 + 133) = 0;
      *(_WORD *)(v15 + 130) = 16 * v16;
      *(_DWORD *)(HIDWORD(v15) + 24) = 0;
      *(_BYTE *)(v12 + 28) = a1;
      *(_BYTE *)(v12 + 29) = *(_BYTE *)(v14 + 35);
      *(_DWORD *)(v12 + 88) = a2;
      *(_DWORD *)(v12 + 92) = a3;
      return sub_1190B4(v12, 5);
    }
  }
  else
  {
    v9 = *(_DWORD *)(v4 + 72);
    v10 = *(unsigned __int8 *)(v9 + 4);
    if ( *(_BYTE *)(v9 + 4) )
      v10 = 1;
    result = sub_119084(v10, 26);
    v12 = result;
    if ( result )
      goto LABEL_5;
  }
  return result;
}

