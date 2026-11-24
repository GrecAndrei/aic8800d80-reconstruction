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


extern uint32_t off_10D0DC;
extern uint32_t off_10D0E0;

// bt_set_address @ 0x10d0bc, size 26 bytes
int  bt_set_address(int a1)
{
  int result; // r0
  uint32_t *v3; // r3

  result = alloc_tx_event("chan notify: %x\r\n", a1);
  v3 = off_10D0E0;
  *(uint32_t *)off_10D0DC = a1;
  *v3 = 0x1000000;
  return result;
}
