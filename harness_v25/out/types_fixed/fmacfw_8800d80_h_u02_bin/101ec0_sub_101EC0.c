// sub_101EC0 @ 0x101ec0, size 2412 bytes
void __fastcall sub_101EC0(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int8 a5,
        unsigned __int8 a6)
{
  int v11; // r0
  int variant_cached; // r0
  __int16 v13; // r6
  __int64 v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r0
  unsigned int *v18; // r7
  int v19; // r1
  int v20; // r0
  _DWORD *v21; // r2
  _DWORD *v22; // r2
  int v23; // r1
  _BYTE *v24; // r6
  int v25; // r0
  unsigned int v26; // r3
  int v27; // r6
  __int64 v28; // r8
  __int64 v29; // r10
  __int64 v30; // r6
  __int64 v31; // r0
  __int64 v32; // r0
  __int64 v33; // r0
  int v34; // r0
  __int64 v35; // r0
  __int64 v36; // r0
  __int64 v37; // r0
  __int64 v38; // r0
  __int64 v39; // r0
  __int64 v40; // r10
  int *v41; // r5
  int v42; // r0
  _DWORD *v43; // r2
  unsigned int *v44; // r5
  __int64 v45; // r0
  __int64 v46; // r0
  int v47; // r9
  __int64 v48; // r6
  int v49; // r5
  __int64 v50; // r0
  __int64 v51; // r0
  __int64 v52; // r0
  int v53; // r0
  int v54; // r1
  _DWORD *v55; // r5
  unsigned int *v56; // r2
  unsigned int *v57; // r8
  __int64 v58; // r0
  __int64 v59; // r6
  __int64 v60; // r0
  __int64 v61; // r6
  unsigned int *v62; // r9
  __int64 v63; // r0
  int v64; // r0
  __int64 v65; // r0
  __int64 v66; // r0
  unsigned int v67; // r8
  int v68; // r0
  __int64 v69; // r0
  int v70; // r0
  int v71; // r2
  int v72; // r8
  int v73; // r0
  int v74; // lr
  int v75; // r12
  int v76; // r6
  unsigned int *v77; // r1
  _DWORD *v78; // r7
  unsigned int *v79; // r5
  _BYTE *v80; // r6
  int v81; // r0
  __int64 v82; // r8
  __int64 v83; // r0
  int *v84; // r7
  __int64 v85; // r10
  __int64 v86; // r0
  __int64 v87; // r0
  __int64 v88; // r0
  int v89; // r0
  int v90; // r6
  __int64 v91; // r0
  __int64 v92; // r0
  __int64 v93; // r0
  __int64 v94; // r0
  int v95; // r0
  _DWORD *v96; // r2
  unsigned int *v97; // r6
  __int64 v98; // r0
  __int64 v99; // r0
  int v100; // r1
  unsigned int *v101; // r7
  int v102; // r0
  __int64 v103; // r0
  __int64 v104; // r0
  __int64 v105; // r0
  __int64 v106; // r0
  __int64 v107; // r0
  unsigned int v108; // [sp+20h] [bp-4Ch]

  msg_parse(off_10220C, off_102208, a1, a2, a3, a4, a6);
  if ( **(_BYTE **)off_102210 != 3 )
    feature_guard_sdio(4, off_102214, a3);
  sub_100670(a4);
  sub_100BE0(a1, a2, a3, a4, a5);
  variant_cached = get_variant_cached(v11);
  v13 = variant_cached;
  if ( variant_cached == 240 )
  {
    if ( a4 <= 1 )
      v100 = dword_102894;
    else
      v100 = dword_102890;
    v101 = (unsigned int *)off_102898;
    v102 = sub_1424DC(0, v100);
    *v101 = *v101 & 0xC00FFFFF | dword_10289C & (sub_142EEC(v102) << 20);
  }
  else
  {
    v14 = sub_142894(variant_cached);
    if ( a4 > 1 )
      v15 = sub_142968(v14, HIDWORD(v14), dword_1024E8, dword_1024EC);
    else
      v15 = sub_142968(v14, HIDWORD(v14), dword_1021F8, dword_1021FC);
    v16 = sub_142F2C(v15);
    v17 = sub_1428B8(v16);
    v18 = (unsigned int *)off_102218;
    v20 = sub_1424DC(v17, v19);
    *v18 = *v18 & 0xF003FFFF | dword_10221C & (sub_142EEC(v20) << 18);
  }
  if ( a1 )
    v21 = off_10288C;
  else
    v21 = off_102220;
  *(_DWORD *)off_102224 = (unsigned __int16)*(_DWORD *)off_102224
                        | (((*v21 >> 8) - (unsigned __int16)(((*(_DWORD *)off_102218 >> 18) & 0x3FF) + v13)) << 16);
  v22 = off_10222C;
  *(_DWORD *)off_102228 = *(_DWORD *)off_102228 & 0xFFFE1FFF | 0xE000;
  v23 = *((unsigned __int8 *)off_102230 + 36);
  *v22 &= ~4u;
  if ( v23 != a1 )
    sub_103180(a1);
  if ( **(__int16 **)off_102234 >= 0 || a1 <= 1 )
  {
    if ( !a1 )
    {
      v24 = off_102238;
      v25 = sub_100FAC(a3, a4);
      if ( *(_DWORD *)(v24 + 0x4) )
        sub_100730(v25);
      if ( a4 )
      {
        if ( a4 == 1 )
          *(_DWORD *)off_10223C = *(_DWORD *)off_10223C & 0xFFFFFFC7 | 8;
      }
      else
      {
        *(_DWORD *)off_1028A8 &= 0xFFFFFFC7;
      }
LABEL_18:
      v26 = (*(_DWORD *)off_102240 >> 5) & 0x1F;
      if ( (*(_DWORD *)off_102240 & 0x400) != 0 )
        v26 *= 2;
      if ( (*(_DWORD *)off_102244 & 0x80000) != 0 && (*(_DWORD *)off_102244 & 0x40000) != 0 )
        v26 >>= 1;
      v27 = (unsigned __int8)*off_102248 * v26;
      if ( a1 )
      {
        v82 = sub_142894(a3);
        v83 = sub_142894(v27);
        v84 = (int *)off_102860;
        v85 = v83;
        v86 = sub_142968(v83, HIDWORD(v83), 0, dword_10285C);
        v87 = sub_142BBC(v82, HIDWORD(v82), v86, HIDWORD(v86));
        v88 = sub_142968(v87, HIDWORD(v87), 0, dword_102864);
        v89 = sub_1424DC(v88, HIDWORD(v88));
        v90 = sub_142EEC(v89);
        v91 = sub_142BBC(v82, HIDWORD(v82), 0, dword_102868);
        LODWORD(v82) = sub_1424DC(v91, HIDWORD(v91));
        v92 = sub_142874(v90);
        v93 = sub_142968(v92, HIDWORD(v92), 0, dword_10285C);
        v94 = sub_142968(v93, HIDWORD(v93), v85, HIDWORD(v85));
        v40 = sub_142968(v94, HIDWORD(v94), 0, dword_10286C);
        sub_101E7C(0);
        *(_DWORD *)off_102870 = v90 & 0x7FFFFFFF;
        v95 = sub_142EEC(v82);
        v96 = off_10287C;
        *v84 = dword_102878 & *v84 | dword_102874 & (v95 << 13);
        *v96 |= 1u;
        if ( a1 == 1 )
        {
          v97 = (unsigned int *)off_102884;
          v98 = sub_142BBC(0, dword_102880, v40, HIDWORD(v40));
          v99 = sub_1424DC(v98, HIDWORD(v98));
          *v97 = *v97 & 0xF0000000 | sub_142E9C(v99, HIDWORD(v99)) & 0xFFFFFFF;
          v47 = 1;
          v48 = sub_142BBC(v40, HIDWORD(v40), 0, dword_102888);
LABEL_26:
          if ( sub_142E74(v48, HIDWORD(v48), 0, dword_102278) )
          {
            v105 = sub_142968(v48, HIDWORD(v48), 0, 1098907648);
            v106 = sub_142BBC(v105, HIDWORD(v105), 0, dword_1028A4);
            v107 = sub_1424DC(v106, HIDWORD(v106));
            v53 = sub_142E9C(v107, HIDWORD(v107));
            v54 = 0x20000000;
          }
          else
          {
            v49 = sub_142E74(v48, HIDWORD(v48), 0, dword_10227C);
            v50 = sub_142968(v48, HIDWORD(v48), 0, 1098907648);
            if ( v49 )
            {
              v51 = sub_142BBC(v50, HIDWORD(v50), 0, dword_10227C);
              v52 = sub_1424DC(v51, HIDWORD(v51));
              v53 = sub_142E9C(v52, HIDWORD(v52));
              v54 = 0x10000000;
            }
            else
            {
              v103 = sub_142BBC(v50, HIDWORD(v50), 0, dword_1028A0);
              v104 = sub_1424DC(v103, HIDWORD(v103));
              v53 = sub_142E9C(v104, HIDWORD(v104));
              v54 = 0;
            }
          }
          v55 = off_102284;
          v56 = (unsigned int *)off_102288;
          v57 = (unsigned int *)off_102290;
          *(_DWORD *)off_102280 = v53 & 0xFFFFFFF;
          *v55 = *v55 & 0xFFFFFFF | v54;
          *v56 = *v56 & 0xFFFFFFFC | v47;
          v58 = sub_142894(a2);
          v59 = sub_1425FC(v58, HIDWORD(v58), v40, HIDWORD(v40));
          v60 = sub_142894(a3);
          v61 = sub_1425F8(v59, HIDWORD(v59), v60, HIDWORD(v60));
          v62 = (unsigned int *)off_102294;
          v63 = sub_142BBC(0, dword_10228C, v40, HIDWORD(v40));
          v64 = sub_1425FC(v63, HIDWORD(v63), 0, dword_102254);
          v108 = *v57;
          *v57 = v108 & 0xFFFF8000 | sub_142EEC(v64) & 0x7FFF;
          v65 = sub_142968(v40, HIDWORD(v40), 0, dword_1024F0);
          v66 = sub_142BBC(v65, HIDWORD(v65), v61, HIDWORD(v61));
          v67 = *v62;
          v68 = sub_1425FC(v66, HIDWORD(v66), 0, dword_1024F4);
          *v62 = (unsigned __int16)sub_142EEC(v68) | (HIWORD(v67) << 16);
          v69 = sub_142BBC(0, dword_1024F8, v61, HIDWORD(v61));
          v70 = sub_1425FC(v69, HIDWORD(v69), 0, dword_1024F4);
          *v62 = *v62 & 0x8000FFFF | dword_1024FC & (sub_142EEC(v70) << 16);
          *v55 = a4 & 0xF | *v55 & 0xFFFFFFF0;
          if ( a4 )
          {
            if ( a4 == 1 )
            {
              v72 = 0;
              v76 = 0;
              v71 = 16;
              v73 = 0x100000;
              v74 = 402653184;
              v75 = 11;
            }
            else
            {
              v71 = 32;
              v72 = 0x80000;
              v73 = 3145728;
              v74 = 402653184;
              v75 = 13;
              v76 = 256;
            }
          }
          else
          {
            v71 = 0;
            v72 = 0;
            v76 = 0;
            v73 = 0x100000;
            v74 = 419430400;
            v75 = 10;
          }
          v77 = (unsigned int *)off_102500;
          v78 = off_102504;
          v79 = (unsigned int *)off_102508;
          *(_DWORD *)off_102500 = *(_DWORD *)off_102500 & 0xFFFFFFCF | v71;
          *v77 = *v77 & 0xFFF3FFFF | v72;
          *v77 = *v77 & 0xFFCFFFFF | v73;
          *v78 = *v78 & 0xFFFFFF | v74;
          *v78 = *v78 & 0xFFFFFF00 | v75;
          *v79 = *v79 & 0xFFFFFEFF | v76;
          while ( 1 )
            ;
        }
      }
      else
      {
        v28 = sub_142894(a3);
        v29 = sub_142894(v27);
        v30 = sub_1425FC(v28, HIDWORD(v28), v28, HIDWORD(v28));
        v31 = sub_142968(v29, HIDWORD(v29), 0, dword_10224C);
        v32 = sub_142BBC(v30, HIDWORD(v30), v31, HIDWORD(v31));
        v33 = sub_142968(v32, HIDWORD(v32), 0, dword_102250);
        v34 = sub_1424DC(v33, HIDWORD(v33));
        LODWORD(v30) = sub_142EEC(v34);
        v35 = sub_142BBC(v28, HIDWORD(v28), 0, dword_10224C);
        LODWORD(v28) = sub_1424DC(v35, HIDWORD(v35));
        v36 = sub_142874(v30);
        v37 = sub_142968(v36, HIDWORD(v36), 0, dword_10224C);
        v38 = sub_142968(v37, HIDWORD(v37), 0, dword_102254);
        v39 = sub_142968(v38, HIDWORD(v38), v29, HIDWORD(v29));
        v40 = sub_142968(v39, HIDWORD(v39), 0, dword_102258);
        sub_101E7C(0);
        v41 = (int *)off_102260;
        *(_DWORD *)off_10225C = v30 & 0x7FFFFFFF;
        v42 = sub_142EEC(v28);
        v43 = off_10226C;
        *v41 = dword_102268 & *v41 | dword_102264 & (v42 << 13);
        *v43 |= 1u;
      }
      v44 = (unsigned int *)off_102274;
      v45 = sub_142BBC(0, dword_102270, v40, HIDWORD(v40));
      v46 = sub_1424DC(v45, HIDWORD(v45));
      *v44 = sub_142E9C(v46, HIDWORD(v46)) & 0xFFFFFFF | *v44 & 0xF0000000;
      v47 = 0;
      v48 = sub_142BBC(v40, HIDWORD(v40), dword_102200, dword_102204);
      goto LABEL_26;
    }
  }
  else
  {
    sub_12F32C(off_10251C, off_102518[0], 5664);
  }
  v80 = off_102520;
  v81 = sub_101260(a3, a4);
  if ( *(_DWORD *)(v80 + 0x4) )
    sub_10076C(v81);
  if ( a4 )
  {
    if ( a4 == 1 )
      *(_DWORD *)off_1028A8 = *(_DWORD *)off_1028A8 & 0xFFFFFFC7 | 0x18;
    else
      *(_DWORD *)off_102524 = *(_DWORD *)off_102524 & 0xFFFFFFC7 | 0x20;
  }
  else
  {
    *(_DWORD *)off_1028A8 = *(_DWORD *)off_1028A8 & 0xFFFFFFC7 | 0x10;
  }
  goto LABEL_18;
}

