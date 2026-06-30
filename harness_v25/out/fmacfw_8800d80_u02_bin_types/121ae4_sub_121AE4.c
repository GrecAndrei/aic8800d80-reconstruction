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

extern uint32_t off_121BCC;
extern uint32_t dword_121C00;
extern uint32_t dword_121BFC;
extern uint32_t dword_121BD0;
extern uint32_t off_121BD4;
extern uint32_t off_121C04;
extern uint32_t off_121BD8;
extern uint32_t off_121BDC;
extern uint32_t dword_121BF8;
extern uint32_t off_121BE4;
extern uint32_t off_121BE8;
extern uint32_t off_121BE0;
extern uint32_t off_121BEC;
extern uint32_t off_121BF0;
extern uint32_t off_121BF4;

// sub_121AE4 @ 0x121ae4, size 230 bytes
// Doc: sub_1221AE4 [util]: Init/lookup routine reading global pointer and signed halfword state
// sub_1221AE4 [util]: Init/lookup routine reading global pointer and signed halfword state
int sub_121AE4()
{
  int *v0; // r8
  int *v1; // r4
  uint32_t *v2; // r5
  int v3; // r3
  int v4; // r7
  int v5; // r9
  uint32_t *v6; // r0
  uint32_t *v7; // r1
  int v8; // r4
  int v9; // r3
  int result; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r2

  if ( **(int16_t **)off_121BCC < 0 && msg_get_value(0) == 4 )
    sub_12F46C(dword_121C00, dword_121BFC, 1799);
  feature_guard_check(4, dword_121BD0);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_121BD4 = 1;
  }
  v0 = (int *)off_121C04;
  v1 = (int *)off_121BD8;
  v2 = off_121BDC;
  ++*(uint32_t *)off_121C04;
  v3 = *v1;
  *v1 = 0;
  v4 = v2[4];
  v5 = v3 & 0xF;
  while ( *v1 << 28 )
  {
    sub_1179F4();
    if ( (unsigned int)(v2[4] - v4) > 0x7530 )
      feature_guard_check(4, dword_121BF8);
  }
  v6 = off_121BE4;
  v7 = off_121BE8;
  v8 = *(uint32_t *)off_121BE4;
  *((uint32_t *)off_121BE0 + 1) &= ~4u;
  if ( v5 && (*v7 & v8 & 4) == 0 )
  {
    while ( (*v7 & *v6 & 4) == 0 )
      ;
  }
  v9 = *((uint8_t *)off_121BEC + 90);
  *(uint32_t *)off_121BF0 = 4;
  if ( v9 )
    sub_117A24();
  result = sub_12CD34(0);
  v11 = *v0;
  *((uint16_t *)off_121BF4 + 9) = 0;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(uint32_t *)off_121BD4;
    *v0 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}

