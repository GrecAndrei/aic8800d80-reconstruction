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

// register_irq_handler @ 0x1207c4, size 26 bytes
int  register_irq_handler(int a1)
{
  uint32_t *v2; // r0

  v2 = (uint32_t *)bt_buf_alloc(143, 0, 255, 4);
  *v2 = a1;
  return hci_evt_send(v2);
}

