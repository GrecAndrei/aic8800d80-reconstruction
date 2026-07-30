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

extern uint32_t off_136B24;

// sub_136AE8 @ 0x136ae8, size 58 bytes
// Doc: sub_1236AE8 [bt]: Init/dispatch helper, calls 0x12cb54 with constants 0x3f/0/7/0xc
// sub_1236AE8 [bt]: Init/dispatch helper, calls 0x12cb54 with constants 0x3f/0/7/0xc
uint32_t *sub_136AE8()
{
  int v0; // r4
  int v1; // r0
  int16_t v2; // r1
  int16_t v3; // r2

  v0 = *(uint32_t *)off_136B24;
  v1 = rf_bus_setup_n3a8(63, 0, 7, 0xCu);
  v2 = *(uint16_t *)(v0 + 36);
  v3 = *(uint16_t *)(v0 + 38);
  *(uint32_t *)v1 = *(uint32_t *)(v0 + 32);
  *(uint16_t *)(v1 + 4) = v2;
  *(uint16_t *)(v1 + 6) = v3;
  *(uint8_t *)(v1 + 8) = *(uint8_t *)(v0 + 50);
  *(uint8_t *)(v1 + 9) = *(uint8_t *)(v0 + 51);
  sub_12CBB4(v1);
  return rf_bus_mark_n_3b7(7u, 2);
}

