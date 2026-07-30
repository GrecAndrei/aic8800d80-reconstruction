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

extern uint32_t dword_136D58;
extern uint32_t off_136D54;

// sub_136D48 @ 0x136d48, size 12 bytes
int sub_136D48()
{
  int v0; // r0

  v0 = dword_136D58;
  *(uint8_t *)off_136D54 = 0;
  return sub_12E948(v0);
}

