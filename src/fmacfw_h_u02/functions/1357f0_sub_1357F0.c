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

// ke_msg_send_1 @ 0x1357f0, size 46 bytes
int  ke_msg_send_1(int a1)
{
  invalid_handler_12c5fc((char *)0x180A, 6);
  if ( !a1 )
    return mac_dma_setup();
  check_feature_flag(256, "ext auth st %x\n", a1);
  return assert_trace(a1);
}
