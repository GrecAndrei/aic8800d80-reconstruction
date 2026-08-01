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

extern uint32_t off_10DD4C;
extern uint32_t dword_10DD50;
extern uint32_t off_10DD54;
extern uint32_t off_10DD5C;
extern uint32_t dword_10DD60;
extern uint32_t off_10DD58;

// init_oscillators @ 0x10dcec, size 94 bytes
int init_oscillators()
{
  uint32_t *v0; // r1
  uint32_t *v1; // r3
  int result; // r0

  irq_set_priority(1);
  gpio_set_bit_reg8(1);
  irq_set_priority(2);
  gpio_set_bit_reg8(2);
  if ( *((uint8_t *)off_10DD4C + 369) )
  {
    gpio_set_bit_reg0(1);
    gpio_set_bit_reg0(2);
  }
  else
  {
    gpio_clear_bit_reg0(1);
    gpio_clear_bit_reg0(2);
  }
  gpio_clear_bit_reg8(3);
  gpio_pin_config(3, 2, dword_10DD50);
  v0 = off_10DD54;
  v1 = off_10DD5C;
  result = dword_10DD60;
  *((uint32_t *)off_10DD54 + 1) = off_10DD58;
  v1[1] = result;
  v1[2] = 0;
  v0[2] = 0;
  return result;
}

