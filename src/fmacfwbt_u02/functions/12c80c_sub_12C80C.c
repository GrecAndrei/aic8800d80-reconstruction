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

extern uint32_t off_12C958;
extern uint32_t dword_12C944;
extern uint32_t dword_12C94C;
extern uint32_t dword_12C948;
extern uint32_t dword_12C950;
extern uint32_t off_12C92C;
extern uint32_t off_12C95C;
extern uint32_t off_12C960;
extern uint32_t dword_12C934;
extern uint32_t dword_12C930;
extern uint32_t dword_12C954;
extern uint32_t dword_12C93C;
extern uint32_t off_12C938;
extern uint32_t dword_12C940;

// patch_aware_dispatch @ 0x12c80c, size 288 bytes
int  patch_aware_dispatch(int a1, int a2, unsigned int a3)
{
  int16_t **v3; // r11
  int *v7; // r8
  uint32_t *v8; // r10
  int v9; // r6
  int v10; // r4
  int v11; // r2
  int v12; // r0
  unsigned int v13; // r5
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // r0

  v3 = (int16_t **)off_12C958;
  if ( **(int16_t **)off_12C958 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_12C944 )
        mmio_irq_clear(dword_12C94C, dword_12C948, 148);
    }
    else
    {
      mmio_irq_clear(dword_12C950, dword_12C948, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12C92C = 1;
  }
  v7 = (int *)off_12C95C;
  v8 = off_12C960;
  v9 = *((uint32_t *)off_12C960 + 5);
  ++*(uint32_t *)off_12C95C;
  if ( v9 )
    v9 = *(uint16_t *)(v9 + 4) == a1 && *(uint16_t *)(v9 + 6) == a2;
  v10 = tx_list_foreach(dword_12C934, dword_12C930, a2 | (a1 << 16));
  if ( !v10 )
  {
    v17 = mem_alloc_align(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      mmio_irq_clear(dword_12C954, dword_12C948, 165);
    *(uint16_t *)(v10 + 4) = a1;
    *(uint16_t *)(v10 + 6) = a2;
  }
  v11 = dword_12C93C;
  v12 = dword_12C934;
  v13 = a3 + *((uint32_t *)off_12C938 + 4);
  *(uint32_t *)(v10 + 8) = v13;
  result = list_find(v12, v10, v11);
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = ke_event_lock(dword_12C940, *(uint32_t *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(uint32_t *)off_12C92C, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((uint32_t *)off_12C938 + 4)) < 0 )
      return set_system_flag_1(0x10000000);
  }
  else if ( (int)(v13 - *((uint32_t *)off_12C938 + 4)) < 0 )
  {
    return set_system_flag_1(0x10000000);
  }
  return result;
}

