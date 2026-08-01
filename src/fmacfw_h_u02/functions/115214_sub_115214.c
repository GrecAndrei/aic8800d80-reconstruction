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

extern uint32_t dword_115248;
extern uint32_t off_11524C;

// log_boot_message @ 0x115214, size 50 bytes
void __noreturn log_boot_message()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r1
  int v4; // r2

  debug_printf(dword_115248);
  if ( *(uint8_t *)(*(uint32_t *)off_11524C + 6) == 2 )
  {
    v2 = get_phy_state();
    rf_set_frequency(v2, v3, v4);
  }
  while ( 1 )
  {
    while ( !radio_rx_status() )
      ;
    v0 = radio_rx_read_byte();
    v1 = lock_with_timeout(v0);
    rf_calibration_proc(v1);
  }
}

