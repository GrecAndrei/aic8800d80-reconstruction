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

extern uint32_t off_11B738;
extern uint32_t off_11B73C;
extern uint32_t off_11B734;

// rf_reg_update @ 0x11b6f0, size 68 bytes
int rf_reg_update()
{
  int *v0; // r4
  int v1; // r5
  int result; // r0

  v0 = *((int **)off_11B738 + 2);
  v1 = *((uint32_t *)off_11B73C + 10);
  for ( *(uint32_t *)off_11B734 &= ~4u; v0; v0 = (int *)*v0 )
  {
    while ( v0[18] != v1 || *((uint8_t *)v0 + 94) || !*((uint8_t *)v0 + 96) )
    {
      v0 = (int *)*v0;
      if ( !v0 )
        return result;
    }
    result = rate_index_lookup_fast(
               *((uint8_t *)v0 + 102),
               *((uint8_t *)v0 + 94),
               *((uint8_t *)v0 + 94));
  }
  return result;
}

