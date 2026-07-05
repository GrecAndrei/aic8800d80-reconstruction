#include <stdint.h>
#define BYTE1(x) ((uint8_t)(((uint32_t)(x) >> 8) & 0xFFu))
#define BYTE2(x) ((uint8_t)(((uint32_t)(x) >> 16) & 0xFFu))
#define BYTE3(x) ((uint8_t)(((uint32_t)(x) >> 24) & 0xFFu))
#define __noreturn
#define _VF 0
#define _CF 0
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

// buf_alloc_0x68_init @ 0x1193f0, size 14 bytes
// Doc: buf_alloc_0x68_init [util]: Allocate 0x68-byte buffer and return 0 (init helper)
// buf_alloc_0x68_init [util]: Allocate 0x68-byte buffer and return 0 (init helper)
int  buf_alloc_0x68_init(int a1, int a2, int a3, int a4)
{
  sub_11DED8(104, a4, a3);
  return 0;
}

