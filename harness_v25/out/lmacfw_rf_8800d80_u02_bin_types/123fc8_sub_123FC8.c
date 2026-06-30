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

extern uint32_t off_123FD8;

// sub_123FC8 @ 0x123fc8, size 16 bytes
int  sub_123FC8(int result)
{
  *(uint32_t *)off_123FD8 = *(uint32_t *)off_123FD8 & 0xFFFEFFFF | (result << 16);
  return result;
}

