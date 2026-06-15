// rx_desc_compare_n6e0 @ 0x1196e0, size 384 bytes
// Doc: rx_desc_compare_n6e0 [rx]: Compare two RX descriptor fields at offset 0x1d
// rx_desc_compare_n6e0 [rx]: Compare two RX descriptor fields at offset 0x1d
int __fastcall rx_desc_compare_n6e0(int a1, int a2, int a3)
{
  unsigned int v3; // r7
  int result; // r0
  int v7; // r3
  int v8; // r6
  bool v9; // nf
  __int16 v10; // r3
  int v11; // r1
  int v12; // r9
  int v13; // r7
  int v14; // r2
  int v15; // r8
  int v16; // r10
  int v17; // r0
  int v18; // r3
  int v19; // r2
  int v20; // r1
  int v21; // r1
  _DWORD *v22; // r2
  __int16 v23; // r3
  int v24; // r2
  char v25; // r3

  if ( *(unsigned __int8 *)(a1 + 29) != *(unsigned __int8 *)(a2 + 29)
    || *(unsigned __int8 *)(a1 + 27) != *(unsigned __int8 *)(a2 + 27) )
  {
    return 0;
  }
  v7 = *(_DWORD *)(a1 + 36);
  v8 = *(_DWORD *)(a2 + 68);
  v9 = (v7 & 0x200000) != 0;
  if ( (v7 & 0x200000) != 0 )
    v7 = *(_DWORD *)(a1 + 68);
  else
    v3 = *(unsigned __int16 *)(a1 + 80);
  if ( v9 )
    v3 = *(unsigned __int16 *)(v7 + 10);
  v10 = *(_WORD *)(v8 + 8);
  if ( (v10 & 6) == 4 )
    return 0;
  if ( v3 <= 0xE78 )
  {
    result = v10 & 2;
    if ( (v10 & 2) == 0 )
    {
      v11 = *(_DWORD *)(v8 + 264);
      if ( v11 )
      {
        if ( *(_DWORD *)(v11 + 16) != dword_119860 || (int)(v3 + *(unsigned __int16 *)(v8 + 10)) <= 3704 )
          return result;
        goto LABEL_16;
      }
      return 0;
    }
  }
LABEL_16:
  result = v10 & 1;
  if ( (v10 & 1) != 0 )
  {
    result = *(_WORD *)(*(_DWORD *)(v8 + 324) + 82) & 1;
    if ( result )
    {
      *(_WORD *)(v8 + 8) = v10 | 6;
      return 1;
    }
  }
  else
  {
    v12 = dword_119870;
    v13 = dword_119870 + 84 * a3;
    v14 = *(unsigned __int8 *)(v13 + 77);
    if ( v14 != 1 )
    {
      v15 = *(_DWORD *)(v13 + 52);
      if ( (*(_WORD *)(v15 + 82) & 1) != 0 )
      {
        if ( (*(_DWORD *)off_119868 & 0x3F) > *(unsigned __int8 *)(*(_DWORD *)off_119864 + 62)
                                            + *(unsigned __int8 *)(*(_DWORD *)off_119864 + 63) )
        {
          v16 = *(_DWORD *)(v15 + 76);
          *(_BYTE *)(v16 + 1) = v14;
          v17 = *(_DWORD *)(v13 + 48);
          *(_DWORD *)(v15 + 36) |= 0x380000u;
          *(_DWORD *)(v8 + 324) = v15;
          rf_chan_field_get_n_4c6(v17);
          v18 = *(unsigned __int8 *)(*(_DWORD *)off_11986C + 1);
          if ( *(_BYTE *)(*(_DWORD *)off_11986C + 1) )
          {
            sub_1193BC(
              v8,
              *(_WORD *)(v15 + 34),
              *(unsigned __int8 *)(v8 + 12),
              *(unsigned __int8 *)(v8 + 13),
              *(_BYTE *)(v13 + 78));
            *(_DWORD *)(v16 + 20) = v8 + 84;
          }
          else
          {
            v19 = *(_DWORD *)(a1 + 76);
            *(_DWORD *)(v8 + 20) = v18;
            v20 = *(_DWORD *)(v19 + 68) << 10;
            *(_DWORD *)(v16 + 16) = v18;
            *(_DWORD *)(v16 + 20) = v18;
            if ( v20 >= 0 )
            {
              v21 = v8 + 16;
              *(_DWORD *)(v19 + 16) = v8 + 16;
            }
            else
            {
              v21 = v8 + 16;
              *(_DWORD *)(*(_DWORD *)(a1 + 68) + 20) = v8 + 16;
            }
            v22 = (_DWORD *)(v12 + 84 * a3);
            *v22 = v16 + 12;
            v22[1] = v21;
            v22[2] = 1;
          }
          v23 = *(_WORD *)(v8 + 8);
          *(_DWORD *)(v16 + 68) = *(_DWORD *)(v15 + 36) | 0x100;
          if ( (v23 & 2) != 0 )
            *(_DWORD *)(*(_DWORD *)(v8 + 52) + 20) = *(_DWORD *)(v8 + 4);
          *(_WORD *)(v8 + 8) = v23 | 0xF;
          list_push_tail(v12 + 84 * a3 + 28);
          v24 = v12 + 84 * a3;
          v25 = *(_BYTE *)(v24 + 80);
          *(_DWORD *)(v24 + 44) = 0;
          *(_BYTE *)(v24 + 80) = v25 + 1;
          return 1;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}

