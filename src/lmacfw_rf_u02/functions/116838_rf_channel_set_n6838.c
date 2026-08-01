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

// rate_index_lookup_fast @ 0x116838, size 4 bytes
// Doc: rate_index_lookup_fast [rf]: Set RF channel by querying current state and applying delta (sub 1)
// rate_index_lookup_fast [rf]: Set RF channel by querying current state and applying delta (sub 1)
// attributes: thunk
int  rate_index_lookup_fast(int a1, int a2, int a3)
{
  return rate_index_lookup(a1, a2, a3);
}

