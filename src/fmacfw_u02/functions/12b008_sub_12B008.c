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


extern uint32_t off_12B06C;
extern uint32_t off_12B074;

// ke_task_state_get_1 @ 0x12b008, size 98 bytes
int ke_task_state_get_1()
{
  int v0; // r5
  int v1; // r4
  int v2; // r0

  v0 = *(uint32_t *)off_12B06C;
  v1 = *((uint8_t *)off_12B06C + 10);
  if ( rx_rate_field_parse(2u) != 2 )
  {
    v2 = rx_rate_field_parse(2u);
    event_dispatch("start st=%d\n", v2);
  }
  if ( **(uint16_t **)off_12B074 < 0 && rx_rate_field_parse(2u) != 2 )
    mmio_clear_register((int)aKeStateGetTask_3, (int)aMmScanChannelS, 163);
  if ( (*(uint8_t *)(v0 + 6 * v1 + 3) & 1) == 0 )
    controller_read_features();
  rx_phy_status_parse(2u, 3);
  return 0;
}
