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

extern uint32_t off_115694;

// system_init @ 0x115674, size 32 bytes
int system_init()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((uint8_t *)off_115694 + 1) = 0;
  v0 = lock_init_0x18274c();
  v1 = vendor_platform_init(v0);
  v2 = get_rf_state(v1);
  v3 = update_modulation_mode(v2);
  return timer_init_0x1922d4(v3);
}

