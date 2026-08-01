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

extern uint32_t dword_1177D8;
extern uint32_t off_1177D4;
extern uint32_t off_1177E0;
extern uint32_t off_1177DC;

// radio_isr @ 0x117788, size 76 bytes
unsigned int radio_isr()
{
  int v0; // r4
  unsigned int result; // r0

  v0 = dword_1177D8 & *(uint32_t *)off_1177D4;
  if ( (*(uint32_t *)off_1177D4 & 0x10) != 0 )
  {
    if ( (*(uint32_t *)off_1177D4 & 0x1000) != 0 )
    {
      v0 |= 0x1000u;
      *((uint32_t *)off_1177E0 + 52) |= 4u;
    }
    run_with_busy_flag();
  }
  result = v0 & 0xF00000;
  if ( (v0 & 0xF00000) != 0 )
    result = rf_command_handler((uint8_t)(11 - __clz(result)));
  *(uint32_t *)off_1177DC = v0;
  return result;
}

