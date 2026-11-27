// rf_calibrate @ 0x101e18
int rf_calibrate( unsigned int a1, int a2, unsigned int r2_0, unsigned int a4, uint8_t a5, uint8_t a6) {
  int v10; // r0
  uint16_t v11; // r4
  uint64_t v12; // r0
  uint64_t v13; // r0
  unsigned int v14; // r0
  uint64_t v15; // r0
  volatile unsigned int *v16; // r5
  uint64_t v17; // r0
  volatile uint32_t *v18; // r2
  volatile uint32_t *v19; // r2
  int v20; // r1
  volatile uint8_t *v21; // r4
  unsigned int v22; // r3
  int v23; // r5
  uint64_t v24; // r0
  unsigned int v25; // r2
  uint64_t v26; // r4
  uint64_t v27; // r6
  uint64_t v28; // r0
  uint64_t v29; // d8
  uint64_t v30; // r2
  volatile unsigned int *v31; // r11
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
  volatile uint32_t *v52; // r2
  uint64_t v53; // r0
  volatile unsigned int *v54; // r6
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
  volatile uint32_t *v67; // r6
  volatile unsigned int *v68; // r2
  volatile unsigned int *v69; // r7
  volatile unsigned int *v70; // r11
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
  volatile unsigned int *v95; // r3
  volatile uint32_t *v96; // r6
  volatile unsigned int *v97; // r4
  volatile unsigned int v98; // r1
  unsigned int v99; // r1
  int v100; // r3
  volatile uint32_t *v101; // r2
  int v102; // r6
  int v103; // r8
  int v104; // r11
  int v105; // r5
  uint64_t v106; // r6
  uint64_t v107; // r0
  uint64_t v108; // r2
  volatile unsigned int *v109; // r11
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
  volatile uint32_t *v127; // r2
  uint64_t v128; // r0
  volatile unsigned int *v129; // r6
  uint64_t v130; // r0
  uint64_t v131; // r0
  uint64_t v132; // r2
  volatile uint8_t *v133; // r4
  volatile int *v134; // r4
  int v135; // r2
  int v136; // r0
  volatile uint32_t *v137; // r7
  volatile uint32_t *v138; // r4
  volatile int *v139; // r9
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
  volatile uint32_t *v152; // r5
  int v153; // r1
  int v154; // r0
  int result; // r0
  uint64_t v156; // r0
  volatile unsigned int *v157; // r5
  uint64_t v158; // r0
  uint64_t v159; // r2
  uint64_t v160; // r0
  uint64_t v161; // r0
  uint64_t v162; // r0
  uint64_t v163; // r2
  uint64_t v164; // r0
  uint64_t v165; // r0
  volatile uint32_t *v166; // r0
  volatile uint32_t *v167; // r1
  volatile uint32_t *v168; // r2
  int v169; // r3
  struct __attribute__((packed)) { union { unsigned int v171; // [sp+24h] [bp-50h]
  unsigned int v172; }; // [sp+24h] [bp-50h]
  volatile uint8_t *v173; // [sp+28h] [bp-4Ch]
  int v174; // [sp+2Ch] [bp-48h]
  char _pad3[4]; uint32_t v175[16]; // [sp+34h] [bp-40h] BYREF
  } _frame;
  dispatch_event_handler_1("\x9D\x87%s: band=%d freq=%d freq1=%d chantype=%d sx=%d\n", aPhyHwSetChanne, a1, a2, r2_0, a4, a6);
  if ( **(volatile uint8_t **)off_102168 != 3 )
    dispatch_event_handler_1("setch:%d\r\n", r2_0);
  store_byte_value(a4);
  mac_send_frame(a1, a2, r2_0, a4, a5);
  v10 = read_byte_register();
  v11 = v10;
  if ( v10 == 240 )
  {
    if ( a4 <= 1 )
      v156 = (v156 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102800) << 32);
    else
      v156 = (v156 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1027FC) << 32);
    v157 = (volatile unsigned int *)off_102804;
    v156 = (v156 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v158 = parse_data_field(v156);
    *v157 = *v157 & 0xC00FFFFF | dword_102808 & (((int (*)(uint64_t))aeabi_d2iz)(v158) << 20);
  }
  else
  {
    v12 = aeabi_i2d(v10);
    if ( a4 > 1 )
      v13 = ((uint64_t (*)())aeabi_dadd)(v12, *(volatile uint64_t *)&dword_1024A0);
    else
      v13 = ((uint64_t (*)())aeabi_dadd)(v12, *(volatile uint64_t *)&dword_102150);
    v14 = ((int (*)(uint64_t))aeabi_dmul)(v13);
    v15 = ((uint64_t (*)())aeabi_d2f)(v14);
    v16 = (volatile unsigned int *)off_102170;
    v17 = parse_data_field(v15);
    *v16 = *v16 & 0xF003FFFF | dword_102174 & (((int (*)(uint64_t))aeabi_d2iz)(v17) << 18);
  }
  if ( a1 )
    v18 = (void *)(uintptr_t)(off_102500);
  else
    v18 = (void *)(uintptr_t)(off_102178);
  *(volatile uint32_t *)off_10217C = (uint16_t)*(volatile uint32_t *)off_10217C
                        | (((*v18 >> 8) - (uint16_t)(((*(volatile uint32_t *)off_102170 >> 18) & 0x3FF) + v11)) << 16);
  v19 = (void *)(uintptr_t)(off_102184);
  *(volatile uint32_t *)off_102180 = *(volatile uint32_t *)off_102180 & 0xFFFE1FFF | 0xE000;
  v20 = *((volatile uint8_t *)off_102188 + 36);
  *v19 &= ~4u;
  if ( v20 != a1 )
    configure_external_clock(a1);
  if ( (int16_t)**(volatile uint16_t **) off_10218C < 0 && a1 > 1 )
  {
    flash_ctrl_init((int)aBandPhyBandMax, (int)aPhyHwSetChanne_0, 5664);
    goto LABEL_49;
  }
  if ( a1 )
  {
LABEL_49:
    _frame.v173 = (void *)(uintptr_t)(off_10250C);
    v133 = (void *)(uintptr_t)(off_10250C);
    mac_ctrl_clear(r2_0);
    if ( v133[1] )
      get_device_config_1();
    if ( a4 )
    {
      if ( a4 == 1 )
        *(volatile uint32_t *)off_102820 = *(volatile uint32_t *)off_102820 & 0xFFFFFFC7 | 0x18;
      else
        *(volatile uint32_t *)off_102510 = *(volatile uint32_t *)off_102510 & 0xFFFFFFC7 | 0x20;
    }
    else
    {
      *(volatile uint32_t *)off_102820 = *(volatile uint32_t *)off_102820 & 0xFFFFFFC7 | 0x10;
    }
    goto LABEL_18;
  }
  _frame.v173 = (void *)(uintptr_t)(off_102190);
  v21 = (void *)(uintptr_t)(off_102190);
  mac_ctrl_set(r2_0, a4);
  if ( v21[1] )
    periph_config();
  if ( a4 )
  {
    if ( a4 == 1 )
      *(volatile uint32_t *)off_102194 = *(volatile uint32_t *)off_102194 & 0xFFFFFFC7 | 8;
  }
  else
  {
    *(volatile uint32_t *)off_102820 &= 0xFFFFFFC7;
  }
LABEL_18:
  v22 = (*(volatile uint32_t *)off_102198 >> 5) & 0x1F;
  if ( (*(volatile uint32_t *)off_102198 & 0x400) != 0 )
    v22 *= 2;
  if ( (*(volatile uint32_t *)off_10219C & 0x80000) != 0 && (*(volatile uint32_t *)off_10219C & 0x40000) != 0 )
    v22 >>= 1;
  v23 = *(volatile uint8_t *)off_1021A0 * v22;
  if ( !a1 )
  {
    v24 = aeabi_i2d(r2_0);
    v25 = v24;
    v24 = (v24 & ~0xFFFFFFFFull) | ((uint32_t)(v23) & 0xFFFFFFFFu);
    v26 = __PAIR64__(HIDWORD(v24), v25);
    v27 = aeabi_i2d(v24);
    v28 = double_add(v26, v26);
    v29 = v27;
    v30 = (v30 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021A4) << 32);
    v31 = (volatile unsigned int *)off_1021E8;
    v32 = v28;
    v30 = (v30 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v33 = ((uint64_t (*)())aeabi_dadd)(v29, v30);
    v34 = ((uint64_t (*)())aeabi_dsub)(v32, v33);
    v35 = (v35 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021A8) << 32);
    v35 = (v35 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v36 = ((uint64_t (*)())aeabi_dadd)(v34, v35);
    v37 = parse_data_field(v36);
    v38 = ((int (*)(uint64_t))aeabi_d2iz)(v37);
    v39 = (v39 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021A4) << 32);
    v39 = (v39 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v40 = v38;
    v41 = ((uint64_t (*)())aeabi_dsub)(v26, v39);
    v42 = parse_data_field(v41);
    v43 = aeabi_ui2d(v40);
    v44 = (v44 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021A4) << 32);
    v44 = (v44 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v45 = ((uint64_t (*)())aeabi_dadd)(v43, v44);
    v46 = (v46 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021AC) << 32);
    v46 = (v46 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v47 = ((uint64_t (*)())aeabi_dadd)(v45, v46);
    v48 = ((uint64_t (*)())aeabi_dadd)(v47, v29);
    v49 = (v49 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021B0) << 32);
    v49 = (v49 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v50 = ((uint64_t (*)())aeabi_dadd)(v48, v49);
    pll_set_output(0);
    *(volatile uint32_t *)off_1021B4 = v40 & 0x7FFFFFFF;
    v51 = ((int (*)(uint64_t))aeabi_d2iz)(v42);
    v52 = (void *)(uintptr_t)(off_1021C0);
    *v31 = dword_1021BC & *v31 | dword_1021B8 & (v51 << 13);
    *v52 |= 1u;
LABEL_25:
    v53 = (v53 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021C4) << 32);
    v54 = (volatile unsigned int *)off_1021C8;
    v53 = (v53 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v55 = ((uint64_t (*)())aeabi_dsub)(v53, v50);
    v56 = parse_data_field(v55);
    *v54 = ((int (*)(uint64_t))double_to_float_1)(v56) & 0xFFFFFFF | *v54 & 0xF0000000;
    v57 = 0;
    v58 = ((uint64_t (*)())aeabi_dsub)(v50, *(volatile uint64_t *)&dword_102158);
    goto LABEL_26;
  }
  v106 = aeabi_i2d(r2_0);
  v107 = aeabi_i2d(v23);
  v108 = (v108 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024D4) << 32);
  v109 = (volatile unsigned int *)off_102514;
  v108 = (v108 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v110 = v107;
  v111 = ((uint64_t (*)())aeabi_dadd)(v107, v108);
  v112 = ((uint64_t (*)())aeabi_dsub)(v106, v111);
  v113 = (v113 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024D8) << 32);
  v113 = (v113 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v114 = ((uint64_t (*)())aeabi_dadd)(v112, v113);
  v115 = parse_data_field(v114);
  v116 = ((int (*)(uint64_t))aeabi_d2iz)(v115);
  v117 = (v117 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024DC) << 32);
  v117 = (v117 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v118 = v116;
  v119 = ((uint64_t (*)())aeabi_dsub)(v106, v117);
  v120 = parse_data_field(v119);
  v121 = aeabi_ui2d(v118);
  v122 = (v122 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024D4) << 32);
  v122 = (v122 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v123 = ((uint64_t (*)())aeabi_dadd)(v121, v122);
  v124 = ((uint64_t (*)())aeabi_dadd)(v123, v110);
  v125 = (v125 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024E0) << 32);
  v125 = (v125 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v50 = ((uint64_t (*)())aeabi_dadd)(v124, v125);
  pll_set_output(0);
  *(volatile uint32_t *)off_1024E4 = v118 & 0x7FFFFFFF;
  v126 = ((int (*)(uint64_t))aeabi_d2iz)(v120);
  v127 = (void *)(uintptr_t)(off_1024F0);
  *v109 = dword_1024EC & *v109 | dword_1024E8 & (v126 << 13);
  *v127 |= 1u;
  if ( a1 != 1 )
    goto LABEL_25;
  v128 = (v128 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024F4) << 32);
  v129 = (volatile unsigned int *)off_1024F8;
  v128 = (v128 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v130 = ((uint64_t (*)())aeabi_dsub)(v128, v50);
  v131 = parse_data_field(v130);
  *v129 = *v129 & 0xF0000000 | ((int (*)(uint64_t))double_to_float_1)(v131) & 0xFFFFFFF;
  v132 = (v132 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v132 = (v132 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024FC) << 32);
  v57 = 1;
  v58 = ((uint64_t (*)())aeabi_dsub)(v50, v132);
LABEL_26:
  v59 = (v59 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021CC) << 32);
  v59 = (v59 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
if ( ((int (*)())double_ge)(v58, v59) ) { v162 = ((uint64_t (*)())aeabi_dadd)(v58, 0x4180000000000000uLL);
    v163 = (v163 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_102810) << 32);
    v163 = (v163 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v164 = ((uint64_t (*)())aeabi_dsub)(v162, v163);
    v165 = parse_data_field(v164);
    v66 = ((int (*)(uint64_t))double_to_float_1)(v165);
    v61 = 0x20000000;
  }
  else
  {
    v60 = (v60 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021D0) << 32);
    v60 = (v60 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v61 = ((int (*)())double_ge)(v58, v60);
    v62 = ((uint64_t (*)())aeabi_dadd)(v58, 0x4180000000000000uLL);
    if ( v61 )
    {
      v63 = (v63 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021D0) << 32);
      v63 = (v63 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v64 = ((uint64_t (*)())aeabi_dsub)(v62, v63);
      v65 = parse_data_field(v64);
      v66 = ((int (*)(uint64_t))double_to_float_1)(v65);
      v61 = 0x10000000;
    }
    else
    {
      v159 = (v159 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10280C) << 32);
      v159 = (v159 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v160 = ((uint64_t (*)())aeabi_dsub)(v62, v159);
      v161 = parse_data_field(v160);
      v66 = ((int (*)(uint64_t))double_to_float_1)(v161);
    }
  }
  v67 = (void *)(uintptr_t)(off_1021D8);
  v68 = (volatile unsigned int *)off_1021DC;
  v69 = (volatile unsigned int *)off_1021E0;
  *(volatile uint32_t *)off_1021D4 = v66 & 0xFFFFFFF;
  *v67 = *v67 & 0xFFFFFFF | v61;
  v70 = (volatile unsigned int *)off_1021EC;
  *v68 = *v68 & 0xFFFFFFFC | v57;
  v71 = aeabi_i2d(a2);
  v72 = double_add(v71, v50);
  v73 = aeabi_i2d(r2_0);
  v74 = ((uint64_t (*)())double_subtract)(v72, v73);
  v75 = (v75 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021E4) << 32);
  v75 = (v75 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v76 = ((uint64_t (*)())aeabi_dsub)(v75, v50);
  v77 = (v77 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v77 = (v77 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1021AC) << 32);
  v78 = double_add(v76, v77);
  _frame.v171 = *v69;
  *v69 = _frame.v171 & 0xFFFF8000 | ((int (*)(uint64_t))aeabi_d2iz)(v78) & 0x7FFF;
  v79 = (v79 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024A8) << 32);
  v79 = (v79 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v80 = ((uint64_t (*)())aeabi_dadd)(v50, v79);
  v81 = ((uint64_t (*)())aeabi_dsub)(v80, v74);
  v82 = (v82 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024AC) << 32);
  v83 = *v70;
  v82 = (v82 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v84 = double_add(v81, v82);
  *v70 = (HIWORD(v83) << 16) | (uint16_t)((int (*)(uint64_t))aeabi_d2iz)(v84);
  v85 = (v85 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024B0) << 32);
  v85 = (v85 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v86 = ((uint64_t (*)())aeabi_dsub)(v85, v74);
  v87 = (v87 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1024AC) << 32);
  v87 = (v87 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v88 = double_add(v86, v87);
  *v70 = *v70 & 0x8000FFFF | dword_1024B4 & (((int (*)(uint64_t))aeabi_d2iz)(v88) << 16);
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
  v95 = (volatile unsigned int *)off_1024B8;
  v96 = (void *)(uintptr_t)(off_1024BC);
  *(volatile uint32_t *)off_1024B8 = *(volatile uint32_t *)off_1024B8 & 0xFFFFFFCF | v89;
  v97 = (volatile unsigned int *)off_1024C0;
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
  v101 = (void *)(uintptr_t)(off_1024CC);
  *(volatile uint32_t *)off_1024C8 = 4;
  *v101 |= 4u;
  if ( a1 )
    v102 = *(volatile uint8_t *)off_1027F8;
  else
    v102 = *(volatile uint8_t *)off_1024D0;
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
  if ( !*(volatile uint8_t *)off_1027D0 )
    goto LABEL_68;
  v134 = (void *)(uintptr_t)(off_1027D4);
  v135 = *(volatile uint8_t *)off_1027D8;
  _frame.v174 = *(volatile uint32_t *)(uintptr_t)(off_1027D4);
  v136 = *(volatile uint32_t *)(uintptr_t)(off_1027D4);
  *(volatile uint8_t *)off_1027D0 = 0;
  if ( !v135 && v136 )
  {
    v166 = (void *)(uintptr_t)(off_102814);
    *v134 = 0;
    v167 = (void *)(uintptr_t)(off_102818);
    v168 = (void *)(uintptr_t)(off_10281C);
    *v166 += 200000;
    *v167 += 200000;
    *v168 += 200000;
    v167[2] += 200000;
    v168[3] += 200000;
  }
  v137 = (void *)(uintptr_t)(off_1027DC);
  v138 = (void *)(uintptr_t)(off_1027E0);
  dispatch_event_handler_1("process rx1: %x %x\n", *(volatile uint32_t *)off_1027DC, *(volatile uint32_t *)off_1027E0);
  while ( *v138 != *v137 )
    wait_for_hw_event();
  v139 = (volatile int *)off_102824;
  if ( *(volatile uint32_t *)off_102824 )
  {
    init_with_stack(0);
    if ( !v102 )
      goto LABEL_63;
LABEL_82:
    clock_set_source(a1, a4, 0);
    goto LABEL_63;
  }
  if ( v102 )
    goto LABEL_82;
LABEL_63:
  v140 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[1];
  v141 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[2];
  _frame.v175[0] = ((volatile uint32_t *)(uintptr_t)off_1027E8)[0];
  _frame.v175[1] = v140;
  _frame.v175[2] = v141;
  v142 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[5];
  v143 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[6];
  v144 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[7];
  _frame.v175[3] = ((volatile uint32_t *)(uintptr_t)off_1027E8)[4];
  _frame.v175[4] = v142;
  _frame.v175[5] = v143;
  _frame.v175[6] = v144;
  v145 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[9];
  v146 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[10];
  v147 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[11];
  _frame.v175[7] = ((volatile uint32_t *)(uintptr_t)off_1027E8)[8];
  _frame.v175[8] = v145;
  _frame.v175[9] = v146;
  _frame.v175[10] = v147;
  v148 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[12];
  v149 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[13];
  v150 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[14];
  v151 = ((volatile uint32_t *)(uintptr_t)off_1027E8)[15];
  _frame.v172 = off_1027EC + 8 * v105;
  *(volatile uint8_t *)(_frame.v172 + 4) = 1;
  v152 = (void *)(uintptr_t)(off_1027F0);
  _frame.v175[11] = v148;
  _frame.v175[12] = v149;
  _frame.v175[13] = v150;
  _frame.v175[14] = v151;
  v153 = off_1027F4;
  *(volatile uint32_t *)off_1027F0 |= 0x8000u;
  *v152 |= 0x2000u;
  apply_dsp_transform((int)_frame.v175, v153, 0, 0, (volatile uint16_t *)off_1027EC, 6, 1);
  *v152 &= ~0x8000u;
  *v152 &= ~0x2000u;
  *(volatile uint8_t *)(_frame.v172 + 4) = 0;
  if ( r2_0 <= 0x1387 )
  {
    rf_ctrl_set(0, r2_0);
    if ( _frame.v173[13] )
      _frame.v173[15] |= 1u;
  }
  else
  {
    rf_ctrl_set(1, r2_0);
  }
  if ( !*(volatile uint8_t *)off_1027D8 && _frame.v174 )
  {
    v154 = *v139;
    *(volatile uint32_t *)(uintptr_t)(off_1027D4) = _frame.v174;
    if ( !v154 )
      goto LABEL_68;
  }
  else
  {
    v154 = *v139;
    if ( !*v139 )
      goto LABEL_68;
  }
  init_with_stack(v154);
LABEL_68:
  result = rf_reg_init(off_1027F4 + v104, off_1027F4 + v103);
  if ( v102 )
    return clock_set_source(a1, a4, v102);
  return result;
}


// pmu_write_ctrl @ 0x102828
int pmu_write_ctrl() {
  volatile int *v0; // r3
  volatile int *v1; // r2
  volatile int *v2; // r1
  volatile uint32_t *v3; // r4
  volatile uint32_t *v4; // r1
  int result; // r0

  tx_path_check();
  v0 = (volatile int *)off_102898;
  *(volatile uint32_t *)off_102898 = dword_10289C;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_1028A0;
  v1 = (volatile int *)off_102898;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_1028A4;
  v2 = (volatile int *)off_102898;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  rf_calibrate((unsigned int)*v2 >> 31, 2412, 0x96Cu, (unsigned int)*v2 >> 31, *v2 < 0, *v2 < 0);
  v3 = (void *)(uintptr_t)(off_1028AC);
  v4 = (void *)(uintptr_t)(off_1028B0);
  result = dword_1028B4;
  *(volatile uint32_t *)off_1028A8 &= ~0x200u;
  *v3 = 12;
  *v4 = result;
  return result;
}


// wifi_set_channel @ 0x1028b8
int wifi_set_channel(volatile int *a1) {
  volatile int *v2; // r6
  int v3; // r7
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int result; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3

  rf_band_config();
  rf_ctrl_set(0, 2412);
  pmu_write_ctrl();
  v2 = (volatile int *)off_102900;
  v3 = dword_102904;
  *(volatile uint32_t *)off_1028FC &= 0xFFFFFC00;
  v4 = *a1;
  v5 = a1[1];
  v6 = a1[2];
  v7 = a1[3];
  a1 += 4;
  *v2 = v4;
  v2[1] = v5;
  v2[2] = v6;
  v2[3] = v7;
  result = *a1;
  v9 = a1[1];
  v10 = a1[2];
  v11 = a1[3];
  v2[4] = *a1;
  v2[5] = v9;
  v2[6] = v10;
  v2[7] = v11;
  v2[8] = a1[4];
  v2[9] = v3;
  v2[10] = 16711935;
  return result;
}


// tx_set_power @ 0x102908
/* luna: Apply the supplied channel/radio configuration to PHY radio 0, calibrate the RF path, and copy the configuration into the active radio state. */
int tx_set_power(volatile uint8_t *a1, int a2) {
  int result; // r0
  int v4; // r1
  int radio_state_ptr; // r3

  if ( a2 )
    return dispatch_event_handler_1("\x9B\x87%s: radio %d does not exist\n", aPhySetChannel, a2);
  rf_calibrate(*a1, *((volatile uint16_t *)a1 + 1), *((volatile uint16_t *)a1 + 2), a1[1], a1[9], 0);
  result = *(volatile uint32_t *)a1;
  v4 = *((volatile uint32_t *)a1 + 1);
  radio_state_ptr = dword_10293C;
  *(volatile uint32_t *)dword_10293C = *(volatile uint32_t *)a1;
  *(volatile uint32_t *)(radio_state_ptr + 4) = v4;
  *(volatile uint16_t *)(radio_state_ptr + 8) = *((volatile uint16_t *)a1 + 4);
  return result;
}


// event_counter @ 0x102948
int event_counter() {
  int result; // r0

  result = rf_ctrl_set(*((volatile uint8_t *)off_102960 + 36), *((volatile uint16_t *)off_102960 + 20));
  ++*(volatile uint8_t *)off_102964;
  return result;
}


// rf_check_freq @ 0x102968
int rf_check_freq(unsigned int a1) {
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



// rf_get_rssi @ 0x1029a8
volatile uint8_t * rf_get_rssi(volatile uint8_t *result, volatile uint8_t *a2) {
  volatile uint8_t *v2; // r3

  v2 = (void *)(uintptr_t)(off_1029B8);
  *result = *((volatile uint8_t *)off_1029B8 + 294);
  *a2 = v2[295];
  return result;
}



// clock_get_divider @ 0x1029bc
int clock_get_divider() {
  return (uint8_t)((1 << ((uint8_t)*(volatile uint32_t *)off_1029D8 >> 4)) - 1);
}



// gpio_config @ 0x1029dc
unsigned int gpio_config(uint8_t a1) {
  volatile unsigned int *v1; // r1
  volatile unsigned int *v2; // r2
  uint8_t v3; // r0
  unsigned int result; // r0

  v1 = (volatile unsigned int *)off_102A14;
  v2 = (volatile unsigned int *)off_102A18;
  *(volatile uint32_t *)off_102A14 = *(volatile uint32_t *)off_102A14 & 0xFFFFFF00 | a1;
  *v2 = *v2 & 0xFFFFFF00 | a1;
  v3 = a1 - 3;
  *v1 = *v1 & 0xFFF00FFF | (v3 << 12);
  result = *v2 & 0xFFF00FFF | (v3 << 12);
  *v2 = result;
  return result;
}



