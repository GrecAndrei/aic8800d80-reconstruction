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

extern uint32_t dword_12DD04;

// log_format_message @ 0x12dce0, size 36 bytes
uint8_t * log_format_message(uint8_t *a1, int a2)
{
  uint8_t *result; // r0
  uint16_t v3[3]; // [sp+Eh] [bp-6h] BYREF

  result = mem_range_setup(a1, a2, (uint8_t *)dword_12DD04, 5, v3);
  if ( result )
  {
    if ( v3[0] != 26 )
      return 0;
  }
  return result;
}

