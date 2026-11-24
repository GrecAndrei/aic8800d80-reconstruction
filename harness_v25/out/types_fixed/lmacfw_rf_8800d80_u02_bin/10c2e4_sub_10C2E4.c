// sub_10C2E4 @ 0x10c2e4, size 2260 bytes
void __fastcall sub_10C2E4()
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
  _DWORD *v10; // r3
  _DWORD *v11; // r1
  _DWORD *v12; // r4
  unsigned int v13; // r0
  int v14; // r4
  int v15; // r0
  int v16; // r3
  int v17; // r4
  _BYTE *v18; // r8
  _DWORD *v19; // r9
  _BYTE *v20; // r7
  int v21; // r5
  int v22; // r0
  int v23; // r8
  _DWORD *v24; // r9
  int v25; // r4
  int i; // r5
  int v27; // r0
  _BYTE *v28; // r1
  int j; // r3
  int v30; // r2
  unsigned int v31; // r0
  _DWORD *v32; // r4
  _DWORD *v33; // r3
  _DWORD *v34; // r2
  int v35; // r3
  int *v36; // r1
  _DWORD *v37; // r2
  _BYTE *v38; // r10
  int v39; // r5
  _DWORD *v40; // r2
  int v41; // r1
  int v42; // r3
  int v43; // r1
  int *v44; // r2
  int v45; // r3
  int v46; // r0
  int v47; // r5
  _BYTE *v48; // r4
  unsigned int v49; // r0
  _BYTE *v50; // r7
  int *v51; // r7
  _DWORD *v52; // r3
  _DWORD *v53; // r1
  _BYTE *v54; // r3
  char v55; // r1
  char v56; // r2
  _DWORD *v57; // r9
  int v58; // r7
  _DWORD *v59; // r6
  int v60; // r9
  unsigned __int8 *v61; // r11
  _BYTE *v62; // r8
  int v63; // r5
  char v64; // t1
  int v65; // r0
  int v66; // r1
  int v67; // r5
  _DWORD *v68; // r9
  int v69; // r11
  _BYTE *v70; // r6
  _DWORD *v71; // r4
  int *v72; // r7
  _BYTE *v73; // r9
  int v74; // r5
  char v75; // t1
  int v76; // r0
  int v77; // r3
  unsigned __int8 *v78; // [sp+8h] [bp-A4h]
  int *v79; // [sp+8h] [bp-A4h]
  _BYTE *v80; // [sp+Ch] [bp-A0h]
  __int16 v81; // [sp+12h] [bp-9Ah] BYREF
  int v82; // [sp+14h] [bp-98h] BYREF
  int v83; // [sp+18h] [bp-94h] BYREF
  int v84; // [sp+1Ch] [bp-90h]
  int v85; // [sp+20h] [bp-8Ch]
  unsigned __int8 *(_DWORD *)(v86 + 0x220); // [sp+24h] [bp-88h] BYREF

  v0 = off_10C3DC;
  *((_DWORD *)off_10C3D8 + 64) = 8;
  if ( !*(_DWORD *)(v0 + 0x8) )
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
  *(_DWORD *)(v1 + 0x54) = *(_DWORD *)(v1 + 0x54) & 0x37F | 0x80 | *(_DWORD *)(v1 + 0x54) & v3;
  *(_DWORD *)(v4 + 0x144) = 16;
  v6 = *((unsigned __int8 *)v5 + 177);
  *v1 = *v1 & 0x37F | 0x80 | v3 & *v1;
  if ( v6 && (*(_DWORD *)(v1 + 0x30) & 0x40) == 0 && (*(_DWORD *)(v1 + 0x30) & 4) != 0 )
  {
    v44 = (int *)off_10CA80;
    v45 = *(_DWORD *)(v5 + 0xa8) | 0x2000000;
    *(_BYTE *)off_10CA7C = 1;
    *v44 = v45;
    *(_DWORD *)(v4 + 0x38) |= 0x10u;
  }
  else
  {
    *(_DWORD *)off_10C3EC = *(_DWORD *)(v5 + 0xa8);
  }
  if ( *(_DWORD *)(v0 + 0x8) )
  {
    if ( **(_BYTE **)off_10C3F0 == 2 )
    {
      v52 = off_10CAA4;
      v53 = off_10CAA8;
      *((_DWORD *)off_10CAA4 + 20) |= 0x40000u;
      *(_DWORD *)(v53 + 0x1c) &= ~0x100u;
      *(_DWORD *)(v52 + 0x24) = *(_DWORD *)(v52 + 0x24) & 0xFFFFFF00 | 0x60;
      *(_DWORD *)(v52 + 0x24) = *(_DWORD *)(v52 + 0x24) & 0xFFFF00FF | 0xDF00;
LABEL_11:
      irq23_enable();
      if ( !*(_DWORD *)off_10C3F4 )
        goto LABEL_15;
      goto LABEL_12;
    }
    v7 = off_10C3E0;
    **(_BYTE **)off_10C3F0 = 2;
    v8 = off_10C3D8;
    v9 = (unsigned __int8)*(_DWORD *)(v0 + 0x8);
    *(_DWORD *)(v7 + 0x50) |= 0x40000u;
    *(_DWORD *)(v8 + 0x1c) &= ~0x100u;
    *(_DWORD *)(v7 + 0x24) = *(_DWORD *)(v7 + 0x24) & 0xFFFFFF00 | 0x60;
    *(_DWORD *)(v7 + 0x24) = *(_DWORD *)(v7 + 0x24) & 0xFFFF00FF | 0xDF00;
    if ( v9 )
      goto LABEL_11;
  }
  else
  {
    v10 = off_10C71C;
    v11 = off_10C720;
    *((_DWORD *)off_10C71C + 20) |= 0x40000u;
    *(_DWORD *)(v11 + 0x1c) &= ~0x100u;
    *(_DWORD *)(v10 + 0x24) = *(_DWORD *)(v10 + 0x24) & 0xFFFFFF00 | 0x60;
    *(_DWORD *)(v10 + 0x24) = *(_DWORD *)(v10 + 0x24) & 0xFFFF00FF | 0xDF00;
  }
  timer_init();
  if ( !*(_DWORD *)off_10C724 )
  {
LABEL_15:
    v12 = off_10C720;
    sub_10300C();
    *(_DWORD *)(v12 + 0x10) |= 2u;
    clock_calc();
    v81 = 0;
    if ( (*v12 & 0x2000000) != 0 )
    {
      sub_113B88(&v81);
      rf_cmd_query_status((_BYTE *)&v81 + 1);
      v13 = (unsigned __int8)v81;
      if ( (_BYTE)v81 )
      {
LABEL_19:
        if ( v13 > 0x1F )
        {
          v13 = 31;
          LOBYTE(v81) = 31;
        }
        sub_10F170(v13);
        sub_10DA6C(dword_10C728, (unsigned __int8)v81);
LABEL_22:
        if ( HIBYTE(v81) )
        {
          if ( HIBYTE(v81) <= 0x3Fu )
          {
            v14 = (HIBYTE(v81) << 18) & 0xFC0000;
          }
          else
          {
            HIBYTE(v81) = 63;
            v14 = 16515072;
          }
          v15 = dword_10C730;
          *(_DWORD *)off_10C72C = *(_DWORD *)off_10C72C & 0xFF03FFFF | v14;
          sub_10DA6C(v15);
        }
        v16 = *(unsigned __int8 *)off_10C734;
        if ( (v16 == 7 || v16 == 193) && !sub_113B4C() )
        {
          v49 = sub_113B5C(3);
          if ( v49 != 3 )
            sub_10DA6C(dword_10CA8C, v49);
        }
        v17 = HIBYTE(*(_DWORD *)off_10C720) & 2;
        if ( v17 )
        {
          v18 = (_BYTE *)dword_10C790;
          v19 = off_10C794;
          v20 = off_10C738;
          v21 = 0;
          do
          {
            v22 = sub_113DF8(v21, *v19 + 3 * v21);
            ++v21;
            if ( v22 != 546 )
              *(_DWORD *)(v20 + 0x4) |= 1u;
            *v18 = v22 & 0xF;
            *(_DWORD *)(v18 + 0x4) = (unsigned __int8)v22 >> 4;
            *(_DWORD *)(v18 + 0x8) = BYTE1(v22) & 0xF;
            v18 += 3;
          }
          while ( v21 != 3 );
          v23 = dword_10C798;
          v24 = off_10C79C;
          v25 = dword_10C73C;
          for ( i = 0; i != 3; ++i )
          {
            v27 = sub_113F3C(i, *v24 + 6 * i);
            if ( v27 != v25 )
              *(_DWORD *)(v20 + 0x4) |= 1u;
            v28 = (_BYTE *)v23;
            for ( j = 0; j != 24; j += 4 )
            {
              v30 = v27 >> j;
              *v28++ = v30 & 0xF;
            }
            v23 += 6;
          }
          *v20 = 31 - __clz(sub_114208());
        }
        else
        {
          v84 = 0;
          v85 = 0;
          v83 = 0;
          if ( rf_param_set_op2((int)&v83) )
          {
            v50 = off_10CA90;
          }
          else
          {
            v67 = dword_10CBCC;
            v68 = off_10CBDC;
            sub_10DA6C(dword_10CBD0);
            v69 = 0;
            v79 = &v83;
            v70 = (_BYTE *)v67;
            v71 = v68;
            do
            {
              sub_10DA6C(dword_10CBC0, v69);
              v72 = v79;
              v73 = v70;
              v74 = 0;
              do
              {
                v75 = *(_BYTE *)v72;
                v72 = (int *)((char *)v72 + 1);
                v76 = dword_10CBC4;
                *(_BYTE *)(*v71 + v74 + 3 * v69) = v75;
                v77 = *v71 + v74++;
                sub_10DA6C(v76, *(char *)(v77 + 3 * v69));
                *v73++ = 15;
              }
              while ( v74 != 3 );
              ++v69;
              v79 = (int *)((char *)v79 + 3);
              v70 += 3;
            }
            while ( v69 != 3 );
            v50 = off_10CBD4;
            v17 = 0;
            sub_10DA6C(dword_10CBC8);
            *(_DWORD *)(v50 + 0x4) |= 1u;
          }
          memset(v86, 0, 20);
          if ( !rf_emit_setup_word((int)v86) )
          {
            v57 = off_10CBD8;
            sub_10DA6C(dword_10CBB8);
            v80 = v50;
            v58 = dword_10CBBC;
            v78 = v86;
            v59 = v57;
            v60 = 0;
            do
            {
              sub_10DA6C(dword_10CBC0, v60);
              v61 = v78;
              v62 = (_BYTE *)v58;
              v63 = 0;
              do
              {
                v64 = *v61++;
                v65 = dword_10CBC4;
                *(_BYTE *)(*v59 + v17 + v63) = v64;
                v66 = *(char *)(*v59 + v17 + v63++);
                sub_10DA6C(v65, v66);
                *v62++ = 15;
              }
              while ( v63 != 6 );
              v17 += 6;
              ++v60;
              v78 += 6;
              v58 += 6;
            }
            while ( v17 != 18 );
            v50 = v80;
            sub_10DA6C(dword_10CBC8);
            *(_DWORD *)(v80 + 0x4) |= 1u;
          }
          if ( sub_1145DC((int)&v82) )
            *v50 = -1;
          else
            *v50 = v82;
        }
        sub_10DA6C(dword_10C740);
        if ( *((_BYTE *)v5 + 372) )
        {
          if ( (*(_DWORD *)off_10C720 & 0x2000000) != 0 )
          {
            if ( sub_1141CC() )
            {
              v46 = sub_11413C();
              v47 = dword_10CA84;
              v48 = off_10CA88;
              *(_BYTE *)off_10CA88 = *(_BYTE *)(dword_10CA84 + v46);
              *(_DWORD *)(v48 + 0x4) = *(_BYTE *)(v47 + sub_11414C());
              *(_DWORD *)(v48 + 0x8) = *(_BYTE *)(v47 + sub_11415C());
            }
          }
          else
          {
            *(_DWORD *)v86 = 0;
            if ( !sub_1145B8((int)v86) )
            {
              v54 = off_10CA88;
              v55 = *(_BYTE *)(dword_10CA84 + *(_DWORD *)(v86 + 0x4));
              v56 = *(_BYTE *)(dword_10CA84 + *(_DWORD *)(v86 + 0x8));
              *(_BYTE *)off_10CA88 = *(_BYTE *)(dword_10CA84 + *(_DWORD *)(v86 + 0x0));
              *(_DWORD *)(v54 + 0x4) = v55;
              *(_DWORD *)(v54 + 0x8) = v56;
            }
          }
        }
        v31 = patch_apply_slot_36();
        v32 = off_10C744;
        if ( v31 )
          *(_DWORD *)off_10C744 |= 1u;
        if ( sub_1141F8() )
          *v32 |= 2u;
        *(_DWORD *)off_10C748 &= 0xFFFFFFC7;
        if ( (*(_BYTE *)off_10C734 & 0xC0) == 0xC0 )
        {
          v33 = off_10C750;
          *(_DWORD *)off_10C74C = dword_10C754;
          v34 = off_10C758;
          *v33 = dword_10C75C;
          v35 = dword_10C760;
          v36 = (int *)off_10C764;
          *v34 = dword_10C760;
          v37 = off_10C768;
          *v36 = v35;
          *v37 = dword_10C76C;
        }
        lmac_sub_init(0, 0, 0x10u, dword_10C770);
        lmac_sub_init(0, 16, 0x10u, dword_10C774);
        if ( (*v32 & 2) == 0 )
        {
          v51 = (int *)off_10CA94;
          lmac_sub_init(0, 32, 0x10u, *((_DWORD *)off_10CA94 + 2));
          lmac_sub_init(0, 48, 0x10u, *(_DWORD *)(v51 + 0x4));
          lmac_sub_init(0, 64, 0x10u, *v51);
          lmac_sub_init(1, 0, 0x10u, *(_DWORD *)off_10CA98);
          lmac_sub_init(1, 16, 0x10u, *(_DWORD *)off_10CA9C);
        }
        sub_100D18();
        sub_1033C4();
        sub_100C3C(0);
        sub_1033C4();
        if ( (*(_BYTE *)off_10C734 & 0xC0) != 0xC0 && (*(_DWORD *)(v5 + 0x188) & 4) != 0 )
        {
          v40 = off_10CA70;
          v41 = dword_10CA74;
          *((_DWORD *)off_10CA70 + 13) = dword_10CA74;
          v41 += 36;
          *(_DWORD *)(v40 + 0x38) = v41;
          v41 -= 37;
          *(_DWORD *)(v40 + 0x1b4) = v41;
          v41 += 27;
          *(_DWORD *)(v40 + 0x1b8) = v41;
          v41 -= 25;
          *(_DWORD *)(v40 + 0x330) = v41;
          v41 += 17;
          *(_DWORD *)(v40 + 0x334) = v41;
          v41 += 16;
          *(_DWORD *)(v40 + 0x338) = v41;
          v41 += 25;
          *(_DWORD *)(v40 + 0x3c) = v41;
          *(_DWORD *)(v40 + 0x1bc) = v41;
          *(_DWORD *)(v40 + 0x33c) = v41;
          *(_DWORD *)(v40 + 0x4bc) = v41;
          *(_DWORD *)(v40 + 0x63c) = v41;
          *(_DWORD *)(v40 + 0x7bc) = v41;
          v41 -= 48;
          v42 = dword_10CA78;
          *(_DWORD *)(v40 + 0x4b0) = v41;
          *(_DWORD *)(v40 + 0x630) = v41;
          *(_DWORD *)(v40 + 0x7b0) = v41;
          v41 += 16;
          *(_DWORD *)(v40 + 0x4b4) = v41;
          *(_DWORD *)(v40 + 0x634) = v41;
          *(_DWORD *)(v40 + 0x7b4) = v41;
          v41 += 16;
          *(_DWORD *)(v40 + 0x4b8) = v41;
          *(_DWORD *)(v40 + 0x638) = v41;
          *(_DWORD *)(v40 + 0x7b8) = v41;
          v43 = v42 + 7584;
          do
          {
            *(_DWORD *)(v42 + 1272) |= 0x8000u;
            v42 += 1264;
          }
          while ( v43 != v42 );
        }
        v38 = off_10C7A0;
        v39 = dword_10C77C;
        *(_DWORD *)off_10C778 |= 0x8000000u;
        v83 = 3983;
        v84 = v39;
        *v38 = 2;
        lmac_init_frame_n_1b4(0, 2437, &v83, (unsigned __int16 *)v86);
      }
    }
    else
    {
      *(_DWORD *)v86 = 0;
      if ( sub_114558((int)v86) )
      {
        v13 = (unsigned __int8)v81;
      }
      else
      {
        v13 = *(_DWORD *)(v86 + 0x0);
        v81 = *(_WORD *)v86;
      }
      if ( v13 )
        goto LABEL_19;
    }
    sub_10F170(15);
    goto LABEL_22;
  }
LABEL_12:
  sub_10F1E0();
  rf_init_blockb_e798();
  rf_init_blockc();
  goto LABEL_15;
}
