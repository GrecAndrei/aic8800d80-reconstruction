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

extern uint32_t dword_10ED1C;
extern uint32_t dword_10ED24;
extern uint32_t dword_10ED20;
extern uint32_t dword_10ED28;
extern uint32_t dword_10ED2C;

// periph_trigger_write @ 0x10ecd8, size 66 bytes
int  periph_trigger_write(int a1, int a2, int a3)
{
  ke_event_schedule(dword_10ED1C, a1, a3);
  atomic_reg_write(dword_10ED24, 196608, dword_10ED20, 1);
  atomic_reg_write(1879048192, 1, 1, 1);
  atomic_reg_read_alt(dword_10ED28, a1, 1);
  return atomic_reg_write(dword_10ED2C, 2, 2, 1);
}

