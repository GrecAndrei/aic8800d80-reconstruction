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

extern uint32_t off_10D5D8;

// log_hw_init_if @ 0x10d5cc, size 12 bytes
// Doc: log_hw_init_if [util]: Initialize logging hardware (NVIC IRQ enable)
// log_hw_init_if [util]: Initialize logging hardware (NVIC IRQ enable)
void log_hw_init_if()
{
  if ( !*(uint32_t *)off_10D5D8 )
    log_hw_init();
}

