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

// rf_bus_reset2_n_ec @ 0x11176c, size 74 bytes
// Doc: rf_bus_mark_na6 [rf]: Set RF bus bitfield (mask 0x7E0, value 0x20) on reg 0x10
// rf_bus_mark_na6 [rf]: Set RF bus bitfield (mask 0x7E0, value 0x20) on reg 0x10
int rf_bus_reset2_n_ec()
{
  uint32_t *v0; // r1
  int v1; // r0
  uint32_t *v2; // r3
  int result; // r0

  v0 = *(uint32_t **)rf_bus_write_n_208;
  v1 = *(uint32_t *)rf_bus_write2_n_2bc;
  v2 = rf_bus_reset2_n_98;
  *((uint16_t *)rf_bus_write2_n_2b4 + 5) = 0;
  *v0 = 167772160;
  v0[1] = v1;
  v2[4] = v2[4] & 0xFFFFF81F | 0x20;
  do
    result = v2[4] & 0x20;
  while ( result );
  v2[578] = v2[578];
  v2[581] = v0;
  v2[576] |= 0x84000000;
  return result;
}

