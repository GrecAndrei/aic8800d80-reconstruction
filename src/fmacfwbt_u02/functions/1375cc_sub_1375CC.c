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

extern uint32_t off_1376A0;
extern uint32_t off_1376D0;
extern uint32_t off_1376A4;
extern uint32_t off_1376A8;
extern uint32_t dword_1376B0;
extern uint32_t dword_1376AC;
extern uint32_t off_1376B8;
extern uint32_t off_1376BC;
extern uint32_t off_1376B4;
extern uint32_t off_1376C4;
extern uint32_t off_1376CC;
extern uint32_t off_1376C8;
extern uint32_t off_1376C0;

// sub_1375CC @ 0x1375cc, size 212 bytes
uint32_t * sub_1375CC(int a1)
{
  uint16_t *v2; // r4
  uint8_t **v3; // r7
  int16_t v4; // r0
  uint8_t *v5; // r5
  int *v6; // r2
  uint16_t *v7; // r0
  int v8; // r1
  int v9; // r0
  uint32_t *v11; // r3

  if ( *(uint8_t *)off_1376A0 )
    sub_1029F8(*((uint8_t *)off_1376D0 + 9));
  v2 = off_1376A4;
  v3 = (uint8_t **)off_1376A8;
  if ( *((uint8_t *)off_1376A4 + 3850) == 1 )
    v4 = 4099;
  else
    v4 = 4097;
  v5 = (uint8_t *)sub_12CB54(v4, *((uint16_t *)off_1376A4 + 1924), 4, 3u);
  sub_12EEF8(
    8,
    dword_1376B0,
    dword_1376AC,
    *(uint8_t *)(*(uint32_t *)v2 + 366),
    *((uint8_t *)v2 + 3850),
    a1);
  v6 = (int *)off_1376B8;
  v7 = (uint16_t *)off_1376BC;
  *(uint32_t *)off_1376B4 &= ~4u;
  v8 = *v7;
  v9 = *(uint32_t *)v2;
  *v6 = (HIWORD(*v6) << 16) | v8;
  *v5 = *(uint8_t *)(v9 + 366);
  v5[1] = a1;
  v5[2] = v2[2];
  if ( **v3 == 1 && *((uint8_t *)off_1376C4 + 189) )
  {
    v11 = off_1376CC;
    *(uint32_t *)off_1376C8 &= 0xFC0FFFFF;
    *v11 |= 0x400000u;
    *v11 |= 0x200000u;
  }
  sub_12CC60(v9 - 12);
  *(uint32_t *)v2 = 0;
  sub_12CBB4((int)v5);
  *((uint32_t *)off_1376C0 + 1) &= ~0x20u;
  return sub_12CF5C(4u, 0);
}

