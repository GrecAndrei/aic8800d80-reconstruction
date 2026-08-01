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

// dispatch_by_type @ 0x124ee8, size 96 bytes
// Doc: dispatch_by_type [bt]: Dispatch Bluetooth message based on type field compared against 3
// dispatch_by_type [bt]: Dispatch Bluetooth message based on type field compared against 3
int  dispatch_by_type(int a1, uint16_t *a2, int a3, void *a4)
{
  int v4; // r4
  void *v6; // r1
  int v8; // [sp+0h] [bp-8h]
  int v9; // [sp+0h] [bp-8h]
  int v10; // [sp+0h] [bp-8h]
  int v11; // [sp+0h] [bp-8h]

  v4 = *(uint32_t *)a2;
  v6 = a4;
  switch ( v4 )
  {
    case 0:
      v8 = a3;
      radio_reg_init(a2 + 2);
      a3 = v8;
      v6 = a4;
      break;
    case 1:
      v10 = a3;
      ble_store_adv_data((uint8_t *)a2 + 4);
      a3 = v10;
      v6 = a4;
      break;
    case 2:
      v11 = a3;
      radio_read_config((uint8_t *)a2 + 4);
      a3 = v11;
      v6 = a4;
      break;
    case 3:
      v9 = a3;
      set_cfg_flag((uint8_t *)a2 + 4, a4);
      a3 = v9;
      v6 = a4;
      break;
    default:
      break;
  }
  hci_evt_alloc_send(127, v6, a3, a4);
  return 0;
}

