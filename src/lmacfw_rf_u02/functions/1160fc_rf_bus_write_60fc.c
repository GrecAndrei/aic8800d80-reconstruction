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

extern uint32_t off_116318;
extern uint32_t dword_11631C;
extern uint32_t off_1162F8;
extern uint32_t off_116320;
extern uint32_t off_1162FC;
extern uint32_t dword_116300;
extern uint32_t off_116304;
extern uint32_t off_116308;
extern uint32_t off_116324;
extern uint32_t dword_11630C;
extern uint32_t dword_116310;
extern uint32_t dword_116314;
extern uint32_t off_1162F4;

// wlan_hw_init @ 0x1160fc, size 502 bytes
// Doc: wlan_hw_init [rf]: Writes value to RF bus register
// wlan_hw_init [rf]: Writes value to RF bus register
int  wlan_hw_init(int a1, int a2)
{
  uint8_t **v2; // r11
  int v3; // r10
  int v6; // r1
  int v7; // r2
  int v8; // r4
  int *v9; // r5
  int v11; // r3
  int v12; // r2
  int v13; // r2
  int v14; // r1
  int v15; // r8
  int v16; // r0
  int v17; // r12
  int v18; // r9
  int16_t *v19; // lr
  unsigned int v20; // r1
  int v21; // r2
  int *v22; // r3
  int v23; // r1
  int v24; // r3
  uint8_t *v25; // r3
  int *v26; // r8
  int v27; // r0
  int v28; // r1
  int v29; // r3
  int v30; // r2
  int16_t v31; // [sp+4h] [bp-10h]
  int v32; // [sp+8h] [bp-Ch] BYREF
  int v33; // [sp+Ch] [bp-8h]

  v2 = (uint8_t **)off_116318;
  v3 = dword_11631C;
  while ( 1 )
  {
    v8 = list_pop_front(a2);
    if ( !v8 )
      break;
    while ( 1 )
    {
      v9 = *(int **)(v8 + 32);
      if ( *(uint32_t *)(v8 + 24) )
      {
        *v9 = 2080374784;
      }
      else if ( *v9 >= 0 )
      {
        *v9 = 0x40000000;
      }
      if ( *(uint16_t *)(v8 + 4) )
        break;
      log_and_disable_irq(v8, v6, v7);
      v8 = list_pop_front(a2);
      if ( !v8 )
        return pool_alloc_init();
    }
    v11 = *v9;
    v12 = *(uint32_t *)(v8 + 40);
    *v9 |= 0x800000u;
    if ( v12 < 0 )
    {
      v14 = **v2;
      switch ( v14 )
      {
        case 2:
          v15 = disable_interrupts();
          if ( v15 )
          {
            if ( *(uint32_t *)off_1162F8 )
            {
              v16 = list_pop_front(off_1162F8);
              *(uint8_t *)v15 = 8;
              *(uint8_t *)(v15 + 1) = 0;
              *(uint16_t *)(v15 + 2) = 18;
              v17 = *(uint32_t *)(v8 + 40) & 0x3FFFFFFF;
              v18 = v16;
              v32 = *v9 & 0xF;
              v33 = v17;
              memcpy_large(v15 + 4, &v32, 8);
              v19 = (int16_t *)off_116320;
              v20 = *(uint16_t *)off_116320;
              if ( v20 > 0x186 )
              {
                v21 = 0;
                LOWORD(v20) = 0;
                v31 = 1;
              }
              else
              {
                v31 = v20 + 1;
                v21 = 8 * v20;
              }
              v22 = (int *)off_1162FC;
              *(uint16_t *)(v18 + 12) = v20;
              v23 = *v22;
              v24 = dword_116300;
              *(uint32_t *)(v23 + v21 + 4) = v15;
              *(uint32_t *)(v23 + v21) = v24 & *(uint32_t *)(v23 + v21) | 0x400000C;
              v25 = off_116304;
              *v19 = v31;
              ++v25[3074];
              *(uint32_t *)(v18 + 4) = v23 + v21;
              *(uint8_t *)(v18 + 14) = 1;
              *(uint32_t *)v18 = 0;
              *(uint32_t *)(v18 + 8) = 12;
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_116308 = 1;
              }
              v26 = (int *)off_116324;
              ++*(uint32_t *)off_116324;
              dispatch_event_handler(v3, v8);
              v27 = check_kernel_state(dword_11630C);
              process_event(v27, v28);
              if ( *v26 )
              {
                v29 = *v26 - 1;
                v30 = *(uint32_t *)off_116308;
                *v26 = v29;
                if ( !v29 )
                {
                  if ( v30 )
                    __enable_irq();
                }
              }
            }
            else
            {
              log_printf(dword_116310);
            }
          }
          else
          {
            log_printf(dword_116314);
          }
          break;
        case 1:
          v32 = v11 & 0xF;
          v33 = v12 & 0x3FFFFFFF;
          ke_alloc_node(18, (int)&v32, 8);
          dispatch_event_handler(v3, v8);
          break;
        case 3:
          **(uint32_t **)off_1162F4 = v11 & 0xF;
          enable_uart();
          break;
      }
    }
    deferred_cb_clear(v8);
    ke_int_lock_mode(a1, v8, v13);
  }
  return pool_alloc_init();
}

