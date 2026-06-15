// v23 annotated: sub_131688 @ 0x131688
// Original: 131688_sub_131688.c
// Primary struct: <unclustered>
//
// sub_131688 @ 0x131688, size 226 bytes
int __fastcall sub_131688(int a1, int *a2, __int16 a3, __int16 a4)
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

  if ( sub_12CE88(5u) == 1 )
    return 2;
  v7 = sub_12C92C(5138, a4, a3, 0xCu);
  if ( **(__int16 **)off_13176C < 0 )
  {
    v14 = (unsigned __int8 *)off_131770;
    v8 = *((unsigned __int8 *)off_131770 + 16);
    if ( v8 == 255 )
    {
      sub_12F46C(dword_13177C, dword_131778, 1092);
      v8 = v14[16];
    }
  }
  else
  {
    v8 = *((unsigned __int8 *)off_131770 + 16);
  }
  if ( sub_101A0C() )
    sub_101A20(*((unsigned __int8 *)a2 + 11));
  v9 = dword_131774 + 1320 * v8;
  v10 = *(_DWORD *)(v9 + 72);
  if ( v10 )
  {
    *(_BYTE *)v7 = *(_BYTE *)(v10 + 24);
    if ( *((_BYTE *)a2 + 10) )
    {
      if ( sub_12D36C((_DWORD **)dword_131780) == 1 )
      {
        v15 = sub_12C92C(59, 0, 5, 0xCu);
        *(_BYTE *)v15 = *(_BYTE *)(*(_DWORD *)(v9 + 72) + 24);
        v16 = *((_WORD *)a2 + 4);
        v17 = a2[1];
        *(_DWORD *)(v15 + 2) = *a2;
        *(_WORD *)(v15 + 10) = v16;
        *(_DWORD *)(v15 + 6) = v17;
        sub_12C98C(v15);
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
    sub_12C98C(v7);
    return 0;
  }
  *(_BYTE *)v7 = -1;
  sub_12C98C(v7);
  return 0;
}

