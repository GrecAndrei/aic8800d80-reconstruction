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


extern uint32_t dword_13B66C;
extern uint32_t dword_13B670;

// adv_pdu_type_handler @ 0x13b638, size 50 bytes
int  adv_pdu_type_handler(int a1, int a2, unsigned int a3)
{
  if ( rx_rate_field_parse(a3) == 2 )
  {
    rf_get_chan_state(a3 >> 8);
    cmd_handler_a(dword_13B670, (uint32_t *)(dword_13B66C + 32 * (a3 >> 8)));
    rx_phy_status_parse(a3, 0);
  }
  return 0;
}
