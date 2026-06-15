// v23 annotated: sub_116858 @ 0x116858
// Original: 116858_sub_116858.c
// Primary struct: <unclustered>
//
// sub_116858 @ 0x116858, size 974 bytes
int __fastcall sub_116858(int a1)
{
  __int16 **v1; // r7
  int v2; // r5
  int v3; // r1
  __int16 *v5; // r0
  __int16 v6; // r8
  unsigned int v7; // r3
  int v9; // r6
  int v10; // r2
  int v11; // r5
  int v12; // r9
  int v13; // r3
  int v14; // r2
  int v15; // r2
  int v16; // r11
  int v17; // r8
  _DWORD *v18; // r2
  int *v19; // r8
  _DWORD *v20; // r4
  _DWORD *v21; // r2
  int v22; // r6
  _DWORD *v23; // r9
  unsigned int v24; // r3
  int v25; // r2
  int v26; // r6
  _DWORD *v27; // r11
  _DWORD *v28; // r10
  _DWORD *v29; // r9
  unsigned int v30; // r3
  int v31; // r4
  int v32; // r9
  int v33; // r4
  int v34; // r0
  __int64 v35; // r0
  __int64 v36; // r6
  __int64 v37; // r0
  __int64 v38; // r0
  __int64 v39; // r0
  int v40; // r0
  int v41; // r11
  _DWORD *v42; // r4
  int v43; // r1
  unsigned int v44; // r3
  int v45; // r3
  int v46; // r2
  _DWORD *v47; // r4
  int v48; // r2
  unsigned int v49; // r3
  int v50; // [sp+4h] [bp-10h]
  int v51; // [sp+Ch] [bp-8h] BYREF

  if ( *(_WORD *)(a1 + 48) )
  {
    v1 = (__int16 **)off_116B48;
    v2 = *(_DWORD *)(a1 + 28);
    v3 = **(__int16 **)off_116B48;
    if ( v3 < 0 && !v2 )
    {
      sub_121960(dword_116B7C, dword_116B78, 423, *(_DWORD *)off_116B48);
      return v2;
    }
    v5 = *(__int16 **)(v2 + 8);
    v6 = *v5;
    v7 = *(_DWORD *)(a1 + 84);
    if ( *((_BYTE *)off_116B4C + 408)
      && (*((_DWORD *)off_116B50 + 1) & 0x40) != 0
      && (*(_DWORD *)(a1 + 84) & 0x600) == 0x200 )
    {
      if ( (v6 & 0xFC) == 0xC4 )
        ++*(_DWORD *)off_116B80;
    }
    else
    {
      if ( (dword_116B54 & ~v7) != 0 )
        return 0;
      *(_DWORD *)(a1 + 84) = v7 & 0xFEFFFFFF;
      if ( v3 < 0 )
      {
        v2 = (v7 >> 15) & 0x1F0;
        if ( !v2 )
        {
          sub_121960(dword_116B84, dword_116B78, 475, v7);
          return v2;
        }
      }
      v9 = (unsigned __int8)((v7 >> 15) - 16);
      v10 = dword_116B58 + 152 * v9;
      v2 = *(unsigned __int8 *)(v10 + 35);
      if ( !*(_BYTE *)(v10 + 35) )
      {
        *(_DWORD *)(a1 + 84) = v7 & 0xFCFFFFFF;
        return v2;
      }
      if ( *(unsigned __int16 *)(v10 + 30) == 0xFFFF )
      {
        if ( (v6 & 0xFC) != 0x80 )
        {
          *(_DWORD *)(a1 + 84) = v7 & 0xFCFFFFFF;
          return 0;
        }
        v11 = *(_DWORD *)(v10 + 44);
        *(_DWORD *)(a1 + 84) = v7 & 0xFE007FFF | ((*(unsigned __int8 *)(v11 + 33) + 16) << 15);
      }
      else
      {
        v11 = dword_116B58 + 152 * v9;
      }
      v12 = *(unsigned __int8 *)(v11 + 32);
      v13 = dword_116B5C;
      v14 = dword_116B5C + 224 * v12;
      if ( !*(_BYTE *)(v14 + 96) )
        return 0;
      v15 = *(unsigned __int8 *)(v14 + 94);
      v16 = 224 * v12;
      if ( v15 )
      {
        if ( (v6 & 4) != 0 )
          goto LABEL_44;
        goto LABEL_42;
      }
      if ( (v6 & 0x300) != 0x200 )
      {
        if ( (v6 & 4) != 0 )
        {
LABEL_17:
          v17 = v6 & 0xFC;
          if ( v17 == 128 )
          {
            v41 = v16 + v13;
            v51 = 0;
            v2 = sub_119218(a1 + 20, v41, v11, &v51) == 0;
            rf_chan_init_or_reset_n_324(v41);
            return v2;
          }
          if ( v17 == 80 )
          {
            v18 = off_116B60;
            v50 = *(_DWORD *)off_116B60 & 0xF;
            if ( v50 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(_DWORD *)off_116B64 = 1;
              }
              v19 = (int *)off_116B8C;
              v20 = off_116B60;
              v21 = off_116B68;
              ++*(_DWORD *)off_116B8C;
              *v20 = 0;
              v22 = v21[4];
              v23 = v21;
              while ( 1 )
              {
                v2 = *v20 & 0xF;
                if ( !v2 )
                  break;
                v24 = v23[4] - v22;
                if ( v24 > 0x7530 )
                  sub_11F74C(2, dword_116C3C, 30000, v24);
              }
              v25 = *(_DWORD *)off_116B6C;
              v26 = *((_DWORD *)off_116B68 + 4);
              if ( (*(_DWORD *)off_116B70 & *(_DWORD *)off_116B6C & 4) == 0 )
              {
                v27 = off_116B6C;
                v28 = off_116B70;
                v29 = off_116B68;
                do
                {
                  v30 = v29[4] - v26;
                  v31 = *v28 & *v27;
                  if ( v30 > 0x7530 )
                    sub_11F74C(2, dword_116B74, v25, v30);
                }
                while ( (v31 & 4) == 0 );
              }
              *(_DWORD *)off_116C28 = 4;
              if ( *v19 )
              {
                v45 = *v19 - 1;
                v46 = *(_DWORD *)off_116C2C;
                *v19 = v45;
                if ( !v45 )
                {
                  if ( v46 )
                    __enable_irq();
                }
              }
              v47 = off_116C30;
              v48 = **v1;
              v49 = *((_DWORD *)off_116C30 + 1) & 0xFFFFFDFF;
              *((_DWORD *)off_116C30 + 1) = v49;
              if ( v48 < 0 )
              {
                if ( *(_DWORD *)off_116C38 << 28 )
                {
                  sub_1219F4(dword_116C44, dword_116C40, 472);
                  v49 = v47[1];
                }
              }
              *(_DWORD *)off_116C34 = v49 | *v47;
              *(_DWORD *)off_116C38 = 16 * v50;
              return v2;
            }
            v42 = off_116B50;
            v43 = **v1;
            v44 = *((_DWORD *)off_116B50 + 1) & 0xFFFFFDFF;
            *((_DWORD *)off_116B50 + 1) = v44;
            if ( v43 >= 0 )
            {
              v2 = 0;
              *(_DWORD *)off_116B88 = v44 | *v42;
              return v2;
            }
            v2 = *v18 & 0xF;
            if ( !v2 )
            {
              *(_DWORD *)off_116C34 = v44 | *v42;
              return v2;
            }
            sub_1219F4(dword_116C44, dword_116C40, 472);
            *(_DWORD *)off_116C34 = v42[1] | *v42;
          }
          return 0;
        }
        goto LABEL_42;
      }
      v40 = sub_128288(v5 + 8, v16 + 88 + dword_116B5C, 6);
      v13 = dword_116B5C;
      if ( v40 )
      {
        if ( (v6 & 4) != 0 )
        {
LABEL_43:
          v32 = v13 + 224 * v12;
          v15 = *(unsigned __int8 *)(v32 + 94);
          if ( !*(_BYTE *)(v32 + 94) )
            goto LABEL_17;
LABEL_44:
          if ( v15 == 2 && *(unsigned __int8 *)(v11 + 33) <= 3u )
          {
            v33 = *(char *)(a1 + 65);
            chip_rev_id_get();
            v34 = *(char *)(v11 + 145);
            if ( !*(_BYTE *)(v11 + 145) )
            {
              *(_BYTE *)(v11 + 145) = v33;
              return v34;
            }
            v35 = sub_12754C(v34);
            v36 = sub_127620(v35, HIDWORD(v35), dword_116B38, dword_116B3C);
            v37 = sub_12754C(v33);
            v38 = sub_127620(v37, HIDWORD(v37), dword_116B40, dword_116B44);
            v39 = sub_1272B4(v36, HIDWORD(v36), v38, HIDWORD(v38));
            *(_BYTE *)(v11 + 145) = sub_127B54(v39, HIDWORD(v39));
          }
          return 0;
        }
LABEL_42:
        sub_11C834(*(unsigned __int8 *)(v13 + 224 * v12 + 95), v9, 1);
        v13 = dword_116B5C;
        goto LABEL_43;
      }
    }
  }
  return 1;
}

