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

extern uint32_t off_12B974;
extern uint32_t off_12B97C;
extern uint32_t off_12B978;
extern uint32_t dword_12B980;
extern uint32_t off_12B984;
extern uint32_t off_12B988;
extern uint32_t off_12B98C;
extern uint32_t dword_12B9D8;
extern uint32_t dword_12B9D4;
extern uint32_t off_12B990;
extern uint32_t dword_12B998;
extern uint32_t dword_12B994;
extern uint32_t off_12B99C;
extern uint32_t dword_12B9A0;
extern uint32_t off_12B9A4;
extern uint32_t off_12B9A8;
extern uint32_t off_12B9B0;
extern uint32_t off_12B9AC;
extern uint32_t off_12B9B8;
extern uint32_t off_12B9B4;
extern uint32_t off_12B9BC;
extern uint32_t off_12B9C0;
extern uint32_t off_12B9C4;
extern uint32_t off_12B9C8;
extern uint32_t off_12B9CC;
extern uint32_t off_12B9DC;
extern uint32_t off_12B9D0;

// rf_hw_init @ 0x12b77c, size 502 bytes
int rf_hw_init()
{
  uint32_t *v0; // r2
  unsigned int v1; // r0
  uint32_t *v2; // r3
  uint32_t *v3; // r2
  int16_t **v4; // r1
  char *v5; // r0
  int *v6; // r3
  uint32_t *v7; // r1
  int v8; // r2
  int *v9; // r4
  int v10; // r5
  uint8_t *v11; // r1
  int *v12; // r3
  uint32_t *v13; // r3
  uint32_t *v14; // r4
  unsigned int *v15; // r6
  uint32_t *v16; // r2
  uint32_t *v17; // r5
  int result; // r0
  uint32_t *v19; // r1
  uint8_t **v20; // r2
  uint32_t *v21; // r4
  uint32_t *v22; // r6
  int v23; // r0
  unsigned int *v24; // r5
  uint8_t v25; // [sp+6h] [bp-2h] BYREF
  uint8_t v26; // [sp+7h] [bp-1h] BYREF

  v0 = off_12B974;
  *(uint32_t *)off_12B974 = 1;
  while ( (uint8_t)*v0 )
    ;
  v1 = global_state_get_byte();
  rf_irq_service(v1);
  v2 = off_12B97C;
  *(uint32_t *)off_12B978 = dword_12B980;
  v3 = off_12B984;
  *v2 = 0x80000000;
  v4 = (int16_t **)off_12B988;
  *v3 &= ~0x800u;
  if ( **v4 < 0 && *(uint32_t *)off_12B98C < 0x2F000000u )
    irq_disable_mmio_write(dword_12B9D8, dword_12B9D4, 284);
  v5 = (char *)off_12B98C;
  v6 = (int *)off_12B990;
  v7 = off_12B984;
  v8 = dword_12B998;
  *(uint32_t *)off_12B98C = dword_12B994;
  *v6 = v8;
  v9 = (int *)off_12B99C;
  v10 = dword_12B9A0;
  *v7 |= 0x40007C0u;
  *v7 &= ~0x4000000u;
  v11 = off_12B9A4;
  v12 = v6 - 8199;
  *(uint32_t *)&v5[-132] |= 0x10000u;
  *v9 = v10;
  *v12 |= 0xFF000000;
  *v12 |= 0x800000u;
  *v12 = *v12 & 0xFF80FFFF | 0x100000;
  if ( !v11[2] )
    *v12 = (HIWORD(*v12) << 16) | 0x64;
  v13 = off_12B9A8;
  v14 = off_12B984;
  v15 = (unsigned int *)off_12B9B0;
  *(uint32_t *)off_12B9AC = 12288;
  *v13 = 0;
  get_calibration_offsets(&v26, &v25);
  v16 = off_12B9B8;
  *(uint32_t *)off_12B9B4 = (v26 << 8) | (v25 << 16) | v26;
  v17 = off_12B9BC;
  *v14 |= 0x1000u;
  *v14 |= 0x2000u;
  *v16 |= 0x80000u;
  *v16 &= ~0x80u;
  result = get_rf_field_mid();
  v19 = off_12B9C0;
  *v15 = ((result + 1) << 26) & 0x1C000000 | *v15 & 0xE3FFFFFF;
  v20 = (uint8_t **)off_12B9C4;
  *v14 |= 0x20u;
  *v17 &= ~1u;
  *v19 |= 2u;
  if ( **v20 == 1 )
    *(uint32_t *)off_12B9C8 &= 0x80FFFFFF;
  v21 = off_12B984;
  v22 = off_12B9CC;
  *(uint32_t *)off_12B984 |= 0x2000000u;
  if ( (*v22 & 0x20000) != 0 )
  {
    result = rf_status_bit28();
    if ( result )
    {
      v23 = get_rf_field_hi();
      v24 = (unsigned int *)off_12B9DC;
      result = v23 << 8;
      *(uint32_t *)off_12B9DC = result & 0x700 | *(uint32_t *)off_12B9DC & 0xFFFFF8FF;
      *v24 = *v24 & 0xFFFFFF1F | 0x60;
      *v24 |= 4u;
      *v24 |= 1u;
      if ( (*v22 & 0x8000) != 0 )
      {
        result = rf_status_bit21();
        if ( result )
        {
          *v21 |= 0x80000u;
          *v24 = *v24 & 0xF1FFFFFF | 0x4000000;
        }
      }
      if ( (*(uint32_t *)off_12B9CC & 0x20000) != 0 )
      {
        result = rf_status_bit30();
        if ( result )
          *(uint32_t *)off_12B9DC |= 2u;
      }
    }
  }
  *(uint32_t *)off_12B9D0 |= 1u;
  return result;
}

