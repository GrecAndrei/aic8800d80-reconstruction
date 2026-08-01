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

// flash_erase_main @ 0x111d44, size 36 bytes
// Doc: rf_bus_reset2_n35f [rf]: Stub returning immediately (bx lr) for RF bus reset variant
// rf_bus_reset2_n35f [rf]: Stub returning immediately (bx lr) for RF bus reset variant
int * flash_erase_main(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)unknown_16(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return unknown_15(a2, 0x8000000, 0);
  }
  return result;
}

