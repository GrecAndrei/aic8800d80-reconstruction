// fwstruct annotate: 12e11c_sub_12E11C.c
// sub_12E11C @ 0x12e11c, size 2264 bytes
// Doc: sdio_buffer_prepare_evt [mmio]: Prepare SDIO buffer for event path
// sdio_buffer_prepare_evt [mmio]: Prepare SDIO buffer for event path
int __fastcall sub_12E11C(_BYTE *a1, int a2, unsigned int a3, _BYTE *a4, int *a5)
{
  unsigned int v5; // r12
  int v8; // r2
  unsigned __int8 *v9; // r5
  _BYTE *v10; // r7
  int v11; // r4
  int v12; // r6
  _BYTE *v13; // r9
  int v14; // r10
  int v15; // r0
  int v16; // t1
  int v18; // t1
  unsigned int v19; // t1
  int v20; // t1
  unsigned int v21; // r1
  int v22; // t1
  _BYTE *v23; // r2
  int v24; // r0
  int v25; // r3
  _BYTE *v26; // r0
  unsigned int v27; // r3
  unsigned int v28; // t1
  int v29; // r10
  _BYTE *v30; // lr
  char v31; // r0
  bool v32; // cc
  _BYTE *v33; // r2
  int v34; // r0
  char v35; // r0
  _BYTE *v36; // t1
  unsigned __int8 *v37; // t1
  int v38; // r2
  int v39; // lr
  int v40; // r3
  char v41; // r1
  char v42; // r3
  int v43; // r1
  int v44; // r2
  unsigned int v45; // r10
  char *v46; // r2
  bool v47; // zf
  int v48; // t1
  char v49; // r9
  unsigned __int8 *v50; // t1
  int v51; // lr
  int v52; // r3
  char v53; // r2
  unsigned __int8 *v54; // r1
  _BYTE *v55; // r3
  int v56; // t1
  char v57; // r2
  int v58; // r1
  int v59; // r3
  int v60; // r2
  int v61; // r1
  int v62; // t1
  int v63; // r2
  char v64; // r3
  int v65; // r3
  _BYTE *v66; // r1
  int v67; // r0
  int v68; // t1
  int v70; // t1
  int v71; // r3
  int v72; // lr
  int v73; // r3
  int v74; // r0
  int v75; // [sp+0h] [bp-54h]
  int v76; // [sp+4h] [bp-50h]
  unsigned int v77; // [sp+8h] [bp-4Ch]
  int v78; // [sp+Ch] [bp-48h]
  _DWORD v79[12]; // [sp+10h] [bp-44h] BYREF
  _BYTE v80[4]; // [sp+50h] [bp-4h] BYREF

  v9 = a4 + 1;
  v8 = (unsigned __int8)*a4;
  v78 = a2;
  v10 = a1;
  if ( !a1 )
  {
    v11 = (unsigned __int8)*a4;
    if ( *a4 )
    {
      v78 = 0;
sdio_buffer_prepare_n22:
      v11 = 0;
      v75 = 0;
      v76 = 0;
      v12 = v78;
      v77 = 0;
      v13 = nullptr;
      v14 = 0;
      while ( 2 )
      {
        switch ( v8 )
        {
          case ' ':
          case '+':
          case '-':
            a2 = 5;
            break;
          case '%':
            v59 = 1;
            goto LABEL_125;
          case '*':
            v59 = 4;
LABEL_125:
            a2 = dword_12E9F4;
            v14 = *(unsigned __int8 *)(dword_12E9F4 + 8 * v14 + v59);
            switch ( v14 )
            {
              case 0:
              case 1:
              case 2:
              case 3:
              case 4:
              case 5:
              case 6:
              case 7:
                goto LABEL_164;
              default:
                goto LABEL_162;
            }
          case '.':
            a2 = 2;
            break;
          case '0':
            v14 = *(unsigned __int8 *)(dword_12E490 + 8 * v14 + 3);
            switch ( v14 )
            {
              case 0:
              case 1:
              case 2:
              case 3:
              case 4:
              case 5:
              case 6:
              case 7:
                goto LABEL_164;
              default:
                goto LABEL_162;
            }
          case 'A':
          case 'M':
          case 'X':
          case 'a':
          case 'b':
          case 'c':
          case 'd':
          case 'i':
          case 'm':
          case 'p':
          case 's':
          case 'u':
          case 'x':
            a2 = 7;
            break;
          case 'h':
          case 'l':
            a2 = 6;
            break;
          default:
            if ( (unsigned int)(v8 - 49) <= 8 )
            {
              v14 = *(unsigned __int8 *)(dword_12E490 + 8 * v14 + 4);
              a2 = (int)jpt_12E3EC;
              switch ( v14 )
              {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
LABEL_164:
                  *(_BYTE *)(2 * a2) = 0;
                  MEMORY[0] = 0;
                  JUMPOUT(0x14E51C);
                default:
                  a2 = dword_12E490;
LABEL_162:
                  if ( **(__int16 **)off_12EA00 < 0 )
                    sub_12F46C(dword_12E9FC, dword_12E9F8, 594);
                  break;
              }
              goto sdio_buffer_prepare_n1d6_e2f2;
            }
            a2 = 0;
            break;
        }
        v15 = dword_12E490;
        v14 = *(unsigned __int8 *)(dword_12E490 + 8 * v14 + a2);
        switch ( v14 )
        {
          case 0:
            if ( v12 )
            {
              if ( a3 <= v11 )
              {
                *v10++ = v8;
                --v12;
              }
            }
            ++v11;
            v14 = 0;
            goto sdio_buffer_prepare_n1d6_e2f2;
          case 1:
            v75 = 0;
            v77 = 0;
            v76 = -1;
            v14 = 1;
            goto sdio_buffer_prepare_n1d6_e2f2;
          case 2:
            switch ( v8 )
            {
              case ' ':
                v75 |= 0x10u;
                v14 = 2;
                break;
              case '+':
                v75 |= 8u;
                v14 = 2;
                break;
              case '-':
                v75 |= 0x20u;
                v14 = 2;
                break;
              case '0':
                v75 |= 0x40u;
                v14 = 2;
                break;
              default:
                if ( **(__int16 **)off_12E494 < 0 )
                  sub_12F46C(dword_12E9FC, dword_12E9F8, 283);
                v14 = 2;
                break;
            }
            goto sdio_buffer_prepare_n1d6_e2f2;
          case 3:
            if ( v8 == 42 )
            {
              v19 = *a5++;
              v77 = v19;
            }
            else
            {
              v77 = v8 - 48 + 10 * v77;
            }
            v14 = 3;
            goto sdio_buffer_prepare_n1d6_e2f2;
          case 4:
            v76 = 0;
            v14 = 4;
            goto sdio_buffer_prepare_n1d6_e2f2;
          case 5:
            if ( v8 == 42 )
            {
              v18 = *a5++;
              v76 = v18;
            }
            else
            {
              v76 = v8 - 48 + 10 * v76;
            }
            v14 = 5;
            goto sdio_buffer_prepare_n1d6_e2f2;
          case 6:
            if ( v8 == 104 )
            {
              v75 |= 1u;
              v14 = 6;
            }
            else if ( v8 == 108 )
            {
              v75 |= 2u;
              v14 = 6;
            }
            else
            {
              if ( **(__int16 **)off_12E494 < 0 )
                sub_12F46C(dword_12E9FC, dword_12E9F8, 334);
              v14 = 6;
            }
            goto sdio_buffer_prepare_n1d6_e2f2;
          case 7:
            switch ( v8 )
            {
              case 'A':
              case 'a':
                v37 = (unsigned __int8 *)*a5++;
                v38 = v77;
                v39 = dword_12EA08;
                v5 = (unsigned int)(v37 + 1);
                v40 = *v37;
                if ( v77 )
                {
                  v41 = *(_BYTE *)(dword_12EA08 + (v40 >> 4));
                  v42 = *(_BYTE *)(dword_12EA08 + (v40 & 0xF));
                  LOBYTE(v79[0]) = v41;
                  if ( v77 >= 0x15 )
                    v38 = 21;
                  v43 = 3 * v38;
                  v44 = v38 - 1;
                  BYTE1(v79[0]) = v42;
                  v25 = v43 - 1;
                  a2 = 1 - v43;
                  if ( !v44 )
                  {
LABEL_107:
                    if ( (v75 & 0x40) != 0 )
                    {
                      v77 = 0;
                      v23 = v79;
                      goto LABEL_59;
                    }
                    v77 = v75 & 0x40;
                    v23 = v79;
                    if ( (v75 & 0x20) != 0 )
                      goto LABEL_58;
                    if ( v25 )
                      goto LABEL_59;
                    goto LABEL_94;
                  }
                }
                else
                {
                  v63 = v40 >> 4;
                  v64 = *(_BYTE *)(dword_12EA08 + (v40 & 0xF));
                  LOBYTE(v79[0]) = *(_BYTE *)(dword_12EA08 + v63);
                  BYTE1(v79[0]) = v64;
                  a2 = -47;
                  v25 = 47;
                  v44 = 15;
                }
                v45 = v5 + v44;
                v46 = (char *)v79 + 3;
                do
                {
                  v47 = (v5 & 3) == 0;
                  v48 = *(unsigned __int8 *)v5++;
                  *v46 = *(_BYTE *)(v39 + (v48 >> 4));
                  v46[1] = *(_BYTE *)(v39 + (v48 & 0xF));
                  if ( v47 )
                    v49 = 58;
                  else
                    v49 = 46;
                  *(v46 - 1) = v49;
                  v46 += 3;
                }
                while ( v45 != v5 );
                goto LABEL_107;
              case 'M':
              case 'm':
                v50 = (unsigned __int8 *)*a5++;
                v51 = dword_12EA08;
                v5 = (unsigned int)(v50 + 6);
                v52 = *v50;
                v53 = *(_BYTE *)(dword_12EA08 + (v52 >> 4));
                BYTE1(v79[0]) = *(_BYTE *)(dword_12EA08 + (v52 & 0xF));
                LOBYTE(v79[0]) = v53;
                v54 = v50 + 1;
                v55 = v79;
                do
                {
                  v56 = *v54++;
                  v55[2] = 58;
                  v57 = *(_BYTE *)(v51 + (v56 & 0xF));
                  v55[3] = *(_BYTE *)(v51 + (v56 >> 4));
                  v55[4] = v57;
                  v55 += 3;
                }
                while ( (unsigned __int8 *)v5 != v54 );
                a2 = v77 - 17;
                v23 = v79;
                v24 = v75 & 0x40;
                v25 = 17;
                goto LABEL_56;
              case 'X':
              case 'b':
              case 'd':
              case 'p':
              case 'u':
              case 'x':
                if ( (v75 & 2) != 0 || (v15 = v75 << 31, (v75 & 1) == 0) )
                {
                  v60 = v8 - 88;
                  v62 = *a5++;
                  v61 = v62;
                  switch ( v60 )
                  {
                    case 0:
                      goto LABEL_173;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 11:
                    case 13:
                    case 14:
                    case 15:
                    case 16:
                    case 17:
                    case 18:
                    case 19:
                    case 20:
                    case 21:
                    case 22:
                    case 23:
                    case 25:
                    case 26:
                    case 27:
                    case 28:
                    case 30:
                    case 31:
                      v11 *= 16;
                      v61 = 2048;
                      v15 = 0;
                      goto LABEL_170;
                    case 10:
                      v61 = v12 << 8;
                      v15 = 0;
                      v12 <<= 22;
LABEL_173:
                      *(_DWORD *)(v61 + v15) = v12;
                      v79[0] = v11;
                      goto LABEL_174;
                    case 12:
                      v11 = (int)jpt_12E7D6 >> 2;
                      v60 = 0;
                      goto LABEL_167;
                    case 24:
LABEL_170:
                      v74 = v15 << 16;
                      *(_DWORD *)(2 * v74) = v74;
                      *(_DWORD *)(v61 + v74) = v61 << 14;
                      v79[0] = v11;
                      JUMPOUT(0x14E94A);
                    case 29:
LABEL_167:
                      *(_UNKNOWN **)((char *)jpt_12E7D6 + v60) = (_UNKNOWN *)v11;
                      *(_WORD *)((__int16)(v11 >> 15) >> 31) = (__int16)(v11 >> 15) >> 15;
                      MEMORY[0] = 0;
                      MEMORY[0xFFFF] = -1;
                      MEMORY[4] = 2 * v11 + v5 + v5;
                      JUMPOUT(0x14E626);
                    case 32:
LABEL_174:
                      *(_WORD *)v61 = 4 * v61;
                      JUMPOUT(0x14E9B8);
                    default:
LABEL_143:
                      a2 = v77;
                      v24 = v75 & 0x40;
                      v23 = v80;
                      v25 = 0;
                      break;
                  }
                  goto LABEL_56;
                }
                if ( v8 != 100 )
                {
                  v20 = *a5++;
                  v21 = (unsigned __int16)v20;
                  switch ( v8 )
                  {
                    case 'X':
                      v72 = dword_12EA08;
                      v23 = v80;
                      do
                      {
                        v73 = v21 & 0xF;
                        v21 >>= 4;
                        *--v23 = *(_BYTE *)(v72 + v73);
                        v25 = v80 - v23;
                      }
                      while ( v21 );
                      goto LABEL_140;
                    case 'b':
                      v23 = v80;
                      do
                      {
                        *--v23 = (v21 & 1) + 48;
                        v21 >>= 1;
                        v25 = v80 - v23;
                      }
                      while ( v21 );
                      goto LABEL_140;
                    case 'p':
                      v75 |= 0x40u;
                      v24 = 64;
                      v77 = 8;
                      break;
                    case 'u':
                      goto LABEL_79;
                    case 'x':
                      v24 = v75 & 0x40;
                      break;
                    default:
                      goto LABEL_143;
                  }
                  v5 = dword_12EA0C;
                  v23 = v80;
                  do
                  {
                    v71 = v21 & 0xF;
                    v21 >>= 4;
                    *--v23 = *(_BYTE *)(v5 + v71);
                    v25 = v80 - v23;
                  }
                  while ( v21 );
                  a2 = v77 - v25;
                  goto LABEL_56;
                }
LABEL_144:
                v70 = *a5++;
                v21 = (__int16)v70;
LABEL_77:
                if ( (v21 & 0x80000000) != 0 )
                {
                  v21 = -v21;
                  v75 |= 0x80u;
                }
LABEL_79:
                v29 = dword_12EA04;
                v25 = 0;
                v30 = v80;
                do
                {
                  v5 = (unsigned int)(((unsigned int)v29 * (unsigned __int64)v21) >> 32) >> 3;
                  v31 = v21 - 10 * v5 + 48;
                  v32 = v21 > 9;
                  v33 = v30;
                  v21 = v5;
                  *--v30 = v31;
                  v34 = v25++;
                }
                while ( v32 );
                if ( (v75 & 0x80) != 0 )
                {
                  v25 = v34 + 2;
                  v35 = 45;
                }
                else if ( (v75 & 8) != 0 )
                {
                  v25 = v34 + 2;
                  v35 = 43;
                }
                else
                {
                  if ( (v75 & 0x10) == 0 )
                  {
                    a2 = v77 - v25;
                    v23 = v30;
                    v24 = v75 & 0x40;
                    goto LABEL_56;
                  }
                  v25 = v34 + 2;
                  v35 = 32;
                }
                *(v30 - 1) = v35;
                v23 = v33 - 2;
                a2 = v77 - v25;
                if ( (v75 & 0x40) == 0 )
                  goto LABEL_57;
                goto LABEL_85;
              case 'c':
                a2 = v77 - 1;
                v22 = *a5++;
                LOBYTE(v79[0]) = v22;
                v23 = v79;
                v24 = v75 & 0x40;
                v25 = 1;
                goto LABEL_56;
              case 'i':
                if ( (v75 & 2) == 0 && (v75 & 1) != 0 )
                  goto LABEL_144;
                v28 = *a5++;
                v21 = v28;
                goto LABEL_77;
              case 's':
                v36 = (_BYTE *)*a5++;
                v23 = v36;
                if ( !v36 )
                  goto LABEL_96;
                v25 = (unsigned __int8)*v23;
                if ( !*v23 )
                {
                  v24 = v75 & 0x40;
                  a2 = v77;
                  goto LABEL_56;
                }
                if ( !v76 )
                {
LABEL_96:
                  a2 = v77;
                  v24 = v75 & 0x40;
                  v25 = 0;
                  goto LABEL_56;
                }
                v65 = v76;
                v66 = v23;
                v67 = 1 - (_DWORD)v23;
                while ( 2 )
                {
                  while ( 1 )
                  {
                    v5 = (unsigned int)&v66[v67];
                    if ( v65 > 0 )
                      break;
                    v5 = (unsigned int)&v66[v67];
                    if ( !*++v66 )
                      goto LABEL_139;
                  }
                  v68 = (unsigned __int8)*++v66;
                  --v65;
                  if ( v68 )
                  {
                    if ( !v65 )
                    {
                      v76 = 0;
                      v25 = v5;
                      a2 = v77 - v5;
                      v24 = v75 & 0x40;
                      goto LABEL_56;
                    }
                    continue;
                  }
                  break;
                }
LABEL_139:
                v76 = v65;
                v25 = v5;
LABEL_140:
                a2 = v77 - v25;
                v24 = v75 & 0x40;
LABEL_56:
                if ( v24 )
                {
LABEL_85:
                  if ( a2 <= 0 )
                    goto LABEL_93;
                  v11 += a2;
                  while ( 1 )
                  {
                    v5 = v11 - a2;
                    if ( v12 )
                    {
                      if ( a3 <= v5 )
                      {
                        *v10 = 48;
                        --v12;
                        ++v10;
                      }
                    }
                    else if ( !--a2 )
                    {
                      a2 = 0;
                      goto LABEL_93;
                    }
                    if ( !--a2 )
                      goto LABEL_122;
                  }
                }
LABEL_57:
                if ( (v75 & 0x20) == 0 )
                {
                  if ( a2 > 0 )
                  {
                    v58 = a2 + v11;
                    LOWORD(v5) = 32;
                    while ( 1 )
                    {
                      if ( v12 )
                      {
                        if ( a3 <= v11 )
                        {
                          *v10 = 32;
                          --v12;
                          ++v10;
                        }
                      }
                      else if ( v58 == ++v11 )
                      {
LABEL_121:
                        v11 = v58;
LABEL_122:
                        a2 = 0;
                        if ( !v25 )
                        {
LABEL_94:
                          v13 = v23;
LABEL_73:
                          v14 = 7;
                          goto sdio_buffer_prepare_n1d6_e2f2;
                        }
LABEL_59:
                        v26 = v23;
                        v13 = &v23[v25];
                        while ( 1 )
                        {
                          v5 = (unsigned int)&v26[v11 - (_DWORD)v23];
                          if ( v12 )
                          {
                            if ( a3 <= v5 )
                            {
                              *v10 = *v26;
                              --v12;
                              ++v10;
                            }
                          }
                          else if ( ++v26 == v13 )
                          {
LABEL_65:
                            v27 = v25 + v11;
                            goto LABEL_66;
                          }
                          if ( ++v26 == v13 )
                            goto LABEL_65;
                        }
                      }
                      if ( v58 == ++v11 )
                        goto LABEL_121;
                    }
                  }
LABEL_93:
                  if ( !v25 )
                    goto LABEL_94;
                  goto LABEL_59;
                }
LABEL_58:
                if ( v25 )
                  goto LABEL_59;
                v27 = v11;
                v13 = v23;
LABEL_66:
                if ( a2 > 0 )
                {
                  v11 = a2 + v27;
                  a2 = 32;
                  while ( 1 )
                  {
                    if ( v12 )
                    {
                      if ( a3 <= v27 )
                      {
                        *v10 = 32;
                        --v12;
                        ++v10;
                      }
                    }
                    else if ( ++v27 == v11 )
                    {
                      goto LABEL_73;
                    }
                    if ( ++v27 == v11 )
                      goto LABEL_73;
                  }
                }
                v11 = v27;
                v14 = 7;
sdio_buffer_prepare_n1d6_e2f2:
                v16 = *v9++;
                v8 = v16;
                if ( !v16 )
                  goto LABEL_13;
                continue;
              default:
                v23 = v13;
                goto LABEL_96;
            }
          default:
            goto LABEL_162;
        }
      }
    }
    return v11;
  }
  if ( *a4 )
    goto sdio_buffer_prepare_n22;
  v12 = a2;
  v11 = 0;
LABEL_13:
  if ( v12 )
  {
    *v10 = 0;
    return v11;
  }
  if ( !v78 )
    return v11;
  *(v10 - 1) = 0;
  return v11;
}

