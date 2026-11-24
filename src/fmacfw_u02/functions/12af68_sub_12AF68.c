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


extern uint32_t off_12AFF8;
extern uint32_t off_12AFFC;

// ke_state_check @ 0x12af68, size 138 bytes
int ke_state_check()
{
  int v0; // r0
  uint8_t *v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r3
  int v5; // r1

  if ( rx_rate_field_parse(2u) != 3 )
  {
    v0 = rx_rate_field_parse(2u);
    event_dispatch("end st=%d\n", v0);
  }
  if ( **(uint16_t **)off_12AFF8 < 0 && rx_rate_field_parse(2u) != 3 )
    mmio_clear_register((int)aKeStateGetTask_2, (int)aMmScanChannelE, 201);
  v1 = off_12AFFC;
  v2 = *(uint32_t *)off_12AFFC;
  v3 = *(uint8_t *)(*(uint32_t *)off_12AFFC + 367);
  v4 = (uint8_t)(*((uint8_t *)off_12AFFC + 10) + 1);
  *((uint8_t *)off_12AFFC + 10) = v4;
  if ( v3 <= v4 || v1[11] )
  {
    branch_to_12cbc8((char *)(v2 - 12));
    v5 = *((uint16_t *)v1 + 4);
    if ( v1[11] )
    {
      reg_read_indirect(0, v5);
      v1[11] = 0;
    }
    else
    {
      ke_msg_send_no_param(2050, v5, 2);
    }
    rx_phy_status_parse(2u, 0);
    return 0;
  }
  else
  {
    ke_timer_setup();
    return 0;
  }
}
