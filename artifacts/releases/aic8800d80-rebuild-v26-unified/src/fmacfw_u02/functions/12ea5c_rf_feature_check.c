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

extern uint32_t off_12EA84;

// rf_feature_check @ 0x12ea5c, size 40 bytes
// Doc: rf_feature_check [rf]: Check supported RF feature index / capability
// rf_feature_check [rf]: Check supported RF feature index / capability
BOOL  rf_feature_check(unsigned int a1, unsigned int a2)
{
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(uint32_t *)off_12EA84 >> a1) & 1;
  if ( result )
    return *((uint32_t *)off_12EA84 + 1) >= a2;
  return result;
}

