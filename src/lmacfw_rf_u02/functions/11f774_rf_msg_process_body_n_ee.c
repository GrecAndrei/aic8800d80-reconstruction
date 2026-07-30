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

extern uint32_t dword_11F794;
extern uint32_t off_11F798;

// rf_msg_process_body_n_ee @ 0x11f774, size 32 bytes
// Doc: rf_mem_read_n1e8 [rf]: Read RF memory region with mailbox kick and flag clear
// rf_mem_read_n1e8 [rf]: Read RF memory region with mailbox kick and flag clear
int rf_msg_process_body_n_ee()
{
  msg_parse(dword_11F794);
  event_queue_push(1071, 1);
  *((uint32_t *)off_11F798 + 20) &= ~2u;
  return 0;
}

