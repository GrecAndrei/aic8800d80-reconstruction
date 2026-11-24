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
extern uint32_t dword_123214;
extern uint32_t dword_123218;
extern uint32_t off_123210;
extern uint32_t off_123224;
extern uint32_t off_123228;

// process_queue_message @ 0x1230e8, size 288 bytes
int  process_queue_message(int a1)
{
  int v1; // r0
  int v2; // r4
  uint32_t *v4; // r0
  uint32_t *v5; // r5
  unsigned int CPSR; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r5
  uint8_t *v10; // r2
  int v11; // r0
  unsigned int v12; // r5
  unsigned int v13; // r6
  int v14; // t1
  unsigned int v15; // r4
  unsigned int v16; // r5
  int v17; // t1

  v1 = co_list_insert(a1, (uint8_t *)dword_123208, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( memset_ff(off_123210) != v1 || strcmp(off_123210, (unsigned int *)dword_123208) )
      {
        v4 = list_pop_front(dword_123214);
        v5 = v4;
        if ( v4 )
        {
          strcpy((unsigned int)(v4 + 1), dword_123208);
          check_kernel_state(dword_123218, v5);
        }
        else
        {
          uart_tx_string(aErrCmdFreeList);
        }
      }
      else
      {
        CPSR = __get_CPSR();
        v7 = __get_CPSR();
        v8 = __get_CPSR();
        v9 = __get_CPSR();
        log_printf(aControl08xXpsr, CPSR, v7, v8, v9, __get_CPSR(), __get_CPSR());
        if ( v9 )
        {
          v12 = v9 & 0xFFFFFFF0;
          uart_tx_string(aDumpmsp);
          v13 = v12 + 256;
          do
          {
            if ( !(v12 << 28) )
              log_printf("\r\n[%08x]:", v12);
            v14 = *(uint32_t *)v12;
            v12 += 4;
            log_printf(" %08X", v14);
          }
          while ( v13 != v12 );
        }
        if ( v8 )
        {
          v15 = v8 & 0xFFFFFFF0;
          uart_tx_string(aDumppsp);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              log_printf("\r\n[%08x]:", v15);
            v17 = *(uint32_t *)v15;
            v15 += 4;
            log_printf(" %08X", v17);
          }
          while ( v16 != v15 );
        }
        uart_tx_string(aAic_0);
        v10 = off_123224;
        v11 = *(uint8_t *)off_123224;
        if ( *(uint8_t *)off_123224 )
        {
          *((uint8_t *)off_123228 + 783) = -4;
          v2 = 0;
          *v10 = 0;
        }
        else
        {
          *((uint8_t *)off_123228 + 783) = -12;
          v2 = v11;
          *v10 = 1;
        }
      }
    }
    else
    {
      uart_tx_string(aAic);
    }
    co_list_insert(0x30u, (uint8_t *)dword_123208, (unsigned int)aAic);
  }
  return v2;
}
