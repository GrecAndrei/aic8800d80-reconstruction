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

extern uint32_t off_115934;
extern uint32_t off_115938;
extern uint32_t dword_115944;
extern uint32_t off_11593C;
extern uint32_t off_115948;

// sub_1157D8 @ 0x1157d8, size 346 bytes
void  sub_1157D8(int a1, int a2)
{
  int v2; // r3
  int v3; // r1
  int v4; // r0
  uint32_t *v5; // r3

  v2 = **(uint16_t **)off_115934;
  if ( (v2 & 1) != 0 )
    ((void ( *)(int, int, int))loc_12F194)(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_115938 = 1;
  }
  v3 = dword_115944;
  ++*(uint32_t *)off_11593C;
  sub_12ECD0(1024, v3);
  v4 = sub_12D14C(0x80000000);
  sub_12BB4C(v4);
  v5 = off_115948;
  *(uint32_t *)off_115948 &= 0xFFFFFFu;
  *v5 |= 0x10u;
  while ( 1 )
    ;
}

