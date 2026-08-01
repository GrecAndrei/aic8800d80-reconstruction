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

extern uint32_t off_11836C;
extern uint32_t off_118370;

// clear_bb_irq @ 0x118354, size 24 bytes
void clear_bb_irq()
{
  int v0; // r3

  v0 = *((uint8_t *)off_11836C + 18) + *((uint8_t *)off_11836C + 17);
  *(uint32_t *)off_118370 = 0;
  if ( v0 <= 1 )
    btcoex_check_state();
}

