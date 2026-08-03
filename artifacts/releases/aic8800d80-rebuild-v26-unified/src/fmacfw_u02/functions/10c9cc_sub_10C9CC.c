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

extern uint32_t off_10CAB8;
extern uint32_t off_10CAD0;
extern uint32_t dword_10CAD4;
extern uint32_t off_10CABC;
extern uint32_t off_10CAD8;
extern uint32_t off_10CADC;
extern uint32_t dword_10CAC4;
extern uint32_t off_10CAC0;
extern uint32_t dword_10CACC;
extern uint32_t off_10CAC8;

// sub_10C9CC @ 0x10c9cc, size 236 bytes
int  sub_10C9CC(char a1)
{
  int v1; // r5
  uint8_t *v2; // r11
  int v3; // r8
  int *v4; // r7
  uint32_t *v5; // r10
  unsigned int v6; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  int *v9; // r9
  int v10; // r0
  int v11; // r1
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r0
  int result; // r0

  clear_flags(2048);
  v1 = *(uint32_t *)off_10CAB8;
  if ( *(uint32_t *)(*(uint32_t *)off_10CAB8 + 636) )
  {
    v2 = (uint8_t *)off_10CAD0;
    v3 = dword_10CAD4;
    v4 = (int *)off_10CABC;
    v5 = off_10CAD8;
    while ( 1 )
    {
      v6 = v2[1621];
      v7 = v2[1622];
      if ( v6 >= v7 )
        break;
      v8 = v2[1620]
         + 1
         - 81 * ((unsigned int)(((unsigned int)v3 * (unsigned uint64_t)((unsigned int)v2[1620] + 1)) >> 32) >> 6);
      v2[1621] = v6 + 1;
      v2[1620] = v8;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      v9 = (int *)off_10CADC;
      ++*(uint32_t *)off_10CADC;
      while ( !*v5 )
        ;
      v10 = rf_bus_mark_n100_d2d0(v1 + 636);
      v11 = *v9;
      *v5 = 1;
      v12 = v10;
      if ( v11 )
      {
        v13 = v11 - 1;
        v14 = *v4;
        *v9 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
      v15 = dword_10CAC4;
      *(uint32_t *)&v2[20 * v8 + 4] = v12 + *(uint32_t *)off_10CAC0;
      list_push_tail(v15);
      if ( !*(uint32_t *)(v1 + 636) )
        goto LABEL_13;
    }
    sub_10DC24(dword_10CACC, v6, v7);
  }
LABEL_13:
  result = irq_nesting_or_d104(256);
  *(uint32_t *)off_10CAC8 = (1 << (a1 + 8)) & 0x1F00;
  return result;
}

