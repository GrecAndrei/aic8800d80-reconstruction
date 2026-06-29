// fwstruct annotate: 13ed0c_sub_13ED0C.c
// sub_13ED0C @ 0x13ed0c, size 1094 bytes
int __fastcall sub_13ED0C(int a1)
{
  char v1; // r3
  int result; // r0
  int v4; // r5
  int v5; // r7
  int v6; // r7
  unsigned int v7; // r0
  unsigned int v8; // r9
  unsigned __int16 v9; // r0
  signed int v10; // r3
  int v11; // r6
  int v12; // r7
  int v13; // r11
  unsigned int v14; // r5
  unsigned int v15; // r1
  unsigned int v16; // r12
  unsigned int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r1
  unsigned int v20; // r3
  unsigned int v21; // r0
  unsigned int v22; // r12
  unsigned int v23; // r7
  unsigned int v24; // r10
  unsigned int v25; // r9
  unsigned int v26; // r6
  unsigned int v27; // r0
  unsigned int v28; // r3
  unsigned int v29; // r6
  unsigned int v30; // r5
  int v31; // lr
  unsigned int v32; // r2
  unsigned int v33; // r0
  unsigned int v34; // r0
  unsigned int v35; // r0
  int v36; // r3
  int v37; // r3
  int v38; // r1
  int v39; // r0
  int v40; // r11
  _BYTE *v41; // r3
  __int16 v42; // r0
  unsigned int v43; // r3
  unsigned int v44; // [sp+0h] [bp-40h]
  int v45; // [sp+0h] [bp-40h]
  __int16 v46; // [sp+4h] [bp-3Ch]
  __int16 v47; // [sp+4h] [bp-3Ch]
  __int16 v48; // [sp+4h] [bp-3Ch]
  __int16 v49; // [sp+4h] [bp-3Ch]
  int v50; // [sp+Ch] [bp-34h] BYREF
  __int16 v51; // [sp+10h] [bp-30h]
  __int16 v52; // [sp+12h] [bp-2Eh]
  __int16 v53; // [sp+14h] [bp-2Ch]
  __int16 v54; // [sp+16h] [bp-2Ah]

  v1 = *(_BYTE *)(a1 + 166);
  if ( (v1 & 0x20) != 0 )
    return 0;
  result = *(unsigned __int8 *)(a1 + 154);
  if ( result )
    return 0;
  v4 = *(unsigned __int16 *)(a1 + 152);
  if ( *(_WORD *)(a1 + 152) )
  {
    *(_WORD *)(a1 + 152) = v4 - 1;
    return result;
  }
  if ( (v1 & 0x40) == 0 )
  {
    v5 = *(unsigned __int16 *)(a1 + 136);
    goto LABEL_6;
  }
  if ( *(unsigned __int16 *)(a1 + 184) <= 9u )
  {
    v5 = *(unsigned __int16 *)(a1 + 136);
    goto LABEL_31;
  }
  v23 = *(unsigned __int8 *)(a1 + 178);
  v24 = *(unsigned __int8 *)(a1 + 177);
  v25 = *(unsigned __int16 *)(a1 + 12 * *(unsigned __int16 *)(a1 + 138) + 10);
  v26 = *(unsigned __int16 *)(a1 + 12 * *(unsigned __int16 *)(a1 + 136) + 10);
  memset_thunk(&v50, 0xFFu, 0xCu);
  v45 = v23 - v24 + 1;
  while ( 2 )
  {
    switch ( (char)v4 )
    {
      case 1:
        if ( v24 <= 3 && (v36 = *(unsigned __int8 *)(a1 + 166), (v36 & 8) != 0) )
        {
          v42 = sub_143A18(v36 << 28);
          v43 = (unsigned __int8)((v42 & 0x7F) % v45 + v24);
          if ( ((*(unsigned __int16 *)(a1 + 174) >> v43) & 1) != 0 )
          {
            if ( !((unsigned __int8)((v42 & 0x7F) % v45) + (_BYTE)v24) )
              v43 = v23;
          }
          else
          {
            v43 = v23;
          }
          HIWORD(v50) = v43;
          if ( v43 - 1 <= 2 )
            HIWORD(v50) = v43 | v42 & 0x400 | (*(unsigned __int8 *)(a1 + 182) << 10);
        }
        else if ( ((v26 >> 11) & 5) == 5 )
        {
          v37 = ((v26 >> 9) & 3) + 1;
          LOWORD(v26) = v26 & 0xF9FF;
          HIWORD(v50) = v26
                      | (((_WORD)v37
                        - (((((unsigned int)dword_13F154 * (unsigned __int64)(unsigned int)v37) >> 32) & 0xFFFE)
                         + (unsigned __int16)((unsigned int)(((unsigned int)dword_13F154
                                                            * (unsigned __int64)(unsigned int)v37) >> 32) >> 1))) << 9);
          v26 = (unsigned __int16)v26;
        }
        else if ( ((v26 >> 11) & 6) != 0 && *(_BYTE *)(a1 + 181) == 1 )
        {
          HIWORD(v50) = v26 ^ 0x200;
        }
        goto LABEL_68;
      case 2:
        v35 = sub_13CF14(a1, v26);
        if ( v35 != v26 )
        {
          v49 = v35;
          if ( sub_13D2F8(a1, v35) )
            v51 = v49;
        }
        goto LABEL_68;
      case 3:
        v34 = sub_13D5E8(a1, v26);
        if ( v34 != v26 )
        {
          v48 = v34;
          if ( sub_13D2F8(a1, v34) )
            v52 = v48;
        }
        goto LABEL_68;
      case 4:
        v33 = sub_13CF14(a1, v25);
        if ( v25 != v33 )
        {
          v47 = v33;
          if ( sub_13D2F8(a1, v33) )
            v53 = v47;
        }
LABEL_68:
        if ( v23 <= 3 )
          goto LABEL_69;
        goto LABEL_71;
      case 5:
        v27 = sub_13D5E8(a1, v25);
        if ( v25 != v27 )
        {
          v46 = v27;
          if ( sub_13D2F8(a1, v27) )
            v54 = v46;
        }
        if ( v23 > 3 || *((unsigned __int16 *)&v50 + v4) != 0xFFFF )
          goto LABEL_53;
        goto LABEL_84;
      default:
        LOWORD(v50) = sub_13D730(a1);
        if ( v23 <= 3 )
        {
LABEL_69:
          if ( *((unsigned __int16 *)&v50 + v4) == 0xFFFF )
LABEL_84:
            *((_WORD *)&v50 + v4) = v23 | 0x400;
        }
        if ( (unsigned __int8)v4 != 5 )
        {
LABEL_71:
          ++v4;
          continue;
        }
LABEL_53:
        v28 = *(unsigned __int16 *)(a1 + 184);
        if ( v28 <= 1 )
        {
          v5 = *(unsigned __int16 *)(a1 + 136);
        }
        else
        {
          v29 = 0;
          v30 = 1;
          v5 = *(unsigned __int16 *)(a1 + 136);
          do
          {
            v32 = a1 + 12 * v30;
            if ( *(__int16 *)(v32 + 8) < 0 && *(unsigned __int8 *)(v32 + 12) <= 0xAu
              || v30 == v5
              || *(unsigned __int16 *)(a1 + 138) == v30
              || *(unsigned __int16 *)(a1 + 140) == v30
              || v29 > 5 )
            {
              v30 = (unsigned __int16)(v30 + 1);
            }
            else
            {
              v31 = *((unsigned __int16 *)&v50 + v29);
              if ( v31 != 0xFFFF )
              {
                if ( v28 )
                {
                  v38 = a1;
                  v39 = 0;
                  while ( 1 )
                  {
                    v40 = *(unsigned __int16 *)(v38 + 10);
                    ++v39;
                    v38 += 12;
                    if ( v40 == v31 )
                      break;
                    if ( v39 == v28 )
                      goto LABEL_92;
                  }
                }
                else
                {
LABEL_92:
                  v41 = (_BYTE *)(a1 + 12 * v30);
                  *(_WORD *)(v32 + 10) = v31;
                  *(_WORD *)(v32 + 8) = 0;
                  v41[13] = 0;
                  *(_WORD *)(v32 + 4) = 0;
                  *(_WORD *)(v32 + 6) = 0;
                  v41[12] = 0;
                  v41[14] = 1;
                  bt_chan_parse(a1, v30, v32, v41);
                  v30 = (unsigned __int16)(v30 + 1);
                  v5 = *(unsigned __int16 *)(a1 + 136);
                  v28 = *(unsigned __int16 *)(a1 + 184);
                }
              }
              ++v29;
            }
          }
          while ( v28 > v30 );
        }
        v1 = *(_BYTE *)(a1 + 166);
LABEL_31:
        *(_BYTE *)(a1 + 166) = v1 & 0xBF;
LABEL_6:
        v6 = 12 * v5;
        v7 = rx_desc_parse_n_ebbc(v6 + 4 + a1);
        v8 = *(unsigned __int8 *)(a1 + 169);
        v44 = v7;
        *(_WORD *)(a1 + 152) = 10 * *(_WORD *)(a1 + 150);
        v9 = sub_143A18(v7);
        v10 = *(unsigned __int16 *)(a1 + 184);
        v11 = (unsigned __int16)(v9 % *(_WORD *)(a1 + 184));
        if ( *(_WORD *)(a1 + 184) )
        {
          v12 = v6 + a1;
          v13 = 0;
          while ( 1 )
          {
            while ( 1 )
            {
              v14 = (v11 + v13) % (unsigned int)v10;
              v11 = (unsigned __int16)v14;
              if ( *(unsigned __int16 *)(a1 + 136) == (unsigned __int16)v14 )
                goto LABEL_26;
              v15 = a1 + 12 * v14;
              if ( *(unsigned __int16 *)(v15 + 8) > 0xF333u )
                goto LABEL_26;
              if ( v8 <= 1 )
                goto LABEL_24;
              if ( (*(_BYTE *)(a1 + 166) & 2) != 0 )
                break;
              v18 = *(unsigned __int16 *)(a1 + 188);
              if ( !*(_WORD *)(a1 + 188) && !*(_WORD *)(a1 + 192) )
                goto LABEL_19;
              v16 = *(unsigned __int16 *)(v15 + 10);
              v17 = v16 >> 11;
              if ( ((v16 >> 11) & 6) != 0 )
                goto LABEL_15;
              if ( v10 <= ++v13 )
                return 0;
            }
            v16 = *(unsigned __int16 *)(v15 + 10);
            v17 = v16 >> 11;
            if ( ((v16 >> 11) & 6) != 0 )
              break;
LABEL_26:
            if ( v10 <= ++v13 )
              return 0;
          }
          v18 = *(unsigned __int16 *)(a1 + 188);
          if ( !*(_WORD *)(a1 + 188) && !*(_WORD *)(a1 + 192) )
            goto LABEL_19;
LABEL_15:
          v19 = v17 & 7;
          if ( v19 <= 3 )
          {
            if ( v19 <= 1 )
            {
              v20 = v16 & 0x7F;
              goto LABEL_18;
            }
            if ( (v16 & 0x10) != 0 )
              goto LABEL_19;
            v20 = v16 & 7;
LABEL_18:
            if ( sub_1172B0(v18) <= v20 )
              goto LABEL_19;
LABEL_25:
            v10 = *(unsigned __int16 *)(a1 + 184);
            goto LABEL_26;
          }
          if ( (((int)v16 >> 4) & 6) == 0 )
          {
            v20 = v16 & 0xF;
            goto LABEL_18;
          }
LABEL_19:
          v21 = rx_desc_parse_n_ebbc(12 * v14 + 4 + a1);
          if ( *(_BYTE *)(a1 + 12 * v14 + 13) )
            v22 = 32;
          else
            v22 = *(unsigned __int16 *)(a1 + 150);
          if ( *(unsigned __int16 *)(v12 + 8) <= 0xF333u )
          {
            if ( v44 <= v21 )
              goto LABEL_24;
          }
          else if ( v44 <= v21 )
          {
LABEL_23:
            if ( *(unsigned __int8 *)(a1 + 12 * v14 + 12) >= v22 )
              goto LABEL_24;
            goto LABEL_25;
          }
          if ( !*(_BYTE *)(a1 + 12 * v14 + 13) )
          {
LABEL_24:
            *(_BYTE *)(a1 + 164) = v14;
            *(_BYTE *)(a1 + 154) = 1;
            return 1;
          }
          goto LABEL_23;
        }
        return 0;
    }
  }
}

