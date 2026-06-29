// sub_1010D4 @ 0x1010d4, size 1740 bytes
unsigned int  sub_1010D4(unsigned int a1)
{
  uint32_t *v1; // r1
  uint32_t *v2; // r2
  uint32_t *v3; // r3
  uint32_t *v4; // r5
  uint32_t *v5; // r6
  uint32_t *v6; // r1
  unsigned int *v7; // r4
  uint32_t *v8; // r2
  int v9; // r5
  uint32_t *v11; // r0
  unsigned int *v12; // r4
  uint32_t *v13; // r1
  unsigned int *v14; // r3
  unsigned int v15; // r3
  unsigned int **v16; // r4
  int *v17; // r0
  int v18; // r3
  int *v19; // r11
  unsigned int *v20; // r2
  int v21; // r1
  unsigned int v22; // r12
  int *v23; // r10
  int v24; // r8
  unsigned int v25; // r9
  int v26; // lr
  int *v27; // r3
  unsigned int v28; // r4
  unsigned int v29; // r4
  uint32_t *v30; // r3
  unsigned int *v31; // r2
  int v32; // r1
  int v33; // r2
  int v34; // r0
  int v35; // r7
  int v36; // r1
  int v37; // r1
  unsigned int *v38; // r4
  int v39; // r5
  uint8_t *v40; // r1
  uint32_t *v41; // r1
  unsigned int v42; // r3
  uint32_t *v43; // r0
  unsigned int *v44; // r1
  bool v45; // zf
  unsigned int *v46; // r2
  unsigned int v47; // r3
  unsigned int v48; // r3
  uint32_t *v49; // r2
  int v50; // r1
  int v51; // r4
  int v52; // r0
  int v53; // r1
  uint32_t *v54; // r3
  int v55; // r4
  int v56; // r0
  int v57; // r1
  int v58; // r2
  int v59; // r5
  uint8_t *v60; // r4
  int v61; // r0
  uint32_t *v62; // r2
  unsigned int result; // r0
  uint32_t *v64; // r2
  uint32_t *v65; // r3
  int v66; // r1
  int v67; // r4
  int v68; // r0
  int v69; // r1
  int v70; // r4
  int v71; // r0
  int v72; // r1
  int v73; // r2
  int *v74; // r0
  int v75; // r3
  int *v76; // r2
  int v77; // r1
  int v78; // r1
  int v79; // r4
  int v80; // r0
  int v81; // r1
  int v82; // r4
  int v83; // r0
  int v84; // r1
  int v85; // r2
  uint32_t *v86; // [sp+4h] [bp-8h]

  v1 = off_101378;
  v2 = off_10137C;
  v3 = off_101380;
  v4 = off_101384;
  v5 = off_101388;
  *(uint32_t *)off_101378 &= ~0x400u;
  *v1 &= ~0x800u;
  *v4 |= 4u;
  v6 = off_10138C;
  *v2 |= 0x80000u;
  *v2 &= ~0x100000u;
  v7 = (unsigned int *)off_101390;
  *v3 |= 0x400u;
  *v3 &= ~0x100u;
  *v3 |= 0x80u;
  v8 = off_101394;
  *v5 |= 0x8000u;
  *v6 |= 1u;
  *v6 &= ~2u;
  *(uint32_t *)((char *)v4 + 0xFFFFFFA4) |= 0x40u;
  *v7 = *v7 & 0xFFC01FFF | 0x32000;
  *v8 &= ~0x8000u;
  *v8 |= 0x4000u;
  v9 = *(uint8_t *)off_101398 & 0xC0;
  if ( v9 == 192 )
    *(uint32_t *)((char *)v8 + 0xFFFFFFFC) = *(uint32_t *)((char *)v8 + 0xFFFFFFFC) & 0xFFF9FFFF | 0x40000;
  else
    *(uint32_t *)off_10139C = *(uint32_t *)off_10139C & 0xFFF9FFFF | 0x20000;
  v11 = off_1013A0;
  v12 = (unsigned int *)off_1013A4;
  v13 = off_1013A8;
  v14 = (unsigned int *)off_1013AC;
  *(uint32_t *)off_1013A0 = *(uint32_t *)off_1013A0 & 0xFFFFE3FF | 0x800;
  *v12 = *v12 & 0xFC7FFFFF | 0x1000000;
  *v13 &= 0xFFFFC7FF;
  *v14 = *v14 & 0xFFFFF83F | 0x400;
  v11[4] = v11[4] & 0xFFFFE3FF | 0x1000;
  v12[4] |= 0xC00u;
  v11[4] = v11[4] & 0xFFFFFF87 | 0x48;
  v13 -= 1904;
  *v14 &= ~1u;
  *v13 |= 8u;
  *v13 |= 4u;
  *v14 &= ~2u;
  v12[6] &= ~0x20000u;
  *v14 |= 0x20u;
  v15 = (unsigned __int16)(a1 - 5000);
  if ( v9 == 192 )
  {
    if ( v15 <= 0xFA )
    {
      v74 = (int *)off_101700;
      v75 = dword_10173C;
      v76 = (int *)off_101708;
      v19 = (int *)off_101770;
      v77 = dword_101740;
      v86 = off_101700;
    }
    else if ( a1 > 0x14C8 )
    {
      if ( a1 <= 0x15C2 )
      {
        v74 = (int *)off_101700;
        v75 = dword_101764;
        v76 = (int *)off_101708;
        v19 = (int *)off_101770;
        v77 = dword_101768;
        v86 = off_101700;
      }
      else if ( a1 > 0x1612 )
      {
        v74 = (int *)off_1017A0;
        if ( a1 > 0x1662 )
        {
          v75 = dword_1017B4;
          v76 = (int *)off_1017A8;
          v19 = (int *)off_1017BC;
          v77 = dword_1017B8;
        }
        else
        {
          v75 = dword_1017A4;
          v76 = (int *)off_1017A8;
          v19 = (int *)off_1017BC;
          v77 = dword_1017AC;
        }
        v86 = off_1017A0;
      }
      else
      {
        v74 = (int *)off_101700;
        v75 = dword_101750;
        v76 = (int *)off_101708;
        v19 = (int *)off_101770;
        v77 = dword_101754;
        v86 = off_101700;
      }
    }
    else
    {
      v74 = (int *)off_101700;
      v75 = dword_101704;
      v76 = (int *)off_101708;
      v19 = (int *)off_101770;
      v77 = dword_10170C;
      v86 = off_101700;
    }
    v26 = 0;
    *v76 = v75;
    *v74 = v75;
    v20 = (unsigned int *)v75;
    v23 = (int *)v75;
    *v19 = v77;
    v25 = 0;
    v24 = 0;
    v22 = 0;
    goto LABEL_7;
  }
  if ( v15 > 0xFA )
  {
    if ( a1 > 0x14C8 )
    {
      if ( a1 > 0x15C2 )
      {
        if ( a1 <= 0x1612 )
        {
          v18 = dword_10175C;
          v16 = (unsigned int **)off_101700;
          v19 = (int *)off_101770;
          v20 = (unsigned int *)dword_101758;
          v37 = dword_10176C;
          v86 = off_101700;
          *(uint32_t *)off_101708 = dword_10175C;
          v22 = 0;
          v24 = 1610612736;
        }
        else
        {
          v16 = (unsigned int **)off_101700;
          v17 = (int *)off_101708;
          v19 = (int *)off_101770;
          v20 = (unsigned int *)dword_101758;
          v86 = off_101700;
          v18 = dword_10175C;
          if ( a1 > 0x1662 )
          {
            v21 = dword_1017B0;
            goto LABEL_6;
          }
          v37 = dword_101760;
          *(uint32_t *)off_101708 = dword_10175C;
          v22 = 0;
          v24 = 0x40000000;
        }
      }
      else
      {
        v18 = dword_1013D0;
        v16 = (unsigned int **)off_1013B0;
        v19 = (int *)off_1013DC;
        v20 = (unsigned int *)dword_1013D4;
        v37 = dword_1013D8;
        v86 = off_1013B0;
        *(uint32_t *)off_1013B4 = dword_1013D0;
        v22 = 0x80000000;
        v24 = 1610612736;
      }
      v23 = (int *)v18;
      *v19 = v37;
      *v16 = v20;
      v25 = v22;
      v26 = v24;
      goto LABEL_7;
    }
    v16 = (unsigned int **)off_101700;
    v17 = (int *)off_101708;
    v18 = dword_101744;
    v19 = (int *)off_101770;
    v20 = (unsigned int *)dword_101748;
    v21 = dword_10174C;
    v86 = off_101700;
  }
  else
  {
    v16 = (unsigned int **)off_1013B0;
    v17 = (int *)off_1013B4;
    v18 = dword_1013B8;
    v19 = (int *)off_1013DC;
    v20 = (unsigned int *)dword_1013BC;
    v21 = dword_1013C0;
    v86 = off_1013B0;
  }
LABEL_6:
  v22 = 0;
  *v17 = v18;
  v23 = (int *)v18;
  *v19 = v21;
  *v16 = v20;
  v24 = 0;
  v25 = 0;
  v26 = 0;
LABEL_7:
  v27 = v23;
  do
  {
    if ( v9 != 192 && (unsigned __int16)(a1 - 5000) > 0x140u )
    {
      v28 = v27[1] & 0xFFFFFFFE;
      *v27 = *v27 & 0x1FFFFFFF | v26 | v25;
      v27[1] = v28;
      v29 = v20[1] & 0xFFFFFFFE;
      *v20 = *v20 & 0x1FFFFFFF | v24 | v22;
      v20[1] = v29;
    }
    v27 += 3;
    v20 += 3;
  }
  while ( v27 != v23 + 48 );
  sub_102D4C(1, 0, 16, v23);
  sub_102D4C(1, 16, 16, *v19);
  sub_102D4C(1, 32, 16, *v86);
  sub_10090C(1, a1);
  v30 = off_1013C4;
  v31 = (unsigned int *)off_1013C8;
  *(uint32_t *)off_1013C4 |= 8u;
  *v30 |= 4u;
  *v31 = *v31 & 0xFFFC7FFF | 0x10000;
  *v31 = *v31 & 0xFFFF8FFF | 0x3000;
  if ( a1 > 0x1666 )
  {
    v35 = 10;
    v34 = 5;
  }
  else if ( a1 > 0x1616 )
  {
    v35 = 8;
    v34 = 4;
  }
  else if ( a1 > 0x15C6 )
  {
    v35 = 6;
    v34 = 3;
  }
  else
  {
    if ( a1 <= 0x1571 )
    {
      v32 = *(unsigned __int8 *)off_101398;
      v33 = v32 & 0xC0;
      v34 = a1 > 0x1486;
      if ( a1 <= 0x1486 )
        v35 = 0;
      else
        v35 = 2;
      if ( v33 == 192 )
        goto LABEL_20;
      goto LABEL_27;
    }
    v35 = 4;
    v34 = 2;
  }
  v32 = *(unsigned __int8 *)off_101674;
  v33 = v32 & 0xC0;
  if ( v33 == 192 )
  {
LABEL_20:
    v36 = dword_1013CC;
    goto LABEL_31;
  }
LABEL_27:
  if ( v32 == 3 )
  {
    v36 = dword_101738;
  }
  else if ( v32 == 7 )
  {
    v36 = dword_101678;
  }
  else
  {
    v36 = 0;
  }
LABEL_31:
  v38 = (unsigned int *)off_101680;
  *(uint32_t *)off_10167C = *(uint32_t *)off_10167C & 0xFFFFFF00 | *(unsigned __int8 *)(v36 + v35);
  v39 = *(unsigned __int8 *)(v36 + v35 + 1);
  v40 = off_101684;
  *v38 = *v38 & 0xFFFFFF00 | v39;
  if ( !v40[1] )
  {
    v41 = off_101688;
    v38[1918] &= 0xFFFFFC7F;
    *v41 &= ~0x8000u;
  }
  v42 = *(uint32_t *)off_10168C & 0xFF00FFFF;
  if ( v34 <= 1 )
    v42 |= 0x1F0000u;
  v43 = off_101690;
  *(uint32_t *)off_10168C = v42;
  v44 = (unsigned int *)off_101694;
  *v43 &= ~0x4000u;
  *v44 = *v44 & 0xFFF8FFFF | 0x20000;
  v45 = v33 == 192;
  v46 = (unsigned int *)off_101698;
  *v44 = *v44 & 0xFFFFFFF0 | 8;
  v47 = *v46;
  if ( v45 )
    v48 = v47 | 0xE0000;
  else
    v48 = v47 & 0xFFF1FFFF;
  if ( !v45 )
    v48 |= 0x60000u;
  *v46 = v48;
  if ( a1 <= 0x15E4 )
  {
    v64 = off_10169C;
    v65 = off_1016B4;
    if ( a1 <= 0x14D6 )
    {
      v78 = dword_101714;
      v79 = dword_101718;
      *(uint32_t *)off_10169C = dword_101710;
      v64[1] = v78;
      v80 = dword_10171C;
      v81 = dword_101720;
      v64[2] = v79;
      v64[3] = v80;
      v64[4] = v81;
      v82 = dword_101724;
      v83 = dword_101728;
      v84 = dword_10172C;
      v85 = dword_101730;
      *v65 = dword_101734;
      v65[1] = v82;
      v65[2] = v83;
      v65[3] = v84;
      v65[4] = v85;
      v59 = 0;
    }
    else
    {
      v66 = dword_1016DC;
      v67 = dword_1016E0;
      *(uint32_t *)off_10169C = dword_1016D8;
      v64[1] = v66;
      v68 = dword_1016E4;
      v69 = dword_1016E8;
      v64[2] = v67;
      v64[3] = v68;
      v64[4] = v69;
      v70 = dword_1016EC;
      v71 = dword_1016F0;
      v72 = dword_1016F4;
      v73 = dword_1016F8;
      *v65 = dword_1016FC;
      v65[1] = v70;
      v65[2] = v71;
      v65[3] = v72;
      v65[4] = v73;
      v59 = 1;
    }
  }
  else
  {
    v49 = off_10169C;
    v50 = dword_1016A4;
    v51 = dword_1016A8;
    *(uint32_t *)off_10169C = dword_1016A0;
    v49[1] = v50;
    v52 = dword_1016AC;
    v53 = dword_1016B0;
    v54 = off_1016B4;
    v49[2] = v51;
    v49[3] = v52;
    v49[4] = v53;
    v55 = dword_1016B8;
    v56 = dword_1016BC;
    v57 = dword_1016C0;
    v58 = dword_1016C4;
    *v54 = dword_1016C8;
    v54[1] = v55;
    v54[2] = v56;
    v54[3] = v57;
    v54[4] = v58;
    v59 = 2;
  }
  v60 = off_1016CC;
  if ( *(unsigned __int8 *)off_1016CC != v59 )
  {
    v61 = sub_102DE0();
    sub_102E04(v61);
  }
  v62 = off_1016D0;
  *v60 = v59;
  while ( !*v62 )
    ;
  result = *(uint32_t *)off_1016D4 & 1;
  if ( !result )
  {
    if ( a1 - 5270 > 0x32 && a1 - 5550 > 0x64 )
      result = sub_100C3C(0);
    else
      result = sub_100D18();
  }
  *(uint32_t *)off_1016D0 = 1;
  return result;
}

