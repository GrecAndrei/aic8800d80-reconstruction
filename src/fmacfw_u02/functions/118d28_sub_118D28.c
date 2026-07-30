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

extern uint32_t off_118DC0;
extern uint32_t off_118DB0;
extern uint32_t dword_118DB4;
extern uint32_t off_118DB8;
extern uint32_t dword_118DBC;

// sub_118D28 @ 0x118d28, size 134 bytes
uint32_t *sub_118D28()
{
  int *v0; // r8
  int *v1; // r7
  int v2; // r6
  uint32_t *v3; // r5
  uint32_t *result; // r0
  uint32_t *v5; // r4
  int v6; // r3
  int v7; // r2
  void ( *v8)(uint32_t, uint32_t); // r2

  clear_flags(0x20000);
  v0 = (int *)off_118DC0;
  v1 = (int *)off_118DB0;
  v2 = dword_118DB4;
  v3 = off_118DB8;
  while ( 1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v1 = 1;
    }
    ++*v0;
    result = (uint32_t *)rf_bus_mark_n100_d2d0(v2);
    v5 = result;
    if ( *v0 )
    {
      v6 = *v0 - 1;
      v7 = *v1;
      *v0 = v6;
      if ( !v6 )
      {
        if ( v7 )
          __enable_irq();
      }
    }
    if ( !result )
      break;
    v8 = (void ( *)(uint32_t, uint32_t))result[22];
    --v3[126];
    if ( v8 && (v8(result[23], *(uint32_t *)(result[19] + 72)), *((uint8_t *)v5 + 98)) )
    {
      *((uint8_t *)v5 + 98) = 0;
    }
    else if ( !*((uint8_t *)v5 + 96) )
    {
      list_push_tail(dword_118DBC);
    }
  }
  return result;
}

