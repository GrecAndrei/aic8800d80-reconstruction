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

extern uint32_t off_11CB10;
extern uint32_t dword_11CB34;
extern uint32_t off_11CB18;
extern uint32_t dword_11CB20;
extern uint32_t dword_11CB1C;
extern uint32_t off_11CB2C;
extern uint32_t dword_11CB30;
extern uint32_t off_11CB28;
extern uint32_t off_11CB24;
extern uint32_t dword_11CB14;

// is_fw_ready @ 0x11c954, size 444 bytes
int  is_fw_ready(int result)
{
  uint8_t *v1; // r6
  int v2; // r3
  int v3; // r1
  int v4; // r7
  int v5; // r8
  int v6; // r5
  int v7; // r3
  int16_t **v8; // r10
  int v9; // r9
  int v10; // r12
  int v11; // r3
  int v12; // r2
  int v13; // r1
  int v14; // r3
  int v15; // r4
  int v16; // r4
  int v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r5
  int v21; // r3
  int v22; // r0
  uint32_t *v23; // r1
  unsigned int v24; // r3
  unsigned int v25; // r2
  int v26; // r0
  int v27; // r3

  v1 = off_11CB10;
  v2 = *((uint32_t *)off_11CB10 + 52);
  v3 = v2 << 30;
  if ( (v2 & 2) != 0 )
  {
    *((uint32_t *)off_11CB10 + 52) = v2 & 0xFFFFFFFD;
    return result;
  }
  v4 = *((uint8_t *)off_11CB10 + 190);
  v5 = dword_11CB34;
  v6 = dword_11CB34 + 84 * v4;
  v7 = *(uint8_t *)(v6 + 26);
  if ( *(uint8_t *)(v6 + 26) )
  {
LABEL_12:
    v16 = *(uint32_t *)(v5 + 84 * v4 + 36);
    if ( v7 == 2 )
      v17 = v16 + 16;
    else
      v17 = v16 + 84;
    v18 = *(uint32_t *)(v17 + 60);
    if ( v18 >= 0 )
      return result;
    if ( (v18 & 0x800000) != 0 )
    {
      v19 = *(uint16_t *)(v16 + 8);
      if ( (v19 & 0x20) == 0 )
      {
        check_hw_fw_status(result);
        v20 = 9;
        while ( 1 )
        {
          v19 = *(uint16_t *)(v16 + 8);
          if ( (v19 & 0x20) != 0 )
            break;
          check_hw_fw_status(v19 << 26);
          if ( !--v20 )
          {
            v19 = *(uint16_t *)(v16 + 8);
            if ( **(int16_t **)off_11CB18 < 0 )
            {
              v3 = v19 << 26;
              if ( (v19 & 0x20) == 0 )
                return unknown_12f2c8(dword_11CB20, dword_11CB1C, 2274, v19);
            }
            break;
          }
        }
      }
      if ( (v19 & 0x40) != 0 )
      {
        if ( v1[199] )
        {
          *(uint32_t *)off_11CB2C = ((uint8_t)v1[164] << 24) & 0x7000000 | *(uint32_t *)off_11CB2C & 0xF8FFFFFF;
        }
        else
        {
          get_rf_capability((uint8_t)v1[190], v3, (uint8_t)v1[199], v19);
          LOWORD(v19) = *(uint16_t *)(v16 + 8);
        }
        goto LABEL_35;
      }
    }
    else
    {
      list_pop(v5 + 84 * v4 + 28);
      LOWORD(v19) = *(uint16_t *)(v16 + 8);
    }
    if ( v1[199] )
    {
      v25 = (HIBYTE(*(uint32_t *)off_11CB2C) & 7) + 1;
      if ( v25 >= (uint8_t)v1[165] )
        v25 = (uint8_t)v1[165];
      *(uint32_t *)off_11CB2C = (v25 << 24) & 0x7000000 | *(uint32_t *)off_11CB2C & 0xF8FFFFFF;
    }
LABEL_35:
    v26 = *(uint32_t *)(dword_11CB30 + 4 * v4);
    *(uint16_t *)(v16 + 8) = v19 | 0x10;
    irq_disable_global_2(v26);
    v27 = v5 + 84 * v4;
    *(uint8_t *)(v27 + 26) = 0;
    *(uint32_t *)(v27 + 36) = 0;
LABEL_25:
    v21 = (int)&v1[28 * v4];
    if ( !*(uint8_t *)(v21 + 46) )
    {
      v22 = *(uint32_t *)(v21 + 36);
      if ( v22 )
        rf_switch_case(v22, v4, *(uint8_t *)(v21 + 46), v21);
      *(uint32_t *)&v1[28 * v4 + 36] = 0;
    }
    v23 = off_11CB28;
    *(uint32_t *)off_11CB24 &= ~0x40u;
    *v23 = 64;
    v24 = *((uint32_t *)v1 + 52) & 0xFFFFFFFE;
    --*(uint8_t *)(v5 + 84 * v4 + 80);
    *((uint32_t *)v1 + 52) = v24;
    return invalid_handler(v4);
  }
  v8 = (int16_t **)off_11CB18;
  v9 = dword_11CB1C;
  while ( 1 )
  {
    v15 = *(uint32_t *)(v6 + 12);
    if ( **v8 < 0 && !v15 )
      irq_disable_mmio_write(dword_11CB14, v9, 2199);
    v10 = *(uint32_t *)(v15 + 76);
    v11 = *(uint32_t *)(v10 + 72);
    v12 = v11 | 0x400000;
    result = v15;
    v13 = v11 | 0x400000;
    if ( v11 >= 0 )
      return result;
    v14 = *(uint32_t *)(v15 + 36);
    *(uint32_t *)(v10 + 72) = v12;
    if ( (v14 & 0x200000) == 0 )
    {
      rx_mpdu_process(v15, v13);
      goto LABEL_25;
    }
    result = get_conn_by_channel(v15, v13);
    v7 = *(uint8_t *)(v6 + 26);
    if ( *(uint8_t *)(v6 + 26) )
      goto LABEL_12;
  }
}

