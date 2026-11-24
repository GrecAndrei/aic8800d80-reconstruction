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


extern uint32_t dword_102150;
extern uint32_t dword_102158;
extern uint32_t dword_102174;
extern uint32_t dword_1021A4;
extern uint32_t dword_1021A8;
extern uint32_t dword_1021AC;
extern uint32_t dword_1021B0;
extern uint32_t dword_1021B8;
extern uint32_t dword_1021BC;
extern uint32_t dword_1021C4;
extern uint32_t dword_1021CC;
extern uint32_t dword_1021D0;
extern uint32_t dword_1021E4;
extern uint32_t dword_1024A0;
extern uint32_t dword_1024A8;
extern uint32_t dword_1024AC;
extern uint32_t dword_1024B0;
extern uint32_t dword_1024B4;
extern uint32_t dword_1024D4;
extern uint32_t dword_1024D8;
extern uint32_t dword_1024DC;
extern uint32_t dword_1024E0;
extern uint32_t dword_1024E8;
extern uint32_t dword_1024EC;
extern uint32_t dword_1024F4;
extern uint32_t dword_1024FC;
extern uint32_t dword_1027FC;
extern uint32_t dword_102800;
extern uint32_t dword_102808;
extern uint32_t dword_10280C;
extern uint32_t dword_102810;
extern uint32_t off_102168;
extern uint32_t off_102170;
extern uint32_t off_102178;
extern uint32_t off_10217C;
extern uint32_t off_102180;
extern uint32_t off_102184;
extern uint32_t off_102188;
extern uint32_t off_10218C;
extern uint32_t off_102190;
extern uint32_t off_102194;
extern uint32_t off_102198;
extern uint32_t off_10219C;
extern uint32_t off_1021A0;
extern uint32_t off_1021B4;
extern uint32_t off_1021C0;
extern uint32_t off_1021C8;
extern uint32_t off_1021D4;
extern uint32_t off_1021D8;
extern uint32_t off_1021DC;
extern uint32_t off_1021E0;
extern uint32_t off_1021E8;
extern uint32_t off_1021EC;
extern uint32_t off_1024B8;
extern uint32_t off_1024BC;
extern uint32_t off_1024C0;
extern uint32_t off_1024C8;
extern uint32_t off_1024CC;
extern uint32_t off_1024D0;
extern uint32_t off_1024E4;
extern uint32_t off_1024F0;
extern uint32_t off_1024F8;
extern uint32_t off_102500;
extern uint32_t off_10250C;
extern uint32_t off_102510;
extern uint32_t off_102514;
extern uint32_t off_1027D0;
extern uint32_t off_1027D4;
extern uint32_t off_1027D8;
extern uint32_t off_1027DC;
extern uint32_t off_1027E0;
extern uint32_t off_1027E8;
extern uint32_t off_1027EC;
extern uint32_t off_1027F0;
extern uint32_t off_1027F4;
extern uint32_t off_1027F8;
extern uint32_t off_102804;
extern uint32_t off_102814;
extern uint32_t off_102818;
extern uint32_t off_10281C;
extern uint32_t off_102820;
extern uint32_t off_102824;

// sub_101E18 @ 0x101e18, size 2476 bytes
int  sub_101E18(
        unsigned int a1,
        int a2,
        unsigned int r2_0,
        unsigned int a4,
        uint8_t a5,
        uint8_t a6)
{
  int v10; // r0
  uint16_t v11; // r4
  uint64_t v12; // r0
  uint64_t v13; // r0
  unsigned int v14; // r0
  uint64_t v15; // r0
  unsigned int *v16; // r5
  uint64_t v17; // r0
  uint32_t *v18; // r2
  uint32_t *v19; // r2
  int v20; // r1
  uint8_t *v21; // r4
  unsigned int v22; // r3
  int v23; // r5
  uint64_t v24; // r0
  unsigned int v25; // r2
  uint64_t v26; // r4
  uint64_t v27; // r6
  uint64_t v28; // r0
  uint64_t v29; // d8
  uint64_t v30; // r2
  unsigned int *v31; // r11
  uint64_t v32; // r6
  uint64_t v33; // r0
  uint64_t v34; // r0
  uint64_t v35; // r2
  uint64_t v36; // r0
  uint64_t v37; // r0
  unsigned int v38; // r0
  uint64_t v39; // r2
  unsigned int v40; // r9
  uint64_t v41; // r0
  uint64_t v42; // r6
  uint64_t v43; // r0
  uint64_t v44; // r2
  uint64_t v45; // r0
  uint64_t v46; // r2
  uint64_t v47; // r0
  uint64_t v48; // r0
  uint64_t v49; // r2
  uint64_t v50; // r4
  unsigned int v51; // r0
  uint32_t *v52; // r2
  uint64_t v53; // r0
  unsigned int *v54; // r6
  uint64_t v55; // r0
  uint64_t v56; // r0
  int v57; // r9
  uint64_t v58; // r6
  uint64_t v59; // r2
  uint64_t v60; // r2
  int v61; // r11
  uint64_t v62; // r0
  uint64_t v63; // r2
  uint64_t v64; // r0
  uint64_t v65; // r0
  int v66; // r0
  uint32_t *v67; // r6
  unsigned int *v68; // r2
  unsigned int *v69; // r7
  unsigned int *v70; // r11
  uint64_t v71; // r0
  uint64_t v72; // r8
  uint64_t v73; // r0
  uint64_t v74; // r8
  uint64_t v75; // r0
  uint64_t v76; // r0
  uint64_t v77; // r2
  uint64_t v78; // r0
  uint64_t v79; // r2
  uint64_t v80; // r0
  uint64_t v81; // r0
  uint64_t v82; // r2
  unsigned int v83; // r4
  uint64_t v84; // r0
  uint64_t v85; // r0
  uint64_t v86; // r0
  uint64_t v87; // r2
  uint64_t v88; // r0
  int v89; // r4
  int v90; // r1
  int v91; // r0
  int v92; // r12
  int v93; // r7
  int v94; // r5
  unsigned int *v95; // r3
  uint32_t *v96; // r6
  unsigned int *v97; // r4
  volatile unsigned int v98; // r1
  unsigned int v99; // r1
  int v100; // r3
  uint32_t *v101; // r2
  int v102; // r6
  int v103; // r8
  int v104; // r11
  int v105; // r5
  uint64_t v106; // r6
  uint64_t v107; // r0
  uint64_t v108; // r2
  unsigned int *v109; // r11
  uint64_t v110; // r4
  uint64_t v111; // r0
  uint64_t v112; // r0
  uint64_t v113; // r2
  uint64_t v114; // r0
  uint64_t v115; // r0
  unsigned int v116; // r0
  uint64_t v117; // r2
  unsigned int v118; // r9
  uint64_t v119; // r0
  uint64_t v120; // r6
  uint64_t v121; // r0
  uint64_t v122; // r2
  uint64_t v123; // r0
  uint64_t v124; // r0
  uint64_t v125; // r2
  unsigned int v126; // r0
  uint32_t *v127; // r2
  uint64_t v128; // r0
  unsigned int *v129; // r6
  uint64_t v130; // r0
  uint64_t v131; // r0
  uint64_t v132; // r2
  uint8_t *v133; // r4
  int *v134; // r4
  int v135; // r2
  int v136; // r0
  uint32_t *v137; // r7
  uint32_t *v138; // r4
  int *v139; // r9
  int v140; // r1
  int v141; // r2
  int v142; // r1
  int v143; // r2
  int v144; // r3
  int v145; // r1
  int v146; // r2
  int v147; // r3
  int v148; // r0
  int v149; // r1
  int v150; // r2
  int v151; // r3
  uint32_t *v152; // r5
  int v153; // r1
  int v154; // r0
  int result; // r0
  uint64_t v156; // r0
  unsigned int *v157; // r5
  uint64_t v158; // r0
  uint64_t v159; // r2
  uint64_t v160; // r0
  uint64_t v161; // r0
  uint64_t v162; // r0
  uint64_t v163; // r2
  uint64_t v164; // r0
  uint64_t v165; // r0
  uint32_t *v166; // r0
  uint32_t *v167; // r1
  uint32_t *v168; // r2
  int v169; // r3
  unsigned int v171; // [sp+24h] [bp-50h]
  unsigned int v172; // [sp+24h] [bp-50h]
  uint8_t *v173; // [sp+28h] [bp-4Ch]
  int v174; // [sp+2Ch] [bp-48h]
  uint32_t v175[16]; // [sp+34h] [bp-40h] BYREF

  sub_11F504("\x9D\x87%s: band=%d freq=%d freq1=%d chantype=%d sx=%d\n", aPhyHwSetChanne, a1, a2, r2_0, a4, a6);
  if ( **(uint8_t **)off_102168 != 3 )
    sub_11F504("setch:%d\r\n", r2_0);
  sub_10058C(a4);
  sub_100A80(a1, a2, r2_0, a4, a5);
  v10 = sub_1005E8();
  v11 = v10;
  if ( v10 == 240 )
  {
    if ( a4 <= 1 )
      HIDWORD(v156) = dword_102800;
    else
      HIDWORD(v156) = dword_1027FC;
    v157 = (unsigned int *)off_102804;
    LODWORD(v156) = 0;
    v158 = sub_127194(v156);
    *v157 = *v157 & 0xC00FFFFF | dword_102808 & (sub_127BA4(v158) << 20);
  }
  else
  {
    v12 = sub_12754C(v10);
    if ( a4 > 1 )
      v13 = sub_127620(v12, *(uint64_t *)&dword_1024A0);
    else
      v13 = sub_127620(v12, *(uint64_t *)&dword_102150);
    v14 = sub_127BE4(v13);
    v15 = sub_127570(v14);
    v16 = (unsigned int *)off_102170;
    v17 = sub_127194(v15);
    *v16 = *v16 & 0xF003FFFF | dword_102174 & (sub_127BA4(v17) << 18);
  }
  if ( a1 )
    v18 = off_102500;
  else
    v18 = off_102178;
  *(uint32_t *)off_10217C = (uint16_t)*(uint32_t *)off_10217C
                        | (((*v18 >> 8) - (uint16_t)(((*(uint32_t *)off_102170 >> 18) & 0x3FF) + v11)) << 16);
  v19 = off_102184;
  *(uint32_t *)off_102180 = *(uint32_t *)off_102180 & 0xFFFE1FFF | 0xE000;
  v20 = *((uint8_t *)off_102188 + 36);
  *v19 &= ~4u;
  if ( v20 != a1 )
    sub_1032DC(a1);
  if ( **(uint16_t **)off_10218C < 0 && a1 > 1 )
  {
    sub_1219C4((int)aBandPhyBandMax, (int)aPhyHwSetChanne_0, 5664);
    goto LABEL_49;
  }
  if ( a1 )
  {
LABEL_49:
    v173 = off_10250C;
    v133 = off_10250C;
    sub_1010D4(r2_0);
    if ( v133[1] )
      sub_100688();
    if ( a4 )
    {
      if ( a4 == 1 )
        *(uint32_t *)off_102820 = *(uint32_t *)off_102820 & 0xFFFFFFC7 | 0x18;
      else
        *(uint32_t *)off_102510 = *(uint32_t *)off_102510 & 0xFFFFFFC7 | 0x20;
    }
    else
    {
      *(uint32_t *)off_102820 = *(uint32_t *)off_102820 & 0xFFFFFFC7 | 0x10;
    }
    goto LABEL_18;
  }
  v173 = off_102190;
  v21 = off_102190;
  sub_100E00(r2_0, a4);
  if ( v21[1] )
    sub_10064C();
  if ( a4 )
  {
    if ( a4 == 1 )
      *(uint32_t *)off_102194 = *(uint32_t *)off_102194 & 0xFFFFFFC7 | 8;
  }
  else
  {
    *(uint32_t *)off_102820 &= 0xFFFFFFC7;
  }
LABEL_18:
  v22 = (*(uint32_t *)off_102198 >> 5) & 0x1F;
  if ( (*(uint32_t *)off_102198 & 0x400) != 0 )
    v22 *= 2;
  if ( (*(uint32_t *)off_10219C & 0x80000) != 0 && (*(uint32_t *)off_10219C & 0x40000) != 0 )
    v22 >>= 1;
  v23 = *(uint8_t *)off_1021A0 * v22;
  if ( !a1 )
  {
    v24 = sub_12754C(r2_0);
    v25 = v24;
    LODWORD(v24) = v23;
    v26 = __PAIR64__(HIDWORD(v24), v25);
    v27 = sub_12754C(v24);
    v28 = sub_1272B4(v26, v26);
    v29 = v27;
    HIDWORD(v30) = dword_1021A4;
    v31 = (unsigned int *)off_1021E8;
    v32 = v28;
    LODWORD(v30) = 0;
    v33 = sub_127620(v29, v30);
    v34 = sub_127874(v32, v33);
    HIDWORD(v35) = dword_1021A8;
    LODWORD(v35) = 0;
    v36 = sub_127620(v34, v35);
    v37 = sub_127194(v36);
    v38 = sub_127BA4(v37);
    HIDWORD(v39) = dword_1021A4;
    LODWORD(v39) = 0;
    v40 = v38;
    v41 = sub_127874(v26, v39);
    v42 = sub_127194(v41);
    v43 = sub_12752C(v40);
    HIDWORD(v44) = dword_1021A4;
    LODWORD(v44) = 0;
    v45 = sub_127620(v43, v44);
    HIDWORD(v46) = dword_1021AC;
    LODWORD(v46) = 0;
    v47 = sub_127620(v45, v46);
    v48 = sub_127620(v47, v29);
    HIDWORD(v49) = dword_1021B0;
    LODWORD(v49) = 0;
    v50 = sub_127620(v48, v49);
    sub_101DD0(0);
    *(uint32_t *)off_1021B4 = v40 & 0x7FFFFFFF;
    v51 = sub_127BA4(v42);
    v52 = off_1021C0;
    *v31 = dword_1021BC & *v31 | dword_1021B8 & (v51 << 13);
    *v52 |= 1u;
LABEL_25:
    HIDWORD(v53) = dword_1021C4;
    v54 = (unsigned int *)off_1021C8;
    LODWORD(v53) = 0;
    v55 = sub_127874(v53, v50);
    v56 = sub_127194(v55);
    *v54 = sub_127B54(v56) & 0xFFFFFFF | *v54 & 0xF0000000;
    v57 = 0;
    v58 = sub_127874(v50, *(uint64_t *)&dword_102158);
    goto LABEL_26;
  }
  v106 = sub_12754C(r2_0);
  v107 = sub_12754C(v23);
  HIDWORD(v108) = dword_1024D4;
  v109 = (unsigned int *)off_102514;
  LODWORD(v108) = 0;
  v110 = v107;
  v111 = sub_127620(v107, v108);
  v112 = sub_127874(v106, v111);
  HIDWORD(v113) = dword_1024D8;
  LODWORD(v113) = 0;
  v114 = sub_127620(v112, v113);
  v115 = sub_127194(v114);
  v116 = sub_127BA4(v115);
  HIDWORD(v117) = dword_1024DC;
  LODWORD(v117) = 0;
  v118 = v116;
  v119 = sub_127874(v106, v117);
  v120 = sub_127194(v119);
  v121 = sub_12752C(v118);
  HIDWORD(v122) = dword_1024D4;
  LODWORD(v122) = 0;
  v123 = sub_127620(v121, v122);
  v124 = sub_127620(v123, v110);
  HIDWORD(v125) = dword_1024E0;
  LODWORD(v125) = 0;
  v50 = sub_127620(v124, v125);
  sub_101DD0(0);
  *(uint32_t *)off_1024E4 = v118 & 0x7FFFFFFF;
  v126 = sub_127BA4(v120);
  v127 = off_1024F0;
  *v109 = dword_1024EC & *v109 | dword_1024E8 & (v126 << 13);
  *v127 |= 1u;
  if ( a1 != 1 )
    goto LABEL_25;
  HIDWORD(v128) = dword_1024F4;
  v129 = (unsigned int *)off_1024F8;
  LODWORD(v128) = 0;
  v130 = sub_127874(v128, v50);
  v131 = sub_127194(v130);
  *v129 = *v129 & 0xF0000000 | sub_127B54(v131) & 0xFFFFFFF;
  LODWORD(v132) = 0;
  HIDWORD(v132) = dword_1024FC;
  v57 = 1;
  v58 = sub_127874(v50, v132);
LABEL_26:
  HIDWORD(v59) = dword_1021CC;
  LODWORD(v59) = 0;
  if ( sub_127B2C(v58, v59) )
  {
    v162 = sub_127620(v58, 0x4180000000000000uLL);
    HIDWORD(v163) = dword_102810;
    LODWORD(v163) = 0;
    v164 = sub_127874(v162, v163);
    v165 = sub_127194(v164);
    v66 = sub_127B54(v165);
    v61 = 0x20000000;
  }
  else
  {
    HIDWORD(v60) = dword_1021D0;
    LODWORD(v60) = 0;
    v61 = sub_127B2C(v58, v60);
    v62 = sub_127620(v58, 0x4180000000000000uLL);
    if ( v61 )
    {
      HIDWORD(v63) = dword_1021D0;
      LODWORD(v63) = 0;
      v64 = sub_127874(v62, v63);
      v65 = sub_127194(v64);
      v66 = sub_127B54(v65);
      v61 = 0x10000000;
    }
    else
    {
      HIDWORD(v159) = dword_10280C;
      LODWORD(v159) = 0;
      v160 = sub_127874(v62, v159);
      v161 = sub_127194(v160);
      v66 = sub_127B54(v161);
    }
  }
  v67 = off_1021D8;
  v68 = (unsigned int *)off_1021DC;
  v69 = (unsigned int *)off_1021E0;
  *(uint32_t *)off_1021D4 = v66 & 0xFFFFFFF;
  *v67 = *v67 & 0xFFFFFFF | v61;
  v70 = (unsigned int *)off_1021EC;
  *v68 = *v68 & 0xFFFFFFFC | v57;
  v71 = sub_12754C(a2);
  v72 = sub_1272B4(v71, v50);
  v73 = sub_12754C(r2_0);
  v74 = sub_1272B0(v72, v73);
  HIDWORD(v75) = dword_1021E4;
  LODWORD(v75) = 0;
  v76 = sub_127874(v75, v50);
  LODWORD(v77) = 0;
  HIDWORD(v77) = dword_1021AC;
  v78 = sub_1272B4(v76, v77);
  v171 = *v69;
  *v69 = v171 & 0xFFFF8000 | sub_127BA4(v78) & 0x7FFF;
  HIDWORD(v79) = dword_1024A8;
  LODWORD(v79) = 0;
  v80 = sub_127620(v50, v79);
  v81 = sub_127874(v80, v74);
  HIDWORD(v82) = dword_1024AC;
  v83 = *v70;
  LODWORD(v82) = 0;
  v84 = sub_1272B4(v81, v82);
  *v70 = (HIWORD(v83) << 16) | (uint16_t)sub_127BA4(v84);
  HIDWORD(v85) = dword_1024B0;
  LODWORD(v85) = 0;
  v86 = sub_127874(v85, v74);
  HIDWORD(v87) = dword_1024AC;
  LODWORD(v87) = 0;
  v88 = sub_1272B4(v86, v87);
  *v70 = *v70 & 0x8000FFFF | dword_1024B4 & (sub_127BA4(v88) << 16);
  *v67 = a4 & 0xF | *v67 & 0xFFFFFFF0;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      v90 = 0;
      v94 = 0;
      v89 = 16;
      v91 = 0x100000;
      v92 = 402653184;
      v93 = 11;
    }
    else
    {
      v89 = 32;
      v90 = 0x80000;
      v91 = 3145728;
      v92 = 402653184;
      v93 = 13;
      v94 = 256;
    }
  }
  else
  {
    v89 = 0;
    v90 = 0;
    v91 = 0x100000;
    v92 = 419430400;
    v93 = 10;
    v94 = 0;
  }
  v95 = (unsigned int *)off_1024B8;
  v96 = off_1024BC;
  *(uint32_t *)off_1024B8 = *(uint32_t *)off_1024B8 & 0xFFFFFFCF | v89;
  v97 = (unsigned int *)off_1024C0;
  *v95 = *v95 & 0xFFF3FFFF | v90;
  *v95 = *v95 & 0xFFCFFFFF | v91;
  *v96 = *v96 & 0xFFFFFF | v92;
  *v96 = *v96 & 0xFFFFFF00 | v93;
  *v97 = *v97 & 0xFFFFFEFF | v94;
  v98 = (*(volatile uint32_t *)0x40501010u);
  v99 = v98 + 2;
  do
    v100 = v99 - (*(volatile uint32_t *)0x40501010u);
  while ( v100 >= 0 );
  v101 = off_1024CC;
  *(uint32_t *)off_1024C8 = 4;
  *v101 |= 4u;
  if ( a1 )
    v102 = *(uint8_t *)off_1027F8;
  else
    v102 = *(uint8_t *)off_1024D0;
  if ( r2_0 > 0x1666 )
  {
    v103 = 8752;
    v104 = 7600;
    v105 = 6;
  }
  else if ( r2_0 > 0x1616 )
  {
    v103 = 7488;
    v104 = 6336;
    v105 = 5;
  }
  else if ( r2_0 > 0x15C6 )
  {
    v103 = 6224;
    v104 = 5072;
    v105 = 4;
  }
  else if ( r2_0 > 0x1571 )
  {
    v103 = 4960;
    v104 = 3808;
    v105 = 3;
  }
  else if ( r2_0 <= 0x1486 )
  {
    if ( r2_0 <= 0x143B )
      v169 = 0;
    else
      v169 = 1264;
    v104 = v169 + 16;
    v103 = v169 + 1168;
    v105 = r2_0 > 0x143B;
  }
  else
  {
    v103 = 3696;
    v104 = 2544;
    v105 = 2;
  }
  if ( !*(uint8_t *)off_1027D0 )
    goto LABEL_68;
  v134 = off_1027D4;
  v135 = *(uint8_t *)off_1027D8;
  v174 = *off_1027D4;
  v136 = *off_1027D4;
  *(uint8_t *)off_1027D0 = 0;
  if ( !v135 && v136 )
  {
    v166 = off_102814;
    *v134 = 0;
    v167 = off_102818;
    v168 = off_10281C;
    *v166 += 200000;
    *v167 += 200000;
    *v168 += 200000;
    v167[2] += 200000;
    v168[3] += 200000;
  }
  v137 = off_1027DC;
  v138 = off_1027E0;
  sub_11F504("process rx1: %x %x\n", *(uint32_t *)off_1027DC, *(uint32_t *)off_1027E0);
  while ( *v138 != *v137 )
    sub_12373C();
  v139 = (int *)off_102824;
  if ( *(uint32_t *)off_102824 )
  {
    sub_1268EC(0);
    if ( !v102 )
      goto LABEL_63;
LABEL_82:
    sub_102E84(a1, a4, 0);
    goto LABEL_63;
  }
  if ( v102 )
    goto LABEL_82;
LABEL_63:
  v140 = ((uint32_t *)(uintptr_t)off_1027E8)[1];
  v141 = ((uint32_t *)(uintptr_t)off_1027E8)[2];
  v175[0] = ((uint32_t *)(uintptr_t)off_1027E8)[0];
  v175[1] = v140;
  v175[2] = v141;
  v142 = ((uint32_t *)(uintptr_t)off_1027E8)[5];
  v143 = ((uint32_t *)(uintptr_t)off_1027E8)[6];
  v144 = ((uint32_t *)(uintptr_t)off_1027E8)[7];
  v175[3] = ((uint32_t *)(uintptr_t)off_1027E8)[4];
  v175[4] = v142;
  v175[5] = v143;
  v175[6] = v144;
  v145 = ((uint32_t *)(uintptr_t)off_1027E8)[9];
  v146 = ((uint32_t *)(uintptr_t)off_1027E8)[10];
  v147 = ((uint32_t *)(uintptr_t)off_1027E8)[11];
  v175[7] = ((uint32_t *)(uintptr_t)off_1027E8)[8];
  v175[8] = v145;
  v175[9] = v146;
  v175[10] = v147;
  v148 = ((uint32_t *)(uintptr_t)off_1027E8)[12];
  v149 = ((uint32_t *)(uintptr_t)off_1027E8)[13];
  v150 = ((uint32_t *)(uintptr_t)off_1027E8)[14];
  v151 = ((uint32_t *)(uintptr_t)off_1027E8)[15];
  v172 = off_1027EC + 8 * v105;
  *(uint8_t *)(v172 + 4) = 1;
  v152 = off_1027F0;
  v175[11] = v148;
  v175[12] = v149;
  v175[13] = v150;
  v175[14] = v151;
  v153 = off_1027F4;
  *(uint32_t *)off_1027F0 |= 0x8000u;
  *v152 |= 0x2000u;
  sub_10B048((int)v175, v153, 0, 0, (uint16_t *)off_1027EC, 6, 1);
  *v152 &= ~0x8000u;
  *v152 &= ~0x2000u;
  *(uint8_t *)(v172 + 4) = 0;
  if ( r2_0 <= 0x1387 )
  {
    sub_10090C(0, r2_0);
    if ( v173[13] )
      v173[15] |= 1u;
  }
  else
  {
    sub_10090C(1, r2_0);
  }
  if ( !*(uint8_t *)off_1027D8 && v174 )
  {
    v154 = *v139;
    *off_1027D4 = v174;
    if ( !v154 )
      goto LABEL_68;
  }
  else
  {
    v154 = *v139;
    if ( !*v139 )
      goto LABEL_68;
  }
  sub_1268EC(v154);
LABEL_68:
  result = sub_100948(off_1027F4 + v104, off_1027F4 + v103);
  if ( v102 )
    return sub_102E84(a1, a4, v102);
  return result;
}
