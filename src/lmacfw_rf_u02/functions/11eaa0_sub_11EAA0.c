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


extern uint32_t dword_11EAC0;

// sub_11EAA0 @ 0x11eaa0, size 26 bytes
unsigned int  sub_11EAA0(unsigned int a1)
{
  unsigned int v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0

  v1 = sub_11E964(a1);
  v2 = sub_127570(v1);
  v3 = sub_127620(v2, *(uint64_t *)&dword_11EAC0);
  return sub_127BE4(v3);
}
