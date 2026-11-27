// tx_packet_handler @ 0x101f70
int tx_packet_handler( unsigned int a1, int a2, unsigned int r2_0, unsigned int a4, uint8_t a5, uint8_t a6) {
  int v11; // r0
  uint16_t v12; // r6
  uint64_t v13; // r0
  uint64_t v14; // r0
  unsigned int v15; // r0
  uint64_t v16; // r0
  volatile unsigned int *v17; // r7
  uint64_t v18; // r0
  volatile uint32_t *v19; // r2
  volatile uint32_t *v20; // r2
  int v21; // r1
  volatile uint8_t *v22; // r6
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
  volatile unsigned int *v47; // r5
  unsigned int v48; // r0
  volatile uint32_t *v49; // r2
  uint64_t v50; // r0
  volatile unsigned int *v51; // r5
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
  volatile uint32_t *v65; // r5
  volatile unsigned int *v66; // r2
  volatile unsigned int *v67; // r8
  uint64_t v68; // r0
  uint64_t v69; // r6
  uint64_t v70; // r0
  uint64_t v71; // r6
  uint64_t v72; // r0
  volatile unsigned int *v73; // r9
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
  volatile unsigned int *v93; // r1
  volatile uint32_t *v94; // r7
  volatile unsigned int *v95; // r5
  volatile unsigned int v96; // r1
  unsigned int v97; // r1
  int v98; // r3
  volatile uint32_t *v99; // r2
  int v100; // r9
  volatile uint8_t *v101; // r6
  volatile uint32_t *v103; // r2
  volatile uint32_t *v104; // r6
  volatile uint32_t *v105; // r5
  volatile uint32_t *v106; // r0
  volatile uint32_t *v107; // r1
  volatile uint32_t *v108; // r6
  volatile uint32_t *v109; // r5
  int v110; // r3
  volatile uint32_t *v111; // r6
  volatile uint32_t *v112; // r5
  volatile uint32_t *v113; // r6
  volatile uint16_t *v114; // r12
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
  volatile unsigned int *v132; // r7
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
  volatile uint32_t *v150; // r2
  uint64_t v151; // r0
  volatile unsigned int *v152; // r6
  uint64_t v153; // r0
  uint64_t v154; // r0
  uint64_t v155; // r2
  uint64_t v156; // r0
  volatile unsigned int *v157; // r7
  uint64_t v158; // r0
  uint64_t v159; // r2
  uint64_t v160; // r0
  uint64_t v161; // r0
  uint64_t v162; // r0
  uint64_t v163; // r2
  uint64_t v164; // r0
  uint64_t v165; // r0
  int v166; // r9
  struct __attribute__((packed)) { unsigned int v167; // [sp+20h] [bp-4Ch]
  volatile uint8_t *v168; // [sp+24h] [bp-48h]
  char _pad2[4]; uint32_t v169[16]; // [sp+2Ch] [bp-40h] BYREF
  } _frame;
  event_dispatch("\x9D\x87%s: band=%d freq=%d freq1=%d chantype=%d sx=%d\n", aPhyHwSetChanne, a1, a2, r2_0, a4, a6);
  if ( **(volatile uint8_t **)off_1022C0 != 3 )
    check_status_bits(4, "setch:%d\r\n", r2_0);
  update_status_byte(a4);
  variadic_call_1006d8(a1, a2, r2_0, a4, a5);
  v11 = get_status_byte();
  v12 = v11;
  if ( v11 == 240 )
  {
    if ( a4 <= 1 )
      v156 = (v156 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102944) << 32);
    else
      v156 = (v156 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102940) << 32);
    v157 = (volatile unsigned int *)off_102948;
    v156 = (v156 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v158 = double_add(v156);
    *v157 = *v157 & 0xC00FFFFF | dword_10294C & (((int (*)(uint64_t))double_to_int)(v158) << 20);
  }
  else
  {
    v13 = int_to_double(v11);
    if ( a4 > 1 )
      v14 = ((uint64_t (*)())double_add_1)(v13, *(volatile uint64_t *)&dword_102598);
    else
      v14 = ((uint64_t (*)())double_add_1)(v13, *(volatile uint64_t *)&dword_1022A8);
    v15 = ((int (*)(uint64_t))double_to_uint)(v14);
    v16 = ((uint64_t (*)())float_to_double)(v15);
    v17 = (volatile unsigned int *)off_1022C8;
    v18 = double_add(v16);
    *v17 = *v17 & 0xF003FFFF | dword_1022CC & (((int (*)(uint64_t))double_to_int)(v18) << 18);
  }
  if ( a1 )
    v19 = (void *)(uintptr_t)(off_10293C);
  else
    v19 = (void *)(uintptr_t)(off_1022D0);
  *(volatile uint32_t *)off_1022D4 = (uint16_t)*(volatile uint32_t *)off_1022D4
                        | (((*v19 >> 8) - (uint16_t)(((*(volatile uint32_t *)off_1022C8 >> 18) & 0x3FF) + v12)) << 16);
  v20 = (void *)(uintptr_t)(off_1022DC);
  *(volatile uint32_t *)off_1022D8 = *(volatile uint32_t *)off_1022D8 & 0xFFFE1FFF | 0xE000;
  v21 = *((volatile uint8_t *)off_1022E0 + 36);
  *v20 &= ~4u;
  if ( v21 != a1 )
    get_radio_state(a1);
  if ( (int16_t)**(volatile uint16_t **) off_1022E4 < 0 && a1 > 1 )
  {
    mmio_clear_register((int)aBandPhyBandMax, (int)aPhyHwSetChanne_0, 5664);
    goto LABEL_42;
  }
  if ( a1 )
  {
LABEL_42:
    _frame.v168 = (void *)(uintptr_t)(off_1025D0);
    v101 = (void *)(uintptr_t)(off_1025D0);
    bb_disable(r2_0);
    if ( v101[1] )
      disable_interrupt();
    if ( a4 )
    {
      if ( a4 == 1 )
        *(volatile uint32_t *)off_102958 = *(volatile uint32_t *)off_102958 & 0xFFFFFFC7 | 0x18;
      else
        *(volatile uint32_t *)off_1025D4 = *(volatile uint32_t *)off_1025D4 & 0xFFFFFFC7 | 0x20;
    }
    else
    {
      *(volatile uint32_t *)off_102958 = *(volatile uint32_t *)off_102958 & 0xFFFFFFC7 | 0x10;
    }
    goto LABEL_18;
  }
  _frame.v168 = (void *)(uintptr_t)(off_1022E8);
  v22 = (void *)(uintptr_t)(off_1022E8);
  bb_enable(r2_0, a4);
  if ( v22[1] )
    enable_interrupt();
  if ( a4 )
  {
    if ( a4 == 1 )
      *(volatile uint32_t *)off_1022EC = *(volatile uint32_t *)off_1022EC & 0xFFFFFFC7 | 8;
  }
  else
  {
    *(volatile uint32_t *)off_102958 &= 0xFFFFFFC7;
  }
LABEL_18:
  v23 = (*(volatile uint32_t *)off_1022F0 >> 5) & 0x1F;
  if ( (*(volatile uint32_t *)off_1022F0 & 0x400) != 0 )
    v23 *= 2;
  if ( (*(volatile uint32_t *)off_1022F4 & 0x80000) != 0 && (*(volatile uint32_t *)off_1022F4 & 0x40000) != 0 )
    v23 >>= 1;
  v24 = *(volatile uint8_t *)off_1022F8 * v23;
  if ( !a1 )
  {
    v25 = int_to_double(r2_0);
    v26 = int_to_double(v24);
    v27 = aeabi_dadd(v25, v25);
    v28 = (v28 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1022FC) << 32);
    v29 = v27;
    v28 = (v28 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v30 = ((uint64_t (*)())double_add_1)(v26, v28);
    v31 = ((uint64_t (*)())double_subtract)(v29, v30);
    v32 = (v32 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102300) << 32);
    v32 = (v32 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v33 = ((uint64_t (*)())double_add_1)(v31, v32);
    v34 = double_add(v33);
    v35 = ((int (*)(uint64_t))double_to_int)(v34);
    v36 = (v36 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1022FC) << 32);
    v36 = (v36 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v29 = (v29 & ~0xFFFFFFFFull) | ((uint32_t)(v35) & 0xFFFFFFFFu);
    v37 = ((uint64_t (*)())double_subtract)(v25, v36);
    v38 = double_add(v37);
    v39 = uint_to_double(v29);
    v40 = (v40 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1022FC) << 32);
    v40 = (v40 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v41 = ((uint64_t (*)())double_add_1)(v39, v40);
    v42 = (v42 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102304) << 32);
    v42 = (v42 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v43 = ((uint64_t (*)())double_add_1)(v41, v42);
    v44 = ((uint64_t (*)())double_add_1)(v43, v26);
    v45 = (v45 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v45 = (v45 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102308) << 32);
    v46 = ((uint64_t (*)())double_add_1)(v44, v45);
    rf_set_tx_power(0);
    v47 = (volatile unsigned int *)off_102310;
    *(volatile uint32_t *)off_10230C = v29 & 0x7FFFFFFF;
    v48 = ((int (*)(uint64_t))double_to_int)(v38);
    v49 = (void *)(uintptr_t)(off_10231C);
    *v47 = dword_102318 & *v47 | dword_102314 & (v48 << 13);
    *v49 |= 1u;
LABEL_25:
    v50 = (v50 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102320) << 32);
    v51 = (volatile unsigned int *)off_102324;
    v50 = (v50 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v52 = ((uint64_t (*)())double_subtract)(v50, v46);
    v53 = double_add(v52);
    *v51 = ((int (*)(uint64_t))double_to_float_1)(v53) & 0xFFFFFFF | *v51 & 0xF0000000;
    v54 = 0;
    v55 = ((uint64_t (*)())double_subtract)(v46, *(volatile uint64_t *)&dword_1022B0);
    goto LABEL_26;
  }
  v129 = int_to_double(r2_0);
  v130 = int_to_double(v24);
  v131 = (v131 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10290C) << 32);
  v132 = (volatile unsigned int *)off_102910;
  v131 = (v131 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v133 = v130;
  v134 = ((uint64_t (*)())double_add_1)(v130, v131);
  v135 = ((uint64_t (*)())double_subtract)(v129, v134);
  v136 = (v136 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102914) << 32);
  v136 = (v136 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v137 = ((uint64_t (*)())double_add_1)(v135, v136);
  v138 = double_add(v137);
  v139 = ((int (*)(uint64_t))double_to_int)(v138);
  v140 = (v140 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102918) << 32);
  v140 = (v140 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v141 = v139;
  v142 = ((uint64_t (*)())double_subtract)(v129, v140);
  v143 = double_add(v142);
  v144 = uint_to_double(v141);
  v145 = (v145 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10290C) << 32);
  v145 = (v145 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v146 = ((uint64_t (*)())double_add_1)(v144, v145);
  v147 = ((uint64_t (*)())double_add_1)(v146, v133);
  v148 = (v148 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v148 = (v148 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10291C) << 32);
  v46 = ((uint64_t (*)())double_add_1)(v147, v148);
  rf_set_tx_power(0);
  *(volatile uint32_t *)off_102920 = v141 & 0x7FFFFFFF;
  v149 = ((int (*)(uint64_t))double_to_int)(v143);
  v150 = (void *)(uintptr_t)(off_10292C);
  *v132 = dword_102928 & *v132 | dword_102924 & (v149 << 13);
  *v150 |= 1u;
  if ( a1 != 1 )
    goto LABEL_25;
  v151 = (v151 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102930) << 32);
  v152 = (volatile unsigned int *)off_102934;
  v151 = (v151 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v153 = ((uint64_t (*)())double_subtract)(v151, v46);
  v154 = double_add(v153);
  *v152 = *v152 & 0xF0000000 | ((int (*)(uint64_t))double_to_float_1)(v154) & 0xFFFFFFF;
  v155 = (v155 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v155 = (v155 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102938) << 32);
  v54 = 1;
  v55 = ((uint64_t (*)())double_subtract)(v46, v155);
LABEL_26:
  v56 = (v56 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102328) << 32);
  v56 = (v56 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
if ( ((int (*)())double_ge)(v55, v56) ) { v162 = ((uint64_t (*)())double_add_1)(v55, 0x4180000000000000uLL);
    v163 = (v163 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102954) << 32);
    v163 = (v163 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v164 = ((uint64_t (*)())double_subtract)(v162, v163);
    v165 = double_add(v164);
    v63 = ((int (*)(uint64_t))double_to_float_1)(v165);
    v64 = 0x20000000;
  }
  else
  {
    v57 = (v57 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10232C) << 32);
    v57 = (v57 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v58 = ((int (*)())double_ge)(v55, v57);
    v59 = ((uint64_t (*)())double_add_1)(v55, 0x4180000000000000uLL);
    if ( v58 )
    {
      v60 = (v60 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10232C) << 32);
      v60 = (v60 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v61 = ((uint64_t (*)())double_subtract)(v59, v60);
      v62 = double_add(v61);
      v63 = ((int (*)(uint64_t))double_to_float_1)(v62);
      v64 = 0x10000000;
    }
    else
    {
      v159 = (v159 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102950) << 32);
      v159 = (v159 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v160 = ((uint64_t (*)())double_subtract)(v59, v159);
      v161 = double_add(v160);
      v63 = ((int (*)(uint64_t))double_to_float_1)(v161);
      v64 = 0;
    }
  }
  v65 = (void *)(uintptr_t)(off_102334);
  v66 = (volatile unsigned int *)off_102338;
  v67 = (volatile unsigned int *)off_102340;
  *(volatile uint32_t *)off_102330 = v63 & 0xFFFFFFF;
  *v65 = *v65 & 0xFFFFFFF | v64;
  *v66 = *v66 & 0xFFFFFFFC | v54;
  v68 = int_to_double(a2);
  v69 = aeabi_dadd(v68, v46);
  v70 = int_to_double(r2_0);
  v71 = ((uint64_t (*)())double_compare_wrapper)(v69, v70);
  v72 = (v72 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10233C) << 32);
  v73 = (volatile unsigned int *)off_102344;
  v72 = (v72 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v74 = ((uint64_t (*)())double_subtract)(v72, v46);
  v75 = (v75 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v75 = (v75 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102304) << 32);
  v76 = aeabi_dadd(v74, v75);
  _frame.v167 = *v67;
  *v67 = _frame.v167 & 0xFFFF8000 | ((int (*)(uint64_t))double_to_int)(v76) & 0x7FFF;
  v77 = (v77 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v77 = (v77 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1025A0) << 32);
  v78 = ((uint64_t (*)())double_add_1)(v46, v77);
  v79 = ((uint64_t (*)())double_subtract)(v78, v71);
  v80 = (v80 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1025A4) << 32);
  v81 = *v73;
  v80 = (v80 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v82 = aeabi_dadd(v79, v80);
  *v73 = (uint16_t)((int (*)(uint64_t))double_to_int)(v82) | (HIWORD(v81) << 16);
  v83 = (v83 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1025A8) << 32);
  v83 = (v83 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v84 = ((uint64_t (*)())double_subtract)(v83, v71);
  v85 = (v85 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1025A4) << 32);
  v85 = (v85 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v86 = aeabi_dadd(v84, v85);
  *v73 = *v73 & 0x8000FFFF | dword_1025AC & (((int (*)(uint64_t))double_to_int)(v86) << 16);
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
  v93 = (volatile unsigned int *)off_1025B0;
  v94 = (void *)(uintptr_t)(off_1025B4);
  v95 = (volatile unsigned int *)off_1025B8;
  *(volatile uint32_t *)off_1025B0 = *(volatile uint32_t *)off_1025B0 & 0xFFFFFFCF | v87;
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
  v99 = (void *)(uintptr_t)(off_1025C4);
  *(volatile uint32_t *)off_1025C0 = 4;
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
    v46 = (v46 & ~0xFFFFFFFFull) | ((uint32_t)(v166 + 1168) & 0xFFFFFFFFu);
    if ( r2_0 > 0x143B )
      v46 = (v46 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(1) << 32);
    v100 = v166 + 16;
    if ( r2_0 <= 0x143B )
      v46 = (v46 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(0) << 32);
  }
  else
  {
    v100 = 2544;
    v46 = 0x200000E70LL;
  }
  if ( rx_rate_field_parse(7u) == 1 || rx_rate_field_parse(6u) == 3 )
  {
    v103 = (void *)(uintptr_t)(off_1025DC);
    v104 = (void *)(uintptr_t)(off_1025E0);
    v105 = (void *)(uintptr_t)(off_1025E4);
    v106 = (void *)(uintptr_t)(off_1025E8);
    v107 = (void *)(uintptr_t)(off_1025EC);
    *(volatile uint32_t *)off_1025DC |= 0x20000u;
    *v104 += 200000;
    *v105 += 200000;
    *v106 += 200000;
    *v107 += 200000;
    v108 = v104 + 8234;
    v109 = v105 + 8234;
    *(v103 - 194) += 200000;
    event_dispatch("process rx1: %x %x\n", *v108, *v109);
    if ( *v109 == *v108 )
    {
LABEL_60:
      v111 = (void *)(uintptr_t)(off_1028EC);
      v112 = (void *)(uintptr_t)(off_1028F0);
      event_dispatch("process rx2: %x, %x\n", *(volatile uint32_t *)off_1028EC, *(volatile uint32_t *)off_1028F0);
      while ( *v112 != *v111 )
        ;
      v113 = (void *)(uintptr_t)(off_1028FC);
      event_dispatch(aProcessRxEnd, v112);
      v114 = (volatile uint16_t *)off_10295C;
      v115 = ((volatile uint32_t *)(uintptr_t)off_102900)[1];
      v116 = ((volatile uint32_t *)(uintptr_t)off_102900)[2];
      _frame.v169[0] = ((volatile uint32_t *)(uintptr_t)off_102900)[0];
      _frame.v169[1] = v115;
      _frame.v169[2] = v116;
      v117 = ((volatile uint32_t *)(uintptr_t)off_102900)[5];
      v118 = ((volatile uint32_t *)(uintptr_t)off_102900)[6];
      v119 = ((volatile uint32_t *)(uintptr_t)off_102900)[7];
      _frame.v169[3] = ((volatile uint32_t *)(uintptr_t)off_102900)[4];
      _frame.v169[4] = v117;
      _frame.v169[5] = v118;
      _frame.v169[6] = v119;
      v120 = ((volatile uint32_t *)(uintptr_t)off_102900)[9];
      v121 = ((volatile uint32_t *)(uintptr_t)off_102900)[10];
      v122 = ((volatile uint32_t *)(uintptr_t)off_102900)[11];
      _frame.v169[7] = ((volatile uint32_t *)(uintptr_t)off_102900)[8];
      _frame.v169[8] = v120;
      _frame.v169[9] = v121;
      _frame.v169[10] = v122;
      v123 = ((volatile uint32_t *)(uintptr_t)off_102900)[12];
      v124 = ((volatile uint32_t *)(uintptr_t)off_102900)[13];
      v125 = ((volatile uint32_t *)(uintptr_t)off_102900)[14];
      v126 = ((volatile uint32_t *)(uintptr_t)off_102900)[15];
      v127 = off_10295C + 8 * HIDWORD(v46);
      *(volatile uint8_t *)(v127 + 4) = 1;
      _frame.v169[11] = v123;
      _frame.v169[12] = v124;
      _frame.v169[13] = v125;
      _frame.v169[14] = v126;
      v128 = off_102904;
      *v113 |= 0x8000u;
      *v113 |= 0x2000u;
      boot_init((int)_frame.v169, v128, 0, 0, v114, 6, 1);
      *v113 &= ~0x8000u;
      *v113 &= ~0x2000u;
      *(volatile uint8_t *)(v127 + 4) = 0;
      if ( r2_0 <= 0x1387 )
      {
        bt_enable(0, r2_0);
        if ( _frame.v168[13] )
          _frame.v168[15] |= 1u;
      }
      else
      {
        bt_enable(1, r2_0);
      }
      *(volatile uint32_t *)off_102908 &= ~0x20000u;
      return bt_control_set((int)off_1025D8 + v100, (int)off_1025D8 + v46);
    }
    while ( 1 )
    {
      while ( 1 )
      {
        radio_init(1);
        v110 = **(volatile uint8_t **)off_1028E8;
        if ( v110 != 1 )
          break;
        bt_scheduler_run();
LABEL_55:
        if ( *v109 == *v108 )
          goto LABEL_60;
      }
      if ( v110 != 2 && v110 != 4 )
        goto LABEL_55;
      call_checked();
      if ( *v109 == *v108 )
        goto LABEL_60;
    }
  }
  return bt_control_set((int)off_1025D8 + v100, (int)off_1025D8 + v46);
}


// mmio_write_40580020 @ 0x102960
int mmio_write_40580020() {
  volatile int *v0; // r3
  volatile int *v1; // r2
  volatile int *v2; // r1
  volatile int *v3; // r3
  int v4; // r2

  event_queue_check();
  v0 = (volatile int *)off_1029C8;
  *(volatile uint32_t *)off_1029C8 = dword_1029CC;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_1029D0;
  v1 = (volatile int *)off_1029C8;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_1029D4;
  v2 = (volatile int *)off_1029C8;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  tx_packet_handler((unsigned int)*v2 >> 31, 2437, 0x985u, (unsigned int)*v2 >> 31, *v2 < 0, *v2 < 0);
  v3 = (volatile int *)off_1029DC;
  v4 = dword_1029E0;
  *(volatile uint32_t *)off_1029D8 = 12;
  *v3 = v4;
  return 12;
}


// periph_init @ 0x1029e4
int periph_init(volatile int *a1) {
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  volatile uint32_t *v6; // r6
  int v7; // r7
  volatile int *v8; // r5
  int result; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3

  clock_enable();
  bt_enable(0, 2412);
  mmio_write_40580020();
  v2 = *a1;
  v3 = a1[1];
  v4 = a1[2];
  v5 = a1[3];
  a1 += 4;
  v6 = (void *)(uintptr_t)(off_102A18);
  v7 = dword_102A1C;
  v8 = (volatile int *)off_102A18;
  *(volatile uint32_t *)off_102A18 = v2;
  v8[1] = v3;
  v8[2] = v4;
  v8[3] = v5;
  v8 += 4;
  result = *a1;
  v10 = a1[1];
  v11 = a1[2];
  v12 = a1[3];
  *v8 = *a1;
  v8[1] = v10;
  v8[2] = v11;
  v8[3] = v12;
  v8[4] = a1[4];
  v6[9] = v7;
  v6[10] = 16711935;
  return result;
}


// rf_enable @ 0x102a20
/* luna: Applies a PHY channel configuration for radio 0 when it differs from the cached settings, and skips redundant updates. */
int rf_enable(volatile uint16_t *a1, int a2) {
  volatile uint8_t *v3; // r0
  int v4; // r1
  int v5; // r1
  unsigned int v6; // r2
  int a5; // r3
  int result; // r0
  int v9; // r1
  int v10; // r3

  if ( a2 )
    return event_dispatch("\x9B\x87%s: radio %d does not exist\n", aPhySetChannel, a2);
  if ( *(volatile uint8_t *)off_102AB8 )
    goto LABEL_4;
  v3 = (volatile uint8_t *)off_102AC0;
  v4 = *((volatile uint16_t *)off_102AC0 + 18);
  *(volatile uint32_t *)off_102ABC &= ~0x200u;
  if ( v4 != *a1 )
    goto LABEL_4;
  a5 = *((volatile uint8_t *)a1 + 9);
  v5 = a1[1];
  if ( v3[45] != a5 )
  {
    v6 = a1[2];
    goto LABEL_5;
  }
  v6 = a1[2];
  if ( *((volatile uint16_t *)v3 + 19) != v5
    || *((volatile uint16_t *)v3 + 20) != v6
    || *((volatile uint16_t *)v3 + 21) != a1[3] )
  {
    goto LABEL_5;
  }
  if ( rx_rate_field_parse(7u) == 1 || rx_rate_field_parse(6u) == 3 )
  {
LABEL_4:
    v5 = a1[1];
    v6 = a1[2];
    a5 = (a5 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)a1 + 9)) & 0xFFu);
LABEL_5:
    tx_packet_handler(*(volatile uint8_t *)a1, v5, v6, *((volatile uint8_t *)a1 + 1), a5, 0);
    result = *(volatile uint32_t *)a1;
    v9 = *((volatile uint32_t *)a1 + 1);
    v10 = dword_102AC4;
    *(volatile uint32_t *)dword_102AC4 = *(volatile uint32_t *)a1;
    *(volatile uint32_t *)(v10 + 4) = v9;
    *(volatile uint16_t *)(v10 + 8) = a1[4];
    return result;
  }
  return event_dispatch("\x9D\x87%s: Setting same channel, do nothing\n", aPhySetChannel);
}


// handle_event @ 0x102ad4
int handle_event() {
  int result; // r0
  volatile int *i; // r4

  result = bt_enable(*((volatile uint8_t *)off_102B04 + 36), *((volatile uint16_t *)off_102B04 + 20));
  for ( i = *((volatile int **)off_102B08 + 2); i; i = (volatile int *)*i )
  {
    while ( !*((volatile uint8_t *)i + 108) )
    {
      i = (volatile int *)*i;
      if ( !i )
        return result;
    }
    result = rf_temperature_comp((int)(uintptr_t)(i));
  }
  return result;
}



// is_magic_value @ 0x102b0c
int is_magic_value(unsigned int a1) {
  if ( a1 > 0x1666 )
    return 5;
  if ( a1 > 0x1616 )
    return 4;
  if ( a1 > 0x15C6 )
    return 3;
  if ( a1 > 0x1571 )
    return 2;
  return a1 > 0x1486;
}



// get_calibration_offsets @ 0x102b4c
volatile uint8_t * get_calibration_offsets(volatile uint8_t *result, volatile uint8_t *a2) {
  volatile uint8_t *v2; // r3

  v2 = (void *)(uintptr_t)(off_102B5C);
  *result = *((volatile uint8_t *)off_102B5C + 294);
  *a2 = v2[295];
  return result;
}



// get_hw_clock_multiplier @ 0x102b60
int get_hw_clock_multiplier() {
  return (uint8_t)((1 << ((uint8_t)*(volatile uint32_t *)off_102B7C >> 4)) - 1);
}



// write_phy_config @ 0x102b80
unsigned int write_phy_config(uint8_t a1) {
  volatile unsigned int *v1; // r1
  volatile unsigned int *v2; // r2
  uint8_t v3; // r0
  unsigned int result; // r0

  v1 = (volatile unsigned int *)off_102BB8;
  v2 = (volatile unsigned int *)off_102BBC;
  *(volatile uint32_t *)off_102BB8 = *(volatile uint32_t *)off_102BB8 & 0xFFFFFF00 | a1;
  *v2 = *v2 & 0xFFFFFF00 | a1;
  v3 = a1 - 3;
  *v1 = *v1 & 0xFFF00FFF | (v3 << 12);
  result = *v2 & 0xFFF00FFF | (v3 << 12);
  *v2 = result;
  return result;
}



