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

extern uint32_t off_11110C;
extern uint32_t off_111138;
extern uint32_t off_111110;
extern uint32_t off_111128;
extern uint32_t off_11112C;
extern uint32_t dword_111130;
extern uint32_t off_111134;
extern uint32_t off_111114;
extern uint32_t off_111118;
extern uint32_t off_11111C;
extern uint32_t off_111120;
extern uint32_t off_111124;

// sub_11101C @ 0x11101c, size 238 bytes
int  sub_11101C(int a1, int a2, int a3)
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
    *(uint32_t *)off_11110C = 1;
  }
  v6 = (int *)off_111138;
  v7 = *(uint8_t **)off_111110;
  v8 = *(uint32_t *)off_111138 + 1;
  *(uint32_t *)off_111138 = v8;
  result = *v7;
  if ( result == 1 )
  {
    v16 = off_111128;
    if ( *(uint8_t *)off_111128 )
    {
      v19 = off_11112C;
      v20 = *((uint8_t *)off_11112C + 374);
      if ( v20 != 1 )
        goto LABEL_4;
      result = rf_msg_handler_n22e(dword_111130);
      if ( result )
        goto LABEL_18;
      if ( v19[369] )
        sub_10DD14(v20);
      else
        rf_mem_read_n47e(v20);
    }
    else
    {
      v17 = (uint8_t *)off_11112C;
      if ( *((uint8_t *)off_11112C + 369) )
        result = sub_10DD14(1);
      else
        result = rf_mem_read_n47e(1);
      v18 = v17[374];
      *v16 = 1;
      if ( v18 != 1 )
        goto LABEL_18;
    }
    result = timestamp_update(dword_111130, *((uint32_t *)off_111134 + 4) + 10000);
LABEL_18:
    v8 = *v6;
  }
LABEL_4:
  v10 = off_111114;
  *(uint32_t *)off_111114 = 256;
  while ( (*v10 & 0x200) != 0 )
    ;
  if ( *(uint32_t *)off_111118 )
  {
    v11 = off_11111C;
    v12 = off_111120;
    *(uint32_t *)(*((uint32_t *)off_11111C + 769) + 4) = a1;
    *v12 += a2;
  }
  else
  {
    v15 = off_111120;
    *(uint32_t *)off_111118 = a1;
    v11 = off_11111C;
    *v15 += a2;
  }
  *(uint32_t *)off_111124 = 256;
  v11[769] = a3;
  if ( v8 )
  {
    v13 = v8 - 1;
    v14 = *(uint32_t *)off_11110C;
    *v6 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}

