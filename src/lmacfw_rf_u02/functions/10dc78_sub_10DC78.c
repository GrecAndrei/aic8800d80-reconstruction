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

extern uint32_t dword_10DCA8;
extern uint32_t off_10DCAC;

// sub_10DC78 @ 0x10dc78, size 48 bytes
int sub_10DC78()
{
  int result; // r0
  uint32_t *v1; // r3

  result = rf_reg_write_cb(dword_10DCA8, 1024, 15360);
  v1 = off_10DCAC;
  *((uint32_t *)off_10DCAC + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

