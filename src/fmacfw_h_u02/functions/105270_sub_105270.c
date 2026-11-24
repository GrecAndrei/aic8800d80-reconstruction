#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))


extern uint32_t dword_105540;
extern uint32_t dword_105550;
extern float flt_105548;
extern float flt_10554C;
extern float flt_105810;
extern uint32_t off_105818;
extern uint32_t off_105824;
extern uint32_t off_1058C8;

// sub_105270 @ 0x105270, size 1618 bytes
int  sub_105270(
        int a1,
        int a2,
        int a3,
        int a4,
        uint8_t a5,
        char a6,
        uint8_t a7,
        int a8,
        int a9)
{
  float *v11; // r4
  int v12; // r9
  float *v13; // r5
  float v14; // s15
  float v15; // s16
  uint64_t v16; // r6
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r0
  float v20; // s17
  float *v21; // r10
  float *v22; // r9
  int v23; // r5
  float *v24; // r4
  uint64_t v25; // r6
  uint64_t v26; // r0
  uint64_t v27; // r0
  float v28; // s13
  int v29; // r5
  float *v30; // r2
  float *v31; // r3
  float v32; // s15
  float v33; // s10
  float v34; // s11
  float v35; // s12
  float v36; // s18
  float *v37; // r7
  float *v38; // r6
  float v39; // s15
  float v40; // s16
  float *v41; // r9
  float v42; // s19
  float v43; // s17
  uint64_t v44; // r0
  float v45; // s17
  float v46; // s19
  int v47; // r5
  int v48; // r10
  int v49; // r11
  float *v50; // r7
  float v51; // s18
  float v52; // s16
  uint64_t v53; // r0
  float v54; // s15
  int v55; // zf
  float v56; // r9
  float v57; // s16
  float *v58; // r5
  int *v59; // r6
  float *v60; // r8
  int *v61; // r7
  int v62; // r9
  float v63; // s13
  float v64; // s15
  float v65; // s14
  int v66; // r2
  int v67; // s13
  int v68; // s15
  int v69; // r11
  int v70; // r7
  int v71; // r5
  int v72; // r8
  int v73; // r10
  int v74; // r9
  int *v75; // r6
  int v76; // r3
  int v77; // r4
  int v78; // r5
  int v79; // r9
  int *v80; // r7
  int v81; // r6
  int v82; // r11
  int *v83; // r0
  int *v84; // r12
  int v85; // t1
  int *v87; // r6
  int v88; // r4
  int v89; // r5
  uint32_t *v90; // r1
  int v91; // r2
  int *v92; // r6
  int v93; // r1
  int *v94; // r4
  int v95; // t1
  uint32_t *v96; // r12
  int v97; // r2
  int v98; // r0
  int *v99; // r2
  int *v100; // r0
  int *v101; // r1
  int v102; // t1
  int v103; // [sp+2Ch] [bp-180h]
  int v104; // [sp+30h] [bp-17Ch]
  int v105; // [sp+30h] [bp-17Ch]
  int v106; // [sp+30h] [bp-17Ch]
  float *v107; // [sp+34h] [bp-178h]
  float *v108; // [sp+34h] [bp-178h]
  unsigned int v109; // [sp+34h] [bp-178h]
  int a4a; // [sp+38h] [bp-174h]
  int a4b; // [sp+38h] [bp-174h]
  int a4c; // [sp+38h] [bp-174h]
  int v113; // [sp+3Ch] [bp-170h]
  int v114; // [sp+40h] [bp-16Ch]
  int v115; // [sp+44h] [bp-168h]
  int v116; // [sp+48h] [bp-164h]
  int a3a; // [sp+5Ch] [bp-150h] BYREF
  unsigned int v119; // [sp+60h] [bp-14Ch]
  int v120; // [sp+64h] [bp-148h]
  float v121[16]; // [sp+68h] [bp-144h] BYREF
  float v122[16]; // [sp+A8h] [bp-104h] BYREF
  uint8_t v123[64]; // [sp+E8h] [bp-C4h] BYREF
  int v124; // [sp+128h] [bp-84h] BYREF
  int v125; // [sp+12Ch] [bp-80h]
  int v126; // [sp+130h] [bp-7Ch]
  int v127; // [sp+134h] [bp-78h]
  int v128; // [sp+138h] [bp-74h]
  int v129; // [sp+13Ch] [bp-70h]
  int v130; // [sp+140h] [bp-6Ch]
  int v131; // [sp+144h] [bp-68h]
  int v132; // [sp+148h] [bp-64h]
  int v133; // [sp+14Ch] [bp-60h]
  int v134; // [sp+150h] [bp-5Ch]
  int v135; // [sp+154h] [bp-58h]
  int v136; // [sp+158h] [bp-54h]
  int v137; // [sp+15Ch] [bp-50h]
  int v138; // [sp+160h] [bp-4Ch]
  int v139; // [sp+164h] [bp-48h]
  uint32_t v140[8]; // [sp+168h] [bp-44h] BYREF
  int v141; // [sp+188h] [bp-24h]
  int v142; // [sp+18Ch] [bp-20h]
  int v143; // [sp+190h] [bp-1Ch]
  int v144; // [sp+194h] [bp-18h]
  int v145; // [sp+198h] [bp-14h]
  int v146; // [sp+19Ch] [bp-10h]
  int v147; // [sp+1A0h] [bp-Ch]
  int v148; // [sp+1A4h] [bp-8h]
  uint8_t v149[4]; // [sp+1A8h] [bp-4h] BYREF

  v11 = (float *)a3;
  v104 = a9 - 1;
  if ( a2 > 1 )
  {
    v12 = a3 + 128 + 4 * a2;
    v13 = (float *)(a3 + 132);
    do
    {
      v14 = *v13++;
      v15 = *(v13 - 2);
      if ( v14 < v15 )
      {
        v16 = sub_1428B8(LODWORD(v14));
        v17 = sub_1428B8(LODWORD(v15));
        v18 = sub_142968(v17, *(uint64_t *)&dword_105550);
        if ( sub_142E4C(v16, v18) )
        {
          sub_12EB90(1, aWarningAmIsNot);
          v15 = *(v13 - 2);
        }
        *(v13 - 1) = v15;
      }
    }
    while ( (float *)v12 != v13 );
  }
  if ( a1 > 0 )
  {
    v19 = sub_142894(a1);
    v20 = flt_105548;
    a4a = (int)v11;
    v21 = v122;
    v22 = (float *)v123;
    v23 = 0;
    v24 = v121;
    v25 = v19;
    do
    {
      v26 = sub_142894(++v23);
      v27 = sub_142BBC(v26, v25);
      *(uint32_t *)v24++ = sub_142F2C(v27);
      *v21++ = 1.0;
      *v22++ = v20;
    }
    while ( v23 != a1 );
    v11 = (float *)a4a;
  }
  v28 = v121[v104];
  v29 = 0;
  a4b = a2 - 1;
  v120 = a2 - 1;
  sub_1051D0(a2, v28, &a3a, (int)v11, 0);
  v30 = &v11[v119];
  v31 = &v11[a3a];
  v32 = *v30;
  v33 = v30[32];
  v34 = v31[32] - v33;
  v35 = *v31 - *v30;
  v122[v104] = v28;
  v36 = (float)((float)((float)(v34 / v35) * (float)(v28 - v32)) + v33) / v28;
  if ( a1 <= 0 )
  {
    if ( a1 )
    {
      sub_12EB90(1, aIDpdOutDpdPmOu);
      goto LABEL_44;
    }
  }
  else
  {
    v37 = v122;
    v38 = v121;
    do
    {
      if ( v29 != v104 )
      {
        v40 = v36 * *v38;
        sub_1051D0(a2, v40, &a3a, (int)v11, 1);
        if ( a3a )
        {
          v41 = &v11[a3a];
          if ( a4b == v119
            || (v42 = v11[v119 + 32],
                v107 = &v11[v119],
                v43 = v41[32] - v42,
                v44 = sub_1428B8(LODWORD(v43)),
                sub_142E4C(v44, *(uint64_t *)&dword_105540)) )
          {
            v39 = 1.0;
          }
          else
          {
            v39 = (float)((float)((float)(*v41 - *v107) * (float)(v40 - v42)) / v43) + *v107;
          }
        }
        else
        {
          v39 = (float)(v40 * *v11) / v11[32];
        }
        *v37 = v39;
      }
      ++v29;
      ++v37;
      ++v38;
    }
    while ( a1 != v29 );
  }
  v45 = flt_105548;
  v105 = a1;
  v46 = flt_10554C;
  v47 = a9 - 1;
  v48 = -1;
  v49 = a9 - 1;
  while ( 1 )
  {
    v56 = v122[v47];
    sub_1051D0(a2, v56, &a3a, (int)v11, 0);
    if ( a3a )
    {
      v108 = &v11[v119];
      v50 = &v11[a3a];
      if ( a4b == v119 )
      {
        v54 = v11[a4b + 96];
      }
      else
      {
        v51 = *v108;
        v52 = *v50 - *v108;
        v53 = sub_1428B8(LODWORD(v52));
        if ( !sub_142E88(v53, *(uint64_t *)&dword_105540) )
          v52 = v46;
        v54 = (float)((float)((float)(v50[96] - v108[96]) / v52) * (float)(v56 - v51)) + v108[96];
      }
    }
    else
    {
      v54 = v11[v49 + 96];
    }
    v55 = v47 == v49;
    if ( v47 != v49 )
    {
      v54 = v45 - v54;
      *(float *)&v149[4 * v47 - 192] = v54;
    }
    v47 = v48 + 1;
    if ( v55 )
      v45 = v54;
    if ( v105 <= v47 )
      break;
    ++v48;
  }
  sub_12EB90(1, aIDpdOutDpdPmOu);
  if ( v105 > 0 )
  {
    v57 = flt_105810;
    v58 = v122;
    v59 = &v124;
    v60 = (float *)v123;
    v61 = v140;
    v62 = 0;
    do
    {
      v63 = *v60++;
      v64 = *v58++;
      v65 = v63 / v57;
      v66 = v62++;
      v67 = vcvts_n_s32_f32(v64, 0xAu);
      v68 = vcvts_n_s32_f32(v65, 9u);
      *v59++ = v67;
      if ( v67 >= 1024 )
        *(v59 - 1) = 1023;
      *v61++ = v68;
      if ( v68 < 0 )
        *(v61 - 1) = v68 + (v68 < 0 ? 0x400 : 0);
      sub_12EB90(1, a5d5d5d, v66);
    }
    while ( v105 != v62 );
  }
LABEL_44:
  v69 = (v127 << 10) + (v126 << 20) + v128;
  v103 = (v130 << 10) + (v129 << 20) + v131;
  v106 = (v133 << 10) + (v132 << 20) + v134;
  v109 = (v136 << 10) + (v135 << 20) + v137;
  v113 = v140[1] + 1049600 * v140[0];
  v114 = (v140[3] << 10) + (v140[2] << 20) + v140[4];
  v115 = (v140[6] << 10) + (v140[5] << 20) + v140[7];
  a4c = (v139 << 10) + (v138 << 20);
  v70 = (v142 << 10) + (v141 << 20) + v143;
  v71 = 15 - a8;
  v72 = (v145 << 10) + (v144 << 20) + v146;
  v73 = (v148 << 10) + (v147 << 20);
  v74 = v125 + (v124 << 10);
  if ( !a7 )
  {
    if ( a8 == 4 )
    {
      v71 = 1;
    }
    else if ( a8 == 7 )
    {
      v71 = 0;
    }
LABEL_48:
    v75 = &((uint32_t *)(uintptr_t)off_105818)[316 * a7 + 12 * v71];
    v116 = v71 + 24;
    v76 = v71;
    v77 = a4 + 96 + 48 * v71;
    v78 = v125 + (v124 << 10);
    v79 = (v142 << 10) + (v141 << 20) + v143;
    v80 = v75;
    v81 = (v127 << 10) + (v126 << 20) + v128;
    v82 = v76;
    do
    {
      sub_12EB90(1, aDpdUseDTable, v82);
      *(uint32_t *)(v77 - 40) = v103;
      *(uint32_t *)(v77 - 36) = v106;
      *(uint32_t *)(v77 - 32) = v109;
      *(uint32_t *)(v77 - 28) = a4c;
      *(uint32_t *)(v77 - 24) = v113;
      *(uint32_t *)(v77 - 20) = v114;
      *(uint32_t *)(v77 - 48) = v78;
      *(uint32_t *)(v77 - 44) = v81;
      *(uint32_t *)(v77 - 16) = v115;
      *(uint32_t *)(v77 - 12) = v79;
      *(uint32_t *)(v77 - 8) = v72;
      *(uint32_t *)(v77 - 4) = v73;
      v83 = (int *)(v77 - 48);
      v84 = v80;
      do
      {
        v85 = *v83++;
        v84[1] = v85;
        ++v84;
      }
      while ( (int *)v77 != v83 );
      v82 += 8;
      v80 += 96;
      v77 += 384;
    }
    while ( v116 != v82 );
    v70 = v79;
    v69 = v81;
    v74 = v78;
    return sub_12EB90(
             1,
             " am1=%x\n"
             " am2=%x\n"
             " am3=%x\n"
             " am4=%x\n"
             " am5=%x\n"
             " am6=%x\n"
             " pm1=%x\n"
             " pm2=%x\n"
             " pm3=%x\n"
             " pm4=%x\n"
             " pm5=%x\n"
             " pm6=%x\n",
             v74,
             v69,
             v103,
             v106,
             v109,
             a4c,
             v113,
             v114,
             v115,
             v70,
             v72,
             v73);
  }
  if ( a8 == 7 )
    v71 = 5;
  if ( !a6 )
    goto LABEL_48;
  if ( a5 == 2 )
  {
    v87 = (int *)off_1058C8;
    sub_12EB90(1, "dpd use %d table\n", v71);
    v96 = (uint32_t *)(a4 + 48 * v71);
    v96[14] = v103;
    v96[15] = v106;
    v96[16] = v109;
    v96[17] = a4c;
    v96[18] = v113;
    v97 = 12 * v71 + 12;
    v96[19] = v114;
    v96[12] = v74;
    v96[13] = v69;
    v96[22] = v72;
    v96[23] = v73;
    v98 = 4 * v97 - 48;
    v88 = a4 + 96;
    v96[20] = v115;
    v96[21] = v70;
    v99 = (int *)(a4 + 4 * v97);
    v100 = (int *)(v98 + a4 + 96);
    v101 = &v87[316 * a7 + 3 + 12 * v71];
    do
    {
      v102 = *v99++;
      v101[1] = v102;
      ++v101;
    }
    while ( v100 != v99 );
  }
  else
  {
    v87 = (int *)off_105824;
    v88 = a4 + 96;
  }
  v89 = v71 + 8 * a5;
  sub_12EB90(1, "dpd use %d table\n", v89);
  v89 *= 3;
  v90 = (uint32_t *)(a4 + 16 * v89);
  v90[14] = v103;
  v90[15] = v106;
  v90[16] = v109;
  v90[17] = a4c;
  v90[18] = v113;
  v90[19] = v114;
  v91 = 4 * v89 + 12;
  v90[12] = v74;
  v90[13] = v69;
  v90[20] = v115;
  v90[21] = v70;
  v90[22] = v72;
  v90[23] = v73;
  v92 = &v87[316 * a7 + 3 + 4 * v89];
  v93 = v88 + 4 * v91 - 48;
  v94 = (int *)(a4 + 4 * v91);
  do
  {
    v95 = *v94++;
    v92[1] = v95;
    ++v92;
  }
  while ( (int *)v93 != v94 );
  return sub_12EB90(
           1,
           " am1=%x\n"
           " am2=%x\n"
           " am3=%x\n"
           " am4=%x\n"
           " am5=%x\n"
           " am6=%x\n"
           " pm1=%x\n"
           " pm2=%x\n"
           " pm3=%x\n"
           " pm4=%x\n"
           " pm5=%x\n"
           " pm6=%x\n",
           v74,
           v69,
           v103,
           v106,
           v109,
           a4c,
           v113,
           v114,
           v115,
           v70,
           v72,
           v73);
}
