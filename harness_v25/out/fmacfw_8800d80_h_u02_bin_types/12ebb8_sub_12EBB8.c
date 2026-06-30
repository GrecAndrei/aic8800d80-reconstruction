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

extern uint32_t dword_12EBD8;
extern uint32_t off_12EBDC;

// sub_12EBB8 @ 0x12ebb8, size 32 bytes
int sub_12EBB8()
{
  sub_12E948(dword_12EBD8);
  sub_12C5FC(1071, 1);
  *((uint32_t *)off_12EBDC + 20) &= ~2u;
  return 0;
}

