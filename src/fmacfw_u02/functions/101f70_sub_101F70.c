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


extern uint32_t dword_1022A8;
extern uint32_t dword_1022B0;
extern uint32_t dword_1022CC;
extern uint32_t dword_1022FC;
extern uint32_t dword_102300;
extern uint32_t dword_102304;
extern uint32_t dword_102308;
extern uint32_t dword_102314;
extern uint32_t dword_102318;
extern uint32_t dword_102320;
extern uint32_t dword_102328;
extern uint32_t dword_10232C;
extern uint32_t dword_10233C;
extern uint32_t dword_102598;
extern uint32_t dword_1025A0;
extern uint32_t dword_1025A4;
extern uint32_t dword_1025A8;
extern uint32_t dword_1025AC;
extern uint32_t dword_10290C;
extern uint32_t dword_102914;
extern uint32_t dword_102918;
extern uint32_t dword_10291C;
extern uint32_t dword_102924;
extern uint32_t dword_102928;
extern uint32_t dword_102930;
extern uint32_t dword_102938;
extern uint32_t dword_102940;
extern uint32_t dword_102944;
extern uint32_t dword_10294C;
extern uint32_t dword_102950;
extern uint32_t dword_102954;
extern uint32_t off_1022C0;
extern uint32_t off_1022C8;
extern uint32_t off_1022D0;
extern uint32_t off_1022D4;
extern uint32_t off_1022D8;
extern uint32_t off_1022DC;
extern uint32_t off_1022E0;
extern uint32_t off_1022E4;
extern uint32_t off_1022E8;
extern uint32_t off_1022EC;
extern uint32_t off_1022F0;
extern uint32_t off_1022F4;
extern uint32_t off_1022F8;
extern uint32_t off_10230C;
extern uint32_t off_102310;
extern uint32_t off_10231C;
extern uint32_t off_102324;
extern uint32_t off_102330;
extern uint32_t off_102334;
extern uint32_t off_102338;
extern uint32_t off_102340;
extern uint32_t off_102344;
extern uint32_t off_1025B0;
extern uint32_t off_1025B4;
extern uint32_t off_1025B8;
extern uint32_t off_1025C0;
extern uint32_t off_1025C4;
extern uint32_t off_1025D0;
extern uint32_t off_1025D4;
extern uint32_t off_1025D8;
extern uint32_t off_1025DC;
extern uint32_t off_1025E0;
extern uint32_t off_1025E4;
extern uint32_t off_1025E8;
extern uint32_t off_1025EC;
extern uint32_t off_1028E8;
extern uint32_t off_1028EC;
extern uint32_t off_1028F0;
extern uint32_t off_1028FC;
extern uint32_t off_102900;
extern uint32_t off_102904;
extern uint32_t off_102908;
extern uint32_t off_102910;
extern uint32_t off_102920;
extern uint32_t off_10292C;
extern uint32_t off_102934;
extern uint32_t off_10293C;
extern uint32_t off_102948;
extern uint32_t off_102958;
extern uint32_t off_10295C;

// sub_101F70 @ 0x101f70, size 2412 bytes
int  sub_101F70(
        unsigned int a1,
        int a2,
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
  uint32_t *v103; // r2
  uint32_t *v104; // r6
  uint32_t *v105; // r5
  uint32_t *v106; // r0
  uint32_t *v107; // r1
  uint32_t *v108; // r6
  uint32_t *v109; // r5
  int v110; // r3
  uint32_t *v111; // r6
  uint32_t *v112; // r5
  uint32_t *v113; // r6
  uint16_t *v114; // r12
  int v115; // r1
  int v116; // r2
  int v117; // r1
  int v118; // r2
  int v119; // r3
  int v120; // r1
  int v121; // r2
  int v122; // r3
  int v123; // r0
  int v124; // r1
  int v125; // r2
  int v126; // r3
  unsigned int v127; // r11
  int v128; // r1
  uint64_t v129; // r8
  uint64_t v130; // r0
  uint64_t v131; // r2
  unsigned int *v132; // r7
  uint64_t v133; // r10
  uint64_t v134; // r0
  uint64_t v135; // r0
  uint64_t v136; // r2
  uint64_t v137; // r0
  uint64_t v138; // r0
  unsigned int v139; // r0
  uint64_t v140; // r2
  unsigned int v141; // r6
  uint64_t v142; // r0
  uint64_t v143; // r8
  uint64_t v144; // r0
  uint64_t v145; // r2
  uint64_t v146; // r0
  uint64_t v147; // r0
  uint64_t v148; // r2
  unsigned int v149; // r0
  uint32_t *v150; // r2
  uint64_t v151; // r0
  unsigned int *v152; // r6
  uint64_t v153; // r0
  uint64_t v154; // r0
  uint64_t v155; // r2
  uint64_t v156; // r0
  unsigned int *v157; // r7
  uint64_t v158; // r0
  uint64_t v159; // r2
  uint64_t v160; // r0
  uint64_t v161; // r0
  uint64_t v162; // r0
  uint64_t v163; // r2
  uint64_t v164; // r0
  uint64_t v165; // r0
  int v166; // r9
  unsigned int v167; // [sp+20h] [bp-4Ch]
  uint8_t *v168; // [sp+24h] [bp-48h]
  uint32_t v169[16]; // [sp+2Ch] [bp-40h] BYREF

  sub_12EA88("\x9D\x87%s: band=%d freq=%d freq1=%d chantype=%d sx=%d\n", aPhyHwSetChanne, a1, a2, r2_0, a4, a6);
  if ( **(uint8_t **)off_1022C0 != 3 )
    sub_12ECD0(4, "setch:%d\r\n", r2_0);
  sub_100670(a4);
  sub_100BE0(a1, a2, r2_0, a4, a5);
  v11 = sub_1006CC();
  v12 = v11;
  if ( v11 == 240 )
  {
    if ( a4 <= 1 )
      HIDWORD(v156) = dword_102944;
    else
      HIDWORD(v156) = dword_102940;
    v157 = (unsigned int *)off_102948;
    LODWORD(v156) = 0;
    v158 = sub_14261C(v156);
    *v157 = *v157 & 0xC00FFFFF | dword_10294C & (sub_14302C(v158) << 20);
  }
  else
  {
    v13 = sub_1429D4(v11);
    if ( a4 > 1 )
      v14 = sub_142AA8(v13, *(uint64_t *)&dword_102598);
    else
      v14 = sub_142AA8(v13, *(uint64_t *)&dword_1022A8);
    v15 = sub_14306C(v14);
    v16 = sub_1429F8(v15);
    v17 = (unsigned int *)off_1022C8;
    v18 = sub_14261C(v16);
    *v17 = *v17 & 0xF003FFFF | dword_1022CC & (sub_14302C(v18) << 18);
  }
  if ( a1 )
    v19 = off_10293C;
  else
    v19 = off_1022D0;
  *(uint32_t *)off_1022D4 = (uint16_t)*(uint32_t *)off_1022D4
                        | (((*v19 >> 8) - (uint16_t)(((*(uint32_t *)off_1022C8 >> 18) & 0x3FF) + v12)) << 16);
  v20 = off_1022DC;
  *(uint32_t *)off_1022D8 = *(uint32_t *)off_1022D8 & 0xFFFE1FFF | 0xE000;
  v21 = *((uint8_t *)off_1022E0 + 36);
  *v20 &= ~4u;
  if ( v21 != a1 )
    sub_103200(a1);
  if ( **(uint16_t **)off_1022E4 < 0 && a1 > 1 )
  {
    sub_12F46C((int)aBandPhyBandMax, (int)aPhyHwSetChanne_0, 5664);
    goto LABEL_42;
  }
  if ( a1 )
  {
LABEL_42:
    v168 = off_1025D0;
    v101 = off_1025D0;
    sub_101260(r2_0);
    if ( v101[1] )
      sub_10076C();
    if ( a4 )
    {
      if ( a4 == 1 )
        *(uint32_t *)off_102958 = *(uint32_t *)off_102958 & 0xFFFFFFC7 | 0x18;
      else
        *(uint32_t *)off_1025D4 = *(uint32_t *)off_1025D4 & 0xFFFFFFC7 | 0x20;
    }
    else
    {
      *(uint32_t *)off_102958 = *(uint32_t *)off_102958 & 0xFFFFFFC7 | 0x10;
    }
    goto LABEL_18;
  }
  v168 = off_1022E8;
  v22 = off_1022E8;
  sub_100FA8(r2_0, a4);
  if ( v22[1] )
    sub_100730();
  if ( a4 )
  {
    if ( a4 == 1 )
      *(uint32_t *)off_1022EC = *(uint32_t *)off_1022EC & 0xFFFFFFC7 | 8;
  }
  else
  {
    *(uint32_t *)off_102958 &= 0xFFFFFFC7;
  }
LABEL_18:
  v23 = (*(uint32_t *)off_1022F0 >> 5) & 0x1F;
  if ( (*(uint32_t *)off_1022F0 & 0x400) != 0 )
    v23 *= 2;
  if ( (*(uint32_t *)off_1022F4 & 0x80000) != 0 && (*(uint32_t *)off_1022F4 & 0x40000) != 0 )
    v23 >>= 1;
  v24 = *(uint8_t *)off_1022F8 * v23;
  if ( !a1 )
  {
    v25 = sub_1429D4(r2_0);
    v26 = sub_1429D4(v24);
    v27 = sub_14273C(v25, v25);
    HIDWORD(v28) = dword_1022FC;
    v29 = v27;
    LODWORD(v28) = 0;
    v30 = sub_142AA8(v26, v28);
    v31 = sub_142CFC(v29, v30);
    HIDWORD(v32) = dword_102300;
    LODWORD(v32) = 0;
    v33 = sub_142AA8(v31, v32);
    v34 = sub_14261C(v33);
    v35 = sub_14302C(v34);
    HIDWORD(v36) = dword_1022FC;
    LODWORD(v36) = 0;
    LODWORD(v29) = v35;
    v37 = sub_142CFC(v25, v36);
    v38 = sub_14261C(v37);
    v39 = sub_1429B4(v29);
    HIDWORD(v40) = dword_1022FC;
    LODWORD(v40) = 0;
    v41 = sub_142AA8(v39, v40);
    HIDWORD(v42) = dword_102304;
    LODWORD(v42) = 0;
    v43 = sub_142AA8(v41, v42);
    v44 = sub_142AA8(v43, v26);
    LODWORD(v45) = 0;
    HIDWORD(v45) = dword_102308;
    v46 = sub_142AA8(v44, v45);
    sub_101F28(0);
    v47 = (unsigned int *)off_102310;
    *(uint32_t *)off_10230C = v29 & 0x7FFFFFFF;
    v48 = sub_14302C(v38);
    v49 = off_10231C;
    *v47 = dword_102318 & *v47 | dword_102314 & (v48 << 13);
    *v49 |= 1u;
LABEL_25:
    HIDWORD(v50) = dword_102320;
    v51 = (unsigned int *)off_102324;
    LODWORD(v50) = 0;
    v52 = sub_142CFC(v50, v46);
    v53 = sub_14261C(v52);
    *v51 = sub_142FDC(v53) & 0xFFFFFFF | *v51 & 0xF0000000;
    v54 = 0;
    v55 = sub_142CFC(v46, *(uint64_t *)&dword_1022B0);
    goto LABEL_26;
  }
  v129 = sub_1429D4(r2_0);
  v130 = sub_1429D4(v24);
  HIDWORD(v131) = dword_10290C;
  v132 = (unsigned int *)off_102910;
  LODWORD(v131) = 0;
  v133 = v130;
  v134 = sub_142AA8(v130, v131);
  v135 = sub_142CFC(v129, v134);
  HIDWORD(v136) = dword_102914;
  LODWORD(v136) = 0;
  v137 = sub_142AA8(v135, v136);
  v138 = sub_14261C(v137);
  v139 = sub_14302C(v138);
  HIDWORD(v140) = dword_102918;
  LODWORD(v140) = 0;
  v141 = v139;
  v142 = sub_142CFC(v129, v140);
  v143 = sub_14261C(v142);
  v144 = sub_1429B4(v141);
  HIDWORD(v145) = dword_10290C;
  LODWORD(v145) = 0;
  v146 = sub_142AA8(v144, v145);
  v147 = sub_142AA8(v146, v133);
  LODWORD(v148) = 0;
  HIDWORD(v148) = dword_10291C;
  v46 = sub_142AA8(v147, v148);
  sub_101F28(0);
  *(uint32_t *)off_102920 = v141 & 0x7FFFFFFF;
  v149 = sub_14302C(v143);
  v150 = off_10292C;
  *v132 = dword_102928 & *v132 | dword_102924 & (v149 << 13);
  *v150 |= 1u;
  if ( a1 != 1 )
    goto LABEL_25;
  HIDWORD(v151) = dword_102930;
  v152 = (unsigned int *)off_102934;
  LODWORD(v151) = 0;
  v153 = sub_142CFC(v151, v46);
  v154 = sub_14261C(v153);
  *v152 = *v152 & 0xF0000000 | sub_142FDC(v154) & 0xFFFFFFF;
  LODWORD(v155) = 0;
  HIDWORD(v155) = dword_102938;
  v54 = 1;
  v55 = sub_142CFC(v46, v155);
LABEL_26:
  HIDWORD(v56) = dword_102328;
  LODWORD(v56) = 0;
  if ( sub_142FB4(v55, v56) )
  {
    v162 = sub_142AA8(v55, 0x4180000000000000uLL);
    HIDWORD(v163) = dword_102954;
    LODWORD(v163) = 0;
    v164 = sub_142CFC(v162, v163);
    v165 = sub_14261C(v164);
    v63 = sub_142FDC(v165);
    v64 = 0x20000000;
  }
  else
  {
    HIDWORD(v57) = dword_10232C;
    LODWORD(v57) = 0;
    v58 = sub_142FB4(v55, v57);
    v59 = sub_142AA8(v55, 0x4180000000000000uLL);
    if ( v58 )
    {
      HIDWORD(v60) = dword_10232C;
      LODWORD(v60) = 0;
      v61 = sub_142CFC(v59, v60);
      v62 = sub_14261C(v61);
      v63 = sub_142FDC(v62);
      v64 = 0x10000000;
    }
    else
    {
      HIDWORD(v159) = dword_102950;
      LODWORD(v159) = 0;
      v160 = sub_142CFC(v59, v159);
      v161 = sub_14261C(v160);
      v63 = sub_142FDC(v161);
      v64 = 0;
    }
  }
  v65 = off_102334;
  v66 = (unsigned int *)off_102338;
  v67 = (unsigned int *)off_102340;
  *(uint32_t *)off_102330 = v63 & 0xFFFFFFF;
  *v65 = *v65 & 0xFFFFFFF | v64;
  *v66 = *v66 & 0xFFFFFFFC | v54;
  v68 = sub_1429D4(a2);
  v69 = sub_14273C(v68, v46);
  v70 = sub_1429D4(r2_0);
  v71 = sub_142738(v69, v70);
  HIDWORD(v72) = dword_10233C;
  v73 = (unsigned int *)off_102344;
  LODWORD(v72) = 0;
  v74 = sub_142CFC(v72, v46);
  LODWORD(v75) = 0;
  HIDWORD(v75) = dword_102304;
  v76 = sub_14273C(v74, v75);
  v167 = *v67;
  *v67 = v167 & 0xFFFF8000 | sub_14302C(v76) & 0x7FFF;
  LODWORD(v77) = 0;
  HIDWORD(v77) = dword_1025A0;
  v78 = sub_142AA8(v46, v77);
  v79 = sub_142CFC(v78, v71);
  HIDWORD(v80) = dword_1025A4;
  v81 = *v73;
  LODWORD(v80) = 0;
  v82 = sub_14273C(v79, v80);
  *v73 = (uint16_t)sub_14302C(v82) | (HIWORD(v81) << 16);
  HIDWORD(v83) = dword_1025A8;
  LODWORD(v83) = 0;
  v84 = sub_142CFC(v83, v71);
  HIDWORD(v85) = dword_1025A4;
  LODWORD(v85) = 0;
  v86 = sub_14273C(v84, v85);
  *v73 = *v73 & 0x8000FFFF | dword_1025AC & (sub_14302C(v86) << 16);
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
  v93 = (unsigned int *)off_1025B0;
  v94 = off_1025B4;
  v95 = (unsigned int *)off_1025B8;
  *(uint32_t *)off_1025B0 = *(uint32_t *)off_1025B0 & 0xFFFFFFCF | v87;
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
  v99 = off_1025C4;
  *(uint32_t *)off_1025C0 = 4;
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
      v166 = 0;
    else
      v166 = 1264;
    LODWORD(v46) = v166 + 1168;
    if ( r2_0 > 0x143B )
      HIDWORD(v46) = 1;
    v100 = v166 + 16;
    if ( r2_0 <= 0x143B )
      HIDWORD(v46) = 0;
  }
  else
  {
    v100 = 2544;
    v46 = 0x200000E70LL;
  }
  if ( sub_12CE88(7u) == 1 || sub_12CE88(6u) == 3 )
  {
    v103 = off_1025DC;
    v104 = off_1025E0;
    v105 = off_1025E4;
    v106 = off_1025E8;
    v107 = off_1025EC;
    *(uint32_t *)off_1025DC |= 0x20000u;
    *v104 += 200000;
    *v105 += 200000;
    *v106 += 200000;
    *v107 += 200000;
    v108 = v104 + 8234;
    v109 = v105 + 8234;
    *(v103 - 194) += 200000;
    sub_12EA88("process rx1: %x %x\n", *v108, *v109);
    if ( *v109 == *v108 )
    {
LABEL_60:
      v111 = off_1028EC;
      v112 = off_1028F0;
      sub_12EA88("process rx2: %x, %x\n", *(uint32_t *)off_1028EC, *(uint32_t *)off_1028F0);
      while ( *v112 != *v111 )
        ;
      v113 = off_1028FC;
      sub_12EA88(aProcessRxEnd, v112);
      v114 = (uint16_t *)off_10295C;
      v115 = ((uint32_t *)(uintptr_t)off_102900)[1];
      v116 = ((uint32_t *)(uintptr_t)off_102900)[2];
      v169[0] = ((uint32_t *)(uintptr_t)off_102900)[0];
      v169[1] = v115;
      v169[2] = v116;
      v117 = ((uint32_t *)(uintptr_t)off_102900)[5];
      v118 = ((uint32_t *)(uintptr_t)off_102900)[6];
      v119 = ((uint32_t *)(uintptr_t)off_102900)[7];
      v169[3] = ((uint32_t *)(uintptr_t)off_102900)[4];
      v169[4] = v117;
      v169[5] = v118;
      v169[6] = v119;
      v120 = ((uint32_t *)(uintptr_t)off_102900)[9];
      v121 = ((uint32_t *)(uintptr_t)off_102900)[10];
      v122 = ((uint32_t *)(uintptr_t)off_102900)[11];
      v169[7] = ((uint32_t *)(uintptr_t)off_102900)[8];
      v169[8] = v120;
      v169[9] = v121;
      v169[10] = v122;
      v123 = ((uint32_t *)(uintptr_t)off_102900)[12];
      v124 = ((uint32_t *)(uintptr_t)off_102900)[13];
      v125 = ((uint32_t *)(uintptr_t)off_102900)[14];
      v126 = ((uint32_t *)(uintptr_t)off_102900)[15];
      v127 = off_10295C + 8 * HIDWORD(v46);
      *(uint8_t *)(v127 + 4) = 1;
      v169[11] = v123;
      v169[12] = v124;
      v169[13] = v125;
      v169[14] = v126;
      v128 = off_102904;
      *v113 |= 0x8000u;
      *v113 |= 0x2000u;
      sub_10B430((int)v169, v128, 0, 0, v114, 6, 1);
      *v113 &= ~0x8000u;
      *v113 &= ~0x2000u;
      *(uint8_t *)(v127 + 4) = 0;
      if ( r2_0 <= 0x1387 )
      {
        sub_1009A0(0, r2_0);
        if ( v168[13] )
          v168[15] |= 1u;
      }
      else
      {
        sub_1009A0(1, r2_0);
      }
      *(uint32_t *)off_102908 &= ~0x20000u;
      return sub_1009DC((int)off_1025D8 + v100, (int)off_1025D8 + v46);
    }
    while ( 1 )
    {
      while ( 1 )
      {
        sub_11DA70(1);
        v110 = **(uint8_t **)off_1028E8;
        if ( v110 != 1 )
          break;
        sub_110C60();
LABEL_55:
        if ( *v109 == *v108 )
          goto LABEL_60;
      }
      if ( v110 != 2 && v110 != 4 )
        goto LABEL_55;
      sub_114058();
      if ( *v109 == *v108 )
        goto LABEL_60;
    }
  }
  return sub_1009DC((int)off_1025D8 + v100, (int)off_1025D8 + v46);
}
