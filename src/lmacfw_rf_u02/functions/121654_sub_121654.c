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

// rf_write_0x40e @ 0x121654, size 116 bytes
int  rf_write_0x40e(int a1, int *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  uint32_t *v7; // r4
  int v9; // r5
  int v10; // r0

  v5 = ke_msg_send_1(1038, a4, a3, 4);
  v6 = a2[1];
  v7 = (uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      dispatch_event_handler_1("\x9D\x81Auto boot to 0x%08x\r\n", *(uint32_t *)(*a2 + 4));
      break;
    case 2:
      dispatch_event_handler_1("\x9D\x81Custom boot to 0x%08x\r\n", *a2);
      break;
    case 3:
      v9 = *a2;
      v10 = dispatch_event_handler_1("delay %d\r\n", v9);
      if ( !v9 )
        schedule_callbacks(v10);
      ke_event_loop(1068, 1, v9 << 10);
      break;
    default:
      dispatch_event_handler_1(aInvalidBootTyp);
      break;
  }
  *v7 = (uint8_t)mmio_read32(0xFu);
  dispatch_event_handler_1(asc_12EB1C);
  rx_irq_handler_1((int)v7);
  return 0;
}
