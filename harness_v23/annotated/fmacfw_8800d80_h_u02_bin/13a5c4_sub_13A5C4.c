// v23 annotated: sub_13A5C4 @ 0x13a5c4
// Original: 13a5c4_sub_13A5C4.c
// Primary struct: <unclustered>
//
// sub_13A5C4 @ 0x13a5c4, size 626 bytes
int __fastcall sub_13A5C4(int a1, int a2)
{
  int v2; // r11
  int v3; // r10
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r3
  int v8; // lr
  int v10; // r2
  int v12; // r4
  __int16 v13; // r3
  int v14; // r1
  int v15; // r0
  __int16 v16; // r1
  int v17; // r0
  int v18; // r3
  int v19; // r12
  int v20; // r3
  int v21; // r3
  int v22; // r3
  __int16 v24; // lr
  __int16 v25; // r3
  __int16 v26; // r3
  int v27; // r6
  int v28; // r6
  int v29; // r0
  __int16 v30; // r3
  int v31; // [sp+4h] [bp-10h]
  int v32; // [sp+8h] [bp-Ch]
  int v33; // [sp+Ch] [bp-8h]

  v2 = *(unsigned __int8 *)(a1 + 29);
  v3 = dword_13A83C;
  v4 = *(unsigned __int8 *)(a1 + 28);
  v5 = dword_13A838;
  v6 = 696 * v2;
  v7 = dword_13A83C + 696 * v2;
  v8 = dword_13A838 + 1320 * v4;
  v32 = *(_DWORD *)(v7 + 184);
  v10 = **(_DWORD **)(v7 + 188);
  v31 = *(_DWORD *)(v8 + 1200);
  v12 = a2 - *(unsigned __int8 *)(a1 + 50);
  if ( *(_BYTE *)(v8 + 106) )
  {
    v13 = 0;
  }
  else
  {
    if ( (*(_DWORD *)(v7 + 4) & 0x20) == 0 )
    {
      v13 = 0;
      v14 = *(unsigned __int8 *)(a1 + 27);
      if ( v14 == 255 )
        goto LABEL_4;
      goto LABEL_26;
    }
    v33 = **(_DWORD **)(v7 + 188);
    v29 = sub_11C224(a1, dword_13A83C + 696 * v2);
    v10 = v33;
    *(_DWORD *)(a2 - 4) = v29;
    v13 = 0x8000;
  }
  v14 = *(unsigned __int8 *)(a1 + 27);
  if ( v14 == 255 )
  {
LABEL_4:
    v15 = *(unsigned __int16 *)(a1 + 30);
    *(_WORD *)v12 = v13 | 8;
    *(_BYTE *)(v12 + 22) = 0;
    *(_BYTE *)(v12 + 23) = 0;
    v16 = v13 | 8;
    if ( (v15 & 0x800) != 0 )
    {
LABEL_5:
      v16 = v13 & 0xFCF7 | 8;
      *(_WORD *)v12 = v16;
      goto LABEL_6;
    }
    if ( (v15 & 0x100) != 0 )
      goto LABEL_30;
    goto LABEL_32;
  }
LABEL_26:
  v15 = *(unsigned __int16 *)(a1 + 30);
  *(_WORD *)(v12 + 22) = 16 * *(_WORD *)(a1 + 32);
  *(_BYTE *)(v12 + 1) = 0;
  if ( (v15 & 0x200) != 0 )
    LOWORD(v14) = v14 | 0x10;
  *(_BYTE *)v12 = 0x80;
  v24 = v13 | 0x88;
  if ( (v15 & 0x100) != 0 )
  {
    *(_WORD *)(v12 + 30) = v14;
    v13 |= 0x80u;
    *(_WORD *)v12 = v24;
    if ( (v15 & 0x800) != 0 )
      goto LABEL_5;
LABEL_30:
    v25 = v13 | 0x308;
    *(_WORD *)v12 = v25;
    v16 = v25;
    goto LABEL_6;
  }
  *(_WORD *)(v12 + 24) = v14;
  v13 |= 0x80u;
  *(_WORD *)v12 = v24;
  v16 = v24;
  if ( (v15 & 0x800) != 0 )
    goto LABEL_5;
LABEL_32:
  if ( *(_BYTE *)(v5 + 1320 * v4 + 106) )
  {
    if ( *(_BYTE *)(v5 + 1320 * v4 + 106) == 2 )
    {
      v30 = v13 | 0x208;
      *(_WORD *)v12 = v30;
      v16 = v30;
    }
  }
  else
  {
    v26 = v13 | 0x108;
    *(_WORD *)v12 = v26;
    v16 = v26;
  }
LABEL_6:
  v17 = v15 << 29;
  v18 = 1320 * v4;
  if ( v17 < 0 )
    v16 |= 0x2000u;
  v19 = v18 + 100;
  if ( v17 < 0 )
    *(_WORD *)v12 = v16;
  *(_WORD *)(v12 + 10) = *(_WORD *)(v5 + v19);
  *(_WORD *)(v12 + 12) = *(_WORD *)(v5 + v19 + 2);
  *(_WORD *)(v12 + 14) = *(_WORD *)(v5 + v19 + 4);
  if ( (v16 & 0x300) == 0x100 )
  {
    v27 = v6 + 38;
    *(_WORD *)(v12 + 4) = *(_WORD *)(v3 + v27);
    *(_WORD *)(v12 + 6) = *(_WORD *)(v3 + v27 + 2);
    *(_WORD *)(v12 + 8) = *(_WORD *)(v3 + v27 + 4);
    *(_WORD *)(v12 + 16) = *(_WORD *)(a1 + 12);
    *(_WORD *)(v12 + 18) = *(_WORD *)(a1 + 14);
    *(_WORD *)(v12 + 20) = *(_WORD *)(a1 + 16);
  }
  else if ( (v16 & 0x300) == 0x200 )
  {
    *(_WORD *)(v12 + 4) = *(_WORD *)(a1 + 12);
    *(_WORD *)(v12 + 6) = *(_WORD *)(a1 + 14);
    *(_WORD *)(v12 + 8) = *(_WORD *)(a1 + 16);
    *(_WORD *)(v12 + 16) = *(_WORD *)(a1 + 18);
    *(_WORD *)(v12 + 18) = *(_WORD *)(a1 + 20);
    *(_WORD *)(v12 + 20) = *(_WORD *)(a1 + 22);
  }
  else if ( (v16 & 0x300) != 0 )
  {
    v28 = v6 + 38;
    *(_WORD *)(v12 + 4) = *(_WORD *)(v3 + v28);
    *(_WORD *)(v12 + 6) = *(_WORD *)(v3 + v28 + 2);
    *(_WORD *)(v12 + 8) = *(_WORD *)(v3 + v28 + 4);
    *(_WORD *)(v12 + 16) = *(_WORD *)(a1 + 12);
    *(_WORD *)(v12 + 18) = *(_WORD *)(a1 + 14);
    *(_WORD *)(v12 + 20) = *(_WORD *)(a1 + 16);
    *(_WORD *)(v12 + 24) = *(_WORD *)(a1 + 18);
    *(_WORD *)(v12 + 26) = *(_WORD *)(a1 + 20);
    *(_WORD *)(v12 + 28) = *(_WORD *)(a1 + 22);
  }
  else
  {
    *(_WORD *)(v12 + 4) = *(_WORD *)(a1 + 12);
    *(_WORD *)(v12 + 6) = *(_WORD *)(a1 + 14);
    *(_WORD *)(v12 + 8) = *(_WORD *)(a1 + 16);
    v20 = v18 + 368;
    *(_WORD *)(v12 + 16) = *(_WORD *)(v5 + v20);
    v21 = v20 + v5;
    *(_WORD *)(v12 + 18) = *(_WORD *)(v21 + 2);
    *(_WORD *)(v12 + 20) = *(_WORD *)(v21 + 4);
  }
  if ( v10
    && v31
    && ((*(_DWORD *)(v5 + 1320 * v4 + 1208) & 2) == 0
     || *(unsigned __int16 *)(v3 + 696 * *(unsigned __int8 *)(a1 + 29) + 56) != (unsigned __int16)__rev16(*(unsigned __int16 *)(a1 + 24))) )
  {
    if ( !v32
      || (v22 = *(unsigned __int8 *)(v32 + 96), v22 == 4)
      || (unsigned int)(v22 - 1) <= 1 && *(unsigned __int8 *)(v3 + 696 * v2 + 669) > 1u )
    {
      *(_WORD *)v12 = v16 | 0x4000;
    }
  }
  return v12;
}

