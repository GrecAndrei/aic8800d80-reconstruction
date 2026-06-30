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

extern uint32_t off_1340A4;
extern uint32_t off_1340A8;
extern uint32_t off_1340AC;
extern uint32_t dword_1340B0;

// sub_134008 @ 0x134008, size 154 bytes
// Doc: sub_1234008 [unknown]: Helper routine processing byte fields from r1 struct
// sub_1234008 [unknown]: Helper routine processing byte fields from r1 struct
int  sub_134008(int a1, uint16_t *a2)
{
  int v3; // r6
  int *v4; // r4
  int v5; // r0
  int v6; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2

  v3 = *((uint8_t *)a2 + 2);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1340A4 = 1;
  }
  v4 = (int *)off_1340A8;
  ++*(uint32_t *)off_1340A8;
  if ( msg_get_value(6u) || *((uint8_t *)off_1340AC + 14) && message_dispatch_n_d8(6155, 6) )
  {
    if ( *v4 )
    {
      v10 = *v4 - 1;
      v11 = *(uint32_t *)off_1340A4;
      *v4 = v10;
      if ( !v10 )
      {
        if ( v11 )
          __enable_irq();
      }
    }
    return 2;
  }
  else
  {
    if ( *v4 )
    {
      v8 = *v4 - 1;
      v9 = *(uint32_t *)off_1340A4;
      *v4 = v8;
      if ( !v8 )
      {
        if ( v9 )
          __enable_irq();
      }
    }
    v5 = dword_1340B0 + 1320 * v3;
    v6 = *(uint8_t *)(v5 + 106);
    if ( !*(uint8_t *)(v5 + 106) && *(uint8_t *)(v5 + 108) )
    {
      sub_134FA8(v5, *a2, 1);
      return v6;
    }
    else
    {
      message_dispatch_n84(6148, 13, 6);
      return 0;
    }
  }
}

