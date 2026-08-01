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

extern uint32_t dword_105E90;
extern uint32_t off_105E88;
extern uint32_t dword_105E8C;

// validate_handle @ 0x105dcc, size 188 bytes
int  validate_handle(int a1, int a2, int a3, int a4, int a5)
{
  int v9; // r4
  unsigned int v10; // r4
  int v11; // r8
  uint32_t *v12; // r3
  int v13; // r1

  if ( *(uint32_t *)(a4 + 132) <= a2 )
  {
    scale_f32(*(float *)(a4 + 4 * a2 + 148), (uint8_t)a1, a4);
    v9 = *(uint8_t *)(a4 + 104);
  }
  else
  {
    v9 = (uint8_t)a1;
  }
  v10 = v9 | a1 & 0xFFFFF000 | (a2 << 8);
  if ( a3 )
  {
    if ( a2 == 7 )
    {
      v11 = 83886080;
      goto LABEL_8;
    }
    goto LABEL_11;
  }
  if ( a2 != 4 )
  {
    if ( a2 == 7 )
      goto LABEL_6;
LABEL_11:
    if ( (unsigned int)(a2 - 4) > 0xB )
      goto LABEL_9;
    if ( a2 > 6 )
    {
      if ( a3 )
      {
        v11 = (15 - a2) << 24;
        goto LABEL_8;
      }
    }
    else if ( a3 )
    {
      goto LABEL_14;
    }
    a3 = 15 - a2;
    goto LABEL_6;
  }
  a3 = 1;
LABEL_6:
  if ( (a5 & 0xFFFFFFFD) == 0 )
  {
LABEL_14:
    v10 |= 0xC08000u;
    check_interrupt_flag(1, dword_105E90, a5, a2);
    goto LABEL_9;
  }
  v11 = a3 << 24;
LABEL_8:
  v10 = v10 & 0xFF3F7FFF | v11;
LABEL_9:
  v12 = off_105E88;
  v13 = dword_105E8C;
  *(uint32_t *)off_105E88 = v10;
  return check_interrupt_flag(1, v13, *v12, v12);
}

