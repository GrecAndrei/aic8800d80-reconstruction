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

extern uint32_t off_120A10;
extern uint32_t off_120A14;
extern uint32_t off_120A18;
extern uint32_t off_120A1C;
extern uint32_t off_120A20;
extern uint32_t off_120A24;
extern uint32_t dword_120A28;
extern uint32_t off_120A54;
extern uint32_t off_120A2C;
extern uint32_t off_120A30;
extern uint32_t dword_120A34;
extern uint32_t off_120A3C;
extern uint32_t off_120A40;
extern uint32_t off_120A44;
extern uint32_t off_120A48;
extern uint32_t off_120A4C;
extern uint32_t off_120A38;
extern uint32_t off_120A50;

// hal_phy_init @ 0x1208f4, size 284 bytes
// Doc: sub_12208F4 [rf]: Init RF register window at 0x403200f0 with helpers
// sub_12208F4 [rf]: Init RF register window at 0x403200f0 with helpers
uint32_t *hal_phy_init()
{
  int *v0; // r4
  int *v1; // r5
  int *v2; // r6
  int v3; // r0
  int v4; // r0
  uint32_t *v5; // r0
  unsigned int *v6; // r1
  unsigned int *v7; // r3
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

  v0 = (int *)off_120A10;
  v1 = (int *)off_120A14;
  v2 = (int *)off_120A18;
  v3 = nullsub_1();
  v4 = nullsub_2(v3);
  nullsub_3(v4);
  v5 = off_120A1C;
  v6 = (unsigned int *)off_120A20;
  v7 = (unsigned int *)off_120A24;
  *v0 = *v0 & 0x3FFFFF | 0x2800000;
  v8 = dword_120A28;
  *v5 |= 0x8000000u;
  *v6 = *v6 & 0xFF0FFFFF | 0x200000;
  *v7 = *v7 & 0xFFFFF8FF | 0x600;
  *v7 = *v7 & 0xFFFFC7FF | 0x2000;
  *v7 = *v7 & 0xFFFE3FFF | 0xC000;
  *v7 |= 0xE0000u;
  *v1 = *v1 & v8 | 0x5DC;
  v5[1] = v5[1] & v8 | 0xBB8;
  *(v6 - 205) = *(v6 - 205) & 0xFFFF00FF | 0xDA00;
  v9 = *v2;
  v10 = *(uint8_t *)(*v2 + 2);
  if ( (v10 & 0x10) != 0 )
    v5[16] &= ~0x80000000;
  else
    *(uint32_t *)off_120A54 |= 0x80000000;
  v11 = (v10 & 1) == 0;
  v12 = *(uint32_t *)off_120A2C;
  if ( v11 )
    v13 = v12 & 0xFFFBFFFF;
  else
    v13 = v12 | 0x40000;
  *(uint32_t *)off_120A2C = v13;
  v14 = off_120A30;
  *(uint32_t *)off_120A30 = dword_120A34;
  if ( *(uint8_t *)(v9 + 1) )
    *(v14 - 215) |= 0x40u;
  v15 = off_120A3C;
  v16 = off_120A40;
  v17 = off_120A44;
  result = off_120A48;
  v19 = (uint8_t **)off_120A4C;
  *(uint32_t *)off_120A38 &= ~1u;
  *v15 = 0xFFFF;
  *v16 = -1;
  *v17 = 0xFFFF;
  *result = -1;
  v20 = **v19;
  if ( (unsigned int)(v20 - 1) <= 1 || v20 == 4 )
    *(uint32_t *)off_120A50 |= 0x80000000;
  return result;
}

