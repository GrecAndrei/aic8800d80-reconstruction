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

extern uint32_t off_102E40;
extern uint32_t off_102E44;

// dma_init @ 0x102e04, size 60 bytes
// Doc: dma_init [rf]: RF firmware initialization/config helper saving r4-r6,lr
// dma_init [rf]: RF firmware initialization/config helper saving r4-r6,lr
int  dma_init(int a1)
{
  uint64_t v1; // kr00_8
  int v2; // r4

  if ( a1 )
  {
    v1 = *(uint64_t *)((char *)off_102E40 + 4);
    v2 = *(uint32_t *)off_102E40;
  }
  else
  {
    v2 = *(uint32_t *)off_102E44;
    v1 = *(uint64_t *)((char *)off_102E44 + 4);
  }
  memcpy_advance(0, 32, 0x10u, SHIDWORD(v1));
  memcpy_advance(0, 48, 0x10u, v1);
  return memcpy_advance(0, 64, 0x10u, v2);
}

