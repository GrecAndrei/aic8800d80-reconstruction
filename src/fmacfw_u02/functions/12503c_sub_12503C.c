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

extern uint32_t dword_1250D8;
extern uint32_t dword_1250DC;
extern uint32_t dword_1250E8;
extern uint32_t dword_1250E0;
extern uint32_t off_1250D4;
extern uint32_t dword_1250F0;
extern uint32_t dword_1250EC;
extern uint32_t dword_1250E4;

// sub_12503C @ 0x12503c, size 152 bytes
// Doc: sub_122503E [unknown]: Helper routine saving r4-r6 and remapping args
// sub_122503E [unknown]: Helper routine saving r4-r6 and remapping args
int  sub_12503C(int a1, int a2)
{
  int v4; // r5

  switch ( a2 )
  {
    case 2:
      v4 = dword_1250D8;
      *(uint32_t *)(dword_1250DC + 20 * a1 + 4) = 0;
      break;
    case 3:
      v4 = dword_1250D8;
      rf_chan_info_copy_n_2d0(*(uint8_t *)(dword_1250D8 + 1320 * a1 + 1225), dword_1250E8 + 38 * a1);
      break;
    case 1:
      v4 = dword_1250D8;
      *(uint32_t *)(dword_1250DC + 20 * a1 + 4) = dword_1250E0 + 20 * a1;
      break;
    default:
      v4 = dword_1250D8;
      if ( **(int16_t **)off_1250D4 < 0 )
        sub_12F46C(dword_1250F0, dword_1250EC, 1214);
      break;
  }
  *(uint8_t *)(a1 + dword_1250E4 + 20) = 0;
  return sub_12AC98(*(uint8_t *)(v4 + 1320 * a1 + 1225), a2);
}

