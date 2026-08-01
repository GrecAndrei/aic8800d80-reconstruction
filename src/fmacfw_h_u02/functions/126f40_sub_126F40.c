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

extern uint32_t off_126F6C;
extern uint32_t off_126F70;

// llc_state_get @ 0x126f40, size 44 bytes
int llc_state_get()
{
  char v0; // r3
  int result; // r0

  if ( *((uint8_t *)off_126F6C + 89) )
  {
    v0 = *((uint8_t *)off_126F6C + 89) - 1;
    *((uint8_t *)off_126F6C + 89) = v0;
    if ( !v0 && *(uint8_t *)off_126F70 == 1 )
    {
      *(uint8_t *)off_126F70 = 0;
      ke_evt_handler();
      return llc_flag_test_bit3();
    }
  }
  return result;
}

