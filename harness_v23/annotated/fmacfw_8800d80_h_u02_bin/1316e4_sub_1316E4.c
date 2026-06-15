// v23 annotated: sub_1316E4 @ 0x1316e4
// Original: 1316e4_sub_1316E4.c
// Primary struct: <unclustered>
//
// sub_1316E4 @ 0x1316e4, size 238 bytes
int __fastcall sub_1316E4(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  int v6; // r2
  int v7; // r6
  int v8; // r5
  __int16 v9; // r0
  __int16 v10; // r1
  __int16 v11; // r2
  unsigned __int16 v12; // r4
  int v13; // r0
  unsigned int v14; // r2
  int v15; // r1
  int v16; // r2
  int *v17; // r4
  int v18; // r3
  int v19; // r0
  int v20; // r3
  int v21; // r3
  int v22; // r2

  v5 = sub_12C7EC(5135, a4, a3, 0xC8u);
  v6 = *a2;
  v7 = v5;
  v8 = *(_DWORD *)(dword_1317D4 + 696 * v6 + 340);
  *(_BYTE *)v5 = v6;
  if ( v8 )
  {
    v9 = *(_WORD *)(v8 + 184);
    v10 = *(_WORD *)(v8 + 144);
    v11 = *(_WORD *)(v8 + 146);
    *(_DWORD *)(v7 + 8) = *(_DWORD *)(v8 + 148);
    *(_WORD *)(v7 + 2) = v9;
    *(_WORD *)(v7 + 4) = v10;
    *(_WORD *)(v7 + 6) = v11;
    *(_BYTE *)(v7 + 12) = *(_BYTE *)(v8 + 168);
    *(_BYTE *)(v7 + 13) = *(_WORD *)(v8 + 152);
    sub_143630(v7 + 14, v8 + 136, 8);
    sub_143630(v7 + 22, v8 + 4, 120);
    if ( *(_WORD *)(v8 + 184) )
    {
      v12 = 0;
      do
      {
        v13 = sub_13F370(v8, (unsigned __int8)v12, 0);
        v14 = *(unsigned __int16 *)(v8 + 184);
        *(_DWORD *)(v7 + 4 * v12++ + 156) = v13;
      }
      while ( v14 > v12 );
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_1317D8 = 1;
    }
    v15 = *(_DWORD *)(v8 + 128);
    v16 = *(_DWORD *)(v8 + 132);
    v17 = (int *)off_1317DC;
    *(_DWORD *)(v7 + 142) = *(_DWORD *)(v8 + 124);
    v18 = *v17;
    *(_DWORD *)(v7 + 146) = v15;
    *(_DWORD *)(v7 + 150) = v16;
    *v17 = v18 + 1;
    v19 = sub_13F370(v8, 10, 0);
    v20 = *v17;
    *(_DWORD *)(v7 + 196) = v19;
    if ( v20 )
    {
      v21 = v20 - 1;
      v22 = *(_DWORD *)off_1317D8;
      *v17 = v21;
      if ( !v21 )
      {
        if ( v22 )
          __enable_irq();
      }
    }
    sub_12C84C(v7);
    return 0;
  }
  else
  {
    *(_WORD *)(v5 + 2) = 0;
    sub_12C84C(v5);
    return 0;
  }
}

