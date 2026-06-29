// sub_105A88 @ 0x105a88, size 2120 bytes
unsigned int * sub_105A88(int a1, int a2, int a3, unsigned int a4, unsigned __int8 a5, int a6)
{
  uint32_t *v6; // lr
  unsigned int *v7; // r4
  unsigned int *v8; // r5
  unsigned int *v9; // r12
  unsigned int *v10; // r7
  unsigned int *v11; // r9
  unsigned int *v12; // r0
  unsigned int v13; // r11
  unsigned int v14; // r10
  unsigned int v15; // r8
  unsigned int v16; // lr
  uint32_t *v19; // r2
  int v20; // r1
  unsigned int *v21; // r11
  unsigned int *v22; // r9
  int *v23; // r8
  uint32_t *v24; // r1
  unsigned int v25; // r10
  unsigned int v26; // r6
  unsigned int v27; // r5
  unsigned int v28; // r11
  unsigned int v29; // lr
  unsigned int v30; // r4
  unsigned int v31; // r9
  unsigned int v32; // r12
  int v33; // r10
  void *v34; // r3
  void *v35; // r3
  void *v36; // r3
  void *v37; // r3
  void *v38; // r3
  char *v39; // r2
  uint32_t *v40; // r4
  unsigned int *v41; // r1
  unsigned int *v42; // r0
  int v43; // r8
  int v44; // r2
  int v45; // r9
  int v46; // r8
  int v47; // r4
  unsigned int *v48; // r6
  unsigned int *v49; // r5
  unsigned int *v50; // r11
  unsigned int *v51; // r4
  unsigned int *v52; // r7
  unsigned int *v53; // r9
  unsigned int *v54; // r8
  uint32_t *v55; // r2
  unsigned int *v56; // r2
  unsigned int *v57; // r12
  unsigned int *v58; // r1
  unsigned int *v59; // r3
  unsigned int *v60; // lr
  unsigned int *result; // r0
  unsigned int *v62; // r10
  uint32_t *v63; // r6
  unsigned int *v64; // r2
  int v65; // r2
  int v66; // [sp+8h] [bp-8Ch]
  int v67; // [sp+Ch] [bp-88h]
  unsigned int v68; // [sp+10h] [bp-84h]
  int v69; // [sp+10h] [bp-84h]
  int v70; // [sp+14h] [bp-80h]
  int v71; // [sp+18h] [bp-7Ch]
  unsigned int v72; // [sp+1Ch] [bp-78h]
  int v73; // [sp+1Ch] [bp-78h]
  unsigned int v74; // [sp+20h] [bp-74h]
  int v75; // [sp+20h] [bp-74h]
  unsigned int v76; // [sp+24h] [bp-70h]
  int v77; // [sp+24h] [bp-70h]
  unsigned int v78; // [sp+28h] [bp-6Ch]
  int v79; // [sp+28h] [bp-6Ch]
  unsigned int v80; // [sp+2Ch] [bp-68h]
  int v81; // [sp+2Ch] [bp-68h]
  unsigned int v82; // [sp+30h] [bp-64h]
  int v83; // [sp+30h] [bp-64h]
  unsigned int v84; // [sp+34h] [bp-60h]
  int v85; // [sp+34h] [bp-60h]
  int v86; // [sp+38h] [bp-5Ch]
  unsigned int v87; // [sp+3Ch] [bp-58h]
  int v88; // [sp+3Ch] [bp-58h]
  unsigned int v89; // [sp+40h] [bp-54h]
  int v90; // [sp+40h] [bp-54h]
  unsigned int v91; // [sp+44h] [bp-50h]
  int v92; // [sp+44h] [bp-50h]
  unsigned int v93; // [sp+48h] [bp-4Ch]
  int v94; // [sp+48h] [bp-4Ch]
  unsigned int v95; // [sp+4Ch] [bp-48h]
  int v96; // [sp+4Ch] [bp-48h]
  unsigned int v97; // [sp+50h] [bp-44h]
  int v98; // [sp+50h] [bp-44h]
  int v99; // [sp+54h] [bp-40h]
  unsigned int v100; // [sp+58h] [bp-3Ch]
  int v101; // [sp+58h] [bp-3Ch]
  int v102; // [sp+5Ch] [bp-38h]
  int v103; // [sp+5Ch] [bp-38h]
  unsigned int v104; // [sp+60h] [bp-34h]
  int v105; // [sp+60h] [bp-34h]
  unsigned int v106; // [sp+64h] [bp-30h]
  int v107; // [sp+64h] [bp-30h]
  int v108; // [sp+68h] [bp-2Ch]
  int v109; // [sp+6Ch] [bp-28h]
  int v110; // [sp+70h] [bp-24h]
  int v111; // [sp+74h] [bp-20h]
  int v112; // [sp+78h] [bp-1Ch]
  int v113; // [sp+7Ch] [bp-18h]
  int v114; // [sp+80h] [bp-14h]
  int v115; // [sp+84h] [bp-10h]
  int v116; // [sp+88h] [bp-Ch]

  v6 = off_105D84;
  v7 = (unsigned int *)off_105D58;
  v8 = (unsigned int *)off_105D5C;
  v9 = (unsigned int *)off_105D6C;
  v10 = (unsigned int *)off_105D60;
  v11 = (unsigned int *)off_105D78;
  *(uint32_t *)off_105D84 |= 0x400u;
  v12 = (unsigned int *)off_105D64;
  *v6 &= ~0x400u;
  v13 = *v8;
  v14 = *v9;
  v68 = *v7;
  v15 = *v7;
  v16 = *v10;
  v72 = *v12;
  v74 = *v12;
  v76 = *v12;
  v78 = *v12;
  v80 = *v8;
  v84 = *(uint32_t *)off_105D68;
  v82 = *(uint32_t *)off_105D68;
  *v8 |= 0x20u;
  *v9 = *v9 & 0xF8FFFFFF | 0x2000000;
  *v7 |= 0x100000u;
  *v7 |= 0x200000u;
  *v10 = *v10 & 0xFFFFFF0F | 0xC0;
  *v11 = *v11 & 0xFFFFFFC7 | 0x20;
  v66 = (v13 >> 5) & 1;
  v67 = HIBYTE(v14) & 7;
  v69 = (v68 >> 21) & 1;
  v70 = (v15 >> 20) & 1;
  v71 = (unsigned __int8)v16 >> 4;
  v73 = (v72 >> 7) & 1;
  v75 = (v74 >> 4) & 7;
  v77 = (v76 >> 10) & 1;
  v79 = (v78 >> 8) & 3;
  v81 = (v80 >> 2) & 7;
  v113 = (v84 >> 22) & 1;
  v112 = (v82 >> 21) & 1;
  *v12 |= 0x400u;
  if ( a4 <= 8 )
  {
    *v12 = *v12 & 0xFFFFFCFF | 0x100;
    *v8 &= 0xFFFFFFE3;
    goto LABEL_3;
  }
  if ( a4 == 9 )
  {
    if ( a5 )
    {
      *v12 &= 0xFFFFFCFF;
      *v8 &= 0xFFFFFFE3;
      goto LABEL_3;
    }
    goto LABEL_26;
  }
  if ( a4 <= 0xB )
  {
LABEL_26:
    v64 = (unsigned int *)off_1062D8;
    *(uint32_t *)off_1062D4 &= 0xFFFFFCFF;
    *v64 = *v64 & 0xFFFFFFE3 | 8;
    goto LABEL_3;
  }
  if ( a5 )
  {
    *v11 = *v11 & 0xFFFFFFC7 | 0x20;
    *v8 = *v8 & 0xFFFFFFE3 | 8;
    *v12 &= 0xFFFFFCFF;
    if ( a4 == 15 && a5 == 1 )
    {
      *v11 &= 0xFFFFFFC7;
      *v12 &= 0xFFFFFCFF;
      *v8 |= 0x1Cu;
    }
  }
  else
  {
    *v11 = *v11 & 0xFFFFFFC7 | 0x10;
    *v8 |= 0x1Cu;
    *v12 &= 0xFFFFFCFF;
  }
LABEL_3:
  v19 = off_105D68;
  v20 = dword_105D70;
  v21 = (unsigned int *)off_105D88;
  v22 = (unsigned int *)off_105D8C;
  v23 = (int *)off_105D90;
  *(uint32_t *)off_105D68 = *(uint32_t *)off_105D68 & 0xFFFE00FF | 0x100;
  *v19 |= 0x20000u;
  *v19 |= 0x40000u;
  sub_12EB90(1, v20);
  v34 = off_105D74;
  v24 = off_105D7C;
  v25 = *(uint32_t *)off_105D78;
  v26 = *(uint32_t *)off_105D7C;
  v27 = *(uint32_t *)off_105D74;
  v87 = *(uint32_t *)off_105D74;
  v89 = *(uint32_t *)off_105D74;
  v91 = *(uint32_t *)off_105D58;
  v93 = *(uint32_t *)off_105D58;
  v95 = *(uint32_t *)off_105D58;
  v97 = *(uint32_t *)off_105D58;
  v28 = *v21;
  v100 = *(uint32_t *)off_105D80;
  v102 = *(uint32_t *)off_105D60;
  v104 = *v22;
  v106 = *(uint32_t *)off_105D60;
  v116 = *v23;
  v115 = *(uint32_t *)off_105D94;
  v29 = *(uint32_t *)off_105D58;
  v30 = *(uint32_t *)off_105D58;
  v31 = *(uint32_t *)off_105D58;
  v32 = *(uint32_t *)off_105D98;
  *(uint32_t *)off_105D78 |= 0x40u;
  *v24 &= 0xFFFF8FFF;
  *(uint32_t *)v34 |= 0x800000u;
  v83 = (v26 >> 12) & 7;
  v85 = (v27 >> 23) & 1;
  v86 = (v27 >> 22) & 1;
  v88 = (v87 >> 20) & 1;
  v90 = (v89 >> 21) & 1;
  v92 = (v91 >> 17) & 1;
  v94 = HIWORD(v93) & 1;
  v96 = (v95 >> 15) & 1;
  v98 = (v97 >> 14) & 1;
  v99 = (v28 >> 18) & 1;
  v101 = (v100 >> 12) & 3;
  v103 = v102 & 3;
  v105 = (v104 >> 18) & 7;
  v107 = (v106 >> 2) & 1;
  v108 = (v29 >> 23) & 1;
  v109 = (v29 >> 22) & 1;
  v110 = (v30 >> 19) & 1;
  v111 = (v31 >> 18) & 1;
  v114 = (v32 >> 8) & 1;
  v33 = (v25 >> 6) & 1;
  *(uint32_t *)v34 |= 0x400000u;
  LOBYTE(v34) = 90;
  do
    v34 = (void *)(unsigned __int8)((uint8_t)v34 - 1);
  while ( v34 );
  v35 = off_105D74;
  *(uint32_t *)off_105D74 &= ~0x100000u;
  *(uint32_t *)v35 |= 0x200000u;
  LOBYTE(v35) = 60;
  do
    v35 = (void *)(unsigned __int8)((uint8_t)v35 - 1);
  while ( v35 );
  v36 = off_105D58;
  *(uint32_t *)off_105D74 |= 0x100000u;
  *(uint32_t *)v36 |= 0x20000u;
  *(uint32_t *)v36 |= 0x10000u;
  LOBYTE(v36) = 90;
  do
    v36 = (void *)(unsigned __int8)((uint8_t)v36 - 1);
  while ( v36 );
  v37 = off_1060AC;
  *(uint32_t *)off_1060AC &= ~0x40000u;
  *(uint32_t *)v37 |= 0x80000u;
  LOBYTE(v37) = 60;
  do
    v37 = (void *)(unsigned __int8)((uint8_t)v37 - 1);
  while ( v37 );
  v38 = off_1060AC;
  *(uint32_t *)off_1060AC |= 0x40000u;
  *(uint32_t *)v38 |= 0x8000u;
  *(uint32_t *)v38 |= 0x4000u;
  LOBYTE(v38) = 90;
  do
    v38 = (void *)(unsigned __int8)((uint8_t)v38 - 1);
  while ( v38 );
  v39 = (char *)off_1060B0;
  v40 = off_1060B4;
  v41 = (unsigned int *)off_1060B8;
  v42 = (unsigned int *)off_1060BC;
  *(uint32_t *)off_1060B0 |= 0x40000u;
  *v40 |= 0x3000u;
  *v41 = *v41 & 0xFFFFFFFC | 1;
  *v42 = *v42 & 0xFFE3FFFF | 0xC0000;
  *v41 |= 4u;
  *(uint32_t *)&v39[-28] |= 0x800000u;
  v40 -= 465770;
  *(uint32_t *)&v39[-28] |= 0x400000u;
  *v40 &= ~0x100u;
  sub_103B54();
  sub_12EB90(1, dword_1060C0);
  sub_1009DC(dword_1060C4 + 1264 * a5 + 16, 1264 * a5 + 1168 + dword_1060C4);
  *v40 &= ~0x200u;
  *v40 |= 0x200u;
  *v40 &= ~0x200u;
  if ( a5 )
  {
    v43 = a3 == 1;
    if ( a4 == 7 )
    {
      v65 = 8 * v43 + 5;
      v46 = v43 << 12;
      v47 = v65;
      v45 = 83886080;
    }
    else
    {
      v44 = 15 - a4 + 8 * v43;
      v45 = (15 - a4) << 24;
      v46 = v43 << 12;
      v47 = v44;
    }
  }
  else if ( a4 == 4 )
  {
    v46 = 0;
    v47 = 1;
    v45 = 0x1000000;
  }
  else if ( a4 == 7 )
  {
    v45 = 0;
    v46 = 0;
    v47 = 0;
  }
  else
  {
    v46 = 0;
    v47 = 15 - a4;
    v45 = (15 - a4) << 24;
  }
  v48 = (unsigned int *)off_1060C8;
  v49 = (unsigned int *)off_1060D0;
  v50 = (unsigned int *)off_1060B0;
  sub_12EB90(1, dword_1060CC);
  sub_103F14(a2, v47, a6);
  v51 = (unsigned int *)off_1060D8;
  sub_12EB90(1, dword_1060D4);
  *v48 = v45 | v46 | (a4 << 8) | 0x3F4080;
  sub_104080();
  v52 = (unsigned int *)off_1060E0;
  v53 = (unsigned int *)off_1060B4;
  v54 = (unsigned int *)off_1060BC;
  sub_12EB90(1, dword_1060DC);
  v55 = off_1060E4;
  *v49 &= ~0x200u;
  *v49 |= 0x200u;
  *v49 &= ~0x200u;
  *v55 |= 0x10000000u;
  sub_100644(6500);
  sub_1043C8();
  *v51 = *v51 & 0xFFBFFFFF | (v113 << 22);
  *v51 = *v51 & 0xFFDFFFFF | (v112 << 21);
  sub_104180();
  v56 = (unsigned int *)off_1060E8;
  v57 = (unsigned int *)off_1060F0;
  v58 = (unsigned int *)off_1060EC;
  v59 = (unsigned int *)off_1060AC;
  v60 = (unsigned int *)off_1060F4;
  *v52 = *v52 & 0xF8FFFFFF | (v67 << 24);
  result = (unsigned int *)off_1060B8;
  *v56 = *v56 & 0xFFFFFFBF | (v33 << 6);
  v62 = (unsigned int *)off_1060F8;
  *v57 = *v57 & 0xFFFF8FFF | (v83 << 12);
  *v58 = *v58 & 0xFF7FFFFF | (v85 << 23);
  *v58 = *v58 & 0xFFBFFFFF | (v86 << 22);
  *v58 = *v58 & 0xFFEFFFFF | (v88 << 20);
  *v58 = *v58 & 0xFFDFFFFF | (v90 << 21);
  *v59 = *v59 & 0xFFFBFFFF | (v111 << 18);
  *v59 = *v59 & 0xFFF7FFFF | (v110 << 19);
  *v59 = *v59 & 0xFFFDFFFF | (v92 << 17);
  *v59 = *v59 & 0xFFFEFFFF | (v94 << 16);
  *v59 = *v59 & 0xFFFF7FFF | (v96 << 15);
  *v59 = *v59 & 0xFFFFBFFF | (v98 << 14);
  *v50 = *v50 & 0xFFFBFFFF | (v99 << 18);
  *v53 = *v53 & 0xFFFFCFFF | (v101 << 12);
  *result = *result & 0xFFFFFFFC | v103;
  *v54 = *v54 & 0xFFE3FFFF | (v105 << 18);
  *result = *result & 0xFFFFFFFB | (4 * v107);
  *v59 = *v59 & 0xFF7FFFFF | (v108 << 23);
  *v59 = *v59 & 0xFFBFFFFF | (v109 << 22);
  *v62 = *v62 & 0xFFFFFFDF | (32 * v66);
  *v59 = *v59 & 0xFFDFFFFF | (v69 << 21);
  *v59 = *v59 & 0xFFEFFFFF | (v70 << 20);
  v63 = off_1062D0;
  *result = *result & 0xFFFFFF0F | (16 * v71);
  v56[20] = v56[20] & 0xFFFFFF7F | (v73 << 7);
  v56[20] = v56[20] & 0xFFFFFF8F | (16 * v75);
  v56[20] = v56[20] & 0xFFFFFBFF | (v77 << 10);
  v56[20] = v56[20] & 0xFFFFFCFF | (v79 << 8);
  *v62 = *v62 & 0xFFFFFFE3 | (4 * v81);
  *v51 &= 0xFFFE00FF;
  *v51 &= ~0x20000u;
  *v51 |= 0x40000u;
  *v60 = *v60 & 0x7FFFFFFF | v116 & 0x80000000;
  *v63 = v115;
  v57 -= 8848;
  *v49 = *v49 & 0xFFFFFEFF | (v114 << 8);
  *v57 |= 0x400u;
  *v57 &= ~0x400u;
  return result;
}

