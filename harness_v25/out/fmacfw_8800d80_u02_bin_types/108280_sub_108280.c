// sub_108280 @ 0x108280, size 4140 bytes
uint32_t * sub_108280(int a1, unsigned int *a2, int a3, unsigned int a4, unsigned int a5, int a6, __int16 a7)
{
  int *v7; // r4
  unsigned int *v8; // lr
  unsigned int *v9; // r5
  uint32_t *v10; // r12
  int *v11; // r6
  unsigned int *v12; // r11
  int *v13; // r8
  int *v14; // r7
  unsigned int v15; // r5
  void *v17; // r3
  void *v18; // r3
  void *v19; // r3
  uint32_t *v20; // r3
  int v21; // r6
  uint32_t *v22; // r0
  uint32_t *v23; // r2
  unsigned int *v24; // r1
  uint32_t *v25; // r2
  int v26; // r0
  uint32_t *v27; // r3
  unsigned int *v28; // r9
  int *v29; // r11
  int *v30; // r10
  int v31; // r1
  int v32; // r2
  int v33; // s16
  int v34; // r4
  int v35; // r7
  int v36; // r8
  int v37; // r1
  int v38; // r4
  int i; // r6
  int v40; // r5
  int v41; // r3
  int v42; // r2
  int v43; // r6
  int v44; // r1
  int v45; // r6
  int v46; // r5
  int v47; // r3
  signed int v48; // r6
  signed int v49; // r5
  int v50; // r1
  int v51; // r6
  int *v52; // r0
  unsigned int *v53; // r1
  unsigned int *v54; // r3
  int v55; // r2
  int v56; // r5
  int v57; // r4
  int v58; // r7
  int v59; // r6
  int v60; // r10
  void *v61; // r2
  int v62; // r0
  int v63; // r9
  int v64; // r5
  int v65; // r2
  void *v66; // r2
  int v67; // r0
  unsigned int *v68; // r1
  int *v69; // r2
  int v70; // r0
  int *v71; // r4
  uint32_t *result; // r0
  int v73; // r1
  int v74; // r4
  int v75; // r5
  signed int v76; // r6
  signed int v77; // r4
  unsigned int *v78; // r1
  unsigned int *v79; // r3
  bool v80; // cc
  int v81; // r1
  unsigned int *v82; // r1
  unsigned int *v83; // r0
  unsigned int *v84; // r11
  unsigned int *v85; // r12
  uint32_t *v86; // r10
  uint32_t *v87; // r9
  unsigned int *v88; // r3
  unsigned int *v89; // r2
  unsigned int *v90; // r4
  unsigned int *v91; // r0
  unsigned int *v92; // r1
  int v93; // r6
  uint32_t *v94; // r7
  unsigned int *v95; // r2
  uint32_t *v96; // r5
  uint32_t *v97; // r5
  unsigned int *v98; // r1
  int v99; // [sp+8h] [bp-1ECh]
  int v100; // [sp+8h] [bp-1ECh]
  int v101; // [sp+Ch] [bp-1E8h]
  int v102; // [sp+10h] [bp-1E4h]
  int v103; // [sp+14h] [bp-1E0h]
  int v104; // [sp+18h] [bp-1DCh]
  int v105; // [sp+1Ch] [bp-1D8h]
  char *v106; // [sp+20h] [bp-1D4h]
  int v107; // [sp+24h] [bp-1D0h]
  int v108; // [sp+28h] [bp-1CCh]
  int v109; // [sp+2Ch] [bp-1C8h]
  int v110; // [sp+30h] [bp-1C4h]
  int v111; // [sp+34h] [bp-1C0h]
  int v112; // [sp+38h] [bp-1BCh]
  int v113; // [sp+3Ch] [bp-1B8h]
  int v114; // [sp+40h] [bp-1B4h]
  int v115; // [sp+44h] [bp-1B0h]
  unsigned int v116; // [sp+48h] [bp-1ACh]
  int v117; // [sp+4Ch] [bp-1A8h]
  unsigned int v118; // [sp+50h] [bp-1A4h]
  int v119; // [sp+54h] [bp-1A0h]
  int v120; // [sp+58h] [bp-19Ch]
  int v121; // [sp+5Ch] [bp-198h]
  int v122; // [sp+60h] [bp-194h]
  int v123; // [sp+64h] [bp-190h]
  int v124; // [sp+68h] [bp-18Ch]
  int v125; // [sp+6Ch] [bp-188h]
  int v126; // [sp+70h] [bp-184h]
  int v127; // [sp+74h] [bp-180h]
  int v128; // [sp+78h] [bp-17Ch]
  int v129; // [sp+7Ch] [bp-178h]
  int v130; // [sp+80h] [bp-174h]
  int v131; // [sp+84h] [bp-170h]
  int v132; // [sp+88h] [bp-16Ch]
  int v133; // [sp+8Ch] [bp-168h]
  int v134; // [sp+90h] [bp-164h]
  int v135; // [sp+94h] [bp-160h]
  unsigned int v136; // [sp+98h] [bp-15Ch]
  int v137; // [sp+9Ch] [bp-158h]
  unsigned int v138; // [sp+A0h] [bp-154h]
  int v139; // [sp+A4h] [bp-150h]
  unsigned int v140; // [sp+A8h] [bp-14Ch]
  int v141; // [sp+ACh] [bp-148h]
  unsigned int v142; // [sp+B0h] [bp-144h]
  int v143; // [sp+B4h] [bp-140h]
  unsigned int v144; // [sp+B8h] [bp-13Ch]
  unsigned int v145; // [sp+BCh] [bp-138h]
  int v146; // [sp+C0h] [bp-134h]
  int v147; // [sp+C4h] [bp-130h]
  int v148; // [sp+C8h] [bp-12Ch]
  int v149; // [sp+CCh] [bp-128h]
  int v150; // [sp+D0h] [bp-124h]
  int v151; // [sp+D4h] [bp-120h]
  int v152; // [sp+D8h] [bp-11Ch]
  int v153; // [sp+DCh] [bp-118h]
  int v154; // [sp+E0h] [bp-114h]
  int v155; // [sp+E4h] [bp-110h]
  int v156; // [sp+E8h] [bp-10Ch]
  int v157; // [sp+ECh] [bp-108h]
  int v158; // [sp+F0h] [bp-104h]
  int v160; // [sp+F8h] [bp-FCh]
  int v161; // [sp+FCh] [bp-F8h]
  unsigned int *v163; // [sp+104h] [bp-F0h]
  uint32_t v164[3]; // [sp+108h] [bp-ECh]
  unsigned int v165[4]; // [sp+114h] [bp-E0h] BYREF
  int v166; // [sp+124h] [bp-D0h] BYREF
  int v167; // [sp+128h] [bp-CCh]
  int v168; // [sp+12Ch] [bp-C8h]
  uint64_t v169; // [sp+130h] [bp-C4h]
  unsigned int v170; // [sp+150h] [bp-A4h]
  uint32_t v171[10]; // [sp+154h] [bp-A0h] BYREF
  char v172; // [sp+17Ch] [bp-78h] BYREF
  int v173; // [sp+18Ch] [bp-68h]
  int v174; // [sp+198h] [bp-5Ch] BYREF
  int v175; // [sp+19Ch] [bp-58h]
  int v176; // [sp+1A0h] [bp-54h]
  int v177; // [sp+1A4h] [bp-50h]

  v7 = (int *)off_108540;
  v8 = (unsigned int *)off_108574;
  v9 = (unsigned int *)off_108544;
  v10 = off_10857C;
  v11 = (int *)off_108548;
  v12 = (unsigned int *)off_108580;
  v13 = (int *)off_108584;
  v158 = *(uint32_t *)off_108578;
  v157 = *(uint32_t *)off_108540;
  v156 = *(uint32_t *)off_108540;
  v155 = *(uint32_t *)off_108574;
  v154 = *(uint32_t *)off_108544;
  v153 = *(uint32_t *)off_108544;
  v152 = *(uint32_t *)off_108544;
  v151 = *(uint32_t *)off_108544;
  v150 = *(uint32_t *)off_10857C;
  v149 = *(uint32_t *)off_10857C;
  v148 = *(uint32_t *)off_108548;
  v147 = *(uint32_t *)off_108540;
  v146 = *(uint32_t *)off_108540;
  *(uint32_t *)off_108578 = *(uint32_t *)off_108578 & 0xF8FFFFFF | 0x1000000;
  v14 = (int *)off_10854C;
  *v7 |= 0x100000u;
  *v7 |= 0x200000u;
  *v8 = *v8 & 0xFFFFFF0F | 0xC0;
  *v9 |= 0x80u;
  *v9 &= 0xFFFFFF8F;
  *v9 |= 0x400u;
  *v9 = *v9 & 0xFFFFFCFF | 0x100;
  *v10 &= 0xFFFE00FF;
  *v10 |= 0x20000u;
  *v10 |= 0x40000u;
  v145 = *v12;
  v144 = *v12;
  v143 = *(uint32_t *)off_108550;
  v142 = *(uint32_t *)off_108550;
  v141 = *(uint32_t *)off_108554;
  v140 = *(uint32_t *)off_108554;
  v139 = *(uint32_t *)off_108558;
  v138 = *(uint32_t *)off_108558;
  v137 = *(uint32_t *)off_10855C;
  v136 = *(uint32_t *)off_10855C;
  v135 = *v13;
  v134 = *v13;
  v133 = *v13;
  v132 = *v13;
  v131 = *v13;
  v130 = *v11;
  v129 = *v11;
  v128 = *v14;
  v127 = *v14;
  v126 = *v14;
  v125 = *v14;
  v124 = *v7;
  v123 = *v7;
  v122 = *v7;
  v121 = *v7;
  v120 = *(uint32_t *)off_108560;
  v119 = *(uint32_t *)off_108564;
  v118 = *v8;
  v117 = *(uint32_t *)off_108568;
  v116 = *v8;
  v115 = *(uint32_t *)off_10856C;
  v114 = *(uint32_t *)off_108570;
  v112 = *v7;
  v113 = *v7;
  *v11 |= 0x8000u;
  *v11 &= 0xFFFF8FFF;
  *v11 &= ~0x800u;
  *v14 |= 0x800000u;
  v15 = a4;
  *v14 |= 0x400000u;
  LOBYTE(a4) = 90;
  do
    a4 = (unsigned __int8)(a4 - 1);
  while ( a4 );
  v17 = off_10854C;
  *(uint32_t *)off_10854C &= ~0x100000u;
  *(uint32_t *)v17 |= 0x200000u;
  LOBYTE(v17) = 60;
  do
    v17 = (void *)(unsigned __int8)((uint8_t)v17 - 1);
  while ( v17 );
  v18 = off_108540;
  *(uint32_t *)off_10854C |= 0x100000u;
  *(uint32_t *)v18 |= 0x20000u;
  *(uint32_t *)v18 |= 0x10000u;
  LOBYTE(v18) = 90;
  do
    v18 = (void *)(unsigned __int8)((uint8_t)v18 - 1);
  while ( v18 );
  v19 = off_108540;
  *(uint32_t *)off_108540 &= ~0x40000u;
  *(uint32_t *)v19 |= 0x80000u;
  LOBYTE(v19) = 60;
  do
    v19 = (void *)(unsigned __int8)((uint8_t)v19 - 1);
  while ( v19 );
  v20 = off_108540;
  *(uint32_t *)off_108540 |= 0x40000u;
  *v20 |= 0x8000u;
  *v20 |= 0x4000u;
  LOBYTE(v21) = 90;
  do
    v21 = (unsigned __int8)(v21 - 1);
  while ( v21 );
  v22 = off_108560;
  v23 = off_108564;
  v24 = (unsigned int *)off_108574;
  *(uint32_t *)off_108560 |= 0x40000u;
  *v23 |= 0x3000u;
  v25 = off_108540;
  *v24 = *v24 & 0xFFFFFFFC | 1;
  v22[16] = v22[16] & 0xFFE3FFFF | 0xC0000;
  *v24 |= 4u;
  *v25 |= 0x800000u;
  *v25 |= 0x400000u;
  sub_103C6C();
  sub_12ECD0(1, dword_1088AC);
  v111 = *(uint32_t *)off_1088B0;
  *(uint32_t *)off_1088B0 = *(uint32_t *)off_1088B0 & 0xFFFFFFF | 0x10000000;
  do
  {
    sub_10410C(v21, 0);
    v26 = (unsigned __int8)(v21 + 1);
    v21 = (unsigned __int8)(v21 + 2);
    sub_10410C(v26, 0);
  }
  while ( v21 != 32 );
  v27 = off_1088B4;
  *(uint32_t *)off_1088B4 &= ~0x200u;
  *v27 |= 0x200u;
  *v27 &= ~0x200u;
  sub_1071C4();
  if ( a3 == 255 )
  {
    v28 = (unsigned int *)off_1088F4;
    v29 = (int *)off_1088F8;
    v30 = (int *)off_1088FC;
    v31 = *(uint32_t *)(dword_1088B8 + 4);
    v32 = *(uint32_t *)(dword_1088B8 + 8);
    v164[0] = *(uint32_t *)dword_1088B8;
    v164[1] = v31;
    v164[2] = v32;
    memset(v165, 0, sizeof(v165));
    v33 = 0;
    v107 = 6;
    do
    {
      if ( v33 )
      {
        if ( v33 == 1 )
        {
          v167 = 24;
          v34 = 1;
          v163 = a2 + 1;
        }
        else
        {
          v167 = 15;
          v163 = a2;
          v34 = 0;
        }
      }
      else
      {
        v167 = 15;
        v163 = a2 + 2;
        v34 = 2;
      }
      sub_12ECD0(1, dword_1088BC);
      sub_1059E8(a2[v33], v171);
      sub_12ECD0(1, dword_1088C0);
      if ( v173 <= 0 )
      {
        v104 = v164[v34];
      }
      else
      {
        v161 = v34;
        v105 = 2 * (4 * v34 + 1);
        v160 = v34 << 12;
        v35 = dword_1088C4;
        v36 = dword_108900;
        v104 = v164[v34];
        v103 = a1 + 32 * v34;
        v106 = &v172;
        v109 = 0;
        v110 = v107 << 8;
        do
        {
          v37 = dword_1088CC;
          *(uint32_t *)off_1088D0 = dword_1088C8 | v160 | (*(uint32_t *)v106 << 8);
          v106 += 4;
          sub_12ECD0(1, v37);
          sub_12ECD0(1, dword_1088D4);
          v168 = 0;
          sub_107760((int)&v166);
          v38 = v107;
          for ( i = v110; ; i = v38 << 8 )
          {
            *v28 = i & 0xF00 | *v28 & 0xFFFFF0FF;
            *v29 &= v35;
            *v29 &= v36;
            *v30 &= v35;
            *v30 &= v36;
            sub_107A8C((int)&v166);
            sub_107E08();
            sub_1081E8();
            sub_107C48((int)&v166);
            sub_107E70();
            sub_108238();
            v40 = *v30 & 0xFFF;
            v41 = (*v30 & 0x8000000) != 0 ? (HIWORD(*v30) & 0xFFF) - 4096 : HIWORD(*v30) & 0xFFF;
            v42 = (*v30 & 0x800) != 0 ? v40 - 4096 : *v30 & 0xFFF;
            if ( v41 <= 1024 && v42 <= 1024 )
              break;
            v38 = (unsigned __int8)(v38 - 1);
            sub_12ECD0(1, dword_1092B8);
          }
          v107 = v38;
          v110 = i;
          v43 = HIWORD(*v30) & 0xFFF;
          *v28 = ((v38 + 1) << 8) & 0xF00 | *v28 & 0xFFFFF0FF;
          sub_12ECD0(1, dword_1088D8);
          *v30 = dword_1088DC & (v43 << 17) | *v30 & v35;
          sub_107A8C((int)&v166);
          sub_107E08();
          sub_1081E8();
          sub_12ECD0(1, dword_1088E0);
          *v30 = (2 * v40) & 0xFFF | *v30 & v36;
          sub_107C48((int)&v166);
          sub_107E70();
          sub_108238();
          v44 = dword_1088E4;
          v45 = HIWORD(*v30) & 0xFFF;
          v46 = *v30 & 0xFFF;
          v47 = v46 + (v45 << 16);
          *(uint32_t *)(v103 + 8) = v47;
          *(uint32_t *)(v103 + 8) = v47 | (*v28 >> 8 << 28);
          v99 = v45 << 16;
          sub_12ECD0(1, v44);
          *v30 &= v35;
          *v30 &= v36;
          sub_107678((int)&v166, 1);
          v165[0] = v170;
          sub_1079CC(v165, (int)&v166);
          sub_107584((int)&v166, 1);
          v48 = v170;
          sub_12ECD0(1, dword_1088E8);
          *v30 = *v30 & v35 | v99;
          *v30 = v46 | *v30 & v36;
          sub_107584((int)&v166, 1);
          v49 = v170;
          sub_12ECD0(1, dword_1088EC);
          if ( v48 <= v49 )
          {
            sub_12ECD0(1, dword_1092C0);
            v104 = 0;
            *(uint32_t *)(v103 + 8) = 0;
          }
          else
          {
            v104 &= 1u;
            sub_12ECD0(1, dword_1088F0);
          }
          v164[v161] = v104;
          sub_12ECD0(1, dword_108BEC);
          sub_12ECD0(1, dword_108BF0);
          v50 = dword_108BF4;
          v51 = dword_108BF8;
          *v30 = *v30 & v35 | ((*(uint16_t *)(v103 + 10) & 0xFFF) << 16);
          *v30 = *(uint32_t *)(v103 + 8) & 0xFFF | *v30 & v36;
          sub_12ECD0(1, v50);
          sub_12ECD0(1, dword_108BFC);
          v52 = (int *)off_108C00;
          v53 = (unsigned int *)off_108C04;
          v54 = (unsigned int *)off_108C08;
          *v28 &= ~0x40000000u;
          *v28 &= 0xCFFFFFFF;
          v55 = *v52 & v36;
          v171[6] = 1;
          v174 = 600;
          v175 = 600;
          v176 = 0;
          v177 = 0;
          v166 = 0;
          *v52 = v55 | 0x300;
          *v53 = *v53 & 0xFFFFFF8F | 0x50;
          *v54 = *v54 & 0xFFF0FFFF | 0x10000;
          *v54 = *v54 & 0xFFFF0FFF | 0x1000;
          *v54 = *v54 & 0xFFFFF0FF | 0x100;
          *v54 = *v54 & 0xFFFFFF0F | 0x20;
          *v54 = *v54 & 0xFFFFFFF0 | 3;
          v168 = 10;
          v56 = 0;
          sub_107760((int)&v166);
          v108 = 0;
          do
          {
            while ( 1 )
            {
              v101 = v174;
              v102 = v175;
              v57 = v176;
              v100 = v177;
              v166 = v56;
              sub_107EE4(&v174);
              sub_107F54((int)&v174, &v166);
              sub_108080((int)&v166, &v174, v171);
              if ( v56 )
                break;
              if ( v169 )
              {
                v56 = 1;
              }
              else
              {
                sub_12ECD0(1, dword_1092BC);
                ++v108;
                v168 += 6;
                sub_107760((int)&v166);
                v174 = v101;
                v175 = v102;
                v176 = v57;
                v177 = v100;
                v56 = v108 > 2;
              }
              sub_12ECD0(1, v51);
            }
            ++v56;
            sub_12ECD0(1, v51);
          }
          while ( v56 != 5 );
          v73 = dword_108F7C;
          v74 = dword_108F78 & (v177 << 16);
          v75 = v176 & 0xFFF;
          *(uint32_t *)(v103 + 12) = v74 + (((*v28 >> 12) & 7) << 28) + ((HIWORD(*v28) & 7) << 12) + v75;
          sub_12ECD0(1, v73);
          sub_12ECD0(1, dword_108F80);
          *v29 &= v35;
          *v29 &= v36;
          sub_107678((int)&v166, 0);
          v165[0] = v170;
          sub_1079CC(v165, (int)&v166);
          sub_107584((int)&v166, 0);
          v76 = v170;
          sub_12ECD0(1, dword_108F84);
          *v29 = v74 | *v29 & v35;
          *v29 = v75 | *v29 & v36;
          sub_107584((int)&v166, 0);
          v77 = v170;
          sub_12ECD0(1, dword_108F88);
          v78 = (unsigned int *)off_108F90;
          v79 = (unsigned int *)off_108F94;
          *(uint32_t *)off_108F8C = *(uint32_t *)off_108F8C & v36 | 0xC0;
          *v78 = *v78 & 0xFFFFFF8F | 0x40;
          *v79 = *v79 & 0xFFF0FFFF | 0x10000;
          *v79 = *v79 & 0xFFFF0FFF | 0x1000;
          *v79 = *v79 & 0xFFFFF0FF | 0x100;
          *v79 = *v79 & 0xFFFFFF0F | 0x10;
          *v79 = *v79 & 0xFFFFFFF0 | 1;
          if ( v76 <= v77 )
          {
            sub_12ECD0(1, dword_1092C4);
            *(uint32_t *)(v103 + 12) = 0;
          }
          else
          {
            sub_12ECD0(1, dword_108F98);
          }
          v103 += 8;
          v80 = v173 <= ++v109;
          v105 += 2;
        }
        while ( !v80 );
      }
      v81 = dword_108F9C;
      *v163 = *v163 & 0xFFFDFFFF | (v104 << 17);
      sub_12ECD0(1, v81);
      sub_12ECD0(1, dword_108FA0);
      ++v33;
    }
    while ( v33 != 3 );
    sub_1073CC();
    v82 = (unsigned int *)off_108FA4;
    v83 = (unsigned int *)off_108FA8;
    v84 = (unsigned int *)off_108FD0;
    v85 = (unsigned int *)off_108FD4;
    v86 = off_108FD8;
    v87 = off_108FDC;
    *(uint32_t *)off_108FA4 = v130 & 0x8000 | *(uint32_t *)off_108FA4 & 0xFFFF7FFF;
    v88 = (unsigned int *)off_108FAC;
    *v82 = v129 & 0x7000 | *v82 & 0xFFFF8FFF;
    v89 = (unsigned int *)off_108FB0;
    *v83 = v158 & 0x7000000 | *v83 & 0xF8FFFFFF;
    *v82 = *v82 & 0xFFFFF7FF | v148 & 0x800;
    v90 = (unsigned int *)off_108FB4;
    *v88 = *v88 & 0xFFFBFFFF | v146 & 0x40000;
    v91 = (unsigned int *)off_108FB8;
    *v88 = *v88 & 0xFFF7FFFF | v147 & 0x80000;
    v92 = (unsigned int *)off_108FBC;
    *v89 = *v89 & 0xFF7FFFFF | v128 & 0x800000;
    *v89 = *v89 & 0xFFBFFFFF | v127 & 0x400000;
    v93 = dword_108FC0;
    *v89 = *v89 & 0xFFEFFFFF | v126 & 0x100000;
    *v89 = v125 & 0x200000 | *v89 & 0xFFDFFFFF;
    v94 = off_108FC4;
    *v88 = v124 & 0x20000 | *v88 & 0xFFFDFFFF;
    *v88 = v123 & 0x10000 | *v88 & 0xFFFEFFFF;
    *v88 = v122 & 0x8000 | *v88 & 0xFFFF7FFF;
    v95 = (unsigned int *)off_108F94;
    *v88 = v121 & 0x4000 | *v88 & 0xFFFFBFFF;
    v96 = off_108FC8;
    *v84 = v120 & 0x40000 | *v84 & 0xFFFBFFFF;
    *(uint32_t *)off_108FC8 = v119 & 0x3000 | *v96 & 0xFFFFCFFF;
    v97 = off_108FCC;
    *v90 = v118 & 3 | *v90 & 0xFFFFFFFC;
    *(uint32_t *)off_108FCC = v117 & 0x1C0000 | *v97 & 0xFFE3FFFF;
    *v90 = v116 & 4 | *v90 & 0xFFFFFFFB;
    *v88 = v113 & 0x800000 | *v88 & 0xFF7FFFFF;
    *v88 = v112 & 0x400000 | *v88 & 0xFFBFFFFF;
    *v88 = v157 & 0x200000 | *v88 & 0xFFDFFFFF;
    *v88 = v156 & 0x100000 | *v88 & 0xFFEFFFFF;
    *v90 = v155 & 0xF0 | *v90 & 0xFFFFFF0F;
    *v91 = v154 & 0x80 | *v91 & 0xFFFFFF7F;
    *v91 = v153 & 0x70 | *v91 & 0xFFFFFF8F;
    *v91 = v152 & 0x400 | *v91 & 0xFFFFFBFF;
    *v91 = v151 & 0x300 | *v91 & 0xFFFFFCFF;
    *v92 = *v92 & 0xFFBFFFFF | v150 & 0x400000;
    *v92 = *v92 & 0xFFDFFFFF | v149 & 0x200000;
    result = off_1092AC;
    *v92 &= 0xFFFE00FF;
    *v92 &= ~0x20000u;
    *v92 |= 0x40000u;
    *v85 = *v85 & v93 | v145 & 0x3FFF;
    *v85 = *v85 & 0xC000FFFF | ((HIWORD(v144) & 0x3FFF) << 16);
    *v94 = *v94 & v93 | v143 & 0x3FFF;
    *v94 = *v94 & 0xC000FFFF | ((HIWORD(v142) & 0x3FFF) << 16);
    *result = *result & v93 | v141 & 0x3FFF;
    *result = *result & 0xC000FFFF | ((HIWORD(v140) & 0x3FFF) << 16);
    *v86 = *v86 & v93 | v139 & 0x3FFF;
    *v86 = *v86 & 0xC000FFFF | ((HIWORD(v138) & 0x3FFF) << 16);
    *v87 = v93 & *v87 | v137 & 0x3FFF;
    *v87 = *v87 & 0xC000FFFF | ((HIWORD(v136) & 0x3FFF) << 16);
    *v95 = v135 & 0xF0000 | *v95 & 0xFFF0FFFF;
    *v95 = v134 & 0xF000 | *v95 & 0xFFFF0FFF;
    *v95 = v133 & 0xF00 | *v95 & 0xFFFFF0FF;
    *v95 = v132 & 0xF0 | *v95 & 0xFFFFFF0F;
    v98 = (unsigned int *)off_1092B0;
    *v95 = *v95 & 0xFFFFFFF0 | v131 & 0xF;
    *v98 = *v98 & 0x7FFFFFFF | v115 & 0x80000000;
    *(uint32_t *)off_1092B4 = v114;
    *(v84 - 19976) = *(unsigned int *)((char *)v84 + 0xFFFFFFE0 - 79872) & 0xFFFFFFF | v111 & 0xF0000000;
  }
  else
  {
    v58 = dword_108C10;
    v59 = ((int)((unsigned uint64_t)(dword_108C0C * (uint64_t)a3) >> 32) >> 5) - (a3 >> 31);
    v60 = a3 - 100 * v59;
    sub_103B6C();
    v61 = off_108C14;
    v62 = dword_108C18;
    *(uint32_t *)off_108C14 &= ~1u;
    v167 = 30;
    v168 = v59;
    sub_12EA88(v62, v59, v61);
    v63 = HIWORD(v15) & 0xFFF;
    v64 = v15 & 0xFFF;
    sub_12EA88(dword_108C1C, v60, v65);
    sub_12EA88(dword_108C20, v63, v64);
    *(uint32_t *)off_108C24 = a6;
    sub_12EA88(dword_108C28, a6, a6);
    v66 = off_108C00;
    v67 = dword_108C2C;
    *(uint32_t *)off_108C00 = *(uint32_t *)off_108C00 & v58 | a7 & 0xFFF;
    sub_12EA88(v67, a7, v66);
    sub_103CA4(v60);
    v68 = (unsigned int *)off_108C08;
    v69 = (int *)off_108C30;
    v70 = dword_108C34;
    v71 = (int *)off_108C38;
    *(uint32_t *)off_108C08 = *(uint32_t *)off_108C08 & 0xFFF0FFFF | 0x10000;
    *v68 = *v68 & 0xFFFF0FFF | 0x1000;
    *v68 = *v68 & 0xFFFFF0FF | 0x100;
    *v68 = *v68 & 0xFFFFFF0F | 0x20;
    *v68 = *v68 & 0xFFFFFFF0 | 3;
    *v69 = *v69 & v70 | (v63 << 16);
    *v69 = v64 | *v69 & v58;
    *v71 = *v71 & v70 | ((HIWORD(a5) & 0xFFF) << 16);
    *v71 = a5 & 0xFFF | *v71 & v58;
    sub_107518();
    sub_107760((int)&v166);
    sub_107584((int)&v166, 0);
    sub_12ECD0(1, dword_108C3C);
    sub_107584((int)&v166, 0);
    sub_12ECD0(1, dword_108C3C);
    sub_100644(500);
    return (uint32_t *)sub_103F2C();
  }
  return result;
}

