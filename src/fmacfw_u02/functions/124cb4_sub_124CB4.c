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


extern uint32_t off_124D1C;

// hci_event_dispatch @ 0x124cb4, size 102 bytes
int  hci_event_dispatch(int a1, int a2, int a3, int a4)
{
  int v6; // r1
  int a3a; // [sp+4h] [bp-4h]
  int a3b; // [sp+4h] [bp-4h]
  int a3c; // [sp+4h] [bp-4h]
  int a3d; // [sp+4h] [bp-4h]
  int a3e; // [sp+4h] [bp-4h]

  switch ( *(uint32_t *)a2 )
  {
    case 0:
      a3a = a3;
      ble_mmio_config((uint16_t *)(a2 + 4));
      a3 = a3a;
      break;
    case 1:
      a3c = a3;
      llc_update_channel_map((uint8_t *)(a2 + 4));
      a3 = a3c;
      break;
    case 2:
      a3d = a3;
      rf_rssi_read((uint8_t *)(a2 + 4));
      a3 = a3d;
      break;
    case 3:
      a3e = a3;
      util_get_flag((uint8_t *)(a2 + 4));
      a3 = a3e;
      break;
    case 6:
      v6 = *(uint8_t *)(a2 + 4);
      a3b = a3;
      *off_124D1C = v6;
      event_dispatch("vendor set ap ps =%d\n", v6);
      a3 = a3b;
      break;
    default:
      break;
  }
  ke_msg_send_no_param(127, a4, a3);
  return 0;
}
