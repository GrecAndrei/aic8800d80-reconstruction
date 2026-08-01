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

extern uint32_t dword_1313F8;

// mem_alloc @ 0x1313d8, size 30 bytes
int  mem_alloc(int a1, int a2, int16_t a3, int16_t a4)
{
  memcpy(dword_1313F8, a2, 254);
  mac_write_header_word(5123, a4, a3);
  return 0;
}

