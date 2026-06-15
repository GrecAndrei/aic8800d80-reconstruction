// sub_10A9A8 @ 0x10a9a8, size 1610 bytes
int __fastcall sub_10A9A8(unsigned int a1, unsigned int a2, int a3, unsigned int a4, unsigned __int8 a5, char a6)
{
  unsigned int v8; // s17
  int v9; // r3
  _DWORD *v10; // r2
  _DWORD *v11; // r5
  _DWORD *v12; // r7
  unsigned int *v13; // r3
  unsigned int *v14; // r1
  _DWORD *v15; // r6
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
  _DWORD *v35; // r1
  unsigned int *v36; // r3
  unsigned int *v37; // r1
  __int16 v38; // r3
  _DWORD *v39; // r3
  int v40; // r1
  unsigned int *v42; // r3
  int v43; // [sp+24h] [bp-7C0h]
  int v44; // [sp+28h] [bp-7BCh]
  int v45; // [sp+34h] [bp-7B0h]
  int v46; // [sp+38h] [bp-7ACh]
  unsigned int v48; // [sp+44h] [bp-7A0h]
  int v49; // [sp+48h] [bp-79Ch]
  char v52; // [sp+5Ah] [bp-78Ah] BYREF
  char v53; // [sp+5Bh] [bp-789h] BYREF
  int v54; // [sp+5Ch] [bp-788h] BYREF
  int v55; // [sp+60h] [bp-784h] BYREF
  int v56; // [sp+64h] [bp-780h] BYREF
  __int16 v57[6]; // [sp+68h] [bp-77Ch] BYREF
  __int16 v58[952]; // [sp+74h] [bp-770h] BYREF

  feature_guard_check(0x2000, dword_10ACB8);
  v8 = ((a1 >> 1) & 1) + 3;
  if ( (a1 & 0xC) != 0 )
  {
    if ( ((a1 >> 2) & 3) == 1 )
      v9 = 5;
    else
      v9 = 10;
    v48 = v9;
  }
  else
  {
    v48 = 1;
  }
  v10 = off_10ACBC;
  v11 = off_10ACC0;
  v12 = off_10ACC4;
  v13 = (unsigned int *)off_10ACC8;
  v14 = (unsigned int *)off_10ACCC;
  v15 = off_10ACD0;
  v16 = (unsigned int *)off_10ACE0;
  *(_DWORD *)off_10ACBC &= ~4u;
  *v11 &= 0xFFFF0FFF;
  *v12 = 0;
  *v13 |= 0x80u;
  *v14 |= 0x80000000;
  *v10 |= 4u;
  *v15 = HIWORD(*v15) << 16;
  *(v12 - 6154) = *(v12 - 6154) & 0xCFFFFFFF | 0x10000000;
  v17 = (unsigned int *)off_10ACD4;
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
  v43 = 0;
  v49 = ((v10[2069] >> 3) & 7) << 6;
  v18 = 0;
  v19 = v17;
  v46 = -1;
  do
  {
    v45 = 0;
    do
    {
      if ( a4 <= a5 )
      {
        v20 = a4;
        do
        {
          *v16 = dword_10ACD8 & (((__int16)v49 | (4 * v20) | 1) << 8) | *v16 & 0xFFFE00FF;
          *v16 |= 0x20000u;
          *v16 |= 0x40000u;
          delay_us_0644(1);
          if ( v43 )
          {
            if ( v45 )
            {
              v21 = (__int16)v20;
            }
            else
            {
              sub_1094F8(v18, v20, &v52, (char *)&v58[6] + 3 * v20, (int *)&v58[8 * v20 + 54]);
              v21 = (__int16)v20;
              sub_1094F8(v18, v20, &v53, (char *)&v58[30] + 3 * v20, (int *)&v58[8 * v20 + 182]);
            }
            v22 = *((unsigned __int8 *)&v58[6] + 3 * v20 + v46);
            v23 = *((unsigned __int8 *)&v58[30] + 3 * v20 + v46);
            *v19 = *v19 & 0xFE01FFFF | (v22 << 17);
            *v19 = *v19 & 0xFFFF00FF | (v22 << 8);
            mac_reg_init_n0(&v55, (unsigned int *)&v56);
            if ( v22 != v23 )
            {
              *v19 = *v19 & 0xFE01FFFF | (v23 << 17);
              *v19 = *v19 & 0xFFFF00FF | (v23 << 8);
              mac_reg_init_n0(&v54, (unsigned int *)&v56);
            }
          }
          else
          {
            *v19 = *v19 & 0xFE01FFFF | 0x1000000;
            *v19 = *v19 & 0xFFFF00FF | 0x8000;
            mac_reg_init_n0(&v55, (unsigned int *)&v56);
            v21 = (__int16)v20;
          }
          sub_109518((unsigned __int8)v45, v55, &v58[20 * v21 + 310]);
          sub_109518((unsigned __int8)v45, v56, &v58[20 * v20 + 630]);
          v20 = (unsigned __int8)(v20 + 1);
        }
        while ( a5 >= v20 );
      }
      v24 = v48 == ++v45;
    }
    while ( !v24 );
    if ( a4 <= a5 )
    {
      v25 = a4;
      do
      {
        while ( 1 )
        {
          v27 = v43 + 4 * v25;
          if ( v48 != 1 )
            break;
          *(_DWORD *)&v58[2 * v27 + 54] = *(_DWORD *)&v58[20 * v25 + 310];
          *(_DWORD *)&v58[2 * v27 + 182] = *(_DWORD *)&v58[20 * v25 + 630];
          v25 = (unsigned __int8)(v25 + 1);
          if ( a5 < v25 )
            goto LABEL_28;
        }
        if ( v25 >= 6 )
          v26 = 100;
        else
          v26 = 50;
        v44 = v26;
        *(_DWORD *)&v58[2 * v27 + 54] = sub_10957C(v48, v26, (int *)&v58[20 * v25 + 310]);
        *(_DWORD *)&v58[2 * v27 + 182] = sub_10957C(v48, v44, (int *)&v58[20 * v25 + 630]);
        v25 = (unsigned __int8)(v25 + 1);
      }
      while ( a5 >= v25 );
    }
LABEL_28:
    ++v46;
    v18 = (unsigned __int8)++v43;
  }
  while ( v8 > (unsigned __int8)v43 );
  if ( a4 > a5 )
  {
    subsystem_init_helper((a1 >> 5) & 1, v57);
    subsystem_init_helper((a1 >> 5) & 1, v58);
  }
  else
  {
    v28 = a4;
    do
    {
      v29 = sub_10A764(v8, v28, (unsigned __int8 *)&v58[6] + 3 * v28, (int *)&v58[8 * v28 + 54]);
      v30 = sub_10A764(v8, v28, (unsigned __int8 *)&v58[30] + 3 * v28, (int *)&v58[8 * v28 + 182]);
      v31 = v28 - 10;
      if ( v28 > 9 )
        v57[v31] = v29;
      else
        v31 = a2;
      if ( v28 <= 9 )
        *(_WORD *)(v31 + 2 * (__int16)v28) = (unsigned __int8)v29 | (unsigned __int16)(v30 << 8);
      v32 = v28 + 1;
      if ( v28 > 9 )
        v58[v31] = v30;
      v28 = v32;
    }
    while ( a5 >= (unsigned int)v32 );
    subsystem_init_helper((a1 >> 5) & 1, v57);
    subsystem_init_helper((a1 >> 5) & 1, v58);
    for ( i = a4; ; i = (unsigned __int8)(i + 1) )
    {
      if ( i > 9 )
        *(_WORD *)(a2 + 2 * (__int16)i) = LOBYTE(v57[i - 10]) | (unsigned __int16)(v58[i - 10] << 8);
      if ( a5 == i )
        break;
    }
    v34 = a4;
    do
    {
      feature_guard_check(0x2000, dword_10AFF4);
      feature_guard_check(0x2000, dword_10AFF8);
      v24 = a5 == v34;
      v34 = (unsigned __int8)(v34 + 1);
    }
    while ( !v24 );
  }
  v35 = off_10AFFC;
  v36 = (unsigned int *)off_10B000;
  *(_DWORD *)off_10AFFC &= ~2u;
  *v36 |= 4u;
  *v36 = *v36 & 0xFFFF8FFF | 0x3000;
  *v36 = *v36 & 0xFFFFF8FF | 0x600;
  *v36 &= ~8u;
  *v36 &= ~1u;
  *(v35 - 6224) &= 0xCFFFFFFF;
  if ( a6 )
  {
    v37 = (unsigned int *)off_10B004;
    v38 = *(_WORD *)(a2 + 2 * a4);
    *(_DWORD *)off_10B004 = *(_DWORD *)off_10B004 & 0xFE01FFFF | ((unsigned __int8)v38 << 17);
    *v37 = v38 & 0xFF00 | *v37 & 0xFFFF00FF;
  }
  else
  {
    v42 = (unsigned int *)off_10B004;
    *(_DWORD *)off_10B004 &= ~0x2000000u;
    *v42 &= ~0x10000u;
    *v42 = *v42 & 0xFE01FFFF | 0x1000000;
    *v42 = *v42 & 0xFFFF00FF | 0x8000;
  }
  v39 = off_10B008;
  v40 = dword_10B00C;
  *(_DWORD *)off_10B008 &= 0xFFFE00FF;
  *v39 &= ~0x20000u;
  *v39 |= 0x40000u;
  return feature_guard_check(0x2000, v40);
}

