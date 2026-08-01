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

extern uint32_t off_118E10;
extern uint32_t dword_118E18;
extern uint32_t off_118E1C;
extern uint32_t off_118E14;

// rf_enable @ 0x118dec, size 34 bytes
// Doc: sub_1226698 [bt]: FMAC BT helper: dispatch on arg0 with 8-register save
// sub_1226698 [bt]: FMAC BT helper: dispatch on arg0 with 8-register save
unsigned int rf_enable()
{
  unsigned int result; // r0
  int v1; // r1
  uint32_t *v2; // r2

  *(uint32_t *)off_118E10 |= 2u;
  result = gpio_set_bit10(0);
  v1 = dword_118E18;
  v2 = off_118E1C;
  *(uint32_t *)off_118E14 = dword_118E18;
  *v2 |= v1;
  return result;
}

