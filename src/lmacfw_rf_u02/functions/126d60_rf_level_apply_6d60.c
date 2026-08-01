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

extern uint32_t off_126D98;

// mmio_bit_set @ 0x126d60, size 52 bytes
// Doc: rf_level_apply_n_60 [rf]: Apply RF level by clearing bits 0x10000 and 0x780000 in control registers
// rf_level_apply_n_60 [rf]: Apply RF level by clearing bits 0x10000 and 0x780000 in control registers
int  mmio_bit_set(int a1)
{
  void *v1; // r1
  unsigned int *v2; // r2
  int v3; // r3
  int v4; // r0
  unsigned int v5; // r3

  v1 = rf_level_apply_6d94;
  v2 = (unsigned int *)off_126D98;
  v3 = *(uint32_t *)rf_level_apply_6d94;
  if ( a1 )
  {
    *(uint32_t *)rf_level_apply_6d94 = v3 | 0x10000;
    v4 = rf_level_apply_0;
    v5 = *v2 & 0xFF87FFFF | 0x700000;
  }
  else
  {
    *(uint32_t *)rf_level_apply_6d94 = v3 & 0xFFFEFFFF;
    v4 = rf_level_apply_n_38;
    v5 = *v2 & 0xFF87FFFF;
  }
  *v2 = v5;
  return dispatch_event_handler(v4, v1, v2, v5);
}

