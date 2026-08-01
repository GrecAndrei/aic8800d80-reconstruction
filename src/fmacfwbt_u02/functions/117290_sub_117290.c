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

// tx_check_ready @ 0x117290, size 30 bytes
int  tx_check_ready(int result)
{
  int v1; // r4

  if ( *(uint16_t *)(result + 4) )
  {
    v1 = result;
    result = *(uint32_t *)(result + 72);
    if ( result )
    {
      if ( (*(uint32_t *)(v1 + 36) & 0x200000) == 0 )
      {
        result = memory_pool_free((uint32_t *)result);
        *(uint32_t *)(v1 + 72) = 0;
      }
    }
  }
  return result;
}

