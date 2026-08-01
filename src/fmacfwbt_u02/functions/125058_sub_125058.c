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

extern uint32_t off_1250B8;
extern uint32_t off_1250BC;
extern uint32_t off_1250C0;
extern uint32_t off_1250C4;

// ke_event_set_lock @ 0x125058, size 96 bytes
int  ke_event_set_lock(int a1)
{
  int *v1; // r4
  void *v2; // r5
  int v3; // zf
  int result; // r0
  int v5; // r3
  int v6; // r2
  uint32_t *v7; // r3
  int v8; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1250B8 = 1;
  }
  v1 = (int *)off_1250BC;
  v2 = off_1250C0;
  v3 = *(uint32_t *)off_1250C0 == a1;
  ++*(uint32_t *)off_1250BC;
  if ( v3 )
  {
    result = list_pop_front(v2);
    v7 = off_1250C4;
    if ( *(uint32_t *)v2 )
    {
      v8 = *(uint32_t *)(*(uint32_t *)v2 + 12);
      result = 0x40000;
      *((uint32_t *)off_1250C4 + 2) = 0x40000;
      v7[12] = v8;
      v7[2] = 4;
    }
    else
    {
      *((uint32_t *)off_1250C4 + 2) = 1024;
    }
  }
  else
  {
    result = check_abort_flag_3(v2, a1);
  }
  if ( *v1 )
  {
    v5 = *v1 - 1;
    v6 = *(uint32_t *)off_1250B8;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

