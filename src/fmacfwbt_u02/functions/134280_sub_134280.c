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

extern uint32_t off_134324;
extern uint32_t dword_134328;
extern uint32_t dword_13432C;

// sub_134280 @ 0x134280, size 162 bytes
int sub_134280()
{
  int v1; // r4
  int v2; // r6
  int v3; // r5
  int v4; // r0
  int v5; // r2
  int v6; // r3
  int16_t v7; // r1
  uint8_t *v8; // r0

  if ( msg_get_value(6u) == 9 )
  {
    v1 = *((uint32_t *)off_134324 + 4);
    v2 = dword_134328 + 1320 * *(uint8_t *)(v1 + 61);
    v3 = *(uint8_t *)(v2 + 116);
    v4 = rf_bus_setup_n3a8(75, 0, 6, 6u);
    *(uint8_t *)(v4 + 4) = *(uint8_t *)(v1 + 58);
    *(uint16_t *)(v4 + 2) = *(uint16_t *)(v1 + 56);
    *(uint8_t *)v4 = *(uint8_t *)(v1 + 61);
    sub_12CBB4(v4);
    v5 = dword_13432C + 696 * v3;
    v6 = 2 - (*(uint32_t *)(v2 + 1208) & 1);
    v7 = __rev16(*(uint16_t *)(v1 + 52));
    *(uint8_t *)(v5 + 52) = v6;
    *(uint16_t *)(v5 + 56) = v7;
    if ( v6 == 2 )
    {
      v8 = (uint8_t *)rf_bus_setup_n3a8(5145, 5, 6, 2u);
      *v8 = 0;
      v8[1] = *(uint8_t *)(v1 + 61);
      sub_12CBB4((int)v8);
    }
    sub_135020(0);
    return 0;
  }
  else
  {
    if ( msg_get_value(6u) == 10 )
      sub_1349D8(10);
    return 0;
  }
}

