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

extern uint32_t off_121A60;
extern uint32_t off_121A64;
extern uint32_t off_121A68;
extern uint32_t off_121A6C;
extern uint32_t off_121A70;
extern uint32_t off_121A74;
extern uint32_t off_121A78;
extern uint32_t off_121A7C;
extern uint32_t dword_121A80;
extern uint32_t off_121A88;
extern uint32_t dword_121A90;
extern uint32_t dword_121A8C;
extern uint32_t off_121A84;

// read_hw_stats @ 0x1219e8, size 118 bytes
unsigned int  read_hw_stats(int *a1)
{
  uint32_t *v1; // r3
  uint32_t *v2; // r7
  uint32_t *v3; // r4
  uint32_t *v4; // r1
  uint32_t *v5; // r6
  uint32_t *v6; // r5
  int v7; // r7
  int v8; // r0
  int16_t **v9; // r0
  int *v10; // r4
  int v11; // r2
  int16_t *v12; // r3

  v1 = off_121A60;
  v2 = off_121A64;
  v3 = off_121A68;
  v4 = off_121A6C;
  v5 = off_121A70;
  v6 = off_121A74;
  *(uint32_t *)off_121A60 &= ~2u;
  *v1 |= 1u;
  *v2 = 768;
  v7 = *a1;
  v8 = *((uint16_t *)a1 + 2);
  *v5 = 0;
  *v6 = 0;
  *v3 = v7;
  *v4 = v8;
  v9 = (int16_t **)off_121A78;
  v10 = (int *)off_121A7C;
  v11 = dword_121A80;
  *v1 &= 0xFFFFF8FF;
  v12 = *v9;
  *v10 = v11;
  if ( *v12 < 0 && *(uint32_t *)off_121A88 << 28 )
  {
    mmio_field_update(dword_121A90, dword_121A8C, 472);
    v11 = *v10;
  }
  *(uint32_t *)off_121A84 = v11 | v10[1];
  return rf_ant_switch_set(0);
}

