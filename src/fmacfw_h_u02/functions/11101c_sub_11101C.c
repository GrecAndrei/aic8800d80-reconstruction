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

extern uint32_t off_1110FC;
extern uint32_t off_111100;
extern uint32_t off_111104;
extern uint32_t off_111120;
extern uint32_t off_111124;
extern uint32_t dword_111128;
extern uint32_t off_11112C;
extern uint32_t off_111108;
extern uint32_t off_11110C;
extern uint32_t dword_111110;
extern uint32_t off_111114;
extern uint32_t off_11111C;
extern uint32_t off_111118;

// memcpy @ 0x11101c, size 222 bytes
int  memcpy(int a1)
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
    *(uint32_t *)off_1110FC = 1;
  }
  v2 = (int *)off_111100;
  v3 = *(uint8_t **)off_111104;
  v4 = *(uint32_t *)off_111100 + 1;
  *(uint32_t *)off_111100 = v4;
  if ( *v3 == 1 )
  {
    v11 = off_111120;
    v12 = off_111124;
    if ( *(uint8_t *)off_111120 )
    {
      v14 = *((uint8_t *)off_111124 + 374);
      if ( v14 != 1 )
        goto LABEL_4;
      if ( get_mmio_state(dword_111128) )
        goto LABEL_18;
      if ( v12[369] )
        mmio_clear_bit(v14);
      else
        mmio_set_bit(v14);
    }
    else
    {
      if ( *((uint8_t *)off_111124 + 369) )
        mmio_clear_bit(1);
      else
        mmio_set_bit(1);
      v13 = (uint8_t)v12[374];
      *v11 = 1;
      if ( v13 != 1 )
        goto LABEL_18;
    }
    mem_copy_util(dword_111128, *((uint32_t *)off_11112C + 4) + 10000);
LABEL_18:
    v4 = *v2;
  }
LABEL_4:
  v5 = off_111108;
  *(uint32_t *)off_111108 = 64;
  while ( (*v5 & 0x80) != 0 )
    ;
  if ( *(uint32_t *)off_11110C )
  {
    result = dword_111110;
    v7 = off_111114;
    *(uint32_t *)(*(uint32_t *)(dword_111110 + 6164) + 4) = a1;
  }
  else
  {
    v7 = off_111114;
    *(uint32_t *)off_11110C = a1;
    result = dword_111110;
  }
  ++*v7;
  v8 = off_11111C;
  *(uint8_t *)off_111118 |= 2u;
  *v8 = 64;
  *(uint32_t *)(result + 6164) = a1;
  if ( v4 )
  {
    v9 = v4 - 1;
    v10 = *(uint32_t *)off_1110FC;
    *v2 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}

