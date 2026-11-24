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


extern uint32_t dword_11F6B0;
extern uint32_t off_11F690;
extern uint32_t off_11F694;
extern uint32_t off_11F69C;
extern uint32_t off_11F6A0;
extern uint32_t off_11F6A4;
extern uint32_t off_11F6A8;
extern uint32_t off_11F6AC;
extern uint32_t off_11F6B4;
extern uint32_t off_11F6B8;
extern uint32_t off_11F6BC;
extern uint32_t off_11F6C4;
extern uint32_t off_11F6C8;
extern uint32_t off_11F6D0;
extern uint32_t off_11F6D4;
extern uint32_t off_11F6D8;
extern uint32_t off_11F6DC;
extern uint32_t off_11F6E0;

// llm_conn_active_check @ 0x11f4f4, size 412 bytes
int  llm_conn_active_check(int result)
{
  int v1; // r4
  int *v2; // r2
  unsigned int v3; // r1
  uint32_t *v4; // r3
  uint32_t *v5; // r0
  int v6; // r1
  int *v7; // r6
  uint32_t *v8; // r5
  volatile unsigned int v9; // r8
  unsigned int v10; // r3
  volatile unsigned int v11; // r10
  uint32_t *v12; // r9
  uint32_t *v13; // r8
  unsigned int v14; // r3
  int v15; // r5
  int v16; // r3
  int v17; // r2
  uint32_t *v18; // r5
  int v19; // r2
  int v20; // r3
  uint32_t *v21; // r2
  int v22; // r1

  v1 = result;
  if ( *(uint8_t *)(result + 1224) )
    result = llc_clear_evt_state(result);
  if ( *(uint32_t *)(v1 + 72) )
    result = rx_validate_entry(v1);
  if ( (*(uint32_t *)(v1 + 4) & 1) != 0 )
  {
    if ( (*(uint32_t *)off_11F690 & 0x2000000) != 0 || (result = *(uint32_t *)off_11F690 << 6, *((uint8_t *)off_11F694 + 36)) )
    {
      result = check_status_bits(2, "M,%d\r\n", *(uint8_t *)(v1 + 128));
      v2 = (int *)off_11F69C;
      v3 = *((uint8_t *)off_11F69C + 1);
      *(uint32_t *)(v1 + 4) &= ~1u;
      *v2 = v3 > 1;
      if ( BYTE2(((uint32_t *)(uintptr_t)off_11F6A0)[47]) )
      {
        if ( **(uint8_t **)off_11F6A4 == 2 )
        {
          result = fatal_error_handler();
          v4 = off_11F6A8;
          *(uint32_t *)off_11F6A8 &= ~1u;
          *v4 &= ~0x80u;
          if ( *(uint8_t *)(v1 + 128) > 9u )
          {
            v5 = off_11F6AC;
            v6 = dword_11F6B0;
            *(uint32_t *)off_11F690 &= ~4u;
            if ( (*v5 & v6) == 0 )
              process_global_167204();
            if ( *(uint32_t *)off_11F6B4 << 28 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_11F6B8 = 1;
              }
              v7 = (int *)off_11F6BC;
              v8 = off_11F6B4;
              ++*(uint32_t *)off_11F6BC;
              *v8 = 0;
              v9 = (*(volatile uint32_t *)0x40501010u);
              while ( *v8 << 28 )
              {
                v10 = (*(volatile uint32_t *)0x40501010u) - v9;
                if ( v10 > 0x7530 )
                  check_status_bits(2, aIdleErr, 30000);
              }
              v11 = (*(volatile uint32_t *)0x40501010u);
              if ( (*(uint32_t *)off_11F6C4 & *(uint32_t *)off_11F6C8 & 4) == 0 )
              {
                v12 = off_11F6C4;
                v13 = off_11F6C8;
                do
                {
                  v14 = (*(volatile uint32_t *)0x40501010u) - v11;
                  v15 = *v12 & *v13;
                  if ( v14 > 0x7530 )
                    check_status_bits(2, aIdleIntErr);
                }
                while ( (v15 & 4) == 0 );
              }
              *(uint32_t *)off_11F6D0 = 4;
              if ( *v7 )
              {
                v16 = *v7 - 1;
                v17 = *(uint32_t *)off_11F6B8;
                *v7 = v16;
                if ( !v16 )
                {
                  if ( v17 )
                    __enable_irq();
                }
              }
            }
            v18 = off_11F6D8;
            v19 = **(uint16_t **)off_11F6D4;
            v20 = *((uint32_t *)off_11F6D8 + 1) | 0x200;
            *((uint32_t *)off_11F6D8 + 1) = v20;
            if ( v19 < 0 )
            {
              if ( *(uint32_t *)off_11F6B4 << 28 )
              {
                call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
                v20 = v18[1];
              }
            }
            v21 = off_11F6B4;
            v22 = off_11F6E0;
            *(uint32_t *)off_11F6DC = v20 | *v18;
            *v21 = 48;
            return link_get_connection_info(*(uint8_t *)(v1 + 107), v22, v1);
          }
        }
      }
    }
  }
  return result;
}
