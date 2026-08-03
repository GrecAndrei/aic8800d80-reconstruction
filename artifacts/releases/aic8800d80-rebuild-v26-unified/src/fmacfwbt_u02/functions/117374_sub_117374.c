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

extern uint32_t off_11748C;
extern uint32_t off_117490;
extern uint32_t off_117494;
extern uint32_t off_117498;
extern uint32_t off_1174A0;
extern uint32_t off_11749C;
extern uint32_t off_1174A4;
extern uint32_t off_1174A8;
extern uint32_t dword_1174B0;
extern uint32_t dword_1174AC;

// sub_117374 @ 0x117374, size 278 bytes
int  sub_117374(int result)
{
  int v1; // r3
  int v2; // r6
  uint32_t *v3; // r2
  int *v4; // r5
  int v5; // r4
  int v6; // r1
  int *v7; // r3
  int v8; // r3
  uint32_t *v9; // r2
  uint32_t *v10; // r2
  uint32_t *v11; // r2
  uint32_t *v12; // r2
  uint32_t *v13; // r2
  uint32_t *v14; // r2

  v1 = *(uint32_t *)off_11748C;
  v2 = 1 << result;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_117490 = 1;
  }
  v3 = off_117494;
  v4 = (int *)off_11748C;
  v5 = *(uint32_t *)off_117494;
  v6 = *(uint32_t *)off_117494 + 1;
  *(uint32_t *)off_117494 = v6;
  *v4 = v1 & ~v2;
  if ( v6 )
  {
    v7 = (int *)off_117490;
    *v3 = v5;
    v8 = *v7;
    if ( !v5 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  *(uint32_t *)off_117498 = v2;
  switch ( result )
  {
    case 0:
      v10 = off_1174A0;
      *(uint32_t *)off_11749C = 0x10000;
      while ( (*v10 & 0x30) != 0 )
        ;
      *(uint32_t *)off_1174A4 = 0x10000;
      break;
    case 1:
      v11 = off_1174A0;
      *(uint32_t *)off_11749C = 0x20000;
      while ( (*v11 & 0x300) != 0 )
        ;
      *(uint32_t *)off_1174A4 = 0x20000;
      break;
    case 2:
      v13 = off_1174A0;
      *(uint32_t *)off_11749C = 0x40000;
      while ( (*v13 & 0x3000) != 0 )
        ;
      *(uint32_t *)off_1174A4 = 0x40000;
      break;
    case 3:
      v12 = off_1174A0;
      *(uint32_t *)off_11749C = 0x80000;
      while ( (*v12 & 0x30000) != 0 )
        ;
      *(uint32_t *)off_1174A4 = 0x80000;
      break;
    case 4:
      v14 = off_1174A0;
      *(uint32_t *)off_11749C = 0x8000;
      while ( *v14 << 30 )
        ;
      *(uint32_t *)off_1174A4 = 0x8000;
      break;
    case 5:
      v9 = off_1174A0;
      *(uint32_t *)off_11749C = 0x200000;
      while ( (*v9 & 0x3000000) != 0 )
        ;
      *(uint32_t *)off_1174A4 = 0x200000;
      break;
    default:
      if ( **(int16_t **)off_1174A8 < 0 )
        result = sub_12F694(dword_1174B0, dword_1174AC, 2338);
      break;
  }
  return result;
}

