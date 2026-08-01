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

extern uint32_t dword_123208;
extern uint32_t dword_123210;
extern uint32_t dword_123214;
extern uint32_t dword_123218;
extern uint32_t dword_12322C;
extern uint32_t dword_12321C;
extern uint32_t dword_12323C;
extern uint32_t dword_123234;
extern uint32_t dword_123230;
extern uint32_t dword_123238;
extern uint32_t dword_123220;
extern uint32_t off_123224;
extern uint32_t off_123228;
extern uint32_t dword_12320C;

// process_queue_message @ 0x1230e8, size 288 bytes
int  process_queue_message(unsigned int a1)
{
  int v1; // r0
  int v2; // r4
  uint32_t *v4; // r0
  uint32_t *v5; // r5
  unsigned int CPSR; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r3
  uint8_t *v11; // r2
  int v12; // r0
  int v13; // r8
  int v14; // r7
  unsigned int v15; // r5
  unsigned int v16; // r6
  int v17; // t1
  int v18; // r7
  int v19; // r6
  unsigned int v20; // r4
  unsigned int v21; // r5
  int v22; // t1
  unsigned int v23; // [sp+8h] [bp-8h]

  v1 = co_list_insert(a1, (uint8_t *)dword_123208, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( memset_ff(dword_123210) != v1 || strcmp(dword_123210, dword_123208) )
      {
        v4 = list_pop_front(dword_123214);
        v5 = v4;
        if ( v4 )
        {
          strcpy(v4 + 1, dword_123208);
          check_kernel_state(dword_123218, v5);
        }
        else
        {
          uart_tx_string((uint8_t *)dword_12322C);
        }
      }
      else
      {
        CPSR = __get_CPSR();
        v7 = __get_CPSR();
        v8 = __get_CPSR();
        v9 = __get_CPSR();
        v10 = __get_CPSR();
        v23 = __get_CPSR();
        log_printf(dword_12321C, CPSR, v7, v8, v9, v10, v23);
        if ( v9 )
        {
          v13 = dword_12323C;
          v14 = dword_123234;
          v15 = v9 & 0xFFFFFFF0;
          uart_tx_string((uint8_t *)dword_123230);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              log_printf(v13, v15);
            v17 = *(uint32_t *)v15;
            v15 += 4;
            log_printf(v14, v17);
          }
          while ( v16 != v15 );
        }
        if ( v8 )
        {
          v18 = dword_12323C;
          v19 = dword_123234;
          v20 = v8 & 0xFFFFFFF0;
          uart_tx_string((uint8_t *)dword_123238);
          v21 = v20 + 256;
          do
          {
            if ( !(v20 << 28) )
              log_printf(v18, v20);
            v22 = *(uint32_t *)v20;
            v20 += 4;
            log_printf(v19, v22);
          }
          while ( v21 != v20 );
        }
        uart_tx_string((uint8_t *)dword_123220);
        v11 = off_123224;
        v12 = *(uint8_t *)off_123224;
        if ( *(uint8_t *)off_123224 )
        {
          *((uint8_t *)off_123228 + 783) = -4;
          v2 = 0;
          *v11 = 0;
        }
        else
        {
          *((uint8_t *)off_123228 + 783) = -12;
          v2 = v12;
          *v11 = 1;
        }
      }
    }
    else
    {
      uart_tx_string((uint8_t *)dword_12320C);
    }
    co_list_insert(0x30u, (uint8_t *)dword_123208, dword_12320C);
  }
  return v2;
}

