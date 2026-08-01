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

extern uint32_t off_1078C8;
extern uint32_t off_1078CC;
extern uint32_t off_1078D0;

// rf_clear_irq_flag_alt @ 0x107860, size 104 bytes
int rf_clear_irq_flag_alt()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r2
  int result; // r0
  uint32_t *v3; // r2
  int v4; // r3

  v0 = off_1078C8;
  clk_set_divider();
  *v0 &= ~1u;
  write_timer_reg(1);
  v1 = off_1078CC;
  *(uint32_t *)off_1078CC = *(uint32_t *)off_1078CC & 0xCFFFFFFF | 0x10000000;
  *v1 |= 0x40000000u;
  result = write_timer_reg(1);
  v3 = off_1078D0;
  *v0 |= 1u;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  *(uint32_t *)off_1078C8 &= ~1u;
  return result;
}

