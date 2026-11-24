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


extern uint32_t dword_115798;
extern uint32_t dword_11579C;
extern uint32_t off_115768;
extern uint32_t off_11576C;
extern uint32_t off_115774;
extern uint32_t off_115778;
extern uint32_t off_11577C;
extern uint32_t off_115780;
extern uint32_t off_115784;
extern uint32_t off_115788;
extern uint32_t off_115790;
extern uint32_t off_115794;
extern uint32_t off_1157A4;
extern uint32_t off_1157A8;

// peripheral_clock_enable_1 @ 0x115640, size 296 bytes
unsigned int peripheral_clock_enable_1()
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

  v0 = off_11576C;
  *((uint32_t *)off_115768 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = off_115774;
  check_status_bits(2, aW);
  v2 = off_115778;
  *(uint32_t *)off_115778 |= 0x80000000;
  v1[1] = 0;
  while ( (*v2 & 0x40000000) == 0 )
    ;
  v3 = (int *)off_11577C;
  if ( BYTE1(((uint32_t *)(uintptr_t)off_11577C)[47]) && **(uint16_t **)off_115780 < 0 && *v1 != (*(uint32_t *)off_115794 & 0xF) )
    mmio_clear_register((int)aRwnxEnvPrevHwS, (int)aRwnxlWakeup, 968);
  v4 = off_115778;
  v5 = (uint8_t **)off_115784;
  *(uint32_t *)off_115778 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (uint8_t)**v5;
  if ( v6 == 3 )
  {
    *(uint32_t *)off_1157A8 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(uint32_t *)off_1157A4 &= ~0x20u;
  }
  if ( *(uint8_t *)off_115788 )
    *(uint32_t *)off_11576C |= 0x2000000u;
  else
    *((uint32_t *)off_115768 + 14) &= ~0x10u;
  result = check_status_bits(2, aWe_0);
  v8 = *(uint8_t **)off_115790;
  v9 = **(uint8_t **)off_115790;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
LABEL_22:
      *(uint32_t *)off_1157A8 &= ~1u;
  }
  else
  {
    if ( !*((uint8_t *)v3 + 189) )
    {
      *(uint32_t *)off_115794 = (uint8_t)(16 * *v1);
      v9 = (uint8_t)*v8;
    }
    if ( v9 == 1 )
    {
      v10 = dword_115798;
      v11 = dword_11579C;
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
