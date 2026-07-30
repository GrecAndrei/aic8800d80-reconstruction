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

extern uint32_t dword_1231CC;
extern uint32_t dword_1231D0;

// mbox_send_cmd_0x85 @ 0x123194, size 56 bytes
// Doc: mbox_send_cmd_0x85 [ipc]: Send mailbox command 0x85 with arg=1 and ack via MMIO 0x70000010
// mbox_send_cmd_0x85 [ipc]: Send mailbox command 0x85 with arg=1 and ack via MMIO 0x70000010
int  mbox_send_cmd_0x85(int a1, int a2, int a3, int a4)
{
  uint8_t *v4; // r4
  unsigned int v5; // r0

  v4 = (uint8_t *)sub_12C92C(133, a4, a3, 1);
  v5 = sub_10ED84(dword_1231CC, 1);
  *v4 = (BYTE2(v5) ^ 1) & 1;
  msg_parse(dword_1231D0, v5, HIWORD(v5) & 1);
  sdio_buffer_prepare_n_4e8(v4);
  return 0;
}

