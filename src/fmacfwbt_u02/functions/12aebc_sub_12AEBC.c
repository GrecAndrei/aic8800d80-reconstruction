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

extern uint32_t dword_12AF20;
extern uint32_t off_12AF1C;
extern uint32_t dword_12AF28;
extern uint32_t dword_12AF24;

// bt_control_dispatch @ 0x12aebc, size 94 bytes
int  bt_control_dispatch(int result, int a2)
{
  switch ( a2 )
  {
    case 2:
      result = dword_12AF20 + 140 * result;
      *(uint8_t *)(result + 132) = 0;
      break;
    case 3:
      result = dword_12AF20 + 140 * result;
      if ( !*(uint8_t *)(result + 132) )
        return (int)set_flag_byte(*(uint8_t *)(result + 113), 1);
      break;
    case 1:
      result = dword_12AF20 + 140 * result;
      *(uint8_t *)(result + 132) = 1;
      break;
    default:
      if ( **(int16_t **)off_12AF1C < 0 )
        return mmio_irq_clear(dword_12AF28, dword_12AF24, 1898);
      break;
  }
  return result;
}

