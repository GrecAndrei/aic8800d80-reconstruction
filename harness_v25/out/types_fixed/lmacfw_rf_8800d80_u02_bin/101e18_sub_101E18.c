// sub_101E18 @ 0x101e18, size 2476 bytes
void __fastcall sub_101E18(int a1, int a2, int a3, int a4)
{
  int v8; // r0
  __int16 v9; // r4
  __int64 v10; // r0
  unsigned int v11; // r0
  int v12; // r1
  unsigned int v13; // r0
  int v14; // r1
  int v15; // r2
  unsigned int v16; // r3
  __int64 v17; // r0
  unsigned int *v18; // r5
  __int64 v19; // r0
  _DWORD *v20; // r2
  _DWORD *v21; // r2
  int v22; // r1
  _BYTE *v23; // r4
  unsigned int v24; // r3
  int v25; // r5
  int v26; // r2
  int v27; // r0
  unsigned int v28; // r1
  unsigned __int64 v29; // r4
  __int64 v30; // r6
  int v31; // r1
  __int64 v32; // r0
  __int64 v33; // d8
  unsigned int *v34; // r11
  __int64 v35; // r6
  unsigned int v36; // r0
  unsigned int v37; // r1
  __int64 v38; // r0
  __int64 v39; // r0
  __int64 v40; // r0
  unsigned int v41; // r9
  __int64 v42; // r0
  __int64 v43; // r6
  __int64 v44; // r0
  __int64 v45; // r0
  __int64 v46; // r0
  __int64 v47; // r0
  int v48; // r1
  __int64 v49; // r4
  unsigned int v50; // r0
  _DWORD *v51; // r2
  unsigned int *v52; // r6
  __int64 v53; // r0
  __int64 v54; // r0
  int v55; // r9
  int v56; // r1
  __int64 v57; // r6
  int v58; // r11
  unsigned int v59; // r0
  unsigned int v60; // r1
  __int64 v61; // r0
  __int64 v62; // r0
  unsigned int v63; // r0
  _DWORD *v64; // r6
  unsigned int *v65; // r2
  unsigned int *v66; // r7
  unsigned int *v67; // r11
  __int64 v68; // r0
  int v69; // r8
  int v70; // r1
  int v71; // r9
  int v72; // r0
  int v73; // r1
  __int64 v74; // r8
  __int64 v75; // r0
  __int64 v76; // r2
  unsigned int v77; // r0
  int v78; // r1
  unsigned int v79; // r0
  unsigned int v80; // r1
  __int64 v81; // r0
  __int64 v82; // r2
  unsigned int v83; // r4
  unsigned int v84; // r0
  int v85; // r1
  __int64 v86; // r0
  __int64 v87; // r2
  unsigned int v88; // r0
  int v89; // r1
  int v90; // r4
  int v91; // r1
  int v92; // r0
  int v93; // r12
  int v94; // r7
  int v95; // r5
  unsigned int *v96; // r3
  _DWORD *v97; // r6
  unsigned int *v98; // r4
  unsigned int v99; // r6
  unsigned int v100; // r1
  unsigned int v101; // r7
  __int64 v102; // r0
  unsigned int *v103; // r11
  __int64 v104; // r4
  unsigned int v105; // r0
  unsigned int v106; // r1
  __int64 v107; // r0
  __int64 v108; // r0
  __int64 v109; // r0
  unsigned int v110; // r9
  __int64 v111; // r0
  __int64 v112; // r6
  __int64 v113; // r0
  __int64 v114; // r0
  __int64 v115; // r0
  int v116; // r1
  unsigned int v117; // r0
  _DWORD *v118; // r2
  unsigned int *v119; // r6
  __int64 v120; // r0
  __int64 v121; // r0
  int v122; // r1
  _BYTE *v123; // r4
  __int64 v124; // r0
  unsigned int *v125; // r5
  __int64 v126; // r0
  __int64 v127; // r0
  __int64 v128; // r0
  unsigned int v129; // r0
  unsigned int v130; // r1
  __int64 v131; // r0
  __int64 v132; // r0
  unsigned int v134; // [sp+24h] [bp-50h]
  char v135; // [sp+A8h] [bp+34h]
  unsigned __int8 v136; // [sp+ACh] [bp+38h]

  msg_parse(dword_102164, dword_102160, a1, a2, a3, a4, v136);
  if ( **(_BYTE **)off_102168 != 3 )
    msg_parse(dword_10216C, a3);
  sub_10058C(a4);
  rf_init_or_setup_n_1200a80(a1, a2, a3, a4, v135);
  v8 = sub_1005E8();
  v9 = v8;
  if ( v8 == 240 )
  {
    if ( (unsigned int)a4 <= 1 )
      HIDWORD(v124) = dword_102800;
    else
      HIDWORD(v124) = dword_1027FC;
    v125 = (unsigned int *)off_102804;
    LODWORD(v124) = 0;
    v126 = math_round(v124);
    *v125 = *v125 & 0xC00FFFFF | dword_102808 & (sub_127BA4(v126, SHIDWORD(v126)) << 20);
  }
  else
  {
    LODWORD(v10) = sub_12754C(v8);
    if ( (unsigned int)a4 > 1 )
      v11 = sub_127620(v10, dword_1024A0, dword_1024A4);
    else
      v11 = sub_127620(v10, dword_102150, dword_102154);
    v13 = sub_127BE4(v11, v12);
    LODWORD(v17) = sub_127570(v13, v14, v15, v16);
    v18 = (unsigned int *)off_102170;
    v19 = math_round(v17);
    *v18 = *v18 & 0xF003FFFF | dword_102174 & (sub_127BA4(v19, SHIDWORD(v19)) << 18);
  }
  if ( a1 )
    v20 = off_102500;
  else
    v20 = off_102178;
  *(_DWORD *)off_10217C = (unsigned __int16)*(_DWORD *)off_10217C
                        | (((*v20 >> 8) - (unsigned __int16)(((*(_DWORD *)off_102170 >> 18) & 0x3FF) + v9)) << 16);
  v21 = off_102184;
  *(_DWORD *)off_102180 = *(_DWORD *)off_102180 & 0xFFFE1FFF | 0xE000;
  v22 = *((unsigned __int8 *)off_102188 + 36);
  *v21 &= ~4u;
  if ( v22 != a1 )
    rf_power_enable_32dc(a1);
  if ( **(__int16 **)off_10218C >= 0 || (unsigned int)a1 <= 1 )
  {
    if ( !a1 )
    {
      v23 = off_102190;
      mmio_clock_setup(a3, a4);
      if ( *(_DWORD *)(v23 + 0x4) )
        rf_init_clocks_n2c0();
      if ( a4 )
      {
        if ( a4 == 1 )
          *(_DWORD *)off_102194 = *(_DWORD *)off_102194 & 0xFFFFFFC7 | 8;
      }
      else
      {
        *(_DWORD *)off_102820 &= 0xFFFFFFC7;
      }
LABEL_18:
      v24 = (*(_DWORD *)off_102198 >> 5) & 0x1F;
      if ( (*(_DWORD *)off_102198 & 0x400) != 0 )
        v24 *= 2;
      if ( (*(_DWORD *)off_10219C & 0x80000) != 0 && (*(_DWORD *)off_10219C & 0x40000) != 0 )
        v24 >>= 1;
      v25 = *(unsigned __int8 *)off_1021A0 * v24;
      if ( a1 )
      {
        v99 = sub_12754C(a3);
        v101 = v100;
        LODWORD(v102) = sub_12754C(v25);
        v103 = (unsigned int *)off_102514;
        v104 = v102;
        v105 = sub_127620(v102, 0, dword_1024D4);
        LODWORD(v107) = sub_127874(v99, v101, v105, v106);
        LODWORD(v108) = sub_127620(v107, 0, dword_1024D8);
        v109 = math_round(v108);
        v110 = sub_127BA4(v109, SHIDWORD(v109));
        LODWORD(v111) = sub_127874(v99, v101, 0, dword_1024DC);
        v112 = math_round(v111);
        LODWORD(v113) = sub_12752C(v110);
        LODWORD(v114) = sub_127620(v113, 0, dword_1024D4);
        LODWORD(v115) = sub_127620(v114, v104, HIDWORD(v104));
        LODWORD(v49) = sub_127620(v115, 0, dword_1024E0);
        HIDWORD(v49) = v116;
        rf_mmio_set_byte_field(0);
        *(_DWORD *)off_1024E4 = v110 & 0x7FFFFFFF;
        v117 = sub_127BA4(v112, SHIDWORD(v112));
        v118 = off_1024F0;
        *v103 = dword_1024EC & *v103 | dword_1024E8 & (v117 << 13);
        *v118 |= 1u;
        if ( a1 == 1 )
        {
          v119 = (unsigned int *)off_1024F8;
          LODWORD(v120) = sub_127874(0, dword_1024F4, v49, HIDWORD(v49));
          v121 = math_round(v120);
          *v119 = *v119 & 0xF0000000 | sub_127B54(v121, SHIDWORD(v121)) & 0xFFFFFFF;
          v55 = 1;
          LODWORD(v57) = sub_127874(v49, HIDWORD(v49), 0, dword_1024FC);
          HIDWORD(v57) = v122;
LABEL_26:
          if ( sub_127B2C(v57, SHIDWORD(v57), 0, dword_1021CC) )
          {
            v129 = sub_127620(v57, 0, 0x41800000u);
            LODWORD(v131) = sub_127874(v129, v130, 0, dword_102810);
            v132 = math_round(v131);
            v63 = sub_127B54(v132, SHIDWORD(v132));
            v58 = 0x20000000;
          }
          else
          {
            v58 = sub_127B2C(v57, SHIDWORD(v57), 0, dword_1021D0);
            v59 = sub_127620(v57, 0, 0x41800000u);
            if ( v58 )
            {
              LODWORD(v61) = sub_127874(v59, v60, 0, dword_1021D0);
              v62 = math_round(v61);
              v63 = sub_127B54(v62, SHIDWORD(v62));
              v58 = 0x10000000;
            }
            else
            {
              LODWORD(v127) = sub_127874(v59, v60, 0, dword_10280C);
              v128 = math_round(v127);
              v63 = sub_127B54(v128, SHIDWORD(v128));
            }
          }
          v64 = off_1021D8;
          v65 = (unsigned int *)off_1021DC;
          v66 = (unsigned int *)off_1021E0;
          *(_DWORD *)off_1021D4 = v63 & 0xFFFFFFF;
          *v64 = *v64 & 0xFFFFFFF | v58;
          v67 = (unsigned int *)off_1021EC;
          *v65 = *v65 & 0xFFFFFFFC | v55;
          LODWORD(v68) = sub_12754C(a2);
          v69 = sub_1272B4(v68, v49);
          v71 = v70;
          v72 = sub_12754C(a3);
          v74 = sub_1272B0(v69, v71, v72, v73);
          LODWORD(v75) = sub_127874(0, dword_1021E4, v49, HIDWORD(v49));
          LODWORD(v76) = 0;
          HIDWORD(v76) = dword_1021AC;
          v77 = sub_1272B4(v75, v76);
          v134 = *v66;
          *v66 = v134 & 0xFFFF8000 | sub_127BA4(v77, v78) & 0x7FFF;
          v79 = sub_127620(v49, 0, dword_1024A8);
          LODWORD(v81) = sub_127874(v79, v80, v74, HIDWORD(v74));
          HIDWORD(v82) = dword_1024AC;
          v83 = *v67;
          LODWORD(v82) = 0;
          v84 = sub_1272B4(v81, v82);
          *v67 = (HIWORD(v83) << 16) | (unsigned __int16)sub_127BA4(v84, v85);
          LODWORD(v86) = sub_127874(0, dword_1024B0, v74, HIDWORD(v74));
          HIDWORD(v87) = dword_1024AC;
          LODWORD(v87) = 0;
          v88 = sub_1272B4(v86, v87);
          *v67 = *v67 & 0x8000FFFF | dword_1024B4 & (sub_127BA4(v88, v89) << 16);
          *v64 = a4 & 0xF | *v64 & 0xFFFFFFF0;
          if ( a4 )
          {
            if ( a4 == 1 )
            {
              v91 = 0;
              v95 = 0;
              v90 = 16;
              v92 = 0x100000;
              v93 = 402653184;
              v94 = 11;
            }
            else
            {
              v90 = 32;
              v91 = 0x80000;
              v92 = 3145728;
              v93 = 402653184;
              v94 = 13;
              v95 = 256;
            }
          }
          else
          {
            v90 = 0;
            v91 = 0;
            v92 = 0x100000;
            v93 = 419430400;
            v94 = 10;
            v95 = 0;
          }
          v96 = (unsigned int *)off_1024B8;
          v97 = off_1024BC;
          *(_DWORD *)off_1024B8 = *(_DWORD *)off_1024B8 & 0xFFFFFFCF | v90;
          v98 = (unsigned int *)off_1024C0;
          *v96 = *v96 & 0xFFF3FFFF | v91;
          *v96 = *v96 & 0xFFCFFFFF | v92;
          *v97 = *v97 & 0xFFFFFF | v93;
          *v97 = *v97 & 0xFFFFFF00 | v94;
          *v98 = *v98 & 0xFFFFFEFF | v95;
          while ( 1 )
            ;
        }
      }
      else
      {
        v26 = sub_12754C(a3);
        v27 = v25;
        v29 = __PAIR64__(v28, v26);
        LODWORD(v30) = sub_12754C(v27);
        HIDWORD(v30) = v31;
        LODWORD(v32) = sub_1272B4(v29, v29);
        v33 = v30;
        v34 = (unsigned int *)off_1021E8;
        v35 = v32;
        v36 = sub_127620(v33, 0, dword_1021A4);
        LODWORD(v38) = sub_127874(v35, HIDWORD(v35), v36, v37);
        LODWORD(v39) = sub_127620(v38, 0, dword_1021A8);
        v40 = math_round(v39);
        v41 = sub_127BA4(v40, SHIDWORD(v40));
        LODWORD(v42) = sub_127874(v29, HIDWORD(v29), 0, dword_1021A4);
        v43 = math_round(v42);
        LODWORD(v44) = sub_12752C(v41);
        LODWORD(v45) = sub_127620(v44, 0, dword_1021A4);
        LODWORD(v46) = sub_127620(v45, 0, dword_1021AC);
        LODWORD(v47) = sub_127620(v46, v33, HIDWORD(v33));
        LODWORD(v49) = sub_127620(v47, 0, dword_1021B0);
        HIDWORD(v49) = v48;
        rf_mmio_set_byte_field(0);
        *(_DWORD *)off_1021B4 = v41 & 0x7FFFFFFF;
        v50 = sub_127BA4(v43, SHIDWORD(v43));
        v51 = off_1021C0;
        *v34 = dword_1021BC & *v34 | dword_1021B8 & (v50 << 13);
        *v51 |= 1u;
      }
      v52 = (unsigned int *)off_1021C8;
      LODWORD(v53) = sub_127874(0, dword_1021C4, v49, HIDWORD(v49));
      v54 = math_round(v53);
      *v52 = sub_127B54(v54, SHIDWORD(v54)) & 0xFFFFFFF | *v52 & 0xF0000000;
      v55 = 0;
      LODWORD(v57) = sub_127874(v49, HIDWORD(v49), dword_102158, dword_10215C);
      HIDWORD(v57) = v56;
      goto LABEL_26;
    }
  }
  else
  {
    rf_cmd_send_n264(dword_102508, dword_102504, 5664);
  }
  v123 = off_10250C;
  rf_init_hw_setup(a3);
  if ( *(_DWORD *)(v123 + 0x4) )
    sub_100688();
  if ( a4 )
  {
    if ( a4 == 1 )
      *(_DWORD *)off_102820 = *(_DWORD *)off_102820 & 0xFFFFFFC7 | 0x18;
    else
      *(_DWORD *)off_102510 = *(_DWORD *)off_102510 & 0xFFFFFFC7 | 0x20;
  }
  else
  {
    *(_DWORD *)off_102820 = *(_DWORD *)off_102820 & 0xFFFFFFC7 | 0x10;
  }
  goto LABEL_18;
}

