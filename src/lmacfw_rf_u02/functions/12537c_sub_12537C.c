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

extern uint32_t dword_1253B8;
extern uint32_t off_1253B0;
extern uint32_t dword_1253B4;

// bt_conditional_action @ 0x12537c, size 50 bytes
int  bt_conditional_action(int a1, int a2)
{
  BOOL v2; // r1
  int v3; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler(dword_1253B8, *(uint32_t *)off_1253B0);
  }
  else
  {
    v2 = parse_number(*(uint8_t **)(a2 + 4), 0, 0) != 0;
    v3 = dword_1253B4;
    *(uint32_t *)off_1253B0 = v2;
    dispatch_event_handler(v3);
  }
  return 0;
}

