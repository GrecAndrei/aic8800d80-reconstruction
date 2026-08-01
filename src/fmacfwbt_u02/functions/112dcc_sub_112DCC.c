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

// critical_enter @ 0x112dcc, size 126 bytes
// Doc: rf_stream_start2_n_41a [rf]: Start RF stream variant 2
// rf_stream_start2_n_41a [rf]: Start RF stream variant 2
void critical_enter()
{
  int *v0; // r4
  int v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)rf_cmd_send_n_20 = 1;
  }
  v0 = (int *)rf_stream_start2_e50;
  v1 = *(uint8_t *)rf_stream_start2_n_3f8;
  v2 = *(uint32_t *)rf_stream_start2_e50 + 1;
  *(uint32_t *)rf_stream_start2_e50 = v2;
  if ( v1 )
  {
    *((uint32_t *)rf_msg_handler_n_108 + 513) |= 1u;
    while ( 1 )
      ;
  }
  if ( v2 )
  {
    v3 = v2 - 1;
    v4 = *(uint32_t *)rf_cmd_send_n_20;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
}

