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


extern uint32_t dword_11CB34;
extern uint32_t off_11CB10;
extern uint32_t off_11CB18;
extern uint32_t off_11CB24;
extern uint32_t off_11CB28;
extern uint32_t off_11CB2C;
extern uint32_t off_11CB30;

// is_fw_ready @ 0x11c954, size 444 bytes
void is_fw_ready()
{
  uint8_t *v0; // r6
  int v1; // r3
  int v2; // r7
  int v3; // r8
  int v4; // r5
  int v5; // r3
  uint16_t **v6; // r10
  int v7; // r12
  int v8; // r3
  int v9; // r2
  int v10; // r1
  int v11; // r3
  int v12; // r4
  int v13; // r4
  int v14; // r3
  int v15; // r3
  uint16_t v16; // r3
  int v17; // r5
  char *v18; // r3
  int v19; // r0
  uint32_t *v20; // r1
  unsigned int v21; // r3
  unsigned int v22; // r2
  int v23; // r0
  int v24; // r3

  v0 = off_11CB10;
  v1 = *((uint32_t *)off_11CB10 + 52);
  if ( (v1 & 2) != 0 )
  {
    *((uint32_t *)off_11CB10 + 52) = v1 & 0xFFFFFFFD;
    return;
  }
  v2 = *((uint8_t *)off_11CB10 + 190);
  v3 = dword_11CB34;
  v4 = dword_11CB34 + 84 * v2;
  v5 = *(uint8_t *)(v4 + 26);
  if ( *(uint8_t *)(v4 + 26) )
  {
LABEL_12:
    v13 = *(uint32_t *)(v3 + 84 * v2 + 36);
    if ( v5 == 2 )
      v14 = v13 + 16;
    else
      v14 = v13 + 84;
    v15 = *(uint32_t *)(v14 + 60);
    if ( v15 >= 0 )
      return;
    if ( (v15 & 0x800000) != 0 )
    {
      v16 = *(uint16_t *)(v13 + 8);
      if ( (v16 & 0x20) == 0 )
      {
        check_hw_fw_status();
        v17 = 9;
        while ( 1 )
        {
          v16 = *(uint16_t *)(v13 + 8);
          if ( (v16 & 0x20) != 0 )
            break;
          check_hw_fw_status();
          if ( !--v17 )
          {
            v16 = *(uint16_t *)(v13 + 8);
            if ( **(uint16_t **)off_11CB18 < 0 && (v16 & 0x20) == 0 )
            {
              unknown_12f2c8((int)aAggDescStatusA, (int)aTxlHeTbTransmi_0, 2274);
              return;
            }
            break;
          }
        }
      }
      if ( (v16 & 0x40) != 0 )
      {
        if ( v0[199] )
        {
          *(uint32_t *)off_11CB2C = ((uint8_t)v0[164] << 24) & 0x7000000 | *(uint32_t *)off_11CB2C & 0xF8FFFFFF;
        }
        else
        {
          get_rf_capability((uint8_t)v0[190]);
          v16 = *(uint16_t *)(v13 + 8);
        }
        goto LABEL_35;
      }
    }
    else
    {
      list_pop(v3 + 84 * v2 + 28);
      v16 = *(uint16_t *)(v13 + 8);
    }
    if ( v0[199] )
    {
      v22 = (HIBYTE(*(uint32_t *)off_11CB2C) & 7) + 1;
      if ( v22 >= (uint8_t)v0[165] )
        v22 = (uint8_t)v0[165];
      *(uint32_t *)off_11CB2C = (v22 << 24) & 0x7000000 | *(uint32_t *)off_11CB2C & 0xF8FFFFFF;
    }
LABEL_35:
    v23 = ((uint32_t *)(uintptr_t)off_11CB30)[v2];
    *(uint16_t *)(v13 + 8) = v16 | 0x10;
    irq_disable_global_2(v23);
    v24 = v3 + 84 * v2;
    *(uint8_t *)(v24 + 26) = 0;
    *(uint32_t *)(v24 + 36) = 0;
LABEL_25:
    v18 = &v0[28 * v2];
    if ( !v18[46] )
    {
      v19 = *((uint32_t *)v18 + 9);
      if ( v19 )
        rf_switch_case(v19, v2);
      *(uint32_t *)&v0[28 * v2 + 36] = 0;
    }
    v20 = off_11CB28;
    *(uint32_t *)off_11CB24 &= ~0x40u;
    *v20 = 64;
    v21 = *((uint32_t *)v0 + 52) & 0xFFFFFFFE;
    --*(uint8_t *)(v3 + 84 * v2 + 80);
    *((uint32_t *)v0 + 52) = v21;
    invalid_handler(v2);
    return;
  }
  v6 = (uint16_t **)off_11CB18;
  while ( 1 )
  {
    v12 = *(uint32_t *)(v4 + 12);
    if ( **v6 < 0 && !v12 )
      irq_disable_mmio_write((int)aTxdescNull, (int)aTxlHeTbTransmi_0, 2199);
    v7 = *(uint32_t *)(v12 + 76);
    v8 = *(uint32_t *)(v7 + 72);
    v9 = v8 | 0x400000;
    v10 = v8 | 0x400000;
    if ( v8 >= 0 )
      break;
    v11 = *(uint32_t *)(v12 + 36);
    *(uint32_t *)(v7 + 72) = v9;
    if ( (v11 & 0x200000) == 0 )
    {
      rx_mpdu_process(v12, v10);
      goto LABEL_25;
    }
    get_conn_by_channel(v12, v10);
    v5 = *(uint8_t *)(v4 + 26);
    if ( *(uint8_t *)(v4 + 26) )
      goto LABEL_12;
  }
}
