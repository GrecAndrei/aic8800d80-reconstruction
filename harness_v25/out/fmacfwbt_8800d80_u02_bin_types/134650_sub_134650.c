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

extern uint32_t off_134688;
extern uint32_t off_13468C;

// sub_134650 @ 0x134650, size 54 bytes
// Doc: sub_1234650 [util]: Clear/reset state structure fields and zero registers
// sub_1234650 [util]: Clear/reset state structure fields and zero registers
uint32_t *sub_134650()
{
  uint32_t *v0; // r4
  uint16_t *v1; // r3
  int v2; // r0

  v0 = off_134688;
  v1 = off_13468C;
  v2 = *((uint32_t *)off_134688 + 4);
  *((uint8_t *)off_13468C + 13) = 0;
  v1[7] = 0;
  *((uint8_t *)v1 + 3) = 0;
  if ( v2 )
  {
    j_buffer_pool_get(v2 - 12);
    j_buffer_pool_get(v0[5] - 12);
  }
  memset_thunk((int *)off_134688, 0, 0x2Cu);
  return rf_bus_mark_n_3b7(6u, 0);
}

