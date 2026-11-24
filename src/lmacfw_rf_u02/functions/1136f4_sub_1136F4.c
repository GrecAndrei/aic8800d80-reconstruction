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
extern uint32_t off_113750;
extern uint32_t off_113754;

// lookup_task_id @ 0x1136f4, size 82 bytes
int  lookup_task_id(int a1)
{
  int result; // r0
  int v2; // r2

  if ( a1 == *(uint32_t *)off_113748 )
  {
    v2 = 0;
  }
  else
  {
    if ( a1 != *((uint32_t *)off_113748 + 1) )
    {
      result = dispatch_event_handler_1("%s, func 0x%x unknown\n", (const char *)a1, *(uint32_t *)off_113748);
      goto LABEL_4;
    }
    v2 = 1;
  }
  result = dispatch_event_handler_1("%s, func is %s\n", aUsbTransErrorH, *(const char **)(off_113754 + 4 * v2));
LABEL_4:
  if ( *((uint8_t *)off_113750 + 353) )
    return ke_event_loop(1068, 1, 1000 * *((uint8_t *)off_113750 + 354));
  return result;
}
