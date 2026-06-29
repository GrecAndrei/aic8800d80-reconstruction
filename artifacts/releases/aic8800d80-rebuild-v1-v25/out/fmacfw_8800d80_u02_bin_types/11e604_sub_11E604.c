// sub_11E604 @ 0x11e604, size 1106 bytes
int  sub_11E604(int a1)
{
  int v1; // r8
  int v2; // r10
  int v3; // r11
  uint32_t *v4; // r6
  unsigned __int8 **v5; // r5
  __int16 v6; // r2
  unsigned __int8 *v7; // r3
  int v8; // r4
  int v9; // r3
  unsigned int v10; // r7
  int v11; // r3
  int *v12; // r6
  int v13; // r11
  int v14; // r3
  unsigned __int8 v15; // r7
  int v16; // r4
  int v17; // r11
  int v18; // r3
  unsigned __int16 *v19; // r6
  int v20; // r2
  int *v21; // r7
  int v22; // r0
  int v23; // r0
  int v24; // r1
  int v25; // r3
  int v26; // r2
  uint16_t *v28; // r7
  int *v29; // r9
  unsigned int v30; // r1
  int v31; // r0
  int v32; // r0
  int v33; // r12
  int v34; // r3
  uint32_t *v35; // r1
  uint8_t *v36; // r12
  int v37; // r0
  char v38; // r2
  int v39; // r0
  int v40; // r3
  int *v41; // r2
  int v42; // r3
  int v43; // r1
  int v44; // r3
  unsigned int CPSR; // r0
  uint32_t *v46; // r3
  uint32_t *v47; // r0
  int v48; // r1
  int v49; // r2
  uint32_t *v50; // r2
  uint32_t *v51; // r5
  uint32_t *v52; // r0
  int v53; // r1
  int v54; // r2
  int v55; // r7
  int v56; // r2
  int v57; // r12
  int v58; // r2
  uint8_t *v59; // r1
  char v60; // r2
  unsigned __int8 *v61; // r3
  int v62; // r1
  int v63; // r0
  int v64; // r1
  int *v65; // r4
  int v66; // r0
  int v67; // r2
  int v68; // r3
  int v69; // r0
  int v70; // [sp+Ch] [bp-10h]
  __int16 v71; // [sp+12h] [bp-Ah] BYREF
  int v72[2]; // [sp+14h] [bp-8h] BYREF

  v4 = off_11E838;
  v5 = (unsigned __int8 **)off_11E83C;
  v6 = *((unsigned __int8 *)off_11E838 + 50);
  v7 = *(unsigned __int8 **)off_11E83C;
  v8 = a1;
  v72[0] = *(uint32_t *)(a1 + 28);
  v71 = v6;
  v9 = *v7;
  if ( v9 == 3 )
  {
    v2 = sub_12F550();
    v9 = **v5;
    v3 = v2 + 60;
  }
  if ( v9 == 2 )
  {
    v28 = off_11E85C;
    if ( !*((uint32_t *)off_11E85C + 2057) )
    {
      v62 = v72[0];
      *(uint8_t *)(v8 + 16) |= 1u;
      v63 = sub_11DF7C(v8, v62);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11EA6C = 1;
      }
      v65 = (int *)off_11EA70;
      ++*(uint32_t *)off_11EA70;
      v66 = sub_1134B4(v63, v64);
      if ( *v65 )
      {
        v68 = *v65 - 1;
        v67 = *(uint32_t *)off_11EA6C;
        *v65 = v68;
        if ( !v68 )
        {
          if ( v67 )
            __enable_irq();
        }
      }
      return sub_10DC24(dword_11EA98, v66, v67);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11E850 = 1;
    }
    v29 = (int *)off_11E854;
    v30 = (unsigned __int16)v28[4122];
    v31 = dword_11E860;
    ++*(uint32_t *)off_11E854;
    if ( v30 > 0x186 )
      v28[4122] = 0;
    v32 = sub_12D2D0(v31);
    v33 = *(uint32_t *)off_11E864;
    v34 = (unsigned __int16)v28[4122];
    *(uint16_t *)(v32 + 12) = v34;
    v35 = (uint32_t *)(v33 + 8 * v34);
    v35[1] = v8 + 48;
    *v35 = dword_11E868;
    v36 = off_11E84C;
    *(uint32_t *)(v32 + 4) = v35;
    v1 = v32;
    v37 = *v29;
    LOBYTE(v35) = *((uint8_t *)v28 + 3074) + 1;
    v38 = v36[3] + 1;
    v28[4122] = v34 + 1;
    *((uint8_t *)v28 + 3074) = (uint8_t)v35;
    v36[3] = v38;
    if ( v37 )
    {
      v39 = v37 - 1;
      v40 = *(uint32_t *)off_11E850;
      *v29 = v39;
      if ( !v39 )
      {
        if ( v40 )
          __enable_irq();
      }
    }
    v10 = *(unsigned __int16 *)(v8 + 48);
    v9 = **(__int16 **)off_11E840;
    if ( v9 >= 0 )
    {
LABEL_37:
      v9 = **v5;
      if ( v9 == 2 )
      {
        sub_11DC0C(v72, v10, &v71);
        goto LABEL_7;
      }
LABEL_5:
      if ( v9 == 1 )
      {
        sub_11DD44(v72, v10, &v71);
      }
      else
      {
        sub_11DE64(v72, v10, v3, &v71, 0);
        v4[7] = v10 + v3;
      }
LABEL_7:
      sub_10199C((QWORD *)(v8 + 88), 0);
      v11 = **v5;
      if ( v11 == 3 )
      {
        v41 = (int *)off_11EA58;
        v42 = *((uint32_t *)off_11EA58 + 1);
        *(uint32_t *)(v8 + 100) = dword_11EA5C;
        *(uint32_t *)(v8 + 104) = v8 + 48;
        v43 = dword_11EA60;
        *(uint32_t *)(v8 + 108) = v2;
        *(uint32_t *)(v42 + 32) = v8 + 104;
        *(uint32_t *)(v8 + 112) = v43;
        *(uint32_t *)(v8 + 116) = 58;
        *(uint32_t *)(v8 + 120) = 58;
        v70 = v8 + 104;
        *(uint32_t *)(v8 + 124) = 262148;
        *(uint32_t *)(v8 + 136) = 0;
        goto LABEL_41;
      }
      if ( v11 != 1 )
      {
        if ( v11 == 2 )
        {
          v19 = (unsigned __int16 *)off_11EA80;
          if ( *((uint8_t *)off_11EA80 + 2) )
          {
LABEL_17:
            v20 = *(uint32_t *)(v1 + 4);
            *(uint32_t *)(v1 + 8) = *v19 + 58;
            *(uint8_t *)(v20 + 3) &= 0x3Fu;
            *(uint8_t *)(v1 + 14) = *((uint8_t *)v19 + 3);
            *(uint32_t *)v1 = 0;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(uint32_t *)off_11E850 = 1;
            }
            v21 = (int *)off_11E854;
            v22 = dword_11E858;
            ++*(uint32_t *)off_11E854;
            v23 = sub_12D248(v22);
            sub_1134B4(v23, v24);
            if ( *v21 )
            {
              v25 = *v21 - 1;
              v26 = *(uint32_t *)off_11E850;
              *v21 = v25;
              if ( !v25 )
              {
                if ( v26 )
                  __enable_irq();
              }
            }
            *(uint32_t *)v19 = 0;
            *((uint32_t *)v19 + 1) = 0;
            if ( **v5 != 3 )
              return sub_11DF7C(v8, v72[0]);
            goto LABEL_65;
          }
        }
        return sub_11DF7C(v8, v72[0]);
      }
      v12 = (int *)off_11E844;
      if ( *((uint8_t *)off_11E844 + 32) )
      {
        v52 = (uint32_t *)sub_1102BC();
        v55 = (int)v52;
        if ( v52 )
        {
          if ( *((uint8_t *)v12 + 32) )
          {
            v56 = *v12;
            v57 = v12[1] + 1;
            v52[2] = (v57 << 24) & 0x7F000000 | v52[2] & 0x80FFFFFF;
            v12[1] = v57;
            sub_11113C(v52, v8 + 48, v56, 0x3Au, 0);
            v58 = *((unsigned __int8 *)off_11EA84 + 192);
            v12[3] += 58;
            if ( v58 )
              sub_11E270(v55);
            else
              sub_11101C(v55, v12[1], v12[2]);
            v59 = off_11EA88;
            v60 = *(uint8_t *)off_11EA88;
            v12[1] = 0;
            v12[3] = 0;
            *v12 = 0;
            v12[2] = 0;
            *((uint8_t *)v12 + 32) = 0;
            v61 = *v5;
            *v59 = v60 | 1;
            v18 = *v61;
            if ( v18 == 2 )
              goto LABEL_16;
            goto LABEL_64;
          }
        }
        else
        {
          v69 = dword_11EA9C;
          *(uint8_t *)(v8 + 16) |= 1u;
          sub_12EA88(v69, v53, v54);
          *((uint8_t *)v12 + 32) = 0;
        }
      }
      sub_12ECD0(1024, dword_11E848);
      v13 = *v12;
      *(uint8_t *)(v8 + 16) |= 1u;
      if ( v13 && v12[1] )
      {
        v14 = v8;
        v15 = 0;
        v16 = v13;
        v17 = v14;
        do
        {
          v16 = *(uint32_t *)(v16 + 4);
          sub_1102FC();
          ++v15;
        }
        while ( v15 < (unsigned int)v12[1] );
        v8 = v17;
      }
      v12[1] = 0;
      v12[3] = 0;
      *v12 = 0;
      v12[2] = 0;
      v18 = **v5;
      if ( v18 == 2 )
      {
LABEL_16:
        v19 = (unsigned __int16 *)off_11E84C;
        if ( *((uint8_t *)off_11E84C + 2) )
          goto LABEL_17;
        return sub_11DF7C(v8, v72[0]);
      }
LABEL_64:
      if ( v18 == 3 )
      {
LABEL_65:
        v41 = (int *)off_11EA58;
LABEL_41:
        sub_10D414(*v41, v70, 5);
        while ( (*(uint32_t *)off_11EA64 & 0x800) == 0 )
          ;
        v44 = *(uint32_t *)off_11EA64;
        if ( (*(uint32_t *)off_11EA64 & 0x40000) != 0 )
          *(uint32_t *)off_11EA64 |= 0x4000000u;
        if ( (v44 & 0x800) != 0 )
        {
          CPSR = __get_CPSR();
          *(uint32_t *)(dword_11EA68 + 4428) |= 0x8000000u;
          if ( CPSR )
          {
            *((uint32_t *)off_11EA74 + 5) = 0;
          }
          else
          {
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(uint32_t *)off_11EA6C = 1;
            }
            v46 = off_11EA70;
            v47 = off_11EA74;
            v48 = *(uint32_t *)off_11EA70;
            v49 = *(uint32_t *)off_11EA70 + 1;
            *(uint32_t *)off_11EA70 = v49;
            v47[5] = 0;
            if ( v49 )
            {
              v50 = off_11EA6C;
              *v46 = v48;
              if ( !v48 )
              {
                if ( *v50 )
                  __enable_irq();
              }
            }
          }
        }
        v51 = off_11EA78;
        while ( !*(uint32_t *)off_11EA78 )
          ;
        sub_12D248(*(uint32_t *)off_11EA7C + 620);
        *v51 = 1;
        sub_10CC88();
        return sub_11DF7C(v8, v72[0]);
      }
      return sub_11DF7C(v8, v72[0]);
    }
  }
  else
  {
    v10 = *(unsigned __int16 *)(v8 + 48);
    if ( **(__int16 **)off_11E840 >= 0 )
      goto LABEL_5;
  }
  if ( !v10 )
    return sub_12F408(dword_11EA90, dword_11EA8C, 1545, v9);
  if ( v10 <= 0x3000 )
    goto LABEL_37;
  return sub_12F408(dword_11EA94, dword_11EA8C, 1547, v9);
}

