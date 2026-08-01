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

extern uint32_t off_118C80;
extern uint32_t off_118C70;
extern uint32_t dword_118C74;
extern uint32_t off_118C78;
extern uint32_t dword_118C7C;

// alloc_dma_buf @ 0x118be8, size 134 bytes
uint32_t *alloc_dma_buf()
{
  int *v0; // r8
  int *v1; // r7
  int v2; // r6
  uint32_t *v3; // r5
  uint32_t *result; // r0
  uint32_t *v5; // r4
  int v6; // r3
  int v7; // r2
  void ( *v8)(uint32_t, uint32_t); // r2

  irq_disable_global_3(0x20000);
  v0 = (int *)off_118C80;
  v1 = (int *)off_118C70;
  v2 = dword_118C74;
  v3 = off_118C78;
  while ( 1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v1 = 1;
    }
    ++*v0;
    result = (uint32_t *)list_pop(v2);
    v5 = result;
    if ( *v0 )
    {
      v6 = *v0 - 1;
      v7 = *v1;
      *v0 = v6;
      if ( !v6 )
      {
        if ( v7 )
          __enable_irq();
      }
    }
    if ( !result )
      break;
    v8 = (void ( *)(uint32_t, uint32_t))result[22];
    --v3[126];
    if ( v8 && (v8(result[23], *(uint32_t *)(result[19] + 72)), *((uint8_t *)v5 + 98)) )
    {
      *((uint8_t *)v5 + 98) = 0;
    }
    else if ( !*((uint8_t *)v5 + 96) )
    {
      wlan_ioctl_handler_1(dword_118C7C);
    }
  }
  return result;
}

