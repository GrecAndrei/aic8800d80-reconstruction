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

extern uint32_t off_1319C0;
extern uint32_t dword_1319CC;
extern uint32_t dword_1319C8;
extern uint32_t off_1319C4;

// rx_path_check @ 0x131978, size 70 bytes
// Doc: me_chan_ctxt_update [mac]: Update MAC engine channel context fields
// me_chan_ctxt_update [mac]: Update MAC engine channel context fields
int  rx_path_check(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(int16_t **)off_1319C0 < 0 && rx_rate_field_parse(a3) != 1 )
    mmio_clear_register(dword_1319CC, dword_1319C8, 670);
  v4 = *((uint16_t *)off_1319C4 + 4);
  if ( v4 != 255 )
    ke_msg_send_no_param(5144, v4, a3);
  rx_phy_status_parse(a3, 0);
  return 0;
}

