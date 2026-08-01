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

extern uint32_t off_10DFE0;
extern uint32_t off_10DFE4;
extern uint32_t dword_10DFE8;
extern uint32_t dword_10DFEC;
extern uint32_t dword_10DFC8;
extern uint32_t dword_10DFCC;
extern uint32_t dword_10DFD0;
extern uint32_t dword_10DFD4;
extern uint32_t dword_10DFD8;
extern uint32_t dword_10DFDC;

// rf_core_reset @ 0x10df48, size 128 bytes
int rf_core_reset()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r3
  int v2; // r1
  int v3; // r2
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  int v7; // r0

  v0 = off_10DFE0;
  v1 = off_10DFE4;
  v2 = dword_10DFE8;
  v3 = dword_10DFEC;
  *(uint32_t *)off_10DFE4 = 0;
  v0[14] = 296;
  v1[2] = v1[2] & 0xF000FFFF | 0x2000000;
  v1[3] = v2 & v1[3] | 0xA06A000;
  v1[3] = v3 & v1[3] | 0x100230;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v4 = uint_to_double(v1[4]);
  v5 = double_add(v4, HIDWORD(v4), dword_10DFC8, dword_10DFCC);
  v6 = double_subtract(v5, HIDWORD(v5), dword_10DFD0, dword_10DFD4);
  v7 = double_compare_wrapper(v6, HIDWORD(v6), dword_10DFD8, dword_10DFDC);
  return double_to_uint(v7);
}

