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

extern uint32_t off_136230;
extern uint32_t dword_136238;
extern uint32_t dword_136234;

// lmac_ps_state_check @ 0x1361fc, size 52 bytes
// Doc: lmac_ps_state_check [mac]: Check LMAC power-save state via signed halfword
// lmac_ps_state_check [mac]: Check LMAC power-save state via signed halfword
int  lmac_ps_state_check(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_136230 >= 0 || (value = msg_get_value(7u), value == 3) )
  {
    sub_136820(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_136238, dword_136234, 415);
    sub_136820(v2);
    return 0;
  }
}

