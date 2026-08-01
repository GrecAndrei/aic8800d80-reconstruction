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

extern uint32_t off_1365EC;
extern uint32_t dword_1365F0;

// reset_hci_control_block @ 0x1365c0, size 42 bytes
uint32_t *reset_hci_control_block()
{
  uint8_t *v0; // r4
  int v1; // r3

  v0 = off_1365EC;
  sub_100200((int *)off_1365EC, 0, 0x24u);
  v1 = dword_1365F0;
  v0[15] = 3;
  *((uint32_t *)v0 + 4) = 20000;
  *((uint32_t *)v0 + 6) = v1;
  v0[12] = 0;
  return hci_cmd_preprocess(7u, 0);
}

