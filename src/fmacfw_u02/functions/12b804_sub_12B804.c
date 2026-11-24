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


extern uint32_t off_12B87C;
extern uint32_t off_12B880;
extern uint32_t off_12B888;
extern uint32_t off_12B88C;
extern uint32_t off_12B890;
extern uint32_t off_12B894;
extern uint32_t off_12B898;
extern uint32_t off_12B89C;

// read_cal_trim @ 0x12b804, size 120 bytes
int read_cal_trim()
{
  uint32_t *v0; // r1
  volatile unsigned int v1; // r3
  int v2; // r6
  uint32_t *v3; // r4
  uint32_t *v4; // r2
  uint32_t *v5; // r5
  uint32_t *v6; // r7
  int result; // r0
  uint32_t *v8; // r4
  int v9; // r3
  int *v10; // r3
  int v11; // r3

  if ( **(uint16_t **)off_12B87C < 0 && !(*(uint32_t *)off_12B898 << 28) )
    return bad_func_0x12f408((int)aNxmacCurrentSt_0, (int)aHalMachwIdleRe, 213);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12B880 = 1;
  }
  v0 = off_12B888;
  v1 = REG_4032_0120;
  v2 = *(uint32_t *)off_12B888;
  v3 = off_12B88C;
  v4 = off_12B890;
  v5 = off_12B894;
  v6 = off_12B898;
  result = *(uint32_t *)off_12B888 + 1;
  *(uint32_t *)off_12B888 = result;
  *v3 = v1 + 25000;
  v8 = off_12B89C;
  *v4 = 128;
  v9 = v8[1] | 4;
  *v5 |= 0x80u;
  v8[1] = v9;
  *v6 = 0;
  if ( result )
  {
    v10 = (int *)off_12B880;
    *v0 = v2;
    v11 = *v10;
    if ( !v2 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}
