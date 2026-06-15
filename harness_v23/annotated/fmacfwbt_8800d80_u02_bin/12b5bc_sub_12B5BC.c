// v23 annotated: sub_12B5BC @ 0x12b5bc
// Original: 12b5bc_sub_12B5BC.c
// Primary struct: <unclustered>
//
// sub_12B5BC @ 0x12b5bc, size 312 bytes
// Doc: sub_122B5BC [rf]: Read RF status bytes and dispatch to message handler
// sub_122B5BC [rf]: Read RF status bytes and dispatch to message handler
void sub_12B5BC()
{
  int v0; // r5
  char *v1; // r6
  int v2; // r7
  int v3; // r0
  int v4; // r0
  char *v5; // r2
  int v6; // r1
  _WORD *v7; // lr
  int v8; // r3
  __int16 v9; // r4
  int *v10; // r9
  int v11; // r12
  __int16 v12; // r10
  int v13; // r0
  int v14; // r0
  __int16 v15; // r10
  int v16; // r0
  int v17; // r3
  char v18; // t1
  int v19; // r2
  int v20; // r3
  int v21; // [sp+0h] [bp-Ch]
  int v22; // [sp+4h] [bp-8h]

  v0 = *(_DWORD *)off_12B6F4;
  v22 = *((unsigned __int8 *)off_12B6F4 + 10);
  if ( *(_BYTE *)(*(_DWORD *)off_12B6F4 + 368) )
  {
    v21 = dword_12B6F8 + 1320 * *(unsigned __int8 *)(*(_DWORD *)off_12B6F4 + 366);
    v1 = (char *)(v0 + 253);
    v2 = 0;
    do
    {
      if ( *(_BYTE *)(v21 + 1224) || *(_BYTE *)(v0 + 6 * v22 + 2) )
      {
        v3 = 1;
      }
      else
      {
        v3 = *(unsigned __int8 *)(v0 + 369);
        if ( *(_BYTE *)(v0 + 369) )
          v3 = 1;
      }
      v4 = sub_119084(v3, *(unsigned __int16 *)(v0 + 364) + (unsigned __int8)*(v1 - 1) + 26);
      v5 = v1;
      v6 = v4;
      if ( !v4 )
        break;
      v7 = off_12B700;
      v8 = *(_DWORD *)(v4 + 72);
      v9 = *((_WORD *)off_12B700 + 254);
      v10 = (int *)off_12B704;
      v11 = *(_DWORD *)(v4 + 76);
      v12 = *((_WORD *)off_12B704 + 2);
      *(_DWORD *)(v8 + 118) = *(_DWORD *)(v21 + 100);
      v13 = *v10;
      LOWORD(v10) = *(_WORD *)(v21 + 104);
      *(_DWORD *)(v8 + 112) = v13;
      ++v9;
      v14 = *(_DWORD *)(v0 + 352);
      *(_WORD *)(v8 + 116) = v12;
      v15 = *(_WORD *)(v0 + 356);
      *(_WORD *)(v8 + 122) = (_WORD)v10;
      *(_DWORD *)(v8 + 124) = v14;
      *(_BYTE *)(v8 + 108) = 64;
      *(_WORD *)(v8 + 128) = v15;
      *(_BYTE *)(v8 + 109) = 0;
      *(_BYTE *)(v8 + 110) = 0;
      *(_BYTE *)(v8 + 111) = 0;
      v7[254] = v9;
      *(_BYTE *)(v8 + 132) = 0;
      *(_BYTE *)(v8 + 133) = *(v1 - 1);
      v16 = (unsigned __int8)*(v1 - 1);
      *(_WORD *)(v8 + 130) = 16 * v9;
      if ( v16 )
      {
        v17 = v8 + 133;
        do
        {
          v18 = *v5++;
          *(_BYTE *)++v17 = v18;
        }
        while ( v5 != &v1[v16] );
      }
      v19 = *(unsigned __int16 *)(v0 + 364);
      v20 = *(_DWORD *)(v11 + 32);
      *(_DWORD *)(v11 + 24) = dword_12B6FC;
      *(_DWORD *)(v11 + 32) = v20 - v19;
      *(_DWORD *)(v6 + 88) = 0;
      *(_DWORD *)(v6 + 92) = 0;
      *(_BYTE *)(v6 + 28) = *(_BYTE *)(v0 + 366);
      *(_BYTE *)(v6 + 29) = -1;
      sub_1190B4(v6, 5);
      ++v2;
      v1 += 33;
    }
    while ( *(unsigned __int8 *)(v0 + 368) > v2 );
  }
}

