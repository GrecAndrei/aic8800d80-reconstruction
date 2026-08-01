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

extern uint32_t dword_12EE98;
extern uint32_t off_12EE9C;

// bt_global_op_0x16acdc @ 0x12ee6c, size 42 bytes
int  bt_global_op_0x16acdc(int a1, uint32_t *a2, int16_t a3, int16_t a4)
{
  alloc_tx_event(dword_12EE98, *a2);
  *(uint32_t *)off_12EE9C = *a2;
  mac_write_header_word(1029, a4, a3);
  return 0;
}

