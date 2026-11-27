// rf_calibrate_tx @ 0x101ec0
void rf_calibrate_tx( unsigned int a1, unsigned int a2, unsigned int r2_0, unsigned int a4, uint8_t a5, uint8_t a6) {
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
  volatile uint32_t *v102; // r2
  volatile uint32_t *v103; // r6
  volatile uint32_t *v104; // r5
  volatile uint32_t *v105; // r0
  volatile uint32_t *v106; // r1
  volatile uint32_t *v107; // r6
  volatile uint32_t *v108; // r5
  int v109; // r3
  volatile uint32_t *v110; // r6
  volatile uint32_t *v111; // r5
  volatile uint32_t *v112; // r6
  volatile uint16_t *v113; // r12
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
  volatile unsigned int *v131; // r7
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
  volatile uint32_t *v149; // r2
  uint64_t v150; // r0
  volatile unsigned int *v151; // r6
  uint64_t v152; // r0
  uint64_t v153; // r0
  uint64_t v154; // r2
  uint64_t v155; // r0
  volatile unsigned int *v156; // r7
  uint64_t v157; // r0
  uint64_t v158; // r2
  uint64_t v159; // r0
  uint64_t v160; // r0
  uint64_t v161; // r0
  uint64_t v162; // r2
  uint64_t v163; // r0
  uint64_t v164; // r0
  int v165; // r9
  struct __attribute__((packed)) { unsigned int v166; // [sp+20h] [bp-4Ch]
  volatile uint8_t *v167; // [sp+24h] [bp-48h]
  char _pad2[4]; uint32_t v168[16]; // [sp+2Ch] [bp-40h] BYREF
  } _frame;
  alloc_tx_event("\x9D\x87%s: band=%d freq=%d freq1=%d chantype=%d sx=%d\n", aPhyHwSetChanne, a1, a2, r2_0, a4, a6);
  if ( **(volatile uint8_t **)off_102210 != 3 )
    check_feature_flag(4, "setch:%d\r\n", r2_0);
  variant_update_cache(a4);
  save_and_call_handler(a1, a2, r2_0, a4, a5);
  v11 = global_state_get_byte();
  v12 = v11;
  if ( v11 == 240 )
  {
    if ( a4 <= 1 )
      v155 = (v155 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102894) << 32);
    else
      v155 = (v155 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102890) << 32);
    v156 = (volatile unsigned int *)off_102898;
    v155 = (v155 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v157 = double_exp_check(v155);
    *v156 = *v156 & 0xC00FFFFF | dword_10289C & (((int (*)(uint64_t))double_to_uint32)(v157) << 20);
  }
  else
  {
    v13 = signed_int_to_double(v11);
    if ( a4 > 1 )
      v14 = ((uint64_t (*)())double_multiply)(v13, *(volatile uint64_t *)&dword_1024E8);
    else
      v14 = ((uint64_t (*)())double_multiply)(v13, *(volatile uint64_t *)&dword_1021F8);
    v15 = ((int (*)(uint64_t))double_to_float)(v14);
    v16 = ((uint64_t (*)())float_to_double)(v15);
    v17 = (volatile unsigned int *)off_102218;
    v18 = double_exp_check(v16);
    *v17 = *v17 & 0xF003FFFF | dword_10221C & (((int (*)(uint64_t))double_to_uint32)(v18) << 18);
  }
  if ( a1 )
    v19 = (void *)(uintptr_t)(off_10288C);
  else
    v19 = (void *)(uintptr_t)(off_102220);
  *(volatile uint32_t *)off_102224 = (uint16_t)*(volatile uint32_t *)off_102224
                        | (((*v19 >> 8) - (uint16_t)(((*(volatile uint32_t *)off_102218 >> 18) & 0x3FF) + v12)) << 16);
  v20 = (void *)(uintptr_t)(off_10222C);
  *(volatile uint32_t *)off_102228 = *(volatile uint32_t *)off_102228 & 0xFFFE1FFF | 0xE000;
  v21 = *((volatile uint8_t *)off_102230 + 36);
  *v20 &= ~4u;
  if ( v21 != a1 )
    read_radio_status_flag(a1);
  if ( **(volatile uint16_t **)off_102234 < 0 && a1 > 1 )
  {
    irq_disable_mmio_write((int)aBandPhyBandMax, (int)aPhyHwSetChanne_0, 5664);
    goto LABEL_42;
  }
  if ( a1 )
  {
LABEL_42:
    _frame.v167 = (void *)(uintptr_t)(off_102520);
    v101 = (void *)(uintptr_t)(off_102520);
    mmio_ahb_gate_release_n_60(r2_0);
    if ( v101[1] )
      mmio_clear_bit();
    if ( a4 )
    {
      if ( a4 == 1 )
        *(volatile uint32_t *)off_1028A8 = *(volatile uint32_t *)off_1028A8 & 0xFFFFFFC7 | 0x18;
      else
        *(volatile uint32_t *)off_102524 = *(volatile uint32_t *)off_102524 & 0xFFFFFFC7 | 0x20;
    }
    else
    {
      *(volatile uint32_t *)off_1028A8 = *(volatile uint32_t *)off_1028A8 & 0xFFFFFFC7 | 0x10;
    }
    goto LABEL_18;
  }
  _frame.v167 = (void *)(uintptr_t)(off_102238);
  v22 = (void *)(uintptr_t)(off_102238);
  arm_core_enable(r2_0, a4);
  if ( v22[1] )
    mmio_set_bit();
  if ( a4 )
  {
    if ( a4 == 1 )
      *(volatile uint32_t *)off_10223C = *(volatile uint32_t *)off_10223C & 0xFFFFFFC7 | 8;
  }
  else
  {
    *(volatile uint32_t *)off_1028A8 &= 0xFFFFFFC7;
  }
LABEL_18:
  v23 = (*(volatile uint32_t *)off_102240 >> 5) & 0x1F;
  if ( (*(volatile uint32_t *)off_102240 & 0x400) != 0 )
    v23 *= 2;
  if ( (*(volatile uint32_t *)off_102244 & 0x80000) != 0 && (*(volatile uint32_t *)off_102244 & 0x40000) != 0 )
    v23 >>= 1;
  v24 = *(volatile uint8_t *)off_102248 * v23;
  if ( !a1 )
  {
    v25 = signed_int_to_double(r2_0);
    v26 = signed_int_to_double(v24);
    v27 = double_add(v25, v25);
    v28 = (v28 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10224C) << 32);
    v29 = v27;
    v28 = (v28 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v30 = ((uint64_t (*)())double_multiply)(v26, v28);
    v31 = ((uint64_t (*)())double_divide)(v29, v30);
    v32 = (v32 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102250) << 32);
    v32 = (v32 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v33 = ((uint64_t (*)())double_multiply)(v31, v32);
    v34 = double_exp_check(v33);
    v35 = ((int (*)(uint64_t))double_to_uint32)(v34);
    v36 = (v36 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10224C) << 32);
    v36 = (v36 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v29 = (v29 & ~0xFFFFFFFFull) | ((uint32_t)(v35) & 0xFFFFFFFFu);
    v37 = ((uint64_t (*)())double_divide)(v25, v36);
    v38 = double_exp_check(v37);
    v39 = unsigned_int_to_double(v29);
    v40 = (v40 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10224C) << 32);
    v40 = (v40 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v41 = ((uint64_t (*)())double_multiply)(v39, v40);
    v42 = (v42 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102254) << 32);
    v42 = (v42 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v43 = ((uint64_t (*)())double_multiply)(v41, v42);
    v44 = ((uint64_t (*)())double_multiply)(v43, v26);
    v45 = (v45 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v45 = (v45 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102258) << 32);
    v46 = ((uint64_t (*)())double_multiply)(v44, v45);
    set_clock_divider(0);
    v47 = (volatile unsigned int *)off_102260;
    *(volatile uint32_t *)off_10225C = v29 & 0x7FFFFFFF;
    v48 = ((int (*)(uint64_t))double_to_uint32)(v38);
    v49 = (void *)(uintptr_t)(off_10226C);
    *v47 = dword_102268 & *v47 | dword_102264 & (v48 << 13);
    *v49 |= 1u;
LABEL_25:
    v50 = (v50 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102270) << 32);
    v51 = (volatile unsigned int *)off_102274;
    v50 = (v50 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v52 = ((uint64_t (*)())double_divide)(v50, v46);
    v53 = double_exp_check(v52);
    *v51 = ((int (*)(uint64_t))double_to_float_1)(v53) & 0xFFFFFFF | *v51 & 0xF0000000;
    v54 = 0;
    v55 = ((uint64_t (*)())double_divide)(v46, *(volatile uint64_t *)&dword_102200);
    goto LABEL_26;
  }
  v128 = signed_int_to_double(r2_0);
  v129 = signed_int_to_double(v24);
  v130 = (v130 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10285C) << 32);
  v131 = (volatile unsigned int *)off_102860;
  v130 = (v130 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v132 = v129;
  v133 = ((uint64_t (*)())double_multiply)(v129, v130);
  v134 = ((uint64_t (*)())double_divide)(v128, v133);
  v135 = (v135 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102864) << 32);
  v135 = (v135 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v136 = ((uint64_t (*)())double_multiply)(v134, v135);
  v137 = double_exp_check(v136);
  v138 = ((int (*)(uint64_t))double_to_uint32)(v137);
  v139 = (v139 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102868) << 32);
  v139 = (v139 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v140 = v138;
  v141 = ((uint64_t (*)())double_divide)(v128, v139);
  v142 = double_exp_check(v141);
  v143 = unsigned_int_to_double(v140);
  v144 = (v144 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10285C) << 32);
  v144 = (v144 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v145 = ((uint64_t (*)())double_multiply)(v143, v144);
  v146 = ((uint64_t (*)())double_multiply)(v145, v132);
  v147 = (v147 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v147 = (v147 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10286C) << 32);
  v46 = ((uint64_t (*)())double_multiply)(v146, v147);
  set_clock_divider(0);
  *(volatile uint32_t *)off_102870 = v140 & 0x7FFFFFFF;
  v148 = ((int (*)(uint64_t))double_to_uint32)(v142);
  v149 = (void *)(uintptr_t)(off_10287C);
  *v131 = dword_102878 & *v131 | dword_102874 & (v148 << 13);
  *v149 |= 1u;
  if ( a1 != 1 )
    goto LABEL_25;
  v150 = (v150 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102880) << 32);
  v151 = (volatile unsigned int *)off_102884;
  v150 = (v150 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v152 = ((uint64_t (*)())double_divide)(v150, v46);
  v153 = double_exp_check(v152);
  *v151 = *v151 & 0xF0000000 | ((int (*)(uint64_t))double_to_float_1)(v153) & 0xFFFFFFF;
  v154 = (v154 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v154 = (v154 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102888) << 32);
  v54 = 1;
  v55 = ((uint64_t (*)())double_divide)(v46, v154);
LABEL_26:
  v56 = (v56 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102278) << 32);
  v56 = (v56 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
if ( ((int (*)())double_greater_equal)(v55, v56) ) { v161 = ((uint64_t (*)())double_multiply)(v55, 0x4180000000000000uLL);
    v162 = (v162 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1028A4) << 32);
    v162 = (v162 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v163 = ((uint64_t (*)())double_divide)(v161, v162);
    v164 = double_exp_check(v163);
    v63 = ((int (*)(uint64_t))double_to_float_1)(v164);
    v64 = 0x20000000;
  }
  else
  {
    v57 = (v57 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10227C) << 32);
    v57 = (v57 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v58 = ((int (*)())double_greater_equal)(v55, v57);
    v59 = ((uint64_t (*)())double_multiply)(v55, 0x4180000000000000uLL);
    if ( v58 )
    {
      v60 = (v60 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10227C) << 32);
      v60 = (v60 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v61 = ((uint64_t (*)())double_divide)(v59, v60);
      v62 = double_exp_check(v61);
      v63 = ((int (*)(uint64_t))double_to_float_1)(v62);
      v64 = 0x10000000;
    }
    else
    {
      v158 = (v158 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1028A0) << 32);
      v158 = (v158 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v159 = ((uint64_t (*)())double_divide)(v59, v158);
      v160 = double_exp_check(v159);
      v63 = ((int (*)(uint64_t))double_to_float_1)(v160);
      v64 = 0;
    }
  }
  v65 = (void *)(uintptr_t)(off_102284);
  v66 = (volatile unsigned int *)off_102288;
  v67 = (volatile unsigned int *)off_102290;
  *(volatile uint32_t *)off_102280 = v63 & 0xFFFFFFF;
  *v65 = *v65 & 0xFFFFFFF | v64;
  *v66 = *v66 & 0xFFFFFFFC | v54;
  v68 = signed_int_to_double(a2);
  v69 = double_add(v68, v46);
  v70 = signed_int_to_double(r2_0);
  v71 = ((uint64_t (*)())double_compare_neg)(v69, v70);
  v72 = (v72 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10228C) << 32);
  v73 = (volatile unsigned int *)off_102294;
  v72 = (v72 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v74 = ((uint64_t (*)())double_divide)(v72, v46);
  v75 = (v75 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v75 = (v75 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102254) << 32);
  v76 = double_add(v74, v75);
  _frame.v166 = *v67;
  *v67 = _frame.v166 & 0xFFFF8000 | ((int (*)(uint64_t))double_to_uint32)(v76) & 0x7FFF;
  v77 = (v77 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v77 = (v77 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024F0) << 32);
  v78 = ((uint64_t (*)())double_multiply)(v46, v77);
  v79 = ((uint64_t (*)())double_divide)(v78, v71);
  v80 = (v80 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024F4) << 32);
  v81 = *v73;
  v80 = (v80 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v82 = double_add(v79, v80);
  *v73 = (uint16_t)((int (*)(uint64_t))double_to_uint32)(v82) | (HIWORD(v81) << 16);
  v83 = (v83 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024F8) << 32);
  v83 = (v83 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v84 = ((uint64_t (*)())double_divide)(v83, v71);
  v85 = (v85 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024F4) << 32);
  v85 = (v85 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v86 = double_add(v84, v85);
  *v73 = *v73 & 0x8000FFFF | dword_1024FC & (((int (*)(uint64_t))double_to_uint32)(v86) << 16);
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
  v93 = (volatile unsigned int *)off_102500;
  v94 = (void *)(uintptr_t)(off_102504);
  v95 = (volatile unsigned int *)off_102508;
  *(volatile uint32_t *)off_102500 = *(volatile uint32_t *)off_102500 & 0xFFFFFFCF | v87;
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
  v99 = (void *)(uintptr_t)(off_102514);
  *(volatile uint32_t *)off_102510 = 4;
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
    v46 = (v46 & ~0xFFFFFFFFull) | ((uint32_t)(v165 + 1168) & 0xFFFFFFFFu);
    if ( r2_0 > 0x143B )
      v46 = (v46 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(1) << 32);
    v100 = v165 + 16;
    if ( r2_0 <= 0x143B )
      v46 = (v46 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(0) << 32);
  }
  else
  {
    v100 = 2544;
    v46 = 0x200000E70LL;
  }
  if ( hci_cmd_handler(7u) == 1 || hci_cmd_handler(6u) == 3 )
  {
    v102 = (void *)(uintptr_t)(off_10252C);
    v103 = (void *)(uintptr_t)(off_102530);
    v104 = (void *)(uintptr_t)(off_102534);
    v105 = (void *)(uintptr_t)(off_102538);
    v106 = (void *)(uintptr_t)(off_10253C);
    *(volatile uint32_t *)off_10252C |= 0x20000u;
    *v103 += 200000;
    *v104 += 200000;
    *v105 += 200000;
    *v106 += 200000;
    v107 = v103 + 8234;
    v108 = v104 + 8234;
    *(v102 - 194) += 200000;
    alloc_tx_event("process rx1: %x %x\n", *v107, *v108);
    if ( *v108 == *v107 )
    {
LABEL_60:
      v110 = (void *)(uintptr_t)(off_10283C);
      v111 = (void *)(uintptr_t)(off_102840);
      alloc_tx_event("process rx2: %x, %x\n", *(volatile uint32_t *)off_10283C, *(volatile uint32_t *)off_102840);
      while ( *v111 != *v110 )
        ;
      v112 = (void *)(uintptr_t)(off_10284C);
      alloc_tx_event(aProcessRxEnd, v111);
      v113 = (volatile uint16_t *)off_1028AC;
      v114 = ((volatile uint32_t *)(uintptr_t)off_102850)[1];
      v115 = ((volatile uint32_t *)(uintptr_t)off_102850)[2];
      _frame.v168[0] = ((volatile uint32_t *)(uintptr_t)off_102850)[0];
      _frame.v168[1] = v114;
      _frame.v168[2] = v115;
      v116 = ((volatile uint32_t *)(uintptr_t)off_102850)[5];
      v117 = ((volatile uint32_t *)(uintptr_t)off_102850)[6];
      v118 = ((volatile uint32_t *)(uintptr_t)off_102850)[7];
      _frame.v168[3] = ((volatile uint32_t *)(uintptr_t)off_102850)[4];
      _frame.v168[4] = v116;
      _frame.v168[5] = v117;
      _frame.v168[6] = v118;
      v119 = ((volatile uint32_t *)(uintptr_t)off_102850)[9];
      v120 = ((volatile uint32_t *)(uintptr_t)off_102850)[10];
      v121 = ((volatile uint32_t *)(uintptr_t)off_102850)[11];
      _frame.v168[7] = ((volatile uint32_t *)(uintptr_t)off_102850)[8];
      _frame.v168[8] = v119;
      _frame.v168[9] = v120;
      _frame.v168[10] = v121;
      v122 = ((volatile uint32_t *)(uintptr_t)off_102850)[12];
      v123 = ((volatile uint32_t *)(uintptr_t)off_102850)[13];
      v124 = ((volatile uint32_t *)(uintptr_t)off_102850)[14];
      v125 = ((volatile uint32_t *)(uintptr_t)off_102850)[15];
      v126 = off_1028AC + 8 * HIDWORD(v46);
      *(volatile uint8_t *)(v126 + 4) = 1;
      _frame.v168[11] = v122;
      _frame.v168[12] = v123;
      _frame.v168[13] = v124;
      _frame.v168[14] = v125;
      v127 = off_102854;
      *v112 |= 0x8000u;
      *v112 |= 0x2000u;
      rf_calibration_1((int)_frame.v168, v127, 0, 0, v113, 6, 1);
      *v112 &= ~0x8000u;
      *v112 &= ~0x2000u;
      *(volatile uint8_t *)(v126 + 4) = 0;
      if ( r2_0 <= 0x1387 )
      {
        sdio_irq_enable(0, r2_0);
        if ( _frame.v167[13] )
          _frame.v167[15] |= 1u;
      }
      else
      {
        sdio_irq_enable(1, r2_0);
      }
      *(volatile uint32_t *)off_102858 &= ~0x20000u;
      goto LABEL_52;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        dma_ring_init(1);
        v109 = **(volatile uint8_t **)off_102838;
        if ( v109 != 1 )
          break;
        rx_task();
LABEL_55:
        if ( *v108 == *v107 )
          goto LABEL_60;
      }
      if ( v109 != 2 && v109 != 4 )
        goto LABEL_55;
      util_call_deep();
      if ( *v108 == *v107 )
        goto LABEL_60;
    }
  }
LABEL_52:
  sdio_irq_mask_enable((int)off_102528 + v100, (int)off_102528 + v46);
}


// pll_clock_config @ 0x1028b0
int pll_clock_config() {
  volatile int *v0; // r3
  volatile int *v1; // r2
  volatile int *v2; // r1
  volatile int *v3; // r3
  int v4; // r2

  is_scan_active();
  v0 = (volatile int *)off_102918;
  *(volatile uint32_t *)off_102918 = dword_10291C;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_102920;
  v1 = (volatile int *)off_102918;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_102924;
  v2 = (volatile int *)off_102918;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  rf_calibrate_tx((unsigned int)*v2 >> 31, 0x985u, 0x985u, (unsigned int)*v2 >> 31, *v2 < 0, *v2 < 0);
  v3 = (volatile int *)off_10292C;
  v4 = dword_102930;
  *(volatile uint32_t *)off_102928 = 12;
  *v3 = v4;
  return 12;
}


// set_rf_channel @ 0x102934
void set_rf_channel(volatile int *a1) {
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int v5; // r3
  volatile uint32_t *v6; // r6
  int v7; // r7
  volatile int *v8; // r5
  int v9; // r1
  int v10; // r2
  int v11; // r3

  pll_enable();
  sdio_irq_enable(0, 2412);
  pll_clock_config();
  v2 = *a1;
  v3 = a1[1];
  v4 = a1[2];
  v5 = a1[3];
  a1 += 4;
  v6 = (void *)(uintptr_t)(off_102968);
  v7 = dword_10296C;
  v8 = (volatile int *)off_102968;
  *(volatile uint32_t *)off_102968 = v2;
  v8[1] = v3;
  v8[2] = v4;
  v8[3] = v5;
  v8 += 4;
  v9 = a1[1];
  v10 = a1[2];
  v11 = a1[3];
  *v8 = *a1;
  v8[1] = v9;
  v8[2] = v10;
  v8[3] = v11;
  v8[4] = a1[4];
  v6[9] = v7;
  v6[10] = 16711935;
}


// check_boot_flag @ 0x102970
int check_boot_flag(volatile uint16_t *a1, int a2) {
  volatile uint8_t *v3; // r0
  int v4; // r1
  unsigned int v5; // r1
  unsigned int v6; // r2
  int a5; // r3
  int result; // r0
  int v9; // r1
  int v10; // r3

  if ( a2 )
    return alloc_tx_event("\x9B\x87%s: radio %d does not exist\n", aPhySetChannel, a2);
  if ( *(volatile uint8_t *)off_102A08 )
    goto LABEL_4;
  v3 = (volatile uint8_t *)off_102A10;
  v4 = *((volatile uint16_t *)off_102A10 + 18);
  *(volatile uint32_t *)off_102A0C &= ~0x200u;
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
  if ( hci_cmd_handler(7u) == 1 || hci_cmd_handler(6u) == 3 )
  {
LABEL_4:
    v5 = a1[1];
    v6 = a1[2];
    a5 = (a5 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)a1 + 9)) & 0xFFu);
LABEL_5:
    rf_calibrate_tx(*(volatile uint8_t *)a1, v5, v6, *((volatile uint8_t *)a1 + 1), a5, 0);
    result = *(volatile uint32_t *)a1;
    v9 = *((volatile uint32_t *)a1 + 1);
    v10 = dword_102A14;
    *(volatile uint32_t *)dword_102A14 = *(volatile uint32_t *)a1;
    *(volatile uint32_t *)(v10 + 4) = v9;
    *(volatile uint16_t *)(v10 + 8) = a1[4];
    return result;
  }
  return alloc_tx_event("\x9D\x87%s: Setting same channel, do nothing\n", aPhySetChannel);
}


// rf_read_cal_values @ 0x102a24
int rf_read_cal_values() {
  int result; // r0
  volatile int *i; // r4

  result = sdio_irq_enable(*((volatile uint8_t *)off_102A54 + 36), *((volatile uint16_t *)off_102A54 + 20));
  for ( i = *((volatile int **)off_102A58 + 2); i; i = (volatile int *)*i )
  {
    while ( !*((volatile uint8_t *)i + 108) )
    {
      i = (volatile int *)*i;
      if ( !i )
        return result;
    }
    result = compute_byte_delta((int)(uintptr_t)(i));
  }
  return result;
}



// check_magic_value @ 0x102a5c
int check_magic_value(unsigned int a1) {
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



// get_calibration_offsets @ 0x102a9c
volatile uint8_t * get_calibration_offsets(volatile uint8_t *result, volatile uint8_t *a2) {
  volatile uint8_t *v2; // r3

  v2 = (void *)(uintptr_t)(off_102AAC);
  *result = *((volatile uint8_t *)off_102AAC + 294);
  *a2 = v2[295];
  return result;
}



// get_clock_prescaler @ 0x102ab0
int get_clock_prescaler() {
  return (uint8_t)((1 << ((uint8_t)*(volatile uint32_t *)off_102ACC >> 4)) - 1);
}



// rf_reg_write_byte @ 0x102ad0
unsigned int rf_reg_write_byte(uint8_t a1) {
  volatile unsigned int *v1; // r1
  volatile unsigned int *v2; // r2
  uint8_t v3; // r0
  unsigned int result; // r0

  v1 = (volatile unsigned int *)off_102B08;
  v2 = (volatile unsigned int *)off_102B0C;
  *(volatile uint32_t *)off_102B08 = *(volatile uint32_t *)off_102B08 & 0xFFFFFF00 | a1;
  *v2 = *v2 & 0xFFFFFF00 | a1;
  v3 = a1 - 3;
  *v1 = *v1 & 0xFFF00FFF | (v3 << 12);
  result = *v2 & 0xFFF00FFF | (v3 << 12);
  *v2 = result;
  return result;
}



