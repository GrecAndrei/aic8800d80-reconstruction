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

extern uint32_t dword_1216D4;
extern uint32_t dword_1216D8;
extern uint32_t dword_1216D0;
extern uint32_t dword_1216C8;
extern uint32_t dword_1216CC;

// rf_write_0x40e @ 0x121654, size 116 bytes
// Doc: sub_1221654 [unknown]: Calls helper with 0x40e, checks state field
// sub_1221654 [unknown]: Calls helper with 0x40e, checks state field
int  rf_write_0x40e(int a1, int *a2, int16_t a3, int16_t a4)
{
  int v5; // r0
  int v6; // r3
  uint32_t *v7; // r4
  int v9; // r5

  v5 = ke_msg_send(1038, a4, a3, 4u);
  v6 = a2[1];
  v7 = (uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      dispatch_event_handler(dword_1216D4, *(uint32_t *)(*a2 + 4));
      break;
    case 2:
      dispatch_event_handler(dword_1216D8, *a2);
      break;
    case 3:
      v9 = *a2;
      dispatch_event_handler(dword_1216D0, v9);
      if ( !v9 )
        schedule_callbacks();
      ke_event_loop(1068, 1, v9 << 10);
      break;
    default:
      dispatch_event_handler(dword_1216C8);
      break;
  }
  *v7 = (uint8_t)mmio_read32(0xFu);
  dispatch_event_handler(dword_1216CC);
  rx_irq_handler((int)v7);
  return 0;
}

