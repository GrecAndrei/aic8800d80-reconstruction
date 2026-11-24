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


extern uint32_t off_12EE68;

// bt_global_op_0x16acb4 @ 0x12ee38, size 42 bytes
int  bt_global_op_0x16acb4(int a1, uint32_t *a2, int a3, int a4)
{
  alloc_tx_event("\x9D\x81DBG: Setting severity filter: 0x%08x\n", *a2);
  *((uint32_t *)off_12EE68 + 1) = *a2;
  mac_write_header_word(1031, a4, a3);
  return 0;
}
