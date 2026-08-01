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

extern uint32_t off_11ED40;
extern uint32_t off_11ED44;
extern uint32_t off_11ED48;
extern uint32_t off_11ED4C;
extern uint32_t off_11ED50;
extern uint32_t off_11ED54;

// hci_uart_dma_rx_start @ 0x11ecb8, size 134 bytes
// Doc: sub_121ECB8 [ipc]: Initializes shared buffer pointers and calls allocator
// sub_121ECB8 [ipc]: Initializes shared buffer pointers and calls allocator
int hci_uart_dma_rx_start()
{
  uint32_t *v0; // r4
  int *v1; // r5
  int v2; // r1
  int v3; // r2
  uint32_t *v4; // r3
  int v5; // r1
  int result; // r0
  int v7; // r2
  uint32_t *v8; // r2
  uint32_t *v9; // r3
  uint32_t _0[10]; // [sp+0h] [bp-18h] BYREF

  unknown_func_12d14c(16);
  v0 = off_11ED40;
  v1 = (int *)off_11ED44;
  v2 = 0;
  while ( (*v0 & 8) == 0 )
  {
    v3 = *v1;
    *v0 |= 1u;
    if ( v3 )
    {
      v9 = &_0[v2 + 6];
      v2 = (uint8_t)(v2 + 1);
      *(v9 - 6) = v3;
      if ( v2 == 4 || (*v0 & 8) != 0 )
      {
        _0[4] = 0;
        _0[5] = v2;
        hci_vendor_cmd_send((int)_0);
        v2 = 0;
      }
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11ED48 = 1;
  }
  v4 = off_11ED4C;
  v5 = *(uint32_t *)off_11ED4C;
  result = *(uint8_t *)off_11ED50;
  v7 = *(uint32_t *)off_11ED4C + 1;
  *(uint32_t *)off_11ED4C = v7;
  if ( result )
  {
    result = *(uint32_t *)off_11ED54 | 0x1000;
    *(uint32_t *)off_11ED54 = result;
  }
  if ( v7 )
  {
    v8 = off_11ED48;
    *v4 = v5;
    if ( !v5 )
    {
      if ( *v8 )
        __enable_irq();
    }
  }
  return result;
}

