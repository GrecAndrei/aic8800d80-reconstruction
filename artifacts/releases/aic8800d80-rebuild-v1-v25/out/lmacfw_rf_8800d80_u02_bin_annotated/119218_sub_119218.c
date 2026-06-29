// fwstruct annotate: 119218_sub_119218.c
// sub_119218 @ 0x119218, size 232 bytes
// Doc: sub_1219218 [mmio]: Read RF status words from MMIO 0x40501000 region
// sub_1219218 [mmio]: Read RF status words from MMIO 0x40501000 region
BOOL __fastcall sub_119218(int a1, int a2, int a3, int *a4)
{
  int v5; // r10
  _DWORD *v6; // r4
  int v7; // r8
  int v8; // r1
  int v9; // r6
  int v10; // r0
  int v11; // r7
  int v13; // r0
  int *v14; // r6
  _BYTE *v15; // r1
  int v16; // r7
  unsigned int v17; // r5
  int v18; // r11
  _BYTE *v19; // r4
  int v21; // [sp+Ch] [bp-10h]
  int v23; // [sp+14h] [bp-8h]
  int v24; // [sp+14h] [bp-8h]

  v5 = *(unsigned __int16 *)(a1 + 28);
  v6 = off_119300;
  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8);
  v8 = dword_119304;
  v9 = a1;
  v11 = *(_DWORD *)(a2 + 112);
  v10 = *(_DWORD *)(a2 + 108);
  *(_BYTE *)(a2 + 116) = 0;
  v21 = v11;
  if ( v8 - v6[4] + v10 < 0 && !rf_channel_set_n6838(*(unsigned __int8 *)(a2 + 102), 0, 0) )
    *(_DWORD *)(a2 + 108) = v6[4];
  v23 = *(char *)(v9 + 45);
  chip_rev_id_get();
  rf_chan_param_set_n_1b8((_BYTE *)a2, v23);
  v13 = sub_11E8B4(v7 + 32, 4, 0);
  *a4 = 0;
  if ( (unsigned __int16)(v5 - 36) > 1u )
  {
    v24 = v9;
    v14 = a4;
    v15 = (_BYTE *)(v7 + 36);
    v16 = a2;
    v17 = (unsigned __int16)(v5 - 36);
    do
    {
      v18 = (unsigned __int8)v15[1];
      v19 = v15 + 2;
      if ( v18 + 1 >= (int)v17 )
        break;
      if ( *v15 == 5 )
        *v14 = (int)v15;
      else
        v13 = sub_11E8B4(v19, (unsigned __int8)v15[1], v13);
      v17 = (unsigned __int16)(v17 + -2 - v18);
      v15 = &v19[v18];
    }
    while ( v17 > 1 );
    a2 = v16;
    a4 = v14;
    v9 = v24;
  }
  *(_DWORD *)(a2 + 112) = v13;
  rf_event_dispatch_n1a4(v7, v5, v9, (_DWORD *)a2, a3, *a4);
  return *(_DWORD *)(a2 + 112) != v21;
}

