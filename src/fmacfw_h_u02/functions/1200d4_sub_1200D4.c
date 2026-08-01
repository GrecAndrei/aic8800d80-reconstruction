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

// get_hw_tsf @ 0x1200d4, size 28 bytes
int  get_hw_tsf(int result)
{
  uint32_t *v1; // r4
  int v2; // r5

  v1 = *(uint32_t **)(result + 240);
  if ( v1 )
  {
    v2 = result;
    do
    {
      result = is_ll_event_pending(v2, (int)v1, 0);
      v1 = (uint32_t *)*v1;
    }
    while ( v1 );
  }
  return result;
}

