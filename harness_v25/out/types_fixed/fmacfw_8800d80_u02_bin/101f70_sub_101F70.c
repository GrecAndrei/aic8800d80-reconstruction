// sub_101F70 @ 0x101f70, size 2412 bytes
void __fastcall sub_101F70(int a1, int a2, int a3, int a4)
{
  int variant_cached; // r0
  __int16 v10; // r6
  __int64 v11; // r0
  unsigned int v12; // r0
  int v13; // r1
  unsigned int v14; // r0
  int v15; // r1
  int v16; // r2
  unsigned int v17; // r3
  __int64 v18; // r0
  unsigned int *v19; // r7
  __int64 v20; // r0
  _DWORD *v21; // r2
  _DWORD *v22; // r2
  int v23; // r1
  _BYTE *v24; // r6
  unsigned int v25; // r3
  int v26; // r6
  __int64 v27; // r8
  int v28; // r1
  __int64 v29; // r10
  int v30; // r1
  unsigned int v31; // r6
  unsigned int v32; // r1
  unsigned int v33; // r7
  unsigned int v34; // r0
  unsigned int v35; // r1
  __int64 v36; // r0
  __int64 v37; // r0
  __int64 v38; // r0
  unsigned int v39; // r6
  __int64 v40; // r0
  __int64 v41; // r8
  __int64 v42; // r0
  __int64 v43; // r0
  __int64 v44; // r0
  __int64 v45; // r0
  int v46; // r1
  __int64 v47; // r10
  unsigned int *v48; // r5
  unsigned int v49; // r0
  _DWORD *v50; // r2
  unsigned int *v51; // r5
  __int64 v52; // r0
  __int64 v53; // r0
  int v54; // r9
  int v55; // r1
  __int64 v56; // r6
  BOOL v57; // r5
  unsigned int v58; // r0
  unsigned int v59; // r1
  __int64 v60; // r0
  __int64 v61; // r0
  unsigned int v62; // r0
  int v63; // r1
  _DWORD *v64; // r5
  unsigned int *v65; // r2
  unsigned int *v66; // r8
  __int64 v67; // r0
  int v68; // r6
  int v69; // r1
  int v70; // r7
  int v71; // r0
  int v72; // r1
  __int64 v73; // r6
  unsigned int *v74; // r9
  __int64 v75; // r0
  __int64 v76; // r2
  unsigned int v77; // r0
  int v78; // r1
  unsigned int v79; // r0
  unsigned int v80; // r1
  __int64 v81; // r0
  __int64 v82; // r2
  unsigned int v83; // r8
  unsigned int v84; // r0
  int v85; // r1
  __int64 v86; // r0
  __int64 v87; // r2
  unsigned int v88; // r0
  int v89; // r1
  int v90; // r2
  int v91; // r8
  int v92; // r0
  int v93; // lr
  int v94; // r12
  int v95; // r6
  unsigned int *v96; // r1
  _DWORD *v97; // r7
  unsigned int *v98; // r5
  _BYTE *v99; // r6
  unsigned int v100; // r8
  unsigned int v101; // r1
  unsigned int v102; // r9
  __int64 v103; // r0
  unsigned int *v104; // r7
  __int64 v105; // r10
  unsigned int v106; // r0
  unsigned int v107; // r1
  __int64 v108; // r0
  __int64 v109; // r0
  __int64 v110; // r0
  unsigned int v111; // r6
  __int64 v112; // r0
  __int64 v113; // r8
  __int64 v114; // r0
  __int64 v115; // r0
  __int64 v116; // r0
  int v117; // r1
  unsigned int v118; // r0
  _DWORD *v119; // r2
  unsigned int *v120; // r6
  __int64 v121; // r0
  __int64 v122; // r0
  int v123; // r1
  __int64 v124; // r0
  unsigned int *v125; // r7
  __int64 v126; // r0
  __int64 v127; // r0
  __int64 v128; // r0
  unsigned int v129; // r0
  unsigned int v130; // r1
  __int64 v131; // r0
  __int64 v132; // r0
  unsigned int v133; // [sp+20h] [bp-4Ch]
  char v134; // [sp+98h] [bp+2Ch]
  unsigned __int8 v135; // [sp+9Ch] [bp+30h]

  msg_parse(dword_1022BC, dword_1022B8, a1, a2, a3, a4, v135);
  if ( **(_BYTE **)off_1022C0 != 3 )
    feature_guard_check(4, dword_1022C4, a3);
  variant_update_cache(a4);
  rf_cmd_queue_next_n_d4(a1, a2, a3, a4, v134);
  variant_cached = get_variant_cached();
  v10 = variant_cached;
  if ( variant_cached == 240 )
  {
    if ( (unsigned int)a4 <= 1 )
      HIDWORD(v124) = dword_102944;
    else
      HIDWORD(v124) = dword_102940;
    v125 = (unsigned int *)off_102948;
    LODWORD(v124) = 0;
    v126 = math_round(v124);
    *v125 = *v125 & 0xC00FFFFF | dword_10294C & (sub_14302C(v126, SHIDWORD(v126)) << 20);
  }
  else
  {
    LODWORD(v11) = sub_1429D4(variant_cached);
    if ( (unsigned int)a4 > 1 )
      v12 = sub_142AA8(v11, dword_102598, dword_10259C);
    else
      v12 = sub_142AA8(v11, dword_1022A8, dword_1022AC);
    v14 = sub_14306C(v12, v13);
    LODWORD(v18) = sub_1429F8(v14, v15, v16, v17);
    v19 = (unsigned int *)off_1022C8;
    v20 = math_round(v18);
    *v19 = *v19 & 0xF003FFFF | dword_1022CC & (sub_14302C(v20, SHIDWORD(v20)) << 18);
  }
  if ( a1 )
    v21 = off_10293C;
  else
    v21 = off_1022D0;
  *(_DWORD *)off_1022D4 = (unsigned __int16)*(_DWORD *)off_1022D4
                        | (((*v21 >> 8) - (unsigned __int16)(((*(_DWORD *)off_1022C8 >> 18) & 0x3FF) + v10)) << 16);
  v22 = off_1022DC;
  *(_DWORD *)off_1022D8 = *(_DWORD *)off_1022D8 & 0xFFFE1FFF | 0xE000;
  v23 = *((unsigned __int8 *)off_1022E0 + 36);
  *v22 &= ~4u;
  if ( v23 != a1 )
    sub_103200(a1);
  if ( **(__int16 **)off_1022E4 >= 0 || (unsigned int)a1 <= 1 )
  {
    if ( !a1 )
    {
      v24 = off_1022E8;
      rf_clock_gate_init(a3, a4);
      if ( *(_DWORD *)(v24 + 0x4) )
        mmio_init_patch_n_730();
      if ( a4 )
      {
        if ( a4 == 1 )
          *(_DWORD *)off_1022EC = *(_DWORD *)off_1022EC & 0xFFFFFFC7 | 8;
      }
      else
      {
        *(_DWORD *)off_102958 &= 0xFFFFFFC7;
      }
LABEL_18:
      v25 = (*(_DWORD *)off_1022F0 >> 5) & 0x1F;
      if ( (*(_DWORD *)off_1022F0 & 0x400) != 0 )
        v25 *= 2;
      if ( (*(_DWORD *)off_1022F4 & 0x80000) != 0 && (*(_DWORD *)off_1022F4 & 0x40000) != 0 )
        v25 >>= 1;
      v26 = *(unsigned __int8 *)off_1022F8 * v25;
      if ( a1 )
      {
        v100 = sub_1429D4(a3);
        v102 = v101;
        LODWORD(v103) = sub_1429D4(v26);
        v104 = (unsigned int *)off_102910;
        v105 = v103;
        v106 = sub_142AA8(v103, 0, dword_10290C);
        LODWORD(v108) = sub_142CFC(v100, v102, v106, v107);
        LODWORD(v109) = sub_142AA8(v108, 0, dword_102914);
        v110 = math_round(v109);
        v111 = sub_14302C(v110, SHIDWORD(v110));
        LODWORD(v112) = sub_142CFC(v100, v102, 0, dword_102918);
        v113 = math_round(v112);
        LODWORD(v114) = sub_1429B4(v111);
        LODWORD(v115) = sub_142AA8(v114, 0, dword_10290C);
        LODWORD(v116) = sub_142AA8(v115, v105, HIDWORD(v105));
        LODWORD(v47) = sub_142AA8(v116, 0, dword_10291C);
        HIDWORD(v47) = v117;
        fmac_hw_setup(0);
        *(_DWORD *)off_102920 = v111 & 0x7FFFFFFF;
        v118 = sub_14302C(v113, SHIDWORD(v113));
        v119 = off_10292C;
        *v104 = dword_102928 & *v104 | dword_102924 & (v118 << 13);
        *v119 |= 1u;
        if ( a1 == 1 )
        {
          v120 = (unsigned int *)off_102934;
          LODWORD(v121) = sub_142CFC(0, dword_102930, v47, HIDWORD(v47));
          v122 = math_round(v121);
          *v120 = *v120 & 0xF0000000 | sub_142FDC(v122, SHIDWORD(v122)) & 0xFFFFFFF;
          v54 = 1;
          LODWORD(v56) = sub_142CFC(v47, HIDWORD(v47), 0, dword_102938);
          HIDWORD(v56) = v123;
LABEL_26:
          if ( sub_142FB4(v56, SHIDWORD(v56), 0, dword_102328) )
          {
            v129 = sub_142AA8(v56, 0, 0x41800000u);
            LODWORD(v131) = sub_142CFC(v129, v130, 0, dword_102954);
            v132 = math_round(v131);
            v62 = sub_142FDC(v132, SHIDWORD(v132));
            v63 = 0x20000000;
          }
          else
          {
            v57 = sub_142FB4(v56, SHIDWORD(v56), 0, dword_10232C);
            v58 = sub_142AA8(v56, 0, 0x41800000u);
            if ( v57 )
            {
              LODWORD(v60) = sub_142CFC(v58, v59, 0, dword_10232C);
              v61 = math_round(v60);
              v62 = sub_142FDC(v61, SHIDWORD(v61));
              v63 = 0x10000000;
            }
            else
            {
              LODWORD(v127) = sub_142CFC(v58, v59, 0, dword_102950);
              v128 = math_round(v127);
              v62 = sub_142FDC(v128, SHIDWORD(v128));
              v63 = 0;
            }
          }
          v64 = off_102334;
          v65 = (unsigned int *)off_102338;
          v66 = (unsigned int *)off_102340;
          *(_DWORD *)off_102330 = v62 & 0xFFFFFFF;
          *v64 = *v64 & 0xFFFFFFF | v63;
          *v65 = *v65 & 0xFFFFFFFC | v54;
          LODWORD(v67) = sub_1429D4(a2);
          v68 = sub_14273C(v67, v47);
          v70 = v69;
          v71 = sub_1429D4(a3);
          v73 = sub_142738(v68, v70, v71, v72);
          v74 = (unsigned int *)off_102344;
          LODWORD(v75) = sub_142CFC(0, dword_10233C, v47, HIDWORD(v47));
          LODWORD(v76) = 0;
          HIDWORD(v76) = dword_102304;
          v77 = sub_14273C(v75, v76);
          v133 = *v66;
          *v66 = v133 & 0xFFFF8000 | sub_14302C(v77, v78) & 0x7FFF;
          v79 = sub_142AA8(v47, 0, dword_1025A0);
          LODWORD(v81) = sub_142CFC(v79, v80, v73, HIDWORD(v73));
          HIDWORD(v82) = dword_1025A4;
          v83 = *v74;
          LODWORD(v82) = 0;
          v84 = sub_14273C(v81, v82);
          *v74 = (unsigned __int16)sub_14302C(v84, v85) | (HIWORD(v83) << 16);
          LODWORD(v86) = sub_142CFC(0, dword_1025A8, v73, HIDWORD(v73));
          HIDWORD(v87) = dword_1025A4;
          LODWORD(v87) = 0;
          v88 = sub_14273C(v86, v87);
          *v74 = *v74 & 0x8000FFFF | dword_1025AC & (sub_14302C(v88, v89) << 16);
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
            v95 = 0;
            v92 = 0x100000;
            v93 = 419430400;
            v94 = 10;
          }
          v96 = (unsigned int *)off_1025B0;
          v97 = off_1025B4;
          v98 = (unsigned int *)off_1025B8;
          *(_DWORD *)off_1025B0 = *(_DWORD *)off_1025B0 & 0xFFFFFFCF | v90;
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
        LODWORD(v27) = sub_1429D4(a3);
        HIDWORD(v27) = v28;
        LODWORD(v29) = sub_1429D4(v26);
        HIDWORD(v29) = v30;
        v31 = sub_14273C(v27, v27);
        v33 = v32;
        v34 = sub_142AA8(v29, 0, dword_1022FC);
        LODWORD(v36) = sub_142CFC(v31, v33, v34, v35);
        LODWORD(v37) = sub_142AA8(v36, 0, dword_102300);
        v38 = math_round(v37);
        v39 = sub_14302C(v38, SHIDWORD(v38));
        LODWORD(v40) = sub_142CFC(v27, HIDWORD(v27), 0, dword_1022FC);
        v41 = math_round(v40);
        LODWORD(v42) = sub_1429B4(v39);
        LODWORD(v43) = sub_142AA8(v42, 0, dword_1022FC);
        LODWORD(v44) = sub_142AA8(v43, 0, dword_102304);
        LODWORD(v45) = sub_142AA8(v44, v29, HIDWORD(v29));
        LODWORD(v47) = sub_142AA8(v45, 0, dword_102308);
        HIDWORD(v47) = v46;
        fmac_hw_setup(0);
        v48 = (unsigned int *)off_102310;
        *(_DWORD *)off_10230C = v39 & 0x7FFFFFFF;
        v49 = sub_14302C(v41, SHIDWORD(v41));
        v50 = off_10231C;
        *v48 = dword_102318 & *v48 | dword_102314 & (v49 << 13);
        *v50 |= 1u;
      }
      v51 = (unsigned int *)off_102324;
      LODWORD(v52) = sub_142CFC(0, dword_102320, v47, HIDWORD(v47));
      v53 = math_round(v52);
      *v51 = sub_142FDC(v53, SHIDWORD(v53)) & 0xFFFFFFF | *v51 & 0xF0000000;
      v54 = 0;
      LODWORD(v56) = sub_142CFC(v47, HIDWORD(v47), dword_1022B0, dword_1022B4);
      HIDWORD(v56) = v55;
      goto LABEL_26;
    }
  }
  else
  {
    sub_12F46C(dword_1025CC, dword_1025C8, 5664);
  }
  v99 = off_1025D0;
  mmio_ahb_gate_release_n_60(a3);
  if ( *(_DWORD *)(v99 + 0x4) )
    fw_init_entry();
  if ( a4 )
  {
    if ( a4 == 1 )
      *(_DWORD *)off_102958 = *(_DWORD *)off_102958 & 0xFFFFFFC7 | 0x18;
    else
      *(_DWORD *)off_1025D4 = *(_DWORD *)off_1025D4 & 0xFFFFFFC7 | 0x20;
  }
  else
  {
    *(_DWORD *)off_102958 = *(_DWORD *)off_102958 & 0xFFFFFFC7 | 0x10;
  }
  goto LABEL_18;
}

