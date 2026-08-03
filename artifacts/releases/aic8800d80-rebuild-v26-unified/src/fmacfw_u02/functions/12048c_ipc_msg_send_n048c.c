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

// ipc_msg_send_n048c @ 0x12048c, size 26 bytes
// Doc: ipc_msg_send_n048c [ipc]: Allocate IPC message (id 0x8f) and store caller's context pointer
// ipc_msg_send_n048c [ipc]: Allocate IPC message (id 0x8f) and store caller's context pointer
int  ipc_msg_send_n048c(int a1)
{
  uint32_t *v2; // r0

  v2 = (uint32_t *)sub_12C92C(143, 0, 255, 4);
  *v2 = a1;
  return sdio_buffer_prepare_n_4e8(v2);
}

