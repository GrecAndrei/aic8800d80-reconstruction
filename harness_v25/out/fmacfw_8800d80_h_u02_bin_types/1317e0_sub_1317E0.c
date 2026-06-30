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

extern uint32_t off_131828;
extern uint32_t dword_131834;
extern uint32_t dword_131830;
extern uint32_t off_13182C;

// sub_1317E0 @ 0x1317e0, size 70 bytes
int  sub_1317E0(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(int16_t **)off_131828 < 0 && sub_12CD48(a3) != 1 )
    sub_12F32C(dword_131834, dword_131830, 822);
  v4 = *((uint16_t *)off_13182C + 4);
  if ( v4 != 255 )
    sub_12C8D0(5146, v4, a3);
  sub_12CBF4(a3, 0);
  return 0;
}

