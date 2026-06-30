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

extern uint32_t dword_135B7C;

// sub_135B4C @ 0x135b4c, size 46 bytes
uint32_t * sub_135B4C(int a1)
{
  sub_12C964(6154, 6);
  if ( !a1 )
    return fmacfwbt_init_handler();
  feature_guard_sdio(256, dword_135B7C, a1);
  return (uint32_t *)sub_135020(a1);
}

