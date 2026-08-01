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

// kernel_send_evt @ 0x119170, size 30 bytes
int  kernel_send_evt(int a1)
{
  uint8_t *v2; // r0

  v2 = (uint8_t *)ke_msg_send(67, 4, 0, 1);
  *v2 = *(uint8_t *)(a1 + 95);
  return rx_irq_handler(v2);
}

