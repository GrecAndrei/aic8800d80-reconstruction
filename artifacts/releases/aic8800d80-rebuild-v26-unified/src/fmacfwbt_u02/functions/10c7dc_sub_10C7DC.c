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

extern uint32_t off_10C810;
extern uint32_t off_10C814;
extern uint32_t off_10C81C;
extern uint32_t off_10C818;
extern uint32_t off_10C820;

// sub_10C7DC @ 0x10c7dc, size 52 bytes
int sub_10C7DC()
{
  int v0; // r4
  int result; // r0
  int *v2; // r2
  uint8_t *v3; // r3
  uint32_t *v4; // r2

  v0 = *(uint32_t *)off_10C810 & 0x1F00;
  if ( v0 )
  {
    result = irq_nesting_or(2048);
    v2 = (int *)off_10C814;
    v3 = off_10C81C;
    *(uint32_t *)off_10C818 = v0;
    *v2 = v0;
    if ( *v3 )
    {
      v4 = off_10C820;
      v3[1] = 1;
      *v4 |= 1u;
    }
  }
  return result;
}

