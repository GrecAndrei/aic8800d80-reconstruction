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

extern uint32_t off_14386C;
extern uint32_t dword_143870;
extern uint32_t dword_143874;

// sub_14383C @ 0x14383c, size 46 bytes
int sub_14383C()
{
  unsigned uint64_t v0; // kr00_8

  v0 = *(uint64_t *)(*(uint32_t *)off_14386C + 168) * __PAIR64__(dword_143870, dword_143874) + 1;
  *(uint64_t *)(*(uint32_t *)off_14386C + 168) = v0;
  return HIDWORD(v0) & 0x7FFFFFFF;
}

