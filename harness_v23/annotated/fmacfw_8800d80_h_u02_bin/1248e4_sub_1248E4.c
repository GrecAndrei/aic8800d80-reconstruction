// v23 annotated: sub_1248E4 @ 0x1248e4
// Original: 1248e4_sub_1248E4.c
// Primary struct: <unclustered>
//
// sub_1248E4 @ 0x1248e4, size 240 bytes
int __fastcall sub_1248E4(unsigned __int8 *a1)
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

  v1 = off_1249D4;
  v2 = a1[16];
  *((_BYTE *)off_1249D4 + 360) = a1[17];
  v1[361] = a1[18];
  v3 = a1[21];
  v1[356] = v3;
  v5 = a1[22];
  v1[357] = v5;
  v6 = a1[23];
  v1[358] = v6;
  v7 = v3 + v5;
  v1[359] = v6 + v7;
  if ( a1[19] )
    *(_DWORD *)off_1249D8 |= 0x10u;
  else
    *(_DWORD *)off_1249D8 &= ~0x10u;
  if ( a1[20] )
    *(_DWORD *)off_1249D8 |= 2u;
  else
    *(_DWORD *)off_1249D8 &= ~2u;
  v8 = off_1249F0;
  v9 = off_1249F4;
  v10 = off_1249F8;
  v11 = 1320 * v2 + 8 + dword_1249DC;
  v12 = a1 - 4;
  v13 = dword_1249DC + 1320 * v2;
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
      *(_DWORD *)(*(_DWORD *)off_1249E0 + 4 * i) = v15;
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
          *(_DWORD *)off_1249EC = v15;
        }
        sub_120368();
      }
    }
  }
  if ( a1[24] )
  {
    v17 = off_1249E4;
    *(_BYTE *)off_1249E4 = a1[24];
  }
  sub_12E948(dword_1249E8, v7, v17);
  return sub_12E9D8(a1, 28, 1, 0);
}

