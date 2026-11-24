// sub_101DE8 @ 0x101de8, size 2412 bytes
void __fastcall sub_101DE8(unsigned int a1, int a2, int a3, unsigned int a4, int a5, unsigned __int8 a6)
{
  int variant_cached; // r0
  __int16 v12; // r6
  __int64 v13; // r0
  unsigned int v14; // r0
  int v15; // r1
  unsigned int v16; // r0
  int v17; // r1
  int v18; // r2
  unsigned int v19; // r3
  __int64 v20; // r0
  unsigned int *v21; // r7
  __int64 v22; // r0
  _DWORD *v23; // r2
  _DWORD *v24; // r2
  int v25; // r1
  _BYTE *v26; // r6
  unsigned int v27; // r3
  int v28; // r6
  __int64 v29; // r8
  int v30; // r1
  __int64 v31; // r10
  int v32; // r1
  unsigned int v33; // r6
  unsigned int v34; // r1
  unsigned int v35; // r7
  unsigned int v36; // r0
  unsigned int v37; // r1
  __int64 v38; // r0
  __int64 v39; // r0
  __int64 v40; // r0
  unsigned int v41; // r6
  __int64 v42; // r0
  __int64 v43; // r8
  __int64 v44; // r0
  __int64 v45; // r0
  __int64 v46; // r0
  __int64 v47; // r0
  int v48; // r1
  __int64 v49; // r10
  unsigned int *v50; // r5
  unsigned int v51; // r0
  _DWORD *v52; // r2
  unsigned int *v53; // r5
  __int64 v54; // r0
  __int64 v55; // r0
  int v56; // r9
  int v57; // r1
  __int64 v58; // r6
  BOOL v59; // r5
  unsigned int v60; // r0
  unsigned int v61; // r1
  __int64 v62; // r0
  __int64 v63; // r0
  unsigned int v64; // r0
  int v65; // r1
  _DWORD *v66; // r5
  unsigned int *v67; // r2
  unsigned int *v68; // r8
  __int64 v69; // r0
  int v70; // r6
  int v71; // r1
  int v72; // r7
  int v73; // r0
  int v74; // r1
  __int64 v75; // r6
  unsigned int *v76; // r9
  __int64 v77; // r0
  __int64 v78; // r2
  unsigned int v79; // r0
  int v80; // r1
  unsigned int v81; // r0
  unsigned int v82; // r1
  __int64 v83; // r0
  __int64 v84; // r2
  unsigned int v85; // r8
  unsigned int v86; // r0
  int v87; // r1
  __int64 v88; // r0
  __int64 v89; // r2
  unsigned int v90; // r0
  int v91; // r1
  int v92; // r2
  int v93; // r8
  int v94; // r0
  int v95; // lr
  int v96; // r12
  int v97; // r6
  unsigned int *v98; // r1
  _DWORD *v99; // r7
  unsigned int *v100; // r5
  _BYTE *v101; // r6
  unsigned int v102; // r8
  unsigned int v103; // r1
  unsigned int v104; // r9
  __int64 v105; // r0
  unsigned int *v106; // r7
  __int64 v107; // r10
  unsigned int v108; // r0
  unsigned int v109; // r1
  __int64 v110; // r0
  __int64 v111; // r0
  __int64 v112; // r0
  unsigned int v113; // r6
  __int64 v114; // r0
  __int64 v115; // r8
  __int64 v116; // r0
  __int64 v117; // r0
  __int64 v118; // r0
  int v119; // r1
  unsigned int v120; // r0
  _DWORD *v121; // r2
  unsigned int *v122; // r6
  __int64 v123; // r0
  __int64 v124; // r0
  int v125; // r1
  __int64 v126; // r0
  unsigned int *v127; // r7
  __int64 v128; // r0
  __int64 v129; // r0
  __int64 v130; // r0
  unsigned int v131; // r0
  unsigned int v132; // r1
  __int64 v133; // r0
  __int64 v134; // r0
  unsigned int v135; // [sp+20h] [bp-4Ch]

  sub_12ECB0(dword_102134, dword_102130, a1, a2, a3, a4, a6);
  if ( **(_BYTE **)off_102138 != 3 )
    feature_guard_sdio(4, dword_10213C, a3);
  variant_update_cache(a4);
  rf_calib_init_handler(a1, a2, a3, a4, a5);
  variant_cached = get_variant_cached();
  v12 = variant_cached;
  if ( variant_cached == 240 )
  {
    if ( a4 <= 1 )
      HIDWORD(v126) = dword_1027BC;
    else
      HIDWORD(v126) = dword_1027B8;
    v127 = (unsigned int *)off_1027C0;
    LODWORD(v126) = 0;
    v128 = sub_1426B8(v126);
    *v127 = *v127 & 0xC00FFFFF | dword_1027C4 & (sub_1430C8(v128, SHIDWORD(v128)) << 20);
  }
  else
  {
    LODWORD(v13) = sub_142A70(variant_cached);
    if ( a4 > 1 )
      v14 = sub_142B44(v13, dword_102410, dword_102414);
    else
      v14 = sub_142B44(v13, dword_102120, dword_102124);
    v16 = sub_143108(v14, v15);
    LODWORD(v20) = sub_142A94(v16, v17, v18, v19);
    v21 = (unsigned int *)off_102140;
    v22 = sub_1426B8(v20);
    *v21 = *v21 & 0xF003FFFF | dword_102144 & (sub_1430C8(v22, SHIDWORD(v22)) << 18);
  }
  if ( a1 )
    v23 = off_1027B4;
  else
    v23 = off_102148;
  *(_DWORD *)off_10214C = (unsigned __int16)*(_DWORD *)off_10214C
                        | (((*v23 >> 8) - (unsigned __int16)(((*(_DWORD *)off_102140 >> 18) & 0x3FF) + v12)) << 16);
  v24 = off_102154;
  *(_DWORD *)off_102150 = *(_DWORD *)off_102150 & 0xFFFE1FFF | 0xE000;
  v25 = *((unsigned __int8 *)off_102158 + 36);
  *v24 &= ~4u;
  if ( v25 != a1 )
    rf_power_enable(a1);
  if ( **(__int16 **)off_10215C >= 0 || a1 <= 1 )
  {
    if ( !a1 )
    {
      v26 = off_102160;
      mmio_init_block_1200E54(a3, a4);
      if ( *(_DWORD *)(v26 + 0x4) )
        sub_100730();
      if ( a4 )
      {
        if ( a4 == 1 )
          *(_DWORD *)off_102164 = *(_DWORD *)off_102164 & 0xFFFFFFC7 | 8;
      }
      else
      {
        *(_DWORD *)off_1027D0 &= 0xFFFFFFC7;
      }
LABEL_18:
      v27 = (*(_DWORD *)off_102168 >> 5) & 0x1F;
      if ( (*(_DWORD *)off_102168 & 0x400) != 0 )
        v27 *= 2;
      if ( (*(_DWORD *)off_10216C & 0x80000) != 0 && (*(_DWORD *)off_10216C & 0x40000) != 0 )
        v27 >>= 1;
      v28 = *(unsigned __int8 *)off_102170 * v27;
      if ( a1 )
      {
        v102 = sub_142A70(a3);
        v104 = v103;
        LODWORD(v105) = sub_142A70(v28);
        v106 = (unsigned int *)off_102788;
        v107 = v105;
        v108 = sub_142B44(v105, 0, dword_102784);
        LODWORD(v110) = sub_142D98(v102, v104, v108, v109);
        LODWORD(v111) = sub_142B44(v110, 0, dword_10278C);
        v112 = sub_1426B8(v111);
        v113 = sub_1430C8(v112, SHIDWORD(v112));
        LODWORD(v114) = sub_142D98(v102, v104, 0, dword_102790);
        v115 = sub_1426B8(v114);
        LODWORD(v116) = sub_142A50(v113);
        LODWORD(v117) = sub_142B44(v116, 0, dword_102784);
        LODWORD(v118) = sub_142B44(v117, v107, HIDWORD(v107));
        LODWORD(v49) = sub_142B44(v118, 0, dword_102794);
        HIDWORD(v49) = v119;
        mmio_set_byte_field(0);
        *(_DWORD *)off_102798 = v113 & 0x7FFFFFFF;
        v120 = sub_1430C8(v115, SHIDWORD(v115));
        v121 = off_1027A4;
        *v106 = dword_1027A0 & *v106 | dword_10279C & (v120 << 13);
        *v121 |= 1u;
        if ( a1 == 1 )
        {
          v122 = (unsigned int *)off_1027AC;
          LODWORD(v123) = sub_142D98(0, dword_1027A8, v49, HIDWORD(v49));
          v124 = sub_1426B8(v123);
          *v122 = *v122 & 0xF0000000 | sub_143078(v124, SHIDWORD(v124)) & 0xFFFFFFF;
          v56 = 1;
          LODWORD(v58) = sub_142D98(v49, HIDWORD(v49), 0, dword_1027B0);
          HIDWORD(v58) = v125;
LABEL_26:
          if ( sub_143050(v58, SHIDWORD(v58), 0, dword_1021A0) )
          {
            v131 = sub_142B44(v58, 0, 0x41800000u);
            LODWORD(v133) = sub_142D98(v131, v132, 0, dword_1027CC);
            v134 = sub_1426B8(v133);
            v64 = sub_143078(v134, SHIDWORD(v134));
            v65 = 0x20000000;
          }
          else
          {
            v59 = sub_143050(v58, SHIDWORD(v58), 0, dword_1021A4);
            v60 = sub_142B44(v58, 0, 0x41800000u);
            if ( v59 )
            {
              LODWORD(v62) = sub_142D98(v60, v61, 0, dword_1021A4);
              v63 = sub_1426B8(v62);
              v64 = sub_143078(v63, SHIDWORD(v63));
              v65 = 0x10000000;
            }
            else
            {
              LODWORD(v129) = sub_142D98(v60, v61, 0, dword_1027C8);
              v130 = sub_1426B8(v129);
              v64 = sub_143078(v130, SHIDWORD(v130));
              v65 = 0;
            }
          }
          v66 = off_1021AC;
          v67 = (unsigned int *)off_1021B0;
          v68 = (unsigned int *)off_1021B8;
          *(_DWORD *)off_1021A8 = v64 & 0xFFFFFFF;
          *v66 = *v66 & 0xFFFFFFF | v65;
          *v67 = *v67 & 0xFFFFFFFC | v56;
          LODWORD(v69) = sub_142A70(a2);
          v70 = sub_1427D8(v69, v49);
          v72 = v71;
          v73 = sub_142A70(a3);
          v75 = sub_1427D4(v70, v72, v73, v74);
          v76 = (unsigned int *)off_1021BC;
          LODWORD(v77) = sub_142D98(0, dword_1021B4, v49, HIDWORD(v49));
          LODWORD(v78) = 0;
          HIDWORD(v78) = dword_10217C;
          v79 = sub_1427D8(v77, v78);
          v135 = *v68;
          *v68 = v135 & 0xFFFF8000 | sub_1430C8(v79, v80) & 0x7FFF;
          v81 = sub_142B44(v49, 0, dword_102418);
          LODWORD(v83) = sub_142D98(v81, v82, v75, HIDWORD(v75));
          HIDWORD(v84) = dword_10241C;
          v85 = *v76;
          LODWORD(v84) = 0;
          v86 = sub_1427D8(v83, v84);
          *v76 = (unsigned __int16)sub_1430C8(v86, v87) | (HIWORD(v85) << 16);
          LODWORD(v88) = sub_142D98(0, dword_102420, v75, HIDWORD(v75));
          HIDWORD(v89) = dword_10241C;
          LODWORD(v89) = 0;
          v90 = sub_1427D8(v88, v89);
          *v76 = *v76 & 0x8000FFFF | dword_102424 & (sub_1430C8(v90, v91) << 16);
          *v66 = a4 & 0xF | *v66 & 0xFFFFFFF0;
          if ( a4 )
          {
            if ( a4 == 1 )
            {
              v93 = 0;
              v97 = 0;
              v92 = 16;
              v94 = 0x100000;
              v95 = 402653184;
              v96 = 11;
            }
            else
            {
              v92 = 32;
              v93 = 0x80000;
              v94 = 3145728;
              v95 = 402653184;
              v96 = 13;
              v97 = 256;
            }
          }
          else
          {
            v92 = 0;
            v93 = 0;
            v97 = 0;
            v94 = 0x100000;
            v95 = 419430400;
            v96 = 10;
          }
          v98 = (unsigned int *)off_102428;
          v99 = off_10242C;
          v100 = (unsigned int *)off_102430;
          *(_DWORD *)off_102428 = *(_DWORD *)off_102428 & 0xFFFFFFCF | v92;
          *v98 = *v98 & 0xFFF3FFFF | v93;
          *v98 = *v98 & 0xFFCFFFFF | v94;
          *v99 = *v99 & 0xFFFFFF | v95;
          *v99 = *v99 & 0xFFFFFF00 | v96;
          *v100 = *v100 & 0xFFFFFEFF | v97;
          while ( 1 )
            ;
        }
      }
      else
      {
        LODWORD(v29) = sub_142A70(a3);
        HIDWORD(v29) = v30;
        LODWORD(v31) = sub_142A70(v28);
        HIDWORD(v31) = v32;
        v33 = sub_1427D8(v29, v29);
        v35 = v34;
        v36 = sub_142B44(v31, 0, dword_102174);
        LODWORD(v38) = sub_142D98(v33, v35, v36, v37);
        LODWORD(v39) = sub_142B44(v38, 0, dword_102178);
        v40 = sub_1426B8(v39);
        v41 = sub_1430C8(v40, SHIDWORD(v40));
        LODWORD(v42) = sub_142D98(v29, HIDWORD(v29), 0, dword_102174);
        v43 = sub_1426B8(v42);
        LODWORD(v44) = sub_142A50(v41);
        LODWORD(v45) = sub_142B44(v44, 0, dword_102174);
        LODWORD(v46) = sub_142B44(v45, 0, dword_10217C);
        LODWORD(v47) = sub_142B44(v46, v31, HIDWORD(v31));
        LODWORD(v49) = sub_142B44(v47, 0, dword_102180);
        HIDWORD(v49) = v48;
        mmio_set_byte_field(0);
        v50 = (unsigned int *)off_102188;
        *(_DWORD *)off_102184 = v41 & 0x7FFFFFFF;
        v51 = sub_1430C8(v43, SHIDWORD(v43));
        v52 = off_102194;
        *v50 = dword_102190 & *v50 | dword_10218C & (v51 << 13);
        *v52 |= 1u;
      }
      v53 = (unsigned int *)off_10219C;
      LODWORD(v54) = sub_142D98(0, dword_102198, v49, HIDWORD(v49));
      v55 = sub_1426B8(v54);
      *v53 = sub_143078(v55, SHIDWORD(v55)) & 0xFFFFFFF | *v53 & 0xF0000000;
      v56 = 0;
      LODWORD(v58) = sub_142D98(v49, HIDWORD(v49), dword_102128, dword_10212C);
      HIDWORD(v58) = v57;
      goto LABEL_26;
    }
  }
  else
  {
    sub_12F694(dword_102444, dword_102440, 5664);
  }
  v101 = off_102448;
  sys_irq_dispatch(a3);
  if ( *(_DWORD *)(v101 + 0x4) )
    sub_10076C();
  if ( a4 )
  {
    if ( a4 == 1 )
      *(_DWORD *)off_1027D0 = *(_DWORD *)off_1027D0 & 0xFFFFFFC7 | 0x18;
    else
      *(_DWORD *)off_10244C = *(_DWORD *)off_10244C & 0xFFFFFFC7 | 0x20;
  }
  else
  {
    *(_DWORD *)off_1027D0 = *(_DWORD *)off_1027D0 & 0xFFFFFFC7 | 0x10;
  }
  goto LABEL_18;
}

