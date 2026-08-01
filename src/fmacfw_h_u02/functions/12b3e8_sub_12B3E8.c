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

extern uint32_t off_12B3FC;

// hci_buffer_get @ 0x12b3e8, size 20 bytes
int  hci_buffer_get(int a1)
{
  if ( (*(uint8_t *)(a1 + 3) & 5) != 0 )
    return *(uint32_t *)(*(uint32_t *)off_12B3FC + 20);
  else
    return get_event_payload((uint16_t *)a1);
}

