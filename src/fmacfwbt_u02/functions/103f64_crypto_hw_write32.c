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

extern uint32_t off_103FE4;
extern uint32_t off_103FE8;
extern uint32_t off_103FEC;

// mmio_irq_enable @ 0x103f64, size 126 bytes
// Doc: mmio_irq_enable [ke]: Write 32-bit value to hardware crypto engine register with IRQ mask
// mmio_irq_enable [ke]: Write 32-bit value to hardware crypto engine register with IRQ mask
unsigned int  mmio_irq_enable(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int *v3; // r3
  int v4; // r4
  uint32_t *v5; // r6
  unsigned int result; // r0

  v2 = (unsigned int *)off_103FE4;
  v3 = (unsigned int *)off_103FE8;
  v4 = *(uint32_t *)off_103FE4;
  v5 = off_103FEC;
  *(uint32_t *)off_103FE4 |= 0x1000000u;
  *v3 |= 0x8000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x200000u;
  *v3 |= 0x200000u;
  *v5 = a2;
  result = (a1 << 16) & 0x1F0000 | *v3 & 0xFFE0FFFF;
  *v3 = result;
  *v3 &= ~0x200000u;
  *v3 |= 0x200000u;
  *v3 &= ~0x8000u;
  *v3 |= 0x400000u;
  *v3 |= 0x200000u;
  *v2 = v4 & 0x1000000 | *v2 & 0xFEFFFFFF;
  return result;
}

