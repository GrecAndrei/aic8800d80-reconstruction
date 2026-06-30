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

extern uint32_t off_100498;
extern uint32_t off_10049C;
extern uint32_t off_1004A0;
extern uint32_t off_100494;
extern uint32_t off_1004A4;
extern uint32_t off_1004A8;
extern uint32_t off_1004AC;
extern uint32_t off_1004B0;
extern uint32_t off_1004B8;
extern uint32_t off_1004B4;
extern uint32_t off_1004BC;
extern uint32_t dword_1004C0;
extern uint32_t dword_1004C4;
extern uint32_t off_1004C8;

// sub_1003D4 @ 0x1003d4, size 190 bytes
void __noreturn sub_1003D4()
{
  uint8_t *v0; // r4
  uint32_t *v1; // r2
  uint32_t *v2; // r5
  uint32_t *v3; // r1
  uint32_t *v4; // r3
  uint32_t *v5; // r2
  uint32_t *v6; // r6
  int v7; // r0
  uint32_t *v8; // r3
  int v9; // r0
  int v10; // r0
  uint16_t *v11; // r2
  uint8_t *v12; // r6
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r0
  int v18; // r0
  int v19; // r0

  v0 = off_100498;
  v1 = off_10049C;
  v2 = off_1004A0;
  *(uint32_t *)off_100494 = off_100498;
  *v1 = v0 + 12;
  v3 = off_1004A4;
  v4 = off_1004A8;
  v5 = off_1004AC;
  v6 = off_1004B0;
  *v2 = v0 + 76;
  *v3 = v0 + 136;
  *v4 = v0 + 152;
  *v6 = v0 + 178;
  *v5 = v0 + 176;
  v7 = sub_1002A0();
  if ( *(uint8_t *)*v2 == 1 )
  {
    v8 = off_1004B8;
    *((uint32_t *)off_1004B4 + 22) &= ~1u;
    v8[20] |= 1u;
    v8[20] &= ~2u;
  }
  v9 = sub_123068(v7);
  v10 = sub_10F4B8(v9);
  sub_115000(v10);
  v11 = (uint16_t *)*v6;
  v12 = (uint8_t *)off_1004BC;
  v13 = dword_1004C0;
  *v11 |= 0x2000u;
  v14 = sub_11F504(v13, *v12);
  v15 = sub_126174(v14);
  if ( v0[363] )
  {
    v19 = sub_12704C(v15);
    sub_127108(v19);
  }
  v16 = sub_11F504(dword_1004C4, (uint8_t)v0[76]);
  v17 = sub_10FFF0(v16);
  v18 = sub_10F6A4(v17);
  if ( *(uint8_t *)*v2 == 3 )
    *(uint32_t *)off_1004C8 = 1;
  sub_115018(v18);
}

