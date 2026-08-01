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

extern uint32_t dword_11CA24;
extern uint32_t dword_11CA20;
extern uint32_t off_11CA28;
extern uint32_t dword_11CA34;
extern uint32_t dword_11CA30;
extern uint32_t off_11CA2C;

// radio_send_command @ 0x11c9a4, size 124 bytes
int  radio_send_command(int a1, int a2, int a3, int a4)
{
  int16_t v4; // r6
  uint8_t *v6; // r4
  int v7; // r0
  uint8_t *v8; // r2

  v4 = a4;
  v6 = (uint8_t *)ke_msg_send(2049, a4, a3, 1);
  v7 = flash_write_byte(2);
  check_interrupt_flag(4, dword_11CA24, dword_11CA20, v7);
  if ( flash_write_byte(2) )
  {
    *v6 = 8;
    rx_irq_handler(v6);
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_11CA28 < 0 && !*(uint8_t *)(a2 + 367) )
      flash_ctrl_init(dword_11CA34, dword_11CA30, 73);
    v8 = off_11CA2C;
    *v6 = 0;
    *(uint32_t *)v8 = a2;
    v8[10] = 0;
    *((uint16_t *)v8 + 4) = v4;
    aes_encrypt(a2);
    rx_irq_handler(v6);
    return 1;
  }
}

