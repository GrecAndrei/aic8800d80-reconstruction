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

extern uint32_t off_13A4D4;

// sub_13A4B0 @ 0x13a4b0, size 36 bytes
uint16_t * sub_13A4B0(uint16_t *result)
{
  uint16_t *v1; // r3

  v1 = off_13A4D4;
  if ( !*((uint8_t *)off_13A4D4 + 115) )
  {
    *((uint16_t *)off_13A4D4 + 54) = *result;
    v1[55] = result[1];
    v1[56] = result[2];
    v1[57] = 256;
  }
  return result;
}

