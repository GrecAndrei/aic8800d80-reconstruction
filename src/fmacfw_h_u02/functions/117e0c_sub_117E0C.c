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

extern uint32_t off_117EF8;
extern uint32_t dword_117F08;
extern uint32_t off_117EFC;
extern uint32_t dword_117F00;
extern uint32_t off_117F04;
extern uint32_t dword_117F18;
extern uint32_t dword_117F14;
extern uint32_t dword_117F10;
extern uint32_t dword_117F0C;

// is_initialized @ 0x117e0c, size 234 bytes
int  is_initialized(int a1, int a2, int a3, int a4)
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

  if ( *(uint8_t *)off_117EF8 )
    return alloc_tx_event(dword_117F08, a2, a3);
  LOWORD(v4) = *((uint8_t *)off_117EFC + 190);
  if ( (*((uint32_t *)off_117EFC + 52) & 1) == 0 )
    v4 = (*(uint32_t *)(a1 + 84) >> 11) & 3;
  v6 = list_pop(dword_117F00 + 84 * (int16_t)v4 + 28);
  v7 = *(int16_t **)off_117F04;
  v8 = v6;
  if ( **(int16_t **)off_117F04 < 0 && !v6 )
    return unknown_12f2c8(dword_117F18, dword_117F14, 369, a4);
  v9 = *(uint32_t *)(a1 + 84);
  result = v9 << 6;
  *(uint16_t *)(v8 + 8) |= 0x20u;
  if ( (v9 & 0x2000000) != 0 )
  {
    result = (uint16_t)(v9 >> 15);
    if ( *v7 < 0 && (result & 0x3F0) == 0 )
      return unknown_12f2c8(dword_117F10, dword_117F0C, 217, a4);
    if ( ((v9 >> 15) & 0x3FF) - 16 == *(uint8_t *)(v8 + 12) )
    {
      v11 = *(uint32_t *)(*(uint32_t *)(a1 + 28) + 8);
      v12 = *(uint16_t *)(v11 + 16);
      result = v12 & 0x1E;
      if ( result == 22 )
      {
        result = tx_frame_build(a1, v8);
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

