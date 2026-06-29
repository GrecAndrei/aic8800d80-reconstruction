// sub_11FA78 @ 0x11fa78, size 1108 bytes
int  sub_11FA78(int a1)
{
  int v2; // r6
  int *v3; // r8
  int v4; // r3
  uint8_t *v5; // r5
  int v6; // r2
  int v7; // r3
  int v8; // r3
  int v9; // r4
  int v10; // r6
  int v11; // r1
  int *v13; // r10
  int v14; // r9
  int v15; // r1
  int v16; // r3
  int v17; // r7
  int v18; // r5
  int v19; // r11
  int v20; // r1
  int v21; // r0
  int v22; // r3
  int v23; // r2
  int v24; // r0
  int v25; // r2
  int v26; // r0
  int v27; // r3
  int v28; // r2
  __int16 **v29; // r10
  uint32_t *v30; // r7
  int v31; // r1
  int v32; // r9
  unsigned int v33; // r3
  uint32_t *v34; // r0
  uint32_t *v35; // r3
  int v36; // r1
  int v37; // r2
  unsigned int v38; // r3
  int v39; // r3
  int v40; // r0
  int v41; // r3
  int v42; // r1
  int *v43; // r7
  int v44; // r3
  int v45; // r1
  int v46; // r2
  int v47; // r3
  uint32_t *v48; // r12
  uint32_t *v49; // r1
  int v50; // r0
  int v51; // [sp+8h] [bp-1Ch]
  int v52; // [sp+Ch] [bp-18h]
  int v53; // [sp+10h] [bp-14h]
  int *v54; // [sp+14h] [bp-10h]
  unsigned __int8 *v55; // [sp+1Ch] [bp-8h]

  v2 = dword_11FD7C;
  v3 = (int *)(dword_11FD7C + 1320 * a1);
  v52 = 1320 * a1;
  sub_12D1A8(dword_11FD80, v3);
  if ( *((int **)off_11FD84 + 8) == v3 )
    *((uint32_t *)off_11FD84 + 8) = 0;
  v4 = *(unsigned __int8 *)(v2 + 1320 * a1 + 106);
  if ( v4 == 2 )
  {
    v13 = (int *)off_11FDC4;
    v54 = v3;
    v14 = dword_11FDA4 + 696 * (a1 + 32);
    v15 = 0;
    v16 = dword_11FDA4 + 8 * (87 * (a1 + 32) + 78);
    v55 = (unsigned __int8 *)off_11FD88;
    --*((uint8_t *)off_11FD88 + 18);
    v51 = v16;
    *(uint8_t *)(v14 + 37) = 0;
    v17 = v2 + 8 * (165 * (__int16)a1 + 159);
    v18 = 0;
    do
    {
      if ( *(uint32_t *)(v14 + 584) )
        sub_118800((unsigned __int8)v18, v51 - 40, 0);
      if ( *(uint32_t *)(v14 + 624) )
        sub_118800((unsigned __int8)v18, v51, 0);
      if ( v3[318] || v3[308] )
      {
        v19 = v17 - 40;
        v53 = sub_12D22C(v17, v15);
        v21 = sub_12D22C(v17 - 40, v20);
        sub_12E948(dword_11FDA8, v53, v21);
      }
      else
      {
        v19 = v17 - 40;
      }
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11FDAC = 1;
      }
      ++*v13;
      sub_118800((unsigned __int8)v18, v17, 0);
      sub_118800((unsigned __int8)v18, v19, 0);
      if ( *v13 )
      {
        v22 = *v13 - 1;
        v23 = *(uint32_t *)off_11FDAC;
        *v13 = v22;
        if ( !v22 )
        {
          if ( v23 )
            __enable_irq();
        }
      }
      ++v18;
      v14 += 8;
      v17 += 8;
      v3 += 2;
      v51 += 8;
    }
    while ( v18 != 5 );
    v3 = v54;
    v5 = v55;
    if ( *(uint32_t *)(v2 + 1320 * a1 + 1312) )
    {
      v24 = sub_12D22C(v52 + 1312 + v2, v15);
      sub_12E948(dword_11FDB0, v24, v25);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11FDAC = 1;
    }
    ++*v13;
    v26 = sub_118800(5, v52 + 1312 + v2, 0);
    if ( *v13 )
    {
      v27 = *v13 - 1;
      v28 = *(uint32_t *)off_11FDAC;
      *v13 = v27;
      if ( !v27 )
      {
        if ( v28 )
          __enable_irq();
      }
    }
    v6 = v55[18];
    if ( !v55[18] )
    {
      sub_121774(v26);
LABEL_6:
      v6 = (unsigned __int8)v5[18];
      v7 = (unsigned __int8)v5[17] + v6;
      if ( v7 != 1 )
        goto LABEL_7;
      goto LABEL_40;
    }
    if ( v55[17] + v6 != 1 )
      goto LABEL_9;
  }
  else
  {
    if ( v4 != 4 )
    {
      v5 = off_11FD88;
      if ( !*(uint8_t *)(v2 + 1320 * a1 + 106) )
      {
        v6 = *((unsigned __int8 *)off_11FD88 + 18);
        v39 = (unsigned __int8)(*((uint8_t *)off_11FD88 + 17) - 1);
        *((uint8_t *)off_11FD88 + 17) = v39;
        v7 = v39 + v6;
        if ( v7 != 1 )
          goto LABEL_7;
        goto LABEL_40;
      }
      goto LABEL_6;
    }
    if ( sub_101960() )
      sub_101974(0);
    v5 = off_11FECC;
    v40 = *((unsigned __int8 *)off_11FECC + 16);
    v41 = v2 + 1320 * v40;
    v42 = *(uint32_t *)(v41 + 72);
    *(uint32_t *)(v41 + 4) &= ~0x80u;
    if ( v42 )
      v40 = sub_12847C();
    v6 = (unsigned __int8)v5[18];
    if ( v5[18] )
    {
      sub_1216F4(v40, v42);
      v6 = (unsigned __int8)v5[18];
    }
    else
    {
      v43 = (int *)off_11FED4;
      v44 = dword_11FED8;
      v45 = **(__int16 **)off_11FED0;
      *(uint32_t *)off_11FED4 = dword_11FED8;
      if ( v45 < 0 )
      {
        v6 = *(uint32_t *)off_11FEE0 & 0xF;
        if ( v6 )
        {
          sub_12F35C(dword_11FEE8, dword_11FEE4, 472);
          v44 = *v43;
          v6 = (unsigned __int8)v5[18];
        }
      }
      *(uint32_t *)off_11FEDC = v44 | v43[1];
    }
    v7 = (unsigned __int8)v5[17] + v6;
    v5[16] = -1;
    if ( v7 != 1 )
      goto LABEL_7;
  }
LABEL_40:
  v29 = (__int16 **)off_11FDC8;
  v30 = off_11FDB4;
  v31 = **(__int16 **)off_11FDC8;
  v32 = *((uint32_t *)v5 + 2);
  v33 = *((uint32_t *)off_11FDB4 + 1) & 0xFFFFFFEF;
  *((uint32_t *)off_11FDB4 + 1) = v33;
  if ( v31 >= 0 || !(*(uint32_t *)off_11FEE0 << 28) )
  {
    v34 = off_11FDB8;
    *(uint32_t *)off_11FDC0 = v33 | *v30;
    v35 = off_11FDBC;
    v36 = *(unsigned __int16 *)(v32 + 68);
    *v34 = *(uint32_t *)(v32 + 64);
    *v35 = v36;
    if ( v6 )
      goto LABEL_9;
LABEL_42:
    v37 = **v29;
    v38 = v30[1] & 0xFFFFFEFF;
    v30[1] = v38;
    if ( v37 >= 0 || !(*(uint32_t *)off_11FEE0 << 28) )
    {
      *(uint32_t *)off_11FDC0 = v38 | *v30;
      goto LABEL_9;
    }
    sub_12F35C(dword_11FEE8, dword_11FEE4, 472);
    v7 = (unsigned __int8)v5[17] + (unsigned __int8)v5[18];
    *(uint32_t *)off_11FEDC = *v30 | v30[1];
    goto LABEL_7;
  }
  sub_12F35C(dword_11FEE8, dword_11FEE4, 472);
  v46 = (unsigned __int8)v5[18];
  v47 = (unsigned __int8)v5[17];
  v48 = off_11FEF0;
  *(uint32_t *)off_11FEDC = *v30 | v30[1];
  v7 = v47 + v46;
  v49 = off_11FEEC;
  v50 = *(unsigned __int16 *)(v32 + 68);
  *v48 = *(uint32_t *)(v32 + 64);
  *v49 = v50;
  if ( v7 == 1 )
  {
    if ( v46 )
      goto LABEL_9;
    goto LABEL_42;
  }
LABEL_7:
  if ( !v7 )
    *(uint32_t *)off_11FD8C = 0;
LABEL_9:
  sub_124CF4(v52 + 24 + v2);
  sub_124CF4(v52 + 48 + v2);
  v8 = v2 + 1320 * a1;
  if ( *(uint8_t *)(v8 + 1224) )
  {
    sub_129F0C(*(unsigned __int8 *)(v8 + 1225), 1);
    --v5[19];
  }
  sub_12ACC4(*(unsigned __int8 *)(v2 + 1320 * a1 + 107));
  if ( *((int **)off_11FD90 + 4) == v3 )
    *((uint32_t *)off_11FD90 + 4) = 0;
  *(uint32_t *)off_11FD94 = 0;
  if ( (unsigned __int8)v5[18] + (unsigned __int8)v5[17] <= 1 )
    sub_11F5B0();
  sub_100200(v3, 0, 0x528u);
  v9 = v2 + 1320 * a1;
  v10 = dword_11FD98;
  *(uint8_t *)(v9 + 106) = 5;
  v11 = dword_11FDA0;
  *(uint32_t *)(v9 + 56) = v3;
  *(uint32_t *)(v9 + 52) = v10;
  *(uint8_t *)(v9 + 109) = 127;
  *(uint8_t *)(v9 + 110) = 127;
  sub_12EB90(256, v11);
  return sub_12D108(off_11FD88);
}

