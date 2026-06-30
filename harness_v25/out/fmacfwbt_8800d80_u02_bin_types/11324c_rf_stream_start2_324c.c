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

// rf_stream_start2_324c @ 0x11324c, size 164 bytes
// Doc: rf_cmd_send_n47c [rf]: Send RF command sequence n47c
// rf_cmd_send_n47c [rf]: Send RF command sequence n47c
int  rf_stream_start2_324c(int a1, unsigned int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r5
  int v4; // r3
  uint32_t *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = rf_cmd_send_n484;
  if ( *(uint8_t *)rf_cmd_send_n484 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = rf_bus_mark_n_250_32f4;
  if ( *(uint8_t *)rf_bus_mark_n_250_32f4 )
  {
    log_printf(rf_stream_start2_nbc, rf_cmd_send_n498, *(uint8_t *)rf_bus_mark_n_250_32f4);
    return -3;
  }
  else
  {
    v4 = *(char *)rf_cmd_send_n48c;
    *(uint8_t *)rf_bus_mark_n_250_32f4 = 1;
    v5 = rf_msg_handler_n39c;
    if ( v4 )
    {
      *((uint32_t *)rf_msg_handler_n39c + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((uint32_t *)rf_msg_handler_n39c + 713) |= 1u;
    }
    v6 = rf_bus_write2_n500(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      log_printf(rf_msg_handler_n3ac, rf_cmd_send_n498, v6);
      return -1;
    }
    else
    {
      *(uint8_t *)rf_msg_handler_n3a0 = 1;
      if ( *v2 )
      {
        rf_bus_reset2_n3b8(0, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

