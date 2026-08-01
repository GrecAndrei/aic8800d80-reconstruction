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

extern uint32_t dword_127F30;
extern uint32_t off_127F2C;
extern uint32_t off_127F34;
extern uint32_t off_127F38;

// rx_parse_header @ 0x127ea4, size 136 bytes
int  rx_parse_header(uint8_t *a1)
{
  int v1; // r4
  int result; // r0
  uint8_t *v3; // r5
  int v4; // r6
  int v5; // r7
  int v6; // r1
  int v7; // r3
  int *v8; // r7
  int v9; // r3
  int v10; // r2

  v1 = *a1;
  v3 = a1 + 2;
  result = *(uint32_t *)(a1 + 2);
  v4 = dword_127F30;
  v5 = *((uint32_t *)off_127F2C + 10);
  v6 = *((uint32_t *)v3 + 1);
  v7 = dword_127F30 + 28 * v1 + 4;
  *(uint32_t *)v7 = result;
  *(uint32_t *)(v7 + 4) = v6;
  *(uint16_t *)(v7 + 8) = *((uint16_t *)v3 + 4);
  if ( v5 == v4 + 28 * v1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_127F34 = 1;
    }
    v8 = (int *)off_127F38;
    ++*(uint32_t *)off_127F38;
    rf_ctrl_enable();
    radio_init(0);
    if ( *v8 )
    {
      v9 = *v8 - 1;
      v10 = *(uint32_t *)off_127F34;
      *v8 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    rf_enable((uint16_t *)v3, 0);
    return util_format(*(char *)(v4 + 28 * v1 + 12));
  }
  return result;
}

