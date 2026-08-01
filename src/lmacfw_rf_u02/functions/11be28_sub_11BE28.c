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

extern uint32_t dword_11BEB4;
extern uint32_t off_11BEB0;
extern uint32_t off_11BEB8;
extern uint32_t off_11BEBC;

// rx_desc_parse @ 0x11be28, size 136 bytes
int  rx_desc_parse(uint8_t *a1)
{
  int v1; // r4
  int result; // r0
  uint8_t *v3; // r5
  int v4; // r6
  int v5; // r7
  int v6; // r1
  int v7; // r3
  int *v8; // r7
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r2

  v1 = *a1;
  v3 = a1 + 2;
  result = *(uint32_t *)(a1 + 2);
  v4 = dword_11BEB4;
  v5 = *((uint32_t *)off_11BEB0 + 10);
  v6 = *((uint32_t *)v3 + 1);
  v7 = dword_11BEB4 + 28 * v1 + 4;
  *(uint32_t *)v7 = result;
  *(uint32_t *)(v7 + 4) = v6;
  *(uint16_t *)(v7 + 8) = *((uint16_t *)v3 + 4);
  if ( v5 == v4 + 28 * v1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11BEB8 = 1;
    }
    v8 = (int *)off_11BEBC;
    ++*(uint32_t *)off_11BEBC;
    mmio_bit16_toggle();
    mmio_regs_init(0, v9, v10, v11);
    if ( *v8 )
    {
      v12 = *v8 - 1;
      v13 = *(uint32_t *)off_11BEB8;
      *v8 = v12;
      if ( !v12 )
      {
        if ( v13 )
          __enable_irq();
      }
    }
    tx_set_power(v3, 0);
    return util_byte_to_hex(*(char *)(v4 + 28 * v1 + 12));
  }
  return result;
}

