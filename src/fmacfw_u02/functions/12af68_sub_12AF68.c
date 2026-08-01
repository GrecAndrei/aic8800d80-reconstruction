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

extern uint32_t dword_12AFF4;
extern uint32_t off_12AFF8;
extern uint32_t dword_12B004;
extern uint32_t dword_12B000;
extern uint32_t off_12AFFC;

// ke_state_check @ 0x12af68, size 138 bytes
// Doc: sub_122AF68 [util]: Calls helper(2), checks return against 3 (likely init/status poll)
// sub_122AF68 [util]: Calls helper(2), checks return against 3 (likely init/status poll)
int ke_state_check()
{
  int value; // r0
  int v1; // r2
  uint8_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r3
  int v6; // r1

  if ( rx_rate_field_parse(2) != 3 )
  {
    value = rx_rate_field_parse(2);
    event_dispatch(dword_12AFF4, value, v1);
  }
  if ( **(int16_t **)off_12AFF8 < 0 && rx_rate_field_parse(2) != 3 )
    mmio_clear_register(dword_12B004, dword_12B000, 201);
  v2 = off_12AFFC;
  v3 = *(uint32_t *)off_12AFFC;
  v4 = *(uint8_t *)(*(uint32_t *)off_12AFFC + 367);
  v5 = (uint8_t)(*((uint8_t *)off_12AFFC + 10) + 1);
  *((uint8_t *)off_12AFFC + 10) = v5;
  if ( v4 <= v5 || v2[11] )
  {
    branch_to_12cbc8(v3 - 12);
    v6 = *((uint16_t *)v2 + 4);
    if ( v2[11] )
    {
      reg_read_indirect(0, v6);
      v2[11] = 0;
    }
    else
    {
      ke_msg_send_no_param(2050, v6, 2);
    }
    rx_phy_status_parse(2);
    return 0;
  }
  else
  {
    ke_timer_setup();
    return 0;
  }
}

