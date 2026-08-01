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

// hci_build_event_0x36 @ 0x119b90, size 32 bytes
int  hci_build_event_0x36(int a1, uint8_t *a2, int a3, int a4)
{
  lookup_7byte_channel(*a2);
  ke_evt_handler(54, a4, a3);
  return 0;
}

