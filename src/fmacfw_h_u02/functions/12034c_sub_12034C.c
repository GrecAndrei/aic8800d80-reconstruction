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

// alloc_shared_packet @ 0x12034c, size 26 bytes
int  alloc_shared_packet(int a1)
{
  uint32_t *v2; // r0

  v2 = (uint32_t *)tx_send_pdu(143, 0, 255, 4);
  *v2 = a1;
  return rx_process_packet(v2);
}

