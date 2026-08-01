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
extern uint32_t dword_114220;
extern uint32_t dword_114230;
extern uint32_t dword_11422C;
extern uint32_t dword_114228;
extern uint32_t off_114224;

// is_current_task @ 0x1141c8, size 82 bytes
// Doc: is_current_task [rf]: Log RF message rate if counter changed
// is_current_task [rf]: Log RF message rate if counter changed
int  is_current_task(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // r2

  if ( a1 == *(uint32_t *)off_11421C )
  {
    v5 = 0;
  }
  else
  {
    if ( a1 != *((uint32_t *)off_11421C + 1) )
    {
      result = event_dispatch(dword_114220, a1, *(uint32_t *)off_11421C);
      goto LABEL_4;
    }
    v5 = 1;
  }
  result = event_dispatch(dword_114230, dword_11422C, *(uint32_t *)(dword_114228 + 4 * v5));
LABEL_4:
  if ( *((uint8_t *)off_114224 + 353) )
    return ke_task_create(1068, 1, 1000 * *((uint8_t *)off_114224 + 354), a4);
  return result;
}

