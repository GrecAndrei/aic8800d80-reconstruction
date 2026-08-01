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

extern uint32_t off_10E290;
extern uint32_t dword_10E270;
extern uint32_t dword_10E274;
extern uint32_t dword_10E278;
extern uint32_t dword_10E27C;
extern uint32_t dword_10E280;
extern uint32_t dword_10E284;
extern uint32_t dword_10E294;
extern uint32_t dword_10E298;
extern uint32_t dword_10E288;
extern uint32_t dword_10E28C;
extern uint32_t dword_10E29C;

// rf_core_power_on @ 0x10e1e8, size 130 bytes
int rf_core_power_on()
{
  uint32_t *v0; // r2
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  int v4; // r0
  float v5; // r0
  uint64_t v6; // r0
  uint64_t v7; // r0
  uint64_t v8; // r0
  uint64_t v9; // r0
  uint64_t v10; // r0
  int v11; // r0

  v0 = off_10E290;
  *((uint32_t *)off_10E290 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = uint_to_double(v0[4]);
  v2 = double_add(v1, HIDWORD(v1), dword_10E270, dword_10E274);
  v3 = double_subtract(v2, HIDWORD(v2), dword_10E278, dword_10E27C);
  v4 = double_compare_wrapper(v3, HIDWORD(v3), dword_10E270, dword_10E274);
  v5 = double_to_uint(v4);
  v6 = float_to_double(LODWORD(v5));
  v7 = double_subtract(v6, HIDWORD(v6), dword_10E280, dword_10E284);
  v8 = double_add(v7, HIDWORD(v7), 0, dword_10E294);
  v9 = double_add(v8, HIDWORD(v8), 0, dword_10E298);
  v10 = double_add(v9, HIDWORD(v9), dword_10E288, dword_10E28C);
  v11 = double_subtract(v10, HIDWORD(v10), 0, dword_10E29C);
  return (int)double_to_uint(v11);
}

