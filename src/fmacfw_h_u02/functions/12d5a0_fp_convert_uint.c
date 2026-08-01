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

extern uint32_t dword_12D5C0;
extern uint32_t dword_12D5C4;

// log_float_converted @ 0x12d5a0, size 26 bytes
// Doc: log_float_converted [util]: Convert value via float helpers and pack into uint64
// log_float_converted [util]: Convert value via float helpers and pack into uint64
float  log_float_converted(unsigned int a1)
{
  float v1; // r0
  uint64_t v2; // r0
  int v3; // r0

  v1 = f32_to_f16(a1);
  v2 = float_to_double(LODWORD(v1));
  v3 = double_compare_common(v2, HIDWORD(v2), dword_12D5C0, dword_12D5C4);
  return double_to_int(v3);
}

