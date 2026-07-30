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

extern uint32_t off_13060C;
extern uint32_t dword_130614;
extern uint32_t off_130610;

// fmac_subhandler_n_05b4 @ 0x1305b4, size 88 bytes
// Doc: fmac_subhandler_n_05b4 [mac]: FMAC sub-handler/dispatcher
// fmac_subhandler_n_05b4 [mac]: FMAC sub-handler/dispatcher
int fmac_subhandler_n_05b4()
{
  uint8_t *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r0

  v0 = off_13060C;
  *((uint8_t *)off_13060C + 1) = 1;
  result = message_dispatch_c8b4(1070, 1);
  if ( !result )
  {
    rf_cmd_send_1();
    v0[6] = sub_10EF24();
    rf_timer_toggle_update();
    v2 = (uint8_t)v0[5];
    if ( (uint8_t)v0[6] != v2 )
    {
      rf_reg_write_masked(v2);
      v3 = (uint8_t)v0[5];
      v4 = dword_130614;
      v0[6] = v3;
      msg_parse(v4, v3);
    }
    return timer_set_relative(1070, 1, 1000 * *((uint32_t *)off_130610 + 91));
  }
  return result;
}

