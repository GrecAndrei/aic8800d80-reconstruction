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

extern uint32_t dword_126DD4;

// rf_level_step @ 0x126da4, size 44 bytes
// Doc: rf_level_apply_n_a [rf]: applies RF level/threshold configuration
// rf_level_apply_n_a [rf]: applies RF level/threshold configuration
unsigned int rf_level_step()
{
  uint8_t *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  uint8_t v3; // r0

  v0 = (uint8_t *)rf_level_apply_n_8;
  result = *((uint8_t *)rf_level_apply_n_8 + 6);
  v2 = *((uint8_t *)rf_level_apply_n_8 + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((uint8_t *)rf_level_apply_n_8 + 6) = v3;
    sub_10F170(v3);
    return msg_parse(dword_126DD4, v0[5], v0[6]);
  }
  return result;
}

