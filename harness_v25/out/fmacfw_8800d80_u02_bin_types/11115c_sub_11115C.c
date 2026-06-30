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

extern uint32_t off_11123C;
extern uint32_t off_111240;
extern uint32_t off_111244;
extern uint32_t off_111260;
extern uint32_t off_111264;
extern uint32_t dword_111268;
extern uint32_t off_11126C;
extern uint32_t off_111248;
extern uint32_t off_11124C;
extern uint32_t dword_111250;
extern uint32_t off_111254;
extern uint32_t off_11125C;
extern uint32_t off_111258;

// sub_11115C @ 0x11115c, size 222 bytes
int  sub_11115C(int a1)
{
  int *v2; // r5
  uint8_t *v3; // r3
  int v4; // r1
  uint32_t *v5; // r2
  int result; // r0
  uint32_t *v7; // r2
  uint32_t *v8; // r6
  int v9; // r1
  int v10; // r3
  uint8_t *v11; // r6
  uint8_t *v12; // r7
  int v13; // r3
  int v14; // r6

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11123C = 1;
  }
  v2 = (int *)off_111240;
  v3 = *(uint8_t **)off_111244;
  v4 = *(uint32_t *)off_111240 + 1;
  *(uint32_t *)off_111240 = v4;
  if ( *v3 == 1 )
  {
    v11 = off_111260;
    v12 = off_111264;
    if ( *(uint8_t *)off_111260 )
    {
      v14 = *((uint8_t *)off_111264 + 374);
      if ( v14 != 1 )
        goto LABEL_4;
      if ( rf_msg_handler_n22e(dword_111268) )
        goto LABEL_18;
      if ( v12[369] )
        sub_10DD14(v14);
      else
        rf_mem_read_n47e(v14);
    }
    else
    {
      if ( *((uint8_t *)off_111264 + 369) )
        sub_10DD14(1);
      else
        rf_mem_read_n47e(1);
      v13 = (uint8_t)v12[374];
      *v11 = 1;
      if ( v13 != 1 )
        goto LABEL_18;
    }
    timestamp_update(dword_111268, *((uint32_t *)off_11126C + 4) + 10000);
LABEL_18:
    v4 = *v2;
  }
LABEL_4:
  v5 = off_111248;
  *(uint32_t *)off_111248 = 64;
  while ( (*v5 & 0x80) != 0 )
    ;
  if ( *(uint32_t *)off_11124C )
  {
    result = dword_111250;
    v7 = off_111254;
    *(uint32_t *)(*(uint32_t *)(dword_111250 + 6164) + 4) = a1;
  }
  else
  {
    v7 = off_111254;
    *(uint32_t *)off_11124C = a1;
    result = dword_111250;
  }
  ++*v7;
  v8 = off_11125C;
  *(uint8_t *)off_111258 |= 2u;
  *v8 = 64;
  *(uint32_t *)(result + 6164) = a1;
  if ( v4 )
  {
    v9 = v4 - 1;
    v10 = *(uint32_t *)off_11123C;
    *v2 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}

