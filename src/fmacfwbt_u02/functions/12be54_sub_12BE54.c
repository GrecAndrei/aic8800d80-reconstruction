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

extern uint32_t off_12BEC4;
extern uint32_t off_12BEC8;
extern uint32_t off_12BECC;
extern uint32_t off_12BED0;
extern uint32_t dword_12BED4;
extern uint32_t off_12BEDC;
extern uint32_t dword_12BEE4;
extern uint32_t dword_12BEE0;
extern uint32_t off_12BED8;

// mmio_disable_irq @ 0x12be54, size 110 bytes
unsigned int mmio_disable_irq()
{
  uint32_t *v0; // r2
  uint32_t *v1; // r0
  int16_t **v2; // r5
  int *v3; // r4
  int v4; // r3
  int16_t *v5; // r2
  unsigned int result; // r0
  uint32_t *v7; // r2

  v0 = off_12BEC4;
  v1 = off_12BEC8;
  *(uint32_t *)off_12BEC4 &= ~1u;
  v2 = (int16_t **)off_12BECC;
  v3 = (int *)off_12BED0;
  v4 = dword_12BED4;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(uint32_t *)off_12BEDC << 28 )
  {
    mmio_field_update(dword_12BEE4, dword_12BEE0, 472);
    v4 = *v3;
  }
  *(uint32_t *)off_12BED8 = v4 | v3[1];
  result = rf_ant_switch_set(1);
  v7 = off_12BEC8;
  *(uint32_t *)off_12BEC8 = *(uint32_t *)off_12BEC8 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}

