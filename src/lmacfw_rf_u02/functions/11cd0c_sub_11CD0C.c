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

extern uint32_t dword_11CD38;
extern uint32_t dword_11CD34;

// tx_buf_alloc @ 0x11cd0c, size 40 bytes
// Doc: sub_121CD0C [util]: Init function calling helper with arg 0x804
// sub_121CD0C [util]: Init function calling helper with arg 0x804
int  tx_buf_alloc(char a1, int a2)
{
  uint8_t *v3; // r4
  int v4; // r3

  v3 = (uint8_t *)ke_msg_send(2052, a2, 2, 1);
  check_interrupt_flag(4, dword_11CD38, dword_11CD34, v4);
  *v3 = a1;
  return rx_irq_handler(v3);
}

