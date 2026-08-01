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

// timer_start_reset @ 0x119d58, size 22 bytes
// Doc: sub_1219D58 [rf]: Unknown helper in lmacfw_rf image (reconstructed flow)
// sub_1219D58 [rf]: Unknown helper in lmacfw_rf image (reconstructed flow)
int  timer_start_reset(int a1, int a2, int a3, int a4)
{
  ke_evt_handler(1, a4, a3);
  flash_erase_sector(0);
  return 0;
}

