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


extern uint32_t dword_11F49C;
extern uint32_t off_11EF28;
extern uint32_t off_11EF2C;
extern uint32_t off_11F48C;
extern uint32_t off_11F490;
extern uint32_t off_11F494;
extern uint32_t off_11F498;
extern uint32_t off_11F4A0;
extern uint32_t off_11F4A4;

// sub_11EBB4 @ 0x11ebb4, size 2264 bytes
unsigned int  sub_11EBB4(char *a1, int a2, unsigned int a3, uint8_t *a4, unsigned int *a5)
{
  int v7; // r2
  uint8_t *v8; // r5
  char *v9; // r7
  unsigned int v10; // r4
  int v11; // r6
  char *v12; // r9
  int v13; // r10
  int v14; // r1
  int v15; // t1
  int v17; // t1
  unsigned int v18; // t1
  int v19; // t1
  unsigned int v20; // r1
  int v21; // r1
  int v22; // t1
  char *v23; // r2
  int v24; // r0
  int v25; // r3
  char *v26; // r0
  unsigned int v27; // r3
  unsigned int v28; // t1
  int v29; // r10
  uint8_t *v30; // lr
  char v31; // r0
  int v32; // cc
  uint8_t *v33; // r2
  int v34; // r0
  char v35; // r0
  char *v36; // t1
  uint8_t *v37; // t1
  int v38; // r2
  char *v39; // lr
  int v40; // r3
  uint8_t *v41; // r12
  char v42; // r1
  char v43; // r3
  int v44; // r1
  int v45; // r2
  uint8_t *v46; // r10
  char *v47; // r2
  int v48; // zf
  int v49; // t1
  char v50; // r9
  uint8_t *v51; // t1
  char *v52; // lr
  int v53; // r3
  uint8_t *v54; // r12
  char v55; // r2
  uint8_t *v56; // r1
  char *v57; // r3
  int v58; // t1
  char v59; // r2
  unsigned int v60; // r1
  int v61; // r3
  unsigned int v62; // t1
  int v63; // r2
  char v64; // r3
  int v65; // r3
  char *v66; // r1
  int v67; // r0
  int v68; // r12
  int v69; // t1
  int v71; // t1
  char *v72; // r12
  int v73; // r3
  char *v74; // lr
  int v75; // r3
  int v76; // [sp+0h] [bp-54h]
  int v77; // [sp+4h] [bp-50h]
  unsigned int v78; // [sp+8h] [bp-4Ch]
  int v79; // [sp+Ch] [bp-48h]
  char v80; // [sp+10h] [bp-44h] BYREF
  char v81; // [sp+11h] [bp-43h]
  char v82; // [sp+13h] [bp-41h] BYREF
  uint8_t v83[4]; // [sp+50h] [bp-4h] BYREF

  v8 = a4 + 1;
  v7 = (uint8_t)*a4;
  v79 = a2;
  v9 = a1;
  if ( !a1 )
  {
    v10 = (uint8_t)*a4;
    if ( *a4 )
    {
      v79 = 0;
LABEL_3:
      v10 = 0;
      v76 = 0;
      v77 = 0;
      v11 = v79;
      v78 = 0;
      v12 = nullptr;
      v13 = 0;
      while ( 2 )
      {
        switch ( v7 )
        {
          case ' ':
          case '+':
          case '-':
            v14 = 5;
            goto LABEL_7;
          case '%':
            v61 = 1;
            goto LABEL_124;
          case '*':
            v61 = 4;
LABEL_124:
            v13 = *((uint8_t *)off_11F48C[v13] + v61);
            switch ( v13 )
            {
              case 0:
                goto LABEL_17;
              case 1:
                goto LABEL_11;
              case 2:
LABEL_44:
                if ( **(uint16_t **)off_11EF2C < 0 )
                  sub_1219C4(off_11F494, off_11F490, 283);
                v13 = 2;
                goto LABEL_12;
              case 3:
                goto LABEL_29;
              case 4:
                goto LABEL_16;
              case 5:
                goto LABEL_26;
              case 6:
                goto LABEL_21;
              case 7:
                goto LABEL_9;
              default:
                goto LABEL_161;
            }
          case '.':
            v14 = 2;
            goto LABEL_7;
          case '0':
            v13 = HIBYTE(((uint8_t *)(uintptr_t)off_11EF28[v13] + (0)));
            switch ( v13 )
            {
              case 0:
                goto LABEL_17;
              case 1:
                goto LABEL_11;
              case 2:
LABEL_43:
                v76 |= 0x40u;
                v13 = 2;
                goto LABEL_12;
              case 3:
LABEL_29:
                if ( v7 != 42 )
                  goto LABEL_30;
                v18 = *a5++;
                v78 = v18;
                v13 = 3;
                break;
              case 4:
                goto LABEL_16;
              case 5:
                goto LABEL_26;
              case 6:
                goto LABEL_21;
              case 7:
                goto LABEL_9;
              default:
                goto LABEL_161;
            }
            goto LABEL_12;
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
            v14 = 7;
            goto LABEL_7;
          case 'h':
          case 'l':
            v14 = 6;
            goto LABEL_7;
          default:
            if ( (unsigned int)(v7 - 49) > 8 )
            {
              v14 = 0;
LABEL_7:
              v13 = *((uint8_t *)off_11EF28[v13] + v14);
              switch ( v13 )
              {
                case 0:
                  goto LABEL_17;
                case 1:
                  goto LABEL_11;
                case 2:
                  goto LABEL_10;
                case 3:
                  goto LABEL_29;
                case 4:
                  goto LABEL_16;
                case 5:
                  goto LABEL_26;
                case 6:
                  goto LABEL_21;
                case 7:
                  goto LABEL_9;
                default:
                  goto LABEL_161;
              }
            }
            v13 = LOBYTE(((uint8_t *)(uintptr_t)off_11EF28[v13] + (1)));
            switch ( v13 )
            {
              case 0:
LABEL_17:
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
LABEL_11:
                v76 = 0;
                v78 = 0;
                v77 = -1;
                v13 = 1;
                goto LABEL_12;
              case 2:
LABEL_10:
                switch ( v7 )
                {
                  case ' ':
                    v76 |= 0x10u;
                    v13 = 2;
                    break;
                  case '+':
                    v76 |= 8u;
                    v13 = 2;
                    break;
                  case '-':
                    v76 |= 0x20u;
                    v13 = 2;
                    break;
                  case '0':
                    goto LABEL_43;
                  default:
                    goto LABEL_44;
                }
                goto LABEL_12;
              case 3:
LABEL_30:
                v78 = v7 - 48 + 10 * v78;
                v13 = 3;
                goto LABEL_12;
              case 4:
LABEL_16:
                v77 = 0;
                v13 = 4;
                goto LABEL_12;
              case 5:
LABEL_26:
                if ( v7 == 42 )
                {
                  v17 = *a5++;
                  v77 = v17;
                }
                else
                {
                  v77 = v7 - 48 + 10 * v77;
                }
                v13 = 5;
                goto LABEL_12;
              case 6:
LABEL_21:
                if ( v7 == 104 )
                {
                  v76 |= 1u;
                  v13 = 6;
                }
                else if ( v7 == 108 )
                {
                  v76 |= 2u;
                  v13 = 6;
                }
                else
                {
                  if ( **(uint16_t **)off_11EF2C < 0 )
                    sub_1219C4(off_11F494, off_11F490, 334);
                  v13 = 6;
                }
                goto LABEL_12;
              case 7:
                goto LABEL_9;
              default:
LABEL_161:
                if ( **(uint16_t **)off_11F498 < 0 )
                  sub_1219C4(off_11F494, off_11F490, 594);
                goto LABEL_12;
            }
        }
LABEL_9:
        switch ( v7 )
        {
          case 'A':
          case 'a':
            v37 = (uint8_t *)*a5++;
            v38 = v78;
            v39 = off_11F4A0[0];
            v41 = v37 + 1;
            v40 = *v37;
            if ( v78 )
            {
              v42 = ((uint8_t *)(uintptr_t)off_11F4A0[0] + (v40 >> 4));
              v43 = ((uint8_t *)(uintptr_t)off_11F4A0[0] + (v40 & 0xF));
              v80 = v42;
              if ( v78 >= 0x15 )
                v38 = 21;
              v44 = 3 * v38;
              v45 = v38 - 1;
              v81 = v43;
              v25 = v44 - 1;
              v21 = 1 - v44;
              if ( !v45 )
              {
LABEL_106:
                if ( (v76 & 0x40) != 0 )
                {
                  v78 = 0;
                  v23 = &v80;
                  goto LABEL_58;
                }
                v78 = v76 & 0x40;
                v23 = &v80;
                if ( (v76 & 0x20) != 0 )
                  goto LABEL_57;
                if ( v25 )
                  goto LABEL_58;
                goto LABEL_93;
              }
            }
            else
            {
              v63 = v40 >> 4;
              v64 = ((uint8_t *)(uintptr_t)off_11F4A0[0] + (v40 & 0xF));
              v80 = ((uint8_t *)(uintptr_t)off_11F4A0[0] + (v63));
              v81 = v64;
              v21 = -47;
              v25 = 47;
              v45 = 15;
            }
            v46 = &v41[v45];
            v47 = &v82;
            do
            {
              v48 = ((uint8_t)v41 & 3) == 0;
              v49 = *v41++;
              *v47 = v39[v49 >> 4];
              v47[1] = v39[v49 & 0xF];
              if ( v48 )
                v50 = 58;
              else
                v50 = 46;
              *(v47 - 1) = v50;
              v47 += 3;
            }
            while ( v46 != v41 );
            goto LABEL_106;
          case 'M':
          case 'm':
            v51 = (uint8_t *)*a5++;
            v52 = off_11F4A0[0];
            v54 = v51 + 6;
            v53 = *v51;
            v55 = ((uint8_t *)(uintptr_t)off_11F4A0[0] + (v53 >> 4));
            v81 = ((uint8_t *)(uintptr_t)off_11F4A0[0] + (v53 & 0xF));
            v80 = v55;
            v56 = v51 + 1;
            v57 = &v80;
            do
            {
              v58 = *v56++;
              v57[2] = 58;
              v59 = v52[v58 & 0xF];
              v57[3] = v52[v58 >> 4];
              v57[4] = v59;
              v57 += 3;
            }
            while ( v54 != v56 );
            v21 = v78 - 17;
            v23 = &v80;
            v24 = v76 & 0x40;
            v25 = 17;
            goto LABEL_55;
          case 'X':
          case 'b':
          case 'd':
          case 'p':
          case 'u':
          case 'x':
            if ( (v76 & 2) != 0 || (v76 & 1) == 0 )
            {
              v62 = *a5++;
              v20 = v62;
              switch ( v7 )
              {
                case 'X':
LABEL_152:
                  v74 = off_11F4A0[0];
                  v23 = v83;
                  do
                  {
                    v75 = v20 & 0xF;
                    v20 >>= 4;
                    *--v23 = v74[v75];
                    v25 = v83 - v23;
                  }
                  while ( v20 );
                  goto LABEL_139;
                case 'b':
LABEL_149:
                  v23 = v83;
                  do
                  {
                    *--v23 = (v20 & 1) + 48;
                    v20 >>= 1;
                    v25 = v83 - v23;
                  }
                  while ( v20 );
                  goto LABEL_139;
                case 'd':
                  goto LABEL_76;
                case 'p':
LABEL_145:
                  v76 |= 0x40u;
                  v24 = 64;
                  v78 = 8;
                  break;
                case 'u':
                  goto LABEL_78;
                case 'x':
LABEL_155:
                  v24 = v76 & 0x40;
                  break;
                default:
LABEL_142:
                  v21 = v78;
                  v24 = v76 & 0x40;
                  v23 = v83;
                  v25 = 0;
                  goto LABEL_55;
              }
              v72 = off_11F4A4;
              v23 = v83;
              do
              {
                v73 = v20 & 0xF;
                v20 >>= 4;
                *--v23 = v72[v73];
                v25 = v83 - v23;
              }
              while ( v20 );
              v21 = v78 - v25;
              goto LABEL_55;
            }
            if ( v7 != 100 )
            {
              v19 = *a5++;
              v20 = (uint16_t)v19;
              switch ( v7 )
              {
                case 'X':
                  goto LABEL_152;
                case 'b':
                  goto LABEL_149;
                case 'p':
                  goto LABEL_145;
                case 'u':
                  goto LABEL_78;
                case 'x':
                  goto LABEL_155;
                default:
                  goto LABEL_142;
              }
            }
LABEL_143:
            v71 = *a5++;
            v20 = (uint16_t)v71;
LABEL_76:
            if ( (v20 & 0x80000000) != 0 )
            {
              v20 = -v20;
              v76 |= 0x80u;
            }
LABEL_78:
            v29 = dword_11F49C;
            v25 = 0;
            v30 = v83;
            do
            {
              v31 = v20 - 10 * ((unsigned int)(((unsigned int)v29 * (uint64_t)v20) >> 32) >> 3) + 48;
              v32 = v20 > 9;
              v33 = v30;
              v20 = (unsigned int)(((unsigned int)v29 * (uint64_t)v20) >> 32) >> 3;
              *--v30 = v31;
              v34 = v25++;
            }
            while ( v32 );
            if ( (v76 & 0x80) != 0 )
            {
              v25 = v34 + 2;
              v35 = 45;
            }
            else if ( (v76 & 8) != 0 )
            {
              v25 = v34 + 2;
              v35 = 43;
            }
            else
            {
              if ( (v76 & 0x10) == 0 )
              {
                v21 = v78 - v25;
                v23 = v30;
                v24 = v76 & 0x40;
                goto LABEL_55;
              }
              v25 = v34 + 2;
              v35 = 32;
            }
            *(v30 - 1) = v35;
            v23 = v33 - 2;
            v21 = v78 - v25;
            if ( (v76 & 0x40) == 0 )
              goto LABEL_56;
            goto LABEL_84;
          case 'c':
            v21 = v78 - 1;
            v22 = *a5++;
            v80 = v22;
            v23 = &v80;
            v24 = v76 & 0x40;
            v25 = 1;
            goto LABEL_55;
          case 'i':
            if ( (v76 & 2) == 0 && (v76 & 1) != 0 )
              goto LABEL_143;
            v28 = *a5++;
            v20 = v28;
            goto LABEL_76;
          case 's':
            v36 = (char *)*a5++;
            v23 = v36;
            if ( !v36 )
              goto LABEL_95;
            v25 = (uint8_t)*v23;
            if ( !*v23 )
            {
              v24 = v76 & 0x40;
              v21 = v78;
              goto LABEL_55;
            }
            if ( !v77 )
            {
LABEL_95:
              v21 = v78;
              v24 = v76 & 0x40;
              v25 = 0;
              goto LABEL_55;
            }
            v65 = v77;
            v66 = v23;
            v67 = 1 - (uint32_t)v23;
            while ( 2 )
            {
              while ( 1 )
              {
                v68 = (int)&v66[v67];
                if ( v65 > 0 )
                  break;
                v68 = (int)&v66[v67];
                if ( !*++v66 )
                  goto LABEL_138;
              }
              v69 = (uint8_t)*++v66;
              --v65;
              if ( v69 )
              {
                if ( !v65 )
                {
                  v77 = 0;
                  v25 = v68;
                  v21 = v78 - v68;
                  v24 = v76 & 0x40;
                  goto LABEL_55;
                }
                continue;
              }
              break;
            }
LABEL_138:
            v77 = v65;
            v25 = v68;
LABEL_139:
            v21 = v78 - v25;
            v24 = v76 & 0x40;
LABEL_55:
            if ( v24 )
            {
LABEL_84:
              if ( v21 <= 0 )
                goto LABEL_92;
              v10 += v21;
              while ( 1 )
              {
                if ( v11 )
                {
                  if ( a3 <= v10 - v21 )
                  {
                    *v9 = 48;
                    --v11;
                    ++v9;
                  }
                }
                else if ( !--v21 )
                {
                  v21 = 0;
                  goto LABEL_92;
                }
                if ( !--v21 )
                  goto LABEL_121;
              }
            }
LABEL_56:
            if ( (v76 & 0x20) == 0 )
            {
              if ( v21 > 0 )
              {
                v60 = v21 + v10;
                while ( 1 )
                {
                  if ( v11 )
                  {
                    if ( a3 <= v10 )
                    {
                      *v9 = 32;
                      --v11;
                      ++v9;
                    }
                  }
                  else if ( v60 == ++v10 )
                  {
LABEL_120:
                    v10 = v60;
LABEL_121:
                    v21 = 0;
                    if ( !v25 )
                    {
LABEL_93:
                      v12 = v23;
LABEL_72:
                      v13 = 7;
                      goto LABEL_12;
                    }
LABEL_58:
                    v26 = v23;
                    v12 = &v23[v25];
                    while ( 1 )
                    {
                      if ( v11 )
                      {
                        if ( a3 <= (unsigned int)&v26[v10 - (uint32_t)v23] )
                        {
                          *v9 = *v26;
                          --v11;
                          ++v9;
                        }
                      }
                      else if ( ++v26 == v12 )
                      {
LABEL_64:
                        v27 = v25 + v10;
                        goto LABEL_65;
                      }
                      if ( ++v26 == v12 )
                        goto LABEL_64;
                    }
                  }
                  if ( v60 == ++v10 )
                    goto LABEL_120;
                }
              }
LABEL_92:
              if ( !v25 )
                goto LABEL_93;
              goto LABEL_58;
            }
LABEL_57:
            if ( v25 )
              goto LABEL_58;
            v27 = v10;
            v12 = v23;
LABEL_65:
            if ( v21 > 0 )
            {
              v10 = v21 + v27;
              while ( 1 )
              {
                if ( v11 )
                {
                  if ( a3 <= v27 )
                  {
                    *v9 = 32;
                    --v11;
                    ++v9;
                  }
                }
                else if ( ++v27 == v10 )
                {
                  goto LABEL_72;
                }
                if ( ++v27 == v10 )
                  goto LABEL_72;
              }
            }
            v10 = v27;
            v13 = 7;
LABEL_12:
            v15 = *v8++;
            v7 = v15;
            if ( !v15 )
              goto LABEL_13;
            continue;
          default:
            v23 = v12;
            goto LABEL_95;
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
  if ( !v79 )
    return v10;
  *(v9 - 1) = 0;
  return v10;
}
