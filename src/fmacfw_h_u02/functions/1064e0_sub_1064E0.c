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


extern uint32_t dword_106FF0;
extern uint32_t dword_106FF4;
extern uint32_t dword_106FF8;
extern uint32_t dword_10707C;
extern uint32_t dword_107080;
extern uint32_t off_1067C0;
extern uint32_t off_1067C4;
extern uint32_t off_1067C8;
extern uint32_t off_1067CC;
extern uint32_t off_1067D0;
extern uint32_t off_1067D4;
extern uint32_t off_1067D8;
extern uint32_t off_1067DC;
extern uint32_t off_1067E0;
extern uint32_t off_1067E4;
extern uint32_t off_1067E8;
extern uint32_t off_1067EC;
extern uint32_t off_1067F0;
extern uint32_t off_1067F4;
extern uint32_t off_1067F8;
extern uint32_t off_106980;
extern uint32_t off_106984;
extern uint32_t off_106988;
extern uint32_t off_10698C;
extern uint32_t off_106990;
extern uint32_t off_106994;
extern uint32_t off_106998;
extern uint32_t off_10699C;
extern uint32_t off_106CC0;
extern uint32_t off_106CC4;
extern uint32_t off_106CC8;
extern uint32_t off_106CCC;
extern uint32_t off_106CD0;
extern uint32_t off_106CD4;
extern uint32_t off_106CD8;
extern uint32_t off_106CDC;
extern uint32_t off_106CE0;
extern uint32_t off_106CE4;
extern uint32_t off_106CE8;
extern uint32_t off_106CEC;
extern uint32_t off_106CF0;
extern uint32_t off_106CF4;
extern uint32_t off_106FE8;
extern uint32_t off_106FEC;
extern uint32_t off_107008;
extern uint32_t off_107010;
extern uint32_t off_107078;

// phy_read_table @ 0x1064e0, size 2964 bytes
int  phy_read_table(unsigned int a1, int a2, uint16_t *a3, int a4, int a5, int a6, int a7)
{
  uint32_t *v7; // r9
  unsigned int *v8; // r8
  unsigned int *v9; // r10
  unsigned int *v10; // r4
  unsigned int *v11; // lr
  unsigned int *v12; // r7
  unsigned int *v13; // r12
  unsigned int *v14; // r5
  unsigned int *v15; // r6
  unsigned int v16; // r9
  unsigned int v17; // r8
  unsigned int v18; // r7
  int v19; // r6
  void *v23; // r3
  void *v24; // r3
  void *v25; // r3
  uint32_t *v26; // r3
  int v27; // r7
  uint32_t *v28; // r0
  uint32_t *v29; // r2
  unsigned int *v30; // r1
  uint32_t *v31; // r5
  uint32_t *v32; // r2
  uint32_t *v33; // r2
  uint16_t *v34; // r9
  uint32_t *v35; // r8
  int v36; // r7
  int v37; // r3
  int v38; // t1
  int v39; // r2
  int v40; // r1
  int v41; // r5
  uint32_t *v42; // r6
  uint32_t *v43; // r9
  int v44; // r2
  unsigned int *v45; // r4
  unsigned int *v46; // r5
  unsigned int *v47; // r9
  unsigned int *v48; // r11
  uint32_t *v49; // r8
  uint32_t *v50; // r1
  unsigned int *v51; // r2
  unsigned int *v52; // r12
  unsigned int *v53; // r3
  unsigned int *v54; // r6
  unsigned int *v55; // r0
  unsigned int *v56; // r7
  unsigned int *v57; // r2
  uint32_t *v58; // r10
  unsigned int v60; // r3
  int v61; // r8
  int v62; // r9
  int v63; // r11
  unsigned int v64; // r2
  int v65; // r7
  int v66; // r6
  unsigned int v67; // r5
  int v68; // r3
  int v69; // r7
  int *v70; // r6
  uint32_t *v71; // r7
  int v72; // r9
  int v73; // r11
  int v74; // r8
  unsigned int *v75; // r6
  unsigned int v76; // r5
  int v77; // r5
  char v78; // r3
  int v79; // r6
  int *v80; // r3
  int *v81; // r12
  int *v82; // r2
  int v83; // r0
  int *v84; // r1
  unsigned int v85; // [sp+Ch] [bp-C8h]
  char v86; // [sp+Ch] [bp-C8h]
  int v87; // [sp+Ch] [bp-C8h]
  unsigned int v88; // [sp+10h] [bp-C4h]
  int v89; // [sp+10h] [bp-C4h]
  unsigned int v90; // [sp+14h] [bp-C0h]
  int v91; // [sp+14h] [bp-C0h]
  unsigned int v92; // [sp+18h] [bp-BCh]
  int v93; // [sp+18h] [bp-BCh]
  unsigned int v94; // [sp+1Ch] [bp-B8h]
  int v95; // [sp+1Ch] [bp-B8h]
  unsigned int v96; // [sp+20h] [bp-B4h]
  int v97; // [sp+20h] [bp-B4h]
  unsigned int v98; // [sp+24h] [bp-B0h]
  int v99; // [sp+24h] [bp-B0h]
  unsigned int v100; // [sp+28h] [bp-ACh]
  int v101; // [sp+28h] [bp-ACh]
  unsigned int v102; // [sp+2Ch] [bp-A8h]
  int v103; // [sp+2Ch] [bp-A8h]
  unsigned int v104; // [sp+30h] [bp-A4h]
  int v105; // [sp+30h] [bp-A4h]
  unsigned int v106; // [sp+34h] [bp-A0h]
  int v107; // [sp+34h] [bp-A0h]
  unsigned int v108; // [sp+38h] [bp-9Ch]
  int v109; // [sp+38h] [bp-9Ch]
  unsigned int v110; // [sp+3Ch] [bp-98h]
  int v111; // [sp+3Ch] [bp-98h]
  unsigned int v112; // [sp+40h] [bp-94h]
  int v113; // [sp+40h] [bp-94h]
  unsigned int v114; // [sp+44h] [bp-90h]
  int v115; // [sp+44h] [bp-90h]
  unsigned int v116; // [sp+48h] [bp-8Ch]
  int v117; // [sp+48h] [bp-8Ch]
  unsigned int v118; // [sp+4Ch] [bp-88h]
  int v119; // [sp+4Ch] [bp-88h]
  unsigned int v120; // [sp+50h] [bp-84h]
  int v121; // [sp+50h] [bp-84h]
  unsigned int v122; // [sp+54h] [bp-80h]
  int v123; // [sp+54h] [bp-80h]
  unsigned int v124; // [sp+58h] [bp-7Ch]
  int v125; // [sp+58h] [bp-7Ch]
  unsigned int v126; // [sp+5Ch] [bp-78h]
  int v127; // [sp+5Ch] [bp-78h]
  unsigned int v128; // [sp+60h] [bp-74h]
  int v129; // [sp+60h] [bp-74h]
  unsigned int v130; // [sp+64h] [bp-70h]
  int v131; // [sp+64h] [bp-70h]
  unsigned int v132; // [sp+68h] [bp-6Ch]
  int v133; // [sp+68h] [bp-6Ch]
  unsigned int v134; // [sp+6Ch] [bp-68h]
  int v135; // [sp+6Ch] [bp-68h]
  unsigned int v136; // [sp+70h] [bp-64h]
  int v137; // [sp+70h] [bp-64h]
  unsigned int v138; // [sp+74h] [bp-60h]
  int v139; // [sp+74h] [bp-60h]
  unsigned int v140; // [sp+78h] [bp-5Ch]
  int v141; // [sp+78h] [bp-5Ch]
  int v142; // [sp+7Ch] [bp-58h]
  int v143; // [sp+80h] [bp-54h]
  int v144; // [sp+84h] [bp-50h]
  int v145; // [sp+88h] [bp-4Ch]
  int v146; // [sp+8Ch] [bp-48h]
  int v147; // [sp+90h] [bp-44h]
  int v148; // [sp+94h] [bp-40h]
  int v149; // [sp+98h] [bp-3Ch]
  int v150; // [sp+98h] [bp-3Ch]
  char v151; // [sp+9Ch] [bp-38h]
  int v152; // [sp+A0h] [bp-34h]
  int v153; // [sp+A4h] [bp-30h]
  int v154; // [sp+A8h] [bp-2Ch]
  int v155; // [sp+ACh] [bp-28h]
  int v156; // [sp+B0h] [bp-24h]
  int v157; // [sp+B4h] [bp-20h]
  unsigned int v158; // [sp+B8h] [bp-1Ch]
  int v159; // [sp+BCh] [bp-18h]
  int v160; // [sp+C0h] [bp-14h]
  int v161; // [sp+C4h] [bp-10h]
  int v162; // [sp+C8h] [bp-Ch]
  int v163; // [sp+CCh] [bp-8h]

  v7 = off_1067E8;
  v8 = (unsigned int *)off_1067EC;
  v9 = (unsigned int *)off_1067F0;
  v10 = (unsigned int *)off_1067C0;
  v11 = (unsigned int *)off_1067F4;
  v12 = (unsigned int *)off_1067C4;
  v13 = (unsigned int *)off_1067F8;
  v14 = (unsigned int *)off_1067C8;
  *(uint32_t *)off_1067E8 |= 0x400u;
  *v7 &= ~0x400u;
  v88 = *v8;
  v90 = *v9;
  v92 = *v10;
  v94 = *v10;
  v96 = *v11;
  v98 = *v12;
  v100 = *v12;
  v102 = *v12;
  v104 = *v12;
  v106 = *v8;
  v140 = *(uint32_t *)off_1067CC;
  v138 = *(uint32_t *)off_1067CC;
  *v8 |= 0x20u;
  v15 = (unsigned int *)off_1067CC;
  *v9 = *v9 & 0xF8FFFFFF | 0x2000000;
  *v10 |= 0x100000u;
  *v10 |= 0x200000u;
  *v11 = *v11 & 0xFFFFFF0F | 0xC0;
  *v13 = *v13 & 0xFFFFFFC7 | 0x20;
  *v12 |= 0x400u;
  *v12 = *v12 & 0xFFFFFCFF | 0x100;
  *v15 = *v15 & 0xFFFE00FF | 0x100;
  *v15 |= 0x20000u;
  *v15 |= 0x40000u;
  v108 = *v13;
  v110 = *(unsigned int *)((char *)v15 + 0xFFFFFFC8);
  v112 = *v14;
  v114 = *v14;
  v116 = *v14;
  v118 = *v14;
  v120 = *v10;
  v122 = *v10;
  v124 = *v10;
  v126 = *v10;
  v128 = *(uint32_t *)off_1067D0;
  v130 = *(uint32_t *)off_1067D4;
  v132 = *v11;
  v134 = *(uint32_t *)off_1067D8;
  v136 = *v11;
  v146 = *(uint32_t *)off_1067DC;
  v85 = *v10;
  v17 = *v10;
  v16 = *v10;
  v145 = *(uint32_t *)off_1067E0;
  v18 = *(uint32_t *)off_1067E4;
  *v13 |= 0x40u;
  *(unsigned int *)((char *)v15 + 0xFFFFFFC8) &= 0xFFFF8FFF;
  *v14 |= 0x800000u;
  v19 = a4;
  v89 = (v88 >> 5) & 1;
  v91 = HIBYTE(v90) & 7;
  v93 = (v92 >> 21) & 1;
  v95 = (v94 >> 20) & 1;
  v97 = (uint8_t)v96 >> 4;
  v99 = (v98 >> 7) & 1;
  v101 = (v100 >> 4) & 7;
  v103 = (v102 >> 10) & 1;
  v105 = (v104 >> 8) & 3;
  v107 = (v106 >> 2) & 7;
  v148 = (v140 >> 22) & 1;
  v147 = (v138 >> 21) & 1;
  v109 = (v108 >> 6) & 1;
  v111 = (v110 >> 12) & 7;
  v113 = (v112 >> 23) & 1;
  v115 = (v114 >> 22) & 1;
  v117 = (v116 >> 20) & 1;
  v119 = (v118 >> 21) & 1;
  v121 = (v120 >> 17) & 1;
  v123 = HIWORD(v122) & 1;
  v125 = (v124 >> 15) & 1;
  v127 = (v126 >> 14) & 1;
  v129 = (v128 >> 18) & 1;
  v131 = (v130 >> 12) & 3;
  v133 = v132 & 3;
  v135 = (v134 >> 18) & 7;
  v137 = (v136 >> 2) & 1;
  v139 = (v16 >> 23) & 1;
  v141 = (v17 >> 22) & 1;
  v143 = (v85 >> 18) & 1;
  v144 = (v18 >> 8) & 1;
  v142 = (v85 >> 19) & 1;
  *v14 |= 0x400000u;
  LOBYTE(a4) = 90;
  do
    a4 = (uint8_t)(a4 - 1);
  while ( a4 );
  v23 = off_1067C8;
  *(uint32_t *)off_1067C8 &= ~0x100000u;
  *(uint32_t *)v23 |= 0x200000u;
  LOBYTE(v23) = 60;
  do
    v23 = (void *)(uint8_t)((uint8_t)v23 - 1);
  while ( v23 );
  v24 = off_1067C0;
  *(uint32_t *)off_1067C8 |= 0x100000u;
  *(uint32_t *)v24 |= 0x20000u;
  *(uint32_t *)v24 |= 0x10000u;
  LOBYTE(v24) = 90;
  do
    v24 = (void *)(uint8_t)((uint8_t)v24 - 1);
  while ( v24 );
  v25 = off_106980;
  *(uint32_t *)off_106980 &= ~0x40000u;
  *(uint32_t *)v25 |= 0x80000u;
  LOBYTE(v25) = 60;
  do
    v25 = (void *)(uint8_t)((uint8_t)v25 - 1);
  while ( v25 );
  v26 = off_106980;
  *(uint32_t *)off_106980 |= 0x40000u;
  *v26 |= 0x8000u;
  *v26 |= 0x4000u;
  LOBYTE(v27) = 90;
  do
    v27 = (uint8_t)(v27 - 1);
  while ( v27 );
  v28 = off_106984;
  v29 = off_106988;
  v30 = (unsigned int *)off_10698C;
  v31 = off_106990;
  *(uint32_t *)off_106984 |= 0x40000u;
  *v29 |= 0x3000u;
  v32 = off_106980;
  *v30 = *v30 & 0xFFFFFFFC | 1;
  v28[16] = v28[16] & 0xFFE3FFFF | 0xC0000;
  *v30 |= 4u;
  *v32 |= 0x800000u;
  *v32 |= 0x400000u;
  *v31 &= ~0x100u;
  rf_clear_ana_bits();
  bt_radio_init();
  v33 = off_106998;
  *(uint32_t *)off_106994 |= 0x10000000u;
  *v33 |= 0x18000000u;
  if ( a7 )
  {
    if ( a7 == 1 )
    {
      v60 = (a1 >> 12) & 3;
      *(uint32_t *)off_106FE8 = a1;
      if ( v60 == 1 )
      {
        v160 = 0;
        v161 = *(uint32_t *)asc_152C80;
        v156 = -2;
        v86 = 31;
        v155 = 1;
        v149 = 1;
        v61 = 4;
        v63 = 0x7FFFFFFF;
        v159 = 3;
        v151 = 1;
        v153 = 0x7FFFFFFF;
        v154 = 4;
        v62 = 0;
      }
      else
      {
        if ( v60 == 2 )
        {
          v161 = *(uint32_t *)off_107078;
          v61 = 8;
          v156 = dword_10707C;
          v155 = dword_107080;
        }
        else
        {
          v161 = *(uint32_t *)off_106FEC;
          v155 = dword_106FF4;
          v61 = 8;
          v156 = dword_106FF0;
        }
        a7 = 2;
        v160 = 8;
        v62 = 2;
        v86 = 13;
        v149 = -1;
        v153 = -122881;
        v159 = 15;
        v151 = -13;
        v63 = 0x1FFF;
        v154 = 16;
      }
      v64 = *(uint32_t *)(dword_106FF8 - 18832);
      v65 = (v64 >> 8) & 0xF;
      v66 = (v60 << 8) + dword_106FF8;
      v162 = v66;
      check_feature_flag(1, "tx_gain_reg=%x,apc_table=%d,ampm_index=%x\n", v64, v60, v65);
      *(uint32_t *)(a2 + 140) = *(uint32_t *)(a2 + 152);
      load_const_table(a2, 0);
      v67 = 0;
      check_feature_flag(1, "tx_gain_map_reg=%x  ana_index=%x base=%d \n", *(uint32_t *)off_106FE8, v65, 0);
      v152 = v62;
      v68 = v65;
      v69 = v66 + 16 * v65;
      v70 = (int *)(v69 + v160);
      v71 = (uint32_t *)(v69 + v61);
      v163 = v61;
      v157 = v63;
      v158 = 0;
      v72 = 0;
      v73 = v68;
      v74 = 2 * v68;
      do
      {
        rf_clear_control_bit_a(1);
        if ( v152 == a7 )
        {
          *v70 = *v70 & v153 | ((v159 & v67) << v86);
        }
        else
        {
          *v70 &= v157;
          *v71 &= v156;
          *v70 |= (v149 & v67) << v86;
          *v71 |= (v67 >> v151) & v155;
        }
        rf_clear_control_bit_b(1);
        rf_path_disable((uint16_t)*a3, a2, v73, 0);
        check_feature_flag(1, "tone_amp[0]=%x,pwr_back[%2d]=%d ", *a3, v67, *(uint16_t *)(a2 + v74));
        check_feature_flag(1, "wf_pa_5g_input_2_cbit=%d  ", (*(uint32_t *)off_107008 >> 21) & 3);
        check_feature_flag(1, "wf_dtmx_tuning_cbit=%d\n", (*(uint32_t *)off_107010 >> 15) & 0xF);
        if ( *(uint16_t *)(a2 + v74) > v72 )
        {
          v72 = *(uint16_t *)(a2 + v74);
          v158 = v67;
        }
        ++v67;
      }
      while ( v154 != v67 );
      check_feature_flag(1, "cbit_val=%d\n", v158);
      rf_clear_control_bit_a(1);
      v78 = v86;
      v87 = (v158 >> v151) & v155;
      v79 = (v149 & v158) << v78;
      v150 = (v158 & v159) << v78;
      v80 = (int *)(v162 + v160);
      v81 = (int *)(v160 + 192 + v161);
      v82 = (int *)(v161 + v160);
      v83 = v163 - v160;
      do
      {
        while ( 1 )
        {
          v84 = &v82[v160 / 0xFFFFFFFC];
          if ( v152 == a7 )
            break;
          *v80 &= v157;
          *(int *)((char *)v80 + v83) &= v156;
          *v80 |= v79;
          *(int *)((char *)v80 + v83) |= v87;
          *v82 &= v157;
          *(int *)((char *)v84 + v163) &= v156;
          *v82 |= v79;
          v82 += 3;
          *(int *)((char *)v84 + v163) |= v87;
          v80 += 4;
          if ( v81 == v82 )
            goto LABEL_50;
        }
        *v80 = *v80 & v153 | v150;
        *v82 = *v82 & v153 | v150;
        v82 += 3;
        v80 += 4;
      }
      while ( v81 != v82 );
LABEL_50:
      rf_clear_control_bit_b(1);
      check_feature_flag(1, "use wf_pa_5g_input_2_cbit=%d  ", (*(uint32_t *)off_107008 >> 21) & 3);
      check_feature_flag(1, "use wf_dtmx_tuning_cbit=%d\n", (*(uint32_t *)off_107010 >> 15) & 0xF);
    }
    goto LABEL_28;
  }
  if ( v19 )
  {
    v75 = (unsigned int *)off_106FE8;
    *(uint32_t *)off_106FE8 = a1;
    *v31 &= ~0x200u;
    *v31 |= 0x200u;
    *v31 &= ~0x200u;
    v76 = *v75;
    load_const_table(a2, 0);
    v77 = (v76 >> 8) & 0xF;
    check_feature_flag(1, "tx_gain_map_reg=%x  ana_index=%x base=%d ", *v75, v77, 0);
    rf_path_disable((uint16_t)*a3, a2, v77, 0);
    goto LABEL_28;
  }
  *(uint64_t *)(a2 + 168) = 0xFFFFFFECFFFFFFFELL;
  v34 = a3 - 1;
  v35 = (uint32_t *)(a2 + 140);
  do
  {
    if ( v19 == 2 )
    {
      v36 = *(uint32_t *)(a2 + 124);
LABEL_18:
      v37 = -5;
      goto LABEL_19;
    }
    if ( v19 == 1 )
    {
      v36 = *(uint32_t *)(a2 + 120);
      goto LABEL_18;
    }
    v36 = *(uint32_t *)(a2 + 112);
    if ( a5 || v36 <= 12 )
      goto LABEL_18;
    v37 = -10;
LABEL_19:
    *(uint32_t *)(a2 + 164) = v37;
    *v35 = v35[3];
    ++v35;
    hw_rev_check(a1, v36, a5, a2, a6);
    *v31 &= ~0x200u;
    *v31 |= 0x200u;
    *v31 &= ~0x200u;
    load_const_table(a2, v19);
    v38 = (uint16_t)v34[1];
    ++v34;
    rf_path_disable(v38, a2, v36, v19);
    v39 = v19;
    v40 = *(uint16_t *)(a2 + 2 * (v36 + 16 * v19++));
    init_callbacks(a2, v40, v39);
  }
  while ( v19 != 3 );
  v41 = *(uint32_t *)(a2 + 132);
  if ( v41 <= *(uint32_t *)(a2 + 112) )
  {
    v42 = off_106990;
    v43 = off_10699C;
    do
    {
      while ( 1 )
      {
        hw_rev_check(a1, v41, a5, a2, a6);
        v44 = *(uint32_t *)(a2 + 124);
        *v42 &= ~0x200u;
        *v42 |= 0x200u;
        *v42 &= ~0x200u;
        if ( v44 < v41 )
          break;
        load_const_table(a2, 2);
        check_feature_flag(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v43, v41, 2);
        rf_path_disable((uint16_t)a3[2], a2, v41, 2);
        if ( *(uint32_t *)(a2 + 124) <= v41 )
          break;
LABEL_26:
        if ( *(uint32_t *)(a2 + 120) <= v41 )
          goto LABEL_23;
        if ( *(uint32_t *)(a2 + 112) < ++v41 )
          goto LABEL_28;
      }
      if ( *(uint32_t *)(a2 + 120) >= v41 )
      {
        load_const_table(a2, 1);
        check_feature_flag(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v43, v41, 1);
        rf_path_disable((uint16_t)a3[1], a2, v41, 1);
        goto LABEL_26;
      }
LABEL_23:
      load_const_table(a2, 0);
      check_feature_flag(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v43, v41, 0);
      rf_path_disable((uint16_t)*a3, a2, v41++, 0);
    }
    while ( *(uint32_t *)(a2 + 112) >= v41 );
  }
LABEL_28:
  v45 = (unsigned int *)off_106CC0;
  v46 = (unsigned int *)off_106CC4;
  v47 = (unsigned int *)off_106CE8;
  v48 = (unsigned int *)off_106CEC;
  v49 = off_106CE4;
  *(uint32_t *)off_106CC0 = *(uint32_t *)off_106CC0 & 0xFFBFFFFF | (v148 << 22);
  *v45 = *v45 & 0xFFDFFFFF | (v147 << 21);
  rf_disable();
  v50 = off_106CC8;
  v51 = (unsigned int *)off_106CCC;
  v52 = (unsigned int *)off_106CF0;
  *(uint32_t *)off_106CC8 = *(uint32_t *)off_106CC8 & 0xF8FFFFFF | (v91 << 24);
  v53 = (unsigned int *)off_106CD0;
  *v46 = *v46 & 0xFFFFFFBF | (v109 << 6);
  v54 = (unsigned int *)off_106CD4;
  *v51 = *v51 & 0xFFFF8FFF | (v111 << 12);
  v55 = (unsigned int *)off_106CD8;
  v56 = (unsigned int *)off_106CDC;
  *(uint32_t *)((char *)v50 + 0xFFFFFFDC) = *(uint32_t *)((char *)v50 + 0xFFFFFFDC) & 0xFF7FFFFF | (v113 << 23);
  *(uint32_t *)((char *)v50 + 0xFFFFFFDC) = *(uint32_t *)((char *)v50 + 0xFFFFFFDC) & 0xFFBFFFFF | (v115 << 22);
  v57 = (unsigned int *)off_106CE0;
  *(uint32_t *)((char *)v50 + 0xFFFFFFDC) = *(uint32_t *)((char *)v50 + 0xFFFFFFDC) & 0xFFEFFFFF | (v117 << 20);
  *(uint32_t *)((char *)v50 + 0xFFFFFFDC) = *(uint32_t *)((char *)v50 + 0xFFFFFFDC) & 0xFFDFFFFF | (v119 << 21);
  *v53 = *v53 & 0xFFFBFFFF | (v143 << 18);
  v58 = off_106CF4;
  *v53 = *v53 & 0xFFF7FFFF | (v142 << 19);
  *v53 = *v53 & 0xFFFDFFFF | (v121 << 17);
  *v53 = *v53 & 0xFFFEFFFF | (v123 << 16);
  *v53 = *v53 & 0xFFFF7FFF | (v125 << 15);
  *v53 = *v53 & 0xFFFFBFFF | (v127 << 14);
  *v54 = *v54 & 0xFFFBFFFF | (v129 << 18);
  *v47 = *v47 & 0xFFFFCFFF | (v131 << 12);
  *v55 = *v55 & 0xFFFFFFFC | v133;
  *v56 = *v56 & 0xFFE3FFFF | (v135 << 18);
  *v55 = *v55 & 0xFFFFFFFB | (4 * v137);
  *v53 = *v53 & 0xFF7FFFFF | (v139 << 23);
  *v53 = *v53 & 0xFFBFFFFF | (v141 << 22);
  *v52 = *v52 & 0xFFFFFFDF | (32 * v89);
  *v53 = *v53 & 0xFFDFFFFF | (v93 << 21);
  *v53 = *v53 & 0xFFEFFFFF | (v95 << 20);
  *v55 = *v55 & 0xFFFFFF0F | (16 * v97);
  *v57 = *v57 & 0xFFFFFF7F | (v99 << 7);
  *v57 = *v57 & 0xFFFFFF8F | (16 * v101);
  *v57 = *v57 & 0xFFFFFBFF | (v103 << 10);
  *v57 = *v57 & 0xFFFFFCFF | (v105 << 8);
  *v52 = *v52 & 0xFFFFFFE3 | (4 * v107);
  *v45 &= 0xFFFE00FF;
  *v45 &= ~0x20000u;
  *v45 |= 0x40000u;
  *v48 = *v48 & 0x7FFFFFFF | v146 & 0x80000000;
  *v49 = v145;
  *(v50 - 1902) = *(v50 - 1902) & 0xFFFFFEFF | (v144 << 8);
  *v58 |= 0x400u;
  *v58 &= ~0x400u;
  return v105;
}
