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

extern uint32_t off_13039C;

// sub_130374 @ 0x130374, size 38 bytes
int sub_130374()
{
  if ( *((uint8_t *)off_13039C + 1) )
    return *((char *)off_13039C + 3);
  rf_cmd_send_1();
  return (int)COERCE_FLOAT(rf_hw_timer_read());
}

