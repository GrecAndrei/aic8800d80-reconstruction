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
extern uint32_t off_1137EC;
extern uint32_t dword_113808;
extern uint32_t off_1137E8;
extern uint32_t dword_1137F4;
extern uint32_t off_1137E4;
extern uint32_t off_1137F8;
extern uint32_t off_113810;
extern uint32_t off_1137FC;
extern uint32_t dword_113800;
extern uint32_t dword_113804;
extern uint32_t dword_11380C;

// read_state_flag @ 0x1136b8, size 294 bytes
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
    if ( !*(uint16_t *)off_1137EC )
    {
      check_status_bits(512, dword_113808);
      return;
    }
    if ( *(uint8_t *)off_1137E8 >= (unsigned int)*(uint16_t *)off_1137EC )
    {
      v13 = dword_1137F4;
      *(uint8_t *)off_1137E4 = 1;
      check_status_bits(512, v13);
    }
  }
  else
  {
    if ( *(uint8_t *)off_1137E4 )
      return;
    if ( *(uint8_t *)off_1137E8 >= (unsigned int)*(uint16_t *)off_1137EC && !*(uint8_t *)off_1137E4 )
    {
      *(uint8_t *)off_1137E4 = 1;
      check_status_bits(512, dword_1137F4);
      return;
    }
  }
  v1 = (*(int ( **)(uint32_t))(*((uint32_t *)off_1137F8 + 2) + 16))(*((uint32_t *)off_1137F8 + 1));
  v2 = (uint32_t *)v1;
  if ( v1 )
  {
    if ( *v0 )
    {
      v3 = off_113810;
      v4 = (unsigned int *)off_1137FC;
      v5 = *(uint32_t *)off_1137FC;
      v6 = *(uint32_t *)off_113810 + v1;
      if ( *(uint8_t *)off_1137E4 )
        v7 = ke_task_init(v6, v5);
      else
        v7 = irq_state_load_b(v6, v5);
    }
    else
    {
      v3 = off_113810;
      v4 = (unsigned int *)off_1137FC;
      v7 = irq_state_load_b(*(uint32_t *)off_113810 + v1, *(uint32_t *)off_1137FC);
    }
    if ( v7 )
    {
      v8 = off_1137E4;
      log_printf(dword_113800, v7);
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
          log_printf(dword_113804, 5);
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
    log_printf(dword_11380C);
  }
}

