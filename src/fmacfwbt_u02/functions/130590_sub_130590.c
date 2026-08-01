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

extern uint32_t off_1305B8;

// ke_event_handler @ 0x130590, size 38 bytes
int ke_event_handler()
{
  if ( *((uint8_t *)off_1305B8 + 1) )
    return *((char *)off_1305B8 + 3);
  gpio_reset();
  return (int)COERCE_FLOAT(wait_radio_ready());
}

