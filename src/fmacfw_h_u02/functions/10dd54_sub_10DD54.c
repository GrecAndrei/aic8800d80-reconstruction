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

extern uint32_t off_10DDB4;
extern uint32_t dword_10DDB8;
extern uint32_t off_10DDBC;
extern uint32_t off_10DDC4;
extern uint32_t dword_10DDC8;
extern uint32_t off_10DDC0;

// rf_chain_enable @ 0x10dd54, size 94 bytes
int rf_chain_enable()
{
  uint32_t *v0; // r1
  uint32_t *v1; // r3
  int result; // r0

  rf_irq_clear(1);
  gpio_set_pin(1);
  rf_irq_clear(2);
  gpio_set_pin(2);
  if ( *((uint8_t *)off_10DDB4 + 369) )
  {
    mmio_set_bit(1);
    mmio_set_bit(2);
  }
  else
  {
    mmio_clear_bit(1);
    mmio_clear_bit(2);
  }
  rf_irq_disable(3);
  make_bit_mask(3, 2, dword_10DDB8);
  v0 = off_10DDBC;
  v1 = off_10DDC4;
  result = dword_10DDC8;
  *((uint32_t *)off_10DDBC + 1) = off_10DDC0;
  v1[1] = result;
  v1[2] = 0;
  v0[2] = 0;
  return result;
}

