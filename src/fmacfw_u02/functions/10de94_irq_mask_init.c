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

extern uint32_t off_10DEF4;
extern uint32_t dword_10DEF8;
extern uint32_t off_10DEFC;
extern uint32_t off_10DF04;
extern uint32_t dword_10DF08;
extern uint32_t off_10DF00;

// gpio_init_sequence @ 0x10de94, size 94 bytes
// Doc: gpio_init_sequence [util]: Initialize IRQ masks via enable/disable
// gpio_init_sequence [util]: Initialize IRQ masks via enable/disable
int gpio_init_sequence()
{
  uint32_t *v0; // r1
  uint32_t *v1; // r3
  int result; // r0

  switch_on_arg(1);
  rf_enable_irq(1);
  switch_on_arg(2);
  rf_enable_irq(2);
  if ( *((uint8_t *)off_10DEF4 + 369) )
  {
    gpio_set_bit(1);
    gpio_set_bit(2);
  }
  else
  {
    gpio_clear_bit(1);
    gpio_clear_bit(2);
  }
  rf_disable_irq(3);
  gpio_configure_pin(3, 2, dword_10DEF8);
  v0 = off_10DEFC;
  v1 = off_10DF04;
  result = dword_10DF08;
  *((uint32_t *)off_10DEFC + 1) = off_10DF00;
  v1[1] = result;
  v1[2] = 0;
  v0[2] = 0;
  return result;
}

