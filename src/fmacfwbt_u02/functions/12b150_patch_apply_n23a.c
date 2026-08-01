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

extern uint32_t dword_12B184;
extern uint32_t off_12B188;

// ke_timer_schedule @ 0x12b150, size 48 bytes
// Doc: ke_timer_schedule [patch]: Applies RF patch by ORR-ing bit and storing configuration
// ke_timer_schedule [patch]: Applies RF patch by ORR-ing bit and storing configuration
int  ke_timer_schedule(int a1, int a2, int a3, int a4)
{
  int value; // r4

  value = hci_cmd_send_short(2);
  state_check_feature(4, dword_12B184);
  if ( value )
    *((uint8_t *)off_12B188 + 11) = 1;
  else
    bt_send_hci_804(1, a4);
  return 0;
}

