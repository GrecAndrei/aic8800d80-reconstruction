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


extern uint32_t dword_13A240;
extern uint32_t dword_13A244;
extern uint32_t dword_13A24C;
extern uint32_t dword_13A250;
extern uint32_t dword_13A3E8;
extern uint32_t off_13A238;
extern uint32_t off_13A23C;
extern uint32_t off_13A248;
extern uint32_t off_13A254;
extern uint32_t off_13A3E4;
extern uint32_t off_13A3EC;

// tx_check_allow @ 0x139f5c, size 1160 bytes
int  tx_check_allow(int a1)
{
  unsigned int v1; // r7
  int v2; // r5
  int v3; // r3
  uint8_t *v4; // r4
  int v5; // r6
  int v6; // r1
  uint8_t *v8; // r6
  uint16_t v9; // r8
  uint16_t v10; // r3
  int v11; // r11
  int v12; // r9
  char v13; // r3
  uint16_t v14; // r3
  int v15; // r10
  int v16; // r3
  int v17; // r1
  int v18; // r1
  int v19; // r12
  int v20; // r2
  int v21; // r1
  int v22; // r0
  uint16_t v23; // r1
  uint8_t **v24; // r11
  int v25; // r1
  int v26; // r1
  int v27; // r1
  int v28; // r1
  int v29; // r3
  uint16_t *v30; // r1
  uint8_t *v31; // r9
  int v32; // r0
  uint16_t v33; // r3
  char v34; // r0
  int v35; // r1
  int v36; // r0
  uint16_t v37; // r1
  int v38; // r7
  int v39; // r1
  int v40; // r2
  int v41; // r1
  int v42; // r1
  uint16_t v43; // r1
  int v44; // r1
  int v45; // r1
  uint16_t *v46; // r10
  BOOL v47; // r0
  int v48; // [sp+0h] [bp-Ch]
  unsigned int v49; // [sp+0h] [bp-Ch]
  int v50; // [sp+0h] [bp-Ch]
  int v51; // [sp+4h] [bp-8h]
  int v52; // [sp+4h] [bp-8h]
  int v53; // [sp+4h] [bp-8h]

  v1 = *(uint32_t *)(a1 + 84);
  v2 = a1;
  if ( (v1 & 0x2000) == 0 )
  {
    v3 = *((uint8_t *)off_13A238 + 16);
    if ( v3 != 255 )
    {
      v4 = off_13A23C;
LABEL_4:
      v4[10] = v3;
      rf_rssi_calibrate(v2, 128);
      v5 = 1;
      goto LABEL_5;
    }
LABEL_35:
    v5 = 0;
    goto LABEL_5;
  }
  v4 = off_13A23C;
  v8 = *(uint8_t **)(*(uint32_t *)(a1 + 28) + 8);
  v9 = *(uint16_t *)v8;
  *(uint16_t *)off_13A23C = *(uint16_t *)v8;
  *(uint32_t *)(a1 + 96) = 0;
  v4[9] = -1;
  v4[10] = -1;
  v10 = *((uint16_t *)v8 + 11);
  *((uint16_t *)v4 + 1) = v10;
  v4[48] = 0;
  *((uint16_t *)v4 + 2) = v10 >> 4;
  v4[6] = v10 & 0xF;
  if ( (v9 & 0x88) == 0x88 )
  {
    v11 = v9 & 0x300;
    if ( v11 == 768 )
      v33 = *((uint16_t *)v8 + 15);
    else
      v33 = *((uint16_t *)v8 + 12);
    v4[7] = v33 & 7;
  }
  else
  {
    v4[7] = 0;
    v11 = v9 & 0x300;
  }
  v12 = v9 & 0xFC;
  if ( v11 == 768 )
    v13 = 30;
  else
    v13 = 24;
  if ( v12 == 136 )
    v13 += 2;
  if ( v9 < 0 )
    v13 += 4;
  v4[8] = v13;
  if ( (v8[4] & 1) != 0 )
    v4[48] = 8;
  if ( (v9 & 0x100) != 0 )
  {
    *((uint16_t *)v4 + 18) = *((uint16_t *)v8 + 8);
    *((uint16_t *)v4 + 19) = *((uint16_t *)v8 + 9);
    *((uint16_t *)v4 + 20) = *((uint16_t *)v8 + 10);
    v14 = *(uint16_t *)v8;
    if ( (*(uint16_t *)v8 & 0x200) != 0 )
    {
LABEL_19:
      if ( (v14 & 0x100) != 0 )
      {
        *((uint16_t *)v4 + 21) = *((uint16_t *)v8 + 12);
        *((uint16_t *)v4 + 22) = *((uint16_t *)v8 + 13);
        *((uint16_t *)v4 + 23) = *((uint16_t *)v8 + 14);
      }
      else
      {
        *((uint16_t *)v4 + 21) = *((uint16_t *)v8 + 8);
        *((uint16_t *)v4 + 22) = *((uint16_t *)v8 + 9);
        *((uint16_t *)v4 + 23) = *((uint16_t *)v8 + 10);
      }
      if ( (v1 & 0x2000000) != 0 )
        goto LABEL_22;
LABEL_38:
      if ( v4[115]
        && (v1 & 0x200) == 0
        && *((uint16_t *)v4 + 54) == *((uint16_t *)v8 + 5)
        && *((uint16_t *)v4 + 55) == *((uint16_t *)v8 + 6)
        && *((uint16_t *)v4 + 56) == *((uint16_t *)v8 + 7) )
      {
        v4[114] = (*(uint16_t *)v8 & 0x1400) == 4096;
      }
      if ( (v9 & 0xC) != 0 )
        goto LABEL_56;
      v29 = *((uint16_t *)v8 + 11);
      if ( (*(uint16_t *)v8 & 0x800) != 0 )
      {
        v30 = (uint16_t *)off_13A3E4;
        v31 = v8 + 10;
        if ( *((uint16_t *)v4 + 51) == v29 )
        {
          v49 = off_13A3E4;
          if ( !memcmp((unsigned int)(v8 + 10), off_13A3E4, 6u) )
            goto LABEL_34;
          v9 = *(uint16_t *)v4;
          LOWORD(v29) = *((uint16_t *)v8 + 11);
          v30 = (uint16_t *)v49;
        }
      }
      else
      {
        v30 = off_13A248;
        v31 = v8 + 10;
      }
      v32 = *(uint32_t *)v31;
      v30[2] = *((uint16_t *)v31 + 2);
      *((uint16_t *)v4 + 51) = v29;
      *((uint32_t *)v4 + 24) = v32;
      if ( (v9 & 0x4000) != 0 && ((v1 & 0x7C) != 4 || !tx_packet_ack((int)v8, v1)) )
LABEL_56:
        v5 = rand_gen_u16(v8);
      else
        v5 = tx_send_packet_1(v2, 255);
      goto LABEL_57;
    }
  }
  else
  {
    *((uint16_t *)v4 + 18) = *((uint16_t *)v8 + 2);
    *((uint16_t *)v4 + 19) = *((uint16_t *)v8 + 3);
    *((uint16_t *)v4 + 20) = *((uint16_t *)v8 + 4);
    v14 = *(uint16_t *)v8;
    if ( (*(uint16_t *)v8 & 0x200) != 0 )
      goto LABEL_19;
  }
  *((uint16_t *)v4 + 21) = *((uint16_t *)v8 + 5);
  *((uint16_t *)v4 + 22) = *((uint16_t *)v8 + 6);
  *((uint16_t *)v4 + 23) = *((uint16_t *)v8 + 7);
  if ( (v1 & 0x2000000) == 0 )
    goto LABEL_38;
LABEL_22:
  v15 = dword_13A250;
  v16 = (uint8_t)((v1 >> 15) - 16);
  v17 = dword_13A250 + 696 * v16;
  if ( !*(uint8_t *)(v17 + 37) )
    goto LABEL_34;
  v19 = *(uint8_t *)(v18 + 34);
  v20 = dword_13A244;
  v21 = *(uint32_t *)(v18 + 184);
  v4[9] = v16;
  *((uint32_t *)v4 + 6) = v1;
  v22 = *(uint8_t *)(v20 + 1320 * v19 + 106);
  v4[10] = v19;
  v48 = v21;
  if ( v22 != 2 || (v4[36] & 1) != 0 )
  {
    v23 = v9;
  }
  else
  {
    v34 = fifo_write((int *)dword_13A24C);
    v23 = *(uint16_t *)v4;
    v16 = (uint8_t)((v1 >> 15) - 16);
    v20 = dword_13A244;
    v4[11] = v34;
  }
  if ( v11 == 768 )
    *(uint32_t *)(v2 + 96) |= 4u;
  if ( (v23 & 0x4000) != 0 )
  {
    v51 = v16;
    a1 = tx_packet_ack((int)v8, *((uint32_t *)v4 + 6));
    v16 = v51;
    v20 = dword_13A3E8;
    if ( !a1 )
      goto LABEL_34;
  }
  v24 = (uint8_t **)off_13A254;
  if ( **(uint8_t **)off_13A254 == 1 && !LOBYTE(((uint32_t *)(uintptr_t)off_13A3EC)[103]) )
  {
    v39 = v9 & 0xC;
    if ( v39 == 8 )
    {
      if ( !*(uint8_t *)(v20 + 1320 * (uint8_t)v4[10] + 106) )
      {
        v53 = v16;
        a1 = scan_parse_report((char *)v8, v1, v16);
        v16 = v53;
        if ( !a1 )
          goto LABEL_34;
      }
      goto LABEL_83;
    }
LABEL_30:
    if ( *(uint8_t *)(v15 + 696 * v16 + 669) > 1u
      || !v48
      || (unsigned int)*(uint8_t *)(v48 + 96) - 1 > 1 )
    {
      goto LABEL_31;
    }
    goto LABEL_72;
  }
  v25 = v9 & 0xC;
  if ( v25 != 8 )
    goto LABEL_30;
LABEL_83:
  v52 = v16;
  scan_parse_response((char *)v8, v1, *(uint16_t *)(v2 + 48));
  v16 = v52;
  if ( *(uint8_t *)(v15 + 696 * v52 + 669) > 1u || !v48 || (unsigned int)*(uint8_t *)(v48 + 96) - 1 > 1 )
    goto LABEL_84;
  v45 = 8;
LABEL_72:
  if ( (v9 & 0x4000) != 0 && (v4[36] & 1) == 0 )
    *(uint8_t *)(v15 + 696 * v16 + 669) = 2;
LABEL_31:
  if ( v26 == 4 )
  {
    if ( v12 == 132 )
      rf_get_chan_param(v16, (int)v8);
    goto LABEL_34;
  }
  if ( v27 != 8 )
  {
    if ( v28 )
      goto LABEL_34;
    if ( (v9 & 0x800) != 0 )
    {
      v35 = *((uint16_t *)v4 + 1);
      if ( *(uint16_t *)(v15 + 696 * v16 + 552) == v35 )
        goto LABEL_34;
    }
    else
    {
      v44 = *((uint16_t *)v4 + 1);
    }
    v36 = (uint8_t)v4[48] << 30;
    *(uint16_t *)(v15 + 696 * v16 + 552) = v37;
    if ( v36 < 0 )
    {
      v38 = *((uint32_t *)v4 + 8);
      *(uint64_t *)&a1 = *((uint64_t *)v4 + 2);
      if ( *(uint64_t *)(v38 + 64) >= *(uint64_t *)&a1 )
      {
        event_dispatch(aPnCheckFiltere);
        goto LABEL_34;
      }
      *(uint64_t *)(v38 + 64) = *(uint64_t *)&a1;
    }
    if ( **v24 == 1 && *v8 == 128 && !v8[1] )
    {
LABEL_34:
      v3 = *((uint8_t *)off_13A238 + 16);
      if ( v3 != 255 )
        goto LABEL_4;
      goto LABEL_35;
    }
    v5 = tx_send_packet_1(v2, (uint8_t)v4[9]);
    goto LABEL_57;
  }
LABEL_84:
  if ( (v9 & 0x40) != 0 )
    goto LABEL_34;
  if ( (v9 & 0x80) != 0 )
  {
    v40 = 1;
    if ( (v4[48] & 8) == 0 )
    {
      v50 = v16;
      v47 = phy_read_offset_b(v16, (uint8_t)v4[7]);
      v16 = v50;
      v40 = 1;
      if ( v47 )
      {
        v5 = ll_get_conn(v2, v50);
        goto LABEL_57;
      }
    }
    v46 = (uint16_t *)(v15 + 2 * ((uint8_t)v4[7] + 277 + 348 * v16));
  }
  else
  {
    v40 = 0;
    v46 = (uint16_t *)(v15 + 696 * v16 + 552);
  }
  v41 = *((uint16_t *)v4 + 1);
  if ( (v9 & 0x800) != 0 && (uint16_t)*v46 == v42 )
    goto LABEL_34;
  *v46 = v43;
  v5 = ll_rx_irq(v2, v16, v40);
LABEL_57:
  v3 = *((uint8_t *)off_13A238 + 16);
  if ( v3 != 255 && !v5 )
    goto LABEL_4;
LABEL_5:
  load_and_process_r0((int *)dword_13A240, v6);
  return v5;
}
