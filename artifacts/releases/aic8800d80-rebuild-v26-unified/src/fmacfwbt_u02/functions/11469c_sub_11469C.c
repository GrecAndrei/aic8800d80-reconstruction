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

extern uint32_t off_1146C8;
extern uint32_t dword_1146CC;

// sub_11469C @ 0x11469c, size 44 bytes
int  sub_11469C(uint32_t *a1)
{
  int result; // r0
  int v2; // r2

  if ( *(uint32_t *)off_1146C8 )
    return list_push_tail(off_1146C8);
  result = sub_114E60(a1 + 1, *a1);
  if ( result )
  {
    sub_12ECB0(dword_1146CC, result, v2);
    return list_push_tail(off_1146C8);
  }
  return result;
}

