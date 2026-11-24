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
extern uint32_t off_1137E8;
extern uint32_t off_1137EC;
extern uint32_t off_1137F0;
extern uint32_t off_1137F8;
extern uint32_t off_1137FC;
extern uint32_t off_113810;

// read_state_flag @ 0x1136b8, size 294 bytes
void  read_state_flag(int a1, int a2, int a3, int a4)
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

  v4 = off_1137E0;
  if ( *(uint8_t *)off_1137E0 )
  {
    if ( !*(uint16_t *)off_1137EC )
    {
      check_status_bits(512, "#we\n");
      return;
    }
    if ( *(uint8_t *)off_1137E8 >= (unsigned int)*(uint16_t *)off_1137EC )
    {
      v18 = (uint16_t *)off_1137F0;
      *(uint8_t *)off_1137E4 = 1;
      check_status_bits(512, "#wf:%X\n", *v18);
    }
  }
  else
  {
    if ( *(uint8_t *)off_1137E4 )
      return;
    if ( *(uint8_t *)off_1137E8 >= (unsigned int)*(uint16_t *)off_1137EC && !*(uint8_t *)off_1137E4 )
    {
      v5 = (uint16_t *)off_1137F0;
      *(uint8_t *)off_1137E4 = 1;
      check_status_bits(512, "#wf:%X\n", *v5);
      return;
    }
  }
  v6 = (*(int ( **)(uint32_t))(*((uint32_t *)off_1137F8 + 2) + 16))(*((uint32_t *)off_1137F8 + 1));
  v7 = (uint32_t *)v6;
  if ( v6 )
  {
    if ( *v4 )
    {
      v8 = (uint32_t *)off_113810;
      v9 = (int *)off_1137FC;
      v10 = *(uint32_t *)off_1137FC;
      v11 = *(uint32_t *)off_113810 + v6;
      if ( *(uint8_t *)off_1137E4 )
        v12 = ke_task_init(v11, v10);
      else
        v12 = irq_state_load_b(v11, v10);
    }
    else
    {
      v8 = (uint32_t *)off_113810;
      v9 = (int *)off_1137FC;
      v12 = irq_state_load_b(*(uint32_t *)off_113810 + v6, *(uint32_t *)off_1137FC);
    }
    if ( v12 )
    {
      v13 = off_1137E4;
      log_printf("wd rx %d\r\n", v12);
      v14 = 5;
      while ( 1 )
      {
        if ( *v4 )
        {
          v15 = *v9;
          v16 = (int)v7 + *v8;
          v17 = *v13 ? ke_task_init(v16, v15) : irq_state_load_b(v16, v15);
        }
        else
        {
          v17 = irq_state_load_b((int)v7 + *v8, *v9);
        }
        if ( !v17 )
          break;
        if ( !--v14 )
        {
          log_printf("wd rx max time %d\r\n", 5);
          is_controller_mode(v7);
          unknown_func_12d104(32);
          return;
        }
      }
    }
  }
  else
  {
    unknown_func_12d104(32);
    log_printf(aErrWdNoRxBuf);
  }
}
