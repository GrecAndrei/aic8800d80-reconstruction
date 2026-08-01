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

extern uint32_t dword_12ACFC;
extern uint32_t off_12ACF8;
extern uint32_t dword_12AD04;
extern uint32_t dword_12AD00;

// unknown_check @ 0x12ac98, size 94 bytes
int  unknown_check(int result, int a2)
{
  switch ( a2 )
  {
    case 2:
      result = dword_12ACFC + 140 * result;
      *(uint8_t *)(result + 132) = 0;
      break;
    case 3:
      result = dword_12ACFC + 140 * result;
      if ( !*(uint8_t *)(result + 132) )
        return (int)ke_queue_front(*(uint8_t *)(result + 113), 1);
      break;
    case 1:
      result = dword_12ACFC + 140 * result;
      *(uint8_t *)(result + 132) = 1;
      break;
    default:
      if ( **(int16_t **)off_12ACF8 < 0 )
        return mmio_clear_register(dword_12AD04, dword_12AD00, 1898);
      break;
  }
  return result;
}

