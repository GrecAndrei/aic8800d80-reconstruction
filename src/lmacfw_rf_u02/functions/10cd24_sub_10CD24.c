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

extern uint32_t off_10CD58;
extern uint32_t off_10CD5C;
extern uint32_t off_10CD64;
extern uint32_t off_10CD60;
extern uint32_t off_10CD68;

// wait_for_uart_event @ 0x10cd24, size 52 bytes
int wait_for_uart_event()
{
  int v0; // r4
  int result; // r0
  int *v2; // r2
  uint8_t *v3; // r3
  uint32_t *v4; // r2

  v0 = *(uint32_t *)off_10CD58 & 0xF00;
  if ( v0 )
  {
    result = set_busy_flag_alt(0x10000);
    v2 = (int *)off_10CD5C;
    v3 = off_10CD64;
    *(uint32_t *)off_10CD60 = v0;
    *v2 = v0;
    if ( *v3 )
    {
      v4 = off_10CD68;
      v3[1] = 1;
      *v4 |= 1u;
    }
  }
  return result;
}

