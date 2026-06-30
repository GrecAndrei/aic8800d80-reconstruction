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

extern uint32_t off_11AD34;
extern uint32_t dword_11AD3C;
extern uint32_t dword_11AD38;

// sub_11ACF0 @ 0x11acf0, size 68 bytes
// Doc: sub_121ACF0 [bt]: FMAC+BT firmware routine at 0x121acf0
// sub_121ACF0 [bt]: FMAC+BT firmware routine at 0x121acf0
int  sub_11ACF0(int result, int a2)
{
  int v2; // r3
  int v3; // r2
  int v4; // r3
  unsigned int v5; // r3

  v2 = *(uint32_t *)(result + 60);
  if ( v2 < 0 )
  {
    v3 = *(uint32_t *)(result + 36);
    if ( **(int16_t **)off_11AD34 < 0 && (v4 = v2 << 15, v4 >= 0) )
    {
      return sub_12F630(dword_11AD3C, dword_11AD38, 3371, v4);
    }
    else
    {
      v5 = *(uint32_t *)(v3 + 20) & 0xFFFE3FFF | 0x4000;
      *(uint32_t *)(result + 60) = 0;
      *(uint32_t *)(v3 + 20) = v5;
      return bt_chan_dispatch_n_6f0(result, a2, v3, v5);
    }
  }
  return result;
}

