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

extern uint32_t dword_113704;

// bt_evt_sched_high @ 0x113670, size 124 bytes
// Doc: rf_stream_start2_n460 [rf]: Start RF stream variant 2 with argument
// rf_stream_start2_n460 [rf]: Start RF stream variant 2 with argument
int bt_evt_sched_high()
{
  void *v0; // r7
  int result; // r0
  uint16_t *v2; // r9
  uint16_t *v3; // r6
  int v4; // r8
  int v5; // r11
  int16_t **v6; // r10
  uint16_t v7; // r5
  unsigned int v8; // r1
  int v9; // r2

  v0 = rf_stream_start2_n4a0;
  result = zero_struct(rf_stream_start2_n4a4);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = rf_stream_start2_3700;
    v3 = rf_stream_start2_n4a8;
    v4 = dword_113704;
    v5 = rf_stream_start2_n4bc;
    v6 = (int16_t **)rf_stream_cmd_dispatch;
    v7 = 0;
    do
    {
      if ( !rx_process_item(v4, (uint16_t)(v2[153] - 4)) )
      {
        ke_event_schedule(v5, v7, v9);
        if ( **v6 < 0 )
          mmio_irq_clear(rf_stream_start2_n4b0, rf_stream_start2_n4ac, 495);
      }
      result = check_abort_flag(rf_stream_start2_n4a4);
      v8 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v7;
      ++*v3;
    }
    while ( v8 > v7 );
  }
  return result;
}

