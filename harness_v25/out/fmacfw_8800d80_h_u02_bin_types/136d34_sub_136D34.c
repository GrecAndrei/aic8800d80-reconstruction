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

extern uint32_t dword_136D44;
extern uint32_t off_136D40;

// sub_136D34 @ 0x136d34, size 12 bytes
int sub_136D34()
{
  int v0; // r0

  v0 = dword_136D44;
  *(uint8_t *)off_136D40 = 1;
  return sub_12E948(v0);
}

