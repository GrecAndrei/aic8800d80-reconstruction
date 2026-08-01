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

extern uint32_t dword_12FFF8;
extern uint32_t dword_130000;
extern uint32_t dword_130004;
extern uint32_t dword_130008;
extern uint32_t dword_13001C;
extern uint32_t dword_13000C;
extern uint32_t dword_13002C;
extern uint32_t dword_130024;
extern uint32_t dword_130020;
extern uint32_t dword_130028;
extern uint32_t dword_130010;
extern uint32_t off_130014;
extern uint32_t off_130018;
extern uint32_t dword_12FFFC;

// lock_with_timeout @ 0x12fed8, size 288 bytes
int  lock_with_timeout(unsigned int a1)
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

  v1 = lock_global_mutex(a1, (uint8_t *)dword_12FFF8, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( memcpy_aligned(dword_130000) != v1 || strcmp(dword_130000, dword_12FFF8) )
      {
        v4 = list_pop(dword_130004);
        v5 = v4;
        if ( v4 )
        {
          memcpy(v4 + 1, dword_12FFF8);
          wlan_ioctl_handler_1(dword_130008, v5);
        }
        else
        {
          radio_tx_write_string((uint8_t *)dword_13001C);
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
        debug_printf(dword_13000C, CPSR, v7, v8, v9, v10, v23);
        if ( v9 )
        {
          v13 = dword_13002C;
          v14 = dword_130024;
          v15 = v9 & 0xFFFFFFF0;
          radio_tx_write_string((uint8_t *)dword_130020);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              debug_printf(v13, v15);
            v17 = *(uint32_t *)v15;
            v15 += 4;
            debug_printf(v14, v17);
          }
          while ( v16 != v15 );
        }
        if ( v8 )
        {
          v18 = dword_13002C;
          v19 = dword_130024;
          v20 = v8 & 0xFFFFFFF0;
          radio_tx_write_string((uint8_t *)dword_130028);
          v21 = v20 + 256;
          do
          {
            if ( !(v20 << 28) )
              debug_printf(v18, v20);
            v22 = *(uint32_t *)v20;
            v20 += 4;
            debug_printf(v19, v22);
          }
          while ( v21 != v20 );
        }
        radio_tx_write_string((uint8_t *)dword_130010);
        v11 = off_130014;
        v12 = *(uint8_t *)off_130014;
        if ( *(uint8_t *)off_130014 )
        {
          *((uint8_t *)off_130018 + 783) = -4;
          v2 = 0;
          *v11 = 0;
        }
        else
        {
          *((uint8_t *)off_130018 + 783) = -12;
          v2 = v12;
          *v11 = 1;
        }
      }
    }
    else
    {
      radio_tx_write_string((uint8_t *)dword_12FFFC);
    }
    lock_global_mutex(0x30u, (uint8_t *)dword_12FFF8, dword_12FFFC);
  }
  return v2;
}

