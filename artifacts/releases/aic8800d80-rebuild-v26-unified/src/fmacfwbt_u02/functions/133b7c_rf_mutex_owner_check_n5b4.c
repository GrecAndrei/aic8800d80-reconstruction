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

extern uint32_t off_133BD8;
extern uint32_t dword_133BE0;
extern uint32_t dword_133BDC;

// rf_mutex_owner_check_n5b4 @ 0x133b7c, size 90 bytes
// Doc: rf_mutex_owner_check_n5b4 [rf]: Check current mutex/bus owner field before access
// rf_mutex_owner_check_n5b4 [rf]: Check current mutex/bus owner field before access
int rf_mutex_owner_check_n5b4()
{
  int value; // r0

  if ( **(int16_t **)off_133BD8 < 0 && msg_get_value(6u) != 4 && msg_get_value(6u) && msg_get_value(6u) != 10 )
    sub_12F694(dword_133BE0, dword_133BDC, 636);
  value = msg_get_value(6u);
  if ( value != 4 )
  {
    value = msg_get_value(6u);
    if ( value != 10 )
      return 0;
  }
  sub_1349D8(value);
  return 0;
}

