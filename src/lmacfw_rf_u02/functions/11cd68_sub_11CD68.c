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


extern uint32_t off_11CDA0;
extern uint32_t off_11CDA4;
extern uint32_t off_11CDA8;

// rf_read_rssi @ 0x11cd68, size 56 bytes
int rf_read_rssi()
{
  int result; // r0

  if ( **(uint16_t **)off_11CDA0 < 0 && *(uint32_t *)off_11CDA8 << 28 )
    return ke_int_lock_1((int)aNxmacCurrentSt, (int)aHalMachwIdleIr, 105);
  if ( (*(uint32_t *)off_11CDA4 & 0x80) != 0 )
  {
    *(uint32_t *)off_11CDA4 &= ~0x80u;
    return set_busy_flag_alt(0x2000000);
  }
  return result;
}
