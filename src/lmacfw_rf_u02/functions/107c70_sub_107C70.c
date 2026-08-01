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

extern uint32_t off_107F30;
extern uint32_t off_107F64;
extern uint32_t off_107F34;
extern uint32_t off_107F6C;
extern uint32_t off_107F38;
extern uint32_t off_107F70;
extern uint32_t off_107F74;
extern uint32_t off_107F68;
extern uint32_t off_107F3C;
extern uint32_t off_107F40;
extern uint32_t off_107F44;
extern uint32_t off_107F48;
extern uint32_t off_107F4C;
extern uint32_t off_107F50;
extern uint32_t off_107F54;
extern uint32_t off_107F58;
extern uint32_t off_107F5C;
extern uint32_t off_107F60;
extern uint32_t dword_10829C;
extern uint32_t off_1082A0;
extern uint32_t off_1082A4;
extern uint32_t off_1082E4;
extern uint32_t off_1082E8;
extern uint32_t off_1082EC;
extern uint32_t dword_1082A8;
extern uint32_t dword_1082AC;
extern uint32_t dword_1082B0;
extern uint32_t dword_1082B4;
extern uint32_t dword_1082F0;
extern uint32_t dword_1082BC;
extern uint32_t dword_1082B8;
extern uint32_t off_1082C0;
extern uint32_t dword_1082C4;
extern uint32_t dword_108CA8;
extern uint32_t dword_1082C8;
extern uint32_t dword_1082CC;
extern uint32_t dword_1082D0;
extern uint32_t dword_1082D4;
extern uint32_t dword_1082D8;
extern uint32_t dword_1082DC;
extern uint32_t dword_108CB0;
extern uint32_t dword_1082E0;
extern uint32_t dword_1085DC;
extern uint32_t dword_1085E0;
extern uint32_t dword_1085E4;
extern uint32_t dword_1085E8;
extern uint32_t dword_1085EC;
extern uint32_t off_1085F0;
extern uint32_t off_1085F4;
extern uint32_t off_1085F8;
extern uint32_t dword_108CAC;
extern uint32_t dword_10896C;
extern uint32_t dword_108968;
extern uint32_t dword_108970;
extern uint32_t dword_108974;
extern uint32_t dword_108978;
extern uint32_t off_108980;
extern uint32_t off_108984;
extern uint32_t off_10897C;
extern uint32_t dword_108CB4;
extern uint32_t dword_108988;
extern uint32_t dword_10898C;
extern uint32_t dword_108990;
extern uint32_t off_108994;
extern uint32_t off_108998;
extern uint32_t off_1089C0;
extern uint32_t off_1089C4;
extern uint32_t off_1089C8;
extern uint32_t off_1089CC;
extern uint32_t off_10899C;
extern uint32_t off_1089A0;
extern uint32_t off_1089A4;
extern uint32_t off_1089A8;
extern uint32_t off_1089AC;
extern uint32_t dword_1089B0;
extern uint32_t off_1089B4;
extern uint32_t off_1089B8;
extern uint32_t off_1089BC;
extern uint32_t off_108C9C;
extern uint32_t off_108CA0;
extern uint32_t off_108CA4;
extern uint32_t dword_108600;
extern uint32_t dword_1085FC;
extern uint32_t dword_108608;
extern uint32_t off_108604;
extern uint32_t dword_10860C;
extern uint32_t dword_108610;
extern uint32_t off_108614;
extern uint32_t dword_108618;
extern uint32_t dword_10861C;
extern uint32_t off_108620;
extern uint32_t dword_108624;
extern uint32_t off_108628;
extern uint32_t dword_10862C;

// rf_transmit_packet @ 0x107c70, size 4140 bytes
uint32_t * rf_transmit_packet(int a1, unsigned int *a2, int a3, unsigned int a4, unsigned int a5, int a6, int16_t a7)
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
  int v26; // r2
  int v27; // r3
  int v28; // r0
  uint32_t *v29; // r3
  int *v30; // r0
  int v31; // r2
  unsigned int *v32; // r9
  int *v33; // r11
  int *v34; // r10
  int v35; // r1
  int v36; // r2
  int v37; // s16
  unsigned int *v38; // r3
  int v39; // r4
  int v40; // r3
  int v41; // r7
  int v42; // r8
  int v43; // r1
  int v44; // r4
  int v45; // r3
  int v46; // r3
  int v47; // r4
  int i; // r6
  int v49; // r5
  int v50; // r3
  int v51; // r2
  unsigned int v52; // r2
  int v53; // r3
  int v54; // r6
  int v55; // r2
  int v56; // r3
  int v57; // r1
  int v58; // r6
  int v59; // r5
  int v60; // r3
  int v61; // r3
  signed int v62; // r6
  signed int v63; // r5
  int v64; // r2
  int v65; // r3
  unsigned int v66; // r6
  int v67; // r5
  int v68; // r2
  int v69; // r1
  int v70; // r6
  int v71; // r2
  int v72; // r3
  int *v73; // r0
  unsigned int *v74; // r1
  unsigned int *v75; // r3
  int v76; // r2
  int v77; // r5
  int v78; // r4
  int v79; // r2
  int v80; // r2
  int v81; // r7
  uint64_t v82; // kr00_8
  int v83; // r6
  int v84; // r10
  int v85; // r0
  int v86; // r9
  int v87; // r0
  unsigned int *v88; // r1
  int *v89; // r2
  int v90; // r0
  int *v91; // r4
  uint32_t *result; // r0
  int v93; // r1
  int v94; // r2
  int v95; // r4
  int v96; // r3
  int v97; // r5
  signed int v98; // r6
  signed int v99; // r4
  unsigned int *v100; // r1
  unsigned int *v101; // r3
  unsigned int v102; // r2
  int v103; // cc
  int v104; // r1
  int v105; // r3
  unsigned int *v106; // r1
  unsigned int *v107; // r0
  unsigned int *v108; // r11
  unsigned int *v109; // r12
  uint32_t *v110; // r10
  uint32_t *v111; // r9
  unsigned int *v112; // r3
  unsigned int *v113; // r2
  unsigned int *v114; // r4
  unsigned int *v115; // r0
  unsigned int *v116; // r1
  int v117; // r6
  uint32_t *v118; // r7
  unsigned int *v119; // r2
  uint32_t *v120; // r5
  uint32_t *v121; // r5
  unsigned int *v122; // r1
  int v123; // r2
  int v124; // [sp+0h] [bp-1F4h]
  int v125; // [sp+8h] [bp-1ECh]
  unsigned int v126; // [sp+8h] [bp-1ECh]
  int v127; // [sp+8h] [bp-1ECh]
  int v128; // [sp+Ch] [bp-1E8h]
  int v129; // [sp+10h] [bp-1E4h]
  int v130; // [sp+14h] [bp-1E0h]
  int v131; // [sp+18h] [bp-1DCh]
  int v132; // [sp+1Ch] [bp-1D8h]
  int *v133; // [sp+20h] [bp-1D4h]
  int v134; // [sp+24h] [bp-1D0h]
  int v135; // [sp+28h] [bp-1CCh]
  int v136; // [sp+2Ch] [bp-1C8h]
  int v137; // [sp+30h] [bp-1C4h]
  int v138; // [sp+34h] [bp-1C0h]
  int v139; // [sp+38h] [bp-1BCh]
  int v140; // [sp+3Ch] [bp-1B8h]
  int v141; // [sp+40h] [bp-1B4h]
  int v142; // [sp+44h] [bp-1B0h]
  unsigned int v143; // [sp+48h] [bp-1ACh]
  int v144; // [sp+4Ch] [bp-1A8h]
  unsigned int v145; // [sp+50h] [bp-1A4h]
  int v146; // [sp+54h] [bp-1A0h]
  int v147; // [sp+58h] [bp-19Ch]
  int v148; // [sp+5Ch] [bp-198h]
  int v149; // [sp+60h] [bp-194h]
  int v150; // [sp+64h] [bp-190h]
  int v151; // [sp+68h] [bp-18Ch]
  int v152; // [sp+6Ch] [bp-188h]
  int v153; // [sp+70h] [bp-184h]
  int v154; // [sp+74h] [bp-180h]
  int v155; // [sp+78h] [bp-17Ch]
  int v156; // [sp+7Ch] [bp-178h]
  int v157; // [sp+80h] [bp-174h]
  int v158; // [sp+84h] [bp-170h]
  int v159; // [sp+88h] [bp-16Ch]
  int v160; // [sp+8Ch] [bp-168h]
  int v161; // [sp+90h] [bp-164h]
  int v162; // [sp+94h] [bp-160h]
  unsigned int v163; // [sp+98h] [bp-15Ch]
  int v164; // [sp+9Ch] [bp-158h]
  unsigned int v165; // [sp+A0h] [bp-154h]
  int v166; // [sp+A4h] [bp-150h]
  unsigned int v167; // [sp+A8h] [bp-14Ch]
  int v168; // [sp+ACh] [bp-148h]
  unsigned int v169; // [sp+B0h] [bp-144h]
  int v170; // [sp+B4h] [bp-140h]
  unsigned int v171; // [sp+B8h] [bp-13Ch]
  unsigned int v172; // [sp+BCh] [bp-138h]
  int v173; // [sp+C0h] [bp-134h]
  int v174; // [sp+C4h] [bp-130h]
  int v175; // [sp+C8h] [bp-12Ch]
  int v176; // [sp+CCh] [bp-128h]
  int v177; // [sp+D0h] [bp-124h]
  int v178; // [sp+D4h] [bp-120h]
  int v179; // [sp+D8h] [bp-11Ch]
  int v180; // [sp+DCh] [bp-118h]
  int v181; // [sp+E0h] [bp-114h]
  int v182; // [sp+E4h] [bp-110h]
  int v183; // [sp+E8h] [bp-10Ch]
  int v184; // [sp+ECh] [bp-108h]
  int v185; // [sp+F0h] [bp-104h]
  int v187; // [sp+F8h] [bp-FCh]
  int v188; // [sp+FCh] [bp-F8h]
  unsigned int *v190; // [sp+104h] [bp-F0h]
  uint32_t v191[3]; // [sp+108h] [bp-ECh]
  unsigned int v192[4]; // [sp+114h] [bp-E0h] BYREF
  int v193; // [sp+124h] [bp-D0h] BYREF
  int v194; // [sp+128h] [bp-CCh]
  int v195; // [sp+12Ch] [bp-C8h]
  uint64_t v196; // [sp+130h] [bp-C4h]
  unsigned int v197; // [sp+150h] [bp-A4h]
  uint32_t v198[10]; // [sp+154h] [bp-A0h] BYREF
  char v199; // [sp+17Ch] [bp-78h] BYREF
  int v200; // [sp+18Ch] [bp-68h]
  int v201; // [sp+198h] [bp-5Ch] BYREF
  int v202; // [sp+19Ch] [bp-58h]
  int v203; // [sp+1A0h] [bp-54h]
  int v204; // [sp+1A4h] [bp-50h]

  v7 = (int *)off_107F30;
  v8 = (unsigned int *)off_107F64;
  v9 = (unsigned int *)off_107F34;
  v10 = off_107F6C;
  v11 = (int *)off_107F38;
  v12 = (unsigned int *)off_107F70;
  v13 = (int *)off_107F74;
  v185 = *(uint32_t *)off_107F68;
  v184 = *(uint32_t *)off_107F30;
  v183 = *(uint32_t *)off_107F30;
  v182 = *(uint32_t *)off_107F64;
  v181 = *(uint32_t *)off_107F34;
  v180 = *(uint32_t *)off_107F34;
  v179 = *(uint32_t *)off_107F34;
  v178 = *(uint32_t *)off_107F34;
  v177 = *(uint32_t *)off_107F6C;
  v176 = *(uint32_t *)off_107F6C;
  v175 = *(uint32_t *)off_107F38;
  v174 = *(uint32_t *)off_107F30;
  v173 = *(uint32_t *)off_107F30;
  *(uint32_t *)off_107F68 = *(uint32_t *)off_107F68 & 0xF8FFFFFF | 0x1000000;
  v14 = (int *)off_107F3C;
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
  v172 = *v12;
  v171 = *v12;
  v170 = *(uint32_t *)off_107F40;
  v169 = *(uint32_t *)off_107F40;
  v168 = *(uint32_t *)off_107F44;
  v167 = *(uint32_t *)off_107F44;
  v166 = *(uint32_t *)off_107F48;
  v165 = *(uint32_t *)off_107F48;
  v164 = *(uint32_t *)off_107F4C;
  v163 = *(uint32_t *)off_107F4C;
  v162 = *v13;
  v161 = *v13;
  v160 = *v13;
  v159 = *v13;
  v158 = *v13;
  v157 = *v11;
  v156 = *v11;
  v155 = *v14;
  v154 = *v14;
  v153 = *v14;
  v152 = *v14;
  v151 = *v7;
  v150 = *v7;
  v149 = *v7;
  v148 = *v7;
  v147 = *(uint32_t *)off_107F50;
  v146 = *(uint32_t *)off_107F54;
  v145 = *v8;
  v144 = *(uint32_t *)off_107F58;
  v143 = *v8;
  v142 = *(uint32_t *)off_107F5C;
  v141 = *(uint32_t *)off_107F60;
  v139 = *v7;
  v140 = *v7;
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
  v17 = off_107F3C;
  *(uint32_t *)off_107F3C &= ~0x100000u;
  *(uint32_t *)v17 |= 0x200000u;
  LOBYTE(v17) = 60;
  do
    v17 = (void *)(uint8_t)((uint8_t)v17 - 1);
  while ( v17 );
  v18 = off_107F30;
  *(uint32_t *)off_107F3C |= 0x100000u;
  *(uint32_t *)v18 |= 0x20000u;
  *(uint32_t *)v18 |= 0x10000u;
  LOBYTE(v18) = 90;
  do
    v18 = (void *)(uint8_t)((uint8_t)v18 - 1);
  while ( v18 );
  v19 = off_107F30;
  *(uint32_t *)off_107F30 &= ~0x40000u;
  *(uint32_t *)v19 |= 0x80000u;
  LOBYTE(v19) = 60;
  do
    v19 = (void *)(uint8_t)((uint8_t)v19 - 1);
  while ( v19 );
  v20 = off_107F30;
  *(uint32_t *)off_107F30 |= 0x40000u;
  *v20 |= 0x8000u;
  *v20 |= 0x4000u;
  LOBYTE(v21) = 90;
  do
    v21 = (uint8_t)(v21 - 1);
  while ( v21 );
  v22 = off_107F50;
  v23 = off_107F54;
  v24 = (unsigned int *)off_107F64;
  *(uint32_t *)off_107F50 |= 0x40000u;
  *v23 |= 0x3000u;
  v25 = off_107F30;
  *v24 = *v24 & 0xFFFFFFFC | 1;
  v22[16] = v22[16] & 0xFFE3FFFF | 0xC0000;
  *v24 |= 4u;
  *v25 |= 0x800000u;
  *v25 |= 0x400000u;
  disable_bb_timer_irq();
  check_interrupt_flag(1, dword_10829C, v26, v27);
  v138 = *(uint32_t *)off_1082A0;
  *(uint32_t *)off_1082A0 = *(uint32_t *)off_1082A0 & 0xFFFFFFF | 0x10000000;
  do
  {
    enable_rf_dll(v21, 0);
    v28 = (uint8_t)(v21 + 1);
    v21 = (uint8_t)(v21 + 2);
    enable_rf_dll(v28, 0);
  }
  while ( v21 != 32 );
  v29 = off_1082A4;
  *(uint32_t *)off_1082A4 &= ~0x200u;
  *v29 |= 0x200u;
  *v29 &= ~0x200u;
  v30 = clk_enable();
  if ( a3 == 255 )
  {
    v32 = (unsigned int *)off_1082E4;
    v33 = (int *)off_1082E8;
    v34 = (int *)off_1082EC;
    v35 = *(uint32_t *)(dword_1082A8 + 4);
    v36 = *(uint32_t *)(dword_1082A8 + 8);
    v191[0] = *(uint32_t *)dword_1082A8;
    v191[1] = v35;
    v191[2] = v36;
    memset(v192, 0, sizeof(v192));
    v37 = 0;
    v134 = 6;
    do
    {
      if ( v37 )
      {
        if ( v37 == 1 )
        {
          v194 = 24;
          v38 = a2 + 1;
          v39 = 1;
          v190 = a2 + 1;
        }
        else
        {
          v194 = 15;
          v38 = a2;
          v190 = a2;
          v39 = 0;
        }
      }
      else
      {
        v194 = 15;
        v38 = a2 + 2;
        v190 = a2 + 2;
        v39 = 2;
      }
      check_interrupt_flag(1, dword_1082AC, v37, v38);
      mac_get_params(a2[v37], v198);
      check_interrupt_flag(1, dword_1082B0, v200, v40);
      if ( v200 <= 0 )
      {
        v131 = v191[v39];
      }
      else
      {
        v188 = v39;
        v132 = 2 * (4 * v39 + 1);
        v187 = v39 << 12;
        v41 = dword_1082B4;
        v42 = dword_1082F0;
        v131 = v191[v39];
        v130 = a1 + 32 * v39;
        v133 = (int *)&v199;
        v136 = 0;
        v137 = v134 << 8;
        do
        {
          v43 = dword_1082BC;
          v44 = dword_1082B8 | v187 | (*v133 << 8);
          *(uint32_t *)off_1082C0 = v44;
          v45 = *v133++;
          check_interrupt_flag(1, v43, v37, v45);
          check_interrupt_flag(1, dword_1082C4, v44, v46);
          v195 = 0;
          load_patch_bundle((int)&v193);
          v47 = v134;
          for ( i = v137; ; i = v47 << 8 )
          {
            *v32 = i & 0xF00 | *v32 & 0xFFFFF0FF;
            *v33 &= v41;
            *v33 &= v42;
            *v34 &= v41;
            *v34 &= v42;
            rf_core_irq_poll((int)&v193);
            rf_clear_irq_flag();
            rf_get_cca_status();
            rf_core_irq_dispatch((int)&v193);
            rf_clear_irq_flag_alt();
            rf_get_rx_rssi();
            v49 = *v34 & 0xFFF;
            v50 = (*v34 & 0x8000000) != 0 ? (HIWORD(*v34) & 0xFFF) - 4096 : HIWORD(*v34) & 0xFFF;
            v51 = (*v34 & 0x800) != 0 ? v49 - 4096 : *v34 & 0xFFF;
            if ( v50 <= 1024 && v51 <= 1024 )
              break;
            v123 = v47;
            v47 = (uint8_t)(v47 - 1);
            check_interrupt_flag(1, dword_108CA8, v123, v50);
          }
          v134 = v47;
          v52 = *v32 & 0xFFFFF0FF;
          v53 = ((v47 + 1) << 8) & 0xF00 | v52;
          v137 = i;
          v54 = HIWORD(*v34) & 0xFFF;
          *v32 = v53;
          check_interrupt_flag(1, dword_1082C8, v52, v53);
          *v34 = dword_1082CC & (v54 << 17) | *v34 & v41;
          rf_core_irq_poll((int)&v193);
          rf_clear_irq_flag();
          rf_get_cca_status();
          check_interrupt_flag(1, dword_1082D0, v55, v56);
          *v34 = (2 * v49) & 0xFFF | *v34 & v42;
          rf_core_irq_dispatch((int)&v193);
          rf_clear_irq_flag_alt();
          rf_get_rx_rssi();
          v57 = dword_1082D4;
          v58 = HIWORD(*v34) & 0xFFF;
          v59 = *v34 & 0xFFF;
          v60 = v59 + (v58 << 16);
          *(uint32_t *)(v130 + 8) = v60;
          v61 = v60 | (*v32 >> 8 << 28);
          *(uint32_t *)(v130 + 8) = v61;
          v125 = v58 << 16;
          check_interrupt_flag(1, v57, v132, v61);
          *v34 &= v41;
          *v34 &= v42;
          gpio_output((int)&v193, 1);
          v192[0] = v197;
          timer_delta_compare(v192, (int)&v193);
          pinmux_config((int)&v193, 1);
          v62 = v197;
          check_interrupt_flag(1, dword_1082D8, HIWORD(*v34) & 0xFFF, *v34 & 0xFFF);
          *v34 = *v34 & v41 | v125;
          *v34 = v59 | *v34 & v42;
          pinmux_config((int)&v193, 1);
          v63 = v197;
          check_interrupt_flag(1, dword_1082DC, HIWORD(*v34) & 0xFFF, *v34 & 0xFFF);
          if ( v62 <= v63 )
          {
            check_interrupt_flag(1, dword_108CB0, v64, v65);
            v131 = 0;
            *(uint32_t *)(v130 + 8) = 0;
          }
          else
          {
            v131 &= 1u;
            check_interrupt_flag(1, dword_1082E0, v64, v131);
          }
          v66 = *v32;
          v126 = *v34;
          v67 = *v34;
          v68 = *(v133 - 1);
          v191[v188] = v131;
          check_interrupt_flag(1, dword_1085DC, v68, v37);
          check_interrupt_flag(1, dword_1085E0, (v67 & 0xFFF) + ((HIWORD(v126) & 0xFFF) << 16) + (v66 >> 8 << 28), v126);
          v69 = dword_1085E4;
          v70 = dword_1085E8;
          *v34 = *v34 & v41 | ((*(uint16_t *)(v130 + 10) & 0xFFF) << 16);
          *v34 = *(uint32_t *)(v130 + 8) & 0xFFF | *v34 & v42;
          check_interrupt_flag(1, v69, HIWORD(*v34) & 0xFFF, *v34 & 0xFFF);
          check_interrupt_flag(1, dword_1085EC, v71, v72);
          v73 = (int *)off_1085F0;
          v74 = (unsigned int *)off_1085F4;
          v75 = (unsigned int *)off_1085F8;
          *v32 &= ~0x40000000u;
          *v32 &= 0xCFFFFFFF;
          v76 = *v73 & v42;
          v198[6] = 1;
          v201 = 600;
          v202 = 600;
          v203 = 0;
          v204 = 0;
          v193 = 0;
          *v73 = v76 | 0x300;
          *v74 = *v74 & 0xFFFFFF8F | 0x50;
          *v75 = *v75 & 0xFFF0FFFF | 0x10000;
          *v75 = *v75 & 0xFFFF0FFF | 0x1000;
          *v75 = *v75 & 0xFFFFF0FF | 0x100;
          *v75 = *v75 & 0xFFFFFF0F | 0x20;
          *v75 = *v75 & 0xFFFFFFF0 | 3;
          v195 = 10;
          v77 = 0;
          load_patch_bundle((int)&v193);
          v135 = 0;
          do
          {
            while ( 1 )
            {
              v128 = v201;
              v129 = v202;
              v78 = v203;
              v127 = v204;
              v193 = v77;
              timer_ticks_to_micros(&v201);
              rf_core_set_clock_override((int)&v201, &v193);
              rx_queue_pop_packet((int)&v193, &v201, v198);
              v79 = v77;
              if ( v77 )
                break;
              if ( v196 )
              {
                v78 = v203;
                v80 = 0;
                v77 = 1;
              }
              else
              {
                check_interrupt_flag(1, dword_108CAC, HIDWORD(v196), v196 | HIDWORD(v196));
                ++v135;
                v195 += 6;
                load_patch_bundle((int)&v193);
                v201 = v128;
                v202 = v129;
                v203 = v78;
                v204 = v127;
                v80 = -(v135 <= 2);
                v77 = v135 > 2;
              }
              check_interrupt_flag(1, v70, v80, v78);
            }
            ++v77;
            check_interrupt_flag(1, v70, v79, v203);
          }
          while ( v77 != 5 );
          v93 = dword_10896C;
          v94 = (*v32 >> 12) & 7;
          v95 = dword_108968 & (v204 << 16);
          v96 = HIWORD(*v32) & 7;
          v97 = v203 & 0xFFF;
          *(uint32_t *)(v130 + 12) = v95 + (v94 << 28) + (v96 << 12) + v97;
          check_interrupt_flag(1, v93, v94, v96);
          check_interrupt_flag(1, dword_108970, v132 + 1, *(uint32_t *)(v130 + 12));
          *v33 &= v41;
          *v33 &= v42;
          gpio_output((int)&v193, 0);
          v192[0] = v197;
          timer_delta_compare(v192, (int)&v193);
          pinmux_config((int)&v193, 0);
          v98 = v197;
          check_interrupt_flag(1, dword_108974, *v33 & 0xFFF, HIWORD(*v33) & 0xFFF);
          *v33 = v95 | *v33 & v41;
          *v33 = v97 | *v33 & v42;
          pinmux_config((int)&v193, 0);
          v99 = v197;
          check_interrupt_flag(1, dword_108978, *v33 & 0xFFF, HIWORD(*v33) & 0xFFF);
          v100 = (unsigned int *)off_108980;
          v101 = (unsigned int *)off_108984;
          *(uint32_t *)off_10897C = *(uint32_t *)off_10897C & v42 | 0xC0;
          *v100 = *v100 & 0xFFFFFF8F | 0x40;
          *v101 = *v101 & 0xFFF0FFFF | 0x10000;
          *v101 = *v101 & 0xFFFF0FFF | 0x1000;
          *v101 = *v101 & 0xFFFFF0FF | 0x100;
          *v101 = *v101 & 0xFFFFFF0F | 0x10;
          v102 = *v101 & 0xFFFFFFF0 | 1;
          *v101 = v102;
          if ( v98 <= v99 )
          {
            check_interrupt_flag(1, dword_108CB4, v102, v101);
            *(uint32_t *)(v130 + 12) = 0;
          }
          else
          {
            check_interrupt_flag(1, dword_108988, v102, v101);
          }
          v130 += 8;
          v103 = v200 <= ++v136;
          v132 += 2;
        }
        while ( !v103 );
      }
      v104 = dword_10898C;
      *v190 = *v190 & 0xFFFDFFFF | (v131 << 17);
      check_interrupt_flag(1, v104, v37, v131);
      check_interrupt_flag(1, dword_108990, *v190, v105);
      ++v37;
    }
    while ( v37 != 3 );
    clk_disable();
    v106 = (unsigned int *)off_108994;
    v107 = (unsigned int *)off_108998;
    v108 = (unsigned int *)off_1089C0;
    v109 = (unsigned int *)off_1089C4;
    v110 = off_1089C8;
    v111 = off_1089CC;
    *(uint32_t *)off_108994 = v157 & 0x8000 | *(uint32_t *)off_108994 & 0xFFFF7FFF;
    v112 = (unsigned int *)off_10899C;
    *v106 = v156 & 0x7000 | *v106 & 0xFFFF8FFF;
    v113 = (unsigned int *)off_1089A0;
    *v107 = v185 & 0x7000000 | *v107 & 0xF8FFFFFF;
    *v106 = *v106 & 0xFFFFF7FF | v175 & 0x800;
    v114 = (unsigned int *)off_1089A4;
    *v112 = *v112 & 0xFFFBFFFF | v173 & 0x40000;
    v115 = (unsigned int *)off_1089A8;
    *v112 = *v112 & 0xFFF7FFFF | v174 & 0x80000;
    v116 = (unsigned int *)off_1089AC;
    *v113 = *v113 & 0xFF7FFFFF | v155 & 0x800000;
    *v113 = *v113 & 0xFFBFFFFF | v154 & 0x400000;
    v117 = dword_1089B0;
    *v113 = *v113 & 0xFFEFFFFF | v153 & 0x100000;
    *v113 = v152 & 0x200000 | *v113 & 0xFFDFFFFF;
    v118 = off_1089B4;
    *v112 = v151 & 0x20000 | *v112 & 0xFFFDFFFF;
    *v112 = v150 & 0x10000 | *v112 & 0xFFFEFFFF;
    *v112 = v149 & 0x8000 | *v112 & 0xFFFF7FFF;
    v119 = (unsigned int *)off_108984;
    *v112 = v148 & 0x4000 | *v112 & 0xFFFFBFFF;
    v120 = off_1089B8;
    *v108 = v147 & 0x40000 | *v108 & 0xFFFBFFFF;
    *(uint32_t *)off_1089B8 = v146 & 0x3000 | *v120 & 0xFFFFCFFF;
    v121 = off_1089BC;
    *v114 = v145 & 3 | *v114 & 0xFFFFFFFC;
    *(uint32_t *)off_1089BC = v144 & 0x1C0000 | *v121 & 0xFFE3FFFF;
    *v114 = v143 & 4 | *v114 & 0xFFFFFFFB;
    *v112 = v140 & 0x800000 | *v112 & 0xFF7FFFFF;
    *v112 = v139 & 0x400000 | *v112 & 0xFFBFFFFF;
    *v112 = v184 & 0x200000 | *v112 & 0xFFDFFFFF;
    *v112 = v183 & 0x100000 | *v112 & 0xFFEFFFFF;
    *v114 = v182 & 0xF0 | *v114 & 0xFFFFFF0F;
    *v115 = v181 & 0x80 | *v115 & 0xFFFFFF7F;
    *v115 = v180 & 0x70 | *v115 & 0xFFFFFF8F;
    *v115 = v179 & 0x400 | *v115 & 0xFFFFFBFF;
    *v115 = v178 & 0x300 | *v115 & 0xFFFFFCFF;
    *v116 = *v116 & 0xFFBFFFFF | v177 & 0x400000;
    *v116 = *v116 & 0xFFDFFFFF | v176 & 0x200000;
    result = off_108C9C;
    *v116 &= 0xFFFE00FF;
    *v116 &= ~0x20000u;
    *v116 |= 0x40000u;
    *v109 = *v109 & v117 | v172 & 0x3FFF;
    *v109 = *v109 & 0xC000FFFF | ((HIWORD(v171) & 0x3FFF) << 16);
    *v118 = *v118 & v117 | v170 & 0x3FFF;
    *v118 = *v118 & 0xC000FFFF | ((HIWORD(v169) & 0x3FFF) << 16);
    *result = *result & v117 | v168 & 0x3FFF;
    *result = *result & 0xC000FFFF | ((HIWORD(v167) & 0x3FFF) << 16);
    *v110 = *v110 & v117 | v166 & 0x3FFF;
    *v110 = *v110 & 0xC000FFFF | ((HIWORD(v165) & 0x3FFF) << 16);
    *v111 = v117 & *v111 | v164 & 0x3FFF;
    *v111 = *v111 & 0xC000FFFF | ((HIWORD(v163) & 0x3FFF) << 16);
    *v119 = v162 & 0xF0000 | *v119 & 0xFFF0FFFF;
    *v119 = v161 & 0xF000 | *v119 & 0xFFFF0FFF;
    *v119 = v160 & 0xF00 | *v119 & 0xFFFFF0FF;
    *v119 = v159 & 0xF0 | *v119 & 0xFFFFFF0F;
    v122 = (unsigned int *)off_108CA0;
    *v119 = *v119 & 0xFFFFFFF0 | v158 & 0xF;
    *v122 = *v122 & 0x7FFFFFFF | v142 & 0x80000000;
    *(uint32_t *)off_108CA4 = v141;
    *(v108 - 19976) = *(unsigned int *)((char *)v108 + 0xFFFFFFE0 - 79872) & 0xFFFFFFF | v138 & 0xF0000000;
  }
  else
  {
    v81 = dword_108600;
    v82 = dword_1085FC * (uint64_t)a3;
    v83 = (SHIDWORD(v82) >> 5) - (a3 >> 31);
    v84 = a3 - 100 * v83;
    poll_rf_status((int)v30, SHIDWORD(v82), v31, 100, v124);
    v85 = dword_108608;
    *(uint32_t *)off_108604 &= ~1u;
    v194 = 30;
    v195 = v83;
    dispatch_event_handler(v85, v83);
    v86 = HIWORD(v15) & 0xFFF;
    dispatch_event_handler(dword_10860C, v84);
    dispatch_event_handler(dword_108610, v86);
    *(uint32_t *)off_108614 = a6;
    dispatch_event_handler(dword_108618, a6);
    v87 = dword_10861C;
    *(uint32_t *)off_1085F0 = *(uint32_t *)off_1085F0 & v81 | a7 & 0xFFF;
    dispatch_event_handler(v87, a7);
    set_system_mode(v84);
    v88 = (unsigned int *)off_1085F8;
    v89 = (int *)off_108620;
    v90 = dword_108624;
    v91 = (int *)off_108628;
    *(uint32_t *)off_1085F8 = *(uint32_t *)off_1085F8 & 0xFFF0FFFF | 0x10000;
    *v88 = *v88 & 0xFFFF0FFF | 0x1000;
    *v88 = *v88 & 0xFFFFF0FF | 0x100;
    *v88 = *v88 & 0xFFFFFF0F | 0x20;
    *v88 = *v88 & 0xFFFFFFF0 | 3;
    *v89 = *v89 & v90 | (v86 << 16);
    *v89 = v15 & 0xFFF | *v89 & v81;
    *v91 = *v91 & v90 | ((HIWORD(a5) & 0xFFF) << 16);
    *v91 = a5 & 0xFFF | *v91 & v81;
    clk_set_divider();
    load_patch_bundle((int)&v193);
    pinmux_config((int)&v193, 0);
    check_interrupt_flag(1, dword_10862C, *v91 & 0xFFF, HIWORD(*v91) & 0xFFF);
    pinmux_config((int)&v193, 0);
    check_interrupt_flag(1, dword_10862C, *v91 & 0xFFF, HIWORD(*v91) & 0xFFF);
    write_timer_reg(500);
    return (uint32_t *)enable_bb_clock();
  }
  return result;
}

