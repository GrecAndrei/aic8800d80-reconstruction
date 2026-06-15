// v23 annotated: sub_1120E8 @ 0x1120e8
// Original: 1120e8_sub_1120E8.c
// Primary struct: <unclustered>
//
// sub_1120E8 @ 0x1120e8, size 1958 bytes
int __fastcall sub_1120E8(__int64 a1)
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
    v2 = (unsigned __int8 *)off_1123F4;
    v14 = *(unsigned __int8 *)off_1123F4;
    if ( v14 == 2 )
    {
      v3 = off_1123F8;
      sub_10DAE4(dword_11240C);
      goto LABEL_7;
    }
    if ( (a1 & 0x100000000LL) == 0 )
      goto LABEL_18;
    if ( v14 == 4 )
    {
      HIDWORD(a1) = *((unsigned __int16 *)off_1123F4 + 4);
      v49 = *((_WORD *)off_1123F4 + 5);
      LODWORD(a1) = (unsigned __int16)(WORD2(a1) - v49);
      if ( WORD2(a1) == v49 )
      {
        *(_BYTE *)off_1123F4 = 5;
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
      *((_WORD *)off_1123F4 + 5) = v51;
      if ( HIDWORD(a1) < v51 )
      {
        LODWORD(a1) = sub_10DAE4(dword_112898);
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
          v53 = off_112890;
          *v2 = 5;
          v53[516] |= 0x10u;
          return a1;
        }
        LODWORD(a1) = sub_1119BC(0, 0);
        goto LABEL_18;
      }
      LODWORD(a1) = sub_1119BC(*((_DWORD *)v2 + 1) + v51, v52);
LABEL_18:
      if ( (v1 & 0x20) == 0 )
        return a1;
LABEL_19:
      if ( *v2 == 6 )
      {
        v26 = *(_DWORD **)off_1123F8;
        v27 = *(_DWORD *)off_112404;
        v28 = off_1123FC;
        *v26 = dword_112408;
        v26[1] = v27;
        v28[709] = v26;
        v28[706] = v28[706];
        v28[704] |= 0x84000000;
        *v2 = 7;
        v28[517] |= 0x10u;
        LODWORD(a1) = sub_1117D0();
      }
      return a1;
    }
    if ( v14 != 7 )
      goto LABEL_18;
    v22 = off_1123FC;
    HIDWORD(a1) = off_112410;
    LODWORD(a1) = 0;
    *(_BYTE *)off_1123F4 = 0;
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
      v16 = off_1123FC;
      if ( (*((_DWORD *)off_1123FC + 708) & 0x7F) == 0x40 )
      {
        v17 = *((_DWORD *)off_1123FC + 708);
        LODWORD(a1) = v17 << 12;
        if ( (v17 & 0x80000) != 0 )
        {
          LODWORD(a1) = *(_DWORD *)off_112404;
          v18 = *(_DWORD **)off_1123F8;
          *v18 = dword_112408;
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
      v2 = (unsigned __int8 *)off_1123F4;
      v15 = *(unsigned __int8 *)off_1123F4;
      if ( (a1 & 0x800000000LL) != 0 )
      {
        if ( v15 != 1 )
          return a1;
      }
      else if ( v15 != 2 )
      {
        goto LABEL_18;
      }
LABEL_6:
      v3 = off_1123F8;
LABEL_7:
      if ( (v1 & 0x40) != 0 )
        v4 = (unsigned __int8 *)(*((_DWORD *)off_1123FC + 709) - 8);
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
        sub_10DAE4(dword_112754);
      v7 = off_1123FC;
      v8 = off_112400;
      v9 = *((int (__fastcall **)(void *))off_112400 + 3);
      *((_DWORD *)off_1123FC + 517) &= ~0x10u;
      v7[516] &= ~0x10u;
      if ( v9 && v9(off_1123F4) )
      {
LABEL_46:
        v23 = *v2;
        switch ( v23 )
        {
          case 3:
            if ( !*((_DWORD *)v2 + 1) )
              *((_DWORD *)v2 + 1) = dword_112418;
            goto LABEL_50;
          case 4:
LABEL_87:
            sub_1119BC(*((_DWORD *)v2 + 1), *((unsigned __int16 *)v2 + 4));
            goto LABEL_50;
          case 7:
LABEL_73:
            sub_1117D0();
            goto LABEL_50;
        }
LABEL_49:
        *v2 = 0;
        sub_111A24(0, 0x200000, 0);
        sub_111ADC(0, 0x200000, 0);
LABEL_50:
        v24 = *(_DWORD **)v3;
        LODWORD(a1) = *(_DWORD *)off_112404;
        v25 = off_1123FC;
        *v24 = dword_112408;
        v24[1] = a1;
LABEL_51:
        v25[709] = v24;
        v25[706] = v25[706];
        v25[704] |= 0x84000000;
        return a1;
      }
      v10 = off_11241C;
      v11 = *(_BYTE *)off_11241C;
      v12 = *(unsigned __int8 *)off_11241C;
      if ( (v2[12] & 0x60) != 0 )
      {
LABEL_54:
        if ( v12 == 4 && *v10 != 4 )
LABEL_56:
          sub_11189C();
        goto LABEL_49;
      }
      v13 = v2[13];
      switch ( v2[13] )
      {
        case 0u:
          if ( *(_BYTE *)off_11241C == 4 )
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
                if ( sub_111BD0(v13, v40) )
                {
                  v30 = off_112734;
                  *(_WORD *)off_112734 = 1;
                  goto LABEL_68;
                }
              }
            }
          }
          else
          {
            if ( *((_WORD *)v2 + 8) )
              goto LABEL_54;
            v29 = v2[12] & 0x1F;
            if ( v29 != 1 )
            {
              if ( v29 != 2 )
              {
LABEL_66:
                if ( v29 )
                {
LABEL_59:
                  if ( v11 != 4 )
                    goto LABEL_49;
                  goto LABEL_60;
                }
                v30 = off_112734;
                *(_WORD *)off_112734 = *(unsigned __int8 *)off_112730;
LABEL_68:
                *((_DWORD *)v2 + 1) = v30;
                *((_WORD *)v2 + 4) = 2;
                *v2 = 4;
LABEL_86:
                if ( v12 != 4 )
                  goto LABEL_87;
LABEL_128:
                if ( *v10 == 4 )
                  goto LABEL_46;
LABEL_45:
                sub_11189C();
                goto LABEL_46;
              }
              v40 = v2[13];
              goto LABEL_97;
            }
          }
          v30 = off_1128A0;
          *(_WORD *)off_1128A0 = 0;
          goto LABEL_68;
        case 1u:
          if ( *(_BYTE *)off_11241C != 4 && *((_WORD *)v2 + 8) )
            goto LABEL_54;
          if ( (v2[12] & 0x1F) != 2 || *((_WORD *)v2 + 7) )
            goto LABEL_79;
          sub_111C4C((int *)((*((unsigned __int16 *)v2 + 8) >> 7) & 1), *((_WORD *)v2 + 8) & 0xF);
          *v2 = 7;
          if ( v12 == 4 )
            goto LABEL_44;
          goto LABEL_73;
        case 3u:
          if ( *(_BYTE *)off_11241C != 4 && *((_WORD *)v2 + 8) )
            goto LABEL_54;
          if ( (v2[12] & 0x1F) != 0 )
          {
            if ( (v2[12] & 0x1F) != 2 || *((_WORD *)v2 + 7) )
            {
LABEL_79:
              *v2 = 7;
              if ( v11 == 4 )
              {
LABEL_60:
                if ( *v10 != 4 )
                  goto LABEL_56;
              }
              goto LABEL_49;
            }
            sub_111C28((int *)((*((unsigned __int16 *)v2 + 8) >> 7) & 1), *((_WORD *)v2 + 8) & 0xF);
            *v2 = 7;
            if ( v12 != 4 )
              goto LABEL_73;
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
                  goto LABEL_46;
              }
              else
              {
                sub_11189C();
                if ( v39 )
                  goto LABEL_46;
              }
              goto LABEL_49;
            }
            *(_BYTE *)off_1128A4 = HIBYTE(*((_WORD *)v2 + 8));
            *v2 = 7;
            if ( v11 != 4 )
              goto LABEL_73;
          }
LABEL_44:
          if ( *v10 == 4 )
            goto LABEL_73;
          goto LABEL_45;
        case 5u:
          v34 = *((unsigned __int16 *)v2 + 7);
          *((_DWORD *)off_112738 + 512) = (16 * v34) & 0x7F0 | *((_DWORD *)off_112738 + 512) & 0xFFFFF80F;
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
                  JUMPOUT(0x1323F6);
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
              JUMPOUT(0x1323D0);
            default:
              sub_10DAE4(dword_112414);
              goto LABEL_54;
          }
        case 8u:
          *((_DWORD *)v2 + 1) = dword_112744;
          *((_WORD *)v2 + 4) = 2;
          *v2 = 4;
          goto LABEL_86;
        case 9u:
          v39 = sub_112094();
          goto LABEL_89;
        case 0xAu:
          if ( *(_BYTE *)off_11241C != 4 )
            goto LABEL_54;
          v37 = off_11273C;
          *v2 = *(_BYTE *)off_11241C;
          v38 = off_112740;
          *((_WORD *)v2 + 8) = *v37;
          *((_DWORD *)v2 + 1) = v38;
          *((_WORD *)v2 + 4) = 1;
          goto LABEL_86;
        case 0xBu:
          v35 = *((int (__fastcall **)(_DWORD, _DWORD))v8 + 6);
          if ( !v35 || !v35(*((unsigned __int16 *)v2 + 8), *((unsigned __int16 *)v2 + 7)) )
            goto LABEL_54;
          v36 = off_112740;
          *(_WORD *)off_11273C = *((_WORD *)v2 + 8);
          *v36 = *((_WORD *)v2 + 7);
          *v2 = 7;
LABEL_72:
          if ( v12 != 4 )
            goto LABEL_73;
          goto LABEL_128;
        default:
          goto LABEL_59;
      }
    }
    if ( (a1 & 0x800000000LL) != 0 )
    {
      v2 = (unsigned __int8 *)off_1123F4;
      if ( *(_BYTE *)off_1123F4 )
      {
        sub_111C04((int *)1, 0);
        v3 = off_112750;
        goto LABEL_7;
      }
      goto LABEL_6;
    }
    v3 = off_1123F8;
    v2 = (unsigned __int8 *)off_1123F4;
    v19 = *(_DWORD **)off_1123F8;
    if ( (*(_BYTE *)(*(_DWORD *)off_1123F8 + 3) & 1) == 0 )
    {
      v20 = *(unsigned __int8 *)off_1123F4;
      switch ( v20 )
      {
        case 2:
          goto LABEL_7;
        case 3:
          v42 = *((unsigned __int16 *)off_1123F4 + 5);
          v43 = (int *)off_112748;
          v44 = 64 - *(unsigned __int16 *)v19;
          if ( v44 >= (unsigned __int16)(*((_WORD *)off_1123F4 + 4) - v42) )
            LOWORD(v44) = *((_WORD *)off_1123F4 + 4) - v42;
          sub_143630(v42 + *((_DWORD *)off_1123F4 + 1), *(_DWORD *)off_112748, (unsigned __int16)v44);
          v45 = *((unsigned __int16 *)v2 + 4);
          v46 = (unsigned __int16)(v44 + *((_WORD *)v2 + 5));
          *((_WORD *)v2 + 5) = v46;
          if ( v45 == v46 )
          {
            v54 = *((void (__fastcall **)(unsigned __int8 *))off_112894 + 4);
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
            v57 = off_112890;
            *v55 = dword_11289C;
            v55[1] = v56;
            v57[709] = v55;
            v57[706] = v57[706];
            v57[704] |= 0x84000000;
            *v2 = 7;
            v57[517] |= 0x10u;
            LODWORD(a1) = sub_1117D0();
            goto LABEL_19;
          }
          v47 = *(_DWORD **)v3;
          LODWORD(a1) = *v43;
          v48 = off_112738;
          *v47 = dword_11274C;
          v47[1] = a1;
          v48[709] = v47;
          v48[706] = v48[706];
          v48[704] |= 0x84000000;
          break;
        case 5:
          v25 = off_112738;
          *(_BYTE *)off_1123F4 = 0;
          v24 = *(_DWORD **)v3;
          v41 = off_112748;
          LODWORD(a1) = dword_11274C;
          v25[517] &= ~0x10u;
          v25[516] &= ~0x10u;
          HIDWORD(a1) = *v41;
          *(_QWORD *)v24 = a1;
          goto LABEL_51;
        default:
          v21 = off_1123FC;
          LODWORD(a1) = *(_DWORD *)off_112404;
          *v19 = dword_112408;
          v19[1] = a1;
          v21[709] = v19;
          v21[706] = v21[706];
          v21[704] |= 0x84000000;
          break;
      }
      goto LABEL_18;
    }
    if ( *(_BYTE *)off_1123F4 )
      LODWORD(a1) = sub_111C04((int *)1, 0);
    *v2 = 1;
  }
  return a1;
}

