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

extern uint32_t off_10F0AC;
extern uint32_t off_10F0B0;
extern uint32_t off_10F0B4;

// sub_10F064 @ 0x10f064, size 70 bytes
// Doc: rf_reg_write_core [rf]: Core routine for writing an RF register
// rf_reg_write_core [rf]: Core routine for writing an RF register
int  sub_10F064(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  uint32_t *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10F0AC = 1;
  }
  v4 = (int *)off_10F0B0;
  ++*(uint32_t *)off_10F0B0;
  if ( a4 )
  {
    v5 = off_10F0B4;
    while ( !*(uint32_t *)off_10F0B4 )
      ;
    result = rf_reg_write_cb();
    *v5 = 1;
  }
  else
  {
    result = rf_reg_write_cb();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(uint32_t *)off_10F0AC;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

