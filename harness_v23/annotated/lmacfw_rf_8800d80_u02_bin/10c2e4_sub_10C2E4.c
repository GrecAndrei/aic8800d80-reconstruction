// v23 annotated: sub_10C2E4 @ 0x10c2e4
// Original: 10c2e4_sub_10C2E4.c
// Primary struct: <unclustered>
//
// sub_10C2E4 @ 0x10c2e4, size 2260 bytes
void __noreturn sub_10C2E4()
{
  _BYTE *v0; // r0
  int *v1; // r2
  _DWORD *v2; // r3
  int v3; // r5
  _DWORD *v4; // r4
  _DWORD *v5; // r10
  int v6; // r1
  _DWORD *v7; // r3
  _DWORD *v8; // r1
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int inited; // r0
  _DWORD *v13; // r3
  _DWORD *v14; // r1
  _DWORD *v15; // r4
  unsigned int v16; // r0
  int v17; // r2
  int v18; // r0
  int v19; // r1
  int v20; // r4
  void *v21; // r2
  int v22; // r0
  int v23; // r3
  int v24; // r4
  _BYTE *v25; // r8
  _DWORD *v26; // r9
  _BYTE *v27; // r7
  int v28; // r5
  int v29; // r0
  int v30; // r8
  _DWORD *v31; // r9
  int v32; // r4
  int i; // r5
  int v34; // r0
  _BYTE *v35; // r1
  int j; // r3
  int v37; // r2
  unsigned int v38; // r1
  int v39; // r2
  int v40; // r0
  int v41; // r0
  _DWORD *v42; // r4
  _DWORD *v43; // r3
  _DWORD *v44; // r2
  int v45; // r3
  int *v46; // r1
  _DWORD *v47; // r2
  int *v48; // r2
  int v49; // r3
  int v50; // r0
  int v51; // r5
  _BYTE *v52; // r4
  int v53; // r0
  int v54; // r2
  int v55; // r1
  int v56; // r2
  _BYTE *v57; // r7
  int v58; // r1
  int v59; // r2
  unsigned int v60; // r3
  int *v61; // r7
  _DWORD *v62; // r3
  _DWORD *v63; // r1
  _BYTE *v64; // r3
  char v65; // r1
  char v66; // r2
  _DWORD *v67; // r9
  int v68; // r2
  int v69; // r7
  _DWORD *v70; // r6
  int v71; // r9
  char *v72; // r11
  _BYTE *v73; // r8
  int v74; // r5
  int v75; // t1
  int v76; // r0
  int v77; // r1
  int v78; // r1
  int v79; // r5
  _DWORD *v80; // r9
  int v81; // r2
  int v82; // r11
  _BYTE *v83; // r6
  _DWORD *v84; // r4
  char *v85; // r7
  _BYTE *v86; // r9
  int v87; // r5
  int v88; // t1
  int v89; // r0
  int v90; // r3
  int v91; // r1
  unsigned __int8 *v92; // [sp+8h] [bp-A4h]
  _DWORD *v93; // [sp+8h] [bp-A4h]
  _BYTE *v94; // [sp+Ch] [bp-A0h]
  __int16 v95; // [sp+12h] [bp-9Ah] BYREF
  int v96; // [sp+14h] [bp-98h] BYREF
  _DWORD v97[3]; // [sp+18h] [bp-94h] BYREF
  unsigned __int8 v98[136]; // [sp+24h] [bp-88h] BYREF

  v0 = off_10C3DC;
  *((_DWORD *)off_10C3D8 + 64) = 8;
  if ( !v0[2] )
    *((_DWORD *)off_10C3E0 + 2) = *((_DWORD *)off_10C3E0 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (int *)off_10C3E0;
  while ( (*((_DWORD *)off_10C3E0 + 12) & 0x22) != 2 )
    ;
  v2 = off_10C3E4;
  v3 = dword_10C3E8;
  v4 = off_10C3D8;
  v5 = off_10C3F8;
  *((_DWORD *)off_10C3E0 + 2) = *((_DWORD *)off_10C3E0 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v6 = *((unsigned __int8 *)v5 + 177);
  *v1 = *v1 & 0x37F | 0x80 | v3 & *v1;
  if ( v6 && (v1[12] & 0x40) == 0 && (v1[12] & 4) != 0 )
  {
    v48 = (int *)off_10CA80;
    v49 = v5[42] | 0x2000000;
    *(_BYTE *)off_10CA7C = 1;
    *v48 = v49;
    v4[14] |= 0x10u;
  }
  else
  {
    *(_DWORD *)off_10C3EC = v5[42];
  }
  if ( v0[2] )
  {
    if ( **(_BYTE **)off_10C3F0 == 2 )
    {
      v62 = off_10CAA4;
      v63 = off_10CAA8;
      *((_DWORD *)off_10CAA4 + 20) |= 0x40000u;
      v63[7] &= ~0x100u;
      v62[9] = v62[9] & 0xFFFFFF00 | 0x60;
      v62[9] = v62[9] & 0xFFFF00FF | 0xDF00;
LABEL_11:
      v10 = irq23_enable();
      if ( !*(_DWORD *)off_10C3F4 )
        goto LABEL_15;
      goto LABEL_12;
    }
    v7 = off_10C3E0;
    **(_BYTE **)off_10C3F0 = 2;
    v8 = off_10C3D8;
    v9 = (unsigned __int8)v0[2];
    v7[20] |= 0x40000u;
    v8[7] &= ~0x100u;
    v7[9] = v7[9] & 0xFFFFFF00 | 0x60;
    v7[9] = v7[9] & 0xFFFF00FF | 0xDF00;
    if ( v9 )
      goto LABEL_11;
  }
  else
  {
    v13 = off_10C71C;
    v14 = off_10C720;
    *((_DWORD *)off_10C71C + 20) |= 0x40000u;
    v14[7] &= ~0x100u;
    v13[9] = v13[9] & 0xFFFFFF00 | 0x60;
    v13[9] = v13[9] & 0xFFFF00FF | 0xDF00;
  }
  v10 = timer_init();
  if ( !*(_DWORD *)off_10C724 )
  {
LABEL_15:
    v15 = off_10C720;
    sub_10300C();
    v15[4] |= 2u;
    clock_calc();
    v95 = 0;
    if ( (*v15 & 0x2000000) != 0 )
    {
      sub_113B88(&v95);
      rf_cmd_query_status((char *)&v95 + 1);
      v16 = (unsigned __int8)v95;
      if ( (_BYTE)v95 )
      {
LABEL_19:
        if ( v16 > 0x1F )
        {
          v16 = 31;
          LOBYTE(v95) = 31;
        }
        sub_10F170(v16);
        v18 = sub_10DA6C(dword_10C728, (unsigned __int8)v95, v17);
LABEL_22:
        v19 = HIBYTE(v95);
        if ( HIBYTE(v95) )
        {
          if ( HIBYTE(v95) <= 0x3Fu )
          {
            v20 = (HIBYTE(v95) << 18) & 0xFC0000;
          }
          else
          {
            v19 = 63;
            HIBYTE(v95) = 63;
            v20 = 16515072;
          }
          v21 = off_10C72C;
          v22 = dword_10C730;
          *(_DWORD *)off_10C72C = *(_DWORD *)off_10C72C & 0xFF03FFFF | v20;
          v18 = sub_10DA6C(v22, v19, v21);
        }
        v23 = *(unsigned __int8 *)off_10C734;
        if ( (v23 == 7 || v23 == 193) && !sub_113B4C(v18) )
        {
          v53 = sub_113B5C(3);
          if ( v53 != 3 )
            sub_10DA6C(dword_10CA8C, v53, v54);
        }
        v24 = HIBYTE(*(_DWORD *)off_10C720) & 2;
        if ( v24 )
        {
          v25 = (_BYTE *)dword_10C790;
          v26 = off_10C794;
          v27 = off_10C738;
          v28 = 0;
          do
          {
            v29 = sub_113DF8(v28, *v26 + 3 * v28);
            ++v28;
            if ( v29 != 546 )
              v27[1] |= 1u;
            *v25 = v29 & 0xF;
            v25[1] = (unsigned __int8)v29 >> 4;
            v25[2] = BYTE1(v29) & 0xF;
            v25 += 3;
          }
          while ( v28 != 3 );
          v30 = dword_10C798;
          v31 = off_10C79C;
          v32 = dword_10C73C;
          for ( i = 0; i != 3; ++i )
          {
            v34 = sub_113F3C(i, *v31 + 6 * i);
            if ( v34 != v32 )
              v27[1] |= 1u;
            v35 = (_BYTE *)v30;
            for ( j = 0; j != 24; j += 4 )
            {
              v37 = v34 >> j;
              *v35++ = v37 & 0xF;
            }
            v30 += 6;
          }
          v38 = 31 - __clz(sub_114208());
          *v27 = v38;
        }
        else
        {
          memset(v97, 0, sizeof(v97));
          if ( rf_param_set_op2(v97) )
          {
            v57 = off_10CA90;
          }
          else
          {
            v79 = dword_10CBCC;
            v80 = off_10CBDC;
            sub_10DA6C(dword_10CBD0, v55, v56);
            v82 = 0;
            v93 = v97;
            v83 = (_BYTE *)v79;
            v84 = v80;
            do
            {
              sub_10DA6C(dword_10CBC0, v82, v81);
              v85 = (char *)v93;
              v86 = v83;
              v87 = 0;
              do
              {
                v88 = *v85++;
                v89 = dword_10CBC4;
                *(_BYTE *)(*v84 + v87 + 3 * v82) = v88;
                v90 = *v84 + v87++;
                sub_10DA6C(v89, *(char *)(v90 + 3 * v82), v88);
                *v86++ = 15;
              }
              while ( v87 != 3 );
              ++v82;
              v93 = (_DWORD *)((char *)v93 + 3);
              v83 += 3;
            }
            while ( v82 != 3 );
            v57 = off_10CBD4;
            v24 = 0;
            sub_10DA6C(dword_10CBC8, v91, v81);
            v57[1] |= 1u;
          }
          memset(v98, 0, 20);
          if ( !rf_emit_setup_word(v98) )
          {
            v67 = off_10CBD8;
            sub_10DA6C(dword_10CBB8, v58, v59);
            v94 = v57;
            v69 = dword_10CBBC;
            v92 = v98;
            v70 = v67;
            v71 = 0;
            do
            {
              sub_10DA6C(dword_10CBC0, v71, v68);
              v72 = (char *)v92;
              v73 = (_BYTE *)v69;
              v74 = 0;
              do
              {
                v75 = *v72++;
                v76 = dword_10CBC4;
                *(_BYTE *)(*v70 + v24 + v74) = v75;
                v77 = *(char *)(*v70 + v24 + v74++);
                sub_10DA6C(v76, v77, v75);
                *v73++ = 15;
              }
              while ( v74 != 6 );
              v24 += 6;
              ++v71;
              v92 += 6;
              v69 += 6;
            }
            while ( v24 != 18 );
            v57 = v94;
            sub_10DA6C(dword_10CBC8, v78, v68);
            v94[1] |= 1u;
          }
          if ( sub_1145DC(&v96) )
          {
            v38 = -1;
            *v57 = -1;
          }
          else
          {
            v60 = (char)v96;
            *v57 = v96;
            v38 = v60;
          }
        }
        v40 = sub_10DA6C(dword_10C740, v38, v39);
        if ( *((_BYTE *)v5 + 372) )
        {
          if ( (*(_DWORD *)off_10C720 & 0x2000000) != 0 )
          {
            v40 = sub_1141CC(v40);
            if ( v40 )
            {
              v50 = sub_11413C();
              v51 = dword_10CA84;
              v52 = off_10CA88;
              *(_BYTE *)off_10CA88 = *(_BYTE *)(dword_10CA84 + v50);
              v52[1] = *(_BYTE *)(v51 + sub_11414C());
              v40 = sub_11415C();
              v52[2] = *(_BYTE *)(v51 + v40);
            }
          }
          else
          {
            *(_DWORD *)v98 = 0;
            v40 = sub_1145B8(v98);
            if ( !v40 )
            {
              v64 = off_10CA88;
              v40 = *(unsigned __int8 *)(dword_10CA84 + v98[0]);
              v65 = *(_BYTE *)(dword_10CA84 + v98[1]);
              v66 = *(_BYTE *)(dword_10CA84 + v98[2]);
              *(_BYTE *)off_10CA88 = v40;
              v64[1] = v65;
              v64[2] = v66;
            }
          }
        }
        v41 = patch_apply_slot_36(v40);
        v42 = off_10C744;
        if ( v41 )
          *(_DWORD *)off_10C744 |= 1u;
        if ( sub_1141F8() )
          *v42 |= 2u;
        *(_DWORD *)off_10C748 &= 0xFFFFFFC7;
        if ( (*(_BYTE *)off_10C734 & 0xC0) == 0xC0 )
        {
          v43 = off_10C750;
          *(_DWORD *)off_10C74C = dword_10C754;
          v44 = off_10C758;
          *v43 = dword_10C75C;
          v45 = dword_10C760;
          v46 = (int *)off_10C764;
          *v44 = dword_10C760;
          v47 = off_10C768;
          *v46 = v45;
          *v47 = dword_10C76C;
        }
        lmac_sub_init(0, 0, 0x10u, dword_10C770);
        lmac_sub_init(0, 16, 0x10u, dword_10C774);
        if ( (*v42 & 2) == 0 )
        {
          v61 = (int *)off_10CA94;
          lmac_sub_init(0, 32, 0x10u, *((_DWORD *)off_10CA94 + 2));
          lmac_sub_init(0, 48, 0x10u, v61[1]);
          lmac_sub_init(0, 64, 0x10u, *v61);
          lmac_sub_init(1, 0, 0x10u, *(_DWORD *)off_10CA98);
          lmac_sub_init(1, 16, 0x10u, *(_DWORD *)off_10CA9C);
        }
        sub_100D18();
        sub_1033C4();
      }
    }
    else
    {
      *(_DWORD *)v98 = 0;
      if ( sub_114558(v98) )
      {
        v16 = (unsigned __int8)v95;
      }
      else
      {
        v16 = v98[0];
        v95 = *(_WORD *)v98;
      }
      if ( v16 )
        goto LABEL_19;
    }
    v18 = sub_10F170(15);
    goto LABEL_22;
  }
LABEL_12:
  v11 = sub_10F1E0(v10);
  inited = rf_init_blockb_e798(v11);
  rf_init_blockc(inited);
  goto LABEL_15;
}

