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

extern uint32_t dword_12657C;
extern uint32_t dword_126578;
extern uint32_t dword_126580;

// llm_scan_task_handler @ 0x126474, size 258 bytes
BOOL  llm_scan_task_handler(int a1, int a2, int a3)
{
  int v6; // r5
  int v7; // r3
  int v8; // r9
  unsigned int v9; // r8
  int v10; // r6
  int v11; // r6
  int v12; // r0
  int v13; // r3
  int v14; // r0
  int v16; // r3
  int v17; // r5
  int v18; // r3

  if ( a1 )
  {
    v6 = a1;
  }
  else
  {
    v16 = dword_12657C;
    while ( 1 )
    {
      if ( *(uint8_t *)(v16 + 24) != 255 )
      {
        v17 = *(uint8_t *)(v16 + 27);
        if ( v17 != 255 )
          break;
      }
      v16 += 28;
      if ( dword_12657C + 84 == v16 )
        return 0;
    }
    v6 = dword_126578 + 1320 * v17;
  }
  if ( !a3 || *(uint8_t *)(a3 + 10) == 255 )
  {
    v14 = get_constant_1000() + 14000;
  }
  else
  {
    v7 = dword_126578 + 1320 * *(uint8_t *)(a3 + 8);
    if ( *(uint8_t *)(v7 + 106) )
    {
      if ( *(uint8_t *)(v7 + 106) == 2 )
      {
        v18 = *(uint16_t *)(v7 + 222);
        v9 = v18 << 10;
        v8 = v18 << 9;
      }
      else
      {
        v8 = 51200;
        v9 = 102400;
      }
    }
    else
    {
      v9 = *(uint32_t *)(dword_126580 + 696 * *(uint8_t *)(v7 + 116) + 8);
      v8 = v9 >> 1;
    }
    v10 = *(uint32_t *)(a3 + 4);
    v11 = v10 + 10000 + get_constant_1000();
    v12 = bt_runtime_check2(a1, *(uint8_t *)(a3 + 11));
    v13 = v12 - a2;
    if ( v12 - a2 + v8 < 0 )
    {
      do
        v12 += v9;
      while ( v8 - a2 + v12 < 0 );
      v13 = v12 - a2;
    }
    if ( v13 < 0 )
      a2 = v12 - 1;
    if ( v11 + 9000 - a2 < 0 )
      v14 = 5000;
    else
      v14 = v11 + 4000 - a2;
  }
  return llc_evt_dispatch(v6, 1, 0, 1, 0, v14, a2) != 255;
}

