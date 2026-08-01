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

// copy_config_data @ 0x12de90, size 40 bytes
uint8_t * copy_config_data(uint8_t *a1, int a2, uint8_t *a3)
{
  uint8_t *result; // r0
  uint16_t v5; // [sp+6h] [bp-2h] BYREF

  result = mem_range_check(a1, a2, 35, &v5);
  if ( result )
  {
    if ( (unsigned int)v5 - 24 > 0x21 )
      return 0;
    else
      *a3 = v5 - 3;
  }
  return result;
}

