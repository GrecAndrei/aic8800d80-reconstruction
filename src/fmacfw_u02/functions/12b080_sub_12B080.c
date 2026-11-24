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


extern uint32_t off_12B104;
extern uint32_t off_12B108;

// ke_msg_send_1 @ 0x12b080, size 124 bytes
int  ke_msg_send_1(int a1, int a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v6; // r4
  int v7; // r0
  uint8_t *v8; // r2

  v6 = (uint8_t *)ke_msg_alloc(2049, a4, a3, 1);
  v7 = rx_rate_field_parse(2u);
  check_status_bits(4, "%s:%d\r\n", aScanStartReqHa, v7);
  if ( rx_rate_field_parse(2u) )
  {
    *v6 = 8;
    ke_msg_send_2((int)v6);
    return 0;
  }
  else
  {
    if ( **(uint16_t **)off_12B104 < 0 && !*(uint8_t *)(a2 + 367) )
      mmio_clear_register((int)aParamChanCnt0, (int)aScanStartReqHa_0, 73);
    v8 = off_12B108;
    *v6 = 0;
    *(uint32_t *)v8 = a2;
    v8[10] = 0;
    *((uint16_t *)v8 + 4) = a4;
    controller_get_event(a2);
    ke_msg_send_2((int)v6);
    return 1;
  }
}
