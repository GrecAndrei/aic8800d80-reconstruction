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

// lld_evt_time_get @ 0x123900, size 32 bytes
// Doc: sub_1223900 [unknown]: Wrapper invoking helper with opcode 0x6e and saved args
// sub_1223900 [unknown]: Wrapper invoking helper with opcode 0x6e and saved args
int  lld_evt_time_get(int a1, uint8_t *a2, int a3, int a4)
{
  set_short_address(a2);
  ke_msg_send_no_param(110, a4, a3);
  return 0;
}

