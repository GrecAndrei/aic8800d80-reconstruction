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


extern uint32_t dword_110280;
extern uint32_t off_110278;
extern uint32_t off_11027C;
extern uint32_t off_110284;

// sub_110238 @ 0x110238, size 62 bytes
uint32_t *sub_110238()
{
  int *v0; // r4
  int v1; // r0
  uint32_t *result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110278 = 1;
  }
  v0 = (int *)off_11027C;
  v1 = dword_110280;
  ++*(uint32_t *)off_11027C;
  result = sub_12D4F8(v1);
  if ( result )
    --*(uint32_t *)off_110284;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_110278;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}
