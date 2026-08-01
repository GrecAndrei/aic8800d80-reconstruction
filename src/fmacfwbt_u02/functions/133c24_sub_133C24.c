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

extern uint32_t off_133C6C;

// ke_wait_event @ 0x133c24, size 72 bytes
int ke_wait_event()
{
  if ( hci_cmd_send_short(6u) != 5 && hci_cmd_send_short(6u) != 6 && hci_cmd_send_short(6u) != 7 && hci_cmd_send_short(6u) != 8 )
    return 0;
  if ( *((uint8_t *)off_133C6C + 34) )
  {
    *((uint8_t *)off_133C6C + 34) = 0;
    return 0;
  }
  event_dispatch(1);
  return 0;
}

