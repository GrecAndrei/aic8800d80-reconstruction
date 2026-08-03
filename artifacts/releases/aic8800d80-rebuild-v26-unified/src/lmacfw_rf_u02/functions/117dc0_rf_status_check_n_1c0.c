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

extern uint32_t off_117DEC;
extern uint32_t off_117DF0;

// rf_status_check_n_1c0 @ 0x117dc0, size 44 bytes
// Doc: rf_status_check_n_1c0 [rf]: Check RF status byte at offset 0x5e from radio state block
// rf_status_check_n_1c0 [rf]: Check RF status byte at offset 0x5e from radio state block
void rf_status_check_n_1c0()
{
  uint8_t *v0; // r3
  unsigned int v1; // r2

  v0 = *((uint8_t **)off_117DEC + 2);
  if ( !v0[94] && v0[96] && v0[103] )
  {
    v1 = (uint8_t)v0[104];
    if ( v1 <= 8 )
      *(uint32_t *)off_117DF0 = ((1 << v1) - 1) << 8;
  }
}

