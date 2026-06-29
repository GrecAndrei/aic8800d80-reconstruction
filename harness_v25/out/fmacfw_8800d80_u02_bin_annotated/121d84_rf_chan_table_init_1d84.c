// fwstruct annotate: 121d84_rf_chan_table_init_1d84.c
// rf_chan_table_init_1d84 @ 0x121d84, size 610 bytes
// Doc: rf_chan_table_init_1d84 [rf]: Initialize RF channel table entry (indexed by mla/smlabb, 0x2b8 stride).
// rf_chan_table_init_1d84 [rf]: Initialize RF channel table entry (indexed by mla/smlabb, 0x2b8 stride).
unsigned int __fastcall rf_chan_table_init_1d84(unsigned int a1)
{
  int v1; // r5
  int v2; // r7
  int v3; // r6
  unsigned int v4; // r4
  int v5; // r9
  int v6; // r8
  int v7; // r10
  int v8; // r3
  int v9; // r1
  int v10; // r7
  unsigned __int8 *v11; // r3
  int v12; // r1
  _DWORD *v13; // r1
  char *v14; // r0
  _DWORD *v15; // r7
  _DWORD *v16; // r6
  int *v17; // r1
  int *v18; // r2
  int v19; // r1
  char *v20; // r5
  _DWORD *v21; // r6
  unsigned __int8 v22; // r0
  _DWORD *v23; // r1
  _DWORD *v24; // r1
  int v26; // r2
  int v27; // r11
  int v28; // r9
  unsigned __int8 *v29; // r10
  unsigned int v30; // r3
  int v31; // r6
  _BYTE *v32; // r0
  int *v33; // r3
  _DWORD *v34; // r2
  int v35; // r1
  _DWORD *v36; // r8
  int v37; // r4
  int v38; // r10
  _DWORD *v39; // r9
  int v40; // r11
  unsigned int CPSR; // r1
  void *v42; // r2
  int v43; // r0
  int v44; // r1
  int v45; // r3
  int v46; // r0
  int v47; // r1
  unsigned int v48; // [sp+Ch] [bp-8h]

  v1 = dword_121FE8;
  v2 = dword_121FE8 + 696 * a1;
  v3 = *(unsigned __int8 *)(v2 + 34);
  v4 = a1;
  v5 = dword_121FE8 + 8 * (87 * (__int16)a1 + 78);
  v6 = 0;
  do
  {
    v7 = (unsigned __int8)v6++;
    if ( *(_DWORD *)(v2 + 584) )
      sub_118940(v7, v5 - 40, 0);
    v8 = *(_DWORD *)(v2 + 624);
    v9 = v5;
    v2 += 8;
    v5 += 8;
    if ( v8 )
      sub_118940(v7, v9, 0);
  }
  while ( v6 != 5 );
  v10 = dword_121FEC;
  v11 = (unsigned __int8 *)(dword_121FEC + 1320 * v3);
  v12 = v11[106];
  if ( !v11[106] )
  {
    v11[116] = -1;
LABEL_9:
    v13 = off_121FF0;
    v14 = (char *)off_121FF4;
    v15 = off_121FF8;
    v16 = off_121FFC;
    *(_DWORD *)off_121FF4 = -1;
    *v13 = -1;
    *v15 = 0;
    v17 = v13 + 1;
    *v16 = 0;
    *(int *)((char *)v17 + 0xFFFFFFF0) = 0;
    *(_DWORD *)&v14[-4] = 0;
    v18 = v17;
    *v17 = ((unsigned __int8)(v4 + 16) << 16) | 0x40000000;
    while ( (*v17 & 0x40000000) != 0 )
      ;
    v19 = *(_DWORD *)(v1 + 696 * v4 + 44);
    if ( v19 )
    {
      v20 = (char *)off_121FF4;
      v21 = off_121FF0;
      v22 = *(_BYTE *)(v19 + 35) + 16;
      *(_DWORD *)off_121FF4 = -1;
      *v21 = -1;
      v23 = off_121FFC;
      *(_DWORD *)&v20[-16] = 0;
      *v23 = 0;
      *(_DWORD *)((char *)v21 + 0xFFFFFFF4) = 0;
      v24 = v23 + 5;
      *(_DWORD *)&v20[-4] = 0;
      *v18 = (v22 << 16) | 0x40000000;
      while ( (*v24 & 0x40000000) != 0 )
        ;
    }
    return sub_11F12C(v4);
  }
  if ( *(_BYTE *)(v1 + 696 * v4 + 36) == 1 )
  {
    v26 = (unsigned __int8)(v11[234] - 1);
    v11[234] = v26;
    if ( !v26 )
    {
      v27 = (unsigned __int8)(v11[107] + 32);
      v28 = 696 * v27;
      v29 = (unsigned __int8 *)(v1 + 696 * v27);
      if ( v29[36] )
      {
        v30 = v29[35];
        v29[36] = 0;
        if ( v30 <= 0x1F )
        {
          v32 = (_BYTE *)sub_12C92C(73, 13, 0, 2);
          *v32 = v27;
          v32[1] = 0;
          sdio_buffer_prepare_n_4e8(v32);
          if ( !v29[36] && v29[35] <= 0x1Fu )
          {
            v33 = (int *)off_122004;
            v48 = v4;
            v34 = (_DWORD *)(v10 + 1320 * v29[34]);
            v35 = dword_122000 + v28;
            v36 = (_DWORD *)(v1 + v28);
            v37 = v1 + 8 * (87 * (__int16)v27 + 78);
            v38 = v10 + 8 * (165 * v29[34] + 159);
            v39 = v34;
            v40 = v35;
            do
            {
              if ( v36[146] )
              {
                CPSR = __get_CPSR();
                v42 = (void *)(CPSR << 31);
                if ( (CPSR & 1) == 0 )
                {
                  __disable_irq();
                  v42 = off_122008;
                  *(_DWORD *)off_122008 = 1;
                }
                v43 = dword_12200C;
                v44 = *v33 + 1;
                *v33 = v44;
                msg_parse(v43, v44, v42);
                buf_ptr_deref_n_430(v37 - 40, v38 - 40);
                v45 = v36[147];
                v39[308] = v36[146];
                v39[309] = v45;
                sub_12D240(v37 - 40);
                v33 = (int *)off_122004;
                v46 = *(_DWORD *)off_122004 - 1;
                if ( *(_DWORD *)off_122004 )
                {
                  v34 = off_122008;
                  *(_DWORD *)off_122004 = v46;
                  if ( !v46 )
                  {
                    if ( *v34 )
                      __enable_irq();
                  }
                }
              }
              v47 = v36[156];
              v39 += 2;
              v36 += 2;
              if ( v47 )
              {
                msg_parse(dword_122010, v47, v34);
                buf_ptr_deref_n_430(v38, v37);
                sub_12D240(v37);
                v33 = (int *)off_122004;
              }
              v37 += 8;
              v38 += 8;
            }
            while ( v37 != v40 );
            v4 = v48;
            irq_nesting_or_d104(512);
          }
        }
      }
      v31 = v10 + 1320 * v3;
      sub_136D14(v31, (unsigned __int8)(*(_BYTE *)(v31 + 107) + 32));
      v12 = *(unsigned __int8 *)(v31 + 106);
    }
  }
  if ( v12 != 2 )
    goto LABEL_9;
  return sub_11F12C(v4);
}

