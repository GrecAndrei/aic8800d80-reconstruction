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

extern uint32_t off_124E10;
extern uint32_t off_124E14;
extern uint32_t off_124E18;
extern uint32_t dword_124E24;
extern uint32_t off_124E28;
extern uint32_t dword_124E30;
extern uint32_t dword_124E2C;
extern uint32_t off_124E1C;
extern uint32_t dword_124E20;

// sub_124D3C @ 0x124d3c, size 212 bytes
int  sub_124D3C(int a1, int a2)
{
  int *v4; // r7
  uint32_t *v5; // r2
  int *v6; // r6
  int v7; // r2
  int result; // r0
  int v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r2
  uint32_t *v13; // r2
  int v14; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_124E10 = 1;
  }
  v4 = (int *)off_124E14;
  v5 = off_124E18;
  ++*(uint32_t *)off_124E14;
  if ( a2 - v5[4] < 0 )
  {
    sub_12EA88(dword_124E24, *(uint32_t *)(a1 + 4), a2);
    if ( **(int16_t **)off_124E28 < 0 )
      sub_12F46C(dword_124E30, dword_124E2C, 131);
  }
  v6 = (int *)off_124E1C;
  if ( a1 == *(uint32_t *)off_124E1C )
  {
    sub_12D2D0(off_124E1C);
    v12 = dword_124E20;
    *(uint32_t *)(a1 + 12) = a2;
    result = sub_12D380(v6, a1, v12);
    v9 = *v6;
    if ( !*v6 )
    {
      *((uint32_t *)off_124E18 + 2) = 1024;
      goto LABEL_6;
    }
    goto LABEL_14;
  }
  sub_12D2E8(off_124E1C, a1);
  v7 = dword_124E20;
  *(uint32_t *)(a1 + 12) = a2;
  result = sub_12D380(v6, a1, v7);
  v9 = *v6;
  if ( a1 == *v6 )
  {
LABEL_14:
    v13 = off_124E18;
    v14 = *(uint32_t *)(v9 + 12);
    result = 0x40000;
    *((uint32_t *)off_124E18 + 2) = 0x40000;
    v13[12] = v14;
    v13[2] = 4;
  }
LABEL_6:
  if ( *v4 && (v10 = *v4 - 1, v11 = *(uint32_t *)off_124E10, (*v4 = v10) == 0) && v11 )
  {
    __enable_irq();
    if ( a2 - *((uint32_t *)off_124E18 + 4) < 0 )
      return sub_12D104(0x20000000);
  }
  else if ( a2 - *((uint32_t *)off_124E18 + 4) < 0 )
  {
    return sub_12D104(0x20000000);
  }
  return result;
}

