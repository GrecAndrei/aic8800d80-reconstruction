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

extern uint32_t off_12174C;
extern uint32_t dword_121750;
extern uint32_t off_121748;
extern uint32_t off_121754;
extern uint32_t off_121768;
extern uint32_t dword_121770;
extern uint32_t dword_12176C;
extern uint32_t off_121758;
extern uint32_t dword_121760;
extern uint32_t off_121764;
extern uint32_t off_12175C;

// rf_irq_enable @ 0x1216f4, size 84 bytes
unsigned int rf_irq_enable()
{
  int16_t **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  int v5; // r1
  uint32_t *v6; // r2

  v0 = (int16_t **)off_12174C;
  v1 = dword_121750;
  *(uint32_t *)off_121748 |= 2u;
  v2 = (int *)off_121754;
  v3 = **v0;
  *(uint32_t *)off_121754 = v1;
  if ( v3 < 0 && *(uint32_t *)off_121768 << 28 )
  {
    mmio_write_field(dword_121770, dword_12176C, 472);
    v1 = *v2;
  }
  *(uint32_t *)off_121758 = v1 | v2[1];
  result = mmio_reg_update(0);
  v5 = dword_121760;
  v6 = off_121764;
  *(uint32_t *)off_12175C = dword_121760;
  *v6 |= v5;
  return result;
}

