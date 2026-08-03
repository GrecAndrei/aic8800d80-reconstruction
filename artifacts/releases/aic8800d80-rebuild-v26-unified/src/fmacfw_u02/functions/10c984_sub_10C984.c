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

extern uint32_t off_10C9B8;
extern uint32_t off_10C9BC;
extern uint32_t off_10C9C4;
extern uint32_t off_10C9C0;
extern uint32_t off_10C9C8;

// sub_10C984 @ 0x10c984, size 52 bytes
int sub_10C984()
{
  int v0; // r4
  int result; // r0
  int *v2; // r2
  uint8_t *v3; // r3
  uint32_t *v4; // r2

  v0 = *(uint32_t *)off_10C9B8 & 0x1F00;
  if ( v0 )
  {
    result = irq_nesting_or_d104(2048);
    v2 = (int *)off_10C9BC;
    v3 = off_10C9C4;
    *(uint32_t *)off_10C9C0 = v0;
    *v2 = v0;
    if ( *v3 )
    {
      v4 = off_10C9C8;
      v3[1] = 1;
      *v4 |= 1u;
    }
  }
  return result;
}

