// fwstruct annotate: 131c7c_sub_131C7C.c
// sub_131C7C @ 0x131c7c, size 1220 bytes
int __fastcall sub_131C7C(int a1, int a2, __int16 a3, __int16 a4)
{
  unsigned __int8 *v5; // r4
  int v6; // r0
  int v7; // r9
  int v8; // r2
  int v9; // r5
  int v10; // r8
  int v11; // r2
  char v12; // r1
  __int16 v13; // r0
  int v14; // r10
  int v15; // r8
  int v16; // r12
  int v17; // r1
  int v18; // r2
  char v19; // r5
  int v20; // r7
  _DWORD *v21; // lr
  int v22; // r5
  int v23; // r3
  char v24; // r1
  int v25; // r6
  unsigned int v26; // r0
  int v27; // r3
  char v28; // r1
  char v29; // r12
  _DWORD *v30; // r1
  int v31; // r1
  int v32; // r11
  unsigned __int8 *v33; // r7
  unsigned int v34; // r3
  int v36; // r3
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r1
  int v47; // r2
  int v48; // r3
  int v49; // r1
  int v50; // r2
  int v51; // r3
  int v52; // r0
  int v53; // r1
  int v54; // lr
  int v55; // r1
  int v56; // r2
  _DWORD *v57; // r3
  int v58; // r0
  int v59; // r0
  int v60; // r0
  int v61; // r0
  _BYTE *v62; // r0
  int *v63; // r8
  unsigned __int8 *v64; // r10
  _DWORD *v65; // r4
  _DWORD *v66; // r6
  int v67; // r11
  int v68; // r7
  int v69; // r0
  int v70; // r1
  _DWORD *v71; // r3
  int v72; // r2
  int v73; // [sp+10h] [bp-44h]
  int v74; // [sp+14h] [bp-40h]
  int v75; // [sp+18h] [bp-3Ch]
  int v76; // [sp+18h] [bp-3Ch]
  int v77; // [sp+18h] [bp-3Ch]
  unsigned __int8 *v78; // [sp+18h] [bp-3Ch]
  char v79; // [sp+1Ch] [bp-38h]
  char v80; // [sp+24h] [bp-30h] BYREF
  char v81; // [sp+25h] [bp-2Fh] BYREF
  __int16 v82; // [sp+26h] [bp-2Eh] BYREF
  int v83; // [sp+28h] [bp-2Ch] BYREF
  int v84; // [sp+2Ch] [bp-28h] BYREF
  _DWORD v85[4]; // [sp+30h] [bp-24h] BYREF
  __int16 v86; // [sp+40h] [bp-14h]
  int v87; // [sp+42h] [bp-12h]
  __int16 v88; // [sp+46h] [bp-Eh]
  char v89; // [sp+48h] [bp-Ch]
  char v90; // [sp+49h] [bp-Bh]
  char v91; // [sp+4Dh] [bp-7h]
  char v92; // [sp+4Eh] [bp-6h]

  v83 = 0;
  v84 = 0;
  v5 = (unsigned __int8 *)rf_bus_setup_n3a8(5128, a4, a3, 3u);
  v82 = 0;
  v80 = 0;
  v6 = phy_flag_clear_72();
  v7 = *(unsigned __int8 *)(a2 + 129);
  v8 = *(_DWORD *)(a2 + 120);
  v73 = v6;
  v9 = v8 & 2;
  v74 = 1320 * v7;
  if ( (v8 & 2) == 0 )
  {
    v12 = *(_BYTE *)(a2 + 129);
    goto LABEL_8;
  }
  v9 = v8 & 4;
  if ( (v8 & 4) != 0 )
  {
    v10 = a2 + 52;
    v36 = *(unsigned __int8 *)(dword_132050 + 1320 * v7 + 106);
    if ( v36 == 2 )
    {
      v59 = v74 + 100;
    }
    else
    {
      if ( v36 == 3 )
      {
        v61 = sdio_buffer_prepare_n_17c(a2);
        v8 = *(_DWORD *)(a2 + 120);
        v9 = v61;
        goto LABEL_4;
      }
      if ( *(_BYTE *)(dword_132050 + 1320 * v7 + 106) )
      {
        v9 = 0;
        goto LABEL_4;
      }
      v59 = v74 + 368;
    }
    v60 = sdio_buffer_prepare_n_16c_e1d8(v59 + dword_132050, *(_WORD *)(a2 + 124));
    v8 = *(_DWORD *)(a2 + 120);
    v9 = v60;
    goto LABEL_4;
  }
  v10 = 0;
LABEL_4:
  v11 = v8 & 0x20;
  if ( v11 )
    v11 = a2 + 64;
  sub_132874(a2 + 20, v10, v11, &v82, &v83, &v84, &v80);
  v12 = *(_BYTE *)(a2 + 129);
LABEL_8:
  v87 = *(_DWORD *)a2;
  v13 = *(_WORD *)(a2 + 4);
  v90 = v12;
  v85[3] = v9;
  v85[0] = 0;
  v91 = 0;
  v92 = 0;
  v88 = v13;
  v86 = v82;
  v85[2] = v83;
  v85[1] = v84;
  v89 = v80;
  v14 = rf_stream_dispatch((int)v85, v5, &v81);
  v5[1] = v14;
  if ( v14 )
    goto LABEL_24;
  v15 = *v5;
  v16 = *(_DWORD *)(a2 + 120);
  v17 = *(_DWORD *)(a2 + 10);
  v18 = *(_DWORD *)(a2 + 14);
  v19 = *(_BYTE *)(a2 + 18);
  v20 = dword_13204C + 696 * v15;
  *(_DWORD *)(v20 + 192) = *(_DWORD *)(a2 + 6);
  *(_DWORD *)(v20 + 196) = v17;
  *(_DWORD *)(v20 + 200) = v18;
  *(_BYTE *)(v20 + 204) = v19;
  if ( (v16 & 0x40) != 0 )
    *(_DWORD *)(v20 + 4) |= 0x40u;
  if ( (v16 & 1) != 0
    && (v21 = (_DWORD *)(dword_13204C + 696 * v15), v75 = v21[1], v21[1] = v75 | 1, (v16 & 2) != 0)
    && (v79 = *((_BYTE *)off_132060 + 374), v14 = v79 & 1, (v79 & 1) != 0) )
  {
    v37 = *(_DWORD *)(a2 + 24);
    v38 = *(_DWORD *)(a2 + 28);
    v39 = *(_DWORD *)(a2 + 32);
    v21[52] = *(_DWORD *)(a2 + 20);
    v21[53] = v37;
    v21[54] = v38;
    v21[55] = v39;
    v40 = *(_DWORD *)(a2 + 40);
    v41 = *(_DWORD *)(a2 + 44);
    v42 = *(_DWORD *)(a2 + 48);
    v21[56] = *(_DWORD *)(a2 + 36);
    v21[57] = v40;
    v21[58] = v41;
    v21[59] = v42;
    v21[1] = v75 | 3;
    if ( (v16 & 0x20) != 0 && (v79 & 4) != 0 )
    {
      v43 = *(_DWORD *)(a2 + 68);
      v44 = *(_DWORD *)(a2 + 72);
      v45 = *(_DWORD *)(a2 + 76);
      v21[63] = *(_DWORD *)(a2 + 64);
      v21[64] = v43;
      v21[65] = v44;
      v21[66] = v45;
      v46 = *(_DWORD *)(a2 + 84);
      v47 = *(_DWORD *)(a2 + 88);
      v48 = *(_DWORD *)(a2 + 92);
      v21[67] = *(_DWORD *)(a2 + 80);
      v21[68] = v46;
      v21[69] = v47;
      v21[70] = v48;
      v49 = *(_DWORD *)(a2 + 100);
      v50 = *(_DWORD *)(a2 + 104);
      v51 = *(_DWORD *)(a2 + 108);
      v21[71] = *(_DWORD *)(a2 + 96);
      v21[72] = v49;
      v21[73] = v50;
      v21[74] = v51;
      v52 = *(_DWORD *)(a2 + 112);
      v53 = *(_DWORD *)(a2 + 116);
      v21[1] = v75 | 0x23;
      v21[75] = v52;
      v21[76] = v53;
      if ( (v79 & 8) != 0 )
      {
        sub_11C968(v20);
        v16 = *(_DWORD *)(a2 + 120);
      }
    }
    if ( (v16 & 4) != 0 )
    {
      v54 = *(_DWORD *)(dword_13204C + 696 * v15 + 4);
      if ( (*((_BYTE *)off_132060 + 374) & 2) != 0 || (v54 & 0x20) != 0 )
      {
        v55 = *(_DWORD *)(a2 + 56);
        v56 = *(_DWORD *)(a2 + 60);
        v57 = (_DWORD *)(dword_13204C + 696 * v15);
        v57[60] = *(_DWORD *)(a2 + 52);
        v57[61] = v55;
        v57[62] = v56;
        v57[1] = v54 | 4;
      }
    }
    v22 = dword_132050;
    v58 = sub_13267C(v20, v74 + 248 + dword_132050);
    v16 = *(_DWORD *)(a2 + 120);
    v14 = v58;
  }
  else
  {
    v22 = dword_132050;
  }
  if ( (v16 & 8) != 0 )
    *(_DWORD *)(dword_13204C + 696 * v15 + 4) |= 8u;
  v23 = dword_13204C + 696 * v15;
  *(_BYTE *)(v23 + 310) = *(_BYTE *)(a2 + 126);
  v24 = *(_BYTE *)(a2 + 127);
  *(_WORD *)(v23 + 32) = *(_WORD *)(a2 + 124);
  *(_BYTE *)(v23 + 311) = v24;
  v76 = v23;
  sub_132F20(v20);
  if ( (*(_DWORD *)(a2 + 120) & 0x10) != 0 && *(char *)(a2 + 128) >= 0 )
  {
    idx_record_lookup_n_4d4(
      *(unsigned __int8 *)(v76 + 35),
      *(_BYTE *)(a2 + 128) & 3,
      *(unsigned __int8 *)(a2 + 128) >> 4);
    if ( !v14 )
      goto LABEL_19;
  }
  else if ( !v14 )
  {
    goto LABEL_19;
  }
  idx_record_lookup_n_4d4(*(unsigned __int8 *)(dword_13204C + 696 * v15 + 35), 255, 0);
LABEL_19:
  v25 = v22 + 1320 * v7;
  v26 = *(unsigned __int16 *)(v25 + 236);
  v27 = dword_13204C + 696 * v15;
  v28 = *(_DWORD *)(v25 + 1208) & 1;
  v29 = *(_BYTE *)(v27 + 350);
  *(_DWORD *)(v27 + 680) = v20;
  *(_BYTE *)(v27 + 52) = 2 - v28;
  v30 = off_132058;
  *(_DWORD *)(v27 + 676) = dword_132054;
  *(_WORD *)(v27 + 56) = __rev16(v26);
  *(_BYTE *)(v27 + 350) = v29 | 0x10;
  *(_BYTE *)(v27 + 688) = 1;
  v77 = v27;
  timestamp_update_4f60(696 * v15 + 672 + dword_13204C, dword_13205C + v30[4]);
  v5[2] = v73;
  if ( v73 )
  {
    v31 = *(unsigned __int8 *)(v25 + 234);
    *(_BYTE *)(v77 + 36) = v73;
    if ( !v31 )
    {
      v32 = (unsigned __int8)(*(_BYTE *)(v25 + 107) + 32);
      v33 = (unsigned __int8 *)(dword_13204C + 696 * v32);
      if ( v33[36] != 1 )
      {
        v34 = v33[35];
        v33[36] = 1;
        if ( v34 <= 0x1F )
        {
          v62 = (_BYTE *)rf_bus_setup_n3a8(73, 13, 0, 2u);
          *v62 = v32;
          v62[1] = 1;
          sub_12CBB4((int)v62);
          if ( v33[36] || v33[35] > 0x1Fu )
          {
            LOBYTE(v31) = *(_BYTE *)(v25 + 234);
          }
          else
          {
            v63 = (int *)off_132150;
            v78 = v5;
            v64 = v33;
            v65 = (_DWORD *)(dword_132140 - 664 + 8 * (87 * (__int16)v32 + 78));
            v66 = (_DWORD *)(v22 + 8 * (165 * v33[34] + 159));
            v67 = 696 * v32 + dword_132140;
            v68 = v22 + 1320 * v33[34];
            do
            {
              if ( *((_DWORD *)v64 + 146) )
              {
                if ( (__get_CPSR() & 1) == 0 )
                {
                  __disable_irq();
                  *(_DWORD *)off_132144 = 1;
                }
                v69 = dword_132148;
                ++*v63;
                sub_12ECB0(v69);
                sub_12D658(v65 - 10, v66 - 10);
                *(_QWORD *)(v68 + 1232) = *((_QWORD *)v64 + 73);
                bt_xtal_init_check(v65 - 10);
                v70 = *v63 - 1;
                if ( *v63 )
                {
                  v71 = off_132144;
                  *v63 = v70;
                  if ( !v70 )
                  {
                    if ( *v71 )
                      __enable_irq();
                  }
                }
              }
              v72 = *((_DWORD *)v64 + 156);
              v68 += 8;
              v64 += 8;
              if ( v72 )
              {
                sub_12ECB0(dword_13214C);
                sub_12D658(v66, v65);
                bt_xtal_init_check(v65);
              }
              v65 += 2;
              v66 += 2;
            }
            while ( (_DWORD *)v67 != v65 );
            v5 = v78;
            irq_nesting_or(512);
            LOBYTE(v31) = *(_BYTE *)(v22 + 1320 * v7 + 234);
          }
        }
      }
    }
    *(_BYTE *)(v22 + 1320 * v7 + 234) = v31 + 1;
    sub_12A7F4((unsigned __int8 *)(v74 + v22));
  }
LABEL_24:
  sub_12CBB4((int)v5);
  return 0;
}

