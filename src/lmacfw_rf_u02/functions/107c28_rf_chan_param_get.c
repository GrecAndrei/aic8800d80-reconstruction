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

extern uint32_t off_107C64;
extern uint32_t off_107C60;
extern uint32_t dword_107C68;
extern uint32_t off_107C6C;

// rf_get_rx_rssi @ 0x107c28, size 56 bytes
// Doc: rf_get_rx_rssi [rf]: Extract channel/bandwidth param via ubfx nibble from RF config regs
// rf_get_rx_rssi [rf]: Extract channel/bandwidth param via ubfx nibble from RF config regs
int rf_get_rx_rssi()
{
  unsigned int *v0; // r5
  int v1; // r6
  uint16_t v2; // r4
  int result; // r0
  uint32_t *v4; // r1

  v0 = (unsigned int *)off_107C64;
  v1 = *(uint32_t *)off_107C64;
  v2 = (uint16_t)*(uint32_t *)off_107C60 >> 4;
  result = check_interrupt_flag(1, dword_107C68, v2, off_107C60);
  v4 = off_107C6C;
  *v0 = (v2 + (uint16_t)v1) & 0xFFF | *v0 & 0xFFFFF000;
  *v4 |= 0x400000u;
  return result;
}

