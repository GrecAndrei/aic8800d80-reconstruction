// sub_109D40 @ 0x109d40, size 1512 bytes
int  sub_109D40(
        int *a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        uint64_t *a11)
{
  int *v11; // r10
  int v13; // r1
  int v14; // r2
  float v15; // s20
  int v17; // r7
  unsigned int *v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r11
  unsigned int v22; // r0
  int v23; // r2
  char *v24; // r7
  int v25; // r3
  int i; // r4
  int v27; // r1
  int v28; // r3
  int v29; // r2
  int v30; // r2
  int j; // r3
  float v32; // s16
  int v33; // r1
  int v34; // r3
  int v35; // r2
  int v36; // r2
  int v37; // r3
  int v38; // r3
  float v39; // s21
  float v40; // s22
  float v41; // s17
  int v42; // r8
  float v43; // s23
  float v44; // s16
  int v45; // r3
  int v46; // s25
  int v47; // r3
  int v48; // r3
  int v49; // r3
  int v50; // r3
  float v51; // s15
  uint64_t v52; // r0
  int v53; // r3
  bool v54; // cc
  unsigned int *v55; // r2
  int v56; // r1
  int v57; // r3
  int v58; // r3
  int v59; // r3
  int v60; // r1
  int k; // r3
  int result; // r0
  uint32_t *v63; // r3
  int v64; // r3
  int v65; // r3
  int v66; // r3
  int v67; // r3
  int v68; // r3
  int v69; // r3
  int v70; // r3
  int v71; // r3
  int v72; // r3
  int v73; // r3
  int v74; // r3
  int v75; // [sp+20h] [bp-20h]
  int v76; // [sp+24h] [bp-1Ch]
  int v77; // [sp+2Ch] [bp-14h]
  int v78; // [sp+30h] [bp-10h]
  int *v79; // [sp+34h] [bp-Ch]
  int *v80; // [sp+38h] [bp-8h]
  unsigned int *v81; // [sp+3Ch] [bp-4h]
  uint32_t v82[3]; // [sp+40h] [bp+0h] BYREF
  int v83[5]; // [sp+4Ch] [bp+Ch] BYREF
  float v84; // [sp+24Ch] [bp+20Ch]
  float v85; // [sp+250h] [bp+210h]
  float v86; // [sp+254h] [bp+214h]
  float v87; // [sp+258h] [bp+218h]
  char v88; // [sp+25Ch] [bp+21Ch] BYREF
  int v89; // [sp+2BCh] [bp+27Ch]
  float v90; // [sp+2CCh] [bp+28Ch]
  uint8_t v91[1204]; // [sp+2D0h] [bp+290h] BYREF

  v11 = (int *)off_10A0BC;
  v13 = *(uint32_t *)(dword_10A070 + 4);
  v14 = *(uint32_t *)(dword_10A070 + 8);
  v82[0] = *(uint32_t *)dword_10A070;
  v82[1] = v13;
  v82[2] = v14;
  v15 = flt_10A074;
  v79 = v82;
  *(uint32_t *)(a5 + 4 * a4) = 1;
  v81 = (unsigned int *)(a2 - 4);
  v77 = 1;
  v80 = (int *)(a5 + 4 * a4);
  v17 = 0;
  while ( 2 )
  {
    v19 = v81 + 1;
    v20 = v81[1];
    ++v81;
    v21 = (unsigned __int8)v17;
    if ( !v20 )
    {
      sub_11F74C(1, dword_10A354, v17, 0);
      sub_11F74C(1, dword_10A358, v17, v64);
      goto LABEL_28;
    }
    if ( !a4 && v17 == 1 )
    {
      sub_11F74C(1, dword_10A35C, v19, v20);
      goto LABEL_29;
    }
    sub_11F74C(1, dword_10A078, v17, v20);
    v22 = *v81;
    v89 = 0;
    sub_105494(v22, (int)v83, a4, (int)v81);
    sub_11F74C(1, dword_10A07C, v17, v89);
    v75 = *v79;
    if ( v89 <= 0 )
      goto LABEL_27;
    v78 = v17;
    v76 = 0;
    v24 = &v88;
    do
    {
      v25 = *a1;
      for ( i = *((uint32_t *)v24 + 16); !*a1; v25 = *a1 )
        sub_100560(1);
      sub_11F74C(1, dword_10A080, v23, v25);
      sub_105578((int)v83, (int)v91, v21, i, a4, 0);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      sub_109BF8(i, v83, (int)v91, v21, 0, a4, a6, a7, a9, a10, a11);
      v27 = dword_10A084;
      *v11 |= 0x8000u;
      v28 = *v11 | 0x2000;
      *v11 = v28;
      sub_11F74C(1, v27, v29, v28);
      for ( j = a1[1]; !j; j = a1[1] )
        sub_100560(1);
      v32 = flt_10A08C;
      sub_11F74C(1, dword_10A088, v30, j);
      sub_105578((int)v83, (int)v91, v21, i, a4, 1);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      sub_109BF8(i, v83, (int)v91, v21, 1, a4, a6, 0, a9, a10, a11);
      v33 = dword_10A084;
      *v11 |= 0x8000u;
      v34 = *v11 | 0x2000;
      *v11 = v34;
      sub_11F74C(1, v33, v35, v34);
      sub_11F74C(1, dword_10A090, v36, v37);
      sub_11F74C(1, dword_10A094, (int)(float)(v84 * v32), (int)(float)(v85 * v32));
      sub_11F74C(1, dword_10A098, (int)(float)(v86 * v32), (int)(float)(v87 * v32));
      v39 = v84 / v85;
      v40 = v86 / v87;
      if ( i == 11 )
      {
        v41 = 3.0;
        v43 = 3.0;
        v42 = 30000;
      }
      else
      {
        v38 = i - 12;
        if ( (unsigned int)(i - 12) <= 1 )
        {
          v43 = flt_10A344;
          v42 = 11000;
          v41 = 3.0;
        }
        else if ( i == 14 )
        {
          v43 = flt_10A348;
          v42 = 13000;
          v41 = 3.0;
        }
        else if ( i <= 7 )
        {
          v41 = v15;
          v43 = v15;
          v42 = 10010;
        }
        else
        {
          v41 = flt_10A09C;
          v42 = 11000;
          v43 = flt_10A09C;
        }
      }
      v44 = flt_10A0A0;
      sub_11F74C(1, dword_10A0A4, v42, v38);
      sub_11F74C(1, dword_10A0A8, (int)(float)(v41 * v44), v45);
      v46 = (int)(float)(v39 * v44);
      sub_11F74C(1, dword_10A0AC, v46, v47);
      sub_11F74C(1, dword_10A0B0, (int)(float)(v40 * v44), v48);
      sub_11F74C(1, dword_10A0B4, (int)(float)(v86 * v44), v49);
      if ( v43 >= v39 )
      {
        v51 = v90;
        if ( v90 < 2.0 )
          goto LABEL_19;
        v56 = dword_10A328;
        *(uint32_t *)v24 = 0;
        *((uint32_t *)v24 + 8) = 0;
        sub_11F74C(1, v56, v42, v50);
        sub_11F74C(1, dword_10A32C, (int)(float)(v41 * v44), v57);
        sub_11F74C(1, dword_10A330, (int)(float)(v39 * v44), v58);
        sub_11F74C(1, dword_10A334, (int)(float)(v40 * v44), v59);
        sub_11F74C(1, dword_10A338, v78, i);
        if ( i <= 10 && v78 == 1 )
        {
          v77 = 0;
          sub_11F504(dword_10A33C, i);
          *(uint32_t *)v24 = 1;
          *((uint32_t *)v24 + 8) = 1;
        }
      }
      else
      {
        if ( v41 < v40 )
        {
          v51 = v90;
LABEL_19:
          *(uint32_t *)v24 = 1;
          *((uint32_t *)v24 + 8) = 1;
          if ( i <= 8
            && v41 > v40
            && (v52 = sub_127570(LODWORD(v51)), sub_127B40(v52, HIDWORD(v52), dword_10A068, dword_10A06C))
            && v78 == 1 )
          {
            sub_11F74C(1, dword_10A328, v42, 1);
            sub_11F74C(1, dword_10A32C, (int)(float)(v41 * v44), v65);
            sub_11F74C(1, dword_10A330, v46, v66);
            sub_11F74C(1, dword_10A334, (int)(float)(v40 * v44), v67);
            sub_11F74C(1, dword_10A364, (int)(float)(v90 * flt_10A360), v68);
            sub_11F74C(1, dword_10A368, i, v69);
            v77 = 0;
          }
          else
          {
            sub_11F74C(1, dword_10A0B8, v78, i);
            v77 = 1;
          }
          goto LABEL_24;
        }
        v51 = v90;
        if ( v90 < 2.0 )
          goto LABEL_19;
        v60 = dword_10A340;
        *(uint32_t *)v24 = 1;
        *((uint32_t *)v24 + 8) = 0;
        sub_11F74C(1, v60, v78, i);
        if ( i <= 8 && v78 == 1 )
        {
          if ( v90 > 2.0 )
          {
            sub_11F74C(1, dword_10A328, v42, 1);
            sub_11F74C(1, dword_10A32C, (int)(float)(v41 * v44), v70);
            sub_11F74C(1, dword_10A330, v46, v71);
            sub_11F74C(1, dword_10A334, (int)(float)(v40 * v44), v72);
            sub_11F74C(1, dword_10A364, (int)(float)(v90 * v44), v73);
            sub_11F74C(1, dword_10A368, i, v74);
            v77 = 0;
            sub_11F74C(1, dword_10A33C, i, 0);
          }
          else
          {
            v77 = 1;
          }
        }
        else
        {
          v77 = 1;
        }
      }
LABEL_24:
      v23 = v89;
      v75 &= *(uint32_t *)v24;
      v53 = *v80 & v77;
      v54 = v89 <= ++v76;
      *v79 = v75;
      v24 += 4;
      *v80 = v53;
    }
    while ( !v54 );
    v17 = v78;
LABEL_27:
    v55 = v81;
    *v81 = *v81 & 0xFFFEFFFF | (v75 << 16);
LABEL_28:
    if ( v21 != 2 )
    {
LABEL_29:
      ++v17;
      ++v79;
      continue;
    }
    break;
  }
  for ( k = a1[2]; !k; k = a1[2] )
    sub_100560(1);
  result = sub_11F74C(1, dword_10A34C, v55, k);
  v63 = off_10A350;
  *(uint32_t *)off_10A350 &= ~0x200u;
  *v63 |= 0x200u;
  *v63 &= ~0x200u;
  return result;
}

