// rf_chan_table_init_n_74 @ 0x121340, size 184 bytes
// Doc: rf_chan_table_init_n_74 [rf]: Initialize per-channel RF register table at 0x403200ac..bc sized 0x2b8
// rf_chan_table_init_n_74 [rf]: Initialize per-channel RF register table at 0x403200ac..bc sized 0x2b8
int __fastcall rf_chan_table_init_n_74(int a1, int a2)
{
  int v2; // r6
  _DWORD *v3; // r3
  _DWORD *v4; // lr
  _DWORD *v5; // r12
  _DWORD *v6; // r7
  unsigned __int16 *v7; // r2
  _DWORD *v8; // r5
  int *v9; // r2
  int v10; // r4
  unsigned int v11; // r5
  _DWORD *v12; // r12
  _DWORD *v13; // r7
  unsigned __int16 *v14; // r3
  _DWORD *v15; // r2

  v2 = dword_1213F8;
  v3 = off_1213FC;
  v4 = off_121410;
  v5 = off_121414;
  v6 = off_121400;
  v7 = (unsigned __int16 *)(dword_1213F8 + 696 * a1);
  *(_DWORD *)off_1213FC = v7[19] | (v7[20] << 16);
  v8 = off_121404;
  v3[1] = v7[21];
  v9 = (int *)off_121408;
  *v4 = 0;
  *v5 = 0;
  *v8 = 0;
  *v6 = 0;
  v10 = (unsigned __int8)(a1 + 16);
  *v9 = 0x20000000;
  while ( (*v9 & 0x20000000) != 0 )
    ;
  if ( (*v9 & 0x10000000) == 0 )
  {
    v11 = HIWORD(*v9);
    if ( (unsigned __int8)BYTE2(*v9) != v10 )
    {
      v12 = off_12140C;
      v13 = off_121408;
      *(_DWORD *)off_1213FC = -1;
      *v12 = -1;
      *v9 = ((unsigned __int8)v11 << 16) | 0x40000000;
      while ( (*v13 & 0x40000000) != 0 )
        ;
      v14 = (unsigned __int16 *)(v2 + 696 * a1);
      *(_DWORD *)off_1213FC = v14[19] | (v14[20] << 16);
      *(_DWORD *)off_12140C = v14[21];
    }
  }
  v15 = off_121408;
  *(_DWORD *)off_121408 = (16 * a2) | (v10 << 16) | 0x40000002;
  while ( (*v15 & 0x40000000) != 0 )
    ;
  return (unsigned __int8)(a1 + 16);
}

