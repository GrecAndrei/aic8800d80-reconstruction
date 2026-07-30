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

// fmac_unknown_handler @ 0x1325f4, size 26 bytes
// Doc: fmac_unknown_handler [unknown]: Unidentified FMAC helper
// fmac_unknown_handler [unknown]: Unidentified FMAC helper
int  fmac_unknown_handler(uint8_t *a1)
{
  if ( a1[3] )
    return 3;
  if ( a1[2] )
    return 2;
  return a1[1] != 0;
}

