#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t dword_12E8B4;
extern uint32_t dword_12E350;
extern uint32_t off_12E8C0;
extern uint32_t dword_12E8BC;
extern uint32_t dword_12E8B8;
extern uint32_t off_12E354;
extern uint32_t dword_12E8C8;
extern uint32_t dword_12E8CC;
extern uint32_t dword_12E8C4;

// rx_process_packet @ 0x12dfdc, size 2264 bytes
int  rx_process_packet(uint8_t *a1, int a2, unsigned int a3, uint8_t *a4, int *a5)
{
  unsigned int v5; // r12
  int v8; // r2
  uint8_t *v9; // r5
  uint8_t *v10; // r7
  int v11; // r4
  int v12; // r6
  uint8_t *v13; // r9
  int v14; // r10
  int v15; // r0
  int v16; // t1
  int v18; // t1
  unsigned int v19; // t1
  int v20; // t1
  unsigned int v21; // r1
  int v22; // t1
  uint8_t *v23; // r2
  int v24; // r0
  int v25; // r3
  uint8_t *v26; // r0
  unsigned int v27; // r3
  unsigned int v28; // t1
  int v29; // r10
  uint8_t *v30; // lr
  char v31; // r0
  int v32; // cc
  uint8_t *v33; // r2
  int v34; // r0
  char v35; // r0
  uint8_t *v36; // t1
  uint8_t *v37; // t1
  int v38; // r2
  int v39; // lr
  int v40; // r3
  char v41; // r1
  char v42; // r3
  int v43; // r1
  int v44; // r2
  unsigned int v45; // r10
  char *v46; // r2
  int v47; // zf
  int v48; // t1
  char v49; // r9
  uint8_t *v50; // t1
  int v51; // lr
  int v52; // r3
  char v53; // r2
  uint8_t *v54; // r1
  uint8_t *v55; // r3
  int v56; // t1
  char v57; // r2
  int v58; // r1
  int v59; // r3
  int v60; // r1
  int v61; // t1
  int v62; // r2
  char v63; // r3
  int v64; // r3
  uint8_t *v65; // r1
  int v66; // r0
  int v67; // t1
  int v69; // t1
  int v70; // r3
  int v71; // lr
  int v72; // r3
  int v73; // [sp+0h] [bp-54h]
  int v74; // [sp+4h] [bp-50h]
  unsigned int v75; // [sp+8h] [bp-4Ch]
  int v76; // [sp+Ch] [bp-48h]
  uint32_t v77[12]; // [sp+10h] [bp-44h] BYREF
  uint8_t v78[4]; // [sp+50h] [bp-4h] BYREF

  v9 = a4 + 1;
  v8 = (uint8_t)*a4;
  v76 = a2;
  v10 = a1;
  if ( !a1 )
  {
    v11 = (uint8_t)*a4;
    if ( *a4 )
    {
      v76 = 0;
LABEL_3:
      v11 = 0;
      v73 = 0;
      v74 = 0;
      v12 = v76;
      v75 = 0;
      v13 = 0;
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
            a2 = dword_12E8B4;
            v14 = *(uint8_t *)(dword_12E8B4 + 8 * v14 + v59);
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
            v14 = *(uint8_t *)(dword_12E350 + 8 * v14 + 3);
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
              v14 = *(uint8_t *)(dword_12E350 + 8 * v14 + 4);
              a2 = (int)jpt_12E2AC;
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
                  *(uint8_t *)(2 * a2) = 0;
                  MEMORY[0] = 0;
                  JUMPOUT(0x14E3CC);
                default:
                  a2 = dword_12E350;
LABEL_162:
                  if ( **(int16_t **)off_12E8C0 < 0 )
                    irq_disable_mmio_write(dword_12E8BC, dword_12E8B8, 594);
                  break;
              }
              goto LABEL_12;
            }
            a2 = 0;
            break;
        }
        v15 = dword_12E350;
        v14 = *(uint8_t *)(dword_12E350 + 8 * v14 + a2);
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
            goto LABEL_12;
          case 1:
            v73 = 0;
            v75 = 0;
            v74 = -1;
            v14 = 1;
            goto LABEL_12;
          case 2:
            switch ( v8 )
            {
              case ' ':
                v73 |= 0x10u;
                v14 = 2;
                break;
              case '+':
                v73 |= 8u;
                v14 = 2;
                break;
              case '-':
                v73 |= 0x20u;
                v14 = 2;
                break;
              case '0':
                v73 |= 0x40u;
                v14 = 2;
                break;
              default:
                if ( **(int16_t **)off_12E354 < 0 )
                  irq_disable_mmio_write(dword_12E8BC, dword_12E8B8, 283);
                v14 = 2;
                break;
            }
            goto LABEL_12;
          case 3:
            if ( v8 == 42 )
            {
              v19 = *a5++;
              v75 = v19;
            }
            else
            {
              v75 = v8 - 48 + 10 * v75;
            }
            v14 = 3;
            goto LABEL_12;
          case 4:
            v74 = 0;
            v14 = 4;
            goto LABEL_12;
          case 5:
            if ( v8 == 42 )
            {
              v18 = *a5++;
              v74 = v18;
            }
            else
            {
              v74 = v8 - 48 + 10 * v74;
            }
            v14 = 5;
            goto LABEL_12;
          case 6:
            if ( v8 == 104 )
            {
              v73 |= 1u;
              v14 = 6;
            }
            else if ( v8 == 108 )
            {
              v73 |= 2u;
              v14 = 6;
            }
            else
            {
              if ( **(int16_t **)off_12E354 < 0 )
                irq_disable_mmio_write(dword_12E8BC, dword_12E8B8, 334);
              v14 = 6;
            }
            goto LABEL_12;
          case 7:
            switch ( v8 )
            {
              case 'A':
              case 'a':
                v37 = (uint8_t *)*a5++;
                v38 = v75;
                v39 = dword_12E8C8;
                v5 = (unsigned int)(v37 + 1);
                v40 = *v37;
                if ( v75 )
                {
                  v41 = *(uint8_t *)(dword_12E8C8 + (v40 >> 4));
                  v42 = *(uint8_t *)(dword_12E8C8 + (v40 & 0xF));
                  LOBYTE(v77[0]) = v41;
                  if ( v75 >= 0x15 )
                    v38 = 21;
                  v43 = 3 * v38;
                  v44 = v38 - 1;
                  BYTE1(v77[0]) = v42;
                  v25 = v43 - 1;
                  a2 = 1 - v43;
                  if ( !v44 )
                  {
LABEL_107:
                    if ( (v73 & 0x40) != 0 )
                    {
                      v75 = 0;
                      v23 = v77;
                      goto LABEL_59;
                    }
                    v75 = v73 & 0x40;
                    v23 = v77;
                    if ( (v73 & 0x20) != 0 )
                      goto LABEL_58;
                    if ( v25 )
                      goto LABEL_59;
                    goto LABEL_94;
                  }
                }
                else
                {
                  v62 = v40 >> 4;
                  v63 = *(uint8_t *)(dword_12E8C8 + (v40 & 0xF));
                  LOBYTE(v77[0]) = *(uint8_t *)(dword_12E8C8 + v62);
                  BYTE1(v77[0]) = v63;
                  a2 = -47;
                  v25 = 47;
                  v44 = 15;
                }
                v45 = v5 + v44;
                v46 = (char *)v77 + 3;
                do
                {
                  v47 = (v5 & 3) == 0;
                  v48 = *(uint8_t *)v5++;
                  *v46 = *(uint8_t *)(v39 + (v48 >> 4));
                  v46[1] = *(uint8_t *)(v39 + (v48 & 0xF));
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
                v50 = (uint8_t *)*a5++;
                v51 = dword_12E8C8;
                v5 = (unsigned int)(v50 + 6);
                v52 = *v50;
                v53 = *(uint8_t *)(dword_12E8C8 + (v52 >> 4));
                BYTE1(v77[0]) = *(uint8_t *)(dword_12E8C8 + (v52 & 0xF));
                LOBYTE(v77[0]) = v53;
                v54 = v50 + 1;
                v55 = v77;
                do
                {
                  v56 = *v54++;
                  v55[2] = 58;
                  v57 = *(uint8_t *)(v51 + (v56 & 0xF));
                  v55[3] = *(uint8_t *)(v51 + (v56 >> 4));
                  v55[4] = v57;
                  v55 += 3;
                }
                while ( (uint8_t *)v5 != v54 );
                a2 = v75 - 17;
                v23 = v77;
                v24 = v73 & 0x40;
                v25 = 17;
                goto LABEL_56;
              case 'X':
              case 'b':
              case 'd':
              case 'p':
              case 'u':
              case 'x':
                if ( (v73 & 2) != 0 || (v15 = v73 << 31, (v73 & 1) == 0) )
                {
                  v61 = *a5++;
                  v60 = v61;
                  switch ( v8 )
                  {
                    case 'X':
                      goto LABEL_172;
                    case 'Y':
                    case 'Z':
                    case '[':
                    case '\\':
                    case ']':
                    case '^':
                    case '_':
                    case '`':
                    case 'a':
                    case 'c':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'v':
                    case 'w':
                      v11 *= 16;
                      v60 = 2048;
                      v15 = 0;
                      goto LABEL_169;
                    case 'b':
                      *(uint32_t *)(v60 + v15) = v60 << 14;
                      v77[0] = v11;
LABEL_172:
                      LOWORD(v12) = 4 * v60;
                      goto LABEL_173;
                    case 'd':
                    case 'u':
                      *(uint16_t *)((int16_t)(v11 >> 15) >> 31) = (int16_t)(v11 >> 15) >> 15;
                      MEMORY[0] = 0;
                      MEMORY[0xFFFF] = -1;
                      MEMORY[4] = 2 * v11 + v5 + v5;
                      JUMPOUT(0x14E4D6);
                    case 'p':
LABEL_169:
                      *(uint32_t *)(2 * v15) = v15;
                      *(uint32_t *)(v60 + v15) = v60 << 14;
                      v77[0] = v11;
                      JUMPOUT(0x14E7FA);
                    case 'x':
LABEL_173:
                      *(uint16_t *)v60 = v12;
                      JUMPOUT(0x14E868);
                    default:
LABEL_143:
                      a2 = v75;
                      v24 = v73 & 0x40;
                      v23 = v78;
                      v25 = 0;
                      break;
                  }
                  goto LABEL_56;
                }
                if ( v8 != 100 )
                {
                  v20 = *a5++;
                  v21 = (uint16_t)v20;
                  switch ( v8 )
                  {
                    case 'X':
                      v71 = dword_12E8C8;
                      v23 = v78;
                      do
                      {
                        v72 = v21 & 0xF;
                        v21 >>= 4;
                        *--v23 = *(uint8_t *)(v71 + v72);
                        v25 = v78 - v23;
                      }
                      while ( v21 );
                      goto LABEL_140;
                    case 'b':
                      v23 = v78;
                      do
                      {
                        *--v23 = (v21 & 1) + 48;
                        v21 >>= 1;
                        v25 = v78 - v23;
                      }
                      while ( v21 );
                      goto LABEL_140;
                    case 'p':
                      v73 |= 0x40u;
                      v24 = 64;
                      v75 = 8;
                      break;
                    case 'u':
                      goto LABEL_79;
                    case 'x':
                      v24 = v73 & 0x40;
                      break;
                    default:
                      goto LABEL_143;
                  }
                  v5 = dword_12E8CC;
                  v23 = v78;
                  do
                  {
                    v70 = v21 & 0xF;
                    v21 >>= 4;
                    *--v23 = *(uint8_t *)(v5 + v70);
                    v25 = v78 - v23;
                  }
                  while ( v21 );
                  a2 = v75 - v25;
                  goto LABEL_56;
                }
LABEL_144:
                v69 = *a5++;
                v21 = (int16_t)v69;
LABEL_77:
                if ( (v21 & 0x80000000) != 0 )
                {
                  v21 = -v21;
                  v73 |= 0x80u;
                }
LABEL_79:
                v29 = dword_12E8C4;
                v25 = 0;
                v30 = v78;
                do
                {
                  v5 = (unsigned int)(((unsigned int)v29 * (unsigned uint64_t)v21) >> 32) >> 3;
                  v31 = v21 - 10 * v5 + 48;
                  v32 = v21 > 9;
                  v33 = v30;
                  v21 = v5;
                  *--v30 = v31;
                  v34 = v25++;
                }
                while ( v32 );
                if ( (v73 & 0x80) != 0 )
                {
                  v25 = v34 + 2;
                  v35 = 45;
                }
                else if ( (v73 & 8) != 0 )
                {
                  v25 = v34 + 2;
                  v35 = 43;
                }
                else
                {
                  if ( (v73 & 0x10) == 0 )
                  {
                    a2 = v75 - v25;
                    v23 = v30;
                    v24 = v73 & 0x40;
                    goto LABEL_56;
                  }
                  v25 = v34 + 2;
                  v35 = 32;
                }
                *(v30 - 1) = v35;
                v23 = v33 - 2;
                a2 = v75 - v25;
                if ( (v73 & 0x40) == 0 )
                  goto LABEL_57;
                goto LABEL_85;
              case 'c':
                a2 = v75 - 1;
                v22 = *a5++;
                LOBYTE(v77[0]) = v22;
                v23 = v77;
                v24 = v73 & 0x40;
                v25 = 1;
                goto LABEL_56;
              case 'i':
                if ( (v73 & 2) == 0 && (v73 & 1) != 0 )
                  goto LABEL_144;
                v28 = *a5++;
                v21 = v28;
                goto LABEL_77;
              case 's':
                v36 = (uint8_t *)*a5++;
                v23 = v36;
                if ( !v36 )
                  goto LABEL_96;
                v25 = (uint8_t)*v23;
                if ( !*v23 )
                {
                  v24 = v73 & 0x40;
                  a2 = v75;
                  goto LABEL_56;
                }
                if ( !v74 )
                {
LABEL_96:
                  a2 = v75;
                  v24 = v73 & 0x40;
                  v25 = 0;
                  goto LABEL_56;
                }
                v64 = v74;
                v65 = v23;
                v66 = 1 - (uint32_t)v23;
                while ( 2 )
                {
                  while ( 1 )
                  {
                    v5 = (unsigned int)&v65[v66];
                    if ( v64 > 0 )
                      break;
                    v5 = (unsigned int)&v65[v66];
                    if ( !*++v65 )
                      goto LABEL_139;
                  }
                  v67 = (uint8_t)*++v65;
                  --v64;
                  if ( v67 )
                  {
                    if ( !v64 )
                    {
                      v74 = 0;
                      v25 = v5;
                      a2 = v75 - v5;
                      v24 = v73 & 0x40;
                      goto LABEL_56;
                    }
                    continue;
                  }
                  break;
                }
LABEL_139:
                v74 = v64;
                v25 = v5;
LABEL_140:
                a2 = v75 - v25;
                v24 = v73 & 0x40;
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
                if ( (v73 & 0x20) == 0 )
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
                          goto LABEL_12;
                        }
LABEL_59:
                        v26 = v23;
                        v13 = &v23[v25];
                        while ( 1 )
                        {
                          v5 = (unsigned int)&v26[v11 - (uint32_t)v23];
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
LABEL_12:
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
    goto LABEL_3;
  v12 = a2;
  v11 = 0;
LABEL_13:
  if ( v12 )
  {
    *v10 = 0;
    return v11;
  }
  if ( !v76 )
    return v11;
  *(v10 - 1) = 0;
  return v11;
}

