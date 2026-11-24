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


extern uint32_t off_11363C;
extern uint32_t off_113640;
extern uint32_t off_113644;
extern uint32_t off_113648;
extern uint32_t off_11364C;
extern uint32_t off_113654;
extern uint32_t off_113658;
extern uint32_t off_11366C;

// bt_ctrl_main_task @ 0x113514, size 294 bytes
void  bt_ctrl_main_task(int a1, int a2, int a3, int a4)
{
  uint8_t *v4; // r5
  uint16_t *v5; // r2
  int v6; // r0
  uint32_t *v7; // r4
  uint32_t *v8; // r8
  int *v9; // r6
  int v10; // r1
  int v11; // r0
  int v12; // r0
  uint8_t *v13; // r7
  int v14; // r9
  int v15; // r1
  int v16; // r0
  int v17; // r0
  uint16_t *v18; // r3

  v4 = off_11363C;
  if ( *(uint8_t *)off_11363C )
  {
    if ( !*(uint16_t *)off_113648 )
    {
      state_check_feature(512, "#we\n");
      return;
    }
    if ( *(uint8_t *)off_113644 >= (unsigned int)*(uint16_t *)off_113648 )
    {
      v18 = (uint16_t *)off_11364C;
      *(uint8_t *)off_113640 = 1;
      state_check_feature(512, "#wf:%X\n", *v18);
    }
  }
  else
  {
    if ( *(uint8_t *)off_113640 )
      return;
    if ( *(uint8_t *)off_113644 >= (unsigned int)*(uint16_t *)off_113648 && !*(uint8_t *)off_113640 )
    {
      v5 = (uint16_t *)off_11364C;
      *(uint8_t *)off_113640 = 1;
      state_check_feature(512, "#wf:%X\n", *v5);
      return;
    }
  }
  v6 = (*(int ( **)(uint32_t))(*((uint32_t *)off_113654 + 2) + 16))(*((uint32_t *)off_113654 + 1));
  v7 = (uint32_t *)v6;
  if ( v6 )
  {
    if ( *v4 )
    {
      v8 = (uint32_t *)off_11366C;
      v9 = (int *)off_113658;
      v10 = *(uint32_t *)off_113658;
      v11 = *(uint32_t *)off_11366C + v6;
      if ( *(uint8_t *)off_113640 )
        v12 = global_env_init_params(v11, v10);
      else
        v12 = global_env_init(v11, v10);
    }
    else
    {
      v8 = (uint32_t *)off_11366C;
      v9 = (int *)off_113658;
      v12 = global_env_init(*(uint32_t *)off_11366C + v6, *(uint32_t *)off_113658);
    }
    if ( v12 )
    {
      v13 = off_113640;
      printf_wrapper("wd rx %d\r\n", v12);
      v14 = 5;
      while ( 1 )
      {
        if ( *v4 )
        {
          v15 = *v9;
          v16 = (int)v7 + *v8;
          v17 = *v13 ? global_env_init_params(v16, v15) : global_env_init(v16, v15);
        }
        else
        {
          v17 = global_env_init((int)v7 + *v8, *v9);
        }
        if ( !v17 )
          break;
        if ( !--v14 )
        {
          printf_wrapper("wd rx max time %d\r\n", 5);
          memory_pool_free(v7);
          set_system_flag_1(32);
          return;
        }
      }
    }
  }
  else
  {
    set_system_flag_1(32);
    printf_wrapper(aErrWdNoRxBuf);
  }
}
