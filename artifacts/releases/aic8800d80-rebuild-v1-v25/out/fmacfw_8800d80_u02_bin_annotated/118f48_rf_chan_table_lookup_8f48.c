// fwstruct annotate: 118f48_rf_chan_table_lookup_8f48.c
// rf_chan_table_lookup_8f48 @ 0x118f48, size 304 bytes
// Doc: rf_chan_table_lookup_8f48 [rf]: Look up RF channel entry by index from channel table
// rf_chan_table_lookup_8f48 [rf]: Look up RF channel entry by index from channel table
int __fastcall rf_chan_table_lookup_8f48(int a1, __int16 a2, int a3, int a4)
{
  int v4; // r11
  int v5; // r4
  int v7; // r7
  int v9; // r0
  int v12; // r2
  int v13; // r5
  int v14; // r7
  int v15; // r3
  int v16; // r4
  int v17; // r1
  int v18; // r12
  __int16 v19; // lr
  int v20; // r0
  __int16 v21; // r2
  char v22; // r3

  v4 = dword_119088;
  v5 = dword_119078;
  v7 = *(unsigned __int8 *)(dword_119088 + 696 * a1 + 34);
  v9 = *(_DWORD *)(dword_119078 + 1320 * v7 + 72);
  if ( !v9 )
  {
    if ( **(__int16 **)off_11907C >= 0 )
    {
LABEL_10:
      v13 = sub_118C44(1, 26);
      if ( !v13 )
        return 1;
      goto LABEL_4;
    }
LABEL_9:
    sub_12F46C(dword_119084, dword_119080, 520);
    goto LABEL_10;
  }
  v12 = *(unsigned __int8 *)(v9 + 4);
  if ( **(__int16 **)off_11907C < 0 && v12 == 2 )
    goto LABEL_9;
  v13 = sub_118C44((*(unsigned __int8 *)(dword_119078 + 1320 * v7 + 1224) | v12) != 0, 26);
  if ( !v13 )
    return 1;
LABEL_4:
  v14 = v5 + 1320 * v7;
  sub_12C4E8(v14, v13);
  v15 = v4 + 696 * a1;
  v16 = *(_DWORD *)(v13 + 72);
  v17 = *(_DWORD *)(v15 + 38);
  v18 = *(unsigned __int8 *)(v14 + 106);
  v19 = *(_WORD *)(v15 + 42);
  v20 = *(_DWORD *)(v14 + 100);
  v21 = *(_WORD *)(v14 + 104);
  *(_WORD *)(v16 + 122) = v21;
  *(_WORD *)(v16 + 116) = v19;
  *(_DWORD *)(v16 + 112) = v17;
  *(_DWORD *)(v16 + 118) = v20;
  *(_BYTE *)(v16 + 110) = 0;
  *(_BYTE *)(v16 + 111) = 0;
  if ( v18 )
  {
    *(_DWORD *)(v16 + 124) = *(_DWORD *)(v14 + 100);
    *(_WORD *)(v16 + 128) = v21;
    *(_BYTE *)(v16 + 108) = -56;
    *(_BYTE *)(v16 + 109) = 2;
  }
  else
  {
    *(_DWORD *)(v16 + 124) = v17;
    *(_WORD *)(v16 + 128) = v19;
    *(_BYTE *)(v16 + 108) = -56;
    *(_BYTE *)(v16 + 109) = 1;
  }
  v22 = *(_BYTE *)(v4 + 696 * a1 + 34);
  *(_WORD *)(v16 + 132) = a2;
  *(_BYTE *)(v16 + 130) = 0;
  *(_BYTE *)(v16 + 131) = 0;
  *(_DWORD *)(v13 + 88) = a3;
  *(_DWORD *)(v13 + 92) = a4;
  *(_BYTE *)(v13 + 28) = v22;
  *(_BYTE *)(v13 + 29) = a1;
  rf_param_get_status(v13, 5);
  return 0;
}

