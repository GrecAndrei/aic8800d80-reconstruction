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

extern uint32_t dword_12B3BC;
extern uint32_t off_12B3C0;
extern uint32_t dword_12B3C4;

// bt_reset_controller @ 0x12b394, size 40 bytes
int bt_reset_controller()
{
  int result; // r0
  uint32_t *v1; // r3

  memset_byte((int *)dword_12B3BC, 0, 0xCu);
  result = hci_cmd_send(2);
  v1 = off_12B3C0;
  *(uint32_t *)off_12B3C0 = dword_12B3C4;
  v1[2] = v1 + 5;
  v1[4] = 0;
  v1[1] = 0;
  return result;
}

