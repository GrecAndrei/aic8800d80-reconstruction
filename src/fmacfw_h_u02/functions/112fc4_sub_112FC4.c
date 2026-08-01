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

extern uint32_t off_11312C;
extern uint32_t off_113130;
extern uint32_t off_113134;
extern uint32_t dword_113144;
extern uint32_t dword_113148;
extern uint32_t dword_11314C;
extern uint32_t off_113138;
extern uint32_t dword_113158;
extern uint32_t dword_11315C;
extern uint32_t off_113168;
extern uint32_t dword_113164;
extern uint32_t dword_113140;
extern uint32_t dword_11313C;
extern uint32_t dword_113160;
extern uint32_t dword_113154;
extern uint32_t off_113150;

// rf_read_status @ 0x112fc4, size 360 bytes
int  rf_read_status(uint8_t *a1, unsigned int a2, int a3)
{
  uint16_t *v3; // r7
  uint8_t *v4; // r6
  uint8_t *v5; // r4
  char v6; // r2
  uint8_t *v7; // r4
  int v9; // r8
  int v10; // r6
  uint8_t *v11; // r8
  char v12; // r5
  int v13; // r0
  unsigned int v14; // r3
  char *v15; // r3
  int v17; // r0

  v3 = (uint16_t *)off_11312C;
  v4 = (uint8_t *)off_113130;
  v5 = off_113134;
  ++*(uint16_t *)off_11312C;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  v7 = a1;
  if ( *v4 != 2 )
  {
    debug_printf(dword_113144, *v3, *v4);
    check_global_value(dword_113148, v7, a2, *v4);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    debug_printf(dword_11314C, *v3, a2);
  }
  else
  {
    v9 = a1[2];
    v10 = *a1 | (a1[1] << 8) & 0xF00;
    if ( *(uint8_t *)off_113138 )
      a1 = (uint8_t *)check_feature_flag(512, dword_113158);
    if ( v9 == 1 )
    {
      if ( a2 == v10 || v10 + 1 == a2 )
      {
        ((void (*)(void))util_init_buffer)();
        adv_parse_report(v7 + 4);
        irq_disable_global_2(512);
        return 1;
      }
      debug_printf(dword_11315C, *v3, v10, a2);
    }
    else if ( v9 == 17 )
    {
      v11 = off_113168;
      if ( *((uint8_t *)off_113168 + 2433) >= (unsigned int)*((uint8_t *)off_113168 + 2434) )
      {
        debug_printf(dword_113164);
      }
      else
      {
        if ( v10 + 4 == a2 || a2 == v10 + 5 )
        {
          util_init_buffer(a1);
          v12 = v11[2433];
          v13 = dword_113140;
          v14 = (uint8_t)v11[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)dword_11313C
                               * (unsigned uint64_t)((unsigned int)(uint8_t)v11[2432] + 1)) >> 32) >> 5);
          v11[2432] = v14;
          v15 = &v11[20 * v14];
          *((uint32_t *)v15 + 409) = v7 + 4;
          *((uint32_t *)v15 + 412) = v10;
          v11[2433] = v12 + 1;
          wlan_ioctl_handler_1(v13);
          irq_disable_global_2(0x400000);
          return 1;
        }
        debug_printf(dword_113160, *v3, v10, a2);
      }
    }
    else
    {
      debug_printf(dword_113154, *v3, v9, v10, a2);
    }
  }
  v17 = wait_for_state(&v7[-*(uint32_t *)off_113150]);
  util_init_buffer(v17);
  return 1;
}

