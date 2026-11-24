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


extern uint32_t dword_116300;
extern uint32_t dword_11630C;
extern uint32_t off_1162F4;
extern uint32_t off_1162F8;
extern uint32_t off_1162FC;
extern uint32_t off_116304;
extern uint32_t off_116308;
extern uint32_t off_116318;
extern uint32_t off_116320;
extern uint32_t off_116324;

// wlan_hw_init @ 0x1160fc, size 502 bytes
uint32_t * wlan_hw_init(unsigned int a1, int a2)
{
  uint8_t **v2; // r11
  uint32_t *v5; // r4
  int *v6; // r5
  int v8; // r3
  int v9; // r2
  int v10; // r1
  uint32_t *v11; // r8
  uint32_t *v12; // r0
  int v13; // r12
  uint32_t *v14; // r9
  uint16_t *v15; // lr
  unsigned int v16; // r1
  int v17; // r2
  int *v18; // r3
  int v19; // r1
  int v20; // r3
  uint8_t *v21; // r3
  int *v22; // r8
  int v23; // r2
  int v24; // r3
  int v25; // r3
  int v26; // r2
  uint16_t v27; // [sp+4h] [bp-10h]
  int v28; // [sp+8h] [bp-Ch] BYREF
  int v29; // [sp+Ch] [bp-8h]

  v2 = (uint8_t **)off_116318;
  while ( 1 )
  {
    v5 = list_pop_front(a2);
    if ( !v5 )
      break;
    while ( 1 )
    {
      v6 = (int *)v5[8];
      if ( v5[6] )
      {
        *v6 = 2080374784;
      }
      else if ( *v6 >= 0 )
      {
        *v6 = 0x40000000;
      }
      if ( *((uint16_t *)v5 + 2) )
        break;
      log_and_disable_irq(v5);
      v5 = list_pop_front(a2);
      if ( !v5 )
        return pool_alloc_init();
    }
    v8 = *v6;
    v9 = v5[10];
    *v6 |= 0x800000u;
    if ( v9 < 0 )
    {
      v10 = **v2;
      switch ( v10 )
      {
        case 2:
          v11 = disable_interrupts();
          if ( v11 )
          {
            if ( *(uint32_t *)off_1162F8 )
            {
              v12 = list_pop_front(off_1162F8);
              *(uint8_t *)v11 = 8;
              *((uint8_t *)v11 + 1) = 0;
              *((uint16_t *)v11 + 1) = 18;
              v13 = v5[10] & 0x3FFFFFFF;
              v14 = v12;
              v28 = *v6 & 0xF;
              v29 = v13;
              memcpy_large((char *)v11 + 4, (char *)&v28, 8u);
              v15 = (uint16_t *)off_116320;
              v16 = *(uint16_t *)off_116320;
              if ( v16 > 0x186 )
              {
                v17 = 0;
                LOWORD(v16) = 0;
                v27 = 1;
              }
              else
              {
                v27 = v16 + 1;
                v17 = 8 * v16;
              }
              v18 = (int *)off_1162FC;
              *((uint16_t *)v14 + 6) = v16;
              v19 = *v18;
              v20 = dword_116300;
              *(uint32_t *)(v19 + v17 + 4) = v11;
              *(uint32_t *)(v19 + v17) = v20 & *(uint32_t *)(v19 + v17) | 0x400000C;
              v21 = off_116304;
              *v15 = v27;
              ++v21[3074];
              v14[1] = v19 + v17;
              *((uint8_t *)v14 + 14) = 1;
              *v14 = 0;
              v14[2] = 12;
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_116308 = 1;
              }
              v22 = (int *)off_116324;
              v23 = *((uint16_t *)v5 + 11);
              v24 = *v6 & 0xF;
              ++*(uint32_t *)off_116324;
              dispatch_event_handler_1("cfms: %x, sn=%d, st=%d\r\n", v5, v23, v24);
              check_kernel_state(dword_11630C, v14);
              process_event();
              if ( *v22 )
              {
                v25 = *v22 - 1;
                v26 = *(uint32_t *)off_116308;
                *v22 = v25;
                if ( !v25 )
                {
                  if ( v26 )
                    __enable_irq();
                }
              }
            }
            else
            {
              log_printf(aErrTxlCfmNoBuf);
            }
          }
          else
          {
            log_printf(aErrNoMsgPkt);
          }
          break;
        case 1:
          v28 = v8 & 0xF;
          v29 = v9 & 0x3FFFFFFF;
          ke_alloc_node(18, (char *)&v28, 8u, v28);
          dispatch_event_handler_1("cfms: %x, sn=%d, st=%d\r\n", v5, *((uint16_t *)v5 + 11), *v6 & 0xF);
          break;
        case 3:
          **(uint32_t **)off_1162F4 = v8 & 0xF;
          enable_uart();
          break;
      }
    }
    deferred_cb_clear((int)v5);
    ke_int_lock_mode(a1, (int)v5);
  }
  return pool_alloc_init();
}
