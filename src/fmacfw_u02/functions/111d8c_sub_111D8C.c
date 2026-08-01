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

// flash_write_data @ 0x111d8c, size 40 bytes
// Doc: rf_bus_write_d94 [rf]: Write value to RF bus with type dispatch
// rf_bus_write_d94 [rf]: Write value to RF bus with type dispatch
int * flash_write_data(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)unknown_16(a2, 0x8000000, 0x200000);
  }
  else if ( a2 <= 5 )
  {
    return unknown_15(a2, 0x8000000, 0x200000);
  }
  return result;
}

