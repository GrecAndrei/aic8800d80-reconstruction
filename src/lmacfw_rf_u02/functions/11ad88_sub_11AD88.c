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

// time_delta @ 0x11ad88, size 70 bytes
// Doc: sub_121AD88 [unknown]: Resolve two symbol pointers and compute difference between resolved addresses
// sub_121AD88 [unknown]: Resolve two symbol pointers and compute difference between resolved addresses
BOOL  time_delta(int a1, int a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r5
  int v6; // r6
  int v7; // r0

  v3 = *(uint32_t *)(a1 + 4);
  v4 = os_get_tick_hz();
  v5 = *(uint32_t *)(a2 + 4);
  v6 = v4;
  v7 = os_get_tick_hz();
  return v3 - v5 < 0 && v5 - 14000 - v3 - v6 < 0 || v5 - v3 < 0 && v3 - v5 - 14000 - v7 < 0 || v3 == v5;
}

