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

extern uint32_t dword_12ADE8;

// calc_channel_rate @ 0x12adc8, size 30 bytes
int  calc_channel_rate(int a1, int a2, int a3)
{
  int v3; // r3
  unsigned int v4; // r2
  int result; // r0

  v3 = dword_12ADE8;
  v4 = (unsigned int)(1967 * a2 * a3) >> 16;
  result = dword_12ADE8 + 32 * a1;
  if ( v4 )
    *(uint32_t *)(result + 24) = v4;
  else
    v3 = 1;
  if ( !v4 )
    *(uint32_t *)(result + 24) = v3;
  return result;
}

