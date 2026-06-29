// fwstruct annotate: 112228_sub_112228.c
// sub_112228 @ 0x112228, size 1958 bytes
// Doc: rf_state_check_n178 [rf]: Check RF subsystem state (variant n178)
// rf_state_check_n178 [rf]: Check RF subsystem state (variant n178)
int __fastcall sub_112228(__int64 a1)
{
  int v1; // r4
  unsigned __int8 *v2; // r5
  void *v3; // r6
  unsigned __int8 *v4; // r3
  unsigned __int8 v5; // r2
  int v6; // r3
  _DWORD *v7; // r3
  _WORD *v8; // r4
  int (__fastcall *v9)(void *); // r1
  _BYTE *v10; // r8
  char v11; // r2
  int v12; // r7
  int v13; // r0
  int v14; // r3
  int v15; // r3
  _DWORD *v16; // r2
  int v17; // r3
  _DWORD *v18; // r3
  _DWORD *v19; // r3
  int v20; // r1
  _DWORD *v21; // r2
  _DWORD *v22; // r3
  int v23; // r3
  _DWORD *v24; // r2
  _DWORD *v25; // r3
  _DWORD *v26; // r2
  int v27; // r0
  _DWORD *v28; // r3
  int v29; // r3
  void *v30; // r3
  unsigned int v31; // r0
  unsigned int v32; // r3
  bool v33; // zf
  int v34; // r1
  int (__fastcall *v35)(_DWORD, _DWORD); // r3
  _BYTE *v36; // r3
  _WORD *v37; // r3
  void *v38; // r2
  int v39; // r4
  unsigned int v40; // r1
  _DWORD *v41; // r4
  int v42; // r0
  int *v43; // r8
  int v44; // r7
  int v45; // r3
  int v46; // r7
  _DWORD *v47; // r2
  _DWORD *v48; // r3
  __int16 v49; // r2
  int v50; // r6
  unsigned int v51; // r2
  unsigned int v52; // r1
  _DWORD *v53; // r2
  void (__fastcall *v54)(unsigned __int8 *); // r3
  _DWORD *v55; // r2
  int v56; // r0
  _DWORD *v57; // r3
  unsigned int v58; // r0
  int v59; // r0
  void *v60; // r2
  unsigned int v61; // r3
  __int16 v62; // r0

  v1 = HIDWORD(a1);
  if ( (_DWORD)a1 )
  {
    v2 = (unsigned __int8 *)rf_bus_reset_n_4b4;
    v14 = *(unsigned __int8 *)rf_bus_reset_n_4b4;
    if ( v14 == 2 )
    {
      v3 = rf_bus_reset_n_4b0;
      sub_10DC24(rf_state_check_n378);
      goto LABEL_7;
    }
    if ( (a1 & 0x100000000LL) == 0 )
      goto rf_state_check_n154;
    if ( v14 == 4 )
    {
      HIDWORD(a1) = *((unsigned __int16 *)rf_bus_reset_n_4b4 + 4);
      v49 = *((_WORD *)rf_bus_reset_n_4b4 + 5);
      LODWORD(a1) = (unsigned __int16)(WORD2(a1) - v49);
      if ( WORD2(a1) == v49 )
      {
        *(_BYTE *)rf_bus_reset_n_4b4 = 5;
        return a1;
      }
      if ( (_DWORD)a1 == 64 )
      {
        v50 = 1;
      }
      else
      {
        if ( (unsigned int)a1 >= 0x40 )
          LODWORD(a1) = 64;
        v50 = 0;
      }
      v51 = (unsigned __int16)(v49 + a1);
      *((_WORD *)rf_bus_reset_n_4b4 + 5) = v51;
      if ( HIDWORD(a1) < v51 )
      {
        LODWORD(a1) = sub_10DC24(rf_bus_reset_n_10_29d8);
        WORD2(a1) = *((_WORD *)v2 + 4);
        v51 = *((unsigned __int16 *)v2 + 5);
      }
      v52 = (unsigned __int16)(WORD2(a1) - v51);
      if ( v52 > 0x40 )
      {
        v52 = 64;
      }
      else if ( !v52 )
      {
        if ( !v50 )
        {
          v53 = rf_bus_reset_n_18;
          *v2 = 5;
          v53[516] |= 0x10u;
          return a1;
        }
        LODWORD(a1) = rf_bus_mark_n279(0, 0);
        goto rf_state_check_n154;
      }
      LODWORD(a1) = rf_bus_mark_n279(*((_DWORD *)v2 + 1) + v51, v52);
rf_state_check_n154:
      if ( (v1 & 0x20) == 0 )
        return a1;
rf_bus_setup_n430:
      if ( *v2 == 6 )
      {
        v26 = *(_DWORD **)rf_bus_reset_n_4b0;
        v27 = *(_DWORD *)off_112544;
        v28 = rf_state_check_n368;
        *v26 = phy_rf_init_n_4f4;
        v26[1] = v27;
        v28[709] = v26;
        v28[706] = v28[706];
        v28[704] |= 0x84000000;
        *v2 = 7;
        v28[517] |= 0x10u;
        LODWORD(a1) = rf_bus_init_n_4a8();
      }
      return a1;
    }
    if ( v14 != 7 )
      goto rf_state_check_n154;
    v22 = rf_state_check_n368;
    HIDWORD(a1) = rf_bus_reset_n_498_2550;
    LODWORD(a1) = 0;
    *(_BYTE *)rf_bus_reset_n_4b4 = 0;
    v22[517] &= ~0x10u;
    v22[516] &= ~0x10u;
    if ( *(_BYTE *)HIDWORD(a1) )
    {
      v22[513] = (16 * (unsigned __int8)*(_BYTE *)HIDWORD(a1)) & 0x70 | v22[513] & 0xFFFFFF8F;
      *(_BYTE *)HIDWORD(a1) = 0;
    }
  }
  else
  {
    if ( (BYTE4(a1) & 0x21) == 0x21 )
    {
      v16 = rf_state_check_n368;
      if ( (*((_DWORD *)rf_state_check_n368 + 708) & 0x7F) == 0x40 )
      {
        v17 = *((_DWORD *)rf_state_check_n368 + 708);
        LODWORD(a1) = v17 << 12;
        if ( (v17 & 0x80000) != 0 )
        {
          LODWORD(a1) = *(_DWORD *)off_112544;
          v18 = *(_DWORD **)rf_bus_reset_n_4b0;
          *v18 = phy_rf_init_n_4f4;
          v18[1] = a1;
          v16[709] = v18;
          v16[706] = v16[706];
          v16[704] |= 0x84000000;
          return a1;
        }
      }
    }
    if ( (a1 & 0x100000000LL) == 0 )
    {
      v2 = (unsigned __int8 *)rf_bus_reset_n_4b4;
      v15 = *(unsigned __int8 *)rf_bus_reset_n_4b4;
      if ( (a1 & 0x800000000LL) != 0 )
      {
        if ( v15 != 1 )
          return a1;
      }
      else if ( v15 != 2 )
      {
        goto rf_state_check_n154;
      }
LABEL_6:
      v3 = rf_bus_reset_n_4b0;
LABEL_7:
      if ( (v1 & 0x40) != 0 )
        v4 = (unsigned __int8 *)(*((_DWORD *)rf_state_check_n368 + 709) - 8);
      else
        v4 = *(unsigned __int8 **)(*(_DWORD *)v3 + 4);
      *((_DWORD *)v2 + 1) = 0;
      *((_DWORD *)v2 + 2) = 0;
      *v2 = 2;
      v2[12] = v2[12] & 0x7F | (*v4 >> 7 << 7);
      v5 = v2[12] & 0x9F | (32 * (((int)*v4 >> 5) & 3));
      v2[12] = v5;
      v2[12] = v5 & 0xE0 | *v4 & 0x1F;
      v2[13] = v4[1];
      *((_WORD *)v2 + 7) = v4[2] | (v4[3] << 8);
      *((_WORD *)v2 + 8) = v4[4] | (v4[5] << 8);
      v6 = v4[6] | (v4[7] << 8);
      *((_WORD *)v2 + 9) = v6;
      if ( !v6 && (v2[12] & 0x80u) != 0 )
        sub_10DC24(rf_bus_reset_n_154_2894);
      v7 = rf_state_check_n368;
      v8 = rf_state_check_2540;
      v9 = *((int (__fastcall **)(void *))rf_state_check_2540 + 3);
      *((_DWORD *)rf_state_check_n368 + 517) &= ~0x10u;
      v7[516] &= ~0x10u;
      if ( v9 && v9(rf_bus_reset_n_4b4) )
      {
rf_state_check_n29e:
        v23 = *v2;
        switch ( v23 )
        {
          case 3:
            if ( !*((_DWORD *)v2 + 1) )
              *((_DWORD *)v2 + 1) = rf_state_check_n384;
            goto rf_state_check_n2cc_24a0;
          case 4:
LABEL_87:
            rf_bus_mark_n279(*((_DWORD *)v2 + 1), *((unsigned __int16 *)v2 + 4));
            goto rf_state_check_n2cc_24a0;
          case 7:
message_dispatch_n_272:
            rf_bus_init_n_4a8();
            goto rf_state_check_n2cc_24a0;
        }
rf_state_check_484:
        *v2 = 0;
        rf_bus_write_1b64(0, 0x200000, 0);
        rf_bus_write2_1c1c(0, 0x200000, 0);
rf_state_check_n2cc_24a0:
        v24 = *(_DWORD **)v3;
        LODWORD(a1) = *(_DWORD *)off_112544;
        v25 = rf_state_check_n368;
        *v24 = phy_rf_init_n_4f4;
        v24[1] = a1;
LABEL_51:
        v25[709] = v24;
        v25[706] = v25[706];
        v25[704] |= 0x84000000;
        return a1;
      }
      v10 = unknown_n1;
      v11 = *(_BYTE *)unknown_n1;
      v12 = *(unsigned __int8 *)unknown_n1;
      if ( (v2[12] & 0x60) != 0 )
      {
rf_state_check_n342:
        if ( v12 == 4 && *v10 != 4 )
LABEL_56:
          rf_bus_scan_19dc();
        goto rf_state_check_484;
      }
      v13 = v2[13];
      switch ( v2[13] )
      {
        case 0u:
          if ( *(_BYTE *)unknown_n1 == 4 )
          {
            v29 = v2[12] & 0x1F;
            if ( v29 != 1 )
            {
              if ( v29 != 2 )
                goto LABEL_66;
              v58 = *((unsigned __int16 *)v2 + 8);
              v40 = v58 & 0xF;
              if ( v40 <= 5 )
              {
                v13 = (v58 >> 7) & 1;
LABEL_97:
                if ( sub_111D10(v13, v40) )
                {
                  v30 = off_112874;
                  *(_WORD *)off_112874 = 1;
                  goto rf_fault_dump_n_492;
                }
              }
            }
          }
          else
          {
            if ( *((_WORD *)v2 + 8) )
              goto rf_state_check_n342;
            v29 = v2[12] & 0x1F;
            if ( v29 != 1 )
            {
              if ( v29 != 2 )
              {
LABEL_66:
                if ( v29 )
                {
rf_state_check_n38c:
                  if ( v11 != 4 )
                    goto rf_state_check_484;
                  goto rf_bus_reset_n_484_2564;
                }
                v30 = off_112874;
                *(_WORD *)off_112874 = *(unsigned __int8 *)rf_bus_reset_n_178;
rf_fault_dump_n_492:
                *((_DWORD *)v2 + 1) = v30;
                *((_WORD *)v2 + 4) = 2;
                *v2 = 4;
LABEL_86:
                if ( v12 != 4 )
                  goto LABEL_87;
LABEL_128:
                if ( *v10 == 4 )
                  goto rf_state_check_n29e;
rf_state_check_46e:
                rf_bus_scan_19dc();
                goto rf_state_check_n29e;
              }
              v40 = v2[13];
              goto LABEL_97;
            }
          }
          v30 = rf_bus_reset_n_8_9e0;
          *(_WORD *)rf_bus_reset_n_8_9e0 = 0;
          goto rf_fault_dump_n_492;
        case 1u:
          if ( *(_BYTE *)unknown_n1 != 4 && *((_WORD *)v2 + 8) )
            goto rf_state_check_n342;
          if ( (v2[12] & 0x1F) != 2 || *((_WORD *)v2 + 7) )
            goto LABEL_79;
          sub_111D8C((int *)((*((unsigned __int16 *)v2 + 8) >> 7) & 1), *((_WORD *)v2 + 8) & 0xF);
          *v2 = 7;
          if ( v12 == 4 )
            goto rf_state_check_n290;
          goto message_dispatch_n_272;
        case 3u:
          if ( *(_BYTE *)unknown_n1 != 4 && *((_WORD *)v2 + 8) )
            goto rf_state_check_n342;
          if ( (v2[12] & 0x1F) != 0 )
          {
            if ( (v2[12] & 0x1F) != 2 || *((_WORD *)v2 + 7) )
            {
LABEL_79:
              *v2 = 7;
              if ( v11 == 4 )
              {
rf_bus_reset_n_484_2564:
                if ( *v10 != 4 )
                  goto LABEL_56;
              }
              goto rf_state_check_484;
            }
            sub_111D68((int *)((*((unsigned __int16 *)v2 + 8) >> 7) & 1), *((_WORD *)v2 + 8) & 0xF);
            *v2 = 7;
            if ( v12 != 4 )
              goto message_dispatch_n_272;
          }
          else
          {
            v59 = *((unsigned __int16 *)v2 + 7);
            if ( v59 != 2 )
            {
              v39 = v59 == 1;
              *v2 = 7;
LABEL_89:
              if ( v12 != 4 || *v10 == 4 )
              {
                if ( v39 )
                  goto rf_state_check_n29e;
              }
              else
              {
                rf_bus_scan_19dc();
                if ( v39 )
                  goto rf_state_check_n29e;
              }
              goto rf_state_check_484;
            }
            *(_BYTE *)rf_bus_reset_n_4 = HIBYTE(*((_WORD *)v2 + 8));
            *v2 = 7;
            if ( v11 != 4 )
              goto message_dispatch_n_272;
          }
rf_state_check_n290:
          if ( *v10 == 4 )
            goto message_dispatch_n_272;
          goto rf_state_check_46e;
        case 5u:
          v34 = *((unsigned __int16 *)v2 + 7);
          *((_DWORD *)off_112878 + 512) = (16 * v34) & 0x7F0 | *((_DWORD *)off_112878 + 512) & 0xFFFFF80F;
          *v2 = 7;
          if ( v34 )
            *v10 = 3;
          else
            *v10 = 2;
          goto LABEL_72;
        case 6u:
          v31 = *((unsigned __int16 *)v2 + 7);
          v32 = (v31 >> 8) - 1;
          v33 = v31 >> 8 == 0;
          switch ( v31 >> 8 )
          {
            case 1u:
              if ( v32 > 0x48 )
              {
                if ( v31 >> 8 == 97 )
                {
                  LODWORD(a1) = 10;
                }
                else
                {
                  v33 = v32 == 108;
LABEL_161:
                  if ( v33 )
                    LODWORD(a1) = 11;
                  else
                    LODWORD(a1) = 255;
                }
              }
              else if ( (v31 & 0x7E) != 0 )
              {
                switch ( v31 >> 8 )
                {
                  case 3u:
                    LODWORD(a1) = 0;
                    break;
                  case 5u:
                    goto LABEL_156;
                  case 0xCu:
                    LODWORD(a1) = 2;
                    break;
                  case 0xDu:
                    goto LABEL_166;
                  case 0x13u:
                    LODWORD(a1) = 5;
                    break;
                  case 0x17u:
                    LODWORD(a1) = 3;
                    break;
                  case 0x19u:
                    LODWORD(a1) = 6;
                    break;
                  default:
                    goto LABEL_158;
                }
              }
              else
              {
LABEL_158:
                LODWORD(a1) = 255;
              }
              return a1;
            case 2u:
LABEL_166:
              LODWORD(a1) = 4;
              return a1;
            case 3u:
              goto LABEL_161;
            case 4u:
            case 5u:
              v62 = v8[104];
              v60 = v3;
              if ( (unsigned int)v3 >= v32 )
                v60 = (void *)v32;
              *((_BYTE *)v8 + 308) = (_BYTE)v60;
              v61 = *(unsigned __int8 *)(v12 + 165);
              if ( v61 == 4 )
              {
                if ( v60 != (void *)4 )
                  JUMPOUT(0x132536);
              }
              else
              {
                if ( v61 >= (unsigned int)v60 )
                  v61 = (unsigned int)v60;
                if ( v61 != 4 )
                {
LABEL_149:
                  *((_BYTE *)v8 + 309) = v61;
                  *((_BYTE *)v8 + 312) = 0;
                  LODWORD(a1) = (v62 & 0xC) != 12;
                  return a1;
                }
              }
              LOBYTE(v61) = 3;
              goto LABEL_149;
            case 6u:
            case 0xFu:
LABEL_156:
              LODWORD(a1) = 1;
              return a1;
            case 7u:
            case 8u:
            case 9u:
            case 0xAu:
            case 0xBu:
            case 0xCu:
            case 0xDu:
            case 0xEu:
              JUMPOUT(0x132510);
            default:
              sub_10DC24(dword_112554);
              goto rf_state_check_n342;
          }
        case 8u:
          *((_DWORD *)v2 + 1) = dword_112884;
          *((_WORD *)v2 + 4) = 2;
          *v2 = 4;
          goto LABEL_86;
        case 9u:
          v39 = rf_state_check_21d4();
          goto LABEL_89;
        case 0xAu:
          if ( *(_BYTE *)unknown_n1 != 4 )
            goto rf_state_check_n342;
          v37 = off_11287C;
          *v2 = *(_BYTE *)unknown_n1;
          v38 = off_112880;
          *((_WORD *)v2 + 8) = *v37;
          *((_DWORD *)v2 + 1) = v38;
          *((_WORD *)v2 + 4) = 1;
          goto LABEL_86;
        case 0xBu:
          v35 = *((int (__fastcall **)(_DWORD, _DWORD))v8 + 6);
          if ( !v35 || !v35(*((unsigned __int16 *)v2 + 8), *((unsigned __int16 *)v2 + 7)) )
            goto rf_state_check_n342;
          v36 = off_112880;
          *(_WORD *)off_11287C = *((_WORD *)v2 + 8);
          *v36 = *((_WORD *)v2 + 7);
          *v2 = 7;
LABEL_72:
          if ( v12 != 4 )
            goto message_dispatch_n_272;
          goto LABEL_128;
        default:
          goto rf_state_check_n38c;
      }
    }
    if ( (a1 & 0x800000000LL) != 0 )
    {
      v2 = (unsigned __int8 *)rf_bus_reset_n_4b4;
      if ( *(_BYTE *)rf_bus_reset_n_4b4 )
      {
        sub_111D44((int *)1, 0);
        v3 = off_112890;
        goto LABEL_7;
      }
      goto LABEL_6;
    }
    v3 = rf_bus_reset_n_4b0;
    v2 = (unsigned __int8 *)rf_bus_reset_n_4b4;
    v19 = *(_DWORD **)rf_bus_reset_n_4b0;
    if ( (*(_BYTE *)(*(_DWORD *)rf_bus_reset_n_4b0 + 3) & 1) == 0 )
    {
      v20 = *(unsigned __int8 *)rf_bus_reset_n_4b4;
      switch ( v20 )
      {
        case 2:
          goto LABEL_7;
        case 3:
          v42 = *((unsigned __int16 *)rf_bus_reset_n_4b4 + 5);
          v43 = (int *)rf_bus_reset_n_160;
          v44 = 64 - *(unsigned __int16 *)v19;
          if ( v44 >= (unsigned __int16)(*((_WORD *)rf_bus_reset_n_4b4 + 4) - v42) )
            LOWORD(v44) = *((_WORD *)rf_bus_reset_n_4b4 + 4) - v42;
          sub_143770(v42 + *((_DWORD *)rf_bus_reset_n_4b4 + 1), *(_DWORD *)rf_bus_reset_n_160, (unsigned __int16)v44);
          v45 = *((unsigned __int16 *)v2 + 4);
          v46 = (unsigned __int16)(v44 + *((_WORD *)v2 + 5));
          *((_WORD *)v2 + 5) = v46;
          if ( v45 == v46 )
          {
            v54 = *((void (__fastcall **)(unsigned __int8 *))off_1129D4 + 4);
            if ( v54 )
              v54(v2);
            LODWORD(a1) = v1 << 26;
            if ( (v1 & 0x20) == 0 )
            {
              *v2 = 6;
              return a1;
            }
            v55 = *(_DWORD **)v3;
            v56 = *v43;
            v57 = rf_bus_reset_n_18;
            *v55 = rf_bus_reset_n_c;
            v55[1] = v56;
            v57[709] = v55;
            v57[706] = v57[706];
            v57[704] |= 0x84000000;
            *v2 = 7;
            v57[517] |= 0x10u;
            LODWORD(a1) = rf_bus_init_n_4a8();
            goto rf_bus_setup_n430;
          }
          v47 = *(_DWORD **)v3;
          LODWORD(a1) = *v43;
          v48 = off_112878;
          *v47 = dword_11288C;
          v47[1] = a1;
          v48[709] = v47;
          v48[706] = v48[706];
          v48[704] |= 0x84000000;
          break;
        case 5:
          v25 = off_112878;
          *(_BYTE *)rf_bus_reset_n_4b4 = 0;
          v24 = *(_DWORD **)v3;
          v41 = rf_bus_reset_n_160;
          LODWORD(a1) = dword_11288C;
          v25[517] &= ~0x10u;
          v25[516] &= ~0x10u;
          HIDWORD(a1) = *v41;
          *(_QWORD *)v24 = a1;
          goto LABEL_51;
        default:
          v21 = rf_state_check_n368;
          LODWORD(a1) = *(_DWORD *)off_112544;
          *v19 = phy_rf_init_n_4f4;
          v19[1] = a1;
          v21[709] = v19;
          v21[706] = v21[706];
          v21[704] |= 0x84000000;
          break;
      }
      goto rf_state_check_n154;
    }
    if ( *(_BYTE *)rf_bus_reset_n_4b4 )
      LODWORD(a1) = sub_111D44((int *)1, 0);
    *v2 = 1;
  }
  return a1;
}

