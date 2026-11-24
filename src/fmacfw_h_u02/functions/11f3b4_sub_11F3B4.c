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


extern uint32_t dword_11F570;
extern uint32_t off_11F550;
extern uint32_t off_11F554;
extern uint32_t off_11F55C;
extern uint32_t off_11F560;
extern uint32_t off_11F564;
extern uint32_t off_11F568;
extern uint32_t off_11F56C;
extern uint32_t off_11F574;
extern uint32_t off_11F578;
extern uint32_t off_11F57C;
extern uint32_t off_11F584;
extern uint32_t off_11F588;
extern uint32_t off_11F590;
extern uint32_t off_11F594;
extern uint32_t off_11F598;
extern uint32_t off_11F59C;
extern uint32_t off_11F5A0;

// is_tx_engine_busy @ 0x11f3b4, size 412 bytes
int  is_tx_engine_busy(int result)
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
    result = bt_get_conn_ptr(result);
  if ( *(uint32_t *)(v1 + 72) )
    result = radio_disable_check(v1);
  if ( (*(uint32_t *)(v1 + 4) & 1) != 0 )
  {
    if ( (*(uint32_t *)off_11F550 & 0x2000000) != 0 || (result = *(uint32_t *)off_11F550 << 6, *((uint8_t *)off_11F554 + 36)) )
    {
      result = check_feature_flag(2, "M,%d\r\n", *(uint8_t *)(v1 + 128));
      v2 = (int *)off_11F55C;
      v3 = *((uint8_t *)off_11F55C + 1);
      *(uint32_t *)(v1 + 4) &= ~1u;
      *v2 = v3 > 1;
      if ( BYTE2(((uint32_t *)(uintptr_t)off_11F560)[47]) )
      {
        if ( **(uint8_t **)off_11F564 == 2 )
        {
          result = critical_section_enter_alt();
          v4 = off_11F568;
          *(uint32_t *)off_11F568 &= ~1u;
          *v4 &= ~0x80u;
          if ( *(uint8_t *)(v1 + 128) > 9u )
          {
            v5 = off_11F56C;
            v6 = dword_11F570;
            *(uint32_t *)off_11F550 &= ~4u;
            if ( (*v5 & v6) == 0 )
              process_event();
            if ( *(uint32_t *)off_11F574 << 28 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_11F578 = 1;
              }
              v7 = (int *)off_11F57C;
              v8 = off_11F574;
              ++*(uint32_t *)off_11F57C;
              *v8 = 0;
              v9 = (*(volatile uint32_t *)0x40501010u);
              while ( *v8 << 28 )
              {
                v10 = (*(volatile uint32_t *)0x40501010u) - v9;
                if ( v10 > 0x7530 )
                  check_feature_flag(2, aIdleErr, 30000);
              }
              v11 = (*(volatile uint32_t *)0x40501010u);
              if ( (*(uint32_t *)off_11F584 & *(uint32_t *)off_11F588 & 4) == 0 )
              {
                v12 = off_11F584;
                v13 = off_11F588;
                do
                {
                  v14 = (*(volatile uint32_t *)0x40501010u) - v11;
                  v15 = *v12 & *v13;
                  if ( v14 > 0x7530 )
                    check_feature_flag(2, aIdleIntErr);
                }
                while ( (v15 & 4) == 0 );
              }
              *(uint32_t *)off_11F590 = 4;
              if ( *v7 )
              {
                v16 = *v7 - 1;
                v17 = *(uint32_t *)off_11F578;
                *v7 = v16;
                if ( !v16 )
                {
                  if ( v17 )
                    __enable_irq();
                }
              }
            }
            v18 = off_11F598;
            v19 = **(uint16_t **)off_11F594;
            v20 = *((uint32_t *)off_11F598 + 1) | 0x200;
            *((uint32_t *)off_11F598 + 1) = v20;
            if ( v19 < 0 )
            {
              if ( *(uint32_t *)off_11F574 << 28 )
              {
                mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
                v20 = v18[1];
              }
            }
            v21 = off_11F574;
            v22 = off_11F5A0;
            *(uint32_t *)off_11F59C = v20 | *v18;
            *v21 = 48;
            return get_bt_device_state(*(uint8_t *)(v1 + 107), v22, v1);
          }
        }
      }
    }
  }
  return result;
}
