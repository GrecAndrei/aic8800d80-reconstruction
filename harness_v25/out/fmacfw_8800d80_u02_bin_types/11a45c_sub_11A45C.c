// sub_11A45C @ 0x11a45c, size 576 bytes
// Doc: sub_121A45C [mac]: Initialize/handle MAC/phy control block (fmacfw)
// sub_121A45C [mac]: Initialize/handle MAC/phy control block (fmacfw)
int  sub_11A45C(int a1, int *a2, unsigned int a3, unsigned int a4, unsigned __int8 a5)
{
  int v5; // r6
  int *v6; // r8
  int v7; // r4
  uint32_t *v8; // r0
  uint32_t *v10; // r7
  __int16 *v11; // r8
  unsigned int v12; // r12
  unsigned int v13; // r0
  char v14; // r5
  int v15; // r10
  unsigned int v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r9
  int v19; // r11
  __int16 v20; // r7
  __int16 v21; // r1
  __int16 v22; // r1
  int v23; // r7
  int v24; // r9
  unsigned int v25; // r9
  int v26; // r3
  int v27; // r2
  int v28; // r1
  int *v29; // r1
  int v30; // r2
  __int16 *v32; // r8
  int v33; // r3
  int v34; // [sp+4h] [bp-20h]
  int v35; // [sp+4h] [bp-20h]
  int v36; // [sp+8h] [bp-1Ch]
  int v37; // [sp+Ch] [bp-18h]
  int v38; // [sp+10h] [bp-14h]
  int v40; // [sp+1Ch] [bp-8h]

  v5 = *(uint32_t *)(a1 + 68);
  v6 = (int *)off_11A6BC;
  v7 = a1;
  v8 = off_11A69C;
  *(uint8_t *)(v5 + 14) = 1;
  v37 = v8[43];
  v40 = *(uint32_t *)(v5 + 40);
  v38 = v5 + 16;
  v36 = *v6;
  v10 = *(uint32_t **)(v7 + 76);
  v11 = *(__int16 **)off_11A6A0;
  v12 = 0;
  *(uint16_t *)(v5 + 10) = 0;
  *(uint32_t *)(v5 + 40) = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  while ( 1 )
  {
    v16 = *(uint32_t *)(v7 + 36);
    v17 = (unsigned __int16)(((v10[9] + 3) & 0xFFFC) + 4);
    v18 = (unsigned __int16)(v17 + 4 * ((v16 >> 9) & 0x3FF));
    if ( v18 >= a4 )
    {
      v13 += v18;
      if ( v13 > a3 )
        goto LABEL_23;
    }
    else
    {
      if ( a4 <= v17 )
      {
        v19 = (unsigned __int16)(((v10[9] + 3) & 0xFFFC) + 4);
        v12 = 0;
      }
      else
      {
        v12 = ((unsigned int)(unsigned __int16)(a4 - v17) + 3) >> 2;
        v19 = (unsigned __int16)(v17 + 4 * v12);
      }
      v13 += v19;
      if ( v13 > a3 )
      {
LABEL_23:
        v25 = *(uint32_t *)(v7 + 36);
        if ( !v15 )
        {
          if ( v17 > a3 )
          {
            *(uint32_t *)(v5 + 40) = v40;
            sub_11C4F8(v38, a5, a3);
            return 0;
          }
          v26 = *(uint32_t *)v7;
          *(uint16_t *)(v5 + 10) += *(uint16_t *)(v7 + 80);
          v14 = 1;
          if ( (v25 & 0x380000) != 0x280000 )
          {
LABEL_16:
            v27 = *(uint32_t *)(v7 + 76);
            *(uint32_t *)(v5 + 324) = v7;
            *(uint32_t *)(v7 + 36) = v25 | 0x380000;
            v28 = *v11;
            *(uint32_t *)(v27 + 68) = v25 | 0x380100;
            *(uint32_t *)(v27 + 20) = 0;
            if ( v28 >= 0 )
              goto LABEL_17;
            goto LABEL_27;
          }
LABEL_26:
          v34 = v26;
          crypto_ke_ctx_init_n_38(v7, 1);
          v27 = *(uint32_t *)(v7 + 76);
          v32 = *(__int16 **)off_11A6A0;
          *(uint32_t *)(v7 + 68) = v5;
          v38 = v27 + 12;
          v26 = v34;
          if ( *v32 >= 0 )
          {
LABEL_17:
            v29 = (int *)off_11A6A8;
            *(uint8_t *)(v27 + 1) = v14;
            v30 = *v29;
            *a2 = v26;
            if ( !*(uint8_t *)(v30 + 1) )
              *(uint32_t *)(v5 + 88) = *(uint32_t *)(v5 + 20);
            return v38;
          }
LABEL_27:
          if ( *(uint32_t *)(dword_11A6B4 + 84 * a5 + 28) != v5 )
          {
            v35 = v26;
            sub_12F46C(dword_11A6B8, dword_11A6AC, 1119);
            v27 = *(uint32_t *)(v7 + 76);
            v26 = v35;
          }
          goto LABEL_17;
        }
        v25 = *(uint32_t *)(v15 + 36);
        v26 = v7;
        v23 = v25 & 0x380000;
        v7 = v15;
LABEL_15:
        if ( v23 != 2621440 )
          goto LABEL_16;
        goto LABEL_26;
      }
    }
    if ( v10[7] )
      *(uint32_t *)(v10[8] - 3) = v37;
    if ( v18 < a4 )
    {
      v16 = v10[17] & 0xFFF801FF | (v12 << 9);
      *(uint32_t *)(v7 + 36) = v16;
      v10[17] = v16 | 0x100;
    }
    v20 = *(uint16_t *)(v7 + 80);
    v21 = *(uint16_t *)(v5 + 10);
    *(uint32_t *)(v5 + 40) = v13;
    v22 = v21 + v20;
    v23 = v16 & 0x380000;
    *(uint16_t *)(v5 + 10) = v22;
    if ( (v16 & 0x380000) == 0x380000 )
      break;
    v24 = *(uint32_t *)v7;
    ++v14;
    if ( *v11 < 0 && !v24 )
    {
      sub_12F46C(dword_11A6B0, dword_11A6AC, 1113);
      __und(0xFFu);
    }
    if ( *(unsigned __int8 *)(v36 + 62) > (*(uint32_t *)off_11A6A4 & 0x3Fu) )
    {
      v25 = v16;
      v26 = *(uint32_t *)v7;
      goto LABEL_15;
    }
    v10 = *(uint32_t **)(v24 + 76);
    v15 = v7;
    v7 = *(uint32_t *)v7;
  }
  if ( *v11 < 0 && *(uint32_t *)(dword_11A6B4 + 84 * a5 + 28) != v5 )
    sub_12F46C(dword_11A6B8, dword_11A6AC, 1119);
  v33 = *(uint32_t *)(v7 + 76);
  *a2 = *(uint32_t *)v7;
  *(uint32_t *)(v33 + 20) = 0;
  return v5 + 16;
}

