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

// sub_133C24 @ 0x133c24, size 72 bytes
int sub_133C24()
{
  if ( msg_get_value(6u) != 5 && msg_get_value(6u) != 6 && msg_get_value(6u) != 7 && msg_get_value(6u) != 8 )
    return 0;
  if ( *((uint8_t *)off_133C6C + 34) )
  {
    *((uint8_t *)off_133C6C + 34) = 0;
    return 0;
  }
  sub_135020(1);
  return 0;
}

