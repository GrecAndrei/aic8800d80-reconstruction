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


extern uint32_t off_11421C;
extern uint32_t off_114224;
extern uint32_t off_114228;

// is_current_task @ 0x1141c8, size 82 bytes
int  is_current_task(int a1)
{
  int result; // r0
  int v2; // r2

  if ( a1 == *(uint32_t *)off_11421C )
  {
    v2 = 0;
  }
  else
  {
    if ( a1 != *((uint32_t *)off_11421C + 1) )
    {
      result = event_dispatch("%s, func 0x%x unknown\n", (const char *)a1, *(uint32_t *)off_11421C);
      goto LABEL_4;
    }
    v2 = 1;
  }
  result = event_dispatch("%s, func is %s\n", aUsbTransErrorH, *(const char **)&*((uint8_t *)(uintptr_t)off_114228[0] + (4 * v2)));
LABEL_4:
  if ( BYTE1(((uint32_t *)(uintptr_t)off_114224)[88]) )
    return ke_task_create(1068, 1, 1000 * BYTE2(((uint32_t *)(uintptr_t)off_114224)[88]));
  return result;
}
