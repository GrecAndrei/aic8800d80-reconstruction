// fwstruct annotate: 132fa4_idx_record_lookup_n_4d4.c
// idx_record_lookup_n_4d4 @ 0x132fa4, size 526 bytes
// Doc: idx_record_lookup_n_4d4 [mmio]: Looks up a 0x2b8-byte record by index from a base table
// idx_record_lookup_n_4d4 [mmio]: Looks up a 0x2b8-byte record by index from a base table
int __fastcall idx_record_lookup_n_4d4(int a1, unsigned int a2)
{
  int v2; // r7
  int v4; // r0
  int v6; // r6
  unsigned __int16 *v7; // r9
  int v8; // r1
  char v9; // r2
  int v10; // r3
  char v11; // r0
  int v12; // r1
  char v13; // r2
  int v14; // r3
  char v15; // r0
  unsigned __int8 *v16; // r4
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r3
  int result; // r0
  unsigned __int16 *v21; // r9
  int v22; // r3
  int v23; // r2
  char v24; // r0
  int v25; // r3
  char v26; // r1
  int v27; // r1
  char v28; // r2
  int v29; // r3
  char v30; // r0

  v2 = dword_1331B4;
  v4 = dword_1331B4 + 696 * a1;
  v6 = *(unsigned __int8 *)(v4 + 34);
  if ( (*(_DWORD *)(v4 + 4) & 0x20) != 0 )
  {
    v7 = (unsigned __int16 *)off_1331D0;
    if ( **(__int16 **)off_1331B8 < 0 && (*((_BYTE *)off_1331D0 + 374) & 4) == 0 )
      sub_12F694(dword_1331C4, dword_1331C0, 1328);
    v8 = 14;
    v9 = 7;
    do
    {
      v10 = ((int)*(unsigned __int16 *)(v2 + 696 * a1 + 270) >> v8) & 3;
      v11 = v9 - 1;
      v8 -= 2;
      if ( v10 != 3 )
        break;
      --v9;
    }
    while ( v11 );
    v12 = 14;
    v13 = 7;
    do
    {
      v14 = ((int)v7[40] >> v12) & 3;
      v15 = v13 - 1;
      v12 -= 2;
      if ( v14 != 3 )
        break;
      --v13;
    }
    while ( v15 );
  }
  else
  {
    v21 = (unsigned __int16 *)off_1331D0;
    v22 = **(__int16 **)off_1331B8;
    if ( (*(_DWORD *)(v4 + 4) & 4) != 0 )
    {
      if ( v22 < 0 && (*((_BYTE *)off_1331D0 + 374) & 2) == 0 )
        sub_12F694(dword_1331C8, dword_1331C0, 1341);
      v23 = 14;
      v24 = 7;
      do
      {
        v25 = ((int)*(unsigned __int16 *)(v2 + 696 * a1 + 244) >> v23) & 3;
        v26 = v24 - 1;
        v23 -= 2;
        if ( v25 != 3 )
          break;
        --v24;
      }
      while ( v26 );
      v27 = 14;
      v28 = 7;
      do
      {
        v29 = ((int)v21[28] >> v27) & 3;
        v30 = v28 - 1;
        v27 -= 2;
        if ( v29 != 3 )
          break;
        --v28;
      }
      while ( v30 );
    }
    else if ( v22 < 0 && (*((_BYTE *)off_1331D0 + 374) & 1) == 0 )
    {
      sub_12F694(dword_1331CC, dword_1331C0, 1352);
    }
  }
  v16 = (unsigned __int8 *)(v2 + 696 * a1);
  v17 = v16[308];
  v18 = v16[35];
  v19 = *(unsigned __int8 *)(dword_1331BC + 1320 * v6 + 413);
  if ( v17 == 4 )
    v17 = 3;
  if ( v17 >= a2 )
    v17 = a2;
  if ( v19 == 4 )
    v19 = 3;
  if ( v19 >= v17 )
    LOBYTE(v19) = v17;
  v16[309] = v19;
  result = bt_chan_lookup(v18);
  v16[350] |= 8u;
  return result;
}

