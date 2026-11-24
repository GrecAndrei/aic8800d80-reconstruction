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


extern uint32_t off_11CA28;
extern uint32_t off_11CA2C;

// radio_send_command @ 0x11c9a4, size 124 bytes
int  radio_send_command(int a1, int a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v6; // r4
  int v7; // r0
  int v8; // r2

  v6 = (uint8_t *)ke_msg_send_1(2049, a4, a3, 1);
  v7 = flash_write_byte(2u);
  check_interrupt_flag(4, "%s:%d\r\n", aScanStartReqHa, v7);
  if ( flash_write_byte(2u) )
  {
    *v6 = 8;
    rx_irq_handler_1((int)v6);
    return 0;
  }
  else
  {
    if ( **(uint16_t **)off_11CA28 < 0 && !*(uint8_t *)(a2 + 367) )
      flash_ctrl_init((int)aParamChanCnt0, (int)aScanStartReqHa_0, 73);
    v8 = off_11CA2C;
    *v6 = 0;
    *(uint32_t *)v8 = a2;
    *(uint8_t *)(v8 + 0xA) = 0;
    *(uint16_t *)(v8 + 8) = a4;
    aes_encrypt(a2);
    rx_irq_handler_1((int)v6);
    return 1;
  }
}
