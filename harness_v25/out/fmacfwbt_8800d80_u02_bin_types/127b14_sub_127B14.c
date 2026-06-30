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

extern uint32_t off_127B74;
extern uint32_t off_127B78;

// sub_127B14 @ 0x127b14, size 94 bytes
int  sub_127B14(int a1)
{
  int result; // r0
  char v3; // r3
  int v4; // r3

  result = timestamp_update_4f60(a1 + 24, *(uint32_t *)(a1 + 36) + *(uint32_t *)(a1 + 88));
  v3 = *(uint8_t *)(a1 + 85);
  *(uint8_t *)(a1 + 85) = v3 & 0xDF;
  if ( (v3 & 1) != 0 )
  {
    v4 = *((uint32_t *)off_127B74 + 9);
    if ( v4 && *(uint32_t *)(v4 + 12) == a1 + 76 )
    {
      fmacfwbt_init_load();
      bt_rf_calibrate_or_setup(a1, *(uint32_t *)(a1 + 36), 0);
      return mac_state_process_n_1c8(a1, *((uint32_t *)off_127B78 + 4), 0);
    }
    else
    {
      return bt_rf_calibrate_or_setup(a1, *(uint32_t *)(a1 + 36), 0);
    }
  }
  return result;
}

