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

// sub_127108 @ 0x127108, size 88 bytes
// Doc: bt_hci_cmd_send_n_c1c [bt]: Send HCI command 0x180a via BT path
// bt_hci_cmd_send_n_c1c [bt]: Send HCI command 0x180a via BT path
int sub_127108()
{
  uint8_t *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r0

  v0 = rf_level_apply_n388;
  *((uint8_t *)rf_level_apply_n388 + 1) = 1;
  result = sub_11DDCC(1070, 1);
  if ( !result )
  {
    sub_10DE98();
    v0[6] = mmio_bit_extract_n();
    rf_level_apply_n1b8();
    v2 = (uint8_t)v0[5];
    if ( (uint8_t)v0[6] != v2 )
    {
      sub_10F170(v2);
      v3 = (uint8_t)v0[5];
      v4 = rf_level_apply_168;
      v0[6] = v3;
      msg_parse(v4, v3);
    }
    return timer_set_relative(1070, 1, 1000 * *((uint32_t *)rf_level_apply_n38c + 91));
  }
  return result;
}

