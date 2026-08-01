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

extern uint32_t off_1185DC;
extern uint32_t off_1185D8;
extern uint32_t off_1185E0;
extern uint32_t off_1185E4;
extern uint32_t off_1185E8;
extern uint32_t off_1185EC;
extern uint32_t off_1185F0;
extern uint32_t dword_1185F4;
extern uint32_t off_118620;
extern uint32_t off_1185F8;
extern uint32_t off_1185FC;
extern uint32_t dword_118600;
extern uint32_t off_118608;
extern uint32_t off_11860C;
extern uint32_t off_118610;
extern uint32_t off_118614;
extern uint32_t off_118618;
extern uint32_t off_118604;
extern uint32_t off_11861C;

// rf_clock_enable @ 0x1184b0, size 294 bytes
// Doc: rf_clock_enable [mmio]: Set bits in MMIO control register group
// rf_clock_enable [mmio]: Set bits in MMIO control register group
uint32_t *rf_clock_enable()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r0
  uint32_t *v3; // r0
  unsigned int *v4; // r1
  unsigned int *v5; // r3
  int *v6; // r5
  int *v7; // r6
  int v8; // r4
  int v9; // r3
  char v10; // r2
  int v11; // zf
  int v12; // r2
  unsigned int v13; // r2
  uint32_t *v14; // r2
  uint32_t *v15; // r6
  uint32_t *v16; // r5
  uint32_t *v17; // r4
  uint32_t *result; // r0
  uint8_t **v19; // r1
  int v20; // r3

  v0 = (int *)off_1185DC;
  *(uint32_t *)off_1185D8 |= 0x10u;
  v1 = nullsub_1();
  v2 = nullsub_2(v1);
  nullsub_3(v2);
  v3 = off_1185E0;
  v4 = (unsigned int *)off_1185E4;
  v5 = (unsigned int *)off_1185E8;
  v6 = (int *)off_1185EC;
  v7 = (int *)off_1185F0;
  *v0 = *v0 & 0x3FFFFF | 0x2800000;
  v8 = dword_1185F4;
  *v3 |= 0x8000000u;
  *v4 = *v4 & 0xFF0FFFFF | 0x200000;
  *v5 = *v5 & 0xFFFFF8FF | 0x600;
  *v5 = *v5 & 0xFFFFC7FF | 0x2000;
  *v5 = *v5 & 0xFFFE3FFF | 0xC000;
  *v5 |= 0xE0000u;
  *v6 = *v6 & v8 | 0x5DC;
  v3[1] = v3[1] & v8 | 0xBB8;
  *(v4 - 205) = *(v4 - 205) & 0xFFFF00FF | 0xDA00;
  v9 = *v7;
  v10 = *(uint8_t *)(*v7 + 2);
  if ( (v10 & 0x10) != 0 )
    v3[16] &= ~0x80000000;
  else
    *(uint32_t *)off_118620 |= 0x80000000;
  v11 = (v10 & 1) == 0;
  v12 = *(uint32_t *)off_1185F8;
  if ( v11 )
    v13 = v12 & 0xFFFBFFFF;
  else
    v13 = v12 | 0x40000;
  *(uint32_t *)off_1185F8 = v13;
  v14 = off_1185FC;
  *(uint32_t *)off_1185FC = dword_118600;
  if ( *(uint8_t *)(v9 + 1) )
    *(v14 - 215) |= 0x40u;
  v15 = off_118608;
  v16 = off_11860C;
  v17 = off_118610;
  result = off_118614;
  v19 = (uint8_t **)off_118618;
  *(uint32_t *)off_118604 &= ~1u;
  *v15 = 0xFFFF;
  *v16 = -1;
  *v17 = 0xFFFF;
  *result = -1;
  v20 = **v19;
  if ( (unsigned int)(v20 - 1) <= 1 || v20 == 4 )
    *(uint32_t *)off_11861C |= 0x80000000;
  return result;
}

