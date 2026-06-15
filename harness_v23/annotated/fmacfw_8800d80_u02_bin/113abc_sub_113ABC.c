// v23 annotated: sub_113ABC @ 0x113abc
// Original: 113abc_sub_113ABC.c
// Primary struct: <unclustered>
//
// sub_113ABC @ 0x113abc, size 264 bytes
int __fastcall sub_113ABC(int a1)
{
  void *v1; // r5
  _DWORD *v2; // r1
  int *v3; // r2
  _DWORD *v4; // r3
  _WORD *v5; // r6
  int *v6; // r0
  _DWORD *v7; // r2
  _DWORD *v8; // r3
  _DWORD *v9; // r4
  _BYTE *v10; // r3
  int v11; // r5
  int v12; // r0
  int v13; // r1
  _DWORD *v14; // r6
  int *v15; // r2
  _BYTE *v16; // r4
  int v17; // r1
  _BYTE *v18; // r5
  bool v19; // cc
  char v20; // r0
  int v21; // r3
  void *v22; // r2
  int v23; // r0
  int v25; // r0

  v1 = off_113BC4;
  v2 = off_113BCC;
  v3 = *(int **)(*(_DWORD *)off_113BC4 + 16);
  v4 = off_113BD0;
  *(_DWORD *)off_113BC8 = v3;
  *v2 = v3 + 16;
  v5 = off_113BD4;
  v4[2] = a1;
  *v4 = 0;
  v4[1] = 0;
  v4[4] = 0;
  v4[5] = 0;
  v4[3] = 0;
  v5[6] = 0;
  sub_100200(v3, 0, 0x140u);
  v6 = *(int **)(*(_DWORD *)v1 + 20);
  v7 = off_113BDC;
  v8 = off_113BE0;
  *(_DWORD *)off_113BD8 = v6;
  *v7 = v6 + 2;
  *v8 = v6 + 4;
  v8[1] = v6 + 6;
  v8[2] = v6 + 8;
  v8[3] = v6 + 10;
  v9 = off_113BE4;
  v8[4] = v6 + 12;
  *v9 = v6 + 14;
  sub_100200(v6, 0, 0xCB8u);
  if ( **(__int16 **)off_113BE8 < 0 && *(_DWORD *)(*(_DWORD *)v1 + 24) <= 0xCB7u )
    sub_12F46C(dword_113C1C, dword_113C18, 758);
  v10 = off_113BEC;
  v11 = *((unsigned __int16 *)off_113BEC + 164);
  v12 = *((unsigned __int16 *)off_113BEC + 154);
  v13 = dword_113BF4;
  v14 = off_113BF8;
  *(_DWORD *)off_113BFC = *((unsigned __int16 *)off_113BEC + 153) - *(_DWORD *)off_113BF0 - 4;
  v15 = (int *)off_113C00;
  v16 = off_113C04;
  v17 = v13 * v11;
  v18 = off_113C08;
  *v14 = v12 - 4;
  v19 = v17 <= (int)v15;
  if ( v17 > (int)v15 )
    v17 = (int)off_113C0C;
  else
    v15 = (int *)off_113C0C;
  *v18 = v10[320];
  v20 = v10[321];
  v21 = (unsigned __int8)v10[368];
  *v16 = v20;
  if ( v19 )
    *v15 = v17;
  else
    *(_DWORD *)v17 = v15;
  if ( v21 )
  {
    v22 = off_113C10;
    v23 = dword_113C14;
    *(_BYTE *)off_113C10 = v21;
    sub_12EA88(v23, v21, v22);
  }
  else
  {
    v25 = dword_113C14;
    *(_BYTE *)off_113C10 = 10;
    sub_12EA88(v25, 10, v15);
  }
  return 1;
}

