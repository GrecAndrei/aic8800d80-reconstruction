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

extern uint32_t dword_1199C4;
extern uint32_t dword_1199C8;

// sub_11998C @ 0x11998c, size 56 bytes
int  sub_11998C(int a1, int a2, int a3, int a4)
{
  uint8_t *v4; // r4
  int v5; // r0

  v4 = (uint8_t *)rf_setup_dispatch(133, a4, a3, 1);
  v5 = sub_10EFBC(dword_1199C4, 1);
  *v4 = (BYTE2(v5) ^ 1) & 1;
  msg_parse(dword_1199C8, v5);
  sub_11DE50(v4);
  return 0;
}

