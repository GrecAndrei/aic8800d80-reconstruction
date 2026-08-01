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

extern uint32_t off_133910;

// ipc_call_6_ret5 @ 0x1338c8, size 72 bytes
int ipc_call_6_ret5()
{
  if ( hci_cmd_handler(6u) != 5 && hci_cmd_handler(6u) != 6 && hci_cmd_handler(6u) != 7 && hci_cmd_handler(6u) != 8 )
    return 0;
  if ( *((uint8_t *)off_133910 + 34) )
  {
    *((uint8_t *)off_133910 + 34) = 0;
    return 0;
  }
  assert_trace(1);
  return 0;
}

