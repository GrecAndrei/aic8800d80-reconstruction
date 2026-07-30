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

extern uint32_t off_10297C;
extern uint32_t off_102980;

// rf_msg_handler_n_13a @ 0x10294c, size 48 bytes
// Doc: rf_msg_handler_n_13a [rf]: Handle incoming RF message and clear flag
// rf_msg_handler_n_13a [rf]: Handle incoming RF message and clear flag
int rf_msg_handler_n_13a()
{
  int result; // r0
  int *i; // r4

  result = sub_1009A0(*((uint8_t *)off_10297C + 36), *((uint16_t *)off_10297C + 20));
  for ( i = *((int **)off_102980 + 2); i; i = (int *)*i )
  {
    while ( !*((uint8_t *)i + 108) )
    {
      i = (int *)*i;
      if ( !i )
        return result;
    }
    result = message_dispatch_c7ac(i);
  }
  return result;
}

