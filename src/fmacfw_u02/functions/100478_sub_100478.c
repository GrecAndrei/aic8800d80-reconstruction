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

extern uint32_t off_100568;
extern uint32_t off_100570;
extern uint32_t off_100574;
extern uint32_t off_100578;
extern uint32_t off_10056C;
extern uint32_t off_10057C;
extern uint32_t off_100580;
extern uint32_t off_100584;
extern uint32_t off_10058C;
extern uint32_t off_100588;
extern uint32_t off_100594;
extern uint32_t off_100590;
extern uint32_t dword_10059C;
extern uint32_t off_100598;
extern uint32_t dword_1005A4;
extern uint32_t off_1005A0;
extern uint32_t dword_1005AC;
extern uint32_t off_1005A8;

// sub_100478 @ 0x100478, size 240 bytes
void __noreturn sub_100478()
{
  uint8_t *v0; // r4
  uint32_t *v1; // r5
  uint32_t *v2; // r3
  uint32_t *v3; // r0
  uint32_t *v4; // r2
  uint32_t *v5; // r3
  uint32_t *v6; // r1
  int v7; // r0
  uint32_t *v8; // r3
  uint8_t *v9; // r6
  int v10; // r0
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  uint32_t *v17; // r2
  int v18; // r1
  int v19; // r0
  int v20; // r0

  v0 = off_100568;
  v1 = off_100570;
  v2 = off_100574;
  v3 = off_100578;
  *(uint32_t *)off_10056C = off_100568;
  v4 = off_10057C;
  *v1 = v0 + 76;
  *v2 = v0 + 12;
  *v3 = v0 + 136;
  v5 = off_100580;
  v6 = off_100584;
  *v4 = v0 + 152;
  *v5 = v0 + 178;
  *v6 = v0 + 176;
  v7 = sub_1002A0();
  if ( *(uint8_t *)*v1 == 1 )
  {
    v8 = off_10058C;
    *((uint32_t *)off_100588 + 22) &= ~1u;
    v8[20] |= 1u;
    v8[20] &= ~2u;
  }
  v9 = off_100594;
  *((uint8_t *)off_100594 + 2) = (*(uint32_t *)off_100590 & 0xF) == 10;
  v10 = sub_12FF98(v7);
  v11 = sub_10D1A8(v10);
  v12 = sub_10F204(v11);
  v13 = sub_1157B4(v12);
  if ( v0[363] )
  {
    v20 = sub_1304F8(v13);
    sub_1305B4(v20);
  }
  v14 = sub_12EA88(dword_10059C, (uint8_t)v0[76], *(uint8_t *)off_100598);
  v15 = sub_110100(v14);
  v16 = sub_10F458(v15);
  if ( v9[2] )
  {
    sub_114568(v16);
    v17 = off_100590;
    v18 = dword_1005A4;
    *(uint32_t *)off_1005A0 &= ~8u;
    *v17 &= 0xFFFFFFF0;
    v19 = sub_12ECD0(2, v18);
  }
  else
  {
    v19 = sub_12ECD0(2, dword_1005AC);
  }
  if ( *(uint8_t *)*v1 == 3 )
    *(uint32_t *)off_1005A8 = 1;
  sub_115D60(v19);
}

