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

extern uint32_t off_11CA60;
extern uint32_t off_11CA5C;
extern uint32_t off_11CA64;
extern uint32_t off_11CA68;
extern uint32_t dword_11CA8C;
extern uint32_t dword_11CA6C;
extern uint32_t off_11CA90;
extern uint32_t dword_11CA7C;
extern uint32_t dword_11CA78;
extern uint32_t off_11CA74;
extern uint32_t off_11CA70;
extern uint32_t off_11CA80;
extern uint32_t off_11CA84;
extern uint32_t off_11CA88;

// reset_radio_core @ 0x11c8e4, size 376 bytes
// Doc: reset_radio_core [util]: Dispatch a free-pool log entry with 3 halfword fields
// reset_radio_core [util]: Dispatch a free-pool log entry with 3 halfword fields
void reset_radio_core()
{
  uint32_t *v0; // r2
  uint32_t *v1; // r7
  int v2; // r3
  int v3; // r6
  int v4; // r8
  int v5; // r3
  int v6; // r4
  int v7; // r3
  int v8; // r0
  uint32_t *v9; // r1
  unsigned int v10; // r3
  uint32_t *v11; // r4
  int16_t **v12; // r9
  int v13; // r5
  int v14; // r3
  int v15; // r2
  unsigned int v16; // r1
  uint32_t *v17; // r3
  int v18; // r2
  int v19; // r1
  int v20; // nf
  uint32_t *v21; // r1
  int v22; // r2

  v0 = off_11CA60;
  *(uint32_t *)off_11CA5C = 0x100000;
  while ( (*v0 & 0x300000) != 0 )
    ;
  v1 = off_11CA64;
  v2 = *((uint32_t *)off_11CA64 + 52);
  *(uint32_t *)off_11CA68 = 0x100000;
  if ( (v2 & 1) != 0 )
  {
    v3 = *((uint8_t *)v1 + 190);
    v4 = dword_11CA8C;
    v5 = dword_11CA8C + 84 * v3;
    if ( *(uint8_t *)(v5 + 26) )
    {
LABEL_5:
      v6 = v4 + 84 * v3;
      *(uint16_t *)(*(uint32_t *)(v6 + 36) + 8) |= 0x10u;
      mem_word_load(v6 + 28);
      unknown_func_12d104(*(uint32_t *)(dword_11CA6C + 4 * v3));
      *(uint8_t *)(v6 + 26) = 0;
      *(uint32_t *)(v6 + 36) = 0;
    }
    else
    {
      v11 = *(uint32_t **)(v5 + 12);
      if ( (v11[9] & 0x200000) != 0 )
      {
        v22 = *(uint32_t *)(*(uint32_t *)(v5 + 20) + 68);
        if ( v22 == v11[17] )
          *(uint32_t *)(v5 + 20) = **(uint32_t **)(v22 + 324);
      }
      v12 = (int16_t **)off_11CA90;
      v13 = v4 + 84 * v3;
      while ( 1 )
      {
        if ( **v12 < 0 && !v11 )
          mmio_clear_register(dword_11CA7C, dword_11CA78, 2094);
        v14 = v11[19];
        v15 = v11[9];
        v16 = *(uint32_t *)(v14 + 72) | 0x80400000;
        *(uint32_t *)(v14 + 72) = v16;
        if ( (v15 & 0x200000) == 0 )
          break;
        get_connection_by_slot((int)v11, v16);
        v11 = *(uint32_t **)(v13 + 12);
        if ( *(uint8_t *)(v13 + 26) )
          goto LABEL_5;
      }
      process_tx_packet((int)v11, v16);
    }
    v7 = (int)&v1[7 * v3];
    if ( !*(uint8_t *)(v7 + 46) )
    {
      v8 = *(uint32_t *)(v7 + 36);
      if ( v8 )
        radio_band_validate(v8, v3, *(uint8_t *)(v7 + 46), v7);
      v1[7 * v3 + 9] = 0;
    }
    v9 = off_11CA74;
    *(uint32_t *)off_11CA70 &= ~0x40u;
    *v9 = 64;
    v10 = v1[52] & 0xFFFFFFFE;
    --*(uint8_t *)(v4 + 84 * v3 + 80);
    v1[52] = v10;
    test_flag(v3);
  }
  else if ( (v2 & 2) != 0 )
  {
    v1[52] = v2 & 0xFFFFFFFD;
  }
  else
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11CA80 = 1;
    }
    v17 = off_11CA84;
    v18 = *(uint32_t *)off_11CA84;
    v19 = *(uint32_t *)off_11CA84 + 1;
    v20 = (*(uint32_t *)off_11CA88 & 0x1000) != 0;
    *(uint32_t *)off_11CA84 = v19;
    if ( v20 )
      v1[52] |= 4u;
    if ( v19 )
    {
      v21 = off_11CA80;
      *v17 = v18;
      if ( !v18 )
      {
        if ( *v21 )
          __enable_irq();
      }
    }
  }
}

