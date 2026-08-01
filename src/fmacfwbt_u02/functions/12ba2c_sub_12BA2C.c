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

extern uint32_t off_12BAA4;
extern uint32_t off_12BAC0;
extern uint32_t dword_12BACC;
extern uint32_t dword_12BAC8;
extern uint32_t off_12BAA8;
extern uint32_t off_12BAB0;
extern uint32_t off_12BAB4;
extern uint32_t off_12BAB8;
extern uint32_t off_12BABC;
extern uint32_t off_12BAAC;
extern uint32_t off_12BAC4;

// rf_check_clk_state @ 0x12ba2c, size 120 bytes
int rf_check_clk_state()
{
  uint32_t *v0; // r1
  int v1; // r6
  int *v2; // r4
  uint32_t *v3; // r2
  uint32_t *v4; // r5
  uint32_t *v5; // r7
  int v6; // r3
  int result; // r0
  uint32_t *v8; // r4
  int v9; // r3
  int *v10; // r3
  int v11; // r3

  if ( **(int16_t **)off_12BAA4 < 0 && !(*(uint32_t *)off_12BAC0 << 28) )
    return ke_int_lock(dword_12BACC, dword_12BAC8, 213, *(uint32_t *)off_12BAC0);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12BAA8 = 1;
  }
  v0 = off_12BAB0;
  v1 = *(uint32_t *)off_12BAB0;
  v2 = (int *)off_12BAB4;
  v3 = off_12BAB8;
  v4 = off_12BABC;
  v5 = off_12BAC0;
  v6 = *(uint32_t *)off_12BAAC + 25000;
  result = *(uint32_t *)off_12BAB0 + 1;
  *(uint32_t *)off_12BAB0 = result;
  *v2 = v6;
  v8 = off_12BAC4;
  *v3 = 128;
  v9 = v8[1] | 4;
  *v4 |= 0x80u;
  v8[1] = v9;
  *v5 = 0;
  if ( result )
  {
    v10 = (int *)off_12BAA8;
    *v0 = v1;
    v11 = *v10;
    if ( !v1 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

