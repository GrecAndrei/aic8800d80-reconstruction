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

extern uint32_t dword_12B510;

// ipc_msg_alloc_n0 @ 0x12b4e4, size 40 bytes
// Doc: ipc_msg_alloc_n0 [ipc]: Allocate/initialize IPC message (id 0x804) and link to queue
// ipc_msg_alloc_n0 [ipc]: Allocate/initialize IPC message (id 0x804) and link to queue
int  ipc_msg_alloc_n0(char a1, int a2)
{
  uint8_t *v3; // r4

  v3 = (uint8_t *)sub_12C92C(2052, a2, 2, 1);
  feature_guard_check(4, dword_12B510);
  *v3 = a1;
  return sdio_buffer_prepare_n_4e8(v3);
}

