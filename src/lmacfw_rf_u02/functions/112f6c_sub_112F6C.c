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


extern uint32_t off_113098;
extern uint32_t off_11309C;
extern uint32_t off_1130A0;
extern uint32_t off_1130A4;
extern uint32_t off_1130A8;
extern uint32_t off_1130B0;
extern uint32_t off_1130B4;
extern uint32_t off_1130C8;

// main_event_handler @ 0x112f6c, size 298 bytes
void  main_event_handler(int a1, int a2, int a3, int a4)
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

  v4 = off_113098;
  if ( *(uint8_t *)off_113098 )
  {
    if ( !*(uint16_t *)off_1130A4 )
    {
      check_interrupt_flag(512, "#we\n");
      return;
    }
    if ( *(uint8_t *)off_1130A0 >= (unsigned int)*(uint16_t *)off_1130A4 )
    {
      v18 = (uint16_t *)off_1130A8;
      *(uint8_t *)off_11309C = 1;
      check_interrupt_flag(512, "#wf:%X\n", *v18);
    }
  }
  else
  {
    if ( *(uint8_t *)off_11309C )
      return;
    if ( *(uint8_t *)off_1130A0 >= (unsigned int)*(uint16_t *)off_1130A4 && !*(uint8_t *)off_11309C )
    {
      v5 = (uint16_t *)off_1130A8;
      *(uint8_t *)off_11309C = 1;
      check_interrupt_flag(512, "#wf:%X\n", *v5);
      return;
    }
  }
  v6 = (*(int ( **)(uint32_t))(*((uint32_t *)off_1130B0 + 2) + 16))(*((uint32_t *)off_1130B0 + 1));
  v7 = (uint32_t *)v6;
  if ( v6 )
  {
    if ( *v4 )
    {
      v8 = (uint32_t *)off_1130C8;
      v9 = (int *)off_1130B4;
      v10 = *(uint32_t *)off_1130B4;
      v11 = *(uint32_t *)off_1130C8 + v6;
      if ( *(uint8_t *)off_11309C )
        v12 = send_control_packet(v11, v10);
      else
        v12 = send_data_packet(v11, v10);
    }
    else
    {
      v8 = (uint32_t *)off_1130C8;
      v9 = (int *)off_1130B4;
      v12 = send_data_packet(*(uint32_t *)off_1130C8 + v6, *(uint32_t *)off_1130B4);
    }
    if ( v12 )
    {
      v13 = off_11309C;
      log_printf("wd rx %d\r\n", v12);
      v14 = 5;
      while ( 1 )
      {
        if ( *v4 )
        {
          v15 = *v9;
          v16 = (int)v7 + *v8;
          v17 = *v13 ? send_control_packet(v16, v15) : send_data_packet(v16, v15);
        }
        else
        {
          v17 = send_data_packet((int)v7 + *v8, *v9);
        }
        if ( !v17 )
          break;
        if ( !--v14 )
        {
          log_printf("wd rx max time %d\r\n", 5);
          mem_free(v7);
          set_busy_flag_alt(256);
          return;
        }
      }
    }
  }
  else
  {
    set_busy_flag_alt(256);
    log_printf(aErrWdNoRxBuf);
  }
}
