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

extern uint32_t dword_107F50;
extern uint32_t dword_107F4C;

// div3_compute @ 0x107ee4, size 104 bytes
// Doc: div3_compute [mmio]: Loads MMIO base addresses and validates/checks init structure pointer
// div3_compute [mmio]: Loads MMIO base addresses and validates/checks init structure pointer
int * div3_compute(int *a1)
{
  int v1; // r2
  int v2; // r7
  int v3; // r1
  int v4; // r12
  int v5; // r5
  int v6; // r6
  int *result; // r0
  int i; // r4
  int v9; // r2
  int *v10; // r3

  v1 = a1[1];
  v2 = ((unsigned uint64_t)(dword_107F50 * (uint64_t)v1) >> 32) - (v1 >> 31);
  v3 = a1[3] - v1 / 2 + v2 + (v1 >> 31) - ((unsigned uint64_t)(dword_107F4C * (uint64_t)v1) >> 32);
  v4 = ((unsigned uint64_t)(dword_107F50 * (uint64_t)*a1) >> 32) - (*a1 >> 31);
  v5 = (*a1 >> 31) - ((unsigned uint64_t)(dword_107F4C * (uint64_t)*a1) >> 32);
  v6 = a1[2] - *a1 / 2 + v4;
  result = a1 + 7;
  for ( i = 0; i != 9; i += 3 )
  {
    v9 = v6 + v5;
    v10 = result - 3;
    do
    {
      *v10++ = v9;
      v9 += v4;
      v10[8] = v3;
    }
    while ( v10 != result );
    v3 += v2;
    result = v10 + 3;
  }
  return result;
}

