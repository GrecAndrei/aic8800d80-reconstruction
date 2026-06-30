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

extern uint32_t off_100684;

// variant_update_cache @ 0x100670, size 18 bytes
// Doc: variant_update_cache [util]: Update cached variant byte from result
// variant_update_cache [util]: Update cached variant byte from result
int  variant_update_cache(int a1)
{
  int result; // r0

  result = fw_init_setup(a1);
  if ( *(uint8_t *)off_100684 != result )
    *(uint8_t *)off_100684 = result;
  return result;
}

