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

extern uint32_t off_116D7C;
extern uint32_t off_116D94;
extern uint32_t off_116D80;
extern uint32_t off_116D8C;
extern uint32_t off_116D90;
extern uint32_t off_116D88;
extern uint32_t off_116D84;

// sub_116CDC @ 0x116cdc, size 158 bytes
int sub_116CDC()
{
  uint16_t *v0; // r5
  int v1; // r4
  int result; // r0
  int *v3; // r9
  int *v4; // r7
  void ( *v5)(uint32_t); // r2
  int v6; // r3
  int v7; // r2
  uint32_t *v8; // r1
  uint32_t *v9; // r2

  v0 = off_116D7C;
  v1 = *(uint32_t *)off_116D7C;
  result = sub_11E628(0x800000);
  if ( v1 )
  {
    v3 = (int *)off_116D94;
    v4 = (int *)off_116D80;
    do
    {
      if ( (*(uint8_t *)(v1 + 16) & 1) == 0 )
        ++v0[4];
      sub_11E7AC(v0);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      v5 = *(void ( **)(uint32_t))(v1 + 4);
      ++*v3;
      *(uint8_t *)(v1 + 16) = 0;
      if ( v5 )
        v5(*(uint32_t *)(v1 + 8));
      result = *(uint32_t *)(v1 + 12);
      if ( result )
        result = sub_1174EC();
      if ( *v3 )
      {
        v6 = *v3 - 1;
        v7 = *v4;
        *v3 = v6;
        if ( !v6 )
        {
          if ( v7 )
            __enable_irq();
        }
      }
      v1 = *(uint32_t *)v0;
    }
    while ( *(uint32_t *)v0 );
  }
  if ( *((uint8_t *)v0 + 10) != *((uint8_t *)v0 + 11) )
  {
    v8 = off_116D8C;
    v9 = off_116D90;
    *(uint32_t *)off_116D88 = *((uint32_t *)off_116D84 + 4) + 200;
    *v8 = 256;
    *v9 |= 0x100u;
    return 256;
  }
  return result;
}

