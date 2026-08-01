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

extern uint32_t dword_124D20;
extern uint32_t off_124D1C;

// hci_event_dispatch @ 0x124cb4, size 102 bytes
int  hci_event_dispatch(int a1, uint16_t *a2, int a3, int a4)
{
  int v6; // r1
  int v7; // r0
  int v8; // [sp+4h] [bp-4h]
  int v9; // [sp+4h] [bp-4h]
  int v10; // [sp+4h] [bp-4h]
  int v11; // [sp+4h] [bp-4h]
  int v12; // [sp+4h] [bp-4h]

  switch ( *(uint32_t *)a2 )
  {
    case 0:
      v8 = a3;
      ble_mmio_config(a2 + 2);
      a3 = v8;
      break;
    case 1:
      v10 = a3;
      llc_update_channel_map((uint8_t *)a2 + 4);
      a3 = v10;
      break;
    case 2:
      v11 = a3;
      rf_rssi_read((uint8_t *)a2 + 4);
      a3 = v11;
      break;
    case 3:
      v12 = a3;
      util_get_flag((uint8_t *)a2 + 4, a2);
      a3 = v12;
      break;
    case 6:
      v6 = *((uint8_t *)a2 + 4);
      v7 = dword_124D20;
      v9 = a3;
      *(uint8_t *)off_124D1C = v6;
      event_dispatch(v7, v6, a3);
      a3 = v9;
      break;
    default:
      break;
  }
  ke_msg_send_no_param(127, a4, a3);
  return 0;
}

