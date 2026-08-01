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

extern uint32_t dword_12ABBC;
extern uint32_t off_12ABB8;
extern uint32_t dword_12ABC4;
extern uint32_t dword_12ABC0;

// is_state_arg_valid @ 0x12ab58, size 94 bytes
int  is_state_arg_valid(int result, int a2)
{
  switch ( a2 )
  {
    case 2:
      result = dword_12ABBC + 140 * result;
      *(uint8_t *)(result + 132) = 0;
      break;
    case 3:
      result = dword_12ABBC + 140 * result;
      if ( !*(uint8_t *)(result + 132) )
        return (int)util_get_state(*(uint8_t *)(result + 113), 1);
      break;
    case 1:
      result = dword_12ABBC + 140 * result;
      *(uint8_t *)(result + 132) = 1;
      break;
    default:
      if ( **(int16_t **)off_12ABB8 < 0 )
        return irq_disable_mmio_write(dword_12ABC4, dword_12ABC0, 1898);
      break;
  }
  return result;
}

