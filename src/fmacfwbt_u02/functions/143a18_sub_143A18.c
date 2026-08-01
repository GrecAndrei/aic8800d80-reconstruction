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

extern uint32_t off_143A48;
extern uint32_t dword_143A4C;
extern uint32_t dword_143A50;

// random @ 0x143a18, size 46 bytes
int random()
{
  unsigned uint64_t v0; // kr00_8

  v0 = *(uint64_t *)(*(uint32_t *)off_143A48 + 168) * __PAIR64__(dword_143A4C, dword_143A50) + 1;
  *(uint64_t *)(*(uint32_t *)off_143A48 + 168) = v0;
  return HIDWORD(v0) & 0x7FFFFFFF;
}

