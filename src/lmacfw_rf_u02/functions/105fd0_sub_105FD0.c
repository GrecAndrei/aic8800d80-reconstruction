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


extern uint32_t dword_106A68;
extern uint32_t dword_106A6C;
extern uint32_t dword_106A70;
extern uint32_t dword_106BAC;
extern uint32_t dword_106BB0;
extern uint32_t off_1062B0;
extern uint32_t off_1062B4;
extern uint32_t off_1062B8;
extern uint32_t off_1062BC;
extern uint32_t off_1062C0;
extern uint32_t off_1062C4;
extern uint32_t off_1062C8;
extern uint32_t off_1062CC;
extern uint32_t off_1062D0;
extern uint32_t off_1062D4;
extern uint32_t off_1062D8;
extern uint32_t off_1062DC;
extern uint32_t off_1062E0;
extern uint32_t off_1062E4;
extern uint32_t off_1062E8;
extern uint32_t off_106470;
extern uint32_t off_106474;
extern uint32_t off_106478;
extern uint32_t off_10647C;
extern uint32_t off_106480;
extern uint32_t off_106484;
extern uint32_t off_106488;
extern uint32_t off_10648C;
extern uint32_t off_1067B0;
extern uint32_t off_1067B4;
extern uint32_t off_1067B8;
extern uint32_t off_1067BC;
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
extern uint32_t off_106A60;
extern uint32_t off_106A64;
extern uint32_t off_106A80;
extern uint32_t off_106A88;
extern uint32_t off_106A94;
extern uint32_t off_106B94;
extern uint32_t off_106B9C;
extern uint32_t off_106BA4;
extern uint32_t off_106BA8;

// prcm_start @ 0x105fd0, size 3010 bytes
int  prcm_start(unsigned int a1, int a2, uint16_t *a3, int a4, int a5, int a6, int a7, int a8)
{
  uint32_t *v8; // r9
  unsigned int *v9; // r8
  unsigned int *v10; // r10
  unsigned int *v11; // r4
  unsigned int *v12; // lr
  unsigned int *v13; // r7
  unsigned int *v14; // r12
  unsigned int *v15; // r5
  unsigned int *v16; // r6
  unsigned int v17; // r9
  unsigned int v18; // r8
  unsigned int v19; // r7
  int v20; // r6
  void *v24; // r3
  void *v25; // r3
  void *v26; // r3
  uint32_t *v27; // r3
  int v28; // r7
  uint32_t *v29; // r0
  uint32_t *v30; // r2
  unsigned int *v31; // r1
  uint32_t *v32; // r5
  uint32_t *v33; // r2
  uint32_t *v34; // r2
  uint16_t *v35; // r9
  uint32_t *v36; // r8
  int v37; // r7
  int v38; // r3
  int v39; // t1
  int v40; // r2
  int v41; // r1
  int v42; // r5
  uint32_t *v43; // r6
  uint32_t *v44; // r9
  int v45; // r2
  unsigned int *v46; // r4
  unsigned int *v47; // r5
  unsigned int *v48; // r9
  unsigned int *v49; // r11
  uint32_t *v50; // r8
  uint32_t *v51; // r1
  unsigned int *v52; // r2
  unsigned int *v53; // r12
  unsigned int *v54; // r3
  unsigned int *v55; // r6
  unsigned int *v56; // r0
  unsigned int *v57; // r7
  unsigned int *v58; // r2
  uint32_t *v59; // r10
  int v61; // r8
  int v62; // r9
  int v63; // r10
  int v64; // r7
  int v65; // r6
  unsigned int v66; // r5
  int v67; // r3
  int v68; // r7
  int *v69; // r6
  uint32_t *v70; // r7
  int v71; // r9
  int v72; // r10
  int v73; // r8
  unsigned int *v74; // r6
  unsigned int v75; // r5
  int v76; // r5
  char v77; // r3
  int v78; // r6
  int *v79; // r3
  int *v80; // r12
  int *v81; // r2
  int v82; // r0
  int *v83; // r1
  int v84; // r3
  unsigned int v85; // r3
  unsigned int v86; // [sp+8h] [bp-CCh]
  char v87; // [sp+8h] [bp-CCh]
  int v88; // [sp+8h] [bp-CCh]
  unsigned int v89; // [sp+Ch] [bp-C8h]
  int v90; // [sp+Ch] [bp-C8h]
  unsigned int v91; // [sp+10h] [bp-C4h]
  int v92; // [sp+10h] [bp-C4h]
  unsigned int v93; // [sp+14h] [bp-C0h]
  int v94; // [sp+14h] [bp-C0h]
  unsigned int v95; // [sp+18h] [bp-BCh]
  int v96; // [sp+18h] [bp-BCh]
  unsigned int v97; // [sp+1Ch] [bp-B8h]
  int v98; // [sp+1Ch] [bp-B8h]
  unsigned int v99; // [sp+20h] [bp-B4h]
  int v100; // [sp+20h] [bp-B4h]
  unsigned int v101; // [sp+24h] [bp-B0h]
  int v102; // [sp+24h] [bp-B0h]
  unsigned int v103; // [sp+28h] [bp-ACh]
  int v104; // [sp+28h] [bp-ACh]
  unsigned int v105; // [sp+2Ch] [bp-A8h]
  int v106; // [sp+2Ch] [bp-A8h]
  unsigned int v107; // [sp+30h] [bp-A4h]
  int v108; // [sp+30h] [bp-A4h]
  unsigned int v109; // [sp+34h] [bp-A0h]
  int v110; // [sp+34h] [bp-A0h]
  unsigned int v111; // [sp+38h] [bp-9Ch]
  int v112; // [sp+38h] [bp-9Ch]
  unsigned int v113; // [sp+3Ch] [bp-98h]
  int v114; // [sp+3Ch] [bp-98h]
  unsigned int v115; // [sp+40h] [bp-94h]
  int v116; // [sp+40h] [bp-94h]
  unsigned int v117; // [sp+44h] [bp-90h]
  int v118; // [sp+44h] [bp-90h]
  unsigned int v119; // [sp+48h] [bp-8Ch]
  int v120; // [sp+48h] [bp-8Ch]
  unsigned int v121; // [sp+4Ch] [bp-88h]
  int v122; // [sp+4Ch] [bp-88h]
  unsigned int v123; // [sp+50h] [bp-84h]
  int v124; // [sp+50h] [bp-84h]
  unsigned int v125; // [sp+54h] [bp-80h]
  int v126; // [sp+54h] [bp-80h]
  unsigned int v127; // [sp+58h] [bp-7Ch]
  int v128; // [sp+58h] [bp-7Ch]
  unsigned int v129; // [sp+5Ch] [bp-78h]
  int v130; // [sp+5Ch] [bp-78h]
  unsigned int v131; // [sp+60h] [bp-74h]
  int v132; // [sp+60h] [bp-74h]
  unsigned int v133; // [sp+64h] [bp-70h]
  int v134; // [sp+64h] [bp-70h]
  unsigned int v135; // [sp+68h] [bp-6Ch]
  int v136; // [sp+68h] [bp-6Ch]
  unsigned int v137; // [sp+6Ch] [bp-68h]
  int v138; // [sp+6Ch] [bp-68h]
  unsigned int v139; // [sp+70h] [bp-64h]
  int v140; // [sp+70h] [bp-64h]
  unsigned int v141; // [sp+74h] [bp-60h]
  int v142; // [sp+74h] [bp-60h]
  int v143; // [sp+78h] [bp-5Ch]
  int v144; // [sp+7Ch] [bp-58h]
  int v145; // [sp+80h] [bp-54h]
  int v146; // [sp+84h] [bp-50h]
  int v147; // [sp+88h] [bp-4Ch]
  int v148; // [sp+8Ch] [bp-48h]
  int v149; // [sp+90h] [bp-44h]
  char v150; // [sp+94h] [bp-40h]
  int v151; // [sp+94h] [bp-40h]
  int v152; // [sp+98h] [bp-3Ch]
  int v153; // [sp+9Ch] [bp-38h]
  int v154; // [sp+A0h] [bp-34h]
  int v155; // [sp+A4h] [bp-30h]
  int v156; // [sp+A8h] [bp-2Ch]
  int v157; // [sp+ACh] [bp-28h]
  int v158; // [sp+B0h] [bp-24h]
  unsigned int v159; // [sp+B4h] [bp-20h]
  int v160; // [sp+B8h] [bp-1Ch]
  unsigned int v161; // [sp+BCh] [bp-18h]
  int v162; // [sp+C0h] [bp-14h]
  int v163; // [sp+C4h] [bp-10h]
  int v164; // [sp+C8h] [bp-Ch]
  int v165; // [sp+CCh] [bp-8h]

  v8 = off_1062D8;
  v9 = (unsigned int *)off_1062DC;
  v10 = (unsigned int *)off_1062E0;
  v11 = (unsigned int *)off_1062B0;
  v12 = (unsigned int *)off_1062E4;
  v13 = (unsigned int *)off_1062B4;
  v14 = (unsigned int *)off_1062E8;
  v15 = (unsigned int *)off_1062B8;
  *(uint32_t *)off_1062D8 |= 0x400u;
  *v8 &= ~0x400u;
  v89 = *v9;
  v91 = *v10;
  v93 = *v11;
  v95 = *v11;
  v97 = *v12;
  v99 = *v13;
  v101 = *v13;
  v103 = *v13;
  v105 = *v13;
  v107 = *v9;
  v141 = *(uint32_t *)off_1062BC;
  v139 = *(uint32_t *)off_1062BC;
  *v9 |= 0x20u;
  v16 = (unsigned int *)off_1062BC;
  *v10 = *v10 & 0xF8FFFFFF | 0x2000000;
  *v11 |= 0x100000u;
  *v11 |= 0x200000u;
  *v12 = *v12 & 0xFFFFFF0F | 0xC0;
  *v14 = *v14 & 0xFFFFFFC7 | 0x20;
  *v13 |= 0x400u;
  *v13 = *v13 & 0xFFFFFCFF | 0x100;
  *v16 = *v16 & 0xFFFE00FF | 0x100;
  *v16 |= 0x20000u;
  *v16 |= 0x40000u;
  v109 = *v14;
  v111 = *(unsigned int *)((char *)v16 + 0xFFFFFFC8);
  v113 = *v15;
  v115 = *v15;
  v117 = *v15;
  v119 = *v15;
  v121 = *v11;
  v123 = *v11;
  v125 = *v11;
  v127 = *v11;
  v129 = *(uint32_t *)off_1062C0;
  v131 = *(uint32_t *)off_1062C4;
  v133 = *v12;
  v135 = *(uint32_t *)off_1062C8;
  v137 = *v12;
  v147 = *(uint32_t *)off_1062CC;
  v86 = *v11;
  v18 = *v11;
  v17 = *v11;
  v146 = *(uint32_t *)off_1062D0;
  v19 = *(uint32_t *)off_1062D4;
  *v14 |= 0x40u;
  *(unsigned int *)((char *)v16 + 0xFFFFFFC8) &= 0xFFFF8FFF;
  *v15 |= 0x800000u;
  v20 = a4;
  v90 = (v89 >> 5) & 1;
  v92 = HIBYTE(v91) & 7;
  v94 = (v93 >> 21) & 1;
  v96 = (v95 >> 20) & 1;
  v98 = (uint8_t)v97 >> 4;
  v100 = (v99 >> 7) & 1;
  v102 = (v101 >> 4) & 7;
  v104 = (v103 >> 10) & 1;
  v106 = (v105 >> 8) & 3;
  v108 = (v107 >> 2) & 7;
  v149 = (v141 >> 22) & 1;
  v148 = (v139 >> 21) & 1;
  v110 = (v109 >> 6) & 1;
  v112 = (v111 >> 12) & 7;
  v114 = (v113 >> 23) & 1;
  v116 = (v115 >> 22) & 1;
  v118 = (v117 >> 20) & 1;
  v120 = (v119 >> 21) & 1;
  v122 = (v121 >> 17) & 1;
  v124 = HIWORD(v123) & 1;
  v126 = (v125 >> 15) & 1;
  v128 = (v127 >> 14) & 1;
  v130 = (v129 >> 18) & 1;
  v132 = (v131 >> 12) & 3;
  v134 = v133 & 3;
  v136 = (v135 >> 18) & 7;
  v138 = (v137 >> 2) & 1;
  v140 = (v17 >> 23) & 1;
  v142 = (v18 >> 22) & 1;
  v144 = (v86 >> 18) & 1;
  v145 = (v19 >> 8) & 1;
  v143 = (v86 >> 19) & 1;
  *v15 |= 0x400000u;
  LOBYTE(a4) = 90;
  do
    a4 = (uint8_t)(a4 - 1);
  while ( a4 );
  v24 = off_1062B8;
  *(uint32_t *)off_1062B8 &= ~0x100000u;
  *(uint32_t *)v24 |= 0x200000u;
  LOBYTE(v24) = 60;
  do
    v24 = (void *)(uint8_t)((uint8_t)v24 - 1);
  while ( v24 );
  v25 = off_1062B0;
  *(uint32_t *)off_1062B8 |= 0x100000u;
  *(uint32_t *)v25 |= 0x20000u;
  *(uint32_t *)v25 |= 0x10000u;
  LOBYTE(v25) = 90;
  do
    v25 = (void *)(uint8_t)((uint8_t)v25 - 1);
  while ( v25 );
  v26 = off_106470;
  *(uint32_t *)off_106470 &= ~0x40000u;
  *(uint32_t *)v26 |= 0x80000u;
  LOBYTE(v26) = 60;
  do
    v26 = (void *)(uint8_t)((uint8_t)v26 - 1);
  while ( v26 );
  v27 = off_106470;
  *(uint32_t *)off_106470 |= 0x40000u;
  *v27 |= 0x8000u;
  *v27 |= 0x4000u;
  LOBYTE(v28) = 90;
  do
    v28 = (uint8_t)(v28 - 1);
  while ( v28 );
  v29 = off_106474;
  v30 = off_106478;
  v31 = (unsigned int *)off_10647C;
  v32 = off_106480;
  *(uint32_t *)off_106474 |= 0x40000u;
  *v30 |= 0x3000u;
  v33 = off_106470;
  *v31 = *v31 & 0xFFFFFFFC | 1;
  v29[16] = v29[16] & 0xFFE3FFFF | 0xC0000;
  *v31 |= 4u;
  *v33 |= 0x800000u;
  *v33 |= 0x400000u;
  *v32 &= ~0x100u;
  disable_bb_timer_irq();
  bb_hw_init();
  v34 = off_106488;
  *(uint32_t *)off_106484 |= 0x10000000u;
  *v34 |= 0x18000000u;
  if ( a7 )
  {
    if ( a7 == 1 )
    {
      v161 = (a1 >> 12) & 3;
      *(uint32_t *)off_106A60 = a1;
      if ( v161 == 1 )
      {
        v162 = 0;
        v163 = *(uint32_t *)off_106BA4;
        v157 = -2;
        v87 = 31;
        v156 = 1;
        v152 = 1;
        v61 = 4;
        v63 = 0x7FFFFFFF;
        v160 = 3;
        v150 = 1;
        v154 = 0x7FFFFFFF;
        v155 = 4;
        v62 = 0;
      }
      else
      {
        if ( v161 == 2 )
        {
          v163 = *off_106BA8;
          v156 = dword_106BB0;
          v157 = dword_106BAC;
        }
        else
        {
          v163 = *off_106A64;
          v156 = dword_106A6C;
          v157 = dword_106A68;
        }
        v61 = 8;
        a7 = 2;
        v62 = 2;
        v87 = 13;
        v152 = -1;
        v154 = -122881;
        v160 = 15;
        v150 = -13;
        v162 = 8;
        v63 = 0x1FFF;
        v155 = 16;
      }
      v64 = (*(uint32_t *)off_106A60 >> 8) & 0xF;
      v65 = (v161 << 8) + dword_106A70;
      v164 = v65;
      check_interrupt_flag(1, "tx_gain_reg=%x,apc_table=%d,ampm_index=%x\n", *(uint32_t *)off_106A60, v161, v64);
      *(uint32_t *)(a2 + 140) = *(uint32_t *)(a2 + 152);
      load_device_desc(a2, 0);
      v66 = 0;
      check_interrupt_flag(1, "tx_gain_map_reg=%x  ana_index=%x base=%d \n", *(uint32_t *)off_106A60, v64, 0);
      v153 = v62;
      v67 = v64;
      v68 = v65 + 16 * v64;
      v69 = (int *)(v68 + v162);
      v70 = (uint32_t *)(v68 + v61);
      v158 = v63;
      v165 = v61;
      v159 = 0;
      v71 = 0;
      v72 = v67;
      v73 = 2 * v67;
      do
      {
        gpio_set_pin(1);
        if ( a7 == v153 )
        {
          *v69 = *v69 & v154 | ((v160 & v66) << v87);
        }
        else
        {
          *v69 &= v158;
          *v70 &= v157;
          *v69 |= (v152 & v66) << v87;
          *v70 |= (v66 >> v150) & v156;
        }
        gpio_clear_pin(1);
        prcm_set_mask((uint16_t)*a3, a2, v72, 0);
        check_interrupt_flag(1, "tone_amp[0]=%x,pwr_back[%2d]=%d ", *a3, v66, *(uint16_t *)(a2 + v73));
        check_interrupt_flag(1, "wf_pa_5g_input_2_cbit=%d  ", (*(uint32_t *)off_106A80 >> 21) & 3);
        check_interrupt_flag(1, "wf_dtmx_tuning_cbit=%d\n", (*(uint32_t *)off_106A88 >> 15) & 0xF);
        if ( *(uint16_t *)(a2 + v73) > v71 )
        {
          v71 = *(uint16_t *)(a2 + v73);
          v159 = v66;
        }
        ++v66;
      }
      while ( v155 != v66 );
      if ( (*(uint8_t *)off_106A94 & 0xC0) != 0xC0 && a8 > 2 && v161 == 1 )
      {
        if ( a8 == 6 )
          v84 = 1;
        else
          v84 = 2;
        v85 = v159 + v84;
        if ( v85 >= 3 )
          v85 = 3;
        v159 = v85;
      }
      check_interrupt_flag(1, "cbit_val=%d\n", v159);
      gpio_set_pin(1);
      v77 = v87;
      v88 = (v159 >> v150) & v156;
      v78 = (v152 & v159) << v77;
      v151 = (v159 & v160) << v77;
      v79 = (int *)(v164 + v162);
      v80 = (int *)(v162 + 192 + v163);
      v81 = (int *)(v163 + v162);
      v82 = v165 - v162;
      do
      {
        while ( 1 )
        {
          v83 = &v81[v162 / 0xFFFFFFFC];
          if ( a7 == v153 )
            break;
          *v79 &= v158;
          *(int *)((char *)v79 + v82) &= v157;
          *v79 |= v78;
          *(int *)((char *)v79 + v82) |= v88;
          *v81 &= v158;
          *(int *)((char *)v83 + v165) &= v157;
          *v81 |= v78;
          v81 += 3;
          *(int *)((char *)v83 + v165) |= v88;
          v79 += 4;
          if ( v81 == v80 )
            goto LABEL_53;
        }
        *v79 = *v79 & v154 | v151;
        *v81 = *v81 & v154 | v151;
        v81 += 3;
        v79 += 4;
      }
      while ( v81 != v80 );
LABEL_53:
      gpio_clear_pin(1);
      check_interrupt_flag(1, "use wf_pa_5g_input_2_cbit=%d  ", (*(uint32_t *)off_106B94 >> 21) & 3);
      check_interrupt_flag(1, "use wf_dtmx_tuning_cbit=%d\n", (*(uint32_t *)off_106B9C >> 15) & 0xF);
    }
    goto LABEL_28;
  }
  if ( v20 )
  {
    v74 = (unsigned int *)off_106A60;
    *(uint32_t *)off_106A60 = a1;
    *v32 &= ~0x200u;
    *v32 |= 0x200u;
    *v32 &= ~0x200u;
    v75 = *v74;
    load_device_desc(a2, 0);
    v76 = (v75 >> 8) & 0xF;
    check_interrupt_flag(1, "tx_gain_map_reg=%x  ana_index=%x base=%d ", *v74, v76, 0);
    prcm_set_mask((uint16_t)*a3, a2, v76, 0);
    goto LABEL_28;
  }
  *(uint64_t *)(a2 + 168) = 0xFFFFFFECFFFFFFFELL;
  v35 = a3 - 1;
  v36 = (uint32_t *)(a2 + 140);
  do
  {
    if ( v20 == 2 )
    {
      v37 = *(uint32_t *)(a2 + 124);
LABEL_18:
      v38 = -5;
      goto LABEL_19;
    }
    if ( v20 == 1 )
    {
      v37 = *(uint32_t *)(a2 + 120);
      goto LABEL_18;
    }
    v37 = *(uint32_t *)(a2 + 112);
    if ( a5 || v37 <= 12 )
      goto LABEL_18;
    v38 = -10;
LABEL_19:
    *(uint32_t *)(a2 + 164) = v38;
    *v36 = v36[3];
    ++v36;
    validate_handle(a1, v37, a5, a2, a6);
    *v32 &= ~0x200u;
    *v32 |= 0x200u;
    *v32 &= ~0x200u;
    load_device_desc(a2, v20);
    v39 = (uint16_t)v35[1];
    ++v35;
    prcm_set_mask(v39, a2, v37, v20);
    v40 = v20;
    v41 = *(uint16_t *)(a2 + 2 * (v37 + 16 * v20++));
    malloc_wrapper(a2, v41, v40);
  }
  while ( v20 != 3 );
  v42 = *(uint32_t *)(a2 + 132);
  if ( v42 <= *(uint32_t *)(a2 + 112) )
  {
    v43 = off_106480;
    v44 = off_10648C;
    do
    {
      while ( 1 )
      {
        validate_handle(a1, v42, a5, a2, a6);
        v45 = *(uint32_t *)(a2 + 124);
        *v43 &= ~0x200u;
        *v43 |= 0x200u;
        *v43 &= ~0x200u;
        if ( v45 < v42 )
          break;
        load_device_desc(a2, 2);
        check_interrupt_flag(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v44, v42, 2);
        prcm_set_mask((uint16_t)a3[2], a2, v42, 2);
        if ( *(uint32_t *)(a2 + 124) <= v42 )
          break;
LABEL_26:
        if ( *(uint32_t *)(a2 + 120) <= v42 )
          goto LABEL_23;
        if ( *(uint32_t *)(a2 + 112) < ++v42 )
          goto LABEL_28;
      }
      if ( *(uint32_t *)(a2 + 120) >= v42 )
      {
        load_device_desc(a2, 1);
        check_interrupt_flag(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v44, v42, 1);
        prcm_set_mask((uint16_t)a3[1], a2, v42, 1);
        goto LABEL_26;
      }
LABEL_23:
      load_device_desc(a2, 0);
      check_interrupt_flag(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v44, v42, 0);
      prcm_set_mask((uint16_t)*a3, a2, v42++, 0);
    }
    while ( *(uint32_t *)(a2 + 112) >= v42 );
  }
LABEL_28:
  v46 = (unsigned int *)off_1067B0;
  v47 = (unsigned int *)off_1067B4;
  v48 = (unsigned int *)off_1067D8;
  v49 = (unsigned int *)off_1067DC;
  v50 = off_1067D4;
  *(uint32_t *)off_1067B0 = *(uint32_t *)off_1067B0 & 0xFFBFFFFF | (v149 << 22);
  *v46 = *v46 & 0xFFDFFFFF | (v148 << 21);
  disable_rx_path();
  v51 = off_1067B8;
  v52 = (unsigned int *)off_1067BC;
  v53 = (unsigned int *)off_1067E0;
  *(uint32_t *)off_1067B8 = *(uint32_t *)off_1067B8 & 0xF8FFFFFF | (v92 << 24);
  v54 = (unsigned int *)off_1067C0;
  *v47 = *v47 & 0xFFFFFFBF | (v110 << 6);
  v55 = (unsigned int *)off_1067C4;
  *v52 = *v52 & 0xFFFF8FFF | (v112 << 12);
  v56 = (unsigned int *)off_1067C8;
  v57 = (unsigned int *)off_1067CC;
  *(uint32_t *)((char *)v51 + 0xFFFFFFDC) = *(uint32_t *)((char *)v51 + 0xFFFFFFDC) & 0xFF7FFFFF | (v114 << 23);
  *(uint32_t *)((char *)v51 + 0xFFFFFFDC) = *(uint32_t *)((char *)v51 + 0xFFFFFFDC) & 0xFFBFFFFF | (v116 << 22);
  v58 = (unsigned int *)off_1067D0;
  *(uint32_t *)((char *)v51 + 0xFFFFFFDC) = *(uint32_t *)((char *)v51 + 0xFFFFFFDC) & 0xFFEFFFFF | (v118 << 20);
  *(uint32_t *)((char *)v51 + 0xFFFFFFDC) = *(uint32_t *)((char *)v51 + 0xFFFFFFDC) & 0xFFDFFFFF | (v120 << 21);
  *v54 = *v54 & 0xFFFBFFFF | (v144 << 18);
  v59 = off_1067E4;
  *v54 = *v54 & 0xFFF7FFFF | (v143 << 19);
  *v54 = *v54 & 0xFFFDFFFF | (v122 << 17);
  *v54 = *v54 & 0xFFFEFFFF | (v124 << 16);
  *v54 = *v54 & 0xFFFF7FFF | (v126 << 15);
  *v54 = *v54 & 0xFFFFBFFF | (v128 << 14);
  *v55 = *v55 & 0xFFFBFFFF | (v130 << 18);
  *v48 = *v48 & 0xFFFFCFFF | (v132 << 12);
  *v56 = *v56 & 0xFFFFFFFC | v134;
  *v57 = *v57 & 0xFFE3FFFF | (v136 << 18);
  *v56 = *v56 & 0xFFFFFFFB | (4 * v138);
  *v54 = *v54 & 0xFF7FFFFF | (v140 << 23);
  *v54 = *v54 & 0xFFBFFFFF | (v142 << 22);
  *v53 = *v53 & 0xFFFFFFDF | (32 * v90);
  *v54 = *v54 & 0xFFDFFFFF | (v94 << 21);
  *v54 = *v54 & 0xFFEFFFFF | (v96 << 20);
  *v56 = *v56 & 0xFFFFFF0F | (16 * v98);
  *v58 = *v58 & 0xFFFFFF7F | (v100 << 7);
  *v58 = *v58 & 0xFFFFFF8F | (16 * v102);
  *v58 = *v58 & 0xFFFFFBFF | (v104 << 10);
  *v58 = *v58 & 0xFFFFFCFF | (v106 << 8);
  *v53 = *v53 & 0xFFFFFFE3 | (4 * v108);
  *v46 &= 0xFFFE00FF;
  *v46 &= ~0x20000u;
  *v46 |= 0x40000u;
  *v49 = *v49 & 0x7FFFFFFF | v147 & 0x80000000;
  *v50 = v146;
  *(v51 - 1902) = *(v51 - 1902) & 0xFFFFFEFF | (v145 << 8);
  *v59 |= 0x400u;
  *v59 &= ~0x400u;
  return v106;
}
