// v23 annotated: parse_rx_frame_n688 @ 0x139688
// Original: 139688_parse_rx_frame_n688.c
// Primary struct: <unclustered>
//
// parse_rx_frame_n688 @ 0x139688, size 1192 bytes
// Doc: parse_rx_frame_n688 [rx]: Parses received frame with type-tagged header (0xff sentinel)
// parse_rx_frame_n688 [rx]: Parses received frame with type-tagged header (0xff sentinel)
int __fastcall parse_rx_frame_n688(char a1, int a2, int a3, int a4, _BYTE *a5, unsigned int a6, _WORD *a7, _BYTE *a8)
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
  int v23; // r7
  int v24; // r9
  __int16 v25; // r6
  unsigned __int8 *v26; // r0
  int v27; // r1
  unsigned __int8 *v28; // r6
  int v29; // r2
  unsigned __int8 *v30; // r9
  __int16 v31; // r5
  int v32; // r1
  int v33; // r3
  unsigned __int8 *v34; // r2
  int v35; // r4
  int v36; // r1
  unsigned __int16 v37; // r0
  unsigned __int8 *v38; // r8
  int v39; // r3
  int v40; // r9
  int v41; // r4
  int v42; // r10
  int v43; // r7
  _BYTE *v44; // r9
  int v45; // r4
  unsigned __int8 *v46; // r6
  unsigned int v47; // r1
  unsigned __int8 v49; // [sp+Eh] [bp-2h] BYREF
  unsigned __int8 v50; // [sp+Fh] [bp-1h] BYREF

  v9 = (unsigned __int8)*a5;
  if ( v9 == 255 )
  {
    v16 = a1 & 0xFC;
    if ( v16 == 176 )
    {
      check_bit_status();
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
          v40 = *(unsigned __int8 *)(v15 + 1);
          sub_12ECB0(dword_139B30, v40);
          v38 = (unsigned __int8 *)(v15 + 1);
          if ( v40 == 4 )
          {
            v41 = (unsigned __int8)*a5;
            if ( v41 != 255 )
            {
              v42 = dword_139B38;
              v43 = (unsigned __int8)sub_13116C(
                                       (unsigned __int8 *)(v15 + 2),
                                       a2 - a3 - 2,
                                       &v50,
                                       1320 * v41 + 1212 + dword_139B38);
              sub_12ECB0(dword_139B34, v43, v50);
              if ( v43 )
              {
                v44 = (_BYTE *)(1320 * v41 + v42);
                if ( !v44[106] )
                {
                  if ( !v44[146] && v44[148] && v50 == 1 )
                    sub_122810(v44[107], v44[146]);
                  v45 = v42 + 1320 * v41;
                  *(_BYTE *)(v45 + 146) = v43;
                  *(_BYTE *)(v45 + 148) = 1;
                }
              }
            }
          }
          goto LABEL_65;
        case 3:
          v37 = buf_alloc_split_123bb64(a4, v15, *(unsigned __int8 *)(v15 + 1));
          v9 = v37;
          if ( v37 != 33 )
          {
            v31 = (char)v37 << 8;
            v13 = 0;
            *a7 = 8;
            goto LABEL_49;
          }
          return 0;
        case 5:
          v32 = dword_139958;
          if ( *(_BYTE *)(dword_139958 + 1320 * v9 + 106) == 2
            || (v33 = *(unsigned __int8 *)(v15 + 1), v34 = (unsigned __int8 *)(v15 + 1), *(_BYTE *)(v15 + 1)) )
          {
            v13 = 1;
LABEL_84:
            if ( v9 == 255 )
              goto LABEL_88;
            v34 = (unsigned __int8 *)(v15 + 1);
            if ( *(_BYTE *)(dword_139B38 + 1320 * v9 + 106) )
              goto LABEL_46;
            v9 = 255;
          }
          else
          {
            *a7 = 11;
            v35 = (unsigned __int8)*a5;
            if ( v35 == 255 )
            {
              v31 = v33;
              v13 = 1;
              goto LABEL_50;
            }
            v36 = v32 + 1320 * v35;
            v13 = *(unsigned __int8 *)(v36 + 106);
            if ( *(_BYTE *)(v36 + 106) )
            {
              v9 = v33;
              v13 = 1;
              goto LABEL_48;
            }
            v9 = *(unsigned __int8 *)(v36 + 106);
          }
          if ( (unsigned int)*v34 - 6 > 1 )
          {
LABEL_88:
            v13 = 1;
            goto LABEL_47;
          }
          *a7 = 12;
          v31 = 0;
LABEL_50:
          *a7 |= v31;
          return v13;
        case 7:
          v13 = *(unsigned __int8 *)(v15 + 1);
          if ( *(_BYTE *)(v15 + 1) )
          {
            if ( v13 != 1 )
              goto LABEL_46;
            if ( (*(_DWORD *)(dword_139970 + 696 * a4 + 4) & 2) != 0 )
            {
              v13 = *(_BYTE *)(v15 + 2) & 1;
              if ( (*(_BYTE *)(v15 + 2) & 1) != 0 )
              {
                idx_record_lookup_n_4d4(a4, 0xFFu);
                v13 = 0;
              }
              else
              {
                idx_record_lookup_n_4d4(a4, 0xFFu);
              }
              v9 = 255;
              goto LABEL_47;
            }
          }
          else if ( (*(_DWORD *)(dword_139B48 + 696 * a4 + 4) & 2) != 0 )
          {
            v47 = *(unsigned __int8 *)(v15 + 2);
            if ( v47 <= 1 )
            {
              idx_record_lookup_n_4d4(a4, v47);
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
          v13 = *(unsigned __int8 *)(v15 + 1) | *(unsigned __int8 *)(dword_139B38 + 1320 * v9 + 106);
          if ( v13 )
            goto LABEL_46;
          *a7 = 6;
          v31 = 0;
          goto LABEL_50;
        case 0x15:
          v38 = (unsigned __int8 *)(v15 + 1);
LABEL_65:
          v39 = *v38;
          if ( v39 == 1 )
          {
            fmacfwbt_init_or_handler((_DWORD *)(v15 + 2), (_DWORD *)(v15 + 10));
          }
          else
          {
            if ( v39 != 2 )
            {
LABEL_46:
              v13 = 1;
              v9 = 255;
              goto LABEL_47;
            }
            if ( (*(_DWORD *)(dword_139970 + 696 * a4 + 4) & 0x24) != 0 && *(char *)(v15 + 2) >= 0 )
            {
              idx_record_lookup_n_4d4(a4, *(_BYTE *)(v15 + 2) & 3);
              v13 = 0;
              v9 = 255;
LABEL_47:
              if ( *a7 == 255 )
                return v13;
LABEL_48:
              v31 = (_WORD)v9 << 8;
LABEL_49:
              if ( **(__int16 **)off_13996C < 0 && v9 == 255 )
                sub_12F694(dword_139B40, dword_139B3C, 2326);
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
      if ( !*((_BYTE *)off_139960 + 18) )
        return 1;
      v20 = **(unsigned __int8 **)off_139964;
      if ( (unsigned int)(v20 - 1) > 1 && v20 != 4 )
        return 1;
      v21 = *((_DWORD *)off_139960 + 2);
      if ( !v21 )
        return 1;
      v22 = dword_139974;
      v23 = (unsigned __int16)(a2 - 24);
      v13 = 1;
      while ( 1 )
      {
        if ( *(_BYTE *)(v21 + 106) != 2 || !*(_BYTE *)(v21 + 108) || *(_BYTE *)(v21 + 1224) )
          goto LABEL_38;
        v24 = *(unsigned __int8 *)(v21 + 107);
        v25 = *(_WORD *)(v22 + 2 * v24);
        v26 = sub_12DB40((unsigned __int8 *)(a6 + 24), v23, &v49);
        v27 = (unsigned __int16)(v25 - 36);
        v28 = v26;
        v30 = sub_12DB40((unsigned __int8 *)(dword_139968 + (v24 << 9)), v27, &v50);
        if ( v50 )
        {
          if ( v49 )
          {
            v46 = v28 + 2;
            if ( !sub_1437AC(v46, dword_139B44, 7) || v49 != v50 || sub_1437AC(v46, v30 + 2, v49) )
              goto LABEL_38;
          }
        }
        else if ( v49 )
        {
          return 1;
        }
        sub_1196A4(v21, a6 + 10, v29);
        v13 = 0;
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
    v12 = *(unsigned __int8 *)(dword_139958 + 1320 * v9 + 106);
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
        if ( v11 != 160 && (v11 != 176 || check_bit_status()) )
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
    v17 = dword_139958 + 1320 * v9;
  }
  if ( msg_get_value(4u) == 1 )
  {
    v18 = (int *)off_13995C;
    *a8 = 1;
    v19 = *v18;
    *a7 = 4;
    *a5 = *(_BYTE *)(v19 + 366);
  }
  if ( a4 != 255 && *(_BYTE *)(v17 + 108) )
  {
    sub_1331D4(v17, a2, a6);
    return 1;
  }
  return 1;
}

