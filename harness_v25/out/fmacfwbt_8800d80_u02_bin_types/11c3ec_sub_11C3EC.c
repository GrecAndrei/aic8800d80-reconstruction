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

extern uint32_t dword_11C4B4;
extern uint32_t dword_11C4B8;

// sub_11C3EC @ 0x11c3ec, size 198 bytes
int  sub_11C3EC(int a1, int a2)
{
  int v2; // r2
  int v3; // r5
  int v4; // r3
  int result; // r0
  int v7; // r3
  uint16_t *v8; // r5
  int v9; // r12
  unsigned int v10; // r2
  int v11; // r2
  unsigned int v12; // r4
  int v13; // r7

  v2 = *(uint32_t *)(a1 + 84);
  v3 = *(uint32_t *)(*(uint32_t *)(a1 + 28) + 8);
  v4 = *(uint16_t *)(a1 + 48);
  if ( (v2 & 0x200) == 0 || (result = *(uint32_t *)(a1 + 84) & 0x400, (v2 & 0x400) != 0) )
  {
    v7 = v4 - 18;
    v8 = (uint16_t *)(v3 + 18);
    if ( v7 <= 1 )
      return 0;
    v9 = dword_11C4B4 + 696 * *(uint8_t *)(a2 + 12);
    while ( 1 )
    {
      v12 = *v8;
      v13 = v12 & 0x7FF;
      if ( v13 == 2045 )
        break;
      result = v12 & 0x800;
      if ( (v12 & 0x800) == 0 )
      {
        if ( v7 <= 3 )
          return result;
        v10 = v8[1];
        if ( (v10 & 8) != 0 )
          return result;
        v11 = *(uint8_t *)(dword_11C4B8 + ((v10 >> 1) & 7)) + 4;
        if ( v11 > v7 )
          return 0;
LABEL_8:
        v7 -= v11;
        if ( *(uint16_t *)(v9 + 32) == v13 )
          goto LABEL_13;
        goto LABEL_9;
      }
      v11 = 2;
      v7 -= 2;
      if ( *(uint16_t *)(v9 + 32) == v13 )
      {
LABEL_13:
        result = v12 & 0x800;
        if ( (v12 & 0x800) != 0 )
        {
          *(uint32_t *)(a2 + 224) = 0;
          return 1;
        }
        else if ( *(uint8_t *)(a2 + 13) == v12 >> 12 )
        {
          sub_14380C(a2 + 228, v8 + 1, v11 - 2);
          *(uint32_t *)(a2 + 224) = a2 + 228;
          return 1;
        }
        return result;
      }
LABEL_9:
      v8 = (uint16_t *)((char *)v8 + v11);
      if ( v7 <= 1 )
        return 0;
    }
    v11 = 12;
    goto LABEL_8;
  }
  return result;
}

