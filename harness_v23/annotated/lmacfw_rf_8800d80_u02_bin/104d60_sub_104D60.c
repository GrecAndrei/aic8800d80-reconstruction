// v23 annotated: sub_104D60 @ 0x104d60
// Original: 104d60_sub_104D60.c
// Primary struct: <unclustered>
//
// sub_104D60 @ 0x104d60, size 1618 bytes
int __fastcall sub_104D60(
        int a1,
        int a2,
        float *a3,
        int a4,
        unsigned __int8 a5,
        char a6,
        unsigned __int8 a7,
        int a8,
        int a9)
{
  float *v11; // r4
  int v12; // r10
  int v13; // r9
  float *v14; // r5
  float v15; // s15
  float v16; // s16
  __int64 v17; // r6
  __int64 v18; // r0
  __int64 v19; // r0
  int v20; // r2
  int v21; // r3
  __int64 v22; // r0
  float v23; // s17
  float *v24; // r10
  float *v25; // r9
  int v26; // r5
  float *v27; // r4
  __int64 v28; // r6
  __int64 v29; // r0
  int v30; // r0
  float v31; // s13
  int v32; // r5
  float *v33; // r2
  float *v34; // r3
  float v35; // s15
  float v36; // s10
  float v37; // s11
  float v38; // s12
  float *v39; // r3
  float v40; // s18
  float *v41; // r7
  float *v42; // r6
  float v43; // s15
  float v44; // s16
  float *v45; // r9
  float v46; // s19
  float v47; // s17
  __int64 v48; // r0
  float v49; // s17
  float v50; // s19
  int v51; // r5
  int v52; // r10
  int v53; // r11
  int v54; // r2
  float *v55; // r7
  float v56; // s18
  float v57; // s16
  __int64 v58; // r0
  float v59; // s15
  bool v60; // zf
  float v61; // r9
  float v62; // s16
  float *v63; // r5
  int *v64; // r6
  float *v65; // r8
  int *v66; // r7
  int v67; // r9
  float v68; // s13
  float v69; // s15
  int v70; // r1
  float v71; // s14
  int v72; // r2
  int v73; // s13
  int v74; // s15
  int v75; // r3
  int v76; // r11
  int v77; // r7
  int v78; // r5
  int v79; // r8
  int v80; // r10
  int v81; // r9
  int v82; // r1
  int v83; // r6
  int v84; // r3
  int v85; // r4
  int v86; // r5
  int v87; // r9
  int v88; // r7
  int v89; // r6
  int v90; // r11
  int *v91; // r0
  int v92; // r12
  int v93; // t1
  int v95; // r6
  int v96; // r4
  int v97; // r5
  _DWORD *v98; // r1
  int v99; // r2
  int v100; // r6
  int v101; // r1
  int *v102; // r4
  int v103; // t1
  _DWORD *v104; // r12
  int v105; // r2
  int v106; // r0
  int *v107; // r2
  int *v108; // r0
  int v109; // r1
  int v110; // t1
  int v111; // [sp+2Ch] [bp-180h]
  int v112; // [sp+30h] [bp-17Ch]
  int v113; // [sp+30h] [bp-17Ch]
  int v114; // [sp+30h] [bp-17Ch]
  float *v115; // [sp+34h] [bp-178h]
  float *v116; // [sp+34h] [bp-178h]
  int v117; // [sp+34h] [bp-178h]
  float *v118; // [sp+38h] [bp-174h]
  int v119; // [sp+38h] [bp-174h]
  int v120; // [sp+38h] [bp-174h]
  int v121; // [sp+3Ch] [bp-170h]
  int v122; // [sp+40h] [bp-16Ch]
  int v123; // [sp+44h] [bp-168h]
  int v124; // [sp+48h] [bp-164h]
  int v126; // [sp+5Ch] [bp-150h] BYREF
  int v127; // [sp+60h] [bp-14Ch]
  int v128; // [sp+64h] [bp-148h]
  float v129[16]; // [sp+68h] [bp-144h] BYREF
  float v130[16]; // [sp+A8h] [bp-104h] BYREF
  _BYTE v131[64]; // [sp+E8h] [bp-C4h] BYREF
  int v132; // [sp+128h] [bp-84h] BYREF
  int v133; // [sp+12Ch] [bp-80h]
  int v134; // [sp+130h] [bp-7Ch]
  int v135; // [sp+134h] [bp-78h]
  int v136; // [sp+138h] [bp-74h]
  int v137; // [sp+13Ch] [bp-70h]
  int v138; // [sp+140h] [bp-6Ch]
  int v139; // [sp+144h] [bp-68h]
  int v140; // [sp+148h] [bp-64h]
  int v141; // [sp+14Ch] [bp-60h]
  int v142; // [sp+150h] [bp-5Ch]
  int v143; // [sp+154h] [bp-58h]
  int v144; // [sp+158h] [bp-54h]
  int v145; // [sp+15Ch] [bp-50h]
  int v146; // [sp+160h] [bp-4Ch]
  int v147; // [sp+164h] [bp-48h]
  _DWORD v148[8]; // [sp+168h] [bp-44h] BYREF
  int v149; // [sp+188h] [bp-24h]
  int v150; // [sp+18Ch] [bp-20h]
  int v151; // [sp+190h] [bp-1Ch]
  int v152; // [sp+194h] [bp-18h]
  int v153; // [sp+198h] [bp-14h]
  int v154; // [sp+19Ch] [bp-10h]
  int v155; // [sp+1A0h] [bp-Ch]
  int v156; // [sp+1A4h] [bp-8h]
  _BYTE v157[4]; // [sp+1A8h] [bp-4h] BYREF

  v11 = a3;
  v112 = a9 - 1;
  if ( a2 > 1 )
  {
    v12 = dword_105048;
    v13 = (int)&a3[a2 + 32];
    v14 = a3 + 33;
    do
    {
      v15 = *v14++;
      v16 = *(v14 - 2);
      if ( v15 < v16 )
      {
        v17 = sub_127570(LODWORD(v15));
        v18 = sub_127570(LODWORD(v16));
        v19 = sub_127620(v18, HIDWORD(v18), dword_105040, dword_105044);
        if ( sub_127B04(v17, HIDWORD(v17), v19, HIDWORD(v19)) )
        {
          sub_11F74C(1, v12, v20, v21);
          v16 = *(v14 - 2);
        }
        *(v14 - 1) = v16;
      }
    }
    while ( (float *)v13 != v14 );
  }
  if ( a1 > 0 )
  {
    v22 = sub_12754C(a1);
    v23 = flt_105038;
    v118 = v11;
    v24 = v130;
    v25 = (float *)v131;
    v26 = 0;
    v27 = v129;
    v28 = v22;
    do
    {
      v29 = sub_12754C(++v26);
      v30 = sub_127874(v29, HIDWORD(v29), v28, HIDWORD(v28));
      *(_DWORD *)v27++ = sub_127BE4(v30);
      *v24++ = 1.0;
      *v25++ = v23;
    }
    while ( v26 != a1 );
    v11 = v118;
  }
  v31 = v129[v112];
  v32 = 0;
  v119 = a2 - 1;
  v128 = a2 - 1;
  sub_104CC0(a2, v31, &v126, (int)v11, 0);
  v33 = &v11[v127];
  v34 = &v11[v126];
  v35 = *v33;
  v36 = v33[32];
  v37 = v34[32] - v36;
  v38 = *v34 - *v33;
  v39 = &v130[v112];
  *v39 = v31;
  v40 = (float)((float)((float)(v37 / v38) * (float)(v31 - v35)) + v36) / v31;
  if ( a1 <= 0 )
  {
    if ( a1 )
    {
      sub_11F74C(1, dword_1053BC, v130, v39);
      goto LABEL_44;
    }
  }
  else
  {
    v41 = v130;
    v42 = v129;
    do
    {
      if ( v32 != v112 )
      {
        v44 = v40 * *v42;
        sub_104CC0(a2, v44, &v126, (int)v11, 1);
        if ( v126 )
        {
          v45 = &v11[v126];
          if ( v119 == v127
            || (v46 = v11[v127 + 32],
                v115 = &v11[v127],
                v47 = v45[32] - v46,
                v48 = sub_127570(LODWORD(v47)),
                sub_127B04(v48, HIDWORD(v48), dword_105030, dword_105034)) )
          {
            v43 = 1.0;
          }
          else
          {
            v43 = (float)((float)((float)(*v45 - *v115) * (float)(v44 - v46)) / v47) + *v115;
          }
        }
        else
        {
          v43 = (float)(v44 * *v11) / v11[32];
        }
        *v41 = v43;
      }
      ++v32;
      ++v41;
      ++v42;
    }
    while ( a1 != v32 );
  }
  v49 = flt_105038;
  v113 = a1;
  v50 = flt_10503C;
  v51 = a9 - 1;
  v52 = -1;
  v53 = a9 - 1;
  while ( 1 )
  {
    v61 = v130[v51];
    sub_104CC0(a2, v61, &v126, (int)v11, 0);
    if ( v126 )
    {
      v116 = &v11[v127];
      v54 = a2 - 1;
      v55 = &v11[v126];
      if ( v119 == v127 )
      {
        v59 = v11[v119 + 96];
      }
      else
      {
        v56 = *v116;
        v57 = *v55 - *v116;
        v58 = sub_127570(LODWORD(v57));
        if ( !sub_127B40(v58, HIDWORD(v58), dword_105030, dword_105034) )
          v57 = v50;
        v59 = (float)((float)((float)(v55[96] - v116[96]) / v57) * (float)(v61 - v56)) + v116[96];
      }
    }
    else
    {
      v59 = v11[v53 + 96];
    }
    v60 = v51 == v53;
    if ( v51 != v53 )
    {
      v59 = v49 - v59;
      *(float *)&v157[4 * v51 - 192] = v59;
    }
    v51 = v52 + 1;
    if ( v60 )
      v49 = v59;
    if ( v113 <= v51 )
      break;
    ++v52;
  }
  sub_11F74C(1, dword_1052FC, v54, v113);
  if ( v113 > 0 )
  {
    v62 = flt_105300;
    v63 = v130;
    v64 = &v132;
    v65 = (float *)v131;
    v66 = v148;
    v67 = 0;
    do
    {
      v68 = *v65++;
      v69 = *v63++;
      v70 = dword_105304;
      v71 = v68 / v62;
      v72 = v67++;
      v73 = vcvts_n_s32_f32(v69, 0xAu);
      v74 = vcvts_n_s32_f32(v71, 9u);
      v75 = v73;
      *v64++ = v73;
      if ( v73 >= 1024 )
      {
        *(v64 - 1) = 1023;
        v75 = 1023;
      }
      *v66++ = v74;
      if ( v74 < 0 )
        *(v66 - 1) = v74 + (v74 < 0 ? 0x400 : 0);
      sub_11F74C(1, v70, v72, v75);
    }
    while ( v113 != v67 );
  }
LABEL_44:
  v76 = (v135 << 10) + (v134 << 20) + v136;
  v111 = (v138 << 10) + (v137 << 20) + v139;
  v114 = (v141 << 10) + (v140 << 20) + v142;
  v117 = (v144 << 10) + (v143 << 20) + v145;
  v121 = v148[1] + 1049600 * v148[0];
  v122 = (v148[3] << 10) + (v148[2] << 20) + v148[4];
  v123 = (v148[6] << 10) + (v148[5] << 20) + v148[7];
  v120 = (v147 << 10) + (v146 << 20);
  v77 = (v150 << 10) + (v149 << 20) + v151;
  v78 = 15 - a8;
  v79 = (v153 << 10) + (v152 << 20) + v154;
  v80 = (v156 << 10) + (v155 << 20);
  v81 = v133 + (v132 << 10);
  if ( !a7 )
  {
    if ( a8 == 4 )
    {
      v78 = 1;
    }
    else if ( a8 == 7 )
    {
      v78 = 0;
    }
LABEL_48:
    v82 = dword_10530C;
    v83 = 48 * v78 + 1264 * a7 + dword_105308;
    v124 = v78 + 24;
    v84 = v78;
    v85 = a4 + 96 + 48 * v78;
    v86 = v133 + (v132 << 10);
    v87 = (v150 << 10) + (v149 << 20) + v151;
    v88 = v83;
    v89 = (v135 << 10) + (v134 << 20) + v136;
    v90 = v84;
    do
    {
      sub_11F74C(1, v82, v90, v84);
      *(_DWORD *)(v85 - 40) = v111;
      *(_DWORD *)(v85 - 36) = v114;
      *(_DWORD *)(v85 - 32) = v117;
      *(_DWORD *)(v85 - 28) = v120;
      *(_DWORD *)(v85 - 24) = v121;
      *(_DWORD *)(v85 - 20) = v122;
      v82 = dword_10530C;
      *(_DWORD *)(v85 - 48) = v86;
      *(_DWORD *)(v85 - 44) = v89;
      *(_DWORD *)(v85 - 16) = v123;
      *(_DWORD *)(v85 - 12) = v87;
      *(_DWORD *)(v85 - 8) = v79;
      *(_DWORD *)(v85 - 4) = v80;
      v91 = (int *)(v85 - 48);
      v92 = v88;
      do
      {
        v93 = *v91++;
        *(_DWORD *)(v92 + 4) = v93;
        v92 += 4;
      }
      while ( (int *)v85 != v91 );
      v84 = v124;
      v90 += 8;
      v88 += 384;
      v85 += 384;
    }
    while ( v124 != v90 );
    v76 = v89;
    v81 = v86;
    return sub_11F74C(1, dword_105310, v81, v76);
  }
  if ( a8 == 7 )
    v78 = 5;
  if ( !a6 )
    goto LABEL_48;
  if ( a5 == 2 )
  {
    v95 = dword_1053B8;
    sub_11F74C(1, dword_1053B4, v78, 2);
    v104 = (_DWORD *)(a4 + 48 * v78);
    v104[14] = v111;
    v104[15] = v114;
    v104[16] = v117;
    v104[17] = v120;
    v104[18] = v121;
    v105 = 12 * v78 + 12;
    v104[19] = v122;
    v104[12] = v81;
    v104[13] = v76;
    v104[22] = v79;
    v104[23] = v80;
    v106 = 4 * v105 - 48;
    v96 = a4 + 96;
    v104[20] = v123;
    v104[21] = v77;
    v107 = (int *)(a4 + 4 * v105);
    v108 = (int *)(v106 + a4 + 96);
    v109 = 1264 * a7 + 48 * v78 + 12 + v95;
    do
    {
      v110 = *v107++;
      *(_DWORD *)(v109 + 4) = v110;
      v109 += 4;
    }
    while ( v108 != v107 );
  }
  else
  {
    v95 = dword_105314;
    v96 = a4 + 96;
  }
  v97 = v78 + 8 * a5;
  sub_11F74C(1, dword_10530C, v97, a5);
  v97 *= 3;
  v98 = (_DWORD *)(a4 + 16 * v97);
  v98[14] = v111;
  v98[15] = v114;
  v98[16] = v117;
  v98[17] = v120;
  v98[18] = v121;
  v98[19] = v122;
  v99 = 4 * v97 + 12;
  v98[12] = v81;
  v98[13] = v76;
  v98[20] = v123;
  v98[21] = v77;
  v98[22] = v79;
  v98[23] = v80;
  v100 = v95 + 1264 * a7 + 16 * v97 + 12;
  v101 = v96 + 4 * v99 - 48;
  v102 = (int *)(a4 + 4 * v99);
  do
  {
    v103 = *v102++;
    *(_DWORD *)(v100 + 4) = v103;
    v100 += 4;
  }
  while ( (int *)v101 != v102 );
  return sub_11F74C(1, dword_105310, v81, v76);
}

