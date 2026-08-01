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

extern uint32_t off_113748;
extern uint32_t dword_11375C;
extern uint32_t dword_113758;
extern uint32_t dword_11374C;
extern uint32_t off_113750;

// lookup_task_id @ 0x1136f4, size 82 bytes
int  lookup_task_id(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( a1 == *(uint32_t *)off_113748 || a1 == *((uint32_t *)off_113748 + 1) )
    result = dispatch_event_handler(dword_11375C, dword_113758);
  else
    result = dispatch_event_handler(dword_11374C, a1);
  if ( *((uint8_t *)off_113750 + 353) )
    return ke_event_loop(1068, 1, 1000 * *((uint8_t *)off_113750 + 354), a4);
  return result;
}

