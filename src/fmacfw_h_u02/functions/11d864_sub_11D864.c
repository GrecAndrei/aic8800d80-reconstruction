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

extern uint32_t off_11D918;
extern uint32_t off_11D91C;
extern uint32_t off_11D928;
extern uint32_t off_11D92C;
extern uint32_t off_11D920;
extern uint32_t dword_11D924;

// dma_ring_alloc_2 @ 0x11d864, size 180 bytes
int dma_ring_alloc_2()
{
  int *v0; // r6
  int v1; // r4
  int result; // r0
  uint16_t *v3; // r5
  int *v4; // r8
  int *v5; // r9
  char v6; // r2
  void ( *v7)(uint32_t); // r3
  int v8; // r3
  int v9; // r2
  uint8_t *v10; // r4

  v0 = (int *)off_11D918;
  v1 = *(uint32_t *)off_11D918;
  result = irq_disable_global_3(0x200000);
  if ( v1 )
  {
    v3 = off_11D91C;
    if ( *(uint16_t *)off_11D91C )
    {
      v4 = (int *)off_11D928;
      v5 = (int *)off_11D92C;
      do
      {
        if ( (*(uint8_t *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        list_pop(v0);
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *v4 = 1;
        }
        v6 = *(uint8_t *)(v1 + 16);
        ++*v5;
        if ( (v6 & 1) == 0 )
          --*v3;
        v7 = *(void ( **)(uint32_t))(v1 + 4);
        *(uint8_t *)(v1 + 16) = 0;
        if ( v7 )
          v7(*(uint32_t *)(v1 + 8));
        result = *(uint32_t *)(v1 + 12);
        if ( result )
          result = phy_rate_get();
        if ( *v5 )
        {
          v8 = *v5 - 1;
          v9 = *v4;
          *v5 = v8;
          if ( !v8 )
          {
            if ( v9 )
              __enable_irq();
          }
        }
        v1 = *v0;
      }
      while ( *v0 );
      v10 = off_11D920;
      if ( *((uint8_t *)off_11D920 + 69) )
      {
        irq_disable_global_2(0x80000);
        result = check_feature_flag(1024, dword_11D924);
        v10[69] = 0;
      }
    }
  }
  return result;
}

