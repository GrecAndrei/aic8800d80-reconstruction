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

// llc_get_context @ 0x129d68, size 32 bytes
// Doc: llc_get_context [scan]: Acquire next scan channel context
// llc_get_context [scan]: Acquire next scan channel context
int  llc_get_context(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r0
  uint8_t v6; // r4

  v5 = llc_get_context_ptr(a1, a2, a3, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  unknown_worker(a1, v5);
  *(uint8_t *)(a1 + 16) = 1;
  return v6;
}

