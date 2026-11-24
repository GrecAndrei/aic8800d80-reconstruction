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
  uint32_t *v9; // r2

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
  sub_12FF98();
  sub_10D1A8();
  sub_10F204();
  sub_1157B4();
  if ( *((uint8_t *)v0 + 363) )
  {
    sub_1304F8();
    sub_1305B4();
  }
  sub_12EA88("hosttype=%d, asic_ver=0x%x\r\n", *((uint8_t *)v0 + 76), *(uint8_t *)off_100598);
  sub_110100();
  sub_10F458();
  if ( v8[2] )
  {
    sub_114568();
    v9 = off_100590;
    *(uint32_t *)off_1005A0 &= ~8u;
    *v9 &= 0xFFFFFFF0;
    sub_12ECD0(2, aWakeup);
  }
  else
  {
    sub_12ECD0(2, aWifimain);
  }
  if ( *(uint8_t *)*v1 == 3 )
    *(uint32_t *)off_1005A8 = 1;
  sub_115D60();
}
