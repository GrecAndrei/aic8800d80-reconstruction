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


extern uint32_t dword_1021F8;
extern uint32_t dword_102200;
extern uint32_t dword_10221C;
extern uint32_t dword_10224C;
extern uint32_t dword_102250;
extern uint32_t dword_102254;
extern uint32_t dword_102258;
extern uint32_t dword_102264;
extern uint32_t dword_102268;
extern uint32_t dword_102270;
extern uint32_t dword_102278;
extern uint32_t dword_10227C;
extern uint32_t dword_10228C;
extern uint32_t dword_1024E8;
extern uint32_t dword_1024F0;
extern uint32_t dword_1024F4;
extern uint32_t dword_1024F8;
extern uint32_t dword_1024FC;
extern uint32_t dword_10285C;
extern uint32_t dword_102864;
extern uint32_t dword_102868;
extern uint32_t dword_10286C;
extern uint32_t dword_102874;
extern uint32_t dword_102878;
extern uint32_t dword_102880;
extern uint32_t dword_102888;
extern uint32_t dword_102890;
extern uint32_t dword_102894;
extern uint32_t dword_10289C;
extern uint32_t dword_1028A0;
extern uint32_t dword_1028A4;
extern uint32_t off_102210;
extern uint32_t off_102218;
extern uint32_t off_102220;
extern uint32_t off_102224;
extern uint32_t off_102228;
extern uint32_t off_10222C;
extern uint32_t off_102230;
extern uint32_t off_102234;
extern uint32_t off_102238;
extern uint32_t off_10223C;
extern uint32_t off_102240;
extern uint32_t off_102244;
extern uint32_t off_102248;
extern uint32_t off_10225C;
extern uint32_t off_102260;
extern uint32_t off_10226C;
extern uint32_t off_102274;
extern uint32_t off_102280;
extern uint32_t off_102284;
extern uint32_t off_102288;
extern uint32_t off_102290;
extern uint32_t off_102294;
extern uint32_t off_102500;
extern uint32_t off_102504;
extern uint32_t off_102508;
extern uint32_t off_102510;
extern uint32_t off_102514;
extern uint32_t off_102520;
extern uint32_t off_102524;
extern uint32_t off_102528;
extern uint32_t off_10252C;
extern uint32_t off_102530;
extern uint32_t off_102534;
extern uint32_t off_102538;
extern uint32_t off_10253C;
extern uint32_t off_102838;
extern uint32_t off_10283C;
extern uint32_t off_102840;
extern uint32_t off_10284C;
extern uint32_t off_102850;
extern uint32_t off_102854;
extern uint32_t off_102858;
extern uint32_t off_102860;
extern uint32_t off_102870;
extern uint32_t off_10287C;
extern uint32_t off_102884;
extern uint32_t off_10288C;
extern uint32_t off_102898;
extern uint32_t off_1028A8;
extern uint32_t off_1028AC;

// sub_101EC0 @ 0x101ec0, size 2412 bytes
void  sub_101EC0(
        unsigned int a1,
        unsigned int a2,
        unsigned int r2_0,
        unsigned int a4,
        uint8_t a5,
        uint8_t a6)
{
  int v11; // r0
  uint16_t v12; // r6
  uint64_t v13; // r0
  uint64_t v14; // r0
  unsigned int v15; // r0
  uint64_t v16; // r0
  unsigned int *v17; // r7
  uint64_t v18; // r0
  uint32_t *v19; // r2
  uint32_t *v20; // r2
  int v21; // r1
  uint8_t *v22; // r6
  unsigned int v23; // r3
  int v24; // r6
  uint64_t v25; // r8
  uint64_t v26; // r10
  uint64_t v27; // r0
  uint64_t v28; // r2
  uint64_t v29; // r6
  uint64_t v30; // r0
  uint64_t v31; // r0
  uint64_t v32; // r2
  uint64_t v33; // r0
  uint64_t v34; // r0
  unsigned int v35; // r0
  uint64_t v36; // r2
  uint64_t v37; // r0
  uint64_t v38; // r8
  uint64_t v39; // r0
  uint64_t v40; // r2
  uint64_t v41; // r0
  uint64_t v42; // r2
  uint64_t v43; // r0
  uint64_t v44; // r0
  uint64_t v45; // r2
  uint64_t v46; // r10
  unsigned int *v47; // r5
  unsigned int v48; // r0
  uint32_t *v49; // r2
  uint64_t v50; // r0
  unsigned int *v51; // r5
  uint64_t v52; // r0
  uint64_t v53; // r0
  int v54; // r9
  uint64_t v55; // r6
  uint64_t v56; // r2
  uint64_t v57; // r2
  int v58; // r5
  uint64_t v59; // r0
  uint64_t v60; // r2
  uint64_t v61; // r0
  uint64_t v62; // r0
  int v63; // r0
  int v64; // r1
  uint32_t *v65; // r5
  unsigned int *v66; // r2
  unsigned int *v67; // r8
  uint64_t v68; // r0
  uint64_t v69; // r6
  uint64_t v70; // r0
  uint64_t v71; // r6
  uint64_t v72; // r0
  unsigned int *v73; // r9
  uint64_t v74; // r0
  uint64_t v75; // r2
  uint64_t v76; // r0
  uint64_t v77; // r2
  uint64_t v78; // r0
  uint64_t v79; // r0
  uint64_t v80; // r2
  unsigned int v81; // r8
  uint64_t v82; // r0
  uint64_t v83; // r0
  uint64_t v84; // r0
  uint64_t v85; // r2
  uint64_t v86; // r0
  int v87; // r2
  int v88; // r8
  int v89; // r0
  int v90; // lr
  int v91; // r12
  int v92; // r6
  unsigned int *v93; // r1
  uint32_t *v94; // r7
  unsigned int *v95; // r5
  volatile unsigned int v96; // r1
  unsigned int v97; // r1
  int v98; // r3
  uint32_t *v99; // r2
  int v100; // r9
  uint8_t *v101; // r6
  uint32_t *v102; // r2
  uint32_t *v103; // r6
  uint32_t *v104; // r5
  uint32_t *v105; // r0
  uint32_t *v106; // r1
  uint32_t *v107; // r6
  uint32_t *v108; // r5
  int v109; // r3
  uint32_t *v110; // r6
  uint32_t *v111; // r5
  uint32_t *v112; // r6
  uint16_t *v113; // r12
  int v114; // r1
  int v115; // r2
  int v116; // r1
  int v117; // r2
  int v118; // r3
  int v119; // r1
  int v120; // r2
  int v121; // r3
  int v122; // r0
  int v123; // r1
  int v124; // r2
  int v125; // r3
  unsigned int v126; // r11
  int v127; // r1
  uint64_t v128; // r8
  uint64_t v129; // r0
  uint64_t v130; // r2
  unsigned int *v131; // r7
  uint64_t v132; // r10
  uint64_t v133; // r0
  uint64_t v134; // r0
  uint64_t v135; // r2
  uint64_t v136; // r0
  uint64_t v137; // r0
  unsigned int v138; // r0
  uint64_t v139; // r2
  unsigned int v140; // r6
  uint64_t v141; // r0
  uint64_t v142; // r8
  uint64_t v143; // r0
  uint64_t v144; // r2
  uint64_t v145; // r0
  uint64_t v146; // r0
  uint64_t v147; // r2
  unsigned int v148; // r0
  uint32_t *v149; // r2
  uint64_t v150; // r0
  unsigned int *v151; // r6
  uint64_t v152; // r0
  uint64_t v153; // r0
  uint64_t v154; // r2
  uint64_t v155; // r0
  unsigned int *v156; // r7
  uint64_t v157; // r0
  uint64_t v158; // r2
  uint64_t v159; // r0
  uint64_t v160; // r0
  uint64_t v161; // r0
  uint64_t v162; // r2
  uint64_t v163; // r0
  uint64_t v164; // r0
  int v165; // r9
  unsigned int v166; // [sp+20h] [bp-4Ch]
  uint8_t *v167; // [sp+24h] [bp-48h]
  uint32_t v168[16]; // [sp+2Ch] [bp-40h] BYREF

  sub_12E948("\x9D\x87%s: band=%d freq=%d freq1=%d chantype=%d sx=%d\n", aPhyHwSetChanne, a1, a2, r2_0, a4, a6);
  if ( **(uint8_t **)off_102210 != 3 )
    sub_12EB90(4, "setch:%d\r\n", r2_0);
  sub_100670(a4);
  sub_100BE0(a1, a2, r2_0, a4, a5);
  v11 = sub_1006CC();
  v12 = v11;
  if ( v11 == 240 )
  {
    if ( a4 <= 1 )
      HIDWORD(v155) = dword_102894;
    else
      HIDWORD(v155) = dword_102890;
    v156 = (unsigned int *)off_102898;
    LODWORD(v155) = 0;
    v157 = sub_1424DC(v155);
    *v156 = *v156 & 0xC00FFFFF | dword_10289C & (sub_142EEC(v157) << 20);
  }
  else
  {
    v13 = sub_142894(v11);
    if ( a4 > 1 )
      v14 = sub_142968(v13, *(uint64_t *)&dword_1024E8);
    else
      v14 = sub_142968(v13, *(uint64_t *)&dword_1021F8);
    v15 = sub_142F2C(v14);
    v16 = sub_1428B8(v15);
    v17 = (unsigned int *)off_102218;
    v18 = sub_1424DC(v16);
    *v17 = *v17 & 0xF003FFFF | dword_10221C & (sub_142EEC(v18) << 18);
  }
  if ( a1 )
    v19 = off_10288C;
  else
    v19 = off_102220;
  *(uint32_t *)off_102224 = (uint16_t)*(uint32_t *)off_102224
                        | (((*v19 >> 8) - (uint16_t)(((*(uint32_t *)off_102218 >> 18) & 0x3FF) + v12)) << 16);
  v20 = off_10222C;
  *(uint32_t *)off_102228 = *(uint32_t *)off_102228 & 0xFFFE1FFF | 0xE000;
  v21 = *((uint8_t *)off_102230 + 36);
  *v20 &= ~4u;
  if ( v21 != a1 )
    sub_103180(a1);
  if ( **(uint16_t **)off_102234 < 0 && a1 > 1 )
  {
    sub_12F32C((int)aBandPhyBandMax, (int)aPhyHwSetChanne_0, 5664);
    goto LABEL_42;
  }
  if ( a1 )
  {
LABEL_42:
    v167 = off_102520;
    v101 = off_102520;
    sub_101260(r2_0);
    if ( v101[1] )
      sub_10076C();
    if ( a4 )
    {
      if ( a4 == 1 )
        *(uint32_t *)off_1028A8 = *(uint32_t *)off_1028A8 & 0xFFFFFFC7 | 0x18;
      else
        *(uint32_t *)off_102524 = *(uint32_t *)off_102524 & 0xFFFFFFC7 | 0x20;
    }
    else
    {
      *(uint32_t *)off_1028A8 = *(uint32_t *)off_1028A8 & 0xFFFFFFC7 | 0x10;
    }
    goto LABEL_18;
  }
  v167 = off_102238;
  v22 = off_102238;
  sub_100FAC(r2_0, a4);
  if ( v22[1] )
    sub_100730();
  if ( a4 )
  {
    if ( a4 == 1 )
      *(uint32_t *)off_10223C = *(uint32_t *)off_10223C & 0xFFFFFFC7 | 8;
  }
  else
  {
    *(uint32_t *)off_1028A8 &= 0xFFFFFFC7;
  }
LABEL_18:
  v23 = (*(uint32_t *)off_102240 >> 5) & 0x1F;
  if ( (*(uint32_t *)off_102240 & 0x400) != 0 )
    v23 *= 2;
  if ( (*(uint32_t *)off_102244 & 0x80000) != 0 && (*(uint32_t *)off_102244 & 0x40000) != 0 )
    v23 >>= 1;
  v24 = *(uint8_t *)off_102248 * v23;
  if ( !a1 )
  {
    v25 = sub_142894(r2_0);
    v26 = sub_142894(v24);
    v27 = sub_1425FC(v25, v25);
    HIDWORD(v28) = dword_10224C;
    v29 = v27;
    LODWORD(v28) = 0;
    v30 = sub_142968(v26, v28);
    v31 = sub_142BBC(v29, v30);
    HIDWORD(v32) = dword_102250;
    LODWORD(v32) = 0;
    v33 = sub_142968(v31, v32);
    v34 = sub_1424DC(v33);
    v35 = sub_142EEC(v34);
    HIDWORD(v36) = dword_10224C;
    LODWORD(v36) = 0;
    LODWORD(v29) = v35;
    v37 = sub_142BBC(v25, v36);
    v38 = sub_1424DC(v37);
    v39 = sub_142874(v29);
    HIDWORD(v40) = dword_10224C;
    LODWORD(v40) = 0;
    v41 = sub_142968(v39, v40);
    HIDWORD(v42) = dword_102254;
    LODWORD(v42) = 0;
    v43 = sub_142968(v41, v42);
    v44 = sub_142968(v43, v26);
    LODWORD(v45) = 0;
    HIDWORD(v45) = dword_102258;
    v46 = sub_142968(v44, v45);
    sub_101E7C(0);
    v47 = (unsigned int *)off_102260;
    *(uint32_t *)off_10225C = v29 & 0x7FFFFFFF;
    v48 = sub_142EEC(v38);
    v49 = off_10226C;
    *v47 = dword_102268 & *v47 | dword_102264 & (v48 << 13);
    *v49 |= 1u;
LABEL_25:
    HIDWORD(v50) = dword_102270;
    v51 = (unsigned int *)off_102274;
    LODWORD(v50) = 0;
    v52 = sub_142BBC(v50, v46);
    v53 = sub_1424DC(v52);
    *v51 = sub_142E9C(v53) & 0xFFFFFFF | *v51 & 0xF0000000;
    v54 = 0;
    v55 = sub_142BBC(v46, *(uint64_t *)&dword_102200);
    goto LABEL_26;
  }
  v128 = sub_142894(r2_0);
  v129 = sub_142894(v24);
  HIDWORD(v130) = dword_10285C;
  v131 = (unsigned int *)off_102860;
  LODWORD(v130) = 0;
  v132 = v129;
  v133 = sub_142968(v129, v130);
  v134 = sub_142BBC(v128, v133);
  HIDWORD(v135) = dword_102864;
  LODWORD(v135) = 0;
  v136 = sub_142968(v134, v135);
  v137 = sub_1424DC(v136);
  v138 = sub_142EEC(v137);
  HIDWORD(v139) = dword_102868;
  LODWORD(v139) = 0;
  v140 = v138;
  v141 = sub_142BBC(v128, v139);
  v142 = sub_1424DC(v141);
  v143 = sub_142874(v140);
  HIDWORD(v144) = dword_10285C;
  LODWORD(v144) = 0;
  v145 = sub_142968(v143, v144);
  v146 = sub_142968(v145, v132);
  LODWORD(v147) = 0;
  HIDWORD(v147) = dword_10286C;
  v46 = sub_142968(v146, v147);
  sub_101E7C(0);
  *(uint32_t *)off_102870 = v140 & 0x7FFFFFFF;
  v148 = sub_142EEC(v142);
  v149 = off_10287C;
  *v131 = dword_102878 & *v131 | dword_102874 & (v148 << 13);
  *v149 |= 1u;
  if ( a1 != 1 )
    goto LABEL_25;
  HIDWORD(v150) = dword_102880;
  v151 = (unsigned int *)off_102884;
  LODWORD(v150) = 0;
  v152 = sub_142BBC(v150, v46);
  v153 = sub_1424DC(v152);
  *v151 = *v151 & 0xF0000000 | sub_142E9C(v153) & 0xFFFFFFF;
  LODWORD(v154) = 0;
  HIDWORD(v154) = dword_102888;
  v54 = 1;
  v55 = sub_142BBC(v46, v154);
LABEL_26:
  HIDWORD(v56) = dword_102278;
  LODWORD(v56) = 0;
  if ( sub_142E74(v55, v56) )
  {
    v161 = sub_142968(v55, 0x4180000000000000uLL);
    HIDWORD(v162) = dword_1028A4;
    LODWORD(v162) = 0;
    v163 = sub_142BBC(v161, v162);
    v164 = sub_1424DC(v163);
    v63 = sub_142E9C(v164);
    v64 = 0x20000000;
  }
  else
  {
    HIDWORD(v57) = dword_10227C;
    LODWORD(v57) = 0;
    v58 = sub_142E74(v55, v57);
    v59 = sub_142968(v55, 0x4180000000000000uLL);
    if ( v58 )
    {
      HIDWORD(v60) = dword_10227C;
      LODWORD(v60) = 0;
      v61 = sub_142BBC(v59, v60);
      v62 = sub_1424DC(v61);
      v63 = sub_142E9C(v62);
      v64 = 0x10000000;
    }
    else
    {
      HIDWORD(v158) = dword_1028A0;
      LODWORD(v158) = 0;
      v159 = sub_142BBC(v59, v158);
      v160 = sub_1424DC(v159);
      v63 = sub_142E9C(v160);
      v64 = 0;
    }
  }
  v65 = off_102284;
  v66 = (unsigned int *)off_102288;
  v67 = (unsigned int *)off_102290;
  *(uint32_t *)off_102280 = v63 & 0xFFFFFFF;
  *v65 = *v65 & 0xFFFFFFF | v64;
  *v66 = *v66 & 0xFFFFFFFC | v54;
  v68 = sub_142894(a2);
  v69 = sub_1425FC(v68, v46);
  v70 = sub_142894(r2_0);
  v71 = sub_1425F8(v69, v70);
  HIDWORD(v72) = dword_10228C;
  v73 = (unsigned int *)off_102294;
  LODWORD(v72) = 0;
  v74 = sub_142BBC(v72, v46);
  LODWORD(v75) = 0;
  HIDWORD(v75) = dword_102254;
  v76 = sub_1425FC(v74, v75);
  v166 = *v67;
  *v67 = v166 & 0xFFFF8000 | sub_142EEC(v76) & 0x7FFF;
  LODWORD(v77) = 0;
  HIDWORD(v77) = dword_1024F0;
  v78 = sub_142968(v46, v77);
  v79 = sub_142BBC(v78, v71);
  HIDWORD(v80) = dword_1024F4;
  v81 = *v73;
  LODWORD(v80) = 0;
  v82 = sub_1425FC(v79, v80);
  *v73 = (uint16_t)sub_142EEC(v82) | (HIWORD(v81) << 16);
  HIDWORD(v83) = dword_1024F8;
  LODWORD(v83) = 0;
  v84 = sub_142BBC(v83, v71);
  HIDWORD(v85) = dword_1024F4;
  LODWORD(v85) = 0;
  v86 = sub_1425FC(v84, v85);
  *v73 = *v73 & 0x8000FFFF | dword_1024FC & (sub_142EEC(v86) << 16);
  *v65 = a4 & 0xF | *v65 & 0xFFFFFFF0;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      v88 = 0;
      v92 = 0;
      v87 = 16;
      v89 = 0x100000;
      v90 = 402653184;
      v91 = 11;
    }
    else
    {
      v87 = 32;
      v88 = 0x80000;
      v89 = 3145728;
      v90 = 402653184;
      v91 = 13;
      v92 = 256;
    }
  }
  else
  {
    v87 = 0;
    v88 = 0;
    v92 = 0;
    v89 = 0x100000;
    v90 = 419430400;
    v91 = 10;
  }
  v93 = (unsigned int *)off_102500;
  v94 = off_102504;
  v95 = (unsigned int *)off_102508;
  *(uint32_t *)off_102500 = *(uint32_t *)off_102500 & 0xFFFFFFCF | v87;
  *v93 = *v93 & 0xFFF3FFFF | v88;
  *v93 = *v93 & 0xFFCFFFFF | v89;
  *v94 = *v94 & 0xFFFFFF | v90;
  *v94 = *v94 & 0xFFFFFF00 | v91;
  *v95 = *v95 & 0xFFFFFEFF | v92;
  v96 = (*(volatile uint32_t *)0x40501010u);
  v97 = v96 + 2;
  do
    v98 = v97 - (*(volatile uint32_t *)0x40501010u);
  while ( v98 >= 0 );
  v99 = off_102514;
  *(uint32_t *)off_102510 = 4;
  *v99 |= 4u;
  if ( r2_0 > 0x1666 )
  {
    v100 = 7600;
    v46 = 0x600002230LL;
  }
  else if ( r2_0 > 0x1616 )
  {
    v100 = 6336;
    v46 = 0x500001D40LL;
  }
  else if ( r2_0 > 0x15C6 )
  {
    v100 = 5072;
    v46 = 0x400001850LL;
  }
  else if ( r2_0 > 0x1571 )
  {
    v100 = 3808;
    v46 = 0x300001360LL;
  }
  else if ( r2_0 <= 0x1486 )
  {
    if ( r2_0 <= 0x143B )
      v165 = 0;
    else
      v165 = 1264;
    LODWORD(v46) = v165 + 1168;
    if ( r2_0 > 0x143B )
      HIDWORD(v46) = 1;
    v100 = v165 + 16;
    if ( r2_0 <= 0x143B )
      HIDWORD(v46) = 0;
  }
  else
  {
    v100 = 2544;
    v46 = 0x200000E70LL;
  }
  if ( sub_12CD48(7u) == 1 || sub_12CD48(6u) == 3 )
  {
    v102 = off_10252C;
    v103 = off_102530;
    v104 = off_102534;
    v105 = off_102538;
    v106 = off_10253C;
    *(uint32_t *)off_10252C |= 0x20000u;
    *v103 += 200000;
    *v104 += 200000;
    *v105 += 200000;
    *v106 += 200000;
    v107 = v103 + 8234;
    v108 = v104 + 8234;
    *(v102 - 194) += 200000;
    sub_12E948("process rx1: %x %x\n", *v107, *v108);
    if ( *v108 == *v107 )
    {
LABEL_60:
      v110 = off_10283C;
      v111 = off_102840;
      sub_12E948("process rx2: %x, %x\n", *(uint32_t *)off_10283C, *(uint32_t *)off_102840);
      while ( *v111 != *v110 )
        ;
      v112 = off_10284C;
      sub_12E948(aProcessRxEnd, v111);
      v113 = (uint16_t *)off_1028AC;
      v114 = ((uint32_t *)(uintptr_t)off_102850)[1];
      v115 = ((uint32_t *)(uintptr_t)off_102850)[2];
      v168[0] = ((uint32_t *)(uintptr_t)off_102850)[0];
      v168[1] = v114;
      v168[2] = v115;
      v116 = ((uint32_t *)(uintptr_t)off_102850)[5];
      v117 = ((uint32_t *)(uintptr_t)off_102850)[6];
      v118 = ((uint32_t *)(uintptr_t)off_102850)[7];
      v168[3] = ((uint32_t *)(uintptr_t)off_102850)[4];
      v168[4] = v116;
      v168[5] = v117;
      v168[6] = v118;
      v119 = ((uint32_t *)(uintptr_t)off_102850)[9];
      v120 = ((uint32_t *)(uintptr_t)off_102850)[10];
      v121 = ((uint32_t *)(uintptr_t)off_102850)[11];
      v168[7] = ((uint32_t *)(uintptr_t)off_102850)[8];
      v168[8] = v119;
      v168[9] = v120;
      v168[10] = v121;
      v122 = ((uint32_t *)(uintptr_t)off_102850)[12];
      v123 = ((uint32_t *)(uintptr_t)off_102850)[13];
      v124 = ((uint32_t *)(uintptr_t)off_102850)[14];
      v125 = ((uint32_t *)(uintptr_t)off_102850)[15];
      v126 = off_1028AC + 8 * HIDWORD(v46);
      *(uint8_t *)(v126 + 4) = 1;
      v168[11] = v122;
      v168[12] = v123;
      v168[13] = v124;
      v168[14] = v125;
      v127 = off_102854;
      *v112 |= 0x8000u;
      *v112 |= 0x2000u;
      sub_10B2F0((int)v168, v127, 0, 0, v113, 6, 1);
      *v112 &= ~0x8000u;
      *v112 &= ~0x2000u;
      *(uint8_t *)(v126 + 4) = 0;
      if ( r2_0 <= 0x1387 )
      {
        sub_1009A0(0, r2_0);
        if ( v167[13] )
          v167[15] |= 1u;
      }
      else
      {
        sub_1009A0(1, r2_0);
      }
      *(uint32_t *)off_102858 &= ~0x20000u;
      goto LABEL_52;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        sub_11D930(1);
        v109 = **(uint8_t **)off_102838;
        if ( v109 != 1 )
          break;
        sub_110B20();
LABEL_55:
        if ( *v108 == *v107 )
          goto LABEL_60;
      }
      if ( v109 != 2 && v109 != 4 )
        goto LABEL_55;
      sub_113F18();
      if ( *v108 == *v107 )
        goto LABEL_60;
    }
  }
LABEL_52:
  sub_1009DC((int)off_102528 + v100, (int)off_102528 + v46);
}
