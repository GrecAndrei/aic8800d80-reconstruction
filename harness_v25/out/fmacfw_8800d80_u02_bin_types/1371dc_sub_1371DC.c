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

extern uint32_t off_13724C;
extern uint32_t dword_137250;

// sub_1371DC @ 0x1371dc, size 112 bytes
BOOL  sub_1371DC(uint8_t *a1)
{
  int v1; // r8
  int v3; // r9
  int v4; // r7
  int v5; // r4
  int v6; // r5
  uint8_t *v7; // r10
  int v8; // r2

  v1 = *((uint8_t *)off_13724C + 3898);
  if ( *((uint8_t *)off_13724C + 3898) )
    return sub_143710(a1 + 1, dword_137250, 7) == 0;
  v3 = *(uint32_t *)off_13724C;
  v4 = *(uint8_t *)(*(uint32_t *)off_13724C + 368);
  if ( *(uint8_t *)(*(uint32_t *)off_13724C + 368) )
  {
    v5 = *(uint32_t *)off_13724C;
    v6 = *((uint8_t *)off_13724C + 3898);
    v7 = a1 + 1;
    while ( *(uint8_t *)(v5 + 252) )
    {
      v8 = *a1;
      if ( v8 == *(uint8_t *)(v5 + 252) )
      {
        if ( !sub_143710(v5 + 253, v7, v8) )
          return 1;
        v4 = *(uint8_t *)(v3 + 368);
      }
      ++v6;
      v5 += 33;
      if ( v4 <= v6 )
        return v1;
    }
  }
  return 1;
}

