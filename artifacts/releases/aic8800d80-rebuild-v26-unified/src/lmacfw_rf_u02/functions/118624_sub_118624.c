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

extern uint32_t off_118670;

// sub_118624 @ 0x118624, size 76 bytes
uint32_t *sub_118624()
{
  uint8_t *v0; // r4
  int v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0

  v0 = off_118670;
  if ( !*((uint8_t *)off_118670 + 2) )
    sub_11D0B8();
  sub_11843C();
  sub_117DF4();
  v1 = sub_117AF8();
  sub_11C814(v1);
  sub_115820();
  if ( v0[2] )
    v2 = sub_116CA4();
  else
    v2 = sub_116C94();
  v3 = sub_11AB0C(v2);
  v4 = sub_11CA94(v3);
  v5 = sub_11BA64(v4);
  sub_11D8D4(v5);
  sub_10F50C();
  return sub_1184B0();
}

