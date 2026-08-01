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

extern uint32_t off_112B44;
extern uint32_t dword_112B58;
extern uint32_t dword_112B60;
extern uint32_t off_112B4C;
extern uint32_t off_112B78;
extern uint32_t dword_112B68;
extern uint32_t off_112B64;

// tick_counter_update @ 0x112a0c, size 308 bytes
// Doc: rf_cmd_send_n190 [rf]: Send RF command to radio via mailbox
// rf_cmd_send_n190 [rf]: Send RF command to radio via mailbox
int  tick_counter_update(uint8_t *a1, unsigned int a2, int a3)
{
  uint16_t *v3; // r7
  uint8_t *v4; // r6
  uint8_t *v5; // r4
  char v6; // r2
  uint8_t *v7; // r4
  int v9; // r8
  int v10; // r3
  int v11; // r6
  uint8_t *v12; // r8
  char v13; // r5
  int v14; // r0
  unsigned int v15; // r3
  char *v16; // r3
  int v18; // r0

  v3 = (uint16_t *)rf_cmd_send_2b40;
  v4 = (uint8_t *)off_112B44;
  v5 = rf_cmd_send_n230;
  ++*(uint16_t *)rf_cmd_send_2b40;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  v7 = a1;
  if ( *v4 != 2 )
  {
    log_printf(dword_112B58, *v3, *v4);
    lookup_task_id(rf_cmd_send_n244, v7, a2, *v4);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    log_printf(dword_112B60, *v3, a2);
  }
  else
  {
    v9 = a1[2];
    v10 = (a1[1] << 8) & 0xF00;
    v11 = *a1 | v10;
    if ( *(uint8_t *)off_112B4C )
      a1 = (uint8_t *)check_interrupt_flag(512, rf_cmd_send_n254, a2, v10);
    if ( v9 == 17 )
    {
      v12 = off_112B78;
      if ( *((uint8_t *)off_112B78 + 2433) >= (unsigned int)*((uint8_t *)off_112B78 + 2434) )
      {
        log_printf(rf_cmd_send_n258);
      }
      else
      {
        if ( v11 + 4 == a2 || a2 == v11 + 5 )
        {
          check_and_process(a1);
          v13 = v12[2433];
          v14 = rf_bus_mark_n_494_2b54;
          v15 = (uint8_t)v12[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)rf_cmd_send_n238
                               * (unsigned uint64_t)((unsigned int)(uint8_t)v12[2432] + 1)) >> 32) >> 5);
          v12[2432] = v15;
          v16 = &v12[20 * v15];
          *((uint32_t *)v16 + 409) = v7 + 4;
          *((uint32_t *)v16 + 412) = v11;
          v12[2433] = v13 + 1;
          check_kernel_state(v14);
          set_busy_flag_alt(0x1000000);
          return 1;
        }
        log_printf(rf_cmd_send_n25c, *v3, v11, a2);
      }
    }
    else
    {
      log_printf(dword_112B68, *v3, v9, v11, a2);
    }
  }
  v18 = mem_free(&v7[-*(uint32_t *)off_112B64]);
  check_and_process(v18);
  return 1;
}

