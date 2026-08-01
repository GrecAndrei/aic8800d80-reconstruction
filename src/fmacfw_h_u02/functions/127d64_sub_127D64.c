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

extern uint32_t dword_127DF0;
extern uint32_t off_127DEC;
extern uint32_t off_127DF4;
extern uint32_t off_127DF8;

// cfm_mac_info @ 0x127d64, size 136 bytes
int  cfm_mac_info(uint8_t *a1)
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
  v4 = dword_127DF0;
  v5 = *((uint32_t *)off_127DEC + 10);
  v6 = *((uint32_t *)v3 + 1);
  v7 = dword_127DF0 + 28 * v1 + 4;
  *(uint32_t *)v7 = result;
  *(uint32_t *)(v7 + 4) = v6;
  *(uint16_t *)(v7 + 8) = *((uint16_t *)v3 + 4);
  if ( v5 == v4 + 28 * v1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_127DF4 = 1;
    }
    v8 = (int *)off_127DF8;
    ++*(uint32_t *)off_127DF8;
    disable_watchdog();
    dma_ring_init(0);
    if ( *v8 )
    {
      v9 = *v8 - 1;
      v10 = *(uint32_t *)off_127DF4;
      *v8 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    check_boot_flag((uint16_t *)v3, 0);
    return call_stack_helper(*(char *)(v4 + 28 * v1 + 12));
  }
  return result;
}

