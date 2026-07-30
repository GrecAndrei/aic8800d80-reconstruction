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

extern uint32_t off_11E0FC;
extern uint32_t off_11E0F8;

// sub_11E0B4 @ 0x11e0b4, size 66 bytes
int  sub_11E0B4(int result)
{
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(uint32_t *)(result + 152);
  if ( *(uint8_t *)(result + 156) )
  {
    v3 = *(uint32_t *)off_11E0FC & 0x80000000;
    if ( v1 < (*(uint32_t *)off_11E0FC & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(uint32_t *)off_11E0FC = v1 | v3;
  }
  else
  {
    v2 = *(uint32_t *)off_11E0F8 & 0x80000000;
    if ( v1 < (*(uint32_t *)off_11E0F8 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(uint32_t *)off_11E0F8 = v1 | v2;
  }
  return result;
}

