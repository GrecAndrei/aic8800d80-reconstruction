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

extern uint32_t off_117AA8;
extern uint32_t off_117AB0;
extern uint32_t off_117AAC;
extern uint32_t off_117AB4;

// sub_117A24 @ 0x117a24, size 130 bytes
// Doc: sub_1217A24 [util]: Utility/state helper (prologue, shifts and transforms 3 args, 0x10 bytes)
// sub_1217A24 [util]: Utility/state helper (prologue, shifts and transforms 3 args, 0x10 bytes)
void sub_117A24()
{
  int *v0; // r9
  uint32_t *v1; // r7
  uint8_t *v2; // r8
  uint32_t *v3; // r5
  uint8_t *v4; // r6
  int i; // r4
  int v6; // r3
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_117AA8 = 1;
  }
  v0 = (int *)off_117AB0;
  v1 = off_117AAC;
  v2 = off_117AB4;
  ++*(uint32_t *)off_117AB0;
  v3 = v1;
  v4 = v2;
  for ( i = 4; i != -1; --i )
  {
    if ( !*((uint8_t *)v3 + 158)
      && ((v1[52] & 1) == 0 || *((uint8_t *)v1 + 190) != (uint8_t)i)
      && *((uint32_t *)v4 + 84) )
    {
      rf_set_bit_flag((uint8_t)i);
    }
    v3 -= 7;
    v4 -= 84;
  }
  v6 = *v0;
  v2[511] = 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    v8 = *(uint32_t *)off_117AA8;
    *v0 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
}

