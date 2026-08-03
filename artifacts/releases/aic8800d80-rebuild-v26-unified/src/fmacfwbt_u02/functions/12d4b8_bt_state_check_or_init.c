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

extern uint32_t off_12D4EC;
extern uint32_t dword_12D4F4;
extern uint32_t dword_12D4F0;

// bt_state_check_or_init @ 0x12d4b8, size 52 bytes
// Doc: bt_state_check_or_init [bt]: Check signed BT state word and branch, saving args for handler
// bt_state_check_or_init [bt]: Check signed BT state word and branch, saving args for handler
int  bt_state_check_or_init(int result, uint32_t *a2)
{
  uint32_t *v2; // r5

  v2 = (uint32_t *)result;
  if ( **(int16_t **)off_12D4EC < 0 && !a2 )
    result = sub_12F694(dword_12D4F4, dword_12D4F0, 95);
  if ( *v2 )
  {
    *a2 = *v2;
  }
  else
  {
    v2[1] = a2;
    *a2 = 0;
  }
  *v2 = a2;
  return result;
}

