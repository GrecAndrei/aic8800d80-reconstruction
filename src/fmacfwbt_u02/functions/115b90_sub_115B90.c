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


extern uint32_t dword_115CE8;
extern uint32_t dword_115CEC;
extern uint32_t off_115CB8;
extern uint32_t off_115CBC;
extern uint32_t off_115CC4;
extern uint32_t off_115CC8;
extern uint32_t off_115CCC;
extern uint32_t off_115CD0;
extern uint32_t off_115CD4;
extern uint32_t off_115CD8;
extern uint32_t off_115CE0;
extern uint32_t off_115CE4;
extern uint32_t off_115CF4;
extern uint32_t off_115CF8;

// rf_clock_enable @ 0x115b90, size 296 bytes
unsigned int rf_clock_enable()
{
  uint32_t *v0; // r2
  uint8_t *v1; // r4
  uint32_t *v2; // r2
  int *v3; // r6
  uint32_t *v4; // r3
  uint8_t **v5; // r5
  int v6; // r3
  unsigned int result; // r0
  uint8_t *v8; // r7
  int v9; // r3
  int v10; // r3
  int v11; // r1

  v0 = off_115CBC;
  *((uint32_t *)off_115CB8 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = off_115CC4;
  state_check_feature(2, aW);
  v2 = off_115CC8;
  *(uint32_t *)off_115CC8 |= 0x80000000;
  v1[1] = 0;
  while ( (*v2 & 0x40000000) == 0 )
    ;
  v3 = (int *)off_115CCC;
  if ( BYTE1(((uint32_t *)(uintptr_t)off_115CCC)[47]) && **(uint16_t **)off_115CD0 < 0 && *v1 != (*(uint32_t *)off_115CE4 & 0xF) )
    mmio_irq_clear((int)aRwnxEnvPrevHwS, (int)aRwnxlWakeup, 968);
  v4 = off_115CC8;
  v5 = (uint8_t **)off_115CD4;
  *(uint32_t *)off_115CC8 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (uint8_t)**v5;
  if ( v6 == 3 )
  {
    *(uint32_t *)off_115CF8 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(uint32_t *)off_115CF4 &= ~0x20u;
  }
  if ( *(uint8_t *)off_115CD8 )
    *(uint32_t *)off_115CBC |= 0x2000000u;
  else
    *((uint32_t *)off_115CB8 + 14) &= ~0x10u;
  result = state_check_feature(2, aWe_0);
  v8 = *(uint8_t **)off_115CE0;
  v9 = **(uint8_t **)off_115CE0;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
LABEL_22:
      *(uint32_t *)off_115CF8 &= ~1u;
  }
  else
  {
    if ( !*((uint8_t *)v3 + 189) )
    {
      *(uint32_t *)off_115CE4 = (uint8_t)(16 * *v1);
      v9 = (uint8_t)*v8;
    }
    if ( v9 == 1 )
    {
      v10 = dword_115CE8;
      v11 = dword_115CEC;
      do
      {
        if ( *(uint8_t *)(v10 + 37) )
        {
          result = (*(volatile uint32_t *)0x40501010u);
          **(uint32_t **)(v10 + 340) = result;
        }
        v10 += 696;
      }
      while ( v10 != v11 );
    }
    if ( **v5 == 3 && *v8 == 2 )
      goto LABEL_22;
  }
  return result;
}
