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

extern uint32_t off_1130C8;
extern uint32_t off_1130D0;
extern uint32_t dword_1130E4;
extern uint32_t dword_1130E8;
extern uint32_t dword_1130F4;
extern uint32_t dword_1130F8;
extern uint32_t off_113104;
extern uint32_t dword_113100;
extern uint32_t dword_1130DC;
extern uint32_t dword_1130D8;

// seq_num_inc @ 0x112f60, size 360 bytes
// Doc: rf_stream_start2_n_18a [rf]: Start secondary RF streaming/transfer sequence
// rf_stream_start2_n_18a [rf]: Start secondary RF streaming/transfer sequence
int  seq_num_inc(uint8_t *a1, unsigned int a2, int a3)
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

  v3 = (uint16_t *)off_1130C8;
  v4 = (uint8_t *)rf_stream_start_0cc;
  v5 = off_1130D0;
  ++*(uint16_t *)off_1130C8;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  v7 = a1;
  if ( *v4 != 2 )
  {
    printf_wrapper(rf_stream_start2_n_16c, *v3, *v4);
    band_is_supported(dword_1130E4, v7, a2, *v4);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    printf_wrapper(dword_1130E8, *v3, a2);
  }
  else
  {
    v9 = a1[2];
    v10 = *a1 | (a1[1] << 8) & 0xF00;
    if ( *(uint8_t *)rf_msg_process_body_n_14e )
      a1 = (uint8_t *)state_check_feature(512, dword_1130F4);
    if ( v9 == 1 )
    {
      if ( a2 == v10 || v10 + 1 == a2 )
      {
        ((void (*)(void))bt_task_tail_dispatch)();
        rx_packet_parse(v7 + 4);
        set_system_flag_1(512);
        return 1;
      }
      printf_wrapper(dword_1130F8, *v3, v10, a2);
    }
    else if ( v9 == 17 )
    {
      v11 = off_113104;
      if ( *((uint8_t *)off_113104 + 2433) >= (unsigned int)*((uint8_t *)off_113104 + 2434) )
      {
        printf_wrapper(dword_113100);
      }
      else
      {
        if ( v10 + 4 == a2 || a2 == v10 + 5 )
        {
          bt_task_tail_dispatch(a1);
          v12 = v11[2433];
          v13 = dword_1130DC;
          v14 = (uint8_t)v11[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)dword_1130D8
                               * (unsigned uint64_t)((unsigned int)(uint8_t)v11[2432] + 1)) >> 32) >> 5);
          v11[2432] = v14;
          v15 = &v11[20 * v14];
          *((uint32_t *)v15 + 409) = v7 + 4;
          *((uint32_t *)v15 + 412) = v10;
          v11[2433] = v12 + 1;
          check_abort_flag(v13);
          set_system_flag_1(0x400000);
          return 1;
        }
        printf_wrapper(rf_msg_handler_n19c, *v3, v10, a2);
      }
    }
    else
    {
      printf_wrapper(rf_stream_start2_n_15c, *v3, v9, v10, a2);
    }
  }
  v17 = memory_pool_free(&v7[-*(uint32_t *)rf_mem_scan_bytes]);
  bt_task_tail_dispatch(v17);
  return 1;
}

