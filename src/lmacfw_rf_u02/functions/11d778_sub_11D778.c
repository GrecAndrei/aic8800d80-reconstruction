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

extern uint32_t off_11D89C;
extern uint32_t off_11D8A0;
extern uint32_t off_11D8A4;
extern uint32_t off_11D8A8;
extern uint32_t off_11D8AC;
extern uint32_t dword_11D8D0;
extern uint32_t dword_11D8B0;
extern uint32_t off_11D8B4;
extern uint32_t off_11D8B8;
extern uint32_t dword_11D8CC;
extern uint32_t off_11D8C4;

// rf_cmd_clear @ 0x11d778, size 290 bytes
void  rf_cmd_clear(int a1, int a2)
{
  int v2; // r4
  int *v3; // r0
  int *v4; // r1
  int v5; // r2
  int v6; // r3
  unsigned int *v7; // r1
  int v8; // r0
  int v9; // r0
  int v10; // r0

  v2 = *(uint32_t *)off_11D89C & *(uint32_t *)off_11D8A0;
  *(uint32_t *)((char *)off_11D89C + 0xFFFFFFFC) = v2;
  if ( v2 << 30 )
  {
    v3 = (int *)off_11D8A4;
    v4 = (int *)off_11D8A8;
    v5 = *(uint32_t *)off_11D8A4;
    v6 = *(uint32_t *)off_11D8A8;
    if ( (v2 & 1) != 0 && !*((uint8_t *)off_11D8AC + 36) )
    {
      *(uint32_t *)off_11D8A4 = v5 | 0x5400;
      *v3 = v5 | 0xFC00;
      *v4 = v6 | 0x500000;
      v10 = dword_11D8D0;
      *v4 = v6 | 0xF00000;
      dispatch_event_handler(v10, v4);
    }
    else
    {
      v7 = (unsigned int *)off_11D8A8;
      v8 = dword_11D8B0;
      *(uint32_t *)off_11D8A4 = v5 & 0xFFFF57FF;
      *v7 = v6 & 0xFF5FFFFF;
      dispatch_event_handler(v8, v7);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(uint32_t *)off_11D8B4 & 1) != 0 )
    {
      *(uint32_t *)off_11D8B8 |= 0x400000u;
      while ( 1 )
        ;
    }
    v9 = dword_11D8CC;
    *(uint32_t *)off_11D8C4 |= 1u;
    dispatch_event_handler(v9, a2);
  }
}

