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

extern uint32_t off_1142D4;
extern uint32_t off_1142D8;
extern uint32_t off_1142DC;
extern uint32_t off_1142E0;

// sub_11428C @ 0x11428c, size 72 bytes
// Doc: rf_fault_dump_n [rf]: Dumps the n-th RF fault state (field at offset 0x274 in the global RF state struct), increments the fault counter, and sets the handled flag.
// rf_fault_dump_n [rf]: Dumps the n-th RF fault state (field at offset 0x274 in the global RF state struct), increments the fault counter, and sets the handled flag.
int sub_11428C()
{
  int *v0; // r5
  uint32_t *v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1142D4 = 1;
  }
  v0 = (int *)off_1142D8;
  v1 = off_1142DC;
  ++*(uint32_t *)off_1142D8;
  while ( !*v1 )
    ;
  result = sub_12D248(*(uint32_t *)off_1142E0 + 628);
  *v1 = 1;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_1142D4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

