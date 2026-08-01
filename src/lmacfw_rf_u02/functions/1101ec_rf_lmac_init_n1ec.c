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

extern uint32_t off_110224;
extern uint32_t off_110228;
extern uint32_t dword_11022C;

// irq_disable_arg @ 0x1101ec, size 54 bytes
// Doc: irq_disable_arg [rf]: Initialize LMAC RF state with config
// irq_disable_arg [rf]: Initialize LMAC RF state with config
int irq_disable_arg()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110224 = 1;
  }
  v0 = (int *)off_110228;
  v1 = dword_11022C;
  ++*(uint32_t *)off_110228;
  result = check_kernel_state(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_110224;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

