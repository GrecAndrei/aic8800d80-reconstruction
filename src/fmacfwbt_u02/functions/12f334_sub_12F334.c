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

// tx_power_config @ 0x12f334, size 116 bytes
int  tx_power_config(int a1, int *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  uint32_t *v7; // r4
  int v9; // r5
  int v10; // r0

  v5 = bt_buf_alloc(1038, a4, a3, 4);
  v6 = a2[1];
  v7 = (uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      ke_event_schedule_1("\x9D\x81Auto boot to 0x%08x\r\n", *(uint32_t *)(*a2 + 4));
      break;
    case 2:
      ke_event_schedule_1("\x9D\x81Custom boot to 0x%08x\r\n", *a2);
      break;
    case 3:
      v9 = *a2;
      v10 = ke_event_schedule_1("delay %d\r\n", v9);
      if ( !v9 )
        task_poll_loop(v10);
      patch_aware_dispatch(1068, 1, v9 << 10);
      break;
    default:
      ke_event_schedule_1(aInvalidBootTyp);
      break;
  }
  *v7 = (uint8_t)call_vector_1fc(15);
  ke_event_schedule_1(asc_14B084);
  hci_evt_send((int)v7);
  return 0;
}
