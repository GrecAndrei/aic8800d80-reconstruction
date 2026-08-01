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

extern uint32_t dword_110B60;

// set_radio_channel @ 0x110b44, size 28 bytes
uint32_t * set_radio_channel(uint32_t *result, int a2, int a3, uint16_t a4, int a5)
{
  result[2] = dword_110B60 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}

