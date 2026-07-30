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

extern uint32_t off_114874;
extern uint32_t dword_11487C;
extern uint32_t dword_114878;

// sub_11482C @ 0x11482c, size 70 bytes
int  sub_11482C(int a1)
{
  int *v1; // r4
  int result; // r0
  int v3; // r2
  int v4; // r5
  int v5; // r1
  int v6; // r2
  int v7; // r0
  int v8; // r1
  int v9; // r0

  v1 = (int *)off_114874;
  result = j_buffer_pool_get(a1 - 16);
  v3 = *v1;
  if ( *v1 )
  {
    v4 = v3 + 4;
    v5 = sub_114790((uint8_t *)(v3 + 4));
    if ( v5 < 0 )
    {
      v8 = *(uint8_t *)(v6 + 4);
      v9 = dword_11487C;
      return sub_12ECB0(v9, v8, v6);
    }
    v7 = sub_114E60(v4, v5);
    if ( v7 )
    {
      v8 = v7;
      v9 = dword_114878;
      return sub_12ECB0(v9, v8, v6);
    }
    return sub_12D4F8(v1);
  }
  return result;
}

