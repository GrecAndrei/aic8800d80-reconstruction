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

extern uint32_t dword_13BB0C;
extern uint32_t dword_13BB10;

// rf_get_chan_cfg @ 0x13bac0, size 76 bytes
uint8_t * rf_get_chan_cfg(int a1)
{
  uint8_t *result; // r0
  int v2; // r1
  int v3; // r3

  result = (uint8_t *)(dword_13BB0C + 32 * a1);
  v2 = result[16];
  v3 = result[22];
  if ( result[17] )
  {
    if ( result[17] == 1 )
      *(uint8_t *)(696 * v2 + 12 * v3 + dword_13BB10 + 453) = 33;
  }
  else
  {
    *(uint8_t *)(696 * v2 + 12 * v3 + dword_13BB10 + 452) = 33;
  }
  return result;
}

