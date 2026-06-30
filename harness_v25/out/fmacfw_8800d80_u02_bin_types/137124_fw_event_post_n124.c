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

extern uint32_t off_137154;
extern uint32_t dword_137158;

// fw_event_post_n124 @ 0x137124, size 48 bytes
// Doc: fw_event_post_n124 [ipc]: Posts firmware event with opcode 0x100b to host message queue
// fw_event_post_n124 [ipc]: Posts firmware event with opcode 0x100b to host message queue
int  fw_event_post_n124(int a1, uint8_t *a2)
{
  uint16_t *v2; // r5
  int v4; // r0

  v2 = (uint16_t *)off_137154;
  v4 = sub_12C92C(4107, *((uint16_t *)off_137154 + 1924), 4, 1u);
  sdio_buffer_prepare_n_4e8(v4);
  feature_guard_check(8, dword_137158, v2[1924]);
  sub_1374C8(*a2);
  return 0;
}

