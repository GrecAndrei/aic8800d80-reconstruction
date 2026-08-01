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

extern uint32_t off_10E0A8;
extern uint32_t dword_10E090;
extern uint32_t dword_10E094;
extern uint32_t dword_10E098;
extern uint32_t dword_10E09C;
extern uint32_t dword_10E0A0;
extern uint32_t dword_10E0A4;

// rf_core_is_ready @ 0x10e048, size 72 bytes
// Doc: rf_core_is_ready [rf]: Reads RF hardware timer register and compares state
// rf_core_is_ready [rf]: Reads RF hardware timer register and compares state
int rf_core_is_ready()
{
  uint32_t *v0; // r3
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  int v4; // r0

  while ( *((uint32_t *)off_10E0A8 + 7) != 1 )
    ;
  v0 = off_10E0A8;
  *((uint32_t *)off_10E0A8 + 7) = 1;
  v1 = uint_to_double(v0[4]);
  v2 = double_add(v1, HIDWORD(v1), dword_10E090, dword_10E094);
  v3 = double_subtract(v2, HIDWORD(v2), dword_10E098, dword_10E09C);
  v4 = double_compare_wrapper(v3, HIDWORD(v3), dword_10E0A0, dword_10E0A4);
  return double_to_uint(v4);
}

