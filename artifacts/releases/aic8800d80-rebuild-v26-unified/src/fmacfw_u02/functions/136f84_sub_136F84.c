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

extern uint32_t dword_136FA0;
extern uint32_t off_136F9C;

// sub_136F84 @ 0x136f84, size 22 bytes
int  sub_136F84(int a1, int a2, int a3, int a4)
{
  sub_12ECD0(8, dword_136FA0, a4, *((uint16_t *)off_136F9C + 1924));
  return 2;
}

