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

extern uint32_t dword_115394;
extern uint32_t off_115390;

// sub_115384 @ 0x115384, size 12 bytes
int  sub_115384(int a1, int a2)
{
  int v2; // r0

  v2 = dword_115394;
  *(uint8_t *)off_115390 = 0;
  return sub_12E948(v2, a2, 0);
}

