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

// send_ke_message @ 0x11eb54, size 36 bytes
int  send_ke_message(int a1)
{
  int v2; // r0
  int v3; // r1
  int v4; // r4

  v2 = tx_send_pdu(139, 13, 0, 24);
  v3 = a1;
  v4 = v2;
  memcpy(v2, v3, 24);
  return rx_process_packet(v4);
}

