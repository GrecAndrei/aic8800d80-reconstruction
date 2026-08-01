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

extern uint32_t off_1304CC;
extern uint32_t dword_1304D4;
extern uint32_t off_1304D0;

// set_flag_send_event_42e @ 0x130474, size 88 bytes
int set_flag_send_event_42e()
{
  uint8_t *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r0

  v0 = off_1304CC;
  *((uint8_t *)off_1304CC + 1) = 1;
  result = rf_get_state(1070, 1);
  if ( !result )
  {
    hw_block_reset();
    v0[6] = rf_get_status();
    sub_130370();
    v2 = (uint8_t)v0[5];
    if ( (uint8_t)v0[6] != v2 )
    {
      padding_data(v2);
      v3 = (uint8_t)v0[5];
      v4 = dword_1304D4;
      v0[6] = v3;
      alloc_tx_event(v4, v3);
    }
    return ke_event_handler(1070, 1, 1000 * *((uint32_t *)off_1304D0 + 91));
  }
  return result;
}

