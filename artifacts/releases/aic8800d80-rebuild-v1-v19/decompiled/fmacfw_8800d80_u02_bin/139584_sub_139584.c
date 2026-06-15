// sub_139584 @ 0x139584, size 1284 bytes
// Doc: sub_1239584 [unknown]: Process buffer, check for 0xff sentinel value
// sub_1239584 [unknown]: Process buffer, check for 0xff sentinel value
int __fastcall sub_139584(char a1, int a2, int a3, int a4, _BYTE *a5, unsigned int a6, _WORD *a7, _BYTE *a8)
{
  int v9; // r12
  unsigned int v11; // r5
  int v12; // r8
  int v13; // r4
  int v15; // r5
  unsigned int v16; // r0
  int v17; // r5
  int *v18; // r3
  int v19; // r3
  int v20; // r2
  int v21; // r5
  int v22; // r8
  int v23; // r6
  _DWORD *v24; // r9
  int v25; // r10
  __int16 v26; // r11
  unsigned __int8 *v27; // r3
  unsigned __int8 *v28; // r0
  unsigned __int8 *v29; // r10
  int v30; // r2
  unsigned __int8 *v31; // r11
  __int16 v32; // r5
  int v33; // r1
  int v34; // r3
  unsigned __int8 *v35; // r2
  int v36; // r4
  int v37; // r1
  unsigned __int16 v38; // r0
  unsigned __int8 *v39; // r8
  int v40; // r3
  int v41; // r9
  int v42; // r4
  int v43; // r10
  int v44; // r7
  _BYTE *v45; // r9
  int v46; // r4
  unsigned __int8 *v47; // r10
  int v48; // r0
  unsigned int v49; // r1
  int v50; // r0
  unsigned __int8 v52; // [sp+Eh] [bp-6h] BYREF
  _BYTE v53[5]; // [sp+Fh] [bp-5h] BYREF

  v9 = (unsigned __int8)*a5;
  if ( v9 == 255 )
  {
    v16 = a1 & 0xFC;
    if ( v16 == 176 )
    {
      sub_135964();
      return 1;
    }
    if ( v16 > 0xB0 )
    {
      if ( v16 != 208 )
        return 1;
LABEL_12:
      v15 = a6 + a3;
      if ( a4 == 255 )
        return 1;
      switch ( *(_BYTE *)(a6 + a3) )
      {
        case 0:
          v41 = *(unsigned __int8 *)(v15 + 1);
          msg_parse(dword_139A88, v41);
          v39 = (unsigned __int8 *)(v15 + 1);
          if ( v41 == 4 )
          {
            v42 = (unsigned __int8)*a5;
            if ( v42 != 255 )
            {
              v43 = dword_139A90;
              v44 = (unsigned __int8)sub_130F50(
                                       (unsigned __int8 *)(v15 + 2),
                                       a2 - a3 - 2,
                                       v53,
                                       1320 * v42 + 1212 + dword_139A90);
              msg_parse(dword_139A8C, v44, v53[0]);
              if ( v44 )
              {
                v45 = (_BYTE *)(1320 * v42 + v43);
                if ( !v45[106] )
                {
                  if ( !v45[146] && v45[148] && v53[0] == 1 )
                    tx_send_msg_n25dc(v45[107], v45[146]);
                  v46 = v43 + 1320 * v42;
                  *(_BYTE *)(v46 + 146) = v44;
                  *(_BYTE *)(v46 + 148) = 1;
                }
              }
            }
          }
          goto LABEL_65;
        case 3:
          v38 = sub_13BAC8(a4, v15, *(unsigned __int8 *)(v15 + 1));
          v9 = v38;
          if ( v38 != 33 )
          {
            v32 = (char)v38 << 8;
            v13 = 0;
            *a7 = 8;
            goto LABEL_49;
          }
          return 0;
        case 5:
          v33 = dword_139858;
          if ( *(_BYTE *)(dword_139858 + 1320 * v9 + 106) == 2
            || (v34 = *(unsigned __int8 *)(v15 + 1), v35 = (unsigned __int8 *)(v15 + 1), *(_BYTE *)(v15 + 1)) )
          {
            v13 = 1;
LABEL_84:
            if ( v9 == 255 )
              goto LABEL_88;
            v35 = (unsigned __int8 *)(v15 + 1);
            if ( *(_BYTE *)(dword_139A90 + 1320 * v9 + 106) )
              goto LABEL_46;
            v9 = 255;
          }
          else
          {
            *a7 = 11;
            v36 = (unsigned __int8)*a5;
            if ( v36 == 255 )
            {
              v32 = v34;
              v13 = 1;
              goto LABEL_50;
            }
            v37 = v33 + 1320 * v36;
            v13 = *(unsigned __int8 *)(v37 + 106);
            if ( *(_BYTE *)(v37 + 106) )
            {
              v9 = v34;
              v13 = 1;
              goto LABEL_48;
            }
            v9 = *(unsigned __int8 *)(v37 + 106);
          }
          if ( (unsigned int)*v35 - 6 > 1 )
          {
LABEL_88:
            v13 = 1;
            goto LABEL_47;
          }
          *a7 = 12;
          v32 = 0;
LABEL_50:
          *a7 |= v32;
          return v13;
        case 7:
          v13 = *(unsigned __int8 *)(v15 + 1);
          if ( *(_BYTE *)(v15 + 1) )
          {
            if ( v13 != 1 )
              goto LABEL_46;
            if ( (*(_DWORD *)(dword_139870 + 696 * a4 + 4) & 2) != 0 )
            {
              v13 = *(_BYTE *)(v15 + 2) & 1;
              if ( (*(_BYTE *)(v15 + 2) & 1) != 0 )
              {
                chan_ctx_lookup_n2b8(a4, 0xFFu);
                v13 = 0;
              }
              else
              {
                chan_ctx_lookup_n2b8(a4, 0xFFu);
              }
              v9 = 255;
              goto LABEL_47;
            }
          }
          else if ( (*(_DWORD *)(dword_139AA0 + 696 * a4 + 4) & 2) != 0 )
          {
            v49 = *(unsigned __int8 *)(v15 + 2);
            if ( v49 <= 1 )
            {
              chan_ctx_lookup_n2b8(a4, v49);
              v9 = 255;
              goto LABEL_47;
            }
          }
          goto LABEL_69;
        case 8:
          if ( a2 - a3 <= 3 )
            goto LABEL_69;
          if ( v9 == 255 )
            goto LABEL_88;
          v13 = *(unsigned __int8 *)(v15 + 1) | *(unsigned __int8 *)(dword_139A90 + 1320 * v9 + 106);
          if ( v13 )
            goto LABEL_46;
          *a7 = 6;
          v32 = 0;
          goto LABEL_50;
        case 0x15:
          v39 = (unsigned __int8 *)(v15 + 1);
LABEL_65:
          v40 = *v39;
          if ( v40 == 1 )
          {
            mmio_copy_4words((_DWORD *)(v15 + 2), (_DWORD *)(v15 + 10));
          }
          else
          {
            if ( v40 != 2 )
            {
LABEL_46:
              v13 = 1;
              v9 = 255;
              goto LABEL_47;
            }
            if ( (*(_DWORD *)(dword_139870 + 696 * a4 + 4) & 0x24) != 0 && *(char *)(v15 + 2) >= 0 )
            {
              chan_ctx_lookup_n2b8(a4, *(_BYTE *)(v15 + 2) & 3);
              v13 = 0;
              v9 = 255;
LABEL_47:
              if ( *a7 == 255 )
                return v13;
LABEL_48:
              v32 = (_WORD)v9 << 8;
LABEL_49:
              if ( **(__int16 **)off_13986C < 0 && v9 == 255 )
                sub_12F46C(dword_139A98, dword_139A94, 2326);
              goto LABEL_50;
            }
          }
LABEL_69:
          v13 = 0;
          v9 = 255;
          goto LABEL_47;
        case 0x16:
          v13 = 0;
          goto LABEL_84;
        default:
          goto LABEL_46;
      }
    }
    if ( v16 == 64 )
    {
LABEL_33:
      if ( !*((_BYTE *)off_139860 + 18) )
        return 1;
      v20 = **(unsigned __int8 **)off_139864;
      if ( (unsigned int)(v20 - 1) > 1 && v20 != 4 )
        return 1;
      v21 = *((_DWORD *)off_139860 + 2);
      if ( !v21 )
        return 1;
      v22 = dword_139874;
      v23 = dword_139868;
      v24 = off_139878;
      v13 = 1;
      while ( 1 )
      {
        if ( *(_BYTE *)(v21 + 106) == 2 && *(_BYTE *)(v21 + 108) && !*(_BYTE *)(v21 + 1224) )
        {
          v25 = *(unsigned __int8 *)(v21 + 107);
          v26 = *(_WORD *)(v22 + 2 * v25);
          v27 = sub_12D918((unsigned __int8 *)(a6 + 24), (unsigned __int16)(a2 - 24), &v52);
          v28 = (unsigned __int8 *)(v23 + (v25 << 9) + 36);
          v29 = v27;
          v31 = sub_12D918(v28, (unsigned __int16)(v26 - 36), v53);
          if ( v53[0] )
          {
            if ( v52 )
            {
              v47 = v29 + 2;
              v48 = sub_143710(v47, dword_139A9C, 7);
              v30 = v52;
              if ( v48 && v52 == v53[0] )
              {
                if ( !sub_143710(v47, v31 + 2, v52) )
                {
                  msg_parse(dword_139AA4);
                  v50 = dword_139AAC;
                  *(_BYTE *)off_139AA8 = 1;
                  timestamp_update(v50, v24[4] + 200000);
                }
                v30 = v52;
              }
              if ( v30 && (!sub_143710(v47, dword_139A9C, 7) || v52 != v53[0] || sub_143710(v47, v31 + 2, v52)) )
                goto LABEL_38;
            }
          }
          else if ( v52 )
          {
            return 1;
          }
          sdio_buf_align_lshift(v21, a6 + 10, v30);
          v13 = 0;
        }
LABEL_38:
        v21 = *(_DWORD *)v21;
        if ( !v21 )
          return v13;
      }
    }
    if ( v16 != 128 )
      return 1;
    v17 = 0;
  }
  else
  {
    v11 = a1 & 0xFC;
    v12 = *(unsigned __int8 *)(dword_139858 + 1320 * v9 + 106);
    if ( v11 != 128 )
    {
      if ( (a1 & 0xFCu) <= 0x80 )
      {
        if ( v11 != 64 )
        {
          if ( v11 > 0x40 )
          {
            v13 = 1;
            if ( v11 == 80 )
            {
              *a8 = 1;
              *a7 = 4;
            }
            return v13;
          }
          if ( (a1 & 0xDC) != 0x10 )
            return 1;
          goto LABEL_19;
        }
        goto LABEL_33;
      }
      if ( v11 != 192 )
      {
        if ( v11 > 0xC0 )
        {
          if ( v11 != 208 )
            return 1;
          goto LABEL_12;
        }
        if ( v11 != 160 && (v11 != 176 || sub_135964()) )
          return 1;
      }
LABEL_19:
      if ( !v12 )
      {
        *a7 = 6;
        return 1;
      }
      return 1;
    }
    v17 = dword_139858 + 1320 * v9;
  }
  if ( msg_get_value(4u) == 1 )
  {
    v18 = (int *)off_13985C;
    *a8 = 1;
    v19 = *v18;
    *a7 = 4;
    *a5 = *(_BYTE *)(v19 + 366);
  }
  if ( a4 != 255 && *(_BYTE *)(v17 + 108) )
  {
    sub_132FB8(v17, a2, a6);
    return 1;
  }
  return 1;
}

