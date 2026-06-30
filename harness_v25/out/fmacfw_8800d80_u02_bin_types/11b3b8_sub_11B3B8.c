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

extern uint32_t off_11B47C;
extern uint32_t off_11B480;
extern uint32_t off_11B484;
extern uint32_t dword_11B48C;
extern uint32_t off_11B488;

// sub_11B3B8 @ 0x11b3b8, size 194 bytes
int  sub_11B3B8(int a1)
{
  unsigned int CPSR; // r3
  int result; // r0
  uint8_t *v4; // r7
  int *v5; // r6
  char *v6; // r2
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r1

  CPSR = __get_CPSR();
  result = CPSR << 31;
  if ( (CPSR & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11B47C = 1;
  }
  v4 = off_11B480;
  v5 = (int *)off_11B484;
  v6 = (char *)off_11B480 + 28 * a1;
  v7 = (uint8_t)v6[47];
  v8 = *(uint32_t *)off_11B484 + 1;
  *(uint32_t *)off_11B484 = v8;
  if ( v7 )
  {
    v9 = *((uint32_t *)v6 + 10);
    v6[47] = 0;
    if ( v9 << 28 )
    {
      *(uint32_t *)(dword_11B48C + 4 * a1) = v9;
      sub_11B368((uint8_t)a1);
    }
    else if ( !v6[46] )
    {
      v6[46] = 1;
    }
    v4[28 * a1 + 45] = v4[28 * a1 + 44];
    goto LABEL_8;
  }
  if ( !v6[45] )
  {
LABEL_17:
    *(uint32_t *)&v4[28 * a1 + 24] = 0;
    goto LABEL_9;
  }
  v12 = (uint8_t)(v6[45] - 1);
  v6[45] = v12;
  if ( !v12 )
  {
    *(uint32_t *)(dword_11B48C + 4 * a1) = *(uint32_t *)(*((uint32_t *)v4 + 4) + 4 * (a1 + 2));
    result = sub_11B368((uint8_t)a1);
    v8 = *v5;
    goto LABEL_17;
  }
LABEL_8:
  result = timestamp_update(&v4[28 * a1 + 20], *((uint32_t *)off_11B488 + 4) + 0x2000);
  v8 = *v5;
LABEL_9:
  if ( v8 )
  {
    v10 = v8 - 1;
    v11 = *(uint32_t *)off_11B47C;
    *v5 = v10;
    if ( !v10 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

