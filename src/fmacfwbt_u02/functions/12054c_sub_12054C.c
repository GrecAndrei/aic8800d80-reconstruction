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

// wlc_bsscfg_detach @ 0x12054c, size 28 bytes
int  wlc_bsscfg_detach(int result)
{
  uint32_t *v1; // r4
  int v2; // r5

  v1 = *(uint32_t **)(result + 240);
  if ( v1 )
  {
    v2 = result;
    do
    {
      result = wlc_bsscfg_down(v2, (int)v1, 0);
      v1 = (uint32_t *)*v1;
    }
    while ( v1 );
  }
  return result;
}

