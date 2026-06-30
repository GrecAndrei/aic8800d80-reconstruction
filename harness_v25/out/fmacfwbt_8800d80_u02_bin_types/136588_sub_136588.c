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

extern uint32_t off_136614;
extern uint32_t dword_136624;
extern uint32_t dword_13661C;
extern uint32_t off_136618;
extern uint32_t dword_136620;

// sub_136588 @ 0x136588, size 140 bytes
int sub_136588()
{
  int16_t **v0; // r4

  v0 = (int16_t **)off_136614;
  if ( **(int16_t **)off_136614 < 0 && msg_get_value(7u) != 1 && msg_get_value(7u) && msg_get_value(7u) != 3 )
    sub_12F694(dword_136624, dword_13661C, 341);
  if ( msg_get_value(7u) == 1 )
  {
    if ( **v0 < 0 && *((uint32_t *)off_136618 + 1) )
      sub_12F694(dword_136620, dword_13661C, 349);
    sub_136AE8();
  }
  else if ( msg_get_value(7u) == 3 )
  {
    message_dispatch_n84(7171, 13, 7);
    rf_bus_mark_n_3b7(7u, 0);
  }
  return 0;
}

