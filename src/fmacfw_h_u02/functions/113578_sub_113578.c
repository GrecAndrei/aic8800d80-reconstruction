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


extern uint32_t off_1136A0;
extern uint32_t off_1136A4;
extern uint32_t off_1136A8;
extern uint32_t off_1136AC;
extern uint32_t off_1136B0;
extern uint32_t off_1136B8;
extern uint32_t off_1136BC;
extern uint32_t off_1136D0;

// rf_get_flag @ 0x113578, size 294 bytes
void  rf_get_flag(int a1, int a2, int a3, int a4)
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

  v4 = off_1136A0;
  if ( *(uint8_t *)off_1136A0 )
  {
    if ( !*(uint16_t *)off_1136AC )
    {
      check_feature_flag(512, "#we\n");
      return;
    }
    if ( *(uint8_t *)off_1136A8 >= (unsigned int)*(uint16_t *)off_1136AC )
    {
      v18 = (uint16_t *)off_1136B0;
      *(uint8_t *)off_1136A4 = 1;
      check_feature_flag(512, "#wf:%X\n", *v18);
    }
  }
  else
  {
    if ( *(uint8_t *)off_1136A4 )
      return;
    if ( *(uint8_t *)off_1136A8 >= (unsigned int)*(uint16_t *)off_1136AC && !*(uint8_t *)off_1136A4 )
    {
      v5 = (uint16_t *)off_1136B0;
      *(uint8_t *)off_1136A4 = 1;
      check_feature_flag(512, "#wf:%X\n", *v5);
      return;
    }
  }
  v6 = (*(int ( **)(uint32_t))(*((uint32_t *)off_1136B8 + 2) + 16))(*((uint32_t *)off_1136B8 + 1));
  v7 = (uint32_t *)v6;
  if ( v6 )
  {
    if ( *v4 )
    {
      v8 = (uint32_t *)off_1136D0;
      v9 = (int *)off_1136BC;
      v10 = *(uint32_t *)off_1136BC;
      v11 = *(uint32_t *)off_1136D0 + v6;
      if ( *(uint8_t *)off_1136A4 )
        v12 = check_and_init_flag(v11, v10);
      else
        v12 = bt_get_state(v11, v10);
    }
    else
    {
      v8 = (uint32_t *)off_1136D0;
      v9 = (int *)off_1136BC;
      v12 = bt_get_state(*(uint32_t *)off_1136D0 + v6, *(uint32_t *)off_1136BC);
    }
    if ( v12 )
    {
      v13 = off_1136A4;
      debug_printf("wd rx %d\r\n", v12);
      v14 = 5;
      while ( 1 )
      {
        if ( *v4 )
        {
          v15 = *v9;
          v16 = (int)v7 + *v8;
          v17 = *v13 ? check_and_init_flag(v16, v15) : bt_get_state(v16, v15);
        }
        else
        {
          v17 = bt_get_state((int)v7 + *v8, *v9);
        }
        if ( !v17 )
          break;
        if ( !--v14 )
        {
          debug_printf("wd rx max time %d\r\n", 5);
          wait_for_state(v7);
          irq_disable_global_2(32);
          return;
        }
      }
    }
  }
  else
  {
    irq_disable_global_2(32);
    debug_printf(aErrWdNoRxBuf);
  }
}
