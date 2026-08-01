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

extern uint32_t off_12F908;
extern uint32_t dword_12F910;
extern uint32_t dword_12F914;
extern uint32_t off_12F90C;

// rx_packet_process @ 0x12f878, size 144 bytes
// Doc: sub_122F878 [unknown]: Unknown function in fmacfwbt firmware
// sub_122F878 [unknown]: Unknown function in fmacfwbt firmware
unsigned int  rx_packet_process(unsigned int a1, int a2, int a3)
{
  unsigned int v3; // r7
  int *v4; // r5
  uint8_t *v8; // r9
  int v9; // r3
  int v10; // r8
  uint8_t *v11; // r4
  uint8_t *v12; // r6
  int v13; // t1

  v3 = a2 - 1;
  if ( *(uint8_t *)(a2 - 1) == 9 )
  {
    v4 = (int *)off_12F908;
    if ( a3 < *(uint32_t *)off_12F908 )
    {
      v8 = (uint8_t *)dword_12F910;
      do
      {
        uart_puts(v8);
        v9 = *v4 - 1;
        *v4 = v9;
      }
      while ( v9 > a3 );
    }
    if ( v3 > a1 )
    {
      v10 = dword_12F914;
      v11 = (uint8_t *)(a1 - 1);
      v12 = (uint8_t *)(a2 - 2);
      do
      {
        while ( 1 )
        {
          v13 = *++v11;
          if ( v13 == 9 )
            break;
          ++*v4;
          uart_putc(*v11);
          if ( v11 == v12 )
            goto LABEL_10;
        }
        uart_puts((uint8_t *)((*v4 & 7) + v10));
        *v4 = (*v4 & 0xFFFFFFF8) + 8;
      }
      while ( v11 != v12 );
    }
  }
  else
  {
    uart_puts((uint8_t *)dword_12F910);
    --*(uint32_t *)off_12F908;
  }
LABEL_10:
  --*(uint32_t *)off_12F90C;
  return v3;
}

