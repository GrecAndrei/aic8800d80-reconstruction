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

extern uint32_t off_112544;
extern uint32_t off_112874;
extern uint32_t off_112878;
extern uint32_t dword_112554;
extern uint32_t dword_112884;
extern uint32_t off_11287C;
extern uint32_t off_112880;
extern uint32_t off_112890;
extern uint32_t off_1129D4;
extern uint32_t dword_11288C;

// rf_init @ 0x112228, size 1958 bytes
// Doc: rf_state_check_n178 [rf]: Check RF subsystem state (variant n178)
// rf_state_check_n178 [rf]: Check RF subsystem state (variant n178)
int  rf_init(uint64_t a1)
{
  int v1; // r4
  uint8_t *v2; // r5
  void *v3; // r6
  uint8_t *v4; // r3
  uint8_t v5; // r2
  int v6; // r3
  uint32_t *v7; // r3
  uint16_t *v8; // r4
  int ( *v9)(void *); // r1
  uint8_t *v10; // r8
  char v11; // r2
  int v12; // r7
  int v13; // r0
  int v14; // r3
  int v15; // r3
  uint32_t *v16; // r2
  int v17; // r3
  uint32_t *v18; // r3
  uint32_t *v19; // r3
  int v20; // r1
  uint32_t *v21; // r2
  uint32_t *v22; // r3
  int v23; // r3
  uint32_t *v24; // r2
  uint32_t *v25; // r3
  uint32_t *v26; // r2
  int v27; // r0
  uint32_t *v28; // r3
  int v29; // r3
  void *v30; // r3
  unsigned int v31; // r0
  unsigned int v32; // r3
  int v33; // zf
  int v34; // r1
  int ( *v35)(uint32_t, uint32_t); // r3
  uint8_t *v36; // r3
  uint16_t *v37; // r3
  void *v38; // r2
  int v39; // r4
  unsigned int v40; // r1
  uint32_t *v41; // r4
  int v42; // r0
  int *v43; // r8
  int v44; // r7
  int v45; // r3
  int v46; // r7
  uint32_t *v47; // r2
  uint32_t *v48; // r3
  int16_t v49; // r2
  int v50; // r6
  unsigned int v51; // r2
  unsigned int v52; // r1
  uint32_t *v53; // r2
  void ( *v54)(uint8_t *); // r3
  uint32_t *v55; // r2
  int v56; // r0
  uint32_t *v57; // r3
  unsigned int v58; // r0
  int v59; // r0
  void *v60; // r2
  unsigned int v61; // r3
  int16_t v62; // r0

  v1 = HIDWORD(a1);
  if ( (uint32_t)a1 )
  {
    v2 = (uint8_t *)rf_bus_reset_n_4b4;
    v14 = *(uint8_t *)rf_bus_reset_n_4b4;
    if ( v14 == 2 )
    {
      v3 = rf_bus_reset_n_4b0;
      log_printf(rf_state_check_n378);
      goto LABEL_7;
    }
    if ( (a1 & 0x100000000LL) == 0 )
      goto rf_state_check_n154;
    if ( v14 == 4 )
    {
      HIDWORD(a1) = *((uint16_t *)rf_bus_reset_n_4b4 + 4);
      v49 = *((uint16_t *)rf_bus_reset_n_4b4 + 5);
      LODWORD(a1) = (uint16_t)(WORD2(a1) - v49);
      if ( WORD2(a1) == v49 )
      {
        *(uint8_t *)rf_bus_reset_n_4b4 = 5;
        return a1;
      }
      if ( (uint32_t)a1 == 64 )
      {
        v50 = 1;
      }
      else
      {
        if ( (unsigned int)a1 >= 0x40 )
          LODWORD(a1) = 64;
        v50 = 0;
      }
      v51 = (uint16_t)(v49 + a1);
      *((uint16_t *)rf_bus_reset_n_4b4 + 5) = v51;
      if ( HIDWORD(a1) < v51 )
      {
        LODWORD(a1) = log_printf(rf_bus_reset_n_10_29d8);
        WORD2(a1) = *((uint16_t *)v2 + 4);
        v51 = *((uint16_t *)v2 + 5);
      }
      v52 = (uint16_t)(WORD2(a1) - v51);
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
        LODWORD(a1) = bt_cmd_handler(0, 0);
        goto rf_state_check_n154;
      }
      LODWORD(a1) = bt_cmd_handler(*((uint32_t *)v2 + 1) + v51, v52);
rf_state_check_n154:
      if ( (v1 & 0x20) == 0 )
        return a1;
rf_bus_setup_n430:
      if ( *v2 == 6 )
      {
        v26 = *(uint32_t **)rf_bus_reset_n_4b0;
        v27 = *(uint32_t *)off_112544;
        v28 = rf_state_check_n368;
        *v26 = phy_rf_init_n_4f4;
        v26[1] = v27;
        v28[709] = v26;
        v28[706] = v28[706];
        v28[704] |= 0x84000000;
        *v2 = 7;
        v28[517] |= 0x10u;
        LODWORD(a1) = mmio_sync_2();
      }
      return a1;
    }
    if ( v14 != 7 )
      goto rf_state_check_n154;
    v22 = rf_state_check_n368;
    HIDWORD(a1) = rf_bus_reset_n_498_2550;
    LODWORD(a1) = 0;
    *(uint8_t *)rf_bus_reset_n_4b4 = 0;
    v22[517] &= ~0x10u;
    v22[516] &= ~0x10u;
    if ( *(uint8_t *)HIDWORD(a1) )
    {
      v22[513] = (16 * (uint8_t)*(uint8_t *)HIDWORD(a1)) & 0x70 | v22[513] & 0xFFFFFF8F;
      *(uint8_t *)HIDWORD(a1) = 0;
    }
  }
  else
  {
    if ( (BYTE4(a1) & 0x21) == 0x21 )
    {
      v16 = rf_state_check_n368;
      if ( (*((uint32_t *)rf_state_check_n368 + 708) & 0x7F) == 0x40 )
      {
        v17 = *((uint32_t *)rf_state_check_n368 + 708);
        LODWORD(a1) = v17 << 12;
        if ( (v17 & 0x80000) != 0 )
        {
          LODWORD(a1) = *(uint32_t *)off_112544;
          v18 = *(uint32_t **)rf_bus_reset_n_4b0;
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
      v2 = (uint8_t *)rf_bus_reset_n_4b4;
      v15 = *(uint8_t *)rf_bus_reset_n_4b4;
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
        v4 = (uint8_t *)(*((uint32_t *)rf_state_check_n368 + 709) - 8);
      else
        v4 = *(uint8_t **)(*(uint32_t *)v3 + 4);
      *((uint32_t *)v2 + 1) = 0;
      *((uint32_t *)v2 + 2) = 0;
      *v2 = 2;
      v2[12] = v2[12] & 0x7F | (*v4 >> 7 << 7);
      v5 = v2[12] & 0x9F | (32 * (((int)*v4 >> 5) & 3));
      v2[12] = v5;
      v2[12] = v5 & 0xE0 | *v4 & 0x1F;
      v2[13] = v4[1];
      *((uint16_t *)v2 + 7) = v4[2] | (v4[3] << 8);
      *((uint16_t *)v2 + 8) = v4[4] | (v4[5] << 8);
      v6 = v4[6] | (v4[7] << 8);
      *((uint16_t *)v2 + 9) = v6;
      if ( !v6 && (v2[12] & 0x80u) != 0 )
        log_printf(rf_bus_reset_n_154_2894);
      v7 = rf_state_check_n368;
      v8 = rf_state_check_2540;
      v9 = *((int ( **)(void *))rf_state_check_2540 + 3);
      *((uint32_t *)rf_state_check_n368 + 517) &= ~0x10u;
      v7[516] &= ~0x10u;
      if ( v9 && v9(rf_bus_reset_n_4b4) )
      {
rf_state_check_n29e:
        v23 = *v2;
        switch ( v23 )
        {
          case 3:
            if ( !*((uint32_t *)v2 + 1) )
              *((uint32_t *)v2 + 1) = rf_state_check_n384;
            goto rf_state_check_n2cc_24a0;
          case 4:
LABEL_87:
            bt_cmd_handler(*((uint32_t *)v2 + 1), *((uint16_t *)v2 + 4));
            goto rf_state_check_n2cc_24a0;
          case 7:
message_dispatch_n_272:
            mmio_sync_2();
            goto rf_state_check_n2cc_24a0;
        }
rf_state_check_484:
        *v2 = 0;
        unknown_15(0, 0x200000, 0);
        unknown_16(0, 0x200000, 0);
rf_state_check_n2cc_24a0:
        v24 = *(uint32_t **)v3;
        LODWORD(a1) = *(uint32_t *)off_112544;
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
      v11 = *(uint8_t *)unknown_n1;
      v12 = *(uint8_t *)unknown_n1;
      if ( (v2[12] & 0x60) != 0 )
      {
rf_state_check_n342:
        if ( v12 == 4 && *v10 != 4 )
LABEL_56:
          table_lookup_wrapper();
        goto rf_state_check_484;
      }
      v13 = v2[13];
      switch ( v2[13] )
      {
        case 0u:
          if ( *(uint8_t *)unknown_n1 == 4 )
          {
            v29 = v2[12] & 0x1F;
            if ( v29 != 1 )
            {
              if ( v29 != 2 )
                goto LABEL_66;
              v58 = *((uint16_t *)v2 + 8);
              v40 = v58 & 0xF;
              if ( v40 <= 5 )
              {
                v13 = (v58 >> 7) & 1;
LABEL_97:
                if ( mmio_bank_read(v13, v40) )
                {
                  v30 = off_112874;
                  *(uint16_t *)off_112874 = 1;
                  goto rf_fault_dump_n_492;
                }
              }
            }
          }
          else
          {
            if ( *((uint16_t *)v2 + 8) )
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
                *(uint16_t *)off_112874 = *(uint8_t *)rf_bus_reset_n_178;
rf_fault_dump_n_492:
                *((uint32_t *)v2 + 1) = v30;
                *((uint16_t *)v2 + 4) = 2;
                *v2 = 4;
LABEL_86:
                if ( v12 != 4 )
                  goto LABEL_87;
LABEL_128:
                if ( *v10 == 4 )
                  goto rf_state_check_n29e;
rf_state_check_46e:
                table_lookup_wrapper();
                goto rf_state_check_n29e;
              }
              v40 = v2[13];
              goto LABEL_97;
            }
          }
          v30 = rf_bus_reset_n_8_9e0;
          *(uint16_t *)rf_bus_reset_n_8_9e0 = 0;
          goto rf_fault_dump_n_492;
        case 1u:
          if ( *(uint8_t *)unknown_n1 != 4 && *((uint16_t *)v2 + 8) )
            goto rf_state_check_n342;
          if ( (v2[12] & 0x1F) != 2 || *((uint16_t *)v2 + 7) )
            goto LABEL_79;
          flash_write_data((int *)((*((uint16_t *)v2 + 8) >> 7) & 1), *((uint16_t *)v2 + 8) & 0xF);
          *v2 = 7;
          if ( v12 == 4 )
            goto rf_state_check_n290;
          goto message_dispatch_n_272;
        case 3u:
          if ( *(uint8_t *)unknown_n1 != 4 && *((uint16_t *)v2 + 8) )
            goto rf_state_check_n342;
          if ( (v2[12] & 0x1F) != 0 )
          {
            if ( (v2[12] & 0x1F) != 2 || *((uint16_t *)v2 + 7) )
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
            flash_erase_area((int *)((*((uint16_t *)v2 + 8) >> 7) & 1), *((uint16_t *)v2 + 8) & 0xF);
            *v2 = 7;
            if ( v12 != 4 )
              goto message_dispatch_n_272;
          }
          else
          {
            v59 = *((uint16_t *)v2 + 7);
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
                table_lookup_wrapper();
                if ( v39 )
                  goto rf_state_check_n29e;
              }
              goto rf_state_check_484;
            }
            *(uint8_t *)rf_bus_reset_n_4 = HIBYTE(*((uint16_t *)v2 + 8));
            *v2 = 7;
            if ( v11 != 4 )
              goto message_dispatch_n_272;
          }
rf_state_check_n290:
          if ( *v10 == 4 )
            goto message_dispatch_n_272;
          goto rf_state_check_46e;
        case 5u:
          v34 = *((uint16_t *)v2 + 7);
          *((uint32_t *)off_112878 + 512) = (16 * v34) & 0x7F0 | *((uint32_t *)off_112878 + 512) & 0xFFFFF80F;
          *v2 = 7;
          if ( v34 )
            *v10 = 3;
          else
            *v10 = 2;
          goto LABEL_72;
        case 6u:
          v31 = *((uint16_t *)v2 + 7);
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
              *((uint8_t *)v8 + 308) = (uint8_t)v60;
              v61 = *(uint8_t *)(v12 + 165);
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
                  *((uint8_t *)v8 + 309) = v61;
                  *((uint8_t *)v8 + 312) = 0;
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
              log_printf(dword_112554);
              goto rf_state_check_n342;
          }
        case 8u:
          *((uint32_t *)v2 + 1) = dword_112884;
          *((uint16_t *)v2 + 4) = 2;
          *v2 = 4;
          goto LABEL_86;
        case 9u:
          v39 = arg_store();
          goto LABEL_89;
        case 0xAu:
          if ( *(uint8_t *)unknown_n1 != 4 )
            goto rf_state_check_n342;
          v37 = off_11287C;
          *v2 = *(uint8_t *)unknown_n1;
          v38 = off_112880;
          *((uint16_t *)v2 + 8) = *v37;
          *((uint32_t *)v2 + 1) = v38;
          *((uint16_t *)v2 + 4) = 1;
          goto LABEL_86;
        case 0xBu:
          v35 = *((int ( **)(uint32_t, uint32_t))v8 + 6);
          if ( !v35 || !v35(*((uint16_t *)v2 + 8), *((uint16_t *)v2 + 7)) )
            goto rf_state_check_n342;
          v36 = off_112880;
          *(uint16_t *)off_11287C = *((uint16_t *)v2 + 8);
          *v36 = *((uint16_t *)v2 + 7);
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
      v2 = (uint8_t *)rf_bus_reset_n_4b4;
      if ( *(uint8_t *)rf_bus_reset_n_4b4 )
      {
        flash_erase_main((int *)1, 0);
        v3 = off_112890;
        goto LABEL_7;
      }
      goto LABEL_6;
    }
    v3 = rf_bus_reset_n_4b0;
    v2 = (uint8_t *)rf_bus_reset_n_4b4;
    v19 = *(uint32_t **)rf_bus_reset_n_4b0;
    if ( (*(uint8_t *)(*(uint32_t *)rf_bus_reset_n_4b0 + 3) & 1) == 0 )
    {
      v20 = *(uint8_t *)rf_bus_reset_n_4b4;
      switch ( v20 )
      {
        case 2:
          goto LABEL_7;
        case 3:
          v42 = *((uint16_t *)rf_bus_reset_n_4b4 + 5);
          v43 = (int *)rf_bus_reset_n_160;
          v44 = 64 - *(uint16_t *)v19;
          if ( v44 >= (uint16_t)(*((uint16_t *)rf_bus_reset_n_4b4 + 4) - v42) )
            LOWORD(v44) = *((uint16_t *)rf_bus_reset_n_4b4 + 4) - v42;
          memcpy(v42 + *((uint32_t *)rf_bus_reset_n_4b4 + 1), *(uint32_t *)rf_bus_reset_n_160, (uint16_t)v44);
          v45 = *((uint16_t *)v2 + 4);
          v46 = (uint16_t)(v44 + *((uint16_t *)v2 + 5));
          *((uint16_t *)v2 + 5) = v46;
          if ( v45 == v46 )
          {
            v54 = *((void ( **)(uint8_t *))off_1129D4 + 4);
            if ( v54 )
              v54(v2);
            LODWORD(a1) = v1 << 26;
            if ( (v1 & 0x20) == 0 )
            {
              *v2 = 6;
              return a1;
            }
            v55 = *(uint32_t **)v3;
            v56 = *v43;
            v57 = rf_bus_reset_n_18;
            *v55 = rf_bus_reset_n_c;
            v55[1] = v56;
            v57[709] = v55;
            v57[706] = v57[706];
            v57[704] |= 0x84000000;
            *v2 = 7;
            v57[517] |= 0x10u;
            LODWORD(a1) = mmio_sync_2();
            goto rf_bus_setup_n430;
          }
          v47 = *(uint32_t **)v3;
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
          *(uint8_t *)rf_bus_reset_n_4b4 = 0;
          v24 = *(uint32_t **)v3;
          v41 = rf_bus_reset_n_160;
          LODWORD(a1) = dword_11288C;
          v25[517] &= ~0x10u;
          v25[516] &= ~0x10u;
          HIDWORD(a1) = *v41;
          *(uint64_t *)v24 = a1;
          goto LABEL_51;
        default:
          v21 = rf_state_check_n368;
          LODWORD(a1) = *(uint32_t *)off_112544;
          *v19 = phy_rf_init_n_4f4;
          v19[1] = a1;
          v21[709] = v19;
          v21[706] = v21[706];
          v21[704] |= 0x84000000;
          break;
      }
      goto rf_state_check_n154;
    }
    if ( *(uint8_t *)rf_bus_reset_n_4b4 )
      LODWORD(a1) = flash_erase_main((int *)1, 0);
    *v2 = 1;
  }
  return a1;
}

