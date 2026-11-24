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

// send_event_42c @ 0x12efb0, size 22 bytes
void  send_event_42c()
{
  char *v0; // r0

  alloc_tx_event(aReboot);
  v0 = invalid_handler_12c5fc((char *)0x42C, 1);
  event_sync((int)v0);
}
