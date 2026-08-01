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

extern uint32_t off_10FEBC;
extern uint32_t dword_10FEC0;
extern uint32_t dword_10FEC4;

// is_chip_ready @ 0x10fe7c, size 62 bytes
uint32_t * is_chip_ready(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FEBC == 1 )
    v2 = (uint32_t *)mmio_read_2();
  else
    v2 = tx_irq_handler(dword_10FEC0, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( check_state_flag((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  debug_printf(dword_10FEC4, v2);
  return v2;
}

