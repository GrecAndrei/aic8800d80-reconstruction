// sub_10A5B0 @ 0x10a5b0, size 1610 bytes
// Doc: sub_120A5B0 [rf]: RF register setup routine touching 0x40344xxx MMIO block with FP context
// sub_120A5B0 [rf]: RF register setup routine touching 0x40344xxx MMIO block with FP context
int  sub_10A5B0(unsigned int a1, unsigned int a2, int a3, unsigned int a4, unsigned __int8 a5, char a6)
{
  unsigned int v8; // s17
  int v9; // r3
  uint32_t *v10; // r2
  uint32_t *v11; // r5
  uint32_t *v12; // r7
  unsigned int *v13; // r3
  unsigned int *v14; // r1
  uint32_t *v15; // r6
  unsigned int *v16; // r11
  unsigned int *v17; // r0
  int v18; // s16
  unsigned int *v19; // r10
  unsigned int v20; // r8
  int v21; // r6
  int v22; // r5
  int v23; // r4
  bool v24; // zf
  unsigned int v25; // r4
  int v26; // r1
  int v27; // r6
  unsigned int v28; // r7
  __int16 v29; // r4
  __int16 v30; // r0
  unsigned int v31; // r2
  unsigned __int8 v32; // r1
  unsigned int i; // r3
  unsigned int v34; // r4
  unsigned int v35; // r9
  uint32_t *v36; // r1
  unsigned int *v37; // r3
  unsigned int *v38; // r1
  __int16 v39; // r3
  int *v40; // r3
  int v41; // r1
  int v42; // r2
  unsigned int *v44; // r3
  int v45; // [sp+24h] [bp-7C0h]
  int v46; // [sp+28h] [bp-7BCh]
  int v47; // [sp+34h] [bp-7B0h]
  int v48; // [sp+38h] [bp-7ACh]
  unsigned int v50; // [sp+44h] [bp-7A0h]
  int v51; // [sp+48h] [bp-79Ch]
  char v54; // [sp+5Ah] [bp-78Ah] BYREF
  char v55; // [sp+5Bh] [bp-789h] BYREF
  int v56; // [sp+5Ch] [bp-788h] BYREF
  int v57; // [sp+60h] [bp-784h] BYREF
  int v58; // [sp+64h] [bp-780h] BYREF
  __int16 v59[6]; // [sp+68h] [bp-77Ch] BYREF
  __int16 v60[952]; // [sp+74h] [bp-770h] BYREF

  sub_11F74C(0x2000, dword_10A8C0, (*(uint32_t *)off_10A8E4 >> 3) & 7, *(uint32_t *)off_10A8B0);
  v8 = ((a1 >> 1) & 1) + 3;
  if ( (a1 & 0xC) != 0 )
  {
    if ( ((a1 >> 2) & 3) == 1 )
      v9 = 5;
    else
      v9 = 10;
    v50 = v9;
  }
  else
  {
    v50 = 1;
  }
  v10 = off_10A8C4;
  v11 = off_10A8C8;
  v12 = off_10A8CC;
  v13 = (unsigned int *)off_10A8D0;
  v14 = (unsigned int *)off_10A8D4;
  v15 = off_10A8D8;
  v16 = (unsigned int *)off_10A8E8;
  *(uint32_t *)off_10A8C4 &= ~4u;
  *v11 &= 0xFFFF0FFF;
  *v12 = 0;
  *v13 |= 0x80u;
  *v14 |= 0x80000000;
  *v10 |= 4u;
  *v15 = HIWORD(*v15) << 16;
  *(v12 - 6154) = *(v12 - 6154) & 0xCFFFFFFF | 0x10000000;
  v17 = (unsigned int *)off_10A8DC;
  *v10 &= ~4u;
  *v14 &= ~0x80000000;
  *v13 &= ~0x80u;
  *v10 |= 4u;
  v15[6223] |= 2u;
  *v13 = *v13 & 0xFFFF8FFF | 0x4000;
  *v13 = *v13 & 0xF8FFFFFF | 0x6000000;
  *v13 = *v13 & 0xFFFFF8FF | 0x100;
  *v13 &= ~4u;
  *v13 |= 1u;
  *v13 |= 8u;
  *v14 = a3 | *v14 & 0x80000000;
  *v17 |= 0x2000000u;
  *v17 |= 0x10000u;
  v45 = 0;
  v51 = ((v10[2069] >> 3) & 7) << 6;
  v18 = 0;
  v19 = v17;
  v48 = -1;
  do
  {
    v47 = 0;
    do
    {
      if ( a4 <= a5 )
      {
        v20 = a4;
        do
        {
          *v16 = dword_10A8E0 & (((__int16)v51 | (4 * v20) | 1) << 8) | *v16 & 0xFFFE00FF;
          *v16 |= 0x20000u;
          *v16 |= 0x40000u;
          delay_us(1);
          if ( v45 )
          {
            if ( v47 )
            {
              v21 = (__int16)v20;
            }
            else
            {
              sub_109100(v18, v20, &v54, (char *)&v60[6] + 3 * v20, (int *)&v60[8 * v20 + 54]);
              v21 = (__int16)v20;
              sub_109100(v18, v20, &v55, (char *)&v60[30] + 3 * v20, (int *)&v60[8 * v20 + 182]);
            }
            v22 = *((unsigned __int8 *)&v60[6] + 3 * v20 + v48);
            v23 = *((unsigned __int8 *)&v60[30] + 3 * v20 + v48);
            *v19 = *v19 & 0xFE01FFFF | (v22 << 17);
            *v19 = *v19 & 0xFFFF00FF | (v22 << 8);
            sub_108CB8(&v57, (unsigned int *)&v58);
            if ( v22 != v23 )
            {
              *v19 = *v19 & 0xFE01FFFF | (v23 << 17);
              *v19 = *v19 & 0xFFFF00FF | (v23 << 8);
              sub_108CB8(&v56, (unsigned int *)&v58);
            }
          }
          else
          {
            *v19 = *v19 & 0xFE01FFFF | 0x1000000;
            *v19 = *v19 & 0xFFFF00FF | 0x8000;
            sub_108CB8(&v57, (unsigned int *)&v58);
            v21 = (__int16)v20;
          }
          sub_109120((unsigned __int8)v47, v57, &v60[20 * v21 + 310]);
          sub_109120((unsigned __int8)v47, v58, &v60[20 * v20 + 630]);
          v20 = (unsigned __int8)(v20 + 1);
        }
        while ( a5 >= v20 );
      }
      v24 = v50 == ++v47;
    }
    while ( !v24 );
    if ( a4 <= a5 )
    {
      v25 = a4;
      do
      {
        while ( 1 )
        {
          v27 = v45 + 4 * v25;
          if ( v50 != 1 )
            break;
          *(uint32_t *)&v60[2 * v27 + 54] = *(uint32_t *)&v60[20 * v25 + 310];
          *(uint32_t *)&v60[2 * v27 + 182] = *(uint32_t *)&v60[20 * v25 + 630];
          v25 = (unsigned __int8)(v25 + 1);
          if ( a5 < v25 )
            goto LABEL_28;
        }
        if ( v25 >= 6 )
          v26 = 100;
        else
          v26 = 50;
        v46 = v26;
        *(uint32_t *)&v60[2 * v27 + 54] = sub_109184(v50, v26, (int *)&v60[20 * v25 + 310]);
        *(uint32_t *)&v60[2 * v27 + 182] = sub_109184(v50, v46, (int *)&v60[20 * v25 + 630]);
        v25 = (unsigned __int8)(v25 + 1);
      }
      while ( a5 >= v25 );
    }
LABEL_28:
    ++v48;
    v18 = (unsigned __int8)++v45;
  }
  while ( v8 > (unsigned __int8)v45 );
  if ( a4 > a5 )
  {
    sub_109480((a1 >> 5) & 1, v59);
    sub_109480((a1 >> 5) & 1, v60);
  }
  else
  {
    v28 = a4;
    do
    {
      v29 = mac_aggr_setup(v8, v28, (unsigned __int8 *)&v60[6] + 3 * v28, (int *)&v60[8 * v28 + 54]);
      v30 = mac_aggr_setup(v8, v28, (unsigned __int8 *)&v60[30] + 3 * v28, (int *)&v60[8 * v28 + 182]);
      v31 = v28 - 10;
      if ( v28 > 9 )
        v59[v31] = v29;
      else
        v31 = a2;
      if ( v28 <= 9 )
        *(uint16_t *)(v31 + 2 * (__int16)v28) = (unsigned __int8)v29 | (unsigned __int16)(v30 << 8);
      v32 = v28 + 1;
      if ( v28 > 9 )
        v60[v31] = v30;
      v28 = v32;
    }
    while ( a5 >= (unsigned int)v32 );
    sub_109480((a1 >> 5) & 1, v59);
    sub_109480((a1 >> 5) & 1, v60);
    for ( i = a4; ; i = (unsigned __int8)(i + 1) )
    {
      if ( i > 9 )
        *(uint16_t *)(a2 + 2 * (__int16)i) = LOBYTE(v59[i - 10]) | (unsigned __int16)(v60[i - 10] << 8);
      if ( a5 == i )
        break;
    }
    v34 = a4;
    do
    {
      v35 = *(unsigned __int16 *)(a2 + 2 * v34);
      sub_11F74C(0x2000, dword_10ABFC, v34, (unsigned __int8)v35);
      sub_11F74C(0x2000, dword_10AC00, v34, v35 >> 8);
      v24 = a5 == v34;
      v34 = (unsigned __int8)(v34 + 1);
    }
    while ( !v24 );
  }
  v36 = off_10AC04;
  v37 = (unsigned int *)off_10AC08;
  *(uint32_t *)off_10AC04 &= ~2u;
  *v37 |= 4u;
  *v37 = *v37 & 0xFFFF8FFF | 0x3000;
  *v37 = *v37 & 0xFFFFF8FF | 0x600;
  *v37 &= ~8u;
  *v37 &= ~1u;
  *(v36 - 6224) &= 0xCFFFFFFF;
  if ( a6 )
  {
    v38 = (unsigned int *)off_10AC0C;
    v39 = *(uint16_t *)(a2 + 2 * a4);
    *(uint32_t *)off_10AC0C = *(uint32_t *)off_10AC0C & 0xFE01FFFF | ((unsigned __int8)v39 << 17);
    *v38 = v39 & 0xFF00 | *v38 & 0xFFFF00FF;
  }
  else
  {
    v44 = (unsigned int *)off_10AC0C;
    *(uint32_t *)off_10AC0C &= ~0x2000000u;
    *v44 &= ~0x10000u;
    *v44 = *v44 & 0xFE01FFFF | 0x1000000;
    *v44 = *v44 & 0xFFFF00FF | 0x8000;
  }
  v40 = (int *)off_10AC10;
  v41 = dword_10AC14;
  *(uint32_t *)off_10AC10 &= 0xFFFE00FF;
  *v40 &= ~0x20000u;
  v42 = *v40 | 0x40000;
  *v40 = v42;
  return sub_11F74C(0x2000, v41, v42, v40);
}

