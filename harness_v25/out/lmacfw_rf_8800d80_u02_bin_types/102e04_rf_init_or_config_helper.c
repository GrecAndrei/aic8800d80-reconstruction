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

// rf_init_or_config_helper @ 0x102e04, size 60 bytes
// Doc: rf_init_or_config_helper [rf]: RF firmware initialization/config helper saving r4-r6,lr
// rf_init_or_config_helper [rf]: RF firmware initialization/config helper saving r4-r6,lr
int  rf_init_or_config_helper(int a1)
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
  lmac_sub_init(0, 32, 0x10u, SHIDWORD(v1));
  lmac_sub_init(0, 48, 0x10u, v1);
  return lmac_sub_init(0, 64, 0x10u, v2);
}

