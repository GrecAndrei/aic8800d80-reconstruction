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

extern uint32_t off_13446C;
extern uint32_t off_134470;

// reset_controller_state @ 0x134434, size 54 bytes
// Doc: sub_1234434 [util]: Reset/clear a control structure's status fields and byte flags
// sub_1234434 [util]: Reset/clear a control structure's status fields and byte flags
uint32_t *reset_controller_state()
{
  uint32_t *v0; // r4
  uint16_t *v1; // r3
  int v2; // r0

  v0 = off_13446C;
  v1 = off_134470;
  v2 = *((uint32_t *)off_13446C + 4);
  *((uint8_t *)off_134470 + 13) = 0;
  v1[7] = 0;
  *((uint8_t *)v1 + 3) = 0;
  if ( v2 )
  {
    branch_to_12cbc8(v2 - 12);
    branch_to_12cbc8(v0[5] - 12);
  }
  memset((int *)off_13446C, 0, 0x2Cu);
  return rx_phy_status_parse(6u, 0);
}

