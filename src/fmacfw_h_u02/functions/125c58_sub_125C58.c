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

extern uint32_t off_125C84;

// ipc_post_msg @ 0x125c58, size 42 bytes
int  ipc_post_msg(int a1)
{
  uint8_t *v2; // r0
  uint32_t *v3; // r2

  v2 = (uint8_t *)tx_send_pdu(72, *(uint16_t *)(a1 + 14), 0, 2);
  v2[1] = *(uint8_t *)(a1 + 24);
  v3 = off_125C84;
  *v2 = *(uint8_t *)(a1 + 26);
  *v3 &= ~4u;
  return rx_process_packet(v2);
}

