// v23 annotated: sub_11EA44 @ 0x11ea44
// Original: 11ea44_sub_11EA44.c
// Primary struct: <unclustered>
//
// sub_11EA44 @ 0x11ea44, size 1106 bytes
int __fastcall sub_11EA44(int a1)
{
  int v1; // r8
  int v2; // r10
  int v3; // r11
  _DWORD *v4; // r6
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
  _WORD *v28; // r7
  int *v29; // r9
  unsigned int v30; // r1
  int v31; // r0
  int v32; // r0
  int v33; // r12
  int v34; // r3
  _DWORD *v35; // r1
  _BYTE *v36; // r12
  int v37; // r0
  char v38; // r2
  int v39; // r0
  int v40; // r3
  int *v41; // r2
  int v42; // r3
  int v43; // r1
  int v44; // r3
  unsigned int CPSR; // r0
  _DWORD *v46; // r3
  _DWORD *v47; // r0
  int v48; // r1
  int v49; // r2
  _DWORD *v50; // r2
  _DWORD *v51; // r5
  _DWORD *v52; // r0
  int v53; // r1
  int v54; // r2
  int v55; // r7
  int v56; // r2
  int v57; // r12
  int v58; // r2
  _BYTE *v59; // r1
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

  v4 = off_11EC78;
  v5 = (unsigned __int8 **)off_11EC7C;
  v6 = *((unsigned __int8 *)off_11EC78 + 50);
  v7 = *(unsigned __int8 **)off_11EC7C;
  v8 = a1;
  v72[0] = *(_DWORD *)(a1 + 28);
  v71 = v6;
  v9 = *v7;
  if ( v9 == 3 )
  {
    v2 = sub_12F76C();
    v9 = **v5;
    v3 = v2 + 60;
  }
  if ( v9 == 2 )
  {
    v28 = off_11EC9C;
    if ( !*((_DWORD *)off_11EC9C + 2057) )
    {
      v62 = v72[0];
      *(_BYTE *)(v8 + 16) |= 1u;
      v63 = sub_11E3BC(v8, v62);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_11EEAC = 1;
      }
      v65 = (int *)off_11EEB0;
      ++*(_DWORD *)off_11EEB0;
      v66 = sub_113310(v63, v64);
      if ( *v65 )
      {
        v68 = *v65 - 1;
        v67 = *(_DWORD *)off_11EEAC;
        *v65 = v68;
        if ( !v68 )
        {
          if ( v67 )
            __enable_irq();
        }
      }
      return sub_10DA7C(dword_11EED8, v66, v67);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_11EC90 = 1;
    }
    v29 = (int *)off_11EC94;
    v30 = (unsigned __int16)v28[4122];
    v31 = dword_11ECA0;
    ++*(_DWORD *)off_11EC94;
    if ( v30 > 0x186 )
      v28[4122] = 0;
    v32 = sub_12D4F8(v31);
    v33 = *(_DWORD *)off_11ECA4;
    v34 = (unsigned __int16)v28[4122];
    *(_WORD *)(v32 + 12) = v34;
    v35 = (_DWORD *)(v33 + 8 * v34);
    v35[1] = v8 + 48;
    *v35 = dword_11ECA8;
    v36 = off_11EC8C;
    *(_DWORD *)(v32 + 4) = v35;
    v1 = v32;
    v37 = *v29;
    LOBYTE(v35) = *((_BYTE *)v28 + 3074) + 1;
    v38 = v36[3] + 1;
    v28[4122] = v34 + 1;
    *((_BYTE *)v28 + 3074) = (_BYTE)v35;
    v36[3] = v38;
    if ( v37 )
    {
      v39 = v37 - 1;
      v40 = *(_DWORD *)off_11EC90;
      *v29 = v39;
      if ( !v39 )
      {
        if ( v40 )
          __enable_irq();
      }
    }
    v10 = *(unsigned __int16 *)(v8 + 48);
    v9 = **(__int16 **)off_11EC80;
    if ( v9 >= 0 )
    {
LABEL_37:
      v9 = **v5;
      if ( v9 == 2 )
      {
        sub_11E04C(v72, v10, &v71);
        goto LABEL_7;
      }
LABEL_5:
      if ( v9 == 1 )
      {
        sub_11E184(v72, v10, &v71);
      }
      else
      {
        sub_11E2A4(v72, v10, v3, &v71, 0);
        v4[7] = v10 + v3;
      }
LABEL_7:
      sub_101818((_QWORD *)(v8 + 88), 0);
      v11 = **v5;
      if ( v11 == 3 )
      {
        v41 = (int *)off_11EE98;
        v42 = *((_DWORD *)off_11EE98 + 1);
        *(_DWORD *)(v8 + 100) = dword_11EE9C;
        *(_DWORD *)(v8 + 104) = v8 + 48;
        v43 = dword_11EEA0;
        *(_DWORD *)(v8 + 108) = v2;
        *(_DWORD *)(v42 + 32) = v8 + 104;
        *(_DWORD *)(v8 + 112) = v43;
        *(_DWORD *)(v8 + 116) = 58;
        *(_DWORD *)(v8 + 120) = 58;
        v70 = v8 + 104;
        *(_DWORD *)(v8 + 124) = 262148;
        *(_DWORD *)(v8 + 136) = 0;
        goto LABEL_41;
      }
      if ( v11 != 1 )
      {
        if ( v11 == 2 )
        {
          v19 = (unsigned __int16 *)off_11EEC0;
          if ( *((_BYTE *)off_11EEC0 + 2) )
          {
LABEL_17:
            v20 = *(_DWORD *)(v1 + 4);
            *(_DWORD *)(v1 + 8) = *v19 + 58;
            *(_BYTE *)(v20 + 3) &= 0x3Fu;
            *(_BYTE *)(v1 + 14) = *((_BYTE *)v19 + 3);
            *(_DWORD *)v1 = 0;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(_DWORD *)off_11EC90 = 1;
            }
            v21 = (int *)off_11EC94;
            v22 = dword_11EC98;
            ++*(_DWORD *)off_11EC94;
            v23 = sub_12D470(v22);
            sub_113310(v23, v24);
            if ( *v21 )
            {
              v25 = *v21 - 1;
              v26 = *(_DWORD *)off_11EC90;
              *v21 = v25;
              if ( !v25 )
              {
                if ( v26 )
                  __enable_irq();
              }
            }
            *(_DWORD *)v19 = 0;
            *((_DWORD *)v19 + 1) = 0;
            if ( **v5 != 3 )
              return sub_11E3BC(v8, v72[0]);
            goto LABEL_65;
          }
        }
        return sub_11E3BC(v8, v72[0]);
      }
      v12 = (int *)off_11EC84;
      if ( *((_BYTE *)off_11EC84 + 32) )
      {
        v52 = (_DWORD *)sub_110114();
        v55 = (int)v52;
        if ( v52 )
        {
          if ( *((_BYTE *)v12 + 32) )
          {
            v56 = *v12;
            v57 = v12[1] + 1;
            v52[2] = (v57 << 24) & 0x7F000000 | v52[2] & 0x80FFFFFF;
            v12[1] = v57;
            sub_110F98(v52, v8 + 48, v56, 0x3Au, 0);
            v58 = *((unsigned __int8 *)off_11EEC4 + 192);
            v12[3] += 58;
            if ( v58 )
              sub_11E6B0(v55);
            else
              sub_110E78(v55, v12[1], v12[2]);
            v59 = off_11EEC8;
            v60 = *(_BYTE *)off_11EEC8;
            v12[1] = 0;
            v12[3] = 0;
            *v12 = 0;
            v12[2] = 0;
            *((_BYTE *)v12 + 32) = 0;
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
          v69 = dword_11EEDC;
          *(_BYTE *)(v8 + 16) |= 1u;
          sub_12ECB0(v69, v53, v54);
          *((_BYTE *)v12 + 32) = 0;
        }
      }
      sub_12EEF8(1024, dword_11EC88);
      v13 = *v12;
      *(_BYTE *)(v8 + 16) |= 1u;
      if ( v13 && v12[1] )
      {
        v14 = v8;
        v15 = 0;
        v16 = v13;
        v17 = v14;
        do
        {
          v16 = *(_DWORD *)(v16 + 4);
          sub_110154();
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
        v19 = (unsigned __int16 *)off_11EC8C;
        if ( *((_BYTE *)off_11EC8C + 2) )
          goto LABEL_17;
        return sub_11E3BC(v8, v72[0]);
      }
LABEL_64:
      if ( v18 == 3 )
      {
LABEL_65:
        v41 = (int *)off_11EE98;
LABEL_41:
        sub_10D26C(*v41, v70, 5);
        while ( (*(_DWORD *)off_11EEA4 & 0x800) == 0 )
          ;
        v44 = *(_DWORD *)off_11EEA4;
        if ( (*(_DWORD *)off_11EEA4 & 0x40000) != 0 )
          *(_DWORD *)off_11EEA4 |= 0x4000000u;
        if ( (v44 & 0x800) != 0 )
        {
          CPSR = __get_CPSR();
          *(_DWORD *)(dword_11EEA8 + 4428) |= 0x8000000u;
          if ( CPSR )
          {
            *((_DWORD *)off_11EEB4 + 5) = 0;
          }
          else
          {
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(_DWORD *)off_11EEAC = 1;
            }
            v46 = off_11EEB0;
            v47 = off_11EEB4;
            v48 = *(_DWORD *)off_11EEB0;
            v49 = *(_DWORD *)off_11EEB0 + 1;
            *(_DWORD *)off_11EEB0 = v49;
            v47[5] = 0;
            if ( v49 )
            {
              v50 = off_11EEAC;
              *v46 = v48;
              if ( !v48 )
              {
                if ( *v50 )
                  __enable_irq();
              }
            }
          }
        }
        v51 = off_11EEB8;
        while ( !*(_DWORD *)off_11EEB8 )
          ;
        sub_12D470(*(_DWORD *)off_11EEBC + 556);
        *v51 = 1;
        sub_10CAE0();
        return sub_11E3BC(v8, v72[0]);
      }
      return sub_11E3BC(v8, v72[0]);
    }
  }
  else
  {
    v10 = *(unsigned __int16 *)(v8 + 48);
    if ( **(__int16 **)off_11EC80 >= 0 )
      goto LABEL_5;
  }
  if ( !v10 )
    return sub_12F630(dword_11EED0, dword_11EECC, 1545, v9);
  if ( v10 <= 0x3000 )
    goto LABEL_37;
  return sub_12F630(dword_11EED4, dword_11EECC, 1547, v9);
}

