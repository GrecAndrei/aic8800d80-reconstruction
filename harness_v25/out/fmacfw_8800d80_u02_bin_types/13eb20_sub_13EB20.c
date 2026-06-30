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

extern uint32_t dword_13EC64;
extern uint32_t dword_13EC60;
extern uint32_t dword_13EC6C;
extern uint32_t dword_13EC5C;
extern uint32_t dword_13EC68;
extern uint32_t dword_13EC58;

// sub_13EB20 @ 0x13eb20, size 312 bytes
// Doc: sub_123EB20 [util]: Extract fields from a 16-bit word with bitfield ops
// sub_123EB20 [util]: Extract fields from a 16-bit word with bitfield ops
unsigned int  sub_13EB20(int a1)
{
  unsigned int v1; // r3
  int v2; // r1
  int v3; // r4
  int v4; // r2
  unsigned int result; // r0
  unsigned int v6; // r0
  int v7; // r3
  unsigned int v8; // r0

  v1 = *(uint16_t *)(a1 + 6);
  v2 = (v1 >> 11) & 7;
  if ( (v1 & 0x2000) != 0 )
  {
    v3 = v1 & 0xF;
    switch ( v2 )
    {
      case 5:
        v6 = *(uint32_t *)(dword_13EC64 + 4 * (6 * (v1 & 0xF) + 3 * ((v1 >> 8) & 1) + ((v1 >> 9) & 3))) >> ((v1 & 0x80) != 0);
        v7 = (v1 >> 4) & 7;
        return v6 / (v7 + 1);
      case 6:
        v8 = *(uint8_t *)(a1 + 8) & 7;
        if ( v8 > 2 )
          result = (*(uint32_t *)(dword_13EC64
                              + 4
                              * (6 * (v1 & 0xF) + ((v8 - 3) & 0xFE) + ((uint8_t)(v8 - 3) >> 1) + ((v1 >> 9) & 3))) >> ((v8 - 3) & 1))
                 / (((v1 >> 4) & 7) + 1);
        else
          result = *(uint32_t *)(*(uint32_t *)(dword_13EC60 + 4 * v8) + 4 * (3 * (v1 & 0xF) + ((v1 >> 9) & 3)))
                 / (((v1 >> 4) & 7) + 1);
        break;
      case 7:
        if ( ((v1 >> 7) & 3) == 1 )
          result = *(uint32_t *)(dword_13EC6C + 4 * ((v1 >> 9) & 3)) / (((v1 >> 4) & 7) + 1);
        else
          result = *(uint32_t *)(dword_13EC64 + 4 * (6 * (v1 & 0xF) + ((v1 >> 9) & 3))) / (((v1 >> 4) & 7) + 1);
        break;
      default:
        goto LABEL_7;
    }
  }
  else if ( ((v1 >> 11) & 6) != 0 )
  {
    v3 = v1 & 7;
LABEL_7:
    v6 = *(uint32_t *)(dword_13EC5C + 4 * ((v1 >> 9) & 1 | (2 * ((v1 >> 7) & 3)) | (8 * v3)));
    if ( v2 == 4 )
      v7 = (v1 >> 4) & 7;
    else
      v7 = (v1 >> 3) & 3;
    return v6 / (v7 + 1);
  }
  else
  {
    v4 = v1 & 0x7F;
    if ( (v1 & 0x7C) != 0 )
      return *(uint32_t *)(dword_13EC68 + 4 * (v4 - 4));
    else
      return *(uint32_t *)(dword_13EC58 + 4 * ((v1 >> 10) & 1 | (2 * v4)));
  }
  return result;
}

