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

extern uint32_t off_118494;
extern uint32_t dword_11849C;
extern uint32_t off_118498;
extern uint32_t off_1184A4;
extern uint32_t dword_1184AC;
extern uint32_t dword_1184A8;
extern uint32_t off_1184A0;

// sub_11843C @ 0x11843c, size 86 bytes
int sub_11843C()
{
  uint16_t *v0; // r4
  int v1; // r3
  int16_t *v2; // r1
  int v3; // r1

  v0 = off_118494;
  sub_100200((int *)off_118494, 0, 0x20u);
  v1 = dword_11849C;
  v2 = *(int16_t **)off_118498;
  *(uint32_t *)v0 = dword_11849C;
  v0[8] = 0;
  v3 = *v2;
  *((uint32_t *)v0 + 1) = 0;
  if ( v3 < 0 && *(uint32_t *)off_1184A4 << 28 )
  {
    sub_1219F4(dword_1184AC, dword_1184A8, 472);
    *(uint32_t *)off_1184A0 = *(uint32_t *)v0 | *((uint32_t *)v0 + 1);
  }
  else
  {
    *(uint32_t *)off_1184A0 = v1;
  }
  return sub_1183A0();
}

