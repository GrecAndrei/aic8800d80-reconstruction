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

extern uint32_t off_12C730;
extern uint32_t dword_12C71C;
extern uint32_t dword_12C724;
extern uint32_t dword_12C720;
extern uint32_t dword_12C728;
extern uint32_t off_12C704;
extern uint32_t off_12C734;
extern uint32_t off_12C738;
extern uint32_t dword_12C70C;
extern uint32_t dword_12C708;
extern uint32_t dword_12C72C;
extern uint32_t dword_12C714;
extern uint32_t off_12C710;
extern uint32_t dword_12C718;

// sub_12C5E4 @ 0x12c5e4, size 288 bytes
int  sub_12C5E4(int a1, int a2, unsigned int a3)
{
  int16_t **v3; // r11
  int *v7; // r8
  uint32_t *v8; // r10
  int v9; // r6
  int v10; // r4
  int v11; // r2
  int v12; // r0
  unsigned int v13; // r5
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // r0

  v3 = (int16_t **)off_12C730;
  if ( **(int16_t **)off_12C730 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_12C71C )
        sub_12F46C(dword_12C724, dword_12C720, 148);
    }
    else
    {
      sub_12F46C(dword_12C728, dword_12C720, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12C704 = 1;
  }
  v7 = (int *)off_12C734;
  v8 = off_12C738;
  v9 = *((uint32_t *)off_12C738 + 5);
  ++*(uint32_t *)off_12C734;
  if ( v9 )
    v9 = *(uint16_t *)(v9 + 4) == a1 && *(uint16_t *)(v9 + 6) == a2;
  v10 = sub_12CA3C(dword_12C70C, dword_12C708, a2 | (a1 << 16));
  if ( !v10 )
  {
    v17 = sub_12CAE4(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      sub_12F46C(dword_12C72C, dword_12C720, 165);
    *(uint16_t *)(v10 + 4) = a1;
    *(uint16_t *)(v10 + 6) = a2;
  }
  v11 = dword_12C714;
  v12 = dword_12C70C;
  v13 = a3 + *((uint32_t *)off_12C710 + 4);
  *(uint32_t *)(v10 + 8) = v13;
  result = sub_12D380(v12, v10, v11);
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = sub_124D3C(dword_12C718, *(uint32_t *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(uint32_t *)off_12C704, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((uint32_t *)off_12C710 + 4)) < 0 )
      return sub_12D104(0x10000000);
  }
  else if ( (int)(v13 - *((uint32_t *)off_12C710 + 4)) < 0 )
  {
    return sub_12D104(0x10000000);
  }
  return result;
}

