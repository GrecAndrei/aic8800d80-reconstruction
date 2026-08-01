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

extern uint32_t off_1426AC;
extern uint32_t dword_1426B4;
extern uint32_t dword_1426B0;

// softfloat_double_op @ 0x142670, size 58 bytes
int  softfloat_double_op(int a1, unsigned int a2)
{
  if ( **(int16_t **)off_1426AC < 0 && *(uint8_t *)(a2 + 8) == 255 )
    mmio_irq_clear(dword_1426B4, dword_1426B0, 50);
  if ( (*(uint16_t *)(a2 + 2) & 0xFC) == 0xD0 )
    parse_ll_control(a2);
  return 0;
}

