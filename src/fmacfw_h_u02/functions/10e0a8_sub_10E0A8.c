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

extern uint32_t off_10E150;
extern uint32_t dword_10E130;
extern uint32_t dword_10E134;
extern uint32_t dword_10E138;
extern uint32_t dword_10E13C;
extern uint32_t dword_10E140;
extern uint32_t dword_10E144;
extern uint32_t dword_10E154;
extern uint32_t dword_10E158;
extern uint32_t dword_10E148;
extern uint32_t dword_10E14C;
extern uint32_t dword_10E15C;

// hw_ctrl_set @ 0x10e0a8, size 130 bytes
int hw_ctrl_set()
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

  v0 = off_10E150;
  *((uint32_t *)off_10E150 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = unsigned_int_to_double(v0[4]);
  v2 = double_compare_common(v1, HIDWORD(v1), dword_10E130, dword_10E134);
  v3 = double_compare_core(v2, HIDWORD(v2), dword_10E138, dword_10E13C);
  v4 = double_compare_neg(v3, HIDWORD(v3), dword_10E130, dword_10E134);
  v5 = double_to_int(v4);
  v6 = float_to_double(LODWORD(v5));
  v7 = double_compare_core(v6, HIDWORD(v6), dword_10E140, dword_10E144);
  v8 = double_compare_common(v7, HIDWORD(v7), 0, dword_10E154);
  v9 = double_compare_common(v8, HIDWORD(v8), 0, dword_10E158);
  v10 = double_compare_common(v9, HIDWORD(v9), dword_10E148, dword_10E14C);
  v11 = double_compare_core(v10, HIDWORD(v10), 0, dword_10E15C);
  return (int)double_to_int(v11);
}

