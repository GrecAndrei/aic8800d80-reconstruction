// v23 annotated: sub_1318A4 @ 0x1318a4
// Original: 1318a4_sub_1318A4.c
// Primary struct: <unclustered>
//
// sub_1318A4 @ 0x1318a4, size 226 bytes
int __fastcall sub_1318A4(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v7; // r5
  int v8; // r4
  int v9; // r7
  int v10; // r4
  int v11; // r0
  int v12; // r1
  unsigned __int8 *v14; // r7
  int v15; // r0
  __int16 v16; // r1
  int v17; // r4
  int v18; // r1
  int v19; // r2

  if ( sub_12D0B0(5u) == 1 )
    return 2;
  v7 = sub_12CB54(5138, a4, a3, 0xCu);
  if ( **(__int16 **)off_131988 < 0 )
  {
    v14 = (unsigned __int8 *)off_13198C;
    v8 = *((unsigned __int8 *)off_13198C + 16);
    if ( v8 == 255 )
    {
      sub_12F694(dword_131998, dword_131994, 1092);
      v8 = v14[16];
    }
  }
  else
  {
    v8 = *((unsigned __int8 *)off_13198C + 16);
  }
  if ( sub_101888() )
    sub_10189C(*((unsigned __int8 *)a2 + 11));
  v9 = dword_131990 + 1320 * v8;
  v10 = *(_DWORD *)(v9 + 72);
  if ( v10 )
  {
    *(_BYTE *)v7 = *(_BYTE *)(v10 + 24);
    if ( *((_BYTE *)a2 + 10) )
    {
      if ( sub_12D594((_DWORD **)dword_13199C) == 1 )
      {
        v15 = sub_12CB54(59, 0, 5, 0xCu);
        *(_BYTE *)v15 = *(_BYTE *)(*(_DWORD *)(v9 + 72) + 24);
        v16 = *((_WORD *)a2 + 4);
        v17 = a2[1];
        *(_DWORD *)(v15 + 2) = *a2;
        *(_WORD *)(v15 + 10) = v16;
        *(_DWORD *)(v15 + 6) = v17;
        sub_12CBB4(v15);
        v18 = *a2;
        v19 = a2[1];
        *(_WORD *)(v7 + 10) = *((_WORD *)a2 + 4);
        *(_DWORD *)(v7 + 2) = v18;
        *(_DWORD *)(v7 + 6) = v19;
        goto LABEL_9;
      }
      v10 = *(_DWORD *)(v9 + 72);
    }
    v11 = *(_DWORD *)(v10 + 4);
    v12 = *(_DWORD *)(v10 + 8);
    *(_WORD *)(v7 + 10) = *(_WORD *)(v10 + 12);
    *(_DWORD *)(v7 + 2) = v11;
    *(_DWORD *)(v7 + 6) = v12;
LABEL_9:
    sub_12CBB4(v7);
    return 0;
  }
  *(_BYTE *)v7 = -1;
  sub_12CBB4(v7);
  return 0;
}

