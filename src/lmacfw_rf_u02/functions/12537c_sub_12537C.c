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


extern uint32_t off_1253B0;

// bt_conditional_action @ 0x12537c, size 50 bytes
int  bt_conditional_action(int a1, int a2)
{
  BOOL v2; // r1

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1("txpwr_manual_mode: %x\r\n", *(uint32_t *)off_1253B0);
  }
  else
  {
    v2 = parse_number(*(uint8_t **)(a2 + 4), nullptr, 0) != 0;
    *(uint32_t *)off_1253B0 = v2;
    dispatch_event_handler_1("set txpwr_manual_mode: %x\r\n", v2);
  }
  return 0;
}
