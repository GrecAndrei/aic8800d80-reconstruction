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

extern uint32_t dword_115388;
extern uint32_t off_11538C;

// patch_init @ 0x115354, size 50 bytes
void __noreturn patch_init()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r1
  int v4; // r2

  log_printf(dword_115388);
  if ( *(uint8_t *)(*(uint32_t *)off_11538C + 6) == 2 )
  {
    v2 = patch_get_state();
    rf_set_channel(v2, v3, v4);
  }
  while ( 1 )
  {
    while ( !gpio_read_pin() )
      ;
    v0 = gpio_read();
    v1 = find_by_index(v0);
    parse_large_ioctl(v1);
  }
}

