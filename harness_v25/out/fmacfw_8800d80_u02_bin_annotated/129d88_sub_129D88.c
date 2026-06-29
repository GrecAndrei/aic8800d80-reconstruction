// fwstruct annotate: 129d88_sub_129D88.c
// sub_129D88 @ 0x129d88, size 434 bytes
int __fastcall sub_129D88(int result, int a2, unsigned int a3)
{
  int v3; // r8
  int v4; // r9
  int v5; // r5
  int v6; // r4
  int v8; // r3
  int v10; // r2
  _BYTE *v11; // r7
  int v12; // r3
  int v13; // r7
  int v14; // r3
  int v15; // r3
  __int64 v16; // kr00_8
  unsigned int v17; // r7
  unsigned __int8 *v18; // r9
  unsigned __int8 v19; // r11
  unsigned int v20; // r3
  int v21; // r5
  int v22; // r2
  char v23; // r3
  _BYTE *v24; // r7
  int v25; // r3
  int v26; // r6
  int v27; // r3
  int v28; // [sp+0h] [bp-Ch]
  int v29; // [sp+4h] [bp-8h]

  v3 = dword_129F40;
  v4 = 140 * result;
  v5 = result;
  v6 = dword_129F40 + 140 * result;
  if ( !a2 )
  {
    v24 = (_BYTE *)(dword_129F40 + 140 * result);
    v25 = (unsigned __int8)v24[121];
    v24[132] = 0;
    if ( v25 )
    {
      if ( v24[16] )
      {
        timestamp_remove(v6);
        v24[16] = 0;
      }
      v26 = v3 + 140 * v5;
      v27 = *(unsigned __int8 *)(v26 + 64);
      *(_BYTE *)(v26 + 121) = 0;
      if ( v27 )
      {
        timestamp_remove(v4 + 48 + v3);
        *(_BYTE *)(v26 + 64) = 0;
      }
      *(_BYTE *)(v3 + 140 * v5 + 121) = 0;
      sub_129804((unsigned __int8 *)v6);
    }
    goto LABEL_19;
  }
  v8 = dword_129F40 + 140 * result;
  v10 = *(unsigned __int8 *)(a2 + 3);
  if ( !*(_BYTE *)(v8 + 132) || *(unsigned __int8 *)(v8 + 120) != v10 )
  {
    v11 = (_BYTE *)(dword_129F40 + 140 * result);
    v12 = (unsigned __int8)v11[121];
    v11[120] = v10;
    v11[132] = 1;
    if ( v12 )
    {
      if ( v11[16] )
      {
        timestamp_remove(v6);
        v11[16] = 0;
      }
      v13 = v3 + 140 * v5;
      v14 = *(unsigned __int8 *)(v13 + 64);
      *(_BYTE *)(v13 + 121) = 0;
      if ( v14 )
      {
        timestamp_remove(v4 + 48 + v3);
        *(_BYTE *)(v13 + 64) = 0;
      }
      *(_BYTE *)(v3 + 140 * v5 + 121) = 0;
      sub_129804((unsigned __int8 *)v6);
    }
    v15 = *(unsigned __int16 *)(a2 + 1) - 2;
    v16 = dword_129F3C * (__int64)v15;
    v17 = (unsigned __int8)((SHIDWORD(v16) >> 2) - (v15 >> 31));
    if ( (unsigned __int8)(SHIDWORD(v16) >> 2) != (unsigned __int8)(v15 >> 31) )
    {
      v28 = v3 + 140 * v5;
      v18 = (unsigned __int8 *)(a2 + 5);
      v19 = 0;
      v29 = v5;
      do
      {
        v20 = *v18;
        *(_BYTE *)(v6 + 20) = v20;
        ++v19;
        if ( v20 )
        {
          v21 = *(_DWORD *)(v18 + 5);
          if ( v20 <= 1 || v21 )
          {
            *(_DWORD *)(v6 + 24) = *(_DWORD *)(v18 + 1);
            v22 = v21 - 4000 - sub_1019F0();
            v23 = *(_BYTE *)(v6 + 20);
            *(_DWORD *)(v6 + 28) = v22;
            *(_BYTE *)(v6 + 19) = v23;
            if ( scan_chan_get_next_n68(v6, *(unsigned __int8 *)(v28 + 113), *(_DWORD *)(v18 + 9), a3) )
              ++*(_BYTE *)(v28 + 121);
          }
        }
        v18 += 13;
        v6 += 48;
      }
      while ( v19 < v17 );
      v5 = v29;
    }
    if ( *(char *)(a2 + 4) < 0 )
    {
      *(_BYTE *)(v3 + 140 * v5 + 115) = *(_BYTE *)(a2 + 4) & 0x7F;
      return 140;
    }
LABEL_19:
    *(_BYTE *)(v3 + 140 * v5 + 115) = 0;
    return 140;
  }
  return result;
}

