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

extern uint32_t off_107CBC;
extern uint32_t off_107CC0;
extern uint32_t off_107CC4;

// rf_irq_clear_a @ 0x107c60, size 92 bytes
// Doc: sub_1207C60 [util]: Clear low bit of 0x403420c8 register and trigger callback
// sub_1207C60 [util]: Clear low bit of 0x403420c8 register and trigger callback
int rf_irq_clear_a()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r3
  int result; // r0
  uint32_t *v3; // r2
  int v4; // r3

  v0 = off_107CBC;
  rf_set_frequency();
  *v0 &= ~1u;
  timer_set(1);
  v1 = off_107CC0;
  *(uint32_t *)off_107CC0 &= 0xCFFFFFFF;
  *v1 |= 0x40000000u;
  result = timer_set(1);
  v3 = off_107CC4;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  *(uint32_t *)off_107CBC &= ~1u;
  return result;
}

