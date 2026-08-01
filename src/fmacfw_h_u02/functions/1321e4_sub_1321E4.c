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

// ke_malloc_wrapper @ 0x1321e4, size 48 bytes
int  ke_malloc_wrapper(int a1)
{
  uint8_t *v2; // r4

  v2 = (uint8_t *)tx_send_pdu(12, 0, 5, 1u);
  ke_event_schedule(a1);
  *v2 = a1;
  rx_process_packet((int)v2);
  return mac_write_header_word(5130, 13, 5);
}

