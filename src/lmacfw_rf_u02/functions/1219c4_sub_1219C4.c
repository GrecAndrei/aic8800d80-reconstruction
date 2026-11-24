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


extern uint32_t off_1219E8;
extern uint32_t off_1219F0;

// flash_ctrl_init @ 0x1219c4, size 36 bytes
int  flash_ctrl_init(int a1, int a2, int a3)
{
  int result; // r0

  __disable_irq();
  *(uint32_t *)off_1219E8 = 0;
  result = dispatch_event_handler_1("\x9BASSERT (%s) at %s:%d\n", (const char *)a1, (const char *)a2, a3 & 0xFFFFF);
  while ( *off_1219F0 )
    ;
  return result;
}
