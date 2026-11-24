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


extern uint32_t dword_123B4C;
extern uint32_t off_123B50;
extern uint32_t off_123B64;

// lld_evt_schedule_next @ 0x123a94, size 182 bytes
int  lld_evt_schedule_next(int a1, int a2, unsigned int a3, int a4)
{
  uint16_t **v4; // r8
  int v5; // r0
  uint16_t a1a[2]; // [sp+4h] [bp-24h] BYREF
  int v11; // [sp+8h] [bp-20h]
  char v12; // [sp+Dh] [bp-1Bh]
  uint32_t v13[6]; // [sp+10h] [bp-18h] BYREF

  v4 = (uint16_t **)off_123B64;
  v5 = **(uint16_t **)off_123B64;
  memset(v13, 0, sizeof(v13));
  if ( v5 < 0 && rx_rate_field_parse(a3) )
    mmio_clear_register((int)aKeStateGetDest, (int)aMmStartReqHand, 337);
  periph_init((int *)a2);
  *(uint32_t *)a1a = dword_123B4C;
  v12 = 0;
  v11 = 2484;
  rf_enable(a1a, 0);
  util_format(15);
  *((uint16_t *)off_123B50 + 14) = *(uint16_t *)(a2 + 68);
  timer_queue_init((int)v13);
  if ( **v4 < 0 && (uint8_t)a4 > 0xEu )
  {
    mmio_clear_register((int)aIdTaskMax, (int)aKeTaskLocal_2, 183);
    goto LABEL_7;
  }
  if ( (uint8_t)a4 > 0xCu )
LABEL_7:
    ke_msg_send_no_param(3, a4, a3);
  set_clock_divisor();
  read_cal_trim();
  rx_phy_status_parse(a3, 2);
  return 0;
}
