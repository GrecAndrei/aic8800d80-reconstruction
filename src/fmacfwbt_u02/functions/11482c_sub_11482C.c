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


extern uint32_t off_114874;

// malloc_from_heap @ 0x11482c, size 70 bytes
uint32_t * malloc_from_heap(int a1)
{
  int *v1; // r4
  uint32_t *result; // r0
  int v3; // r2
  int v4; // r5
  int v5; // r1
  int v6; // r2
  int v7; // r0

  v1 = (int *)off_114874;
  result = jump_to_tx_entry((char *)(a1 - 16));
  v3 = *v1;
  if ( *v1 )
  {
    v4 = v3 + 4;
    v5 = dispatch_by_cmd((uint8_t *)(v3 + 4));
    if ( v5 < 0 )
    {
      return (uint32_t *)ke_event_schedule_1("err typ:%x\n", *(uint8_t *)(v6 + 4));
    }
    else
    {
      v7 = sys_control(v4, v5);
      if ( v7 )
        return (uint32_t *)ke_event_schedule_1("MB send err %d\n", v7);
      else
        return list_pop_front((int)v1);
    }
  }
  return result;
}
