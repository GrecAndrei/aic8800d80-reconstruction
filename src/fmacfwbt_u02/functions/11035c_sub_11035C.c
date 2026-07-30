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

extern uint32_t off_110460;
extern uint32_t off_110464;
extern uint32_t off_11048C;
extern uint32_t off_110490;
extern uint32_t off_110468;
extern uint32_t dword_110484;
extern uint32_t off_110480;
extern uint32_t dword_110488;
extern uint32_t off_11046C;
extern uint32_t dword_11047C;
extern uint32_t off_110470;
extern uint32_t dword_110478;
extern uint32_t dword_110474;

// sub_11035C @ 0x11035c, size 258 bytes
// Doc: log_free_dispatch_n500 [util]: Dispatch log buffer free across registered sinks
// log_free_dispatch_n500 [util]: Dispatch log buffer free across registered sinks
int  sub_11035C(int result)
{
  uint32_t *v1; // r4
  unsigned int v2; // r3
  int *v3; // r6
  int **v4; // r9
  uint32_t *v5; // r8
  int v6; // r5
  int *v7; // r7
  int v8; // r10
  int *v9; // r0
  int *v10; // r11
  int v11; // r1
  int v12; // r2
  int16_t v13; // r3
  int v14; // r1
  int v15; // r2
  int v16; // r3

  v1 = off_110460;
  v2 = *(uint16_t *)(result + 28);
  v3 = (int *)off_110464;
  v4 = (int **)off_11048C;
  v5 = off_110490;
  v6 = result;
LABEL_2:
  v7 = (int *)off_110468;
  while ( v2 <= 1 )
  {
    v8 = sub_110238();
    if ( !v8 )
    {
      result = log_printf(dword_110484, *(uint32_t *)off_110480);
      if ( *(uint16_t *)(v6 + 28) > 1u )
        return result;
      return irq_nesting_or(32);
    }
    v9 = (int *)log_free_dispatch_n2b4();
    v10 = v9;
    if ( !v9 )
    {
      log_printf(dword_110488);
      result = sub_110288();
      if ( *(uint16_t *)(v6 + 28) > 1u )
        return result;
      return irq_nesting_or(32);
    }
    *v9 = v8;
    v9[1] = 0;
    v9[2] = 0;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11046C = 1;
    }
    v11 = *v7 + 1;
    *v7 = v11;
    *v1 = 1024;
    while ( (*v1 & 0x800) != 0 )
      ;
    if ( (uint8_t)*v3 )
    {
      v16 = *(uint32_t *)(v6 + 20);
      if ( v16 )
      {
        *(uint32_t *)(v16 + 4) = v9;
      }
      else
      {
        log_printf(dword_11047C);
        v11 = *v7;
      }
    }
    else
    {
      if ( **(int16_t **)off_110470 < 0 && *v4 )
      {
        sub_12F694(dword_110478, dword_110474, 261);
        v11 = *v7;
      }
      *v4 = v10;
    }
    v12 = *v3;
    v13 = *(uint16_t *)(v6 + 28);
    *(uint32_t *)(v6 + 20) = v10;
    v2 = (uint16_t)(v13 + 1);
    result = 1024;
    *(uint16_t *)(v6 + 28) = v2;
    *v3 = (uint8_t)(v12 + 1);
    *v5 = 1024;
    if ( v11 )
    {
      v14 = v11 - 1;
      v15 = *(uint32_t *)off_11046C;
      *v7 = v14;
      if ( !v14 )
      {
        if ( v15 )
        {
          __enable_irq();
          v2 = *(uint16_t *)(v6 + 28);
        }
      }
      goto LABEL_2;
    }
  }
  return result;
}

