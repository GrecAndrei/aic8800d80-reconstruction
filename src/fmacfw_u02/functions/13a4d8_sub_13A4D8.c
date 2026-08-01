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

extern uint32_t off_13A4E8;

// clear_flag @ 0x13a4d8, size 14 bytes
int clear_flag()
{
  int result; // r0

  result = *((uint8_t *)off_13A4E8 + 114);
  *((uint16_t *)off_13A4E8 + 57) = 0;
  return result;
}

