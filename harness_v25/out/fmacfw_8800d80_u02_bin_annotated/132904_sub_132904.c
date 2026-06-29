// fwstruct annotate: 132904_sub_132904.c
// sub_132904 @ 0x132904, size 1016 bytes
_DWORD *__fastcall sub_132904(int a1)
{
  char v1; // r3
  _DWORD *v2; // r6
  int *v3; // r4
  int *v4; // r7
  int *v5; // r9
  int *v7; // r2
  _DWORD *v8; // r12
  _DWORD *v9; // r0
  int *v10; // r11
  int v11; // t1
  int v12; // r0
  unsigned __int16 *v13; // r10
  int v14; // r1
  unsigned int *v15; // r12
  int v16; // r3
  int v17; // r0
  int v18; // t1
  int v19; // r2
  __int16 v20; // r0
  unsigned int v21; // r2
  unsigned int v22; // r8
  unsigned int v23; // lr
  int v24; // r8
  unsigned int v25; // r8
  unsigned int v26; // r0
  unsigned int v27; // lr
  int v28; // r8
  unsigned int v29; // r10
  __int16 v30; // r2
  unsigned int v31; // r3
  int v32; // r0
  int v33; // r3
  int v34; // r8
  unsigned int *v35; // r12
  unsigned int v36; // r2
  unsigned int v37; // t1
  int v38; // r1
  _DWORD *v39; // r8
  unsigned int *v40; // r6
  int *v41; // r10
  unsigned __int8 *v42; // r7
  int v43; // r2
  unsigned int v44; // r0
  unsigned int v45; // t1
  int v46; // r4
  int v47; // r3
  unsigned int v48; // r2
  _DWORD *v49; // r2
  int v50; // r1
  int v51; // t1
  int v52; // t1
  int *v53; // r3
  int v54; // r3
  unsigned int v56; // r1
  unsigned int v57; // r2
  int v58; // r0
  unsigned int v59; // r0
  int v60; // r0
  int v61; // [sp+14h] [bp-50h]
  int v62; // [sp+18h] [bp-4Ch]
  int v63; // [sp+18h] [bp-4Ch]
  int v64; // [sp+1Ch] [bp-48h]
  BOOL v65; // [sp+20h] [bp-44h]
  int v66; // [sp+20h] [bp-44h]
  int v67; // [sp+24h] [bp-40h]
  unsigned int v68; // [sp+24h] [bp-40h]
  _DWORD *v69; // [sp+24h] [bp-40h]
  int v70; // [sp+28h] [bp-3Ch]
  int v71; // [sp+28h] [bp-3Ch]
  unsigned int v72; // [sp+2Ch] [bp-38h]
  char *v73; // [sp+30h] [bp-34h]
  char v74; // [sp+34h] [bp-30h]
  unsigned int v75; // [sp+3Ch] [bp-28h]
  _BYTE v76[16]; // [sp+40h] [bp-24h] BYREF
  _DWORD v77[5]; // [sp+50h] [bp-14h] BYREF

  v1 = *(_BYTE *)(a1 + 350);
  v2 = *(_DWORD **)(a1 + 336);
  if ( !v1 )
    return v2;
  v70 = v2[15];
  v61 = v2[1];
  v3 = v2 + 5;
  v64 = v2[2];
  v4 = (int *)v76;
  v5 = v77;
  v7 = v2 + 5;
  v8 = v76;
  v9 = v77;
  v10 = v2 + 9;
  do
  {
    v11 = *v7++;
    *v8++ = v11;
    *v9++ = v7[3];
  }
  while ( v10 != v7 );
  v62 = v1 & 1;
  if ( (v1 & 1) == 0 )
    goto LABEL_23;
  v12 = *(_DWORD *)(a1 + 340);
  v67 = *((unsigned __int8 *)off_132C2C + 359);
  v75 = *(unsigned __int8 *)(a1 + 312);
  v73 = (char *)off_132C2C + 356;
  v74 = v1;
  v65 = 0;
  v13 = (unsigned __int16 *)(v12 + 136);
  v72 = 0;
  v14 = 0;
  v15 = (unsigned int *)v76;
  v16 = v12;
  do
  {
    v18 = *v13++;
    v17 = v18;
    if ( !v67 || v14 == 3 )
      v19 = 0x40000000;
    else
      v19 = (unsigned __int8)v73[v14] << 29;
    v20 = *(_WORD *)(v16 + 12 * v17 + 10);
    v21 = v20 & 0x3FFF | v19;
    if ( ((v21 >> 11) & 6) != 0 )
    {
      v22 = (v21 >> 11) & 7;
      v23 = v21 & 0x7F;
      if ( v22 == 4 )
      {
        v27 = v23 >> 4;
      }
      else
      {
        if ( v22 <= 4 )
        {
          v27 = (v23 >> 3) & 3;
          if ( v14 )
          {
LABEL_20:
            if ( v65 )
              v65 = v27 == v72;
LABEL_22:
            *v15 = *v15 & 0x1FFFC000 | v21;
            goto LABEL_57;
          }
LABEL_65:
          v59 = v72;
          if ( v27 < v75 )
            v59 = v27;
          v72 = v59;
          v60 = v65;
          if ( v27 < v75 )
            v60 = 1;
          v65 = v60;
          goto LABEL_22;
        }
        if ( (v21 & 0x600) == 0x400 )
          v24 = 0x20000;
        else
          v24 = 0x10000;
        v25 = v77[v14] & 0xFFFCFFFF | v24;
        if ( (v20 & 0x4000) != 0 )
          v26 = v25 | 0x40000;
        else
          v26 = v25 & 0xFFFBFFFF;
        v77[v14] = v26;
        v27 = v23 >> 4;
      }
      if ( v14 )
        goto LABEL_20;
      goto LABEL_65;
    }
    v62 = 0;
    *v15 = *v15 & 0x1FFFC000 | v21;
LABEL_57:
    ++v14;
    ++v15;
  }
  while ( v14 != 4 );
  v56 = v61 & 0xFFFFFE7F;
  v61 &= 0xFFFFFE7F;
  v3 = v2 + 5;
  if ( v65 )
    v61 = v56 | ((v72 + 1) << 7);
  if ( v62 )
    v57 = v70 | 8;
  else
    v57 = v70 & 0xFFFFFFF7;
  v1 = v74 | 2;
  v2[15] = v57;
  *(_BYTE *)(a1 + 350) = v74 | 2;
LABEL_23:
  if ( (v1 & 0x20) != 0 )
  {
    v28 = *(_DWORD *)(a1 + 340);
    v29 = v2[9];
    v66 = v2[5];
    v71 = v28 + 12 * *(unsigned __int8 *)(v28 + 164);
    v30 = *(_WORD *)(v71 + 10);
    v31 = v30 & 0x3FFF | 0x40000000;
    v68 = v31;
    if ( *((_BYTE *)off_132C2C + 197) && (v2[5] & 0x387F) != (v31 & 0x387F) )
    {
      v32 = sub_101D58(
              (v31 >> 11) & 7,
              v30 & 0x7F,
              (unsigned __int8 *)(*(_DWORD *)(dword_132C30 + 1320 * *(unsigned __int8 *)(a1 + 34) + 72) + 4));
      v30 = *(_WORD *)(v71 + 10);
      v29 = v32 | (v32 << 8) | (HIWORD(v29) << 16);
    }
    v33 = dword_132C34;
    *(_DWORD *)(v28 + 160) = v29;
    *(_BYTE *)(v28 + 165) = (v30 & 0x4000) != 0;
    *(_DWORD *)(v28 + 156) = v66 & v33 | v68;
    if ( sub_12EA5C(5u, 4u) )
      sub_12EA88(dword_132C38, *(_DWORD *)(v28 + 156), v29);
    sub_140338(v2, *(_DWORD *)(v28 + 156));
    v1 = *(_BYTE *)(a1 + 350);
  }
  if ( (v1 & 2) != 0 )
  {
    v34 = dword_132C48;
    v35 = (unsigned int *)v76;
    do
    {
      v37 = *v35++;
      v36 = v37;
      v38 = v37 & v34;
      if ( v37 & 0x7C | (v37 >> 11) & 7 )
        *(v35 - 1) = v38 | *(_DWORD *)(a1 + 344) | (((v36 >> 7) & 3) << 24);
    }
    while ( v77 != v35 );
  }
  if ( (v1 & 0x10) != 0 )
  {
    v63 = dword_132C30 + 1320 * *(unsigned __int8 *)(a1 + 34);
    v69 = v2;
    v39 = v77;
    v40 = (unsigned int *)v76;
    v41 = v3;
    v42 = (unsigned __int8 *)off_132C2C;
    do
    {
      v43 = v42[197];
      v45 = *v40++;
      v44 = v45;
      v46 = HIWORD(*v39) << 16;
      *v39++ = v46;
      if ( v43 )
      {
        v58 = sub_101D58((v44 >> 11) & 7, v44 & 0x7F, (unsigned __int8 *)(*(_DWORD *)(v63 + 72) + 4));
        *(v39 - 1) = v46 | v58 | (v58 << 8);
      }
      else if ( **(__int16 **)off_132C3C < 0 )
      {
        sub_12F46C(dword_132D00, dword_132CFC, 986);
      }
    }
    while ( v77 != v40 );
    v4 = (int *)v76;
    v2 = v69;
    v1 = *(_BYTE *)(a1 + 350);
    v3 = v41;
  }
  if ( (v1 & 0x40) != 0 )
  {
    v47 = *(_DWORD *)(dword_132C30 + 1320 * *(unsigned __int8 *)(a1 + 34) + 468);
    v48 = v64 & 0xFC0FFFFF;
    v64 &= 0xFC0FFFFF;
    if ( v47 >= 0 )
      v64 = v48 | ((HIBYTE(v47) & 0x3F) << 20);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_132C40 = 1;
  }
  v49 = off_132C44;
  v50 = *(_DWORD *)off_132C44;
  v2[1] = v61;
  v2[2] = v64;
  *v49 = v50 + 1;
  do
  {
    v51 = *v4++;
    *v3++ = v51;
    v52 = *v5++;
    v3[3] = v52;
  }
  while ( v10 != v3 );
  if ( v50 != -1 )
  {
    v53 = (int *)off_132C40;
    *v49 = v50;
    v54 = *v53;
    if ( !v50 )
    {
      if ( v54 )
        __enable_irq();
    }
  }
  *(_BYTE *)(a1 + 350) = 0;
  return v2;
}

