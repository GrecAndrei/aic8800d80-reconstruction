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

extern uint32_t off_10D2B0;
extern uint32_t off_10D2B8;
extern uint32_t dword_10D2C0;
extern uint32_t dword_10D2BC;
extern uint32_t off_10D2B4;

// set_radio_mode @ 0x10d26c, size 66 bytes
int  set_radio_mode(int result)
{
  if ( result == 1 )
  {
    *(uint32_t *)off_10D2B0 = 0x40000;
  }
  else if ( result == 2 )
  {
    *(uint32_t *)off_10D2B0 = 0x80000;
  }
  else if ( **(int16_t **)off_10D2B8 < 0 )
  {
    result = irq_disable_mmio_write(dword_10D2C0, dword_10D2BC, 2118);
  }
  *((uint32_t *)off_10D2B4 + 1) |= 0x400000u;
  return result;
}

