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

// sub_126E54 @ 0x126e54, size 38 bytes
// Doc: rf_level_apply_helper [rf]: RF level apply helper routine
// rf_level_apply_helper [rf]: RF level apply helper routine
int sub_126E54()
{
  if ( *((uint8_t *)rf_level_apply_na4 + 1) )
    return *((char *)rf_level_apply_na4 + 3);
  sub_10DE98();
  return (int)COERCE_FLOAT(sub_10DEF0());
}

