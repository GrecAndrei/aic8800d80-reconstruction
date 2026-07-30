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

extern uint32_t dword_1320B8;

// sub_132088 @ 0x132088, size 46 bytes
int sub_132088()
{
  uint32_t *v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r0

  sub_100200((int *)dword_1320B8, 0, 0x17Cu);
  v0 = sub_12CBF4(5u, 0);
  v1 = sub_137490(v0);
  v2 = sub_1365C0(v1);
  v3 = sub_1342F4(v2);
  v4 = sub_13B82C(v3);
  return sub_140C5C(v4);
}

