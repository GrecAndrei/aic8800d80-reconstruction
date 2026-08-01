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

extern uint32_t dword_117D58;
extern uint32_t off_117D54;
extern uint32_t off_117D60;
extern uint32_t off_117D5C;

// rf_irq_status @ 0x117d08, size 76 bytes
// Doc: rf_irq_status [mmio]: Read-modify MMIO register 0x40328078 with mask 0xf0001f
// rf_irq_status [mmio]: Read-modify MMIO register 0x40328078 with mask 0xf0001f
unsigned int rf_irq_status()
{
  int v0; // r4
  unsigned int result; // r0

  v0 = dword_117D58 & *(uint32_t *)off_117D54;
  if ( (*(uint32_t *)off_117D54 & 0x10) != 0 )
  {
    if ( (*(uint32_t *)off_117D54 & 0x1000) != 0 )
    {
      v0 |= 0x1000u;
      *((uint32_t *)off_117D60 + 52) |= 4u;
    }
    global_flag_set();
  }
  result = v0 & 0xF00000;
  if ( (v0 & 0xF00000) != 0 )
    result = get_84_entry((uint8_t)(11 - __clz(result)));
  *(uint32_t *)off_117D5C = v0;
  return result;
}

