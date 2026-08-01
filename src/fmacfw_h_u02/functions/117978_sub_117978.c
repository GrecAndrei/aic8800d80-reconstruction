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

extern uint32_t off_117A58;
extern uint32_t off_117A5C;
extern uint32_t off_117A60;
extern uint32_t off_117A6C;
extern uint32_t off_117A70;
extern uint32_t dword_117A74;
extern uint32_t off_117A78;
extern uint32_t dword_117A64;
extern uint32_t off_117A68;

// critical_section_enter_alt @ 0x117978, size 222 bytes
int critical_section_enter_alt()
{
  int *v0; // r7
  uint8_t *v1; // r5
  uint32_t *v2; // r8
  uint32_t *v3; // r11
  int v4; // r10
  int *v5; // r9
  uint32_t *v6; // r6
  int i; // r4
  int v8; // r0
  int v9; // r2
  int v10; // r1
  int v11; // r3
  int *v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_117A58 = 1;
  }
  v0 = (int *)off_117A5C;
  v1 = off_117A60;
  v2 = off_117A6C;
  v3 = off_117A70;
  v4 = dword_117A74;
  v5 = (int *)off_117A78;
  ++*(uint32_t *)off_117A5C;
  v1[511] = 0;
  v6 = v2;
  for ( i = 4; i != -1; --i )
  {
    v8 = (uint8_t)i;
    if ( !*((uint8_t *)v6 + 158) && ((v2[52] & 1) == 0 || *((uint8_t *)v2 + 190) != (uint8_t)i) )
    {
      if ( *((uint32_t *)v1 + 84) )
      {
        adv_type_valid((uint8_t)i);
        *(uint32_t *)(dword_117A64 + 4 * i) = *v3 + *(uint32_t *)(v4 + 4 * i);
        *(uint32_t *)off_117A68 = 1 << i;
        v8 = (uint8_t)i;
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(uint32_t *)off_117A58 = 1;
        }
        v9 = *v0;
        v10 = *v0 + 1;
        v11 = (1 << i) | *v5;
        *v0 = v10;
        *v5 = v11;
        if ( v10 )
        {
          v12 = (int *)off_117A58;
          *v0 = v9;
          v13 = *v12;
          if ( !v9 )
          {
            if ( v13 )
              __enable_irq();
          }
        }
      }
      invalid_handler(v8);
    }
    v6 -= 7;
    v1 -= 84;
  }
  if ( *v0 )
  {
    v14 = *v0 - 1;
    v15 = *(uint32_t *)off_117A58;
    *v0 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return irq_disable_global_2(512);
}

