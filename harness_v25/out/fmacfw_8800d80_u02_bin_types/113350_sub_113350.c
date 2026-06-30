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

extern uint32_t dword_1133EC;

// sub_113350 @ 0x113350, size 130 bytes
// Doc: rf_stream_start2_3390 [rf]: Starts an RF stream (variant 2)
// rf_stream_start2_3390 [rf]: Starts an RF stream (variant 2)
int  sub_113350(int a1, unsigned int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r6
  uint32_t *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = rf_cmd_wait_n464;
  if ( *(uint8_t *)rf_cmd_wait_n464 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = rf_cmd_send_n3c8;
  if ( *(uint8_t *)rf_cmd_send_n3c8 )
  {
    sub_10DC24(rf_cmd_process_n_170, rf_msg_handler_n2e0, *(uint8_t *)rf_cmd_send_n3c8);
    return -3;
  }
  else
  {
    v4 = rf_msg_handler_n2d8;
    *(uint8_t *)rf_cmd_send_n3c8 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = rf_bus_setup_n14c(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      sub_10DC24(dword_1133EC, rf_msg_handler_n2e0, v5);
      return -1;
    }
    else
    {
      *(uint8_t *)rf_level_apply_n_14e = 1;
      if ( *v2 )
      {
        rf_bus_write_wrapper(0, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}

