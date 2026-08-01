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

extern uint32_t dword_111510;
extern uint32_t dword_11151C;
extern uint32_t dword_111520;
extern uint32_t dword_111514;
extern uint32_t off_111518;

// rf_channel_set_flag @ 0x11146c, size 162 bytes
int * rf_channel_set_flag(int a1, int a2, int a3)
{
  uint32_t *v3; // r6
  int *v4; // r5
  int v5; // r7
  uint32_t *v6; // r4

  if ( a1 )
  {
    v3 = (uint32_t *)(dword_111510 + 32 * (a1 - 1) + 8);
    v4 = (int *)(dword_111510 + 32 * (a1 - 1));
  }
  else
  {
    v3 = (uint32_t *)dword_11151C;
    v4 = (int *)dword_111520;
  }
  v5 = *v4;
  if ( (*v4 & 0x80008000) != 0 && ((dword_111514 & v5) != 0x20000 || a2 != 0x8000000 || a3) )
  {
    v6 = off_111518;
    *((uint32_t *)off_111518 + 513) |= 0x200u;
    while ( (v6[5] & 0x80) == 0 )
      ;
    *v4 |= a2 | 0x8008000;
    if ( a3 )
      *v4 &= ~a3;
    if ( !a1 )
      goto LABEL_10;
    if ( v5 < 0 )
    {
      *v3 = 2;
      *v4 |= 0x40000000u;
      while ( (*v3 & 2) == 0 )
        ;
      if ( (v5 & 0x8000) != 0 )
        goto LABEL_10;
    }
    else if ( (v5 & 0x8000) != 0 )
    {
LABEL_10:
      *((uint32_t *)off_111518 + 513) |= 0x400u;
      return timer_entry_clear(a1);
    }
    *v4 &= ~0x8000u;
    goto LABEL_10;
  }
  return timer_entry_clear(a1);
}

