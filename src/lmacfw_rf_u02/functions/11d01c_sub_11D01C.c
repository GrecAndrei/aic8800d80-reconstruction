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


extern uint32_t off_11D094;
extern uint32_t off_11D098;
extern uint32_t off_11D0A0;
extern uint32_t off_11D0A4;
extern uint32_t off_11D0A8;
extern uint32_t off_11D0AC;

// rf_cal_trim_check @ 0x11d01c, size 118 bytes
uint32_t *rf_cal_trim_check()
{
  uint32_t *v0; // r2
  volatile unsigned int v1; // r3
  int v2; // r4
  uint32_t *v3; // r0
  uint32_t *v4; // r5
  int v5; // r1
  uint32_t *result; // r0
  int *v7; // r3
  int v8; // r3

  if ( **(uint16_t **)off_11D094 < 0 && !(*(uint32_t *)off_11D0AC << 28) )
    return (uint32_t *)ke_int_lock_1((int)aNxmacCurrentSt_0, (int)aHalMachwIdleRe, 213);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11D098 = 1;
  }
  v0 = off_11D0A0;
  v1 = REG_4032_0120;
  v2 = *(uint32_t *)off_11D0A0;
  v3 = off_11D0A4;
  v4 = off_11D0A8;
  v5 = *(uint32_t *)off_11D0A0 + 1;
  *(uint32_t *)off_11D0A0 = v5;
  *v3 = v1 + 25000;
  result = v3 + 8146;
  *v4 = 128;
  *result |= 0x80u;
  *(v4 - 8212) = 0;
  if ( v5 )
  {
    v7 = (int *)off_11D098;
    *v0 = v2;
    v8 = *v7;
    if ( !v2 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}
