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

// tx_buf_alloc @ 0x11cd0c, size 40 bytes
uint32_t * tx_buf_alloc(char a1, uint16_t a2)
{
  char *v3; // r4

  v3 = (char *)ke_msg_send_1(2052, a2, 2, 1);
  check_interrupt_flag(4, "%s\r\n", aScanSendCancel);
  *v3 = a1;
  return rx_irq_handler_1((int)v3);
}
