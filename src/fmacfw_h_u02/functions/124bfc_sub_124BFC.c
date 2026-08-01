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

extern uint32_t off_124CD0;
extern uint32_t off_124CD4;
extern uint32_t off_124CD8;
extern uint32_t dword_124CE4;
extern uint32_t off_124CE8;
extern uint32_t dword_124CF0;
extern uint32_t dword_124CEC;
extern uint32_t off_124CDC;
extern uint32_t dword_124CE0;

// mem_copy_util @ 0x124bfc, size 212 bytes
int  mem_copy_util(int a1, int a2)
{
  int *v4; // r7
  uint32_t *v5; // r2
  int *v6; // r6
  int v7; // r2
  int result; // r0
  int v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r2
  uint32_t *v13; // r2
  int v14; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_124CD0 = 1;
  }
  v4 = (int *)off_124CD4;
  v5 = off_124CD8;
  ++*(uint32_t *)off_124CD4;
  if ( a2 - v5[4] < 0 )
  {
    alloc_tx_event(dword_124CE4, *(uint32_t *)(a1 + 4), a2);
    if ( **(int16_t **)off_124CE8 < 0 )
      irq_disable_mmio_write(dword_124CF0, dword_124CEC, 131);
  }
  v6 = (int *)off_124CDC;
  if ( a1 == *(uint32_t *)off_124CDC )
  {
    list_pop(off_124CDC);
    v12 = dword_124CE0;
    *(uint32_t *)(a1 + 12) = a2;
    result = list_foreach(v6, a1, v12);
    v9 = *v6;
    if ( !*v6 )
    {
      *((uint32_t *)off_124CD8 + 2) = 1024;
      goto LABEL_6;
    }
    goto LABEL_14;
  }
  wlan_ioctl_handler_3(off_124CDC, a1);
  v7 = dword_124CE0;
  *(uint32_t *)(a1 + 12) = a2;
  result = list_foreach(v6, a1, v7);
  v9 = *v6;
  if ( a1 == *v6 )
  {
LABEL_14:
    v13 = off_124CD8;
    v14 = *(uint32_t *)(v9 + 12);
    result = 0x40000;
    *((uint32_t *)off_124CD8 + 2) = 0x40000;
    v13[12] = v14;
    v13[2] = 4;
  }
LABEL_6:
  if ( *v4 && (v10 = *v4 - 1, v11 = *(uint32_t *)off_124CD0, (*v4 = v10) == 0) && v11 )
  {
    __enable_irq();
    if ( a2 - *((uint32_t *)off_124CD8 + 4) < 0 )
      return irq_disable_global_2(0x20000000);
  }
  else if ( a2 - *((uint32_t *)off_124CD8 + 4) < 0 )
  {
    return irq_disable_global_2(0x20000000);
  }
  return result;
}

