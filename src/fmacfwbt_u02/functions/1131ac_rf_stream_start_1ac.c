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

// rf_stream_start_1ac @ 0x1131ac, size 130 bytes
// Doc: rf_cmd_send_3204 [rf]: Send RF command via bus and store result
// rf_cmd_send_3204 [rf]: Send RF command via bus and store result
int  rf_stream_start_1ac(int a1, unsigned int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r6
  uint32_t *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = rf_stream_start2_n_1c;
  if ( *(uint8_t *)rf_stream_start2_n_1c )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = rf_msg_handler_n2d4;
  if ( *(uint8_t *)rf_msg_handler_n2d4 )
  {
    log_printf(rf_cmd_send_n3d8, rf_msg_handler_n2e0, *(uint8_t *)rf_msg_handler_n2d4);
    return -3;
  }
  else
  {
    v4 = sdio_buffer_prepare_n_210;
    *(uint8_t *)rf_msg_handler_n2d4 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = rf_bus_write2_n42c(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      log_printf(rf_msg_handler_n2e8, rf_msg_handler_n2e0, v5);
      return -1;
    }
    else
    {
      *(uint8_t *)rf_msg_handler_n2dc = 1;
      if ( *v2 )
      {
        rf_bus_reset2_n3b8(0, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}

