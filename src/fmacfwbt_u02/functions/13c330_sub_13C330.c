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

extern uint32_t dword_13C438;
extern uint32_t dword_13C43C;
extern uint32_t off_13C440;
extern uint32_t dword_13C444;

// sub_13C330 @ 0x13c330, size 264 bytes
int  sub_13C330(int a1, int a2, int a3)
{
  int v4; // r3
  int v5; // r3
  int i; // r4
  int v8; // r4
  int v11; // r4
  int v12; // r0
  int v13; // r6
  int v14; // r2
  int v15; // r3
  int ( *v16)(int, int); // r2
  uint8_t v17; // r0

  v4 = 696 * *(uint8_t *)(a1 + 29);
  if ( (*(uint32_t *)(dword_13C438 + v4 + 4) & 2) == 0 )
    return 1;
  v5 = v4 + 12 * *(uint8_t *)(a1 + 27) + dword_13C438;
  --*(uint8_t *)(v5 + 455);
  if ( (*(uint16_t *)(a1 + 30) & 2) == 0 )
    return 1;
  v8 = *(uint8_t *)(v5 + 453);
  if ( v8 == 33 || msg_get_value((v8 << 8) | 8) != 1 )
    return 1;
  v11 = dword_13C43C + 32 * v8;
  v12 = *(uint32_t *)(a1 + 36) << 10;
  v13 = *(uint32_t *)(v11 + 28);
  --*(uint32_t *)(v11 + 4);
  if ( v12 < 0 )
  {
    if ( a3 )
    {
      if ( !a2 )
      {
        v14 = *(uint16_t *)(a1 + 64);
        if ( ((v14 - (*((uint32_t *)off_13C440 + 4) >> 10)) & 0x8000) == 0 )
          sub_12ECB0(dword_13C444, 0, ((unsigned int)(v14 - (*((uint32_t *)off_13C440 + 4) >> 10)) >> 15) & 1);
      }
    }
    else if ( !a2 && ((*(uint16_t *)(a1 + 64) - (*((uint32_t *)off_13C440 + 4) >> 10)) & 0x8000) == 0 )
    {
      i = 0;
      *(uint32_t *)(*(uint32_t *)(a1 + 76) + 4) |= 2u;
      return i;
    }
  }
  *(uint8_t *)((*(int ( **)(int, int))v13)(v13, (*(uint16_t *)(a1 + 32) - *(uint16_t *)(v13 + 4)) & 0xFFF) + v13 + 6) = 2;
  v15 = *(uint8_t *)(v13 + 262) + v13;
  for ( i = 0; *(uint8_t *)(v15 + 6) == 2; i = (char)(i + 1) )
  {
    *(uint8_t *)(v15 + 6) = 0;
    v16 = *(int ( **)(int, int))v13;
    *(uint16_t *)(v13 + 4) = (*(uint16_t *)(v13 + 4) + 1) & 0xFFF;
    v17 = v16(v13, 1);
    v15 = v13 + v17;
    *(uint8_t *)(v13 + 262) = v17;
  }
  return i;
}

