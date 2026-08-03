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

extern uint32_t dword_122058;

// sub_122034 @ 0x122034, size 36 bytes
// Doc: fw_state_get_1222036 [util]: FW state getter, reads from 0x16899c control block
// fw_state_get_1222036 [util]: FW state getter, reads from 0x16899c control block
int  sub_122034(int result, int a2)
{
  int v2; // r4

  v2 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(uint8_t *)(result + 128) = 0;
  }
  else
  {
    feature_guard_check(1024, dword_122058);
    return send_msg_to_host_c43(v2);
  }
  return result;
}

