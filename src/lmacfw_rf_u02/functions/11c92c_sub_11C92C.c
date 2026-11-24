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


extern uint32_t off_11C990;
extern uint32_t off_11C998;

// ke_timer_update @ 0x11c92c, size 98 bytes
int ke_timer_update()
{
  int v0; // r5
  int v1; // r4
  int v2; // r0

  v0 = *(uint32_t *)off_11C990;
  v1 = *(uint8_t *)(off_11C990 + 0xA);
  if ( flash_write_byte(2u) != 2 )
  {
    v2 = flash_write_byte(2u);
    dispatch_event_handler_1("start st=%d\n", v2);
  }
  if ( **(uint16_t **)off_11C998 < 0 && flash_write_byte(2u) != 2 )
    flash_ctrl_init((int)aKeStateGetTask_2, (int)aMmScanChannelS, 163);
  if ( (*(uint8_t *)(v0 + 6 * v1 + 3) & 1) == 0 )
    ll_rx_handler();
  flash_erase_sector(2u, 3);
  return 0;
}
