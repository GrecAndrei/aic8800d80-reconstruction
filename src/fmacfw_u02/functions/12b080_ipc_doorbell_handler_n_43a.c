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

extern uint32_t dword_12B100;
extern uint32_t off_12B104;
extern uint32_t dword_12B110;
extern uint32_t dword_12B10C;
extern uint32_t off_12B108;

// ke_msg_send @ 0x12b080, size 124 bytes
// Doc: ke_msg_send [ipc]: Handles doorbell interrupt from host/AP
// ke_msg_send [ipc]: Handles doorbell interrupt from host/AP
int  ke_msg_send(int a1, int a2, int a3, int a4)
{
  int16_t v4; // r6
  uint8_t *v6; // r4
  uint8_t *v7; // r2

  v4 = a4;
  v6 = (uint8_t *)ke_msg_alloc(2049, a4, a3, 1);
  rx_rate_field_parse(2);
  check_status_bits(4, dword_12B100);
  if ( rx_rate_field_parse(2) )
  {
    *v6 = 8;
    ke_msg_send(v6);
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_12B104 < 0 && !*(uint8_t *)(a2 + 367) )
      mmio_clear_register(dword_12B110, dword_12B10C, 73);
    v7 = off_12B108;
    *v6 = 0;
    *(uint32_t *)v7 = a2;
    v7[10] = 0;
    *((uint16_t *)v7 + 4) = v4;
    controller_get_event(a2);
    ke_msg_send(v6);
    return 1;
  }
}

