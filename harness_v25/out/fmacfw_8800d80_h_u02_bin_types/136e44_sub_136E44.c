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

extern uint32_t dword_136E60;
extern uint32_t off_136E5C;

// sub_136E44 @ 0x136e44, size 22 bytes
int  sub_136E44(int a1, int a2, int a3, int a4)
{
  sub_12EB90(8, dword_136E60, a4, *((uint16_t *)off_136E5C + 1924));
  return 2;
}

