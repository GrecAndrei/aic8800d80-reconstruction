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

extern uint32_t off_1302F0;
extern uint32_t dword_1302F4;

// rf_level_step_02c4 @ 0x1302c4, size 44 bytes
// Doc: rf_level_step_02c4 [rf]: Compares two RF level bytes from a control struct
// rf_level_step_02c4 [rf]: Compares two RF level bytes from a control struct
unsigned int rf_level_step_02c4()
{
  uint8_t *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  uint8_t v3; // r0

  v0 = (uint8_t *)off_1302F0;
  result = *((uint8_t *)off_1302F0 + 6);
  v2 = *((uint8_t *)off_1302F0 + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((uint8_t *)off_1302F0 + 6) = v3;
    rf_reg_write_masked(v3);
    return msg_parse(dword_1302F4, v0[5], v0[6]);
  }
  return result;
}

