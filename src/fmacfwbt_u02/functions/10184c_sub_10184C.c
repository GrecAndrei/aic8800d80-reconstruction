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

extern uint32_t off_101860;
extern uint32_t dword_101868;
extern uint32_t dword_101864;

// sys_irq_dispatch @ 0x10184c, size 18 bytes
int  sys_irq_dispatch(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(uint32_t *)off_101860 << 28 )
    return ke_event_schedule(dword_101868, dword_101864, a3);
  return result;
}

