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

// sub_111BA0 @ 0x111ba0, size 36 bytes
// Doc: rf_bus_write2_n12e [rf]: RF bus write variant dispatch on parameter
// rf_bus_write2_n12e [rf]: RF bus write variant dispatch on parameter
int * sub_111BA0(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_bus_write2_1a78(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return sub_1119C0(a2, 0x8000000, 0);
  }
  return result;
}

