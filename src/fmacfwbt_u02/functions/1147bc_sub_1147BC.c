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

extern uint32_t dword_114828;
extern uint32_t off_11481C;
extern uint32_t dword_114824;
extern uint32_t dword_114820;

// wait_for_value @ 0x1147bc, size 94 bytes
// Doc: sub_12147BC [bt]: BT helper invoked after a sub-routine with result branch
// sub_12147BC [bt]: BT helper invoked after a sub-routine with result branch
int  wait_for_value(uint8_t *a1, int a2)
{
  int v4; // r0
  int v5; // r2
  char *v6; // r7
  int v7; // r0

  v4 = dispatch_by_cmd(a1);
  if ( v4 < 0 )
  {
    ke_event_schedule(dword_114828, *a1, v5);
    return a2;
  }
  else if ( v4 == a2 )
  {
    v6 = (char *)off_11481C;
    if ( *((uint32_t *)off_11481C + 2) )
    {
      v7 = lock_acquire();
      memcpy_aligned(v7 + 4, a1, a2);
      check_abort_flag(v6 + 16);
      set_system_flag_1(16);
    }
    else
    {
      ke_event_schedule(dword_114824, v4, v5);
    }
    return a2;
  }
  else
  {
    ke_event_schedule(dword_114820, v4, a2);
    return a2;
  }
}

