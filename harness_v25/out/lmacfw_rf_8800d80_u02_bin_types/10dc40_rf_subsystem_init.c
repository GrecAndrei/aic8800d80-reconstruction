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

extern uint32_t dword_10DC70;
extern uint32_t off_10DC74;

// rf_subsystem_init @ 0x10dc40, size 48 bytes
// Doc: rf_subsystem_init [rf]: Initialize lmac RF subsystem helper
// rf_subsystem_init [rf]: Initialize lmac RF subsystem helper
int rf_subsystem_init()
{
  int result; // r0
  uint32_t *v1; // r3

  result = rf_reg_write_cb(dword_10DC70, 2048, 15360);
  v1 = off_10DC74;
  *((uint32_t *)off_10DC74 + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

