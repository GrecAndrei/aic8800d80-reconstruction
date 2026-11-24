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


extern uint32_t off_11E7A0;

// check_kernel_state_alt @ 0x11e76c, size 52 bytes
int  check_kernel_state_alt(int result, uint32_t *a2)
{
  uint32_t *v2; // r5

  v2 = (uint32_t *)result;
  if ( **(uint16_t **)off_11E7A0 < 0 && !a2 )
    result = flash_ctrl_init((int)aListHdrNull, (int)aCoListPushFron, 95);
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
