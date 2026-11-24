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


extern uint32_t off_11481C;

// wait_for_value @ 0x1147bc, size 94 bytes
unsigned int  wait_for_value(char *a1, unsigned int a2)
{
  int v4; // r0
  void *v5; // r7
  char *v6; // r6

  v4 = dispatch_by_cmd((uint8_t *)a1);
  if ( v4 < 0 )
  {
    ke_event_schedule_1("err type:%x\n", (uint8_t)*a1);
    return a2;
  }
  else if ( v4 == a2 )
  {
    v5 = off_11481C;
    if ( *((uint32_t *)off_11481C + 2) )
    {
      v6 = (char *)lock_acquire();
      memcpy_aligned(v6 + 4, a1, a2);
      check_abort_flag((int)v5 + 16, v6);
      set_system_flag_1(16);
    }
    else
    {
      ke_event_schedule_1(aErrNoFreeCom, v4);
    }
    return a2;
  }
  else
  {
    ke_event_schedule_1("err len:%d,%d\n", v4, a2);
    return a2;
  }
}
