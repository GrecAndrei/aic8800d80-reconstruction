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

// hci_build_event_0x3a @ 0x119b2c, size 32 bytes
// Doc: hci_build_event_0x3a [util]: Load a single parameter byte and dispatch to handler
// hci_build_event_0x3a [util]: Load a single parameter byte and dispatch to handler
int  hci_build_event_0x3a(int a1, uint8_t *a2, int a3, int a4)
{
  bt_conn_rx_schedule(*a2);
  ke_evt_handler(58, a4, a3);
  return 0;
}

