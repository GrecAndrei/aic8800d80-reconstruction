// fwstruct annotate: 12580c_rf_chan_lookup_n_580c.c
// rf_chan_lookup_n_580c @ 0x12580c, size 316 bytes
// Doc: rf_chan_lookup_n_580c [rf]: RF channel/table lookup indexed by byte field
// rf_chan_lookup_n_580c [rf]: RF channel/table lookup indexed by byte field
int __fastcall rf_chan_lookup_n_580c(int a1)
{
  int v1; // r8
  _BYTE *v2; // r5
  char v4; // r7
  int v5; // r6
  int v6; // r0
  int v7; // r1
  __int16 v8; // r3
  int v9; // r3
  int v10; // r9
  char v11; // r7
  int v12; // r5
  int v13; // r3
  int v14; // r5
  int v15; // r0
  int v16; // r2
  int v17; // r3
  char v18; // r7
  _BYTE *v19; // r0

  v1 = *(_DWORD *)(a1 + 192);
  v2 = (_BYTE *)(dword_125948 + 8 * *(unsigned __int8 *)(a1 + 107));
  v4 = v2[4];
  v5 = a1 + 116;
  v6 = bt_hci_cmd_dispatch_2b8(a1);
  *(_DWORD *)(v1 + 36) = *(unsigned __int16 *)(v6 + 216) + *(unsigned __int16 *)(v6 + 218) + 4;
  if ( *(_BYTE *)(v6 + 1224) )
  {
    v15 = sub_12ADA4(*(unsigned __int8 *)(v6 + 1225));
    if ( v15 )
    {
      v16 = dword_125954 + 20 * *(unsigned __int8 *)(a1 + 107);
      v17 = *(_DWORD *)(v16 + 8);
      *(_DWORD *)(v1 + 36) += v15;
      *(_DWORD *)(v16 + 12) = v15 + v17 - 1;
    }
  }
  v7 = *(_DWORD *)(v1 + 28);
  v8 = *((_WORD *)off_12594C + 254) + 1;
  *((_WORD *)off_12594C + 254) = v8;
  *(_WORD *)(v7 + 22) = 16 * v8;
  v9 = *(unsigned __int8 *)(a1 + 227);
  v2[2] = v9;
  v10 = *(unsigned __int8 *)(a1 + 230);
  if ( v9 )
  {
    v10 &= 2u;
    if ( v10 )
    {
      v11 = v4 | 1;
      v10 = 1;
    }
    else
    {
      v11 = v4 & 0xFE;
    }
  }
  else
  {
    if ( *(_BYTE *)(a1 + 230) )
    {
      v11 = v4 | 1;
      v10 = 1;
    }
    else
    {
      v11 = v4 & 0xFE;
    }
    if ( *(_BYTE *)off_125950 )
      v11 |= 1u;
    *(_BYTE *)(a1 + 227) = v2[3];
  }
  v2[4] = v11;
  v12 = *(unsigned __int8 *)(a1 + 231);
  --*(_BYTE *)(a1 + 227);
  if ( v12 )
  {
    v13 = *(unsigned __int8 *)(a1 + 232);
    v14 = (unsigned __int8)(v12 - 1);
    *(_BYTE *)(a1 + 231) = v14;
    if ( v13 )
    {
      *(_BYTE *)(*(_DWORD *)(v1 + 28) + v13) = v14;
      if ( *(_BYTE *)(a1 + 233) )
        *(_BYTE *)(*(_DWORD *)(v1 + 28) + *(unsigned __int8 *)(a1 + 233)) = *(_BYTE *)(a1 + 231);
      v14 = *(unsigned __int8 *)(a1 + 231);
    }
    if ( !v14
      || (v18 = *(_BYTE *)(a1 + 107),
          v19 = (_BYTE *)rf_bus_setup_n3a8(78, 13, 0, 2),
          *v19 = v18,
          v19[1] = v14,
          sub_12CBB4(v19),
          !*(_BYTE *)(a1 + 231)) )
    {
      *(_BYTE *)(a1 + 231) = 1;
    }
  }
  message_dispatch_n_4a3(a1, v5);
  return v10;
}

