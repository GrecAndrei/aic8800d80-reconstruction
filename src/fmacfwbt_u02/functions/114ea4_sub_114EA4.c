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

// syscall6_get_status @ 0x114ea4, size 44 bytes
// Doc: sub_1214EA4 [util]: Helper calling indirect function with arg 6 and inspecting high byte
// sub_1214EA4 [util]: Helper calling indirect function with arg 6 and inspecting high byte
int  syscall6_get_status(uint8_t *a1)
{
  int16_t v2; // r0

  v2 = MEMORY[0x1FC](6);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (uint8_t)v2 )
      return 1;
    else
      return 2;
  }
}

