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

extern uint32_t off_11326C;
extern uint32_t dword_113284;
extern uint32_t dword_113288;
extern uint32_t dword_1132A0;

// read_periph_status @ 0x113104, size 360 bytes
// Doc: rf_cmd_queue_next_n_260 [rf]: Process next RF command from queue
// rf_cmd_queue_next_n_260 [rf]: Process next RF command from queue
int  read_periph_status(uint8_t *a1, unsigned int a2, int a3)
{
  uint16_t *v3; // r7
  uint8_t *v4; // r6
  uint8_t *v5; // r4
  char v6; // r2
  uint8_t *v7; // r4
  int v9; // r8
  int v10; // r6
  uint8_t *v11; // r8
  char v12; // r5
  int v13; // r0
  unsigned int v14; // r3
  char *v15; // r3
  int v17; // r0

  v3 = (uint16_t *)off_11326C;
  v4 = (uint8_t *)rf_cmd_send_n260;
  v5 = ipc_doorbell_handler_n17b;
  ++*(uint16_t *)off_11326C;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  v7 = a1;
  if ( *v4 != 2 )
  {
    log_printf(dword_113284, *v3, *v4);
    is_current_task(dword_113288, v7, a2, *v4);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    log_printf(rf_cmd_queue_next_n_228, *v3, a2);
  }
  else
  {
    v9 = a1[2];
    v10 = *a1 | (a1[1] << 8) & 0xF00;
    if ( *(uint8_t *)patch_apply_n_2e )
      a1 = (uint8_t *)check_status_bits(512, rf_cmd_send_n288);
    if ( v9 == 1 )
    {
      if ( a2 == v10 || v10 + 1 == a2 )
      {
        ((void (*)(void))timer_delay)();
        check_packet_length(v7 + 4);
        unknown_func_12d104(512);
        return 1;
      }
      log_printf(rf_stream_start2_n_154, *v3, v10, a2);
    }
    else if ( v9 == 17 )
    {
      v11 = mm_chan_ctxt_unlink_cfm_handler;
      if ( *((uint8_t *)mm_chan_ctxt_unlink_cfm_handler + 2433) >= (unsigned int)*((uint8_t *)mm_chan_ctxt_unlink_cfm_handler
                                                                                         + 2434) )
      {
        log_printf(rf_stream_start2_n_14c);
      }
      else
      {
        if ( v10 + 4 == a2 || a2 == v10 + 5 )
        {
          timer_delay(a1);
          v12 = v11[2433];
          v13 = rf_cmd_send_n270_3280;
          v14 = (uint8_t)v11[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)rf_cmd_send_n26c
                               * (unsigned uint64_t)((unsigned int)(uint8_t)v11[2432] + 1)) >> 32) >> 5);
          v11[2432] = v14;
          v15 = &v11[20 * v14];
          *((uint32_t *)v15 + 409) = v7 + 4;
          *((uint32_t *)v15 + 412) = v10;
          v11[2433] = v12 + 1;
          cmd_handler_a(v13);
          unknown_func_12d104(0x400000);
          return 1;
        }
        log_printf(dword_1132A0, *v3, v10, a2);
      }
    }
    else
    {
      log_printf(rf_cmd_process_0, *v3, v9, v10, a2);
    }
  }
  v17 = is_controller_mode(&v7[-*(uint32_t *)rf_cmd_send_n280]);
  timer_delay(v17);
  return 1;
}

