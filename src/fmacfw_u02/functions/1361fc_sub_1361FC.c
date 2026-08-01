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

// patch_check_loaded @ 0x1361fc, size 52 bytes
int  patch_check_loaded(int a1)
{
  int v2; // r0

  if ( **(int16_t **)off_136230 >= 0 || (a1 = rx_rate_field_parse(7u), a1 == 3) )
  {
    bt_ready_check(a1);
    return 0;
  }
  else
  {
    v2 = mmio_clear_register(dword_136238, dword_136234, 415);
    bt_ready_check(v2);
    return 0;
  }
}

