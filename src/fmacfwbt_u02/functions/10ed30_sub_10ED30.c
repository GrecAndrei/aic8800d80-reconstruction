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

extern uint32_t dword_10ED64;
extern uint32_t dword_10ED60;
extern uint32_t dword_10ED68;

// periph_field_set @ 0x10ed30, size 46 bytes
int  periph_field_set(int a1)
{
  atomic_reg_write(dword_10ED64, 196608, dword_10ED60, 1);
  atomic_reg_read_alt(dword_10ED68, a1 << 15, 1);
  return atomic_reg_write(1879048192, 1, 1, 1);
}

