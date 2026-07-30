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

extern uint32_t off_11EAF0;
extern uint32_t off_11EAF4;

// sub_11EAA0 @ 0x11eaa0, size 78 bytes
int  sub_11EAA0(int a1)
{
  char *v2; // r0
  void *v3; // r0
  char v4; // r2

  sub_11DF7C(a1, *(uint32_t *)(a1 + 28));
  v2 = (char *)off_11EAF0;
  if ( *((uint32_t *)off_11EAF0 + 14) )
  {
    *(uint8_t *)(a1 + 16) |= 1u;
    *(uint32_t *)(a1 + 4) = 0;
    v3 = v2 + 56;
    return sub_12D248(v3);
  }
  v3 = off_11EAF4;
  if ( *(uint32_t *)off_11EAF4 )
  {
    v4 = *(uint8_t *)(a1 + 16);
    *(uint32_t *)(a1 + 4) = 0;
    *(uint8_t *)(a1 + 16) = v4 | 1;
    return sub_12D248(v3);
  }
  return sub_11E0B4(a1);
}

