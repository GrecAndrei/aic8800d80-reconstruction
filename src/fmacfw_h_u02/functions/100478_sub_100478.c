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
extern uint32_t off_10056C;
extern uint32_t off_100570;
extern uint32_t off_100574;
extern uint32_t off_100578;
extern uint32_t off_10057C;
extern uint32_t off_100580;
extern uint32_t off_100584;
extern uint32_t off_100588;
extern uint32_t off_10058C;
extern uint32_t off_100590;
extern uint32_t off_100594;
extern uint32_t off_100598;
extern uint32_t off_1005A0;
extern uint32_t off_1005A8;

// sub_100478 @ 0x100478, size 240 bytes
void sub_100478()
{
  int *v0; // r4
  uint32_t *v1; // r5
  uint32_t *v2; // r3
  uint32_t *v3; // r0
  uint32_t *v4; // r2
  uint32_t *v5; // r3
  uint32_t *v6; // r1
  uint32_t *v7; // r3
  uint8_t *v8; // r6
  int v9; // r0
  int v10; // r1
  uint32_t *v11; // r2
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3

  v0 = (int *)off_100568;
  v1 = off_100570;
  v2 = off_100574;
  v3 = off_100578;
  *(uint32_t *)off_10056C = off_100568;
  v4 = off_10057C;
  *v1 = v0 + 19;
  *v2 = v0 + 3;
  *v3 = v0 + 34;
  v5 = off_100580;
  v6 = (uint32_t *)off_100584;
  *v4 = v0 + 38;
  *v5 = (char *)v0 + 178;
  *v6 = v0 + 44;
  sub_1002A0((int)(v0 + 44), (int)v6, (int)v0 + 178, (int)v5);
  if ( *(uint8_t *)*v1 == 1 )
  {
    v7 = off_10058C;
    *((uint32_t *)off_100588 + 22) &= ~1u;
    v7[20] |= 1u;
    v7[20] &= ~2u;
  }
  v8 = off_100594;
  *((uint8_t *)off_100594 + 2) = (*(uint32_t *)off_100590 & 0xF) == 10;
  sub_12FE58();
  sub_10D068();
  sub_10F0C4();
  v9 = sub_115674();
  if ( *((uint8_t *)v0 + 363) )
  {
    sub_1303B8(v9, v10);
    sub_130474();
  }
  sub_12E948("hosttype=%d, asic_ver=0x%x\r\n", *((uint8_t *)v0 + 76), *(uint8_t *)off_100598);
  sub_10FFC0();
  sub_10F318();
  if ( v8[2] )
  {
    sub_114428();
    v11 = off_100590;
    *(uint32_t *)off_1005A0 &= ~8u;
    *v11 &= 0xFFFFFFF0;
    v12 = sub_12EB90(2, aWakeup);
  }
  else
  {
    v12 = sub_12EB90(2, aWifimain);
  }
  v15 = *(uint8_t *)*v1;
  if ( v15 == 3 )
  {
    v15 = off_1005A8;
    v14 = 1;
    *(uint32_t *)off_1005A8 = 1;
  }
  sub_115C20(v12, v13, v14, v15);
}
