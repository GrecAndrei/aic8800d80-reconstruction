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

extern uint32_t off_107C18;
extern uint32_t off_107C14;
extern uint32_t dword_107C1C;
extern uint32_t off_107C24;
extern uint32_t dword_107C20;

// rf_get_cca_status @ 0x107bd8, size 60 bytes
// Doc: rf_get_cca_status [mmio]: Read shifted field from MMIO register block
// rf_get_cca_status [mmio]: Read shifted field from MMIO register block
int rf_get_cca_status()
{
  unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  uint32_t *v4; // r2

  v0 = (unsigned int *)off_107C18;
  v1 = *(uint32_t *)off_107C18;
  v2 = *(uint32_t *)off_107C14 >> 20;
  result = check_interrupt_flag(1, dword_107C1C, v2, off_107C14);
  v4 = off_107C24;
  *v0 = dword_107C20 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}

