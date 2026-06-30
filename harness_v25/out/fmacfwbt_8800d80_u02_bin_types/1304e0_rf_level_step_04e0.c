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

extern uint32_t off_13050C;
extern uint32_t dword_130510;

// rf_level_step_04e0 @ 0x1304e0, size 44 bytes
// Doc: rf_level_step_04e0 [rf]: Step RF TX power level by configured delta
// rf_level_step_04e0 [rf]: Step RF TX power level by configured delta
unsigned int rf_level_step_04e0()
{
  uint8_t *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  uint8_t v3; // r0

  v0 = (uint8_t *)off_13050C;
  result = *((uint8_t *)off_13050C + 6);
  v2 = *((uint8_t *)off_13050C + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((uint8_t *)off_13050C + 6) = v3;
    sub_10ED90(v3);
    return sub_12ECB0(dword_130510, v0[5], v0[6]);
  }
  return result;
}

