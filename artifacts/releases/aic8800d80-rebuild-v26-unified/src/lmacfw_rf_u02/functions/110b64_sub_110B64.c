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

extern uint32_t off_110BD8;
extern uint32_t off_110BDC;
extern uint32_t off_110BE0;
extern uint32_t off_110BE4;
extern uint32_t dword_110BE8;
extern uint32_t off_110BEC;
extern uint32_t off_110BF4;
extern uint32_t off_110BF0;

// sub_110B64 @ 0x110b64, size 116 bytes
int  sub_110B64(int result)
{
  uint32_t *v1; // r1
  uint32_t *v2; // r2
  int v3; // r4
  int v4; // r5
  int v5; // r6
  uint32_t *v6; // r2
  uint32_t *v7; // r7
  int *v8; // r3
  int v9; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110BD8 = 1;
  }
  v1 = off_110BDC;
  v2 = off_110BE0;
  v3 = *(uint32_t *)off_110BDC;
  v4 = *(uint32_t *)off_110BDC + 1;
  *(uint32_t *)off_110BDC = v4;
  *v2 = 64;
  while ( (*v2 & 0x80) != 0 )
    ;
  if ( *(uint32_t *)off_110BE4 )
  {
    v5 = dword_110BE8;
    v6 = off_110BEC;
    *(uint32_t *)(*(uint32_t *)(dword_110BE8 + 6164) + 4) = result;
  }
  else
  {
    v6 = off_110BEC;
    *(uint32_t *)off_110BE4 = result;
    v5 = dword_110BE8;
  }
  ++*v6;
  v7 = off_110BF4;
  *(uint8_t *)off_110BF0 |= 2u;
  *v7 = 64;
  *(uint32_t *)(v5 + 6164) = result;
  if ( v4 )
  {
    v8 = (int *)off_110BD8;
    *v1 = v3;
    v9 = *v8;
    if ( !v3 )
    {
      if ( v9 )
        __enable_irq();
    }
  }
  return result;
}

