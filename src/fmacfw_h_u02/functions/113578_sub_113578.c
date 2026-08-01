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
extern uint32_t off_1136AC;
extern uint32_t dword_1136C8;
extern uint32_t off_1136A8;
extern uint32_t dword_1136B4;
extern uint32_t off_1136A4;
extern uint32_t off_1136B8;
extern uint32_t off_1136D0;
extern uint32_t off_1136BC;
extern uint32_t dword_1136C0;
extern uint32_t dword_1136C4;
extern uint32_t dword_1136CC;

// rf_get_flag @ 0x113578, size 294 bytes
void rf_get_flag()
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

  v0 = off_1136A0;
  if ( *(uint8_t *)off_1136A0 )
  {
    if ( !*(uint16_t *)off_1136AC )
    {
      check_feature_flag(512, dword_1136C8);
      return;
    }
    if ( *(uint8_t *)off_1136A8 >= (unsigned int)*(uint16_t *)off_1136AC )
    {
      v13 = dword_1136B4;
      *(uint8_t *)off_1136A4 = 1;
      check_feature_flag(512, v13);
    }
  }
  else
  {
    if ( *(uint8_t *)off_1136A4 )
      return;
    if ( *(uint8_t *)off_1136A8 >= (unsigned int)*(uint16_t *)off_1136AC && !*(uint8_t *)off_1136A4 )
    {
      *(uint8_t *)off_1136A4 = 1;
      check_feature_flag(512, dword_1136B4);
      return;
    }
  }
  v1 = (*(int ( **)(uint32_t))(*((uint32_t *)off_1136B8 + 2) + 16))(*((uint32_t *)off_1136B8 + 1));
  v2 = (uint32_t *)v1;
  if ( v1 )
  {
    if ( *v0 )
    {
      v3 = off_1136D0;
      v4 = (unsigned int *)off_1136BC;
      v5 = *(uint32_t *)off_1136BC;
      v6 = *(uint32_t *)off_1136D0 + v1;
      if ( *(uint8_t *)off_1136A4 )
        v7 = check_and_init_flag(v6, v5);
      else
        v7 = bt_get_state(v6, v5);
    }
    else
    {
      v3 = off_1136D0;
      v4 = (unsigned int *)off_1136BC;
      v7 = bt_get_state(*(uint32_t *)off_1136D0 + v1, *(uint32_t *)off_1136BC);
    }
    if ( v7 )
    {
      v8 = off_1136A4;
      debug_printf(dword_1136C0, v7);
      v9 = 5;
      while ( 1 )
      {
        if ( *v0 )
        {
          v10 = *v4;
          v11 = (int)v2 + *v3;
          v12 = *v8 ? check_and_init_flag(v11, v10) : bt_get_state(v11, v10);
        }
        else
        {
          v12 = bt_get_state((int)v2 + *v3, *v4);
        }
        if ( !v12 )
          break;
        if ( !--v9 )
        {
          debug_printf(dword_1136C4, 5);
          wait_for_state(v2);
          irq_disable_global_2(32);
          return;
        }
      }
    }
  }
  else
  {
    irq_disable_global_2(32);
    debug_printf(dword_1136CC);
  }
}

