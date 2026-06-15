// sub_135D18 @ 0x135d18, size 1228 bytes
int __fastcall sub_135D18(int a1, int a2, char *a3)
{
  int v3; // r10
  int v4; // r8
  int v5; // r9
  int v6; // r4
  int v9; // r11
  int v10; // r0
  int v11; // r3
  int v12; // r2
  int v13; // r11
  int result; // r0
  int v15; // r4
  int v16; // r5
  int v17; // r0
  int v18; // r2
  int v19; // r3
  int v20; // r12
  char v21; // r2
  char v22; // r11
  int v23; // r3
  _QWORD *v24; // r5
  int v25; // r1
  int v26; // r11
  int v27; // r7
  _BYTE *v28; // r1
  int v29; // r2
  _DWORD *v30; // r1
  int v31; // r12
  int v32; // r7
  int v33; // r8
  int v34; // r2
  int v35; // r8
  int v36; // r1
  int v37; // r3
  unsigned int v38; // r2
  bool v39; // cc
  unsigned int v40; // r3
  unsigned int v41; // r2
  __int16 v42; // r0
  __int16 v43; // r1
  __int16 v44; // r2
  __int16 v45; // r3
  __int16 v46; // r2
  __int16 v47; // r3
  unsigned __int8 v48; // r3
  __int16 v49; // r0
  __int16 v50; // r1
  int v51; // r7
  unsigned __int64 v52; // kr00_8
  int v53; // [sp+Ch] [bp-40h]
  unsigned __int8 v54; // [sp+10h] [bp-3Ch]
  int v55; // [sp+10h] [bp-3Ch]
  char v57; // [sp+18h] [bp-34h]
  int v58; // [sp+1Ch] [bp-30h]
  int v59; // [sp+20h] [bp-2Ch]
  __int16 v60; // [sp+24h] [bp-28h]
  int v61; // [sp+28h] [bp-24h]
  int v62; // [sp+2Ch] [bp-20h]
  int v63; // [sp+30h] [bp-1Ch] BYREF
  int v64; // [sp+34h] [bp-18h]
  _DWORD v65[2]; // [sp+38h] [bp-14h] BYREF
  __int64 v66; // [sp+40h] [bp-Ch] BYREF

  v3 = dword_1360A0;
  v4 = dword_1360A4;
  v5 = *(unsigned __int8 *)(dword_1360A0 + 1320 * a1 + 116);
  v6 = dword_1360A4 + 696 * v5;
  v53 = *(_DWORD *)(v6 + 184);
  v9 = 7;
  while ( 1 )
  {
    v10 = sub_13C140(*(unsigned __int8 *)(v6 + 35), v9);
    v11 = (char)v9;
    v9 = (unsigned __int16)(v9 - 1);
    if ( v10 )
      break;
    if ( v9 == 0xFFFF )
    {
      v12 = -1;
      LOBYTE(v11) = -1;
      goto LABEL_5;
    }
  }
  v12 = v11;
LABEL_5:
  v54 = v11;
  v13 = v3 + 1320 * a1;
  v59 = 1320 * a1;
  v58 = *(unsigned __int8 *)(dword_136098 + v12);
  v57 = *a3;
  result = sub_119084(*(unsigned __int8 *)(v13 + 412) != 0, 512);
  v15 = result;
  if ( result )
  {
    message_dispatch_n_4a3(v3 + 1320 * a1, result);
    v16 = *(_DWORD *)(v15 + 72);
    v17 = *(_DWORD *)(v13 + 100);
    v18 = v4 + 696 * v5;
    v19 = v4 + 2 * (v54 + 348 * *(unsigned __int8 *)(v18 + 35) + 156);
    v20 = *(_DWORD *)(v18 + 38);
    v60 = *(_WORD *)(v19 + 4);
    LOWORD(v18) = *(_WORD *)(v18 + 42);
    *(_BYTE *)(v16 + 108) = -120;
    *(_BYTE *)(v16 + 109) = 1;
    *(_WORD *)(v19 + 4) = (v60 + 1) & 0xFFF;
    *(_WORD *)(v16 + 122) = *(_WORD *)(v13 + 104);
    *(_WORD *)(v16 + 116) = v18;
    *(_DWORD *)(v16 + 118) = v17;
    *(_BYTE *)(v16 + 110) = 0;
    *(_BYTE *)(v16 + 111) = 0;
    *(_DWORD *)(v16 + 112) = v20;
    sub_14380C(v16 + 124, a2, 6);
    v21 = *(_BYTE *)(v13 + 107);
    *(_WORD *)(v16 + 130) = 16 * v60;
    *(_BYTE *)(v15 + 28) = v21;
    *(_BYTE *)(v15 + 29) = *(_BYTE *)(v13 + 116);
    *(_WORD *)(v16 + 132) = v54;
    v22 = a3[1];
    v63 = 0;
    v61 = v16 + 108;
    v64 = 0;
    if ( (v22 & 0x40) != 0 )
    {
      v36 = *(_DWORD *)(*(_DWORD *)(v15 + 76) + 48);
      v37 = *(_DWORD *)(v36 + 12);
      *(_WORD *)(v16 + 108) |= 0x4000u;
      v38 = *(unsigned __int8 *)(v53 + 98);
      *(_DWORD *)(v36 + 12) = v37 & 0xFFFFFC00 | v38;
      switch ( *(_BYTE *)(v53 + 96) )
      {
        case 0:
        case 3:
          *(_BYTE *)(v15 + 51) = 4;
          *(_BYTE *)(v15 + 53) = 4;
          ++*(_QWORD *)(v53 + 72);
          sub_14380C(&v63, v53 + 72, 6);
          *(_WORD *)(v16 + 134) = v63;
          *(_WORD *)(v16 + 136) = HIWORD(v63) | (*(unsigned __int8 *)(v53 + 97) << 14);
          v62 = *(unsigned __int8 *)(v15 + 51);
          v23 = v62 + 26;
          break;
        case 1:
          *(_BYTE *)(v15 + 51) = 8;
          *(_BYTE *)(v15 + 53) = 12;
          ++*(_QWORD *)(v53 + 72);
          sub_14380C(&v63, v53 + 72, 6);
          v48 = v63;
          v49 = HIWORD(v63);
          v46 = v64;
          *(_WORD *)(v16 + 134) = v63 & 0x5F00 | 0x2000 | BYTE1(v63);
          v50 = *(unsigned __int8 *)(v53 + 97);
          *(_WORD *)(v16 + 138) = v49;
          v47 = v48 | (unsigned __int16)(v50 << 14);
          goto LABEL_31;
        case 2:
          *(_BYTE *)(v15 + 51) = 8;
          *(_BYTE *)(v15 + 53) = 8;
          ++*(_QWORD *)(v53 + 72);
          sub_14380C(&v63, v53 + 72, 6);
          *(_WORD *)(v16 + 134) = v63;
          v45 = *(unsigned __int8 *)(v53 + 97);
          v46 = v64;
          *(_WORD *)(v16 + 138) = HIWORD(v63);
          v47 = v45 << 14;
LABEL_31:
          *(_WORD *)(v16 + 136) = v47 | 0x2000;
          *(_WORD *)(v16 + 140) = v46;
          v62 = *(unsigned __int8 *)(v15 + 51);
          v23 = v62 + 26;
          break;
        case 4:
          v39 = v38 > 0xF;
          *(_BYTE *)(v15 + 51) = 18;
          *(_BYTE *)(v15 + 53) = 16;
          v40 = *(_DWORD *)(v53 + 72);
          v41 = *(_DWORD *)(v53 + 76);
          if ( v39 )
            v52 = __PAIR64__(v41, v40) + 2;
          else
            v52 = __PAIR64__(v41, v40) + 1;
          *(_QWORD *)(v53 + 72) = v52;
          sub_14380C(&v63, v53 + 72, 8);
          *(_WORD *)(v16 + 134) = *(unsigned __int8 *)(v53 + 97);
          v42 = HIWORD(v63);
          v43 = v64;
          v44 = HIWORD(v64);
          *(_WORD *)(v16 + 136) = v63;
          *(_WORD *)(v16 + 138) = v42;
          *(_WORD *)(v16 + 140) = v43;
          *(_WORD *)(v16 + 142) = v44;
          *(_WORD *)(v16 + 144) = 23606;
          *(_WORD *)(v16 + 146) = 23606;
          *(_WORD *)(v16 + 148) = 23606;
          *(_WORD *)(v16 + 150) = 23606;
          v62 = *(unsigned __int8 *)(v15 + 51);
          v23 = v62 + 26;
          break;
        default:
          if ( **(__int16 **)off_1361E8 < 0 )
            sub_12F694(dword_1361F0, dword_1361EC, 1636);
          v62 = *(unsigned __int8 *)(v15 + 51);
          v23 = v62 + 26;
          break;
      }
    }
    else
    {
      *(_BYTE *)(v15 + 51) = 0;
      *(_BYTE *)(v15 + 53) = 0;
      v62 = 0;
      v23 = 26;
    }
    v24 = off_13609C;
    v25 = *((_DWORD *)off_13609C + 1);
    v26 = v61 + v23;
    v65[0] = *(_DWORD *)off_13609C;
    v65[1] = v25;
    sub_14380C(v61 + v23, v65, 8);
    v66 = v24[1];
    sub_14380C(v26 + 8, &v66, 8);
    sub_14380C(v26 + 16, v59 + 100 + v3, 6);
    v27 = v3 + 1320 * a1;
    *(_WORD *)(v26 + 22) = *(_DWORD *)(v27 + 1228);
    *(_BYTE *)(v26 + 24) = *(_WORD *)(v27 + 1230);
    *(_BYTE *)(v26 + 25) = *(_BYTE *)(v27 + 1231);
    if ( (a3[1] & 0x40) != 0 )
    {
      if ( v57 >= 0 )
        v28 = a3 + 48;
      else
        v28 = a3 + 50;
    }
    else if ( v57 >= 0 )
    {
      v28 = a3 + 40;
    }
    else
    {
      v28 = a3 + 42;
    }
    sub_14380C(v26 + 26, v28, 10);
    v29 = *(unsigned __int8 *)(v4 + 696 * v5 + 35);
    v30 = *(_DWORD **)(v15 + 76);
    v31 = *(unsigned __int8 *)(v15 + 53);
    *(_DWORD *)(v15 + 92) = v15;
    v32 = v62 + v31 + 62;
    v33 = v4 + 696 * v29 + 12 * v54;
    v34 = v30[7] - 1 + v32;
    *(_DWORD *)(v15 + 88) = 0;
    v30[8] = v34;
    v30[9] = v62 + v31 + 66;
    v35 = *(unsigned __int8 *)(v33 + 453);
    if ( v35 != 33 && msg_get_value((v35 << 8) | 8) == 1 )
    {
      v55 = *(_DWORD *)(dword_1361E4 + 32 * v35 + 28);
      sub_13B9F0();
      rf_state_get_or_set(v55);
    }
    if ( (a3[1] & 0x40) != 0 && *(_BYTE *)(v53 + 96) == 1 )
    {
      sub_14380C(v15 + 12, a2, 6);
      sub_14380C(v15 + 18, v59 + 100 + v3, 6);
      v51 = v32 - (*(unsigned __int8 *)(v15 + 51) + *(unsigned __int8 *)(v15 + 53));
      *(_BYTE *)(v15 + 27) = 0;
      bt_flag_check_init(v15, v53 + 80, v26, v51 - 26);
    }
    return sub_1190B4(v15, v58);
  }
  return result;
}

