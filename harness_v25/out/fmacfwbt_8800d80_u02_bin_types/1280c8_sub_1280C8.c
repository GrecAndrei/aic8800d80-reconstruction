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

extern uint32_t dword_128154;
extern uint32_t off_128150;
extern uint32_t off_128158;
extern uint32_t off_12815C;

// sub_1280C8 @ 0x1280c8, size 136 bytes
int  sub_1280C8(uint8_t *a1)
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
  v4 = dword_128154;
  v5 = *((uint32_t *)off_128150 + 10);
  v6 = *((uint32_t *)v3 + 1);
  v7 = dword_128154 + 28 * v1 + 4;
  *(uint32_t *)v7 = result;
  *(uint32_t *)(v7 + 4) = v6;
  *(uint16_t *)(v7 + 8) = *((uint16_t *)v3 + 4);
  if ( v5 == v4 + 28 * v1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_128158 = 1;
    }
    v8 = (int *)off_12815C;
    ++*(uint32_t *)off_12815C;
    mmio_set_clear_bits();
    sub_11DEB0(0);
    if ( *v8 )
    {
      v9 = *v8 - 1;
      v10 = *(uint32_t *)off_128158;
      *v8 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    sub_102898((uint16_t *)v3, 0);
    return bt_hci_cmd_build_n6ac(*(char *)(v4 + 28 * v1 + 12));
  }
  return result;
}

