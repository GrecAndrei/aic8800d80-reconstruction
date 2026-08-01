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

extern uint32_t off_10CA94;
extern uint32_t off_10CA98;
extern uint32_t off_10CA9C;
extern uint32_t dword_10CAA4;
extern uint32_t dword_10CAA0;

// pmu_isr_224 @ 0x10ca3c, size 86 bytes
// Doc: sub_120CA3C [util]: Loads fw state struct and reads field at offset 0x224
// sub_120CA3C [util]: Loads fw state struct and reads field at offset 0x224
int pmu_isr_224()
{
  uint32_t *v0; // r4
  int v1; // r0
  int v2; // r3
  int v4; // r3

  v0 = off_10CA94;
  while ( !*(uint32_t *)off_10CA94 )
    ;
  if ( *(uint32_t *)(*(uint32_t *)off_10CA98 + 548) )
  {
    v1 = list_pop_front(*(uint32_t *)off_10CA98 + 548);
    v2 = **(int16_t **)off_10CA9C;
    *v0 = 1;
    if ( v2 >= 0 || v1 )
      return v1 + 20;
  }
  else
  {
    v4 = **(int16_t **)off_10CA9C;
    *(uint32_t *)off_10CA94 = 1;
    if ( v4 >= 0 )
      return 20;
  }
  mmio_irq_clear(dword_10CAA4, dword_10CAA0, 1101);
  return 20;
}

