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

extern uint32_t dword_1123A8;
extern uint32_t off_1123AC;
extern uint32_t off_11239C;
extern uint32_t dword_1123B4;
extern uint32_t off_1123B8;
extern uint32_t off_11283C;
extern uint32_t off_1126D4;
extern uint32_t dword_1123B0;
extern uint32_t off_1126EC;
extern uint32_t off_1126E4;

// rx_parse_packet @ 0x112084, size 1958 bytes
// Doc: rf_bus_reset_n_1e4 [rf]: Reset RF bus and re-sync channel window via 0x40 wrap comparison
// rf_bus_reset_n_1e4 [rf]: Reset RF bus and re-sync channel window via 0x40 wrap comparison
int  rx_parse_packet(uint64_t a1)
{
  int v1; // r4
  uint8_t *v2; // r5
  void *v3; // r6
  uint8_t *v4; // r3
  uint8_t v5; // r2
  int v6; // r3
  uint32_t *v7; // r3
  uint32_t *v8; // r4
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
  int v31; // r1
  int ( *v32)(uint32_t, uint32_t); // r3
  uint8_t *v33; // r3
  uint16_t *v34; // r3
  void *v35; // r2
  int v36; // r4
  unsigned int v37; // r1
  uint32_t *v38; // r4
  int v39; // r0
  int *v40; // r8
  int v41; // r7
  int v42; // r3
  int v43; // r7
  uint32_t *v44; // r2
  uint32_t *v45; // r3
  int16_t v46; // r2
  int v47; // r6
  unsigned int v48; // r2
  unsigned int v49; // r1
  uint32_t *v50; // r2
  void ( *v51)(uint8_t *); // r3
  uint32_t *v52; // r2
  int v53; // r0
  uint32_t *v54; // r3
  unsigned int v55; // r0
  int v56; // r0

  v1 = HIDWORD(a1);
  if ( (uint32_t)a1 )
  {
    v2 = (uint8_t *)rf_state_check_390;
    v14 = *(uint8_t *)rf_state_check_390;
    if ( v14 == 2 )
    {
      v3 = rf_bus_reset_4b0;
      printf_wrapper(dword_1123A8);
      goto rf_state_check_n80;
    }
    if ( (a1 & 0x100000000LL) == 0 )
      goto LABEL_18;
    if ( v14 == 4 )
    {
      HIDWORD(a1) = *((uint16_t *)rf_state_check_390 + 4);
      v46 = *((uint16_t *)rf_state_check_390 + 5);
      LODWORD(a1) = (uint16_t)(WORD2(a1) - v46);
      if ( WORD2(a1) == v46 )
      {
        *(uint8_t *)rf_state_check_390 = 5;
        return a1;
      }
      if ( (uint32_t)a1 == 64 )
      {
        v47 = 1;
      }
      else
      {
        if ( (unsigned int)a1 >= 0x40 )
          LODWORD(a1) = 64;
        v47 = 0;
      }
      v48 = (uint16_t)(v46 + a1);
      *((uint16_t *)rf_state_check_390 + 5) = v48;
      if ( HIDWORD(a1) < v48 )
      {
        LODWORD(a1) = printf_wrapper(rf_bus_reset_n_10);
        WORD2(a1) = *((uint16_t *)v2 + 4);
        v48 = *((uint16_t *)v2 + 5);
      }
      v49 = (uint16_t)(WORD2(a1) - v48);
      if ( v49 > 0x40 )
      {
        v49 = 64;
      }
      else if ( !v49 )
      {
        if ( !v47 )
        {
          v50 = rf_bus_reset_n18_282c;
          *v2 = 5;
          v50[516] |= 0x10u;
          return a1;
        }
        LODWORD(a1) = tx_pkt_set_len(0, 0);
        goto LABEL_18;
      }
      LODWORD(a1) = tx_pkt_set_len(*((uint32_t *)v2 + 1) + v48, v49);
LABEL_18:
      if ( (v1 & 0x20) == 0 )
        return a1;
LABEL_19:
      if ( *v2 == 6 )
      {
        v26 = *(uint32_t **)rf_bus_reset_4b0;
        v27 = *(uint32_t *)rf_state_check_n370;
        v28 = rf_state_machine_poll;
        *v26 = rf_bus_reset_n_4a0_23a4;
        v26[1] = v27;
        v28[709] = v26;
        v28[706] = v28[706];
        v28[704] |= 0x84000000;
        *v2 = 7;
        v28[517] |= 0x10u;
        LODWORD(a1) = tx_pkt_start();
      }
      return a1;
    }
    if ( v14 != 7 )
      goto LABEL_18;
    v22 = rf_state_machine_poll;
    HIDWORD(a1) = off_1123AC;
    LODWORD(a1) = 0;
    *(uint8_t *)rf_state_check_390 = 0;
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
      v16 = rf_state_machine_poll;
      if ( (*((uint32_t *)rf_state_machine_poll + 708) & 0x7F) == 0x40 )
      {
        v17 = *((uint32_t *)rf_state_machine_poll + 708);
        LODWORD(a1) = v17 << 12;
        if ( (v17 & 0x80000) != 0 )
        {
          LODWORD(a1) = *(uint32_t *)rf_state_check_n370;
          v18 = *(uint32_t **)rf_bus_reset_4b0;
          *v18 = rf_bus_reset_n_4a0_23a4;
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
      v2 = (uint8_t *)rf_state_check_390;
      v15 = *(uint8_t *)rf_state_check_390;
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
      v3 = rf_bus_reset_4b0;
rf_state_check_n80:
      if ( (v1 & 0x40) != 0 )
        v4 = (uint8_t *)(*((uint32_t *)rf_state_machine_poll + 709) - 8);
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
        printf_wrapper(rf_bus_reset_n_154);
      v7 = rf_state_machine_poll;
      v8 = off_11239C;
      v9 = *((int ( **)(void *))off_11239C + 3);
      *((uint32_t *)rf_state_machine_poll + 517) &= ~0x10u;
      v7[516] &= ~0x10u;
      if ( v9 && v9(rf_state_check_390) )
      {
rf_state_check_n29e:
        v23 = *v2;
        switch ( v23 )
        {
          case 3:
            if ( !*((uint32_t *)v2 + 1) )
              *((uint32_t *)v2 + 1) = dword_1123B4;
            goto rf_state_check_n2cc;
          case 4:
LABEL_87:
            tx_pkt_set_len(*((uint32_t *)v2 + 1), *((uint16_t *)v2 + 4));
            goto rf_state_check_n2cc;
          case 7:
LABEL_73:
            tx_pkt_start();
            goto rf_state_check_n2cc;
        }
LABEL_49:
        *v2 = 0;
        tx_desc_hw_config(0, 0x200000, 0);
        rx_desc_hw_config(0, 0x200000, 0);
rf_state_check_n2cc:
        v24 = *(uint32_t **)v3;
        LODWORD(a1) = *(uint32_t *)rf_state_check_n370;
        v25 = rf_state_machine_poll;
        *v24 = rf_bus_reset_n_4a0_23a4;
        v24[1] = a1;
rf_state_check_30a:
        v25[709] = v24;
        v25[706] = v25[706];
        v25[704] |= 0x84000000;
        return a1;
      }
      v10 = off_1123B8;
      v11 = *(uint8_t *)off_1123B8;
      v12 = *(uint8_t *)off_1123B8;
      if ( (v2[12] & 0x60) != 0 )
      {
LABEL_54:
        if ( v12 == 4 && *v10 != 4 )
LABEL_56:
          ll_hdr_init();
        goto LABEL_49;
      }
      v13 = v2[13];
      switch ( v2[13] )
      {
        case 0u:
          if ( *(uint8_t *)off_1123B8 == 4 )
          {
            v29 = v2[12] & 0x1F;
            if ( v29 != 1 )
            {
              if ( v29 != 2 )
                goto LABEL_66;
              v55 = *((uint16_t *)v2 + 8);
              v37 = v55 & 0xF;
              if ( v37 <= 5 )
              {
                v13 = (v55 >> 7) & 1;
LABEL_97:
                if ( rf_reg_read(v13, v37) )
                {
                  v30 = rf_bus_reset_n_174;
                  *(uint16_t *)rf_bus_reset_n_174 = 1;
                  goto rf_bus_reset_n_44c;
                }
              }
            }
          }
          else
          {
            if ( *((uint16_t *)v2 + 8) )
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
                  goto rf_bus_reset_n_484;
                }
                v30 = rf_bus_reset_n_174;
                *(uint16_t *)rf_bus_reset_n_174 = *(uint8_t *)rf_bus_reset_n_178;
rf_bus_reset_n_44c:
                *((uint32_t *)v2 + 1) = v30;
                *((uint16_t *)v2 + 4) = 2;
                *v2 = 4;
LABEL_86:
                if ( v12 != 4 )
                  goto LABEL_87;
rf_bus_reset_n_a4_27a0:
                if ( *v10 == 4 )
                  goto rf_state_check_n29e;
LABEL_45:
                ll_hdr_init();
                goto rf_state_check_n29e;
              }
              v37 = v2[13];
              goto LABEL_97;
            }
          }
          v30 = off_11283C;
          *(uint16_t *)off_11283C = 0;
          goto rf_bus_reset_n_44c;
        case 1u:
          if ( *(uint8_t *)off_1123B8 != 4 && *((uint16_t *)v2 + 8) )
            goto LABEL_54;
          if ( (v2[12] & 0x1F) != 2 || *((uint16_t *)v2 + 7) )
            goto LABEL_79;
          rf_reg_write_c((int *)((*((uint16_t *)v2 + 8) >> 7) & 1), *((uint16_t *)v2 + 8) & 0xF);
          *v2 = 7;
          if ( v12 == 4 )
            goto rf_state_check_n290;
          goto LABEL_73;
        case 3u:
          if ( *(uint8_t *)off_1123B8 != 4 && *((uint16_t *)v2 + 8) )
            goto LABEL_54;
          if ( (v2[12] & 0x1F) != 0 )
          {
            if ( (v2[12] & 0x1F) != 2 || *((uint16_t *)v2 + 7) )
            {
LABEL_79:
              *v2 = 7;
              if ( v11 == 4 )
              {
rf_bus_reset_n_484:
                if ( *v10 != 4 )
                  goto LABEL_56;
              }
              goto LABEL_49;
            }
            rf_reg_write_b((int *)((*((uint16_t *)v2 + 8) >> 7) & 1), *((uint16_t *)v2 + 8) & 0xF);
            *v2 = 7;
            if ( v12 != 4 )
              goto LABEL_73;
          }
          else
          {
            v56 = *((uint16_t *)v2 + 7);
            if ( v56 != 2 )
            {
              v36 = v56 == 1;
              *v2 = 7;
LABEL_89:
              if ( v12 != 4 || *v10 == 4 )
              {
                if ( v36 )
                  goto rf_state_check_n29e;
              }
              else
              {
                ll_hdr_init();
                if ( v36 )
                  goto rf_state_check_n29e;
              }
              goto LABEL_49;
            }
            *(uint8_t *)rf_bus_reset_n_4 = HIBYTE(*((uint16_t *)v2 + 8));
            *v2 = 7;
            if ( v11 != 4 )
              goto LABEL_73;
          }
rf_state_check_n290:
          if ( *v10 == 4 )
            goto LABEL_73;
          goto LABEL_45;
        case 5u:
          v31 = *((uint16_t *)v2 + 7);
          *((uint32_t *)off_1126D4 + 512) = (16 * v31) & 0x7F0 | *((uint32_t *)off_1126D4 + 512) & 0xFFFFF80F;
          *v2 = 7;
          if ( v31 )
            *v10 = 3;
          else
            *v10 = 2;
          goto LABEL_72;
        case 6u:
          switch ( HIBYTE(*((uint16_t *)v2 + 7)) )
          {
            case 1u:
              rf_calibrate();
              *(uint8_t *)v8 = (uint8_t)v2;
              hci_evt_send(v8);
              LODWORD(a1) = ((int ( *)(int, int, int))hci_evt_alloc_send)(5130, 13, 5);
              return a1;
            case 2u:
              JUMPOUT(0x1325D6);
            default:
              printf_wrapper(dword_1123B0);
              goto LABEL_54;
          }
        case 8u:
          *((uint32_t *)v2 + 1) = rf_bus_reset_n_164_26e0;
          *((uint16_t *)v2 + 4) = 2;
          *v2 = 4;
          goto LABEL_86;
        case 9u:
          v36 = hw_status_update();
          goto LABEL_89;
        case 0xAu:
          if ( *(uint8_t *)off_1123B8 != 4 )
            goto LABEL_54;
          v34 = rf_bus_reset_n_16c;
          *v2 = *(uint8_t *)off_1123B8;
          v35 = rf_bus_reset_n_168;
          *((uint16_t *)v2 + 8) = *v34;
          *((uint32_t *)v2 + 1) = v35;
          *((uint16_t *)v2 + 4) = 1;
          goto LABEL_86;
        case 0xBu:
          v32 = (int ( *)(uint32_t, uint32_t))v8[6];
          if ( !v32 || !v32(*((uint16_t *)v2 + 8), *((uint16_t *)v2 + 7)) )
            goto LABEL_54;
          v33 = rf_bus_reset_n_168;
          *(uint16_t *)rf_bus_reset_n_16c = *((uint16_t *)v2 + 8);
          *v33 = *((uint16_t *)v2 + 7);
          *v2 = 7;
LABEL_72:
          if ( v12 != 4 )
            goto LABEL_73;
          goto rf_bus_reset_n_a4_27a0;
        default:
          goto LABEL_59;
      }
    }
    if ( (a1 & 0x800000000LL) != 0 )
    {
      v2 = (uint8_t *)rf_state_check_390;
      if ( *(uint8_t *)rf_state_check_390 )
      {
        rf_reg_write((int *)1, 0);
        v3 = off_1126EC;
        goto rf_state_check_n80;
      }
      goto LABEL_6;
    }
    v3 = rf_bus_reset_4b0;
    v2 = (uint8_t *)rf_state_check_390;
    v19 = *(uint32_t **)rf_bus_reset_4b0;
    if ( (*(uint8_t *)(*(uint32_t *)rf_bus_reset_4b0 + 3) & 1) == 0 )
    {
      v20 = *(uint8_t *)rf_state_check_390;
      switch ( v20 )
      {
        case 2:
          goto rf_state_check_n80;
        case 3:
          v39 = *((uint16_t *)rf_state_check_390 + 5);
          v40 = (int *)off_1126E4;
          v41 = 64 - *(uint16_t *)v19;
          if ( v41 >= (uint16_t)(*((uint16_t *)rf_state_check_390 + 4) - v39) )
            LOWORD(v41) = *((uint16_t *)rf_state_check_390 + 4) - v39;
          memcpy_aligned(v39 + *((uint32_t *)rf_state_check_390 + 1), *(uint32_t *)off_1126E4, (uint16_t)v41);
          v42 = *((uint16_t *)v2 + 4);
          v43 = (uint16_t)(v41 + *((uint16_t *)v2 + 5));
          *((uint16_t *)v2 + 5) = v43;
          if ( v42 == v43 )
          {
            v51 = *((void ( **)(uint8_t *))rf_bus_reset_n_14 + 4);
            if ( v51 )
              v51(v2);
            LODWORD(a1) = v1 << 26;
            if ( (v1 & 0x20) == 0 )
            {
              *v2 = 6;
              return a1;
            }
            v52 = *(uint32_t **)v3;
            v53 = *v40;
            v54 = rf_bus_reset_n18_282c;
            *v52 = rf_bus_reset_n_c_2838;
            v52[1] = v53;
            v54[709] = v52;
            v54[706] = v54[706];
            v54[704] |= 0x84000000;
            *v2 = 7;
            v54[517] |= 0x10u;
            LODWORD(a1) = tx_pkt_start();
            goto LABEL_19;
          }
          v44 = *(uint32_t **)v3;
          LODWORD(a1) = *v40;
          v45 = off_1126D4;
          *v44 = rf_bus_reset_n_15c;
          v44[1] = a1;
          v45[709] = v44;
          v45[706] = v45[706];
          v45[704] |= 0x84000000;
          break;
        case 5:
          v25 = off_1126D4;
          *(uint8_t *)rf_state_check_390 = 0;
          v24 = *(uint32_t **)v3;
          v38 = off_1126E4;
          LODWORD(a1) = rf_bus_reset_n_15c;
          v25[517] &= ~0x10u;
          v25[516] &= ~0x10u;
          HIDWORD(a1) = *v38;
          *(uint64_t *)v24 = a1;
          goto rf_state_check_30a;
        default:
          v21 = rf_state_machine_poll;
          LODWORD(a1) = *(uint32_t *)rf_state_check_n370;
          *v19 = rf_bus_reset_n_4a0_23a4;
          v19[1] = a1;
          v21[709] = v19;
          v21[706] = v21[706];
          v21[704] |= 0x84000000;
          break;
      }
      goto LABEL_18;
    }
    if ( *(uint8_t *)rf_state_check_390 )
      LODWORD(a1) = rf_reg_write((int *)1, 0);
    *v2 = 1;
  }
  return a1;
}

