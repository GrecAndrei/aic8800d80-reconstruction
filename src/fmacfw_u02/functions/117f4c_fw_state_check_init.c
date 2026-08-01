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

extern uint32_t off_118038;
extern uint32_t dword_118048;
extern uint32_t off_11803C;
extern uint32_t dword_118040;
extern uint32_t off_118044;
extern uint32_t dword_118058;
extern uint32_t dword_118054;
extern uint32_t dword_118050;
extern uint32_t dword_11804C;

// init_flag_check @ 0x117f4c, size 234 bytes
// Doc: init_flag_check [util]: Check firmware state flag at 0x182720 and branch on init status
// init_flag_check [util]: Check firmware state flag at 0x182720 and branch on init status
int  init_flag_check(int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int v6; // r0
  int16_t *v7; // r1
  int v8; // r4
  unsigned int v9; // r2
  int result; // r0
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r2

  if ( *(uint8_t *)off_118038 )
    return event_dispatch(dword_118048, a2, a3);
  LOWORD(v4) = *((uint8_t *)off_11803C + 190);
  if ( (*((uint32_t *)off_11803C + 52) & 1) == 0 )
    v4 = (*(uint32_t *)(a1 + 84) >> 11) & 3;
  v6 = mem_word_load(dword_118040 + 84 * (int16_t)v4 + 28);
  v7 = *(int16_t **)off_118044;
  v8 = v6;
  if ( **(int16_t **)off_118044 < 0 && !v6 )
    return bad_func_0x12f408(dword_118058, dword_118054, 369, a4);
  v9 = *(uint32_t *)(a1 + 84);
  result = v9 << 6;
  *(uint16_t *)(v8 + 8) |= 0x20u;
  if ( (v9 & 0x2000000) != 0 )
  {
    result = (uint16_t)(v9 >> 15);
    if ( *v7 < 0 && (result & 0x3F0) == 0 )
      return bad_func_0x12f408(dword_118050, dword_11804C, 217, a4);
    if ( ((v9 >> 15) & 0x3FF) - 16 == *(uint8_t *)(v8 + 12) )
    {
      v11 = *(uint32_t *)(*(uint32_t *)(a1 + 28) + 8);
      v12 = *(uint16_t *)(v11 + 16);
      result = v12 & 0x1E;
      if ( result == 22 )
      {
        result = parse_rx_header(a1, v8);
        if ( result )
          goto LABEL_17;
      }
      else if ( (v9 & 0x200) == 0 )
      {
        v13 = *(uint16_t *)(a1 + 48);
        if ( (v13 == 52 || v13 == 28) && *(uint8_t *)(v8 + 13) == v12 >> 12 )
        {
          result = memcpy(v8 + 228, v11 + 18, 34);
          *(uint32_t *)(v8 + 224) = v8 + 228;
LABEL_17:
          *(uint16_t *)(v8 + 8) |= 0x40u;
        }
      }
    }
  }
  return result;
}

