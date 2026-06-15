// sub_12E344 @ 0x12e344, size 2264 bytes
// Doc: sdio_buffer_prepare_n3a [tx]: SDIO buffer prepare with shift/mask operations on length
// sdio_buffer_prepare_n3a [tx]: SDIO buffer prepare with shift/mask operations on length
unsigned int __fastcall sub_12E344(int a1, int a2, unsigned int a3, _BYTE *a4, int *a5)
{
  int v7; // r2
  int v8; // r5
  _BYTE *v9; // r7
  unsigned int v10; // r4
  int v11; // r6
  _BYTE *v12; // r9
  int v13; // r10
  int v14; // t1
  int v16; // t1
  unsigned int v17; // t1
  int v18; // t1
  unsigned int v19; // r1
  int v20; // t1
  _BYTE *v21; // r2
  int v22; // r3
  unsigned int v23; // r3
  unsigned int v24; // t1
  int v25; // r10
  _BYTE *v26; // lr
  char v27; // r0
  _BYTE *v28; // r2
  int v29; // r0
  char v30; // r0
  _BYTE *v31; // t1
  unsigned __int8 *v32; // t1
  int v33; // r2
  int v34; // lr
  int v35; // r3
  unsigned __int8 *v36; // r12
  char v37; // r1
  char v38; // r3
  int v39; // r1
  int v40; // r2
  unsigned __int8 *v41; // r10
  char *v42; // r2
  int v44; // t1
  char v45; // r9
  unsigned __int8 *v46; // t1
  int v47; // lr
  int v48; // r3
  unsigned __int8 *v49; // r12
  char v50; // r2
  unsigned __int8 *v51; // r1
  _BYTE *v52; // r3
  int v53; // t1
  char v54; // r2
  unsigned int v55; // r1
  bool v56; // cc
  int v57; // r3
  int v58; // r2
  int v59; // r1
  int v60; // t1
  int v61; // r2
  char v62; // r3
  int v63; // r3
  _BYTE *v64; // r1
  int v65; // r0
  int v66; // r12
  int v67; // t1
  int v69; // t1
  int v70; // r12
  int v71; // r3
  int v72; // lr
  int v73; // r3
  int v74; // r5
  _DWORD *v78; // r4
  int v79; // r1
  int v80; // [sp+0h] [bp-54h]
  int v81; // [sp+4h] [bp-50h]
  unsigned int v82; // [sp+8h] [bp-4Ch]
  int v83; // [sp+Ch] [bp-48h]
  _DWORD v84[16]; // [sp+10h] [bp-44h] BYREF
  _BYTE v85[4]; // [sp+50h] [bp-4h] BYREF

  v8 = (int)(a4 + 1);
  v7 = (unsigned __int8)*a4;
  v83 = a2;
  v9 = (_BYTE *)a1;
  if ( !a1 )
  {
    v10 = (unsigned __int8)*a4;
    if ( *a4 )
    {
      v83 = 0;
LABEL_3:
      v10 = 0;
      v80 = 0;
      v81 = 0;
      v11 = v83;
      v82 = 0;
      v12 = nullptr;
      v13 = 0;
      while ( 2 )
      {
        switch ( v7 )
        {
          case ' ':
          case '+':
          case '-':
            a2 = 5;
            break;
          case '%':
            v57 = 1;
            v56 = __OFSUB__(v7 - 32, 88);
            goto LABEL_125;
          case '*':
            v57 = 4;
            v56 = __OFSUB__(v7 - 32, 88);
LABEL_125:
            a2 = dword_12EC1C;
            v13 = *(unsigned __int8 *)(dword_12EC1C + 8 * v13 + v57);
            switch ( v13 )
            {
              case 0:
              case 1:
              case 3:
              case 4:
              case 5:
              case 6:
              case 7:
                goto LABEL_164;
              case 2:
                goto LABEL_167;
              default:
                goto LABEL_162;
            }
          case '.':
            a2 = 2;
            break;
          case '0':
            v13 = *(unsigned __int8 *)(dword_12E6B8 + 8 * v13 + 3);
            switch ( v13 )
            {
              case 0:
              case 1:
              case 3:
              case 4:
              case 5:
              case 6:
              case 7:
                goto LABEL_164;
              case 2:
                v56 = __OFSUB__(a1, 4);
LABEL_167:
                if ( v56 )
                  JUMPOUT(0x14E688);
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
            if ( (unsigned int)(v7 - 49) <= 8 )
            {
              v13 = *(unsigned __int8 *)(dword_12E6B8 + 8 * v13 + 4);
              a2 = (int)jpt_12E614;
              switch ( v13 )
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
                  JUMPOUT(0x14E664);
                default:
                  a2 = dword_12E6B8;
LABEL_162:
                  if ( **(__int16 **)off_12EC28 < 0 )
                    a1 = sub_12F694(dword_12EC24, dword_12EC20, 594);
                  break;
              }
              goto LABEL_12;
            }
            a2 = 0;
            break;
        }
        a1 = dword_12E6B8;
        v13 = *(unsigned __int8 *)(dword_12E6B8 + 8 * v13 + a2);
        switch ( v13 )
        {
          case 0:
            if ( v11 )
            {
              if ( a3 <= v10 )
              {
                *v9++ = v7;
                --v11;
              }
            }
            ++v10;
            v13 = 0;
            goto LABEL_12;
          case 1:
            v80 = 0;
            v82 = 0;
            v81 = -1;
            v13 = 1;
            goto LABEL_12;
          case 2:
            switch ( v7 )
            {
              case ' ':
                v80 |= 0x10u;
                v13 = 2;
                break;
              case '+':
                v80 |= 8u;
                v13 = 2;
                break;
              case '-':
                v80 |= 0x20u;
                v13 = 2;
                break;
              case '0':
                v80 |= 0x40u;
                v13 = 2;
                break;
              default:
                if ( **(__int16 **)off_12E6BC < 0 )
                  a1 = sub_12F694(dword_12EC24, dword_12EC20, 283);
                v13 = 2;
                break;
            }
            goto LABEL_12;
          case 3:
            if ( v7 == 42 )
            {
              v17 = *a5++;
              v82 = v17;
            }
            else
            {
              v82 = v7 - 48 + 10 * v82;
            }
            v13 = 3;
            goto LABEL_12;
          case 4:
            v81 = 0;
            v13 = 4;
            goto LABEL_12;
          case 5:
            if ( v7 == 42 )
            {
              v16 = *a5++;
              v81 = v16;
            }
            else
            {
              v81 = v7 - 48 + 10 * v81;
            }
            v13 = 5;
            goto LABEL_12;
          case 6:
            if ( v7 == 104 )
            {
              v80 |= 1u;
              v13 = 6;
            }
            else if ( v7 == 108 )
            {
              v80 |= 2u;
              v13 = 6;
            }
            else
            {
              if ( **(__int16 **)off_12E6BC < 0 )
                a1 = sub_12F694(dword_12EC24, dword_12EC20, 334);
              v13 = 6;
            }
            goto LABEL_12;
          case 7:
            switch ( v7 )
            {
              case 'A':
              case 'a':
                v32 = (unsigned __int8 *)*a5++;
                v33 = v82;
                v34 = dword_12EC30;
                v36 = v32 + 1;
                v35 = *v32;
                if ( v82 )
                {
                  v37 = *(_BYTE *)(dword_12EC30 + (v35 >> 4));
                  v38 = *(_BYTE *)(dword_12EC30 + (v35 & 0xF));
                  LOBYTE(v84[0]) = v37;
                  if ( v82 >= 0x15 )
                    v33 = 21;
                  v39 = 3 * v33;
                  v40 = v33 - 1;
                  BYTE1(v84[0]) = v38;
                  v22 = v39 - 1;
                  a2 = 1 - v39;
                  if ( !v40 )
                  {
LABEL_107:
                    if ( (v80 & 0x40) != 0 )
                    {
                      v82 = 0;
                      v21 = v84;
                      goto LABEL_59;
                    }
                    v82 = v80 & 0x40;
                    a1 = v80 << 26;
                    v21 = v84;
                    if ( (v80 & 0x20) != 0 )
                      goto LABEL_58;
                    if ( v22 )
                      goto LABEL_59;
                    goto LABEL_94;
                  }
                }
                else
                {
                  v61 = v35 >> 4;
                  v62 = *(_BYTE *)(dword_12EC30 + (v35 & 0xF));
                  LOBYTE(v84[0]) = *(_BYTE *)(dword_12EC30 + v61);
                  BYTE1(v84[0]) = v62;
                  a2 = -47;
                  v22 = 47;
                  v40 = 15;
                }
                v41 = &v36[v40];
                v42 = (char *)v84 + 3;
                do
                {
                  _ZF = ((unsigned __int8)v36 & 3) == 0;
                  v44 = *v36++;
                  *v42 = *(_BYTE *)(v34 + (v44 >> 4));
                  v42[1] = *(_BYTE *)(v34 + (v44 & 0xF));
                  if ( _ZF )
                    v45 = 58;
                  else
                    v45 = 46;
                  *(v42 - 1) = v45;
                  v42 += 3;
                }
                while ( v41 != v36 );
                goto LABEL_107;
              case 'M':
              case 'm':
                v46 = (unsigned __int8 *)*a5++;
                v47 = dword_12EC30;
                v49 = v46 + 6;
                v48 = *v46;
                v50 = *(_BYTE *)(dword_12EC30 + (v48 >> 4));
                BYTE1(v84[0]) = *(_BYTE *)(dword_12EC30 + (v48 & 0xF));
                LOBYTE(v84[0]) = v50;
                v51 = v46 + 1;
                v52 = v84;
                do
                {
                  v53 = *v51++;
                  v52[2] = 58;
                  v54 = *(_BYTE *)(v47 + (v53 & 0xF));
                  v52[3] = *(_BYTE *)(v47 + (v53 >> 4));
                  v52[4] = v54;
                  v52 += 3;
                }
                while ( v49 != v51 );
                a2 = v82 - 17;
                v21 = v84;
                a1 = v80 & 0x40;
                v22 = 17;
                goto LABEL_56;
              case 'X':
              case 'b':
              case 'd':
              case 'p':
              case 'u':
              case 'x':
                if ( (v80 & 2) != 0 || (a1 = v80 << 31, (v80 & 1) == 0) )
                {
                  v58 = v7 - 88;
                  v60 = *a5++;
                  v59 = v60;
                  switch ( v58 )
                  {
                    case 0:
                      goto LABEL_175;
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
                      *(_DWORD *)(v59 + 40) = v9;
                      *(_DWORD *)&v9[v8] = v58;
                      v84[0] = v10;
                      *(_DWORD *)(v59 + 56) = v9;
                      goto LABEL_173;
                    case 10:
                      goto LABEL_174;
                    case 12:
                    case 29:
                      __cdp(14, 0, 0, 1, 14, 7);
                      v74 = 4 * dword_14E9E8 - 4;
                      *(_WORD *)((v59 << 18) + 4) = 4 * v59;
                      *(_WORD *)(v10 + 2) = 4 * v59;
                      *(_DWORD *)(2 * *(unsigned __int16 *)(v10 - 4)) = *(unsigned __int16 *)(v10 - 4);
                      STACK[0x3F8] = v74;
                      MEMORY[0] = 0;
                      __asm { LDC             p1, c0, [R9], {0x86} }
                      JUMPOUT(0x14E86E);
                    case 24:
LABEL_173:
                      v78 = (_DWORD *)(32 * v58);
                      a1 = 0;
                      v84[12] = 32 * v58;
                      *(_DWORD *)v11 = 32 * v58;
                      *((_BYTE *)v78 + v8) = (unsigned __int8)jpt_12E9FE;
                      *v78 = jpt_12E9FE;
                      v78[1] = v78;
LABEL_174:
                      v11 = 32 * v8;
                      v8 = (v8 & (a1 << 16)) - 3;
LABEL_175:
                      v59 = 32 * v11;
                      MEMORY[0] = v9;
                      *(_DWORD *)(v59 + 8) = v9;
                      *(_DWORD *)(v11 + v8) = v9;
                      v84[0] = 32 * v11;
                      *(_DWORD *)(v59 + 8) = v9;
                      goto LABEL_176;
                    case 32:
LABEL_176:
                      *(_DWORD *)(v59 + 8) = v9;
                      *(_DWORD *)((v58 << 16) + 0x40) = v58 << 16;
                      *(_DWORD *)(1048577 * v58 + 8) = v9;
                      *(_DWORD *)((v58 << 16) + 0x40) = v58 << 16;
                      *(_DWORD *)((v58 << 20) + 0x18) = v9;
                      v79 = v58 << 16;
                      MEMORY[0] = 0;
                      *(_DWORD *)(v79 + 24) = v9;
                      *(_DWORD *)(v79 + 24) = v9;
                      JUMPOUT(0x14EC02);
                    default:
LABEL_143:
                      a2 = v82;
                      a1 = v80 & 0x40;
                      v21 = v85;
                      v22 = 0;
                      break;
                  }
                  goto LABEL_56;
                }
                if ( v7 != 100 )
                {
                  v18 = *a5++;
                  v19 = (unsigned __int16)v18;
                  switch ( v7 )
                  {
                    case 'X':
                      v72 = dword_12EC30;
                      v21 = v85;
                      do
                      {
                        v73 = v19 & 0xF;
                        v19 >>= 4;
                        *--v21 = *(_BYTE *)(v72 + v73);
                        v22 = v85 - v21;
                      }
                      while ( v19 );
                      goto LABEL_140;
                    case 'b':
                      v21 = v85;
                      do
                      {
                        *--v21 = (v19 & 1) + 48;
                        v19 >>= 1;
                        v22 = v85 - v21;
                      }
                      while ( v19 );
                      goto LABEL_140;
                    case 'p':
                      v80 |= 0x40u;
                      a1 = 64;
                      v82 = 8;
                      break;
                    case 'u':
                      goto LABEL_79;
                    case 'x':
                      a1 = v80 & 0x40;
                      break;
                    default:
                      goto LABEL_143;
                  }
                  v70 = dword_12EC34;
                  v21 = v85;
                  do
                  {
                    v71 = v19 & 0xF;
                    v19 >>= 4;
                    *--v21 = *(_BYTE *)(v70 + v71);
                    v22 = v85 - v21;
                  }
                  while ( v19 );
                  a2 = v82 - v22;
                  goto LABEL_56;
                }
LABEL_144:
                v69 = *a5++;
                v19 = (__int16)v69;
LABEL_77:
                if ( (v19 & 0x80000000) != 0 )
                {
                  v19 = -v19;
                  v80 |= 0x80u;
                }
LABEL_79:
                v25 = dword_12EC2C;
                v22 = 0;
                v26 = v85;
                do
                {
                  v27 = v19 - 10 * ((unsigned int)(((unsigned int)v25 * (unsigned __int64)v19) >> 32) >> 3) + 48;
                  v56 = v19 > 9;
                  v28 = v26;
                  v19 = (unsigned int)(((unsigned int)v25 * (unsigned __int64)v19) >> 32) >> 3;
                  *--v26 = v27;
                  v29 = v22++;
                }
                while ( v56 );
                if ( (v80 & 0x80) != 0 )
                {
                  v22 = v29 + 2;
                  v30 = 45;
                }
                else if ( (v80 & 8) != 0 )
                {
                  v22 = v29 + 2;
                  v30 = 43;
                }
                else
                {
                  if ( (v80 & 0x10) == 0 )
                  {
                    a2 = v82 - v22;
                    v21 = v26;
                    a1 = v80 & 0x40;
                    goto LABEL_56;
                  }
                  v22 = v29 + 2;
                  v30 = 32;
                }
                *(v26 - 1) = v30;
                a1 = v80 & 0x40;
                v21 = v28 - 2;
                a2 = v82 - v22;
                if ( (v80 & 0x40) == 0 )
                  goto LABEL_57;
                goto LABEL_85;
              case 'c':
                a2 = v82 - 1;
                v20 = *a5++;
                LOBYTE(v84[0]) = v20;
                v21 = v84;
                a1 = v80 & 0x40;
                v22 = 1;
                goto LABEL_56;
              case 'i':
                if ( (v80 & 2) == 0 && (v80 & 1) != 0 )
                  goto LABEL_144;
                v24 = *a5++;
                v19 = v24;
                goto LABEL_77;
              case 's':
                v31 = (_BYTE *)*a5++;
                v21 = v31;
                if ( !v31 )
                  goto LABEL_96;
                v22 = (unsigned __int8)*v21;
                if ( !*v21 )
                {
                  a1 = v80 & 0x40;
                  a2 = v82;
                  goto LABEL_56;
                }
                if ( !v81 )
                {
LABEL_96:
                  a2 = v82;
                  a1 = v80 & 0x40;
                  v22 = 0;
                  goto LABEL_56;
                }
                v63 = v81;
                v64 = v21;
                v65 = 1 - (_DWORD)v21;
                while ( 2 )
                {
                  while ( 1 )
                  {
                    v66 = (int)&v64[v65];
                    if ( v63 > 0 )
                      break;
                    v66 = (int)&v64[v65];
                    if ( !*++v64 )
                      goto LABEL_139;
                  }
                  v67 = (unsigned __int8)*++v64;
                  --v63;
                  if ( v67 )
                  {
                    if ( !v63 )
                    {
                      v81 = 0;
                      v22 = v66;
                      a2 = v82 - v66;
                      a1 = v80 & 0x40;
                      goto LABEL_56;
                    }
                    continue;
                  }
                  break;
                }
LABEL_139:
                v81 = v63;
                v22 = v66;
LABEL_140:
                a2 = v82 - v22;
                a1 = v80 & 0x40;
LABEL_56:
                if ( a1 )
                {
LABEL_85:
                  if ( a2 <= 0 )
                    goto LABEL_93;
                  v10 += a2;
                  while ( 1 )
                  {
                    a1 = (int)v9;
                    if ( v11 )
                    {
                      if ( a3 <= v10 - a2 )
                      {
                        *v9 = 48;
                        a1 = (int)(v9 + 1);
                        --v11;
                        ++v9;
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
                a1 = v80 << 26;
                if ( (v80 & 0x20) == 0 )
                {
                  if ( a2 > 0 )
                  {
                    v55 = a2 + v10;
                    while ( 1 )
                    {
                      a1 = (int)v9;
                      if ( v11 )
                      {
                        if ( a3 <= v10 )
                        {
                          *v9 = 32;
                          a1 = (int)(v9 + 1);
                          --v11;
                          ++v9;
                        }
                      }
                      else if ( v55 == ++v10 )
                      {
LABEL_121:
                        v10 = v55;
LABEL_122:
                        a2 = 0;
                        if ( !v22 )
                        {
LABEL_94:
                          v12 = v21;
LABEL_73:
                          v13 = 7;
                          goto LABEL_12;
                        }
LABEL_59:
                        a1 = (int)v21;
                        v12 = &v21[v22];
                        while ( 1 )
                        {
                          if ( v11 )
                          {
                            if ( a3 <= a1 + v10 - (unsigned int)v21 )
                            {
                              *v9 = *(_BYTE *)a1;
                              --v11;
                              ++v9;
                            }
                          }
                          else if ( (_BYTE *)++a1 == v12 )
                          {
LABEL_65:
                            v23 = v22 + v10;
                            goto LABEL_66;
                          }
                          if ( (_BYTE *)++a1 == v12 )
                            goto LABEL_65;
                        }
                      }
                      if ( v55 == ++v10 )
                        goto LABEL_121;
                    }
                  }
LABEL_93:
                  if ( !v22 )
                    goto LABEL_94;
                  goto LABEL_59;
                }
LABEL_58:
                if ( v22 )
                  goto LABEL_59;
                v23 = v10;
                v12 = v21;
LABEL_66:
                if ( a2 > 0 )
                {
                  v10 = a2 + v23;
                  a2 = 32;
                  while ( 1 )
                  {
                    if ( v11 )
                    {
                      if ( a3 <= v23 )
                      {
                        *v9 = 32;
                        --v11;
                        ++v9;
                      }
                    }
                    else if ( ++v23 == v10 )
                    {
                      goto LABEL_73;
                    }
                    if ( ++v23 == v10 )
                      goto LABEL_73;
                  }
                }
                v10 = v23;
                v13 = 7;
LABEL_12:
                v14 = *(unsigned __int8 *)v8++;
                v7 = v14;
                if ( !v14 )
                  goto LABEL_13;
                continue;
              default:
                v21 = v12;
                goto LABEL_96;
            }
          default:
            goto LABEL_162;
        }
      }
    }
    return v10;
  }
  if ( *a4 )
    goto LABEL_3;
  v11 = a2;
  v10 = 0;
LABEL_13:
  if ( v11 )
  {
    *v9 = 0;
    return v10;
  }
  if ( !v83 )
    return v10;
  *(v9 - 1) = 0;
  return v10;
}

