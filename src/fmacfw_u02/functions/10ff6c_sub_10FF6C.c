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

extern uint32_t off_10FFB0;
extern uint32_t dword_10FFB4;
extern uint32_t off_10FFB8;

// hci_send_command @ 0x10ff6c, size 66 bytes
int  hci_send_command(int a1, int a2, int a3)
{
  uint32_t *v3; // r3
  uint32_t *v4; // r3

  v3 = off_10FFB0;
  *((uint32_t *)off_10FFB0 + 3) = dword_10FFB4;
  *v3 = a2;
  v3[1] = a3;
  *((uint8_t *)v3 + 8) = 4;
  hci_handle_command(v3, a1, 0x20u);
  v4 = off_10FFB8;
  *((uint32_t *)off_10FFB8 + 5) = 4;
  v4[1] = 0x10000;
  v4[3] = 131074;
  v4[6] = 0x40000;
  *v4 = 1;
  v4[2] = 1;
  v4[4] = 0;
  *((uint16_t *)v4 + 14) = 0;
  return 0x40000;
}

