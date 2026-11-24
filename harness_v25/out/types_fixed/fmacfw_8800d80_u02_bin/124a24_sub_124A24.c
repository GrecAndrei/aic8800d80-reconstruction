// sub_124A24 @ 0x124a24, size 240 bytes
// Doc: sub_1224A24 [rf]: Copies RF parameter block fields into shared config struct
// sub_1224A24 [rf]: Copies RF parameter block fields into shared config struct
int __fastcall sub_124A24(unsigned __int8 *a1)
{
  _BYTE *v1; // r3
  int v2; // r4
  int v3; // r1
  int v5; // r0
  unsigned __int8 v6; // r2
  int v7; // r1
  _DWORD *v8; // r10
  _DWORD *v9; // r9
  _DWORD *v10; // r8
  int v11; // r11
  unsigned __int8 *v12; // r6
  int v13; // r7
  int i; // r4
  int v15; // r3
  int v16; // t1
  void *v17; // r2

  v1 = off_124B14;
  v2 = *(_DWORD *)(a1 + 0x40);
  *((_BYTE *)off_124B14 + 360) = *(_DWORD *)(a1 + 0x44);
  *(_DWORD *)(v1 + 0x5a4) = *(_DWORD *)(a1 + 0x48);
  v3 = *(_DWORD *)(a1 + 0x54);
  *(_DWORD *)(v1 + 0x590) = v3;
  v5 = *(_DWORD *)(a1 + 0x58);
  *(_DWORD *)(v1 + 0x594) = v5;
  v6 = *(_DWORD *)(a1 + 0x5c);
  *(_DWORD *)(v1 + 0x598) = v6;
  v7 = v3 + v5;
  *(_DWORD *)(v1 + 0x59c) = v6 + v7;
  if ( *(_DWORD *)(a1 + 0x4c) )
    *(_DWORD *)off_124B18 |= 0x10u;
  else
    *(_DWORD *)off_124B18 &= ~0x10u;
  if ( *(_DWORD *)(a1 + 0x50) )
    *(_DWORD *)off_124B18 |= 2u;
  else
    *(_DWORD *)off_124B18 &= ~2u;
  v8 = off_124B30;
  v9 = off_124B34;
  v10 = off_124B38;
  v11 = 1320 * v2 + 8 + dword_124B1C;
  v12 = a1 - 4;
  v13 = dword_124B1C + 1320 * v2;
  for ( i = 0; i != 4; ++i )
  {
    v16 = *((_DWORD *)v12 + 1);
    v12 += 4;
    v15 = v16;
    v17 = (void *)(unsigned __int8)i;
    if ( v16 )
    {
      *(_DWORD *)(v11 + 4 * i) = v15;
      v7 = *(unsigned __int8 *)(v13 + 108);
      *(_DWORD *)(*(_DWORD *)off_124B20 + 4 * i) = v15;
      if ( v7 )
      {
        if ( i == 1 )
        {
          *v8 = v15;
        }
        else if ( (unsigned __int8)i == 2 )
        {
          *v9 = v15;
        }
        else if ( (_BYTE)i )
        {
          *v10 = v15;
        }
        else
        {
          *(_DWORD *)off_124B2C = v15;
        }
        fmac_main_loop();
      }
    }
  }
  if ( *(_DWORD *)(a1 + 0x60) )
  {
    v17 = off_124B24;
    *(_BYTE *)off_124B24 = *(_DWORD *)(a1 + 0x60);
  }
  msg_parse(dword_124B28, v7, v17);
  return rf_mem_read_eb18(a1, 28, 1, 0);
}

