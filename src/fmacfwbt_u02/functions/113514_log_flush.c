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

extern uint32_t off_113648;
extern uint32_t dword_113664;
extern uint32_t off_113640;

// bt_ctrl_main_task @ 0x113514, size 294 bytes
// Doc: rf_stream_start_354e [rf]: Start RF data stream and check link state
// rf_stream_start_354e [rf]: Start RF data stream and check link state
void bt_ctrl_main_task()
{
  uint8_t *v0; // r5
  int v1; // r0
  uint32_t *v2; // r4
  uint32_t *v3; // r8
  unsigned int *v4; // r6
  unsigned int v5; // r1
  int v6; // r0
  int started; // r0
  uint8_t *v8; // r7
  int v9; // r9
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r0
  int v13; // r1

  v0 = rf_stream_start2_n3f0;
  if ( *(uint8_t *)rf_stream_start2_n3f0 )
  {
    if ( !*(uint16_t *)off_113648 )
    {
      state_check_feature(512, dword_113664);
      return;
    }
    if ( *(uint8_t *)rf_stream_start2_n3f8 >= (unsigned int)*(uint16_t *)off_113648 )
    {
      v13 = rf_stream_start2_650;
      *(uint8_t *)off_113640 = 1;
      state_check_feature(512, v13);
    }
  }
  else
  {
    if ( *(uint8_t *)off_113640 )
      return;
    if ( *(uint8_t *)rf_stream_start2_n3f8 >= (unsigned int)*(uint16_t *)off_113648
      && !*(uint8_t *)off_113640 )
    {
      *(uint8_t *)off_113640 = 1;
      state_check_feature(512, rf_stream_start2_650);
      return;
    }
  }
  v1 = (*(int ( **)(uint32_t))(*((uint32_t *)rf_stream_start2_n408 + 2) + 16))(*((uint32_t *)rf_stream_start2_n408
                                                                                     + 1));
  v2 = (uint32_t *)v1;
  if ( v1 )
  {
    if ( *v0 )
    {
      v3 = rf_stream_start2_alt_0;
      v4 = (unsigned int *)rf_stream_start2_n40c;
      v5 = *(uint32_t *)rf_stream_start2_n40c;
      v6 = *(uint32_t *)rf_stream_start2_alt_0 + v1;
      if ( *(uint8_t *)off_113640 )
        started = global_env_init_params(v6, v5);
      else
        started = global_env_init(v6, v5);
    }
    else
    {
      v3 = rf_stream_start2_alt_0;
      v4 = (unsigned int *)rf_stream_start2_n40c;
      started = global_env_init(*(uint32_t *)rf_stream_start2_alt_0 + v1, *(uint32_t *)rf_stream_start2_n40c);
    }
    if ( started )
    {
      v8 = off_113640;
      printf_wrapper(rf_stream_start2_n410, started);
      v9 = 5;
      while ( 1 )
      {
        if ( *v0 )
        {
          v10 = *v4;
          v11 = (int)v2 + *v3;
          v12 = *v8 ? global_env_init_params(v11, v10) : global_env_init(v11, v10);
        }
        else
        {
          v12 = global_env_init((int)v2 + *v3, *v4);
        }
        if ( !v12 )
          break;
        if ( !--v9 )
        {
          printf_wrapper(rf_stream_start2_n414, 5);
          memory_pool_free(v2);
          set_system_flag_1(32);
          return;
        }
      }
    }
  }
  else
  {
    set_system_flag_1(32);
    printf_wrapper(rf_stream_start2_n41c);
  }
}

