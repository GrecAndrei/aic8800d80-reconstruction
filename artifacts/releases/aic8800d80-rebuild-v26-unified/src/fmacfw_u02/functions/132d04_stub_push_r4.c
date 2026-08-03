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

// stub_push_r4 @ 0x132d04, size 18 bytes
// Doc: stub_push_r4 [util]: Minimal stub function preserving r4 register
// stub_push_r4 [util]: Minimal stub function preserving r4 register
uint32_t * stub_push_r4(int a1)
{
  sub_13F834();
  return rx_agg_status_update(a1);
}

