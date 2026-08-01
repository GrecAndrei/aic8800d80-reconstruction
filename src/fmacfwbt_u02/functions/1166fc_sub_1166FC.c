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

extern uint32_t off_116754;
extern uint32_t off_116758;
extern uint32_t dword_116760;
extern uint32_t dword_11675C;

// switch_rf_path @ 0x1166fc, size 88 bytes
int  switch_rf_path(int result)
{
  switch ( result )
  {
    case 0:
      *(uint32_t *)off_116754 = 2;
      break;
    case 1:
      *(uint32_t *)off_116754 = 4;
      break;
    case 2:
      *(uint32_t *)off_116754 = 8;
      break;
    case 3:
      *(uint32_t *)off_116754 = 16;
      break;
    case 4:
      *(uint32_t *)off_116754 = 1;
      break;
    case 5:
      *(uint32_t *)off_116754 = 32;
      break;
    default:
      if ( **(int16_t **)off_116758 < 0 )
        result = mmio_irq_clear(dword_116760, dword_11675C, 944);
      break;
  }
  return result;
}

