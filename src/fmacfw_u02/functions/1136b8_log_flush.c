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

extern uint32_t off_1137E0;
extern uint32_t off_1137E4;
extern uint32_t off_1137FC;

// read_state_flag @ 0x1136b8, size 294 bytes
// Doc: rf_stream_start2_n314_3704 [rf]: RF stream start: loads callback table and invokes dispatch function
// rf_stream_start2_n314_3704 [rf]: RF stream start: loads callback table and invokes dispatch function
void read_state_flag()
{
  uint8_t *v0; // r5
  int v1; // r0
  uint32_t *v2; // r4
  uint32_t *v3; // r8
  unsigned int *v4; // r6
  unsigned int v5; // r1
  int v6; // r0
  int v7; // r0
  uint8_t *v8; // r7
  int v9; // r9
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r0
  int v13; // r1

  v0 = off_1137E0;
  if ( *(uint8_t *)off_1137E0 )
  {
    if ( !*(uint16_t *)rf_msg_process_body_n_45c )
    {
      check_status_bits(512, rf_msg_process_body_n_440);
      return;
    }
    if ( *(uint8_t *)rf_stream_start2_n3f8_37e8 >= (unsigned int)*(uint16_t *)rf_msg_process_body_n_45c )
    {
      v13 = rf_cmd_queue_next_n340;
      *(uint8_t *)off_1137E4 = 1;
      check_status_bits(512, v13);
    }
  }
  else
  {
    if ( *(uint8_t *)off_1137E4 )
      return;
    if ( *(uint8_t *)rf_stream_start2_n3f8_37e8 >= (unsigned int)*(uint16_t *)rf_msg_process_body_n_45c
      && !*(uint8_t *)off_1137E4 )
    {
      *(uint8_t *)off_1137E4 = 1;
      check_status_bits(512, rf_cmd_queue_next_n340);
      return;
    }
  }
  v1 = (*(int ( **)(uint32_t))(*((uint32_t *)rf_msg_process_body_n_450 + 2) + 16))(*((uint32_t *)rf_msg_process_body_n_450
                                                                                         + 1));
  v2 = (uint32_t *)v1;
  if ( v1 )
  {
    if ( *v0 )
    {
      v3 = rf_stream_start2_n420;
      v4 = (unsigned int *)off_1137FC;
      v5 = *(uint32_t *)off_1137FC;
      v6 = *(uint32_t *)rf_stream_start2_n420 + v1;
      if ( *(uint8_t *)off_1137E4 )
        v7 = ke_task_init(v6, v5);
      else
        v7 = irq_state_load_b(v6, v5);
    }
    else
    {
      v3 = rf_stream_start2_n420;
      v4 = (unsigned int *)off_1137FC;
      v7 = irq_state_load_b(*(uint32_t *)rf_stream_start2_n420 + v1, *(uint32_t *)off_1137FC);
    }
    if ( v7 )
    {
      v8 = off_1137E4;
      log_printf(rf_cmd_queue_next_n34c, v7);
      v9 = 5;
      while ( 1 )
      {
        if ( *v0 )
        {
          v10 = *v4;
          v11 = (int)v2 + *v3;
          v12 = *v8 ? ke_task_init(v11, v10) : irq_state_load_b(v11, v10);
        }
        else
        {
          v12 = irq_state_load_b((int)v2 + *v3, *v4);
        }
        if ( !v12 )
          break;
        if ( !--v9 )
        {
          log_printf(rf_cmd_queue_next_n350, 5);
          is_controller_mode(v2);
          unknown_func_12d104(32);
          return;
        }
      }
    }
  }
  else
  {
    unknown_func_12d104(32);
    log_printf(rf_cmd_process_n2b4);
  }
}

