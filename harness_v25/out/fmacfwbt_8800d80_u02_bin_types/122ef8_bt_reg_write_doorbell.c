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

extern uint32_t off_122F0C;

// bt_reg_write_doorbell @ 0x122ef8, size 20 bytes
// Doc: bt_reg_write_doorbell [bt]: Write BT doorbell MMIO at 0x40320034 and send IPC msg 0x72
// bt_reg_write_doorbell [bt]: Write BT doorbell MMIO at 0x40320034 and send IPC msg 0x72
int  bt_reg_write_doorbell(int a1, uint32_t *a2, int a3, int a4)
{
  *(uint32_t *)off_122F0C = *a2;
  message_dispatch_n84(114, a4, a3, a4);
  return 0;
}

