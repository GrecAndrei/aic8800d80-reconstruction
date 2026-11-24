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


extern uint32_t dword_119EF8;
extern uint32_t off_119EF4;
extern uint32_t off_119F0C;

// rf_get_rssi_1 @ 0x119e3c, size 184 bytes
int  rf_get_rssi_1(int a1, int a2, unsigned int a3, int a4)
{
  uint16_t **v4; // r8
  int v5; // r0
  int v9; // r2
  uint32_t v11[2]; // [sp+0h] [bp-20h] BYREF
  char v12; // [sp+9h] [bp-17h]
  uint32_t v13[5]; // [sp+Ch] [bp-14h] BYREF

  v4 = (uint16_t **)off_119F0C;
  v5 = **(uint16_t **)off_119F0C;
  memset(v13, 0, sizeof(v13));
  if ( v5 < 0 && flash_write_byte(a3) )
    flash_ctrl_init((int)aKeStateGetDest, (int)aMmStartReqHand, 337);
  wifi_set_channel((int *)a2);
  v9 = dword_119EF8;
  *(uint8_t *)off_119EF4 = 1;
  v11[0] = v9;
  v11[1] = 2412;
  v12 = 0;
  tx_set_power((uint8_t *)v11, 0);
  util_byte_to_hex(15);
  rf_wait_timeout((int)v13);
  if ( **v4 < 0 && (uint8_t)a4 > 5u )
  {
    flash_ctrl_init((int)aIdTaskMax, (int)aKeTaskLocal_2, 183);
    if ( (a4 & 0xFC) != 0 )
      goto LABEL_7;
LABEL_4:
    write_bb_control();
    return 0;
  }
  if ( (a4 & 0xFC) == 0 )
    goto LABEL_4;
LABEL_7:
  ke_evt_handler(3, a4, a3);
  write_bb_control();
  return 0;
}
