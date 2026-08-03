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

// send_msg_to_host_c43 @ 0x122014, size 30 bytes
// Doc: send_msg_to_host_c43 [ipc]: Send message id 0x43 to host with arg 6 and flag=1
// send_msg_to_host_c43 [ipc]: Send message id 0x43 to host with arg 6 and flag=1
int  send_msg_to_host_c43(int a1)
{
  uint8_t *v2; // r0

  v2 = (uint8_t *)sub_12C92C(67, 6, 0, 1);
  *v2 = *(uint8_t *)(a1 + 107);
  return sdio_buffer_prepare_n_4e8(v2);
}

