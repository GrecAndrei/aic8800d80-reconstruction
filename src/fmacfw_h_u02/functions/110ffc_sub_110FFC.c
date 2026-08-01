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

extern uint32_t dword_111018;

// tx_desc_set_control @ 0x110ffc, size 28 bytes
uint32_t * tx_desc_set_control(uint32_t *result, int a2, int a3, uint16_t a4, int a5)
{
  result[2] = dword_111018 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}

