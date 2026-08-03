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

extern uint32_t off_126578;
extern uint32_t off_12657C;
extern uint32_t off_126580;
extern uint32_t off_126584;

// sub_126538 @ 0x126538, size 64 bytes
// Doc: sub_1226538 [unknown]: Unknown helper function in lmacfw_rf image
// sub_1226538 [unknown]: Unknown helper function in lmacfw_rf image
int sub_126538()
{
  uint32_t *v0; // r2
  unsigned int *v1; // r4
  int v2; // r1
  int result; // r0
  unsigned int v4; // r3
  int *v5; // r3
  int v6; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_126578 = 1;
  }
  v0 = off_12657C;
  v1 = (unsigned int *)off_126580;
  v2 = *(uint32_t *)off_12657C;
  result = *(uint32_t *)off_12657C + 1;
  v4 = *(uint32_t *)off_126580 & 0xFFFFFBFF;
  *(uint32_t *)off_12657C = result;
  *v1 = v4;
  if ( result )
  {
    v5 = (int *)off_126578;
    *v0 = v2;
    v6 = *v5;
    if ( !v2 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  *(uint32_t *)off_126584 = 1024;
  return result;
}

