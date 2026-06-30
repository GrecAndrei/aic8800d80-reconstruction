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

extern uint32_t off_11DD10;
extern uint32_t off_11DD28;
extern uint32_t off_11DD14;
extern uint32_t off_11DD20;
extern uint32_t off_11DD24;
extern uint32_t off_11DD1C;
extern uint32_t off_11DD18;

// sub_11DC70 @ 0x11dc70, size 158 bytes
int sub_11DC70()
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

  v0 = off_11DD10;
  v1 = *(uint32_t *)off_11DD10;
  result = sub_12D374(0x200000);
  if ( v1 )
  {
    v3 = (int *)off_11DD28;
    v4 = (int *)off_11DD14;
    do
    {
      if ( (*(uint8_t *)(v1 + 16) & 1) == 0 )
        ++v0[4];
      sub_12D4F8(v0);
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
        result = rx_desc_status_get();
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
    v8 = off_11DD20;
    v9 = off_11DD24;
    *(uint32_t *)off_11DD1C = *((uint32_t *)off_11DD18 + 4) + 200;
    *v8 = 256;
    *v9 |= 0x100u;
    return 256;
  }
  return result;
}

