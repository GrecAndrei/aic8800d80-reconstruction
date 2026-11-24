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


extern uint32_t dword_112548;
extern uint32_t dword_112558;
extern uint32_t dword_112884;
extern uint32_t dword_11288C;
extern uint32_t dword_1129DC;
extern uint32_t off_112534;
extern uint32_t off_112538;
extern uint32_t off_11253C;
extern uint32_t off_112540;
extern uint32_t off_112544;
extern uint32_t off_112550;
extern uint32_t off_11255C;
extern uint32_t off_112870;
extern uint32_t off_112874;
extern uint32_t off_112878;
extern uint32_t off_11287C;
extern uint32_t off_112880;
extern uint32_t off_112888;
extern uint32_t off_112890;
extern uint32_t off_1129D0;
extern uint32_t off_1129D4;
extern uint32_t off_1129E0;
extern uint32_t off_1129E4;

// sub_112228 @ 0x112228, size 1958 bytes
int  sub_112228(uint64_t a1, uint32_t *a2)
{
  int v2; // r4
  uint8_t *v3; // r5
  void *v4; // r6
  uint8_t *v5; // r3
  uint8_t v6; // r2
  int v7; // r3
  uint32_t *v8; // r3
  int ( **v9)(int, unsigned int); // r4
  int ( *v10)(void *); // r1
  uint8_t *v11; // r8
  char v12; // r2
  int v13; // r7
  int v14; // r0
  int v15; // r3
  int v16; // r3
  uint32_t *v17; // r2
  int v18; // r3
  uint32_t *v19; // r3
  uint32_t *v20; // r3
  int v21; // r1
  uint32_t *v22; // r2
  uint32_t *v23; // r3
  int v24; // r3
  uint32_t *v25; // r2
  uint32_t *v26; // r3
  uint32_t *v27; // r2
  int v28; // r0
  uint32_t *v29; // r3
  int v30; // r3
  void *v31; // r3
  unsigned int v32; // r0
  unsigned int v33; // r1
  int v34; // r1
  int ( *v35)(int, unsigned int); // r3
  uint8_t *v36; // r3
  uint16_t *v37; // r3
  void *v38; // r2
  int v39; // r4
  unsigned int v40; // r1
  uint8_t *v41; // r0
  int v42; // r3
  unsigned int v43; // r3
  uint8_t *v44; // r0
  uint8_t *v45; // r0
  uint16_t v46; // r2
  uint16_t v47; // r3
  char v48; // r3
  char v49; // r3
  uint32_t *v50; // r4
  int v51; // r0
  int *v52; // r8
  int v53; // r7
  int v54; // r3
  int v55; // r7
  uint32_t *v56; // r2
  uint32_t *v57; // r3
  uint16_t v58; // r2
  int v59; // r6
  unsigned int v60; // r2
  unsigned int v61; // r1
  uint32_t *v62; // r2
  void ( *v63)(uint8_t *); // r3
  uint32_t *v64; // r2
  int v65; // r0
  uint32_t *v66; // r3
  unsigned int v67; // r0
  int v68; // r0

  v2 = HIDWORD(a1);
  if ( (uint32_t)a1 )
  {
    v3 = (uint8_t *)off_112534;
    v15 = *(uint8_t *)off_112534;
    if ( v15 == 2 )
    {
      v4 = off_112538;
      sub_10DC24(aEp0SetupErrorD, HIDWORD(a1), a2);
      goto LABEL_7;
    }
    if ( (a1 & 0x100000000LL) == 0 )
      goto LABEL_18;
    if ( v15 == 4 )
    {
      HIDWORD(a1) = *((uint16_t *)off_112534 + 4);
      v58 = *((uint16_t *)off_112534 + 5);
      LODWORD(a1) = (uint16_t)(WORD2(a1) - v58);
      if ( WORD2(a1) == v58 )
      {
        *(uint8_t *)off_112534 = 5;
        return a1;
      }
      if ( (uint32_t)a1 == 64 )
      {
        v59 = 1;
      }
      else
      {
        if ( (unsigned int)a1 >= 0x40 )
          LODWORD(a1) = 64;
        v59 = 0;
      }
      v60 = (uint16_t)(v58 + a1);
      *((uint16_t *)off_112534 + 5) = v60;
      if ( HIDWORD(a1) < v60 )
      {
        LODWORD(a1) = sub_10DC24("Ep0 send length err %u-%u", HIDWORD(a1), v60);
        WORD2(a1) = *((uint16_t *)v3 + 4);
        v60 = *((uint16_t *)v3 + 5);
      }
      v61 = (uint16_t)(WORD2(a1) - v60);
      if ( v61 > 0x40 )
      {
        v61 = 64;
      }
      else if ( !v61 )
      {
        if ( !v59 )
        {
          v62 = off_1129D0;
          *v3 = 5;
          v62[516] |= 0x10u;
          return a1;
        }
        LODWORD(a1) = sub_111AFC(nullptr, 0);
        goto LABEL_18;
      }
      LODWORD(a1) = sub_111AFC((char *)(*((uint32_t *)v3 + 1) + v60), v61);
LABEL_18:
      if ( (v2 & 0x20) == 0 )
        return a1;
LABEL_19:
      if ( *v3 == 6 )
      {
        v27 = *(uint32_t **)off_112538;
        v28 = *(uint32_t *)off_112544;
        v29 = off_11253C;
        *v27 = dword_112548;
        v27[1] = v28;
        v29[709] = v27;
        v29[706] = v29[706];
        v29[704] |= 0x84000000;
        *v3 = 7;
        v29[517] |= 0x10u;
        LODWORD(a1) = sub_111910();
      }
      return a1;
    }
    if ( v15 != 7 )
      goto LABEL_18;
    v23 = off_11253C;
    HIDWORD(a1) = off_112550;
    LODWORD(a1) = 0;
    *(uint8_t *)off_112534 = 0;
    v23[517] &= ~0x10u;
    v23[516] &= ~0x10u;
    if ( *(uint8_t *)HIDWORD(a1) )
    {
      v23[513] = (16 * (uint8_t)*(uint8_t *)HIDWORD(a1)) & 0x70 | v23[513] & 0xFFFFFF8F;
      *(uint8_t *)HIDWORD(a1) = 0;
    }
  }
  else
  {
    if ( (BYTE4(a1) & 0x21) == 0x21 )
    {
      v17 = off_11253C;
      if ( (*((uint32_t *)off_11253C + 708) & 0x7F) == 0x40 )
      {
        v18 = *((uint32_t *)off_11253C + 708);
        LODWORD(a1) = v18 << 12;
        if ( (v18 & 0x80000) != 0 )
        {
          LODWORD(a1) = *(uint32_t *)off_112544;
          v19 = *(uint32_t **)off_112538;
          *v19 = dword_112548;
          v19[1] = a1;
          v17[709] = v19;
          v17[706] = v17[706];
          v17[704] |= 0x84000000;
          return a1;
        }
      }
    }
    if ( (a1 & 0x100000000LL) == 0 )
    {
      v3 = (uint8_t *)off_112534;
      v16 = *(uint8_t *)off_112534;
      if ( (a1 & 0x800000000LL) != 0 )
      {
        if ( v16 != 1 )
          return a1;
        goto LABEL_6;
      }
      if ( v16 == 2 )
      {
LABEL_6:
        v4 = off_112538;
        goto LABEL_7;
      }
      goto LABEL_18;
    }
    if ( (a1 & 0x800000000LL) != 0 )
    {
      v3 = (uint8_t *)off_112534;
      if ( !*(uint8_t *)off_112534 )
        goto LABEL_6;
      sub_111D44(1, 0);
      v4 = off_112890;
LABEL_7:
      if ( (v2 & 0x40) != 0 )
        v5 = (uint8_t *)(*((uint32_t *)off_11253C + 709) - 8);
      else
        v5 = *(uint8_t **)(*(uint32_t *)v4 + 4);
      *((uint32_t *)v3 + 1) = 0;
      *((uint32_t *)v3 + 2) = 0;
      *v3 = 2;
      v3[12] = v3[12] & 0x7F | (*v5 >> 7 << 7);
      v6 = v3[12] & 0x9F | (32 * (((int)*v5 >> 5) & 3));
      v3[12] = v6;
      v3[12] = v6 & 0xE0 | *v5 & 0x1F;
      v3[13] = v5[1];
      *((uint16_t *)v3 + 7) = v5[2] | (v5[3] << 8);
      *((uint16_t *)v3 + 8) = v5[4] | (v5[5] << 8);
      v7 = v5[6] | (v5[7] << 8);
      *((uint16_t *)v3 + 9) = v7;
      if ( !v7 && (v3[12] & 0x80u) != 0 )
        sub_10DC24(aEp0SetupErrorW);
      v8 = off_11253C;
      v9 = (int ( **)(int, unsigned int))off_112540;
      v10 = *((int ( **)(void *))off_112540 + 3);
      *((uint32_t *)off_11253C + 517) &= ~0x10u;
      v8[516] &= ~0x10u;
      if ( !v10 || !v10(off_112534) )
      {
        v11 = off_11255C;
        v12 = *(uint8_t *)off_11255C;
        v13 = *(uint8_t *)off_11255C;
        if ( (v3[12] & 0x60) != 0 )
        {
LABEL_54:
          if ( v13 == 4 && *v11 != 4 )
LABEL_56:
            sub_1119DC();
          goto LABEL_49;
        }
        v14 = v3[13];
        switch ( v3[13] )
        {
          case 0u:
            if ( *(uint8_t *)off_11255C == 4 )
            {
              v30 = v3[12] & 0x1F;
              if ( v30 == 1 )
                goto LABEL_156;
              if ( v30 != 2 )
                goto LABEL_66;
              v67 = *((uint16_t *)v3 + 8);
              v40 = v67 & 0xF;
              if ( v40 > 5 )
                goto LABEL_156;
              v14 = (v67 >> 7) & 1;
            }
            else
            {
              if ( *((uint16_t *)v3 + 8) )
                goto LABEL_54;
              v30 = v3[12] & 0x1F;
              if ( v30 == 1 )
                goto LABEL_156;
              if ( v30 != 2 )
              {
LABEL_66:
                if ( v30 )
                  goto LABEL_59;
                v31 = off_112874;
                *(uint16_t *)off_112874 = *(uint8_t *)off_112870;
                goto LABEL_68;
              }
              v40 = v3[13];
            }
            if ( sub_111D10(v14, v40) )
            {
              v31 = off_112874;
              *(uint16_t *)off_112874 = 1;
LABEL_68:
              *((uint32_t *)v3 + 1) = v31;
              *((uint16_t *)v3 + 4) = 2;
              *v3 = 4;
              goto LABEL_86;
            }
LABEL_156:
            v31 = off_1129E0;
            *(uint16_t *)off_1129E0 = 0;
            goto LABEL_68;
          case 1u:
            if ( *(uint8_t *)off_11255C != 4 && *((uint16_t *)v3 + 8) )
              goto LABEL_54;
            if ( (v3[12] & 0x1F) != 2 || *((uint16_t *)v3 + 7) )
              goto LABEL_79;
            sub_111D8C((*((uint16_t *)v3 + 8) >> 7) & 1, *((uint16_t *)v3 + 8) & 0xF);
            *v3 = 7;
            if ( v13 == 4 )
              goto LABEL_44;
            goto LABEL_73;
          case 3u:
            if ( *(uint8_t *)off_11255C != 4 && *((uint16_t *)v3 + 8) )
              goto LABEL_54;
            if ( (v3[12] & 0x1F) != 0 )
            {
              if ( (v3[12] & 0x1F) != 2 || *((uint16_t *)v3 + 7) )
              {
LABEL_79:
                *v3 = 7;
                if ( v12 == 4 )
                {
LABEL_60:
                  if ( *v11 != 4 )
                    goto LABEL_56;
                }
                goto LABEL_49;
              }
              sub_111D68((*((uint16_t *)v3 + 8) >> 7) & 1, *((uint16_t *)v3 + 8) & 0xF);
              *v3 = 7;
              if ( v13 != 4 )
                goto LABEL_73;
            }
            else
            {
              v68 = *((uint16_t *)v3 + 7);
              if ( v68 != 2 )
              {
                v39 = v68 == 1;
                *v3 = 7;
LABEL_89:
                if ( v13 != 4 || *v11 == 4 )
                {
                  if ( v39 )
                    break;
                }
                else
                {
                  sub_1119DC();
                  if ( v39 )
                    break;
                }
                goto LABEL_49;
              }
              *(uint8_t *)off_1129E4 = HIBYTE(*((uint16_t *)v3 + 8));
              *v3 = 7;
              if ( v12 != 4 )
                goto LABEL_73;
            }
LABEL_44:
            if ( *v11 == 4 )
              goto LABEL_73;
LABEL_45:
            sub_1119DC();
            break;
          case 5u:
            v34 = *((uint16_t *)v3 + 7);
            *((uint32_t *)off_112878 + 512) = (16 * v34) & 0x7F0 | *((uint32_t *)off_112878 + 512) & 0xFFFFF80F;
            *v3 = 7;
            if ( v34 )
              *v11 = 3;
            else
              *v11 = 2;
            goto LABEL_72;
          case 6u:
            v32 = *((uint16_t *)v3 + 7);
            v33 = v32 >> 8;
            switch ( v32 >> 8 )
            {
              case 1u:
                v41 = (uint8_t *)(*v9)(1, v33);
                if ( !v41 )
                  goto LABEL_54;
                v42 = *v41;
                if ( v42 != 18 || v41[1] != 1 )
                  goto LABEL_54;
                goto LABEL_102;
              case 2u:
                v45 = (uint8_t *)v9[1](0, v33);
                if ( !v45 || *v45 != 9 || v45[1] != 2 )
                  goto LABEL_54;
                v46 = (uint8_t)v45[3];
                v47 = (uint8_t)v45[2];
                *((uint32_t *)v3 + 1) = v45;
                *((uint16_t *)v3 + 4) = v47 | (v46 << 8);
                v48 = *(uint8_t *)off_112870;
                if ( (v45[7] & 0x40) != 0 )
                  v49 = v48 | 1;
                else
                  v49 = v48 & 0xFE;
                *(uint8_t *)off_112870 = v49;
                goto LABEL_103;
              case 3u:
                v44 = (uint8_t *)v9[2]((uint8_t)v32, v33);
                *((uint32_t *)v3 + 1) = v44;
                if ( !v44 )
                  goto LABEL_54;
                *((uint16_t *)v3 + 4) = *v44;
                goto LABEL_103;
              case 4u:
              case 5u:
                goto LABEL_59;
              case 6u:
                v41 = (uint8_t *)(*v9)(6, v33);
                if ( !v41 )
                  goto LABEL_54;
                v42 = *v41;
                if ( v42 != 10 || v41[1] != 6 )
                  goto LABEL_54;
                goto LABEL_102;
              case 0xFu:
                v41 = (uint8_t *)(*v9)(15, v33);
                if ( !v41 || *v41 != 5 || v41[1] != 15 )
                  goto LABEL_54;
                LOWORD(v42) = v41[2];
LABEL_102:
                *((uint16_t *)v3 + 4) = v42;
                *((uint32_t *)v3 + 1) = v41;
LABEL_103:
                v43 = *((uint16_t *)v3 + 9);
                if ( *((uint16_t *)v3 + 4) > v43 )
                  *((uint16_t *)v3 + 4) = v43;
                *v3 = 4;
                break;
              default:
                sub_10DC24("Unknown descriptor: %d", v33);
                goto LABEL_54;
            }
            goto LABEL_86;
          case 8u:
            *((uint32_t *)v3 + 1) = dword_112884;
            *((uint16_t *)v3 + 4) = 2;
            *v3 = 4;
            goto LABEL_86;
          case 9u:
            v39 = sub_1121D4();
            goto LABEL_89;
          case 0xAu:
            if ( *(uint8_t *)off_11255C != 4 )
              goto LABEL_54;
            v37 = off_11287C;
            *v3 = *(uint8_t *)off_11255C;
            v38 = off_112880;
            *((uint16_t *)v3 + 8) = *v37;
            *((uint32_t *)v3 + 1) = v38;
            *((uint16_t *)v3 + 4) = 1;
LABEL_86:
            if ( v13 != 4 )
              goto LABEL_87;
            goto LABEL_152;
          case 0xBu:
            v35 = v9[6];
            if ( !v35 || !v35(*((uint16_t *)v3 + 8), *((uint16_t *)v3 + 7)) )
              goto LABEL_54;
            v36 = off_112880;
            *(uint16_t *)off_11287C = *((uint16_t *)v3 + 8);
            *v36 = *((uint16_t *)v3 + 7);
            *v3 = 7;
LABEL_72:
            if ( v13 != 4 )
              goto LABEL_73;
LABEL_152:
            if ( *v11 != 4 )
              goto LABEL_45;
            break;
          default:
LABEL_59:
            if ( v13 != 4 )
              goto LABEL_49;
            goto LABEL_60;
        }
      }
      v24 = *v3;
      switch ( v24 )
      {
        case 3:
          if ( !*((uint32_t *)v3 + 1) )
            *((uint32_t *)v3 + 1) = dword_112558;
          goto LABEL_50;
        case 4:
LABEL_87:
          sub_111AFC(*((char **)v3 + 1), *((uint16_t *)v3 + 4));
          goto LABEL_50;
        case 7:
LABEL_73:
          sub_111910();
          goto LABEL_50;
      }
LABEL_49:
      *v3 = 0;
      sub_111B64(0, 0x200000, 0);
      sub_111C1C(0, 0x200000, 0);
LABEL_50:
      v25 = *(uint32_t **)v4;
      LODWORD(a1) = *(uint32_t *)off_112544;
      v26 = off_11253C;
      *v25 = dword_112548;
      v25[1] = a1;
LABEL_51:
      v26[709] = v25;
      v26[706] = v26[706];
      v26[704] |= 0x84000000;
      return a1;
    }
    v4 = off_112538;
    v3 = (uint8_t *)off_112534;
    v20 = *(uint32_t **)off_112538;
    if ( (*(uint8_t *)(*(uint32_t *)off_112538 + 3) & 1) == 0 )
    {
      v21 = *(uint8_t *)off_112534;
      switch ( v21 )
      {
        case 2:
          goto LABEL_7;
        case 3:
          v51 = *((uint16_t *)off_112534 + 5);
          v52 = (int *)off_112888;
          v53 = 64 - *(uint16_t *)v20;
          if ( v53 >= (uint16_t)(*((uint16_t *)off_112534 + 4) - v51) )
            LOWORD(v53) = *((uint16_t *)off_112534 + 4) - v51;
          sub_143770((char *)(v51 + *((uint32_t *)off_112534 + 1)), *(char **)off_112888, (uint16_t)v53);
          v54 = *((uint16_t *)v3 + 4);
          v55 = (uint16_t)(v53 + *((uint16_t *)v3 + 5));
          *((uint16_t *)v3 + 5) = v55;
          if ( v54 == v55 )
          {
            v63 = *((void ( **)(uint8_t *))off_1129D4 + 4);
            if ( v63 )
              v63(v3);
            LODWORD(a1) = v2 << 26;
            if ( (v2 & 0x20) == 0 )
            {
              *v3 = 6;
              return a1;
            }
            v64 = *(uint32_t **)v4;
            v65 = *v52;
            v66 = off_1129D0;
            *v64 = dword_1129DC;
            v64[1] = v65;
            v66[709] = v64;
            v66[706] = v66[706];
            v66[704] |= 0x84000000;
            *v3 = 7;
            v66[517] |= 0x10u;
            LODWORD(a1) = sub_111910();
            goto LABEL_19;
          }
          v56 = *(uint32_t **)v4;
          LODWORD(a1) = *v52;
          v57 = off_112878;
          *v56 = dword_11288C;
          v56[1] = a1;
          v57[709] = v56;
          v57[706] = v57[706];
          v57[704] |= 0x84000000;
          break;
        case 5:
          v26 = off_112878;
          *(uint8_t *)off_112534 = 0;
          v25 = *(uint32_t **)v4;
          v50 = off_112888;
          LODWORD(a1) = dword_11288C;
          v26[517] &= ~0x10u;
          v26[516] &= ~0x10u;
          HIDWORD(a1) = *v50;
          *(uint64_t *)v25 = a1;
          goto LABEL_51;
        default:
          v22 = off_11253C;
          LODWORD(a1) = *(uint32_t *)off_112544;
          *v20 = dword_112548;
          v20[1] = a1;
          v22[709] = v20;
          v22[706] = v22[706];
          v22[704] |= 0x84000000;
          break;
      }
      goto LABEL_18;
    }
    if ( *(uint8_t *)off_112534 )
      LODWORD(a1) = sub_111D44(1, 0);
    *v3 = 1;
  }
  return a1;
}
