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

extern uint32_t dword_1134A8;
extern uint32_t off_1134A0;
extern uint32_t dword_1134B0;
extern uint32_t off_1134A4;

// rf_stream_start2_0 @ 0x1133f0, size 164 bytes
// Doc: rf_cmd_process_n_f2 [rf]: Process RF command loading shared data pointers
// rf_cmd_process_n_f2 [rf]: Process RF command loading shared data pointers
int  rf_stream_start2_0(int a1, unsigned int a2)
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
  v3 = rf_stream_start_498;
  if ( *(uint8_t *)rf_stream_start_498 )
  {
    sub_10DC24(rf_stream_start2_nbc, dword_1134A8, *(uint8_t *)rf_stream_start_498);
    return -3;
  }
  else
  {
    v4 = *(char *)rf_msg_handler_n398;
    *(uint8_t *)rf_stream_start_498 = 1;
    v5 = off_1134A0;
    if ( v4 )
    {
      *((uint32_t *)off_1134A0 + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((uint32_t *)off_1134A0 + 713) |= 1u;
    }
    v6 = rf_state_check_11c(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      sub_10DC24(dword_1134B0, dword_1134A8, v6);
      return -1;
    }
    else
    {
      *(uint8_t *)off_1134A4 = 1;
      if ( *v2 )
      {
        rf_bus_write_wrapper(0, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

