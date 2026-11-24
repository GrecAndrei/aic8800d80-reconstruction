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


extern uint32_t dword_108784;
extern uint32_t dword_108788;
extern uint32_t dword_10879C;
extern uint32_t dword_1087C0;
extern uint32_t dword_108ACC;
extern uint32_t dword_108AD0;
extern uint32_t dword_108AF4;
extern uint32_t dword_108E38;
extern uint32_t dword_108E80;
extern uint32_t off_108400;
extern uint32_t off_108404;
extern uint32_t off_108408;
extern uint32_t off_10840C;
extern uint32_t off_108410;
extern uint32_t off_108414;
extern uint32_t off_108418;
extern uint32_t off_10841C;
extern uint32_t off_108420;
extern uint32_t off_108424;
extern uint32_t off_108428;
extern uint32_t off_10842C;
extern uint32_t off_108430;
extern uint32_t off_108434;
extern uint32_t off_108438;
extern uint32_t off_10843C;
extern uint32_t off_108440;
extern uint32_t off_108444;
extern uint32_t off_108770;
extern uint32_t off_108774;
extern uint32_t off_108778;
extern uint32_t off_108790;
extern uint32_t off_1087B4;
extern uint32_t off_1087B8;
extern uint32_t off_1087BC;
extern uint32_t off_108AC0;
extern uint32_t off_108AC4;
extern uint32_t off_108AC8;
extern uint32_t off_108AD4;
extern uint32_t off_108AE4;
extern uint32_t off_108AF0;
extern uint32_t off_108AF8;
extern uint32_t off_108E4C;
extern uint32_t off_108E50;
extern uint32_t off_108E54;
extern uint32_t off_108E64;
extern uint32_t off_108E68;
extern uint32_t off_108E6C;
extern uint32_t off_108E70;
extern uint32_t off_108E74;
extern uint32_t off_108E78;
extern uint32_t off_108E7C;
extern uint32_t off_108E84;
extern uint32_t off_108E88;
extern uint32_t off_108E8C;
extern uint32_t off_108E90;
extern uint32_t off_108E94;
extern uint32_t off_108E98;
extern uint32_t off_108E9C;
extern uint32_t off_10916C;
extern uint32_t off_109170;
extern uint32_t off_109174;

// rf_phy_init @ 0x108140, size 4140 bytes
uint32_t * rf_phy_init(
        int a1,
        unsigned int *a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        int a6,
        uint16_t a7)
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
  int v37; // r4
  int v38; // r3
  int v39; // r4
  int i; // r6
  int v41; // r5
  int v42; // r3
  int v43; // r2
  int v44; // r6
  int v45; // r6
  int v46; // r5
  int v47; // r3
  int v48; // r3
  signed int v49; // r6
  signed int v50; // r5
  unsigned int v51; // r6
  int v52; // r5
  int v53; // r2
  int *v54; // r0
  unsigned int *v55; // r1
  unsigned int *v56; // r3
  int v57; // r2
  int v58; // r5
  int v59; // r4
  int v60; // r2
  int v61; // r2
  int v62; // r7
  int v63; // r6
  int v64; // r10
  int v65; // r9
  unsigned int v66; // r8
  int v67; // r5
  unsigned int *v68; // r1
  int *v69; // r2
  int v70; // r0
  unsigned int *v71; // r4
  uint32_t *result; // r0
  int v73; // r2
  int v74; // r4
  int v75; // r3
  int v76; // r5
  signed int v77; // r6
  signed int v78; // r4
  unsigned int *v79; // r1
  unsigned int *v80; // r3
  int v81; // cc
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
  int v99; // r2
  int v100; // [sp+0h] [bp-1F4h]
  int v101; // [sp+8h] [bp-1ECh]
  unsigned int v102; // [sp+8h] [bp-1ECh]
  int v103; // [sp+8h] [bp-1ECh]
  int v104; // [sp+Ch] [bp-1E8h]
  int v105; // [sp+10h] [bp-1E4h]
  int v106; // [sp+14h] [bp-1E0h]
  int v107; // [sp+18h] [bp-1DCh]
  int v108; // [sp+1Ch] [bp-1D8h]
  int *v109; // [sp+20h] [bp-1D4h]
  int v110; // [sp+24h] [bp-1D0h]
  int v111; // [sp+28h] [bp-1CCh]
  int v112; // [sp+2Ch] [bp-1C8h]
  int v113; // [sp+30h] [bp-1C4h]
  int v114; // [sp+34h] [bp-1C0h]
  int v115; // [sp+38h] [bp-1BCh]
  int v116; // [sp+3Ch] [bp-1B8h]
  int v117; // [sp+40h] [bp-1B4h]
  int v118; // [sp+44h] [bp-1B0h]
  unsigned int v119; // [sp+48h] [bp-1ACh]
  int v120; // [sp+4Ch] [bp-1A8h]
  unsigned int v121; // [sp+50h] [bp-1A4h]
  int v122; // [sp+54h] [bp-1A0h]
  int v123; // [sp+58h] [bp-19Ch]
  int v124; // [sp+5Ch] [bp-198h]
  int v125; // [sp+60h] [bp-194h]
  int v126; // [sp+64h] [bp-190h]
  int v127; // [sp+68h] [bp-18Ch]
  int v128; // [sp+6Ch] [bp-188h]
  int v129; // [sp+70h] [bp-184h]
  int v130; // [sp+74h] [bp-180h]
  int v131; // [sp+78h] [bp-17Ch]
  int v132; // [sp+7Ch] [bp-178h]
  int v133; // [sp+80h] [bp-174h]
  int v134; // [sp+84h] [bp-170h]
  int v135; // [sp+88h] [bp-16Ch]
  int v136; // [sp+8Ch] [bp-168h]
  int v137; // [sp+90h] [bp-164h]
  int v138; // [sp+94h] [bp-160h]
  unsigned int v139; // [sp+98h] [bp-15Ch]
  int v140; // [sp+9Ch] [bp-158h]
  unsigned int v141; // [sp+A0h] [bp-154h]
  int v142; // [sp+A4h] [bp-150h]
  unsigned int v143; // [sp+A8h] [bp-14Ch]
  int v144; // [sp+ACh] [bp-148h]
  unsigned int v145; // [sp+B0h] [bp-144h]
  int v146; // [sp+B4h] [bp-140h]
  unsigned int v147; // [sp+B8h] [bp-13Ch]
  unsigned int v148; // [sp+BCh] [bp-138h]
  int v149; // [sp+C0h] [bp-134h]
  int v150; // [sp+C4h] [bp-130h]
  int v151; // [sp+C8h] [bp-12Ch]
  int v152; // [sp+CCh] [bp-128h]
  int v153; // [sp+D0h] [bp-124h]
  int v154; // [sp+D4h] [bp-120h]
  int v155; // [sp+D8h] [bp-11Ch]
  int v156; // [sp+DCh] [bp-118h]
  int v157; // [sp+E0h] [bp-114h]
  int v158; // [sp+E4h] [bp-110h]
  int v159; // [sp+E8h] [bp-10Ch]
  int v160; // [sp+ECh] [bp-108h]
  int v161; // [sp+F0h] [bp-104h]
  int v163; // [sp+F8h] [bp-FCh]
  int v164; // [sp+FCh] [bp-F8h]
  unsigned int *v166; // [sp+104h] [bp-F0h]
  uint32_t v167[3]; // [sp+108h] [bp-ECh]
  unsigned int a1a[4]; // [sp+114h] [bp-E0h] BYREF
  int v169; // [sp+124h] [bp-D0h] BYREF
  int v170; // [sp+128h] [bp-CCh]
  int v171; // [sp+12Ch] [bp-C8h]
  uint64_t v172; // [sp+130h] [bp-C4h]
  unsigned int v173; // [sp+150h] [bp-A4h]
  uint32_t a2a[10]; // [sp+154h] [bp-A0h] BYREF
  char v175; // [sp+17Ch] [bp-78h] BYREF
  int v176; // [sp+18Ch] [bp-68h]
  int v177; // [sp+198h] [bp-5Ch] BYREF
  int v178; // [sp+19Ch] [bp-58h]
  int v179; // [sp+1A0h] [bp-54h]
  int v180; // [sp+1A4h] [bp-50h]

  v7 = (int *)off_108400;
  v8 = (unsigned int *)off_108434;
  v9 = (unsigned int *)off_108404;
  v10 = off_10843C;
  v11 = (int *)off_108408;
  v12 = (unsigned int *)off_108440;
  v13 = (int *)off_108444;
  v161 = *(uint32_t *)off_108438;
  v160 = *(uint32_t *)off_108400;
  v159 = *(uint32_t *)off_108400;
  v158 = *(uint32_t *)off_108434;
  v157 = *(uint32_t *)off_108404;
  v156 = *(uint32_t *)off_108404;
  v155 = *(uint32_t *)off_108404;
  v154 = *(uint32_t *)off_108404;
  v153 = *(uint32_t *)off_10843C;
  v152 = *(uint32_t *)off_10843C;
  v151 = *(uint32_t *)off_108408;
  v150 = *(uint32_t *)off_108400;
  v149 = *(uint32_t *)off_108400;
  *(uint32_t *)off_108438 = *(uint32_t *)off_108438 & 0xF8FFFFFF | 0x1000000;
  v14 = (int *)off_10840C;
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
  v148 = *v12;
  v147 = *v12;
  v146 = *(uint32_t *)off_108410;
  v145 = *(uint32_t *)off_108410;
  v144 = *(uint32_t *)off_108414;
  v143 = *(uint32_t *)off_108414;
  v142 = *(uint32_t *)off_108418;
  v141 = *(uint32_t *)off_108418;
  v140 = *(uint32_t *)off_10841C;
  v139 = *(uint32_t *)off_10841C;
  v138 = *v13;
  v137 = *v13;
  v136 = *v13;
  v135 = *v13;
  v134 = *v13;
  v133 = *v11;
  v132 = *v11;
  v131 = *v14;
  v130 = *v14;
  v129 = *v14;
  v128 = *v14;
  v127 = *v7;
  v126 = *v7;
  v125 = *v7;
  v124 = *v7;
  v123 = *(uint32_t *)off_108420;
  v122 = *(uint32_t *)off_108424;
  v121 = *v8;
  v120 = *(uint32_t *)off_108428;
  v119 = *v8;
  v118 = *(uint32_t *)off_10842C;
  v117 = *(uint32_t *)off_108430;
  v115 = *v7;
  v116 = *v7;
  *v11 |= 0x8000u;
  *v11 &= 0xFFFF8FFF;
  *v11 &= ~0x800u;
  *v14 |= 0x800000u;
  v15 = a4;
  *v14 |= 0x400000u;
  LOBYTE(a4) = 90;
  do
    a4 = (uint8_t)(a4 - 1);
  while ( a4 );
  v17 = off_10840C;
  *(uint32_t *)off_10840C &= ~0x100000u;
  *(uint32_t *)v17 |= 0x200000u;
  LOBYTE(v17) = 60;
  do
    v17 = (void *)(uint8_t)((uint8_t)v17 - 1);
  while ( v17 );
  v18 = off_108400;
  *(uint32_t *)off_10840C |= 0x100000u;
  *(uint32_t *)v18 |= 0x20000u;
  *(uint32_t *)v18 |= 0x10000u;
  LOBYTE(v18) = 90;
  do
    v18 = (void *)(uint8_t)((uint8_t)v18 - 1);
  while ( v18 );
  v19 = off_108400;
  *(uint32_t *)off_108400 &= ~0x40000u;
  *(uint32_t *)v19 |= 0x80000u;
  LOBYTE(v19) = 60;
  do
    v19 = (void *)(uint8_t)((uint8_t)v19 - 1);
  while ( v19 );
  v20 = off_108400;
  *(uint32_t *)off_108400 |= 0x40000u;
  *v20 |= 0x8000u;
  *v20 |= 0x4000u;
  LOBYTE(v21) = 90;
  do
    v21 = (uint8_t)(v21 - 1);
  while ( v21 );
  v22 = off_108420;
  v23 = off_108424;
  v24 = (unsigned int *)off_108434;
  *(uint32_t *)off_108420 |= 0x40000u;
  *v23 |= 0x3000u;
  v25 = off_108400;
  *v24 = *v24 & 0xFFFFFFFC | 1;
  v22[16] = v22[16] & 0xFFE3FFFF | 0xC0000;
  *v24 |= 4u;
  *v25 |= 0x800000u;
  *v25 |= 0x400000u;
  rf_clear_ana_bits();
  check_feature_flag(1, aStLoft);
  v114 = *(uint32_t *)off_108770;
  *(uint32_t *)off_108770 = *(uint32_t *)off_108770 & 0xFFFFFFF | 0x10000000;
  do
  {
    rf_enable_switch(v21, 0);
    v26 = (uint8_t)(v21 + 1);
    v21 = (uint8_t)(v21 + 2);
    rf_enable_switch(v26, 0);
  }
  while ( v21 != 32 );
  v27 = off_108774;
  *(uint32_t *)off_108774 &= ~0x200u;
  *v27 |= 0x200u;
  *v27 &= ~0x200u;
  mmio_set_bits();
  if ( a3 == 255 )
  {
    v28 = (unsigned int *)off_1087B4;
    v29 = (int *)off_1087B8;
    v30 = (int *)off_1087BC;
    v31 = ((uint32_t *)(uintptr_t)off_108778)[1];
    v32 = ((uint32_t *)(uintptr_t)off_108778)[2];
    v167[0] = ((uint32_t *)(uintptr_t)off_108778)[0];
    v167[1] = v31;
    v167[2] = v32;
    memset(a1a, 0, sizeof(a1a));
    v33 = 0;
    v110 = 6;
    do
    {
      if ( v33 )
      {
        if ( v33 == 1 )
        {
          v170 = 24;
          v34 = 1;
          v166 = a2 + 1;
        }
        else
        {
          v170 = 15;
          v166 = a2;
          v34 = 0;
        }
      }
      else
      {
        v170 = 15;
        v166 = a2 + 2;
        v34 = 2;
      }
      check_feature_flag(1, "===========table[%d]===========\n", v33);
      dma_chan_init(a2[v33], a2a);
      check_feature_flag(1, "cal_all_times=%d\n", v176);
      if ( v176 <= 0 )
      {
        v107 = v167[v34];
      }
      else
      {
        v164 = v34;
        v108 = 2 * (4 * v34 + 1);
        v163 = v34 << 12;
        v35 = dword_108784;
        v36 = dword_1087C0;
        v107 = v167[v34];
        v106 = a1 + 32 * v34;
        v109 = (int *)&v175;
        v112 = 0;
        v113 = v110 << 8;
        do
        {
          v37 = dword_108788 | v163 | (*v109 << 8);
          *(uint32_t *)off_108790 = v37;
          v38 = *v109++;
          check_feature_flag(1, "****************table[%d] cal [%x] index.********************\n", v33, v38);
          check_feature_flag(1, "tx_gain_map=%x\n", v37);
          v171 = 0;
          load_phy_table((int)&v169);
          v39 = v110;
          for ( i = v113; ; i = v39 << 8 )
          {
            *v28 = i & 0xF00 | *v28 & 0xFFFFF0FF;
            *v29 &= v35;
            *v29 &= v36;
            *v30 &= v35;
            *v30 &= v36;
            pmu_pll_config((int)&v169);
            pmu_clock_disable();
            rx_desc_page_read();
            pmu_reset_config((int)&v169);
            mmio_clear_bit0();
            tx_desc_page_read();
            v41 = *v30 & 0xFFF;
            v42 = (*v30 & 0x8000000) != 0 ? (HIWORD(*v30) & 0xFFF) - 4096 : HIWORD(*v30) & 0xFFF;
            v43 = (*v30 & 0x800) != 0 ? v41 - 4096 : *v30 & 0xFFF;
            if ( v42 <= 1024 && v43 <= 1024 )
              break;
            v100 = v43;
            v99 = v39;
            v39 = (uint8_t)(v39 - 1);
            check_feature_flag(1, "loft_bit_ctrl_ini=%d loft_i=%d loft_q=%d loft i/q too big,re cal\n", v99, v42, v100);
          }
          v110 = v39;
          v113 = i;
          v44 = HIWORD(*v30) & 0xFFF;
          *v28 = ((v39 + 1) << 8) & 0xF00 | *v28 & 0xFFFFF0FF;
          check_feature_flag(1, aReCalI);
          *v30 = dword_10879C & (v44 << 17) | *v30 & v35;
          pmu_pll_config((int)&v169);
          pmu_clock_disable();
          rx_desc_page_read();
          check_feature_flag(1, aReCalQ);
          *v30 = (2 * v41) & 0xFFF | *v30 & v36;
          pmu_reset_config((int)&v169);
          mmio_clear_bit0();
          tx_desc_page_read();
          v45 = HIWORD(*v30) & 0xFFF;
          v46 = *v30 & 0xFFF;
          v47 = v46 + (v45 << 16);
          *(uint32_t *)(v106 + 8) = v47;
          v48 = v47 | (*v28 >> 8 << 28);
          *(uint32_t *)(v106 + 8) = v48;
          v101 = v45 << 16;
          check_feature_flag(1, "loft_res[%d]=%x\n", v108, v48);
          *v30 &= v35;
          *v30 &= v36;
          mmio_enable_aux((int)&v169, 1);
          a1a[0] = v173;
          timer_get_interval(a1a, (int)&v169);
          pll_set_ratio((int)&v169, 1);
          v49 = v173;
          check_feature_flag(1, "din_i=%4x,  din_q=%4x,  pwr_bypass=%4d\n", HIWORD(*v30) & 0xFFF, *v30 & 0xFFF, v173);
          *v30 = *v30 & v35 | v101;
          *v30 = v46 | *v30 & v36;
          pll_set_ratio((int)&v169, 1);
          v50 = v173;
          check_feature_flag(1, "din_i=%4x,  din_q=%4x,  pwr_use=%4d\n", HIWORD(*v30) & 0xFFF, *v30 & 0xFFF, v173);
          if ( v49 <= v50 )
          {
            check_feature_flag(1, aLoftCalCantBeU);
            v107 = 0;
            *(uint32_t *)(v106 + 8) = 0;
          }
          else
          {
            v107 &= 1u;
            check_feature_flag(1, aLoftCanBeUsed);
          }
          v51 = *v28;
          v102 = *v30;
          v52 = *v30;
          v53 = *(v109 - 1);
          v167[v164] = v107;
          check_feature_flag(1, "ana_index[%x] loft_ok[%d]=%d\n", v53, v33, v107);
          check_feature_flag(1, "wdata=%x\n", (v52 & 0xFFF) + ((HIWORD(v102) & 0xFFF) << 16) + (v51 >> 8 << 28));
          *v30 = *v30 & v35 | ((*(uint16_t *)(v106 + 10) & 0xFFF) << 16);
          *v30 = *(uint32_t *)(v106 + 8) & 0xFFF | *v30 & v36;
          check_feature_flag(1, "use loft_i_offset=%x  loft_q_offset=%x \n", HIWORD(*v30) & 0xFFF, *v30 & 0xFFF);
          check_feature_flag(1, aLoftAmPhCal);
          v54 = (int *)off_108AC0;
          v55 = (unsigned int *)off_108AC4;
          v56 = (unsigned int *)off_108AC8;
          *v28 &= ~0x40000000u;
          *v28 &= 0xCFFFFFFF;
          v57 = *v54 & v36;
          a2a[6] = 1;
          v177 = 600;
          v178 = 600;
          v179 = 0;
          v180 = 0;
          v169 = 0;
          *v54 = v57 | 0x300;
          *v55 = *v55 & 0xFFFFFF8F | 0x50;
          *v56 = *v56 & 0xFFF0FFFF | 0x10000;
          *v56 = *v56 & 0xFFFF0FFF | 0x1000;
          *v56 = *v56 & 0xFFFFF0FF | 0x100;
          *v56 = *v56 & 0xFFFFFF0F | 0x20;
          *v56 = *v56 & 0xFFFFFFF0 | 3;
          v171 = 10;
          v58 = 0;
          load_phy_table((int)&v169);
          v111 = 0;
          do
          {
            while ( 1 )
            {
              v104 = v177;
              v105 = v178;
              v59 = v179;
              v103 = v180;
              v169 = v58;
              div3_signed_helper(&v177);
              mmio_set_bit24((int)&v177, &v169);
              mac_hw_queue_check((int)&v169, &v177, (int)a2a);
              v60 = v58;
              if ( v58 )
                break;
              if ( v172 )
              {
                v59 = v179;
                v103 = v180;
                v61 = 0;
                v58 = 1;
              }
              else
              {
                check_feature_flag(1, aEnterReLoftCal, HIDWORD(v172), (unsigned int)v172 | HIDWORD(v172));
                ++v111;
                v171 += 6;
                load_phy_table((int)&v169);
                v177 = v104;
                v178 = v105;
                v179 = v59;
                v180 = v103;
                v61 = -(v111 <= 2);
                v58 = v111 > 2;
              }
              check_feature_flag(1, "time[%d] am=%d,ph=%d\n", v61, v59, v103);
            }
            ++v58;
            check_feature_flag(1, "time[%d] am=%d,ph=%d\n", v60, v179, v180);
          }
          while ( v58 != 5 );
          v73 = (*v28 >> 12) & 7;
          v74 = dword_108E38 & (v180 << 16);
          v75 = HIWORD(*v28) & 7;
          v76 = v179 & 0xFFF;
          *(uint32_t *)(v106 + 12) = v74 + (v73 << 28) + (v75 << 12) + v76;
          check_feature_flag(1, "phase_bit=%d,am_bit=%d\n", v73, v75);
          check_feature_flag(1, "loft_res[%d]=%x\n", v108 + 1, *(uint32_t *)(v106 + 12));
          *v29 &= v35;
          *v29 &= v36;
          mmio_enable_aux((int)&v169, 0);
          a1a[0] = v173;
          timer_get_interval(a1a, (int)&v169);
          pll_set_ratio((int)&v169, 0);
          v77 = v173;
          check_feature_flag(1, "am=%4x, ph=%4x, pwr_am0_ph0=%4d\n", *v29 & 0xFFF, HIWORD(*v29) & 0xFFF, v173);
          *v29 = v74 | *v29 & v35;
          *v29 = v76 | *v29 & v36;
          pll_set_ratio((int)&v169, 0);
          v78 = v173;
          check_feature_flag(1, "am=%4x, ph=%4x,  pwr_am_ph=%4d\n", *v29 & 0xFFF, HIWORD(*v29) & 0xFFF, v173);
          v79 = (unsigned int *)off_108E50;
          v80 = (unsigned int *)off_108E54;
          *(uint32_t *)off_108E4C = *(uint32_t *)off_108E4C & v36 | 0xC0;
          *v79 = *v79 & 0xFFFFFF8F | 0x40;
          *v80 = *v80 & 0xFFF0FFFF | 0x10000;
          *v80 = *v80 & 0xFFFF0FFF | 0x1000;
          *v80 = *v80 & 0xFFFFF0FF | 0x100;
          *v80 = *v80 & 0xFFFFFF0F | 0x10;
          *v80 = *v80 & 0xFFFFFFF0 | 1;
          if ( v77 <= v78 )
          {
            check_feature_flag(1, aLoftAmPhCantBe);
            *(uint32_t *)(v106 + 12) = 0;
          }
          else
          {
            check_feature_flag(1, aLoftAmPhCanBeU);
          }
          v106 += 8;
          v81 = v176 <= ++v112;
          v108 += 2;
        }
        while ( !v81 );
      }
      *v166 = *v166 & 0xFFFDFFFF | (v107 << 17);
      check_feature_flag(1, "loft_ok[%d]=%d\n", v33, v107);
      check_feature_flag(1, "loft_dpd_bit_mask=%x\n", *v166);
      ++v33;
    }
    while ( v33 != 3 );
    mmio_clear_bits();
    v82 = (unsigned int *)off_108E64;
    v83 = (unsigned int *)off_108E68;
    v84 = (unsigned int *)off_108E90;
    v85 = (unsigned int *)off_108E94;
    v86 = off_108E98;
    v87 = off_108E9C;
    *(uint32_t *)off_108E64 = v133 & 0x8000 | *(uint32_t *)off_108E64 & 0xFFFF7FFF;
    v88 = (unsigned int *)off_108E6C;
    *v82 = v132 & 0x7000 | *v82 & 0xFFFF8FFF;
    v89 = (unsigned int *)off_108E70;
    *v83 = v161 & 0x7000000 | *v83 & 0xF8FFFFFF;
    *v82 = *v82 & 0xFFFFF7FF | v151 & 0x800;
    v90 = (unsigned int *)off_108E74;
    *v88 = *v88 & 0xFFFBFFFF | v149 & 0x40000;
    v91 = (unsigned int *)off_108E78;
    *v88 = *v88 & 0xFFF7FFFF | v150 & 0x80000;
    v92 = (unsigned int *)off_108E7C;
    *v89 = *v89 & 0xFF7FFFFF | v131 & 0x800000;
    *v89 = *v89 & 0xFFBFFFFF | v130 & 0x400000;
    v93 = dword_108E80;
    *v89 = *v89 & 0xFFEFFFFF | v129 & 0x100000;
    *v89 = v128 & 0x200000 | *v89 & 0xFFDFFFFF;
    v94 = off_108E84;
    *v88 = v127 & 0x20000 | *v88 & 0xFFFDFFFF;
    *v88 = v126 & 0x10000 | *v88 & 0xFFFEFFFF;
    *v88 = v125 & 0x8000 | *v88 & 0xFFFF7FFF;
    v95 = (unsigned int *)off_108E54;
    *v88 = v124 & 0x4000 | *v88 & 0xFFFFBFFF;
    v96 = off_108E88;
    *v84 = v123 & 0x40000 | *v84 & 0xFFFBFFFF;
    *(uint32_t *)off_108E88 = v122 & 0x3000 | *v96 & 0xFFFFCFFF;
    v97 = off_108E8C;
    *v90 = v121 & 3 | *v90 & 0xFFFFFFFC;
    *(uint32_t *)off_108E8C = v120 & 0x1C0000 | *v97 & 0xFFE3FFFF;
    *v90 = v119 & 4 | *v90 & 0xFFFFFFFB;
    *v88 = v116 & 0x800000 | *v88 & 0xFF7FFFFF;
    *v88 = v115 & 0x400000 | *v88 & 0xFFBFFFFF;
    *v88 = v160 & 0x200000 | *v88 & 0xFFDFFFFF;
    *v88 = v159 & 0x100000 | *v88 & 0xFFEFFFFF;
    *v90 = v158 & 0xF0 | *v90 & 0xFFFFFF0F;
    *v91 = v157 & 0x80 | *v91 & 0xFFFFFF7F;
    *v91 = v156 & 0x70 | *v91 & 0xFFFFFF8F;
    *v91 = v155 & 0x400 | *v91 & 0xFFFFFBFF;
    *v91 = v154 & 0x300 | *v91 & 0xFFFFFCFF;
    *v92 = *v92 & 0xFFBFFFFF | v153 & 0x400000;
    *v92 = *v92 & 0xFFDFFFFF | v152 & 0x200000;
    result = off_10916C;
    *v92 &= 0xFFFE00FF;
    *v92 &= ~0x20000u;
    *v92 |= 0x40000u;
    *v85 = *v85 & v93 | v148 & 0x3FFF;
    *v85 = *v85 & 0xC000FFFF | ((HIWORD(v147) & 0x3FFF) << 16);
    *v94 = *v94 & v93 | v146 & 0x3FFF;
    *v94 = *v94 & 0xC000FFFF | ((HIWORD(v145) & 0x3FFF) << 16);
    *result = *result & v93 | v144 & 0x3FFF;
    *result = *result & 0xC000FFFF | ((HIWORD(v143) & 0x3FFF) << 16);
    *v86 = *v86 & v93 | v142 & 0x3FFF;
    *v86 = *v86 & 0xC000FFFF | ((HIWORD(v141) & 0x3FFF) << 16);
    *v87 = v93 & *v87 | v140 & 0x3FFF;
    *v87 = *v87 & 0xC000FFFF | ((HIWORD(v139) & 0x3FFF) << 16);
    *v95 = v138 & 0xF0000 | *v95 & 0xFFF0FFFF;
    *v95 = v137 & 0xF000 | *v95 & 0xFFFF0FFF;
    *v95 = v136 & 0xF00 | *v95 & 0xFFFFF0FF;
    *v95 = v135 & 0xF0 | *v95 & 0xFFFFFF0F;
    v98 = (unsigned int *)off_109170;
    *v95 = *v95 & 0xFFFFFFF0 | v134 & 0xF;
    *v98 = *v98 & 0x7FFFFFFF | v118 & 0x80000000;
    *(uint32_t *)off_109174 = v117;
    *(v84 - 19976) = *(unsigned int *)((char *)v84 + 0xFFFFFFE0 - 79872) & 0xFFFFFFF | v114 & 0xF0000000;
  }
  else
  {
    v62 = dword_108AD0;
    v63 = ((int)((uint64_t)(dword_108ACC * (uint64_t)a3) >> 32) >> 5) - (a3 >> 31);
    v64 = a3 - 100 * v63;
    rf_set_control_bit();
    *(uint32_t *)off_108AD4 &= ~1u;
    v170 = 30;
    v171 = v63;
    alloc_tx_event("pwr=%d\n", v63);
    v65 = HIWORD(v15) & 0xFFF;
    v66 = HIWORD(a5) & 0xFFF;
    v67 = v15 & 0xFFF;
    alloc_tx_event("index=%d\n", v64);
    alloc_tx_event("din_i=%x din_q=%x ph=%x am=%x\n", v65, v67, v66, a5 & 0xFFF);
    *(uint32_t *)off_108AE4 = a6;
    alloc_tx_event("dump_tx_gain_map=%x\n", a6);
    *(uint32_t *)off_108AC0 = *(uint32_t *)off_108AC0 & v62 | a7 & 0xFFF;
    alloc_tx_event("dump_amp_tone=%x\n", a7);
    bb_start_cmd(v64);
    v68 = (unsigned int *)off_108AC8;
    v69 = (int *)off_108AF0;
    v70 = dword_108AF4;
    v71 = (unsigned int *)off_108AF8;
    *(uint32_t *)off_108AC8 = *(uint32_t *)off_108AC8 & 0xFFF0FFFF | 0x10000;
    *v68 = *v68 & 0xFFFF0FFF | 0x1000;
    *v68 = *v68 & 0xFFFFF0FF | 0x100;
    *v68 = *v68 & 0xFFFFFF0F | 0x20;
    *v68 = *v68 & 0xFFFFFFF0 | 3;
    *v69 = *v69 & v70 | (v65 << 16);
    *v69 = v67 | *v69 & v62;
    *v71 = *v71 & v70 | (v66 << 16);
    *v71 = a5 & 0xFFF | *v71 & v62;
    pll_set_clock();
    load_phy_table((int)&v169);
    pll_set_ratio((int)&v169, 0);
    check_feature_flag(1, "am=%4x, ph=%4x,  dump_pwr=%4d\n", *v71 & 0xFFF, HIWORD(*v71) & 0xFFF, v173);
    pll_set_ratio((int)&v169, 0);
    check_feature_flag(1, "am=%4x, ph=%4x,  dump_pwr=%4d\n", *v71 & 0xFFF, HIWORD(*v71) & 0xFFF, v173);
    mmio_read32(500);
    return (uint32_t *)tx_wait_ready();
  }
  return result;
}
