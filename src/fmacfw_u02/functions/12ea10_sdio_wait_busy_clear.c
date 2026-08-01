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

extern uint32_t off_12EA28;

// ipc_wait_flag @ 0x12ea10, size 24 bytes
// Doc: ipc_wait_flag [mmio]: Polls SDIO status register until busy flag clears
// ipc_wait_flag [mmio]: Polls SDIO status register until busy flag clears
void ipc_wait_flag()
{
  while ( (*(uint32_t *)off_12EA28 & 0x40000) == 0 )
    ;
}

