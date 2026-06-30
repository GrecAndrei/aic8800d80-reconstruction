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

extern uint32_t off_110F68;
extern uint32_t off_110F94;
extern uint32_t off_110F6C;
extern uint32_t off_110F84;
extern uint32_t off_110F88;
extern uint32_t dword_110F8C;
extern uint32_t off_110F90;
extern uint32_t off_110F70;
extern uint32_t off_110F74;
extern uint32_t off_110F78;
extern uint32_t off_110F7C;
extern uint32_t off_110F80;

// log_queue_push2 @ 0x110e78, size 238 bytes
// Doc: log_queue_push2 [util]: Push formatted log entry into debug queue
// log_queue_push2 [util]: Push formatted log entry into debug queue
int  log_queue_push2(int a1, int a2, int a3)
{
  int *v6; // r9
  uint8_t *v7; // r3
  int v8; // r5
  int result; // r0
  uint32_t *v10; // r4
  uint32_t *v11; // r3
  uint32_t *v12; // r1
  int v13; // r5
  int v14; // r3
  uint32_t *v15; // r2
  uint8_t *v16; // r4
  uint8_t *v17; // r5
  int v18; // r3
  uint8_t *v19; // r10
  int v20; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110F68 = 1;
  }
  v6 = (int *)off_110F94;
  v7 = *(uint8_t **)off_110F6C;
  v8 = *(uint32_t *)off_110F94 + 1;
  *(uint32_t *)off_110F94 = v8;
  result = *v7;
  if ( result == 1 )
  {
    v16 = off_110F84;
    if ( *(uint8_t *)off_110F84 )
    {
      v19 = off_110F88;
      v20 = *((uint8_t *)off_110F88 + 374);
      if ( v20 != 1 )
        goto LABEL_4;
      result = timestamp_list_contains_51a0(dword_110F8C);
      if ( result )
        goto LABEL_18;
      if ( v19[369] )
        sub_10DB6C(v20);
      else
        irq_enable(v20);
    }
    else
    {
      v17 = (uint8_t *)off_110F88;
      if ( *((uint8_t *)off_110F88 + 369) )
        result = sub_10DB6C(1);
      else
        result = irq_enable(1);
      v18 = v17[374];
      *v16 = 1;
      if ( v18 != 1 )
        goto LABEL_18;
    }
    result = timestamp_update_4f60(dword_110F8C, *((uint32_t *)off_110F90 + 4) + 10000);
LABEL_18:
    v8 = *v6;
  }
LABEL_4:
  v10 = off_110F70;
  *(uint32_t *)off_110F70 = 256;
  while ( (*v10 & 0x200) != 0 )
    ;
  if ( *(uint32_t *)off_110F74 )
  {
    v11 = off_110F78;
    v12 = off_110F7C;
    *(uint32_t *)(*((uint32_t *)off_110F78 + 769) + 4) = a1;
    *v12 += a2;
  }
  else
  {
    v15 = off_110F7C;
    *(uint32_t *)off_110F74 = a1;
    v11 = off_110F78;
    *v15 += a2;
  }
  *(uint32_t *)off_110F80 = 256;
  v11[769] = a3;
  if ( v8 )
  {
    v13 = v8 - 1;
    v14 = *(uint32_t *)off_110F68;
    *v6 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}

