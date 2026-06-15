// sub_119E08 @ 0x119e08, size 868 bytes
int __fastcall sub_119E08(int a1, int *a2, unsigned int a3, unsigned int a4, unsigned __int8 a5)
{
  int v5; // r5
  int v7; // r4
  int v8; // s16
  int v9; // r6
  int v10; // r11
  void *v12; // r10
  int v13; // r3
  int v14; // r0
  int v15; // r7
  unsigned int v16; // r2
  char v17; // r7
  unsigned int v18; // r11
  unsigned int v19; // r3
  unsigned int v20; // r8
  __int16 v21; // r0
  __int16 v22; // r1
  int v23; // r3
  int v24; // r12
  unsigned int v25; // lr
  int v26; // r3
  int v27; // r2
  char v28; // lr
  int v29; // r1
  int v30; // r3
  int v31; // r3
  int v32; // r7
  int v33; // r3
  bool v34; // zf
  int v35; // r3
  int v36; // r3
  int v37; // r3
  char v38; // r2
  int v39; // r1
  int v40; // r3
  int v42; // r2
  int v43; // r6
  unsigned int v44; // r3
  unsigned int v45; // r7
  int v47; // [sp+8h] [bp-1Ch]
  _DWORD *v48; // [sp+Ch] [bp-18h]
  char v50; // [sp+18h] [bp-Ch]
  int v51; // [sp+1Ch] [bp-8h]

  v5 = *(_DWORD *)(a1 + 68);
  v51 = *(_DWORD *)(v5 + 324);
  v50 = *(_BYTE *)(*(_DWORD *)(v51 + 76) + 1);
  v7 = *a2;
  v8 = dword_11A108 + 84 * a5 + 28;
  v9 = *(_DWORD *)(*a2 + 68);
  v10 = *(_DWORD *)(*a2 + 76);
  sub_12D4F8(v8);
  if ( !sub_119B20(a1, v7, a5)
    || (v12 = off_11A124, *(unsigned __int8 *)(*(_DWORD *)off_11A124 + 62) > (*(_DWORD *)off_11A10C & 0x3Fu)) )
  {
    sub_12D4B8(v8, v5);
    return 0;
  }
  v13 = *(_DWORD *)(v51 + 36);
  v14 = *(_DWORD *)(v51 + 76);
  v15 = *a2;
  v48 = off_11A10C;
  *(_DWORD *)(v14 + 20) = v10 + 12;
  *(_DWORD *)(v51 + 36) = v13 & 0xFFC7FFFF | 0x300000;
  v47 = 0;
  v16 = *(_DWORD *)(v7 + 36) & 0xFFC7FFFF | 0x300000;
  *(_DWORD *)(v14 + 68) = v13 & 0xFFC7FEFF | 0x300100;
  *(_DWORD *)(v7 + 36) = v16;
  *(_DWORD *)(v10 + 68) = *(_DWORD *)(v15 + 36) | 0x100;
  v17 = 0;
  v18 = 0;
  while ( 1 )
  {
    v24 = *(_DWORD *)(v7 + 76);
    v19 = (unsigned __int16)(((*(_DWORD *)(v24 + 36) + 3) & 0xFFFC) + 4);
    v25 = (unsigned __int16)(v19 + 4 * ((v16 >> 9) & 0x3FF));
    if ( v25 < a4 )
      break;
    v19 = (unsigned __int16)(v19 + 4 * ((v16 >> 9) & 0x3FF));
    v20 = v25 + *(_DWORD *)(v5 + 40);
    if ( v20 > a3 )
      goto LABEL_17;
LABEL_7:
    if ( *(unsigned __int8 *)(*(_DWORD *)v12 + 62) > (*v48 & 0x3Fu) )
      goto LABEL_17;
    if ( *(_DWORD *)(v24 + 28) )
      *(_DWORD *)(*(_DWORD *)(v24 + 32) - 3) = *((_DWORD *)off_11A110 + 43);
    v21 = *(_WORD *)(v7 + 80);
    v22 = *(_WORD *)(v5 + 10);
    *(_DWORD *)(v7 + 68) = v5;
    *(_WORD *)(v5 + 10) = v22 + v21;
    *(_WORD *)(v9 + 10) -= v21;
    if ( v25 < a4 )
    {
      v16 = *(_DWORD *)(v24 + 68) & 0xFFF801FF | (v18 << 9);
      *(_DWORD *)(v7 + 36) = v16;
      v19 = v25;
      *(_DWORD *)(v24 + 68) = v16 | 0x100;
    }
    *(_DWORD *)(v5 + 40) = v20;
    *(_DWORD *)(v9 + 40) -= v19;
    if ( (v16 & 0x380000) == 0x380000 )
    {
      v37 = dword_11A108 + 84 * a5;
      v38 = *(_BYTE *)(v37 + 80);
      v39 = *(_DWORD *)off_11A118;
      *(_DWORD *)(v5 + 324) = v7;
      *(_BYTE *)(v37 + 80) = v38 - 1;
      if ( !*(_BYTE *)(v39 + 1) )
        *(_DWORD *)(v5 + 20) = *(_DWORD *)(v9 + 20);
      *(_BYTE *)(v24 + 1) = v50 + v17;
      sub_12D4F8(v8);
      sub_12D470(*(_DWORD *)(v9 + 340));
      v40 = *(_DWORD *)(v7 + 76);
      *a2 = *(_DWORD *)v7;
      *(_DWORD *)(v40 + 20) = 0;
      v32 = 1;
      goto LABEL_34;
    }
    v23 = *(_DWORD *)v7;
    if ( **(__int16 **)off_11A114 < 0 && !v23 )
    {
      sub_12F694(dword_11A120, dword_11A11C, 1713);
      v23 = 0;
    }
    v16 = *(_DWORD *)(v23 + 36);
    v47 = v7;
    ++v17;
    v7 = v23;
  }
  if ( v19 >= a4 )
  {
    v18 = 0;
  }
  else
  {
    v18 = ((unsigned int)(unsigned __int16)(a4 - v19) + 3) >> 2;
    v19 = (unsigned __int16)(v19 + 4 * v18);
  }
  v20 = v19 + *(_DWORD *)(v5 + 40);
  if ( v20 <= a3 )
    goto LABEL_7;
LABEL_17:
  if ( v47 )
  {
    v26 = dword_11A108 + 84 * a5;
    v27 = *(_DWORD *)(v47 + 36);
    v28 = *(_BYTE *)(v26 + 80);
    v29 = *(_DWORD *)(v47 + 76);
    *(_DWORD *)(v5 + 324) = v47;
    v27 |= 0x380000u;
    *(_DWORD *)(v47 + 36) = v27;
    *(_DWORD *)(v29 + 68) = v27 | 0x100;
    *(_DWORD *)(v29 + 20) = 0;
    *(_BYTE *)(v26 + 80) = v28 - 1;
    *(_BYTE *)(v29 + 1) = v50 + v17;
    *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v9 + 324) + 76) + 1) -= v17;
    v30 = *(_DWORD *)(v7 + 36);
    LOWORD(v27) = *(_WORD *)(v9 + 8);
    *(_DWORD *)(v9 + 268) = v7;
    *(_WORD *)(v9 + 8) = v27 | 0x400;
    if ( (v30 & 0x380000) == 0x380000 )
      sub_12D4F8(v8);
    v31 = *(_DWORD *)off_11A118;
    *a2 = v7;
    v32 = *(unsigned __int8 *)(v31 + 1);
    if ( *(_BYTE *)(v31 + 1) )
    {
      v32 = 0;
    }
    else
    {
      v33 = *(_DWORD *)(v7 + 36) & 0x380000;
      v34 = v33 == 3670016;
      if ( v33 == 3670016 )
        v35 = *(_DWORD *)(v7 + 76);
      else
        v35 = *(_DWORD *)(v7 + 68);
      if ( v34 )
        v36 = v35 + 12;
      else
        v36 = v35 + 16;
      *(_DWORD *)(v5 + 20) = v36;
    }
LABEL_34:
    sub_12D4B8(v8, v5);
    return v32;
  }
  v42 = *(_DWORD *)(v51 + 36);
  v43 = *(_DWORD *)(v51 + 76);
  *(_DWORD *)(v43 + 20) = 0;
  *(_DWORD *)(v51 + 36) = v42 | 0x380000;
  v44 = *(_DWORD *)(v7 + 36) & 0xFFC7FFFF | 0x280000;
  v45 = *(_DWORD *)(v7 + 36) & 0xFFC7FEFF | 0x280100;
  *(_DWORD *)(v43 + 68) = v42 | 0x380100;
  *(_DWORD *)(v7 + 36) = v44;
  *(_DWORD *)(v24 + 68) = v45;
  sub_12D4B8(v8, v5);
  v32 = 0;
  *a2 = v7;
  return v32;
}

